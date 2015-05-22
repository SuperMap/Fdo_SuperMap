/*!
   **************************************************************************************
    \file     UGLogFile.h
   **************************************************************************************
    \author   李绍俊
    \brief    日志文件类，用以记录日志信息                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-08  李绍俊    初始化版本.                                       <br>
	\version 2007-04-03  曾志明    增加10个宏供直接使用,整合错误对象.				 <br>
	\remarks <em>关于UGC中日志和错误对象整合的说明</em>
		在UGC中，和错误、日志有关的有两个类，一个是UGErrorObj，该类有些类似于SFC中的soError，
	只不过里面的错误信息可以存放多条，一般为存放较为严重的错误类信息；二次开发者可以从
	错误对象中获得一些程序为什么出错的信息，以便代码的修改和维护。
	另一个是UGLogFile，该类主要是把各类信息都可以写入到一个指定的文件中，各类信息在写入时，
	是可以区分严重程度的，现在分为5个程度，分别是：debug、info、warning、error、fatal，
	日志文件只有在用户设定后才打开并能真正写入信息，并设定该日志文件记录到何种程度的信息，
	例如，如果设定了日志文件是warning程度，那么info和debug类的信息就不能真正写入到日志文件中
	（但error和fatal类的信息也会写入）。
		以前，程序员在开发时，如果要记录一个错误信息，需要向错误对象中记录一个，又要向日志文件中写入一个，
	费时费神，代码也不优雅。在和李文龙商议后，决定采用以下的方式来处理。
	1，	在UGLogFile.h中定义5套、10个宏，用来向日志文件中分别记录5个程度的日志信息，
	大家只需要调用这些宏就可以了，不要理会内部的实现；
	2，	在debug到warning的宏调用，信息是不会记录到错误对象中的；error和fatal的宏调用，
	信息会自动向错误对象中记录一份；
	3，	从debug到warning的宏调用，可以直接写字符串信息（必须用英文），id可以给0或-100等；
	而error、fatal的宏，则必须有正确的字符串资源id号，因为这些id号要给外部用户查找错误使用
	4，	10个宏的定义如下：
	a)	UGDEBUG(id)
	b)	UGDEBUG2(id, strMsg)
	c)	UGINFO(id)
	d)	UGINFO2(id, strMsg)
	e)	UGWARNING(id)
	f)	UGWARNING2(id, strMsg)
	g)	UGERROR(id)
	h)	UGERROR2(id, strMsg)
	i)	UGFATAL(id)
	j)	UGFATAL2(id, strMsg)
   **************************************************************************************
*/

#if !defined(UGLOGFILE)
#define UGLOGFILE

#include "ugplatform.h"

//! \brief 默认的日志信息的格式化参数
//! %DATETIME 日期时间
//! %TIMESPAN 相邻两次日志记录之间的时间间隔(可以用来进行两次日志之间的性能记录)
//! %LEVEL 日志级别
//! %MSG 日志信息
//! %THREADID 线程id
//! %CODEFILE 代码文件
//! %CODELINE 代码行
//! %RESID    资源字符串ID
#define DEF_LOG_FORMAT "%DATETIME [%TIMESPAN] (%LEVEL) |  %MSG "EOLSTRING"ThreadID:%THREADID "EOLSTRING"CodeFile:%CODEFILE "EOLSTRING"CodeLine:%CODELINE"
//! 日期时间格式,请参考UGTime::Format的介绍
#define DEF_DATE_TIME_FORMAT "%Y-%m-%d %H:%M:%S"


#include "ugdefs.h"
#include "UGString.h"
#include "UGFileStream.h"
#include "UGFileStdio.h"
#include "UGThread.h"
#include "UGDict.h"
#include "UGErrorObj.h"
#include <queue>


#define UGDEBUG(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, __FILE__, __LINE__)
#define UGDEBUG2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, strMsg, __FILE__, __LINE__)
#define UGINFO(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, __FILE__, __LINE__)
#define UGINFO2(id, strMsg)		UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, strMsg, __FILE__, __LINE__)
#define UGWARNING(id)			UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id,  __FILE__, __LINE__)
#define UGWARNING2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id, strMsg, __FILE__, __LINE__)
#define UGERROR(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, __FILE__, __LINE__)
#define UGERROR2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, strMsg, __FILE__, __LINE__)
#define UGFATAL(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, __FILE__, __LINE__)
#define UGFATAL2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, strMsg, __FILE__, __LINE__)


namespace UGC {

class UGLogQueryDef;
struct UGLogItem;

//! 日志文件类回调函数
typedef  void (*LogCallBack)(const char* pchErrorInfo);

//! Open 回调函数
typedef  UGbool (*LogOpenCallBack)(void* pDataSource, const UGString& strTableName);
//!  Write 回调函数
typedef  void (*LogWriteCallBack)(void* pDataSource, const UGString& strTableName, const UGLogItem& logItem);
//!  Close 回调函数
typedef  void (*LogCloseCallBack)(void* pDataSource, const UGString& strTableName);


//! \brief 日志item，每条日志信息的完整记录
struct UGLogItem
{
	//! \brief 日期时间
	UGTime m_time;
	//! \brief 时间间隔,毫秒单位
	UGint m_nTimeSpan;
	//! \brief 日志级别, 同 UGLogFile::LogLevelType
	UGint m_eLevel;
	//! \brief 日志描述
	UGString m_strMsg;
	//! \brief 线程ID
	UGuint m_nThreadID;
	//! \brief 日志描述的资源字符串ID
	UGuint m_nResID;
	//! \brief 代码文件
	UGString m_strCodeFile;
	//! \brief 代码行
	UGuint m_nCodeLine;

	UGLogItem(){m_nThreadID=m_nResID=m_nCodeLine=0;}
	//Item(const Item& item){*this = item;}
	//Item& operator=(const Item& item){}
};

typedef UGArray<UGLogItem> UGLogItems;

//! \brief 一种预先确定大小, 快速定位的一种容器, 效率非常高
//! \remarks 内部采用UGArray实现, 以后可以考虑作为单独的文件
template<typename T>
class BASE_API UGContainer
{
public:
	UGContainer()
	{
		m_bCycled = FALSE;
		m_nPos = 0;
		SetCapacity(16);
	}

	//! 得到错误对象个数
	UGint GetCapacity() const
	{
		return m_items.GetSize();
	}

	void SetCapacity(UGint nCapacity)
	{
		m_items.SetSize(nCapacity);
	}

	UGint GetSize() const 
	{
		if(m_bCycled) 
		{
			return GetCapacity();
		}
		return m_nPos;
	}

	void Add(const T& value)
	{
		m_items[m_nPos++] = value;
		if(m_nPos >= GetCapacity()) 
		{
			m_bCycled = TRUE;
			m_nPos = 0;
		}
	}
	
	T& operator[](UGint nIndex) 
	{
		UGint c = GetCapacity();
		if (c > 0)
		{
			nIndex = (c+m_nPos-nIndex-1)%c;
			return m_items[nIndex];
		}
		m_items.SetSize(1);
		return m_items[0];
	}

	void Clear()
	{
		m_bCycled = FALSE;
		m_nPos = 0;
	}
	
private:
	//! 是否是循环的
	UGbool m_bCycled;
	//! 下一个填充位置
	UGint m_nPos;
	//! 存储错误信息
	UGArray<T> m_items;	
};

//! \brief 日志文件类
//! \remarks 具备功能:分级别写入日志;日志存储为文本,xml,数据库;可查询(查询结果可另存);
//!			 支持滚动;线程安全;可自定义日志信息格式;日志实时写入;性能上:写入100万条记录的时间在1分钟左右(文本格式)
//!			 Open时,可设定只存储在内存中; 可随时暂定和继续往物理介质上写入;
class BASE_API UGLogFile  
{
	friend class UGErrorObj;
public:
	//! \brief 日志级别
	enum LogLevelType
	{
		Debug	=	100,
		Info	=	200,
		Warning	=	300,
		Error	=	400,
		Fatal	=	500
	};

	//! \brief 日志存储方式
	enum Mode
	{
		//! \brief 普通的文本文件
		Text	= 0, 
		//! \brief XML格式存储
		XML		= 1,
		//! \brief 数据库
		Database = 2,
		//! \brief 内存模式
		Memory = 3
	};

	//! \brief 日志分文件存储, 规定分文件的时间点;默认为NoTime
	enum TimeInterval
	{
		// by zengzm 2007-10-15 如果达到FileSizeLimit，可以选择如何处理，这里就不要OneFile的枚举了
		// 不是分文件存储
		//OneFile = 0, 

		//! 不按照时间来划分
		NoTime = 0,

		//! 小时
		Hour = 1,
		//! 天
		Day = 2, 
		//! 周
		Week = 3,
		//! 月
		Month = 4
	};

	//! \brief 当日志文件的大小达到某个限定值时，不同的处理方式
	//! \remarks 只对Text和XML模式的日志起作用，以后有需要可以考虑Database模式;
	//! 只有在FileSizeLimit大于0时才起作用
	enum SizeLimitMode
	{
		//! \brief 回滚，即从文件头开始记录，会覆盖原来文件头的信息，但后面没有覆盖到的信息不会删除
		//! \remarks 回滚对XML模式不起作用;原因是XML模式需要完整的XML格式,处理比较困难
		Rolling = 0,
		//! \brief 重新打开, 原来的文件被清空
		ReOpen = 1, 
		//! \brief 生成一个新的日志文件, 文件名在最后加#1/2/3等方式
		NewFile = 2
	};

public:
	~UGLogFile();
	
	//! \brief 用此函数来获得日志文件的唯一实例
	//! \param bLogStarting 是否正在出于Log启动状态，默认为false；
	//! 仅在UGLogFileStartup的构造函数中设置为true，用来防止循环构造；
	//! 在AIX中,如果不如此处理,会出现程序运行不起来的问题
	static UGLogFile& GetInstance(bool bLogStarting=false);

	//! 不要直接使用，请使用GetInstance来得到唯一实例
	UGLogFile();
private:
	UGLogFile(const UGLogFile&);
	UGLogFile& operator=(const UGLogFile&);
	

public:
	//! \brief 打开日志文件，会恢复日志文件的各种默认设置, eMode只支持Text和XML
	//! \param strFileName [in] 日志文件全路径。
	//! \param bAppend [in] 如果目标日志文件已经存在，是否在文件尾追加内容，还是覆盖原有内容。
	//! \param eMode [in] 日志文件的模式，本函数仅支持Text和XML模式。
	//! \return 打开成功，返回true；失败返回false。
	//! \attention 本函数已经被废弃，被UGbool Open(const UGString& strPath, const UGString& strPrefix="Log", TimeInterval eTimeInterval=Day, Mode eMode=Text);
	//!			   所取代，暂时保留一段时间，6.0中予以删除
	UGbool Open(const UGString& strFileName, UGbool bAppend=false, Mode eMode=Text);	

	//! \brief 根据当前时间生成默认文件, 默认为文本格式, 可设定eMode为Text,XML和Memory模式
	//! \param eMode [in] 日志文件的模式，本函数支持Text、XML和Memory模式。
	//! \return 打开成功，返回true；失败返回false。
	UGbool Open(Mode eMode=Text);	

	//! \brief 打开日志数据库
	//! \remark 日志数据库必须在外面先创建好,且是SuperMap的数据源
	//! \param pDataSource [in] 数据源指针，必须是有效合法、且已经Open的SuperMap数据源。
	//! \param strTableName [in] 属性数据集（数据表）的名称，如果不合法，会生成一个新的名字。
	//! \return 打开成功，返回true；失败返回false。
	UGbool Open(void *pDataSource, const UGString& strTableName);	

	//! \brief 打开日志，按照一定规则分不同的文件存放日志信息
	//! \param strPath 存放日志文件的目录
	//! \param strPrefix 日志文件名前缀
	//! \param eTimeInterval 日志分文件的时间点, 如默认为Day,则每天0点时会产生一个新的日志文件
	//! \param eMode 日志文件的存储格式, 本函数中, 仅支持 Text和XML格式
	//! \param bAppend [in] 如果目标日志文件已经存在，是否在文件尾追加内容，还是覆盖原有内容。
	//! \remarks 日志文件名按照："前缀"+"_进程id"+"_起始时间点"的方式命名
	//! \return 打开成功返回true,失败返回false
	UGbool Open(const UGString& strPath, const UGString& strPrefix="Log", 
			TimeInterval eTimeInterval=Day, Mode eMode=Text, UGbool bAppend=false);

	//! \brief 限制文件大小
	//! \param nFileSizeLimit 日志文件大小限定, 如果超过大小限定, 则按照eSizeLimitMode来处理;
	//!							默认为-1, 不限定大小; 单位为 字节 
	//! \param eSizeLimitMode 如果nFileSizeLimit大于0的处理方式
	//! \remarks 目前只支持Text和XML模式
	void SetFileSizeLimit(UGint nFileSizeLimit, SizeLimitMode eSizeLimitMode=Rolling);
	//! \brief 得到文件限制
	UGint GetFileSizeLimit();
	//! \brief 得到文件限制
	SizeLimitMode GetSizeLimitMode();

	//! 数据库引擎的数据源 释放之前, 告知LogFile一下
	void SetDataSourceNull(void *pDataSource);

	//! 关闭文件
	//! \param bDefaultSetting 是否把各种设置恢复为默认值, 默认为恢复
	void Close(UGbool bDefaultSetting=true);									
	//! 文件是否打开
	UGbool IsOpen();									

	//! \brief 设置是否存储到物理介质中，物理介质，可以是文件，也可能是数据库
	//! \param bSaveToPhysical是否保存到物理介质中, 默认为true; 如果为false,则只有驻留在内存中的日志信息
	//! \remarks 如果希望日志文件不生成,请在Open时,用Memory模式; 在Memory模式下,bSaveToPhysical一定为false
	void SetSaveToPhysical(UGbool bSaveToPhysical);

	//! \brief 日志信息是否存储到物理介质中
	UGbool IsSaveToPhysical();

	//! \brief 设置是否过滤重复日志, 作用是在循环调用时,
	//!			减少相同日志的输出,避免对效率的影响,以及提高日志可读性
	//! \param bFilterRepeat 是否过滤重复日志
	//! \remarks 默认为true, 目前的设置为: 
	//!			1)如果当前日志信息和最近一条日志一模一样,是否过滤掉,不予记录
	//! 		2)在最近若干条(暂为100)日志中,如果某条日志重复超过若干次(暂为5),则过滤掉,不予记录
	void SetFilterRepeat(UGbool bFilterRepeat);

	//! \brief 是否过滤重复日志
	UGbool IsFilterRepeat();

	
	//! 日志级别
	LogLevelType GetLevel();
	void SetLevel(LogLevelType eLevel);

	
	//! \brief 查询日志信息
	//! \remarks 查询的结果最新的放在最前面,如queryResult[0]是最新写入的日志,queryResult[size-1]是最古老的日志
	UGbool Query(const UGLogQueryDef& logQueryDef, UGLogItems& queryResult);

	//! \brief 设置最大可查询日志记录的个数, 默认为10240
	void SetQueryMaxNum(UGuint nQueryMaxNum);

	//! \brief 得到最大可查询的日志记录个数
	UGuint GetQueryMaxNum();

	//! \brief 得到指定位置的可查询信息
	//! \remark 仅供内部使用, 外部一般用Query即可
	//const UGLogItem& GetQueryItemAt(UGint nIndex);

	//! \brief 清空可查询的日志信息
	//! \remarks 目前主要供错误对象使用,其它地方谨慎使用
	//void ClearQueryInfo();

	//! \brief 查询结果的存储
	//! \remarks 目前只支持存储为Text和XML格式
	//!			 最新的日志信息在文件最前面
	static UGbool SaveQueryResult(const UGLogItems& queryResult, const UGString& strFileName, Mode eMode);


	//! \brief 设置日志信息回调函数
	static void SetCallBack(LogCallBack pCallBack);

	static void SetOpenCallBack(LogOpenCallBack pOpenCallBack);
	static void SetWriteCallBack(LogWriteCallBack pWriteCallBack);
	static void SetCloseCallBack(LogCloseCallBack pCloseCallBack);
	
	//! \brief 通过id得到字符串信息，并记录到日志文件中。
	//! \param eLevel 该条信息的层次[in]。
	//! \param nResID 字符串资源id[in]。
	//! \param strCodeFile 所在代码文件名[in]。
	//! \param nLineNumber 所在代码行[in]。
	//! \attention 不要直接使用,请采用UGDEBUG等宏记录日志信息
	//! \return 成功返回true;失败返回false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString& strCodeFile, UGint nLineNumber);	

	//! \brief 把字符串信息记录到日志文件中。
	//! \param eLevel 该条信息的层次[in]。
	//! \param nResID 字符串资源id[in]。
	//! \param strMsg 要记录的字符串[in]。
	//! \param strCodeFile 所在代码文件名[in]。
	//! \param nLineNumber 所在代码行[in]。
	//! \attention 不要直接使用,请采用UGDEBUG等宏记录日志信息
	//! \return 成功返回true;失败返回false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString & strMsg, 
							const UGString& strCodeFile, UGint nLineNumber);
	
	
	//! 得到和设置日志信息的格式，具体可以参考 DEF_LOG_FORMAT 的定义
	UGString GetLogFormat();
	void SetLogFormat(const UGString &strLogFormat);

	//! 日期时间格式,请参考UGTime::Format
	UGString GetDateTimeFormat();
	void SetDateTimeFormat(const UGString &strDateTimeFormat);

	
	//! \brief 设置为仅仅记录纯日志信息, 时间,代码,线程等统统不记录
	//! \remarks 主要给内部测试等一些特殊的用途
	void SetRecordOnlyLog();

	static UGString GetLevelAsString(LogLevelType eLevel);
	static LogLevelType GetLevelAsEnum(const UGString& strLogLevel);

	static Mode GetModeAsEnum(const UGString& strLogMode);
	static TimeInterval GetTimeIntervalAsEnum(const UGString& strTimeInterval);
	static SizeLimitMode GetSizeLimitModeAsEnum(const UGString& strSizeLimitMode);

private:
	const UGString &GetDirectory();					//获取日志文件的路径
	void SetDirectory(const UGString &strDirectory);	//设置日志文件的路径
	
	UGString GetDefaultFileName();			//根据当前时间生成默认文件名
	
	// added by zengzm 2005.12.9 增加flush方法，把没有写入文件的数据写入
	//! \brief 把数据即时写入到文件中
	UGbool Flush();

	//! \brief 恢复日志文件的各种默认设置
	//! \remarks 包括日志格式，日志级别，回调函数指针，是否记录日期时间、线程id、代码信息等
	void SetDefaultSetting();

	UGbool OpenText(const UGString& strFileName, UGbool bAppend);
	UGbool OpenXML(const UGString& strFileName, UGbool bAppend);

	//! 创建 xml 文件配套的 xslt文件
	void CreateXslt(const UGString & strXsltName); 

	//! 创建 xml 文件配套的 xsd文件
	void CreateXsd(const UGString & strXsdName); 

	void WriteText(const UGLogItem& logItem);
	void WriteXML(const UGLogItem& logItem);

	//! 日志为按照时间分文件存储时的处理函数
	void DealTimeInterval();

	//! 文件达到预定SizeLimit时的处理函数
	void DealFileSizeLimit();

	//! \brief 判断该条信息是否属于重复记录
	//! \param logItem 要被判断的日志信息
	//! \return 如果属于重复记录,返回true;否则返回false
	UGbool IsFilterRepeat(const UGLogItem& logItem);
	
private:		
	UGString m_strFormat;			//日志格式
	LogLevelType m_eLevel;			//日志文件级别
	Mode m_eMode;					//日志记录的模式，包括：文本、xml、数据库等
	UGString  m_strDirectory;		//日志文件的路径
	//! 日志主文件全名. 
	//! \remarks 对于Text和XML模式,为日志文件名; 对于Database模式,为数据表名; 对于Memory模式,为"Memory"
	UGString m_strFileName; 
	UGbool m_bIsOpen;				//文件是否打开
	//! 回凋函数指针
	static LogCallBack ms_pCallBack;
	//! 往数据库中写入日志信息的回调函数指针
	static LogOpenCallBack ms_pOpenCallBack;
	static LogWriteCallBack ms_pWriteCallBack;
	static LogCloseCallBack ms_pCloseCallBack;

	UGFileStdio m_file;			//文件指针, Text, XML 存储时使用

	UGbool m_bSaveToPhysical; // 是否存储到物理介质中,默认为true

	//! 是否过滤重复日志, 默认为true
	UGbool m_bFilterRepeat;
	UGLogItem m_lastItem;
	
	//! SuperMap数据源指针
	void * m_pDataSource;

	// 被m_strFileName取代
	//! 存储日志的数据表名称,即数据集名称,默认为SmLog; 
	// UGString m_strTableName; 
	
	//! 日志格式描述
	UGString m_strLogFormat;

	//! 日期时间 格式描述
	UGString m_strDateTimeFormat;

	//! 日志信息在内存中的存储,以便查询时使用
	UGContainer<UGLogItem> m_items;
//	UGLogItems 
//	//! 当前记录的位置
//	UGuint m_nPos;
//	//! 是否已经循环记录, 如果循环,则查询时要把 Pos后面的都考虑在内
//	UGbool m_bCycled;

	//! 错误信息在内存中的记录, 以便错误对象使用
	UGContainer<UGErrorObj::ErrorInfo> m_errors;

	//! 标记位,记录当前日志信息,是否是在日志文件调用的函数中发生的
	//! 默认为false, 进入日志文件函数后,设置为true; 如果再进来的日志,就必要记录,避免递归死循环
	//! 目前主要在存储到数据库中时使用,因为存储为其它格式时,所调用的类不会再写日志
	UGbool m_bIntoLogFile;
	
	//! 按照时间分文件存储,默认为NoTime
	TimeInterval m_eTimeInterval;
	//! 分文件存储大小限定, 默认为-1,不限定大小
	UGint m_nSizeLimit;
	//! 分文件存储模式,默认为Rolling,回滚
	SizeLimitMode m_eSizeLimitMode;

	//! 文件名前缀,默认为Log
	UGString m_strPrefix;
	//! 记录重新生成新日志文件时的时间
	UGTime m_time;
	//! 分文件存储时的文件序号
	UGint m_nFileNum;

	//! 最近的时间记录(精确到毫秒), 用来生成 %TIMESPAN 项
	UGint m_nLastMillisecond;

	//! 最近若干条日志中,相同日志(通过hashCode识别)的条数;用来进行重复日志过滤
	UGDict<UGint, UGint> m_infoCount; 

	//! 记录最近若干条日志的HashCode;和m_infoCount配合使用,用来进行重复日志过滤
	//! \remarks 暂时先直接使用stl的queue,以后考虑UGC中封装一个类
	std::queue<UGint> m_hashCodes;

	//! 保证多线程安全
	UGMutex m_mutex;
};

//! 日志查询定义
class BASE_API UGLogQueryDef  
{
public:
	//! 查询的类型
	enum Type	
	{
		//! 日志级别查询
		Level = 100,
		//! 日期时间查询
		DateTime = 200,
		//! 时间间隔查询
		TimeSpan = 300,
		//! 日志描述信息查询
		Description = 400,
		//! 日志描述的资源字符串ID查询
		ResID = 500,
		//! 日志发生的线程ID查询
		ThreadID = 600,
	};
	//! 查询逻辑符号记录, 支持 > < = >= <= != 几种形式
	UGString m_strOperator;
	//1 查询类型
	Type m_eType;
	// 查询逻辑符号右边的字符串记录
	//UGString m_strRight;
	//! 查询的日志级别,在 Level查询时使用
	UGLogFile::LogLevelType m_eLevel; 
	//! 查询的日期时间,在 DateTime 查询时使用
	UGTime m_time;
	//! 查询的时间间隔,在 TimeSpan 查询时使用; 注意单位为毫秒
	UGint m_nTimeSpan;
	//! 查询的描述信息,在 Description 查询时使用
	UGString m_strDescription;
	//! 查询的线程id信息,在 ThreadID 查询时使用
	UGuint m_nThreadID;
	//! 查询的资源字符串id信息,在 ResID 查询时使用
	UGuint m_nResID;
    
	UGLogQueryDef()
	{
		m_eType = ResID; // 默认为 资源ID查询
		m_eLevel = UGLogFile::Error;
		m_nThreadID = m_nResID = m_nTimeSpan = 0;
	}
};

}
#endif // !defined(UGLOGFILE)

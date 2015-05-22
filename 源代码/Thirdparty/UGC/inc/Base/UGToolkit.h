// UGToolkit.h: interface for the UGToolkit class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGTOOLKIT_H
#define UGTOOLKIT_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGTextCodec.h"
#include "ugplatform.h"

namespace UGC{

class BASE_API UGToolkit  
{
private:
	UGToolkit();
	~UGToolkit();

public:
	//! \brief 精确计算Cos值
	//! \remark 主要用来处理当角度为某些特殊值时,可以直接返回精确的值
	//!			由于PI的不精确性, 用cos(弧度)得到的结果会有微小的误差, 尤其在应该为0等精确值时,
	//!			本函数输入参数为角度值,判断了这种情况, 会给出精确的值.
	//!			未来可以考虑内部缓存一些常用值,以提高效率
	//! \param dAngle 角度值
	//! \return cos的计算值
	//! 效率较低, 暂不提供
	//static UGdouble CosAngle(UGdouble dAngle);

	//! \brief 精确计算Sin值
	//! \remark 主要用来处理当角度为某些特殊值时,可以直接返回精确的值
	//!			由于PI的不精确性, 用sin(弧度)得到的结果会有微小的误差, 尤其在应该为0等精确值时,
	//!			本函数输入参数为角度值,判断了这种情况, 会给出精确的值.
	//!			未来可以考虑内部缓存一些常用值,以提高效率
	//! \param dAngle 角度值
	//! \return sin的计算值
	//! 效率较低, 暂不提供
	// static UGdouble SinAngle(UGdouble dAngle);

	static UGint RoundLong(UGdouble dValue)
	{
		if(dValue>0) return UGint(dValue+0.5);
		else return UGint(dValue-0.5);
	};

	//! \brief 得到当前进程的id
	static UGint GetCurProcessId();

// by zengzm 2007-7-13 和路径相关的函数都放到 UGFile中
	//! \attention 原来SuperMap50中Ref和Source的概念正好颠倒了;
	//! 但为了保持代码兼容,这里只修改变量名称, 不调整顺序, 使用者代码不需要改动
	//! 参数strSourcePath为绝对路径名(允许为空), 不带文件名; 参数strRefPath为文件名, 
	//! 可带相对路径或绝对路径信息;返回值为带绝对路径信息的文件名.
	//! 当strSourcePath为空的时候, 如果strRefPath为./abc.txt , 则返回abc.txt ;
	//! 当strSourcePath为空的时候, 如果strRefPath为../abc.txt , 则返回空字符串.
//	static UGString GetAbsolutePath(const UGString &strSrcPath, const UGString &strFile);
	// static UGString GetAbsolutePath(UGString strRefPath, UGString strSourcePath);

	//! 得到相对路径
	//! \remarks 三种路径的定义: 原路径(SourcePath)+相对路径(RefPath) == 绝对路径(AbsPath)
	//! 即 RefPath = AbsPath - SourcePath
	//! 举例说明: SourcePath="d:\\dir\\", AbsPath="d:\\dir\\path\\",  则 RefPath=".\\path\\"
	//! 参数和返回值都只能是只包含目录的路径信息, 并不包含任何文件名.
	//! \attention 原来SuperMap50中概念是不正确的
	//! 但为了保持代码兼容,这里只修改变量名称, 不调整顺序, 使用者代码不需要改动
//	static UGString GetRelativePath(UGString strSourcePath, UGString strAbsPath);
	// static UGString GetRelativePath(UGString strRefPath, UGString strSourcePath);


//	static void SplitPath(const UGString& strPath, UGString& strDrive, UGString& strDir, UGString& strFileName, UGString& strExtName);
//	static UGString ChangeExtName(const UGString &strFileName, const UGString &strExtName);
//	static UGString GetExtName(const UGString &strFileName); 

	// by zengzm 2005.6.2 这个函数没人用, 暂时封起来, 谁要用再说; 增加请加入到UGFile类中
	// static UGbool IsSameFile(UGString strFile1, UGString strFile2);
	// static UGString SetDefaultExtName(const UGString& strFileName, const UGString& strExtName);
	
	// modified by jifang 06/16/2005 把其中的UGchar *用UGString&替换
	//static UGuint GetTemporaryPath(UGuint nBufferLength, UGchar* lpBuffer);
//	static UGString GetTemporaryPath();
//	//static UGuint GetTemporaryFileName(UGchar* lpPathName, UGchar* lpPrefixString,UGuint uUnique,UGchar* lpTempFileName);
//	static UGuint GetTemporaryFileName(const UGString &strPathName, const UGString &strPrefixString, 
//									UGuint uUnique, UGString &strTempFileName);

	//{{ 动态库处理函数======================================================
	static void* LoadDll(const UGString& strLibName);
	// 通过库的句柄和函数名字,得到函数指针
	static void* GetProcAddress(void* hModule, const UGString& strProName);
	// 释放库
	static UGbool FreeDll(void* hModule);
	//}} 动态库处理函数======================================================

// by zengzm 2007-7-13 和文件, 路径相关的函数都放到UGFile中了
//	static UGString GetAppPath();
//	static UGString GetModulePath(const UGchar* p);
//
//	//! \brief 得到单元测试数据所在的目录
//	//! \param strUnitTestName 单元测试工程的文件夹名，如TestBase、TestGeometry等
//	//! \remarks 返回的是绝对路径，可直接使用；采用的是ugcpath/01_SourceCode/TestUnit/strUnitTestName/Data/ 的形式
//	//!			 这样就要求各个单元测试工程的数据放在本测试工程目录下一级的Data目录下; 调用时,把strUnitTestName作为参数传入
//	//! \return 返回单元测试数据所在的目录
//	static UGString GetUnitTestDataPath(const UGString& strUnitTestName);

//	static UGbool FindFileExtPaths(const UGString& strPath, const UGString& strExtName, 
//								  UGArray<UGString>& strFileNames, UGbool bAddPath);
//
//	static UGbool DeleteFileEx(const UGString& strFileName);
//	static UGbool IsFileExisted(const UGString& strFileName);
//	// modified by zengzm 2007-4-2 CopyFileEx这个名字又被MFC给改名为CopyFileExA了，因此，在UGC中只好换一个名字，在前面加UG
//	// static UGbool CopyFileEx(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);
//	static UGbool UGCopyFile(const UGString& strExistedFileName, const UGString& strNewFileName, UGbool bFailIfExists);

	//! \brief 得到当前系统默认的字符集
	static UGTextCodec::Charset GetCurCharset();

	//通过系统函数获取屏幕大小，X11上获取比较慢，这个函数调用要小心，推荐调用下面一个函数 add by xll 2006.12.30
	static UGuint GetScreenSize(UGuint nScreen);	
	//获取屏幕大小，为了节省效率（X11上获取比较慢），每次ondraw前从系统获取值写入到成员变量中
	//后面要使用的时候就直接取成员变量中的值 add by xll 2006.12.30
	static UGuint GetScreenSizeFromMemory(UGuint nScreen);

	//! \brief 内存信息结构
	struct MemoryStatus
	{
		MemoryStatus(){memset(this, 0, sizeof(MemoryStatus));}
		//! \brief 可用物理内存
		UGuint m_nAvailablePhysical;
		//! \brief 所有物理内存
		UGuint m_nTotalPhysical;
		//! \brief 可用虚拟内存
		UGuint m_nAvailableVirtual;
		//! \brief 所有虚拟内存
		UGuint m_nTotalVirtual;
		//! \brief 当前进程可用内存大小(等于min(可用物理内存+可用虚拟内存,进程剩余空间)
		//! \remarks 进程空间 和 程序为23/64位相关,32位为2GB,64位则非常大了
		//! \attention 尚未实现, 非Windows平台尚未找到实现方法
		//UGuint m_nProcessAvailable = 5,
		//! \brief 当前进程全部内存大小(等于min(所有物理内存+所有虚拟内存,进程空间)
		//! \remarks 进程空间 和 程序为23/64位相关,32位为2GB,64位则非常大了
		//! \attention 尚未实现, 非Windows平台尚未找到实现方法
		//UGuint m_nProcessTotal = 6
	};
	//! \brief 得到系统内存状态, 单位均为KB
	//! \param memoryStatus 通过引用返回内存的各种信息[out]
	//! \return 返回查询得到的内存状态
	static UGbool GetMemoryStatus(MemoryStatus& memoryStatus);

	//! \brief 得到系统中空闲(可用)物理内存的大小(KB为单位)
	//! \return 返回系统中空闲(可用)物理内存的大小(KB为单位)
	//! \remarks 分平台实现,Windows上有API:GlobalMemoryStatus;Linux/Unix上用sysconf函数
	//! \attention 本函数已经被GetMemoryStatus替代, 等价于 GetMemoryStatus(AvailablePhysical); 
	//! 为了保持以前的程序可用,暂时保存;新的代码请直接使用 GetMemoryStatus
	static UGuint GetAvailablePhysicalMemory();


	//! \brief 得到系统中全部物理内存的大小(KB为单位)
	//! \return 返回系统中全部物理内存的大小(KB为单位)
	//! \remarks 分平台实现,Windows上有API:GlobalMemoryStatus;Linux/Unix上用sysconf函数
	//! \sa GetAvailablePhysicalMemory
	// 暂不提供
	//static UGuint GetPhysicalMemory();
	
	//! \brief 调整角度值,使之在 [0, 360)之间
	//! param dAngle 要被调整的角度[in][out]
	static void AdjustAngle(UGdouble& dAngle);

	//! \brief 调整弧度值,使之在 [0, 2*PI)之间
	//! param dRadian 要被调整的弧度[in][out]
	static void AdjustRadian(UGdouble& dRadian);

	//! \brief 计算X方向的长度在旋转一定角度后，又被resize，之后应该的长度
	//! \remark 主要用在各种带有旋转角度的Geometry的Resize函数中对X方向的长度的处理
	//! \param dXLength X方向的长度[in]。
	//! \param dCos 该长度具备的旋转弧度的cos值[in]。
	//! \param dSin 该长度具备的旋转弧度的sin值[in]。
	//! \param dXRatio X方向的缩放比例[in]。
	//! \param dYRatio Y方向的缩放比例[in]。
	//! \return 处理后的长度。
	static UGdouble XRotateResize(UGdouble dXLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);	

	//! \brief 计算Y方向的长度在旋转一定角度后，又被resize，之后应该的长度
	//! \remark 主要用在各种带有旋转角度的Geometry的Resize函数中对Y方向的长度的处理
	//! \param dYLength Y方向的长度[in]。
	//! \param dCos 该长度具备的旋转弧度的cos值[in]。
	//! \param dSin 该长度具备的旋转弧度的sin值[in]。
	//! \param dXRatio X方向的缩放比例[in]。
	//! \param dYRatio Y方向的缩放比例[in]。
	//! \return 处理后的长度。
	static UGdouble YRotateResize(UGdouble dYLength, UGdouble dCos, UGdouble dSin, 
								UGdouble dXRatio, UGdouble dYRatio);

public:
	
	static UGbool InRange(UGint nValue, UGint nMin, UGint nMax);
	static UGbool InRange(const void* pValue, const void* pMin, const void* pMax);
	static UGint GetBitCount(PixelFormat pf); 

public:
	//! \brief 得到XML文件头
	//! 在简体中文环境下返回 <?xml version="1.0" encoding="GB18030"?> 
	static UGString GetXmlFileHeader();

	//由于标签内的值不能有空格，或换行暂时关闭此方法. yanmb 2008.1.22
	//! \brief added by yanmb 2007.5.11
	/**
	规范文本输出格式
	\param strXml  需要规范的文本字符串
	\param nPace   文本缩进的空格数
	文本要规范的格式典型样式是这样的
####< >
####   < />
####   < >
####   </ >
####   < >
####      < >
####      </ >
####      < />  //---这是单个标签的情况---------
####      < />
####   </ >
####   < >
####      < >
####      </ >
####   </ >
####</ >
	\attention
	1.在只相差一个级别的">"与"<"之间的内容我们可以规定为一个换行加3个空格
	2.同一级别的">"与"</"之间的内容我们可以规定为一个换行
	3.对于类似"< />"单个标签的情况,我们将其类同</ >来处理
	*/
	static UGString AdjustXmlString(UGString strXml, UGint nPace = 0);

	//! \brief  字符串进一步分割
	//! \remark 主要用于GML解析时
	//! \param  strSrc		需要进一步分割的字符串[in]
	//! \param strDestArray 输出字符串数组 [out]
	//! \Param str1st		第一次分割依赖的字符
	//! \Param str2nd		第二次分割依赖的字符
	/*attention
	这里实在是个无奈之举，由于GML有些版本标签内的内容以逗号和空格隔开，
	有些则以空格隔开。UGString的split方法只能做一步分割。
	其他地方可能很少这种情况，所以这里只考虑符合GML的用法来做了。yanmb
	*///
	static UGbool SlipString(UGString &strSrc, UGStrings &strDestArray, UGString str1st, UGString str2nd);
public: 
	//! \brief 判断字符是否属于 空ASCII字符, 包括 空格,\t\r\n等
	static UGbool IsSpaceChar(UGchar ch);

	//! \brief 判断字符是否属于 空ASCII字符, 包括 空格,\t\r\n等
	static UGbool IsSpaceChar(UGwchar wch);

	//! \brief 判断字符是否属于 数字字符, 从 '0' 到 '9'
	static UGbool IsDigit(UGchar ch);

	//! \brief 判断字符是否属于 十六进制字符, 包括从 '0' 到 '9', 'A'到'F', 'a'到'f'
	static UGbool IsHexDigit(UGchar ch);

	//! \brief 判断字符是否属于 大写字符, 从 'A' 到 'Z'
	static UGbool IsBigLetter(UGchar ch);

	//! \brief 判断字符是否属于 小写字符, 从 'a' 到 'z'
	static UGbool IsLittleLetter(UGchar ch);

	//! \brief 判断该字节是否是lead byte，即该字节和后续字节联合在一起构成一个双字节的字符（如中文、日文等）
	static UGbool IsLeadByte(UGchar ch);

	//! \brief 判断一个UCS2的字符是否是英文字符
	//! \return 如果是中文或日文等字符，返回false；是英文字符，返回true
	static UGbool IsAscii(UGushort ch);

	static UGColor Brightness(UGColor c, UGint nPercentage);
	static UGColor Contrast(UGColor c, UGint nPercentage);

private:
	// added by zengzm 2007-3-26 仅供内部使用,把得到的数据存在内部全局变量中
	static void SaveScreenSize(UGuint nScreen, UGuint ScreenValue);
	
};
//以下这些模板函数做成全局的，放到类里其他工程用会连接不过

//得到最(较)大值
template<typename Type>
const Type& Max(const Type& tValue1, const Type& tValue2)
{
	return ( (tValue1<tValue2)? tValue2 : tValue1);
}
//在nCount个数中得到最大值
template<typename Type>
Type Max(const Type* ptValue, UGint nCount)
{
	assert(ptValue != NULL); //ptValue不能为空
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = ((ptValue[i]<tResult)? tResult : ptValue[i]);
	}
	return tResult;
}

//得到最(较)大值,采用比较仿函数(小于比较)
template<typename Type, typename Compare>
const Type& Max(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue1, tValue2)? tValue2 : tValue1);
}

//在nCount个数中得到最大值,采用比较仿函数(小于比较)
template<typename Type, typename Compare>
Type Max(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue不能为空
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(ptValue[i], tResult)? tResult : ptValue[i]);
	}
	return tResult;
}

template<typename Type>
const Type& Min(const Type& tValue1, const Type& tValue2)
{
	return ( (tValue2<tValue1)? tValue2 : tValue1);
}

//在nCount个数中得到最小值
template<typename Type>
Type Min(const Type* ptValue, UGint nCount)
{
	assert(ptValue != NULL); //ptValue不能为空
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = ((tResult<ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}

//得到最(较)小值,采用比较仿函数(小于比较)
template<typename Type, typename Compare>
const Type& Min(const Type& tValue1, const Type& tValue2, Compare compare)
{
	return (compare(tValue2,tValue1)? tValue2 : tValue1);
}

//在nCount个数中得到最小值,采用比较仿函数(小于比较)
template<typename Type, typename Compare>
Type Min(const Type* ptValue, UGint nCount, Compare compare)
{
	assert(ptValue != NULL); //ptValue不能为空
	Type tResult(ptValue[0]); 
	for(UGint i=1; i<nCount; i++)
	{
		tResult = (compare(tResult, ptValue[i])? tResult : ptValue[i]);
	}
	return tResult;
}
template<typename Type>
void Sort(Type* pBegin, Type* pEnd)
{
	std::sort(pBegin,pEnd);
}
template<typename Type, typename Compare>
void Sort(Type* pBegin, Type* pEnd, Compare compare)
{
	std::sort(pBegin,pEnd,compare);
}
// StableSort, 基本同Sort, 区别在于StableSort保证相等元素的原本次序在排序后保持不变
template<typename Type>
void StableSort(const Type* pBegin, const Type* pEnd)
{
	std::stable_sort(pBegin, pEnd);
}

template<typename Type, typename Compare>
void StableSort(const Type* pBegin, const Type* pEnd, Compare compare)
{
	std::stable_sort(pBegin, pEnd, compare);
}

//! \brief 求两个集合之间的差
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief 求两个集合之间的差
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type, typename Compare>
void Difference(const Type* pBegin1, const Type* pEnd1, 
				const Type* pBegin2, const Type* pEnd2, 
				UGArray<Type>&arrResult, Compare compare)
{
	std::set_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief 求两个集合之间的交
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief 求两个集合之间的交
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type, typename Compare>
void Intersection(const Type* pBegin1, const Type* pEnd1, 
				  const Type* pBegin2, const Type* pEnd2, 
				  UGArray<Type>&arrResult, Compare compare)
{
	std::set_intersection(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief 求两个集合之间的对称差
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief 求两个集合之间的对称差
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type, typename Compare>
void SymmetricDifference(const Type* pBegin1, const Type* pEnd1, 
						 const Type* pBegin2, const Type* pEnd2, 
						 UGArray<Type>&arrResult, Compare compare)
{
	std::set_symmetric_difference(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief 求两个集合之间的并
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, UGArray<Type>&arrResult)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()));
}

//! \brief 求两个集合之间的并
//! \remarks arrResult原有数据会被覆盖,空间不够会自动增长
template<typename Type, typename Compare>
void Union(const Type* pBegin1, const Type* pEnd1, 
		   const Type* pBegin2, const Type* pEnd2, 
		   UGArray<Type>&arrResult, Compare compare)
{
	std::set_union(pBegin1, pEnd1, pBegin2, pEnd2, 
		std::inserter(arrResult.Inner(), arrResult.Inner().begin()), compare);
}

//! \brief 让集合中的元素不重复
//! \param pBegin 集合开始指针
//! \param pEnd 集合结束指针
//! \remarks 在调用Unique之前,集合必须先通过排序,即必须是有序集合
//!			 处理后,保证前面若干个元素不重复
//!			 内部采用stl中的unique算法函数实现
//! \return 返回不重复元素的个数
template<typename Type>
UGuint Unique(Type* pBegin, Type* pEnd)
{
	return std::unique(pBegin, pEnd) - pBegin;
}

//! \brief 让集合中的元素不重复
//! \param pBegin 集合开始指针
//! \param pEnd 集合结束指针
//! \param Compare 元素比较对象
//! \remarks 在调用Unique之前,集合必须先通过排序,即必须是有序集合
//!			 处理后,保证前面若干个元素不重复
//!			 内部采用stl中的unique算法函数实现
//! \return 返回不重复元素的个数
template<typename Type, typename Compare>
UGuint Unique(Type* pBegin, Type* pEnd, Compare compare)
{
	return std::unique(pBegin, pEnd, compare) - pBegin;
}

//! \brief 让集合中的元素不重复
//! \param pBegin 集合开始指针
//! \param pEnd 集合结束指针
//! \param pOut 输出的集合指针
//! \remarks 在调用UniqueCopy之前,集合必须先通过排序,即必须是有序集合;且pOut有足够的空间(不小于返回值)
//!			 处理后,保证pOut前面若干个元素不重复
//!			 内部采用stl中的unique算法函数实现
//! \return 返回不重复元素的个数
template<typename Type>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut)
{
	return std::unique_copy(pBegin, pEnd, pOut) - pOut;
}

//! \brief 让集合中的元素不重复
//! \param pBegin 集合开始指针
//! \param pEnd 集合结束指针
//! \param pOut 输出的集合指针
//! \param Compare 元素比较对象
//! \remarks 在调用UniqueCopy之前,集合必须先通过排序,即必须是有序集合;且pOut有足够的空间(不小于返回值)
//!			 处理后,保证pOut前面若干个元素不重复
//!			 内部采用stl中的unique算法函数实现
//! \return 返回不重复元素的个数
template<typename Type, typename Compare>
UGuint UniqueCopy(Type* pBegin, Type* pEnd, Type* pOut, Compare compare)
{
	return std::unique_copy(pBegin, pEnd, pOut, compare) - pOut;
}

}

#endif


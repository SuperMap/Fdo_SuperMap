// UGODBCConnection.h: interface for the UGODBCConnection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_)
#define AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Base/UGThread.h"
#include "Base/UGVariant.h"

#ifndef WIN32
	#include "sql.h"
	#include "sqlext.h"
	#include "sqltypes.h"
#else

	#ifndef _AFX_NO_DB_SUPPORT
	#include <afxdb.h>
	#endif

	#include <sql.h>
	#include <sqlext.h>
	#include <sqltypes.h>
#endif

// added by zengzm 2007-4-29 SQLLEN在VC6中没有定义,只能再自己处理一下,看来微软的兼容性也有问题
#if defined(_WIN32) && (_MSC_VER == 1200) //Defined as 1200 for Microsoft Visual C++ 6.0.
    typedef SQLINTEGER SQLLEN;
	typedef SQLUINTEGER SQLULEN;
#endif

namespace UGC {

#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)

//!  \brief 连接数据库的信息
//!  包括用户，用户ID，用户密码
//!  \remarks
struct DSNINFO 
{
	UGuchar szDSN[SQL_MAX_DSN_LENGTH+1];
	UGuchar szUID[SQL_MAX_DSN_LENGTH-1];
	UGuchar szPWD[SQL_MAX_DSN_LENGTH-1];
};

//!  \brief	连接数据库的信息
//!  包括数据库驱动，服务，数据库，用户ID，用户密码
//!  \remarks 
struct DRIVERINFO
{
	UGuchar szDriver[SQL_MAX_DSN_LENGTH-1];
	UGuchar szServer[SQL_MAX_DSN_LENGTH-1];
	UGuchar szDatabase[SQL_MAX_DSN_LENGTH-1];
	UGuchar szUID[SQL_MAX_DSN_LENGTH-1];
	UGuchar szPWD[SQL_MAX_DSN_LENGTH-1];
};

//!  \brief	字段信息
//!  
//!  \remarks 
struct FIELDINFO
{
	UGint		Scale;
	UGint		Nullable;
	UGuint		Precisioin;
	UGuint		Length;
	UGuchar		FieldName[SQL_MAX_DSN_LENGTH-1];
	UGuchar		TypeName[SQL_MAX_DSN_LENGTH-1];
};
typedef FIELDINFO FieldInfo;
typedef UGArray<FieldInfo> FieldInfos;

class UGEXPORT UGODBCBind
{
public:
	UGODBCBind();
	//! 构造绑定
	UGODBCBind(UGshort nPosP,UGint nTypeP,UGint nSizeP,UGString &strNameP,void *pDataP,UGint *pIndP);
	~UGODBCBind();

	void operator = (const UGODBCBind &bind)
	{
		nPos	= bind.nPos;
		nType	= bind.nType;
		nSize	= bind.nSize;
		strName	= bind.strName;
		pData	= bind.pData;
		pindicator	= bind.pindicator;
	}
public:
	UGshort			nPos;
	UGint			nType;
	UGint			nSize;
	UGString		strName;
	void			*pData;
	UGint			*pindicator;
};

typedef UGArray<UGODBCBind> UGODBCBinds;


//----------------------------------------------
//	名称：	ODBCDataTypeEnum
//	功能：	数据类型枚举常量
//	参数：	无
//	返回：	无
//  说明:	与DAO定义的数据类型常量一一对应
//----------------------------------------------
typedef enum ODBCDataTypeEnum {
		odbcBoolean = 1,
		odbcByte = 2,
		odbcInteger = 3,
		odbcLong = 4,
		odbcCurrency = 5,
		odbcSingle = 6,
		odbcDouble = 7,
		odbcDate = 8,
		odbcBinary = 9,
		odbcText = 10,
		odbcLongBinary = 11,
		odbcMemo = 12,
		odbcGUID = 15,
		odbcBigInt = 16,
		odbcVarBinary = 17,
		odbcChar = 18,
		odbcNumeric = 19,
		odbcDecimal = 20,
		odbcFloat = 21,
		odbcTime = 22,
		odbcTimeStamp = 23,
		odbcNVarChar = 127	//yanmb
} ODBCDataTypeEnum;


class UGEXPORT UGODBCConnection  
{
	friend class UGODBCCursor;
public:
	UGODBCConnection();
	virtual ~UGODBCConnection();

	//! \brief　连接到数据库
	//!  \details 
	//!  \param strDriver 　驱动类型　[in]
	//!  \param strServer 　服务名	　[in]
	//!  \param strServer　	数据库	  [in]
	//!  \param strUID		用户ID    [in]
	//!  \param strPWD　	用户密码  [in]
	//!  \return 连接成功返回True,否则返回FALSE
	UGbool DriverConnect(const UGString &strDriver,
					   const UGString  &strServer,
					   const UGString &strDatabase,
					   const UGString &strUID,
					   const UGString &strPWD);
	//! \brief　连接到数据库
	//!  \details 
	//!  \param strDriver 　驱动类型　[in]
	//!  \param strServer 　服务名	　[in]
	//!  \param strServer　	数据库	  [in]
	//!  \param strUID		用户ID    [in]
	//!  \param strPWD	　	用户密码  [in]
	//!  \return 连接成功返回True,否则返回FALSE
	UGbool DriverConnect(const UGchar * szDriver, 
					   const UGchar * szServer, 
					   const UGchar * szDatabase, 
					   const UGchar * szUID, 
					   const UGchar * szPWD);
	//! \brief　连接到数据库
	//!  \details 
	//!  \param szDSN 　	服务名	　[in]
	//!  \param szUID		用户ID    [in]
	//!  \param szPWD	　	用户密码  [in]
	//!  \return 连接成功返回True,否则返回FALSE
	UGbool Connect(const UGchar * szDSN,const UGchar * szUID,const UGchar * szPWD);
	//! \brief　连接到数据库
	//!  \details 
	//!  \param szDSN 　	服务名	　[in]
	//!  \param szUID		用户ID    [in]
	//!  \param szPWD　		用户密码  [in]
	//!  \return 连接成功返回True,否则返回FALSE
	UGbool Connect(const UGString &strDSN, const UGString &strUID, const UGString &strPWD);
	UGbool Connect();
	
	//! \brief　断开连接
	void DisConnect();

	//! \brief　判断是否已经连接到数据库
	//! \return 已连接返回True,否则返回FALSE
	UGbool IsConnected(){return m_bConnected;};
	
	//! \brief  执行
	UGuint ExecStatCount(const UGchar* pcSQL,const UGchar* pcFile);

	//! \brief  执行
	UGuint ExecStatCount(const UGchar* pcSQL, UGODBCBinds& binds, const UGchar* pcFile);
	//! \brief  执行
	UGbool ExecUpdate(const UGchar* pcSQL);

	//! \brief  驱动是否支持ODBC函数
	UGbool IsFunctionSupported(UGushort nFunctionID);

	//! \brief  获取服务名
	UGshort GetServerName(UGchar * szServer);

	//! \brief  获取数据库名
	//! \param szDatabase 获取的数据库名　[out]
	UGshort GetDatabaseName(UGchar * szDatabase);

	//! \brief  获取用户名
	//! \param szUser 获取的用户名　[out]
	UGshort GetUserName(UGchar * szUser);

	//! \brief  判断是否只读
	UGbool GetReadOnly();

	//! \brief  设置只读
	void SetReadOnly(UGbool bReadOnly);

	//! \brief  登录超时
	UGint GetLoginTimeOut();
	void SetLoginTimeOut(UGint nTimeOut);

	//! \brief  回滚
	UGbool TransRollBack();
	//! \brief  提交
	UGbool TransCommit();

	//! \brief  使用链接池
	void SetUsingConnpool(UGbool bUsingConnpool);

	//! \brief  判断是否使用了链接池
	UGbool IsUsingConnpool(){return m_bConnPool;};

private:
	UGbool Initialize();
	void dumpError( UGint type, SQLHANDLE hnd );

	//连接系统变量
public:
	SQLHENV m_hEnv;
	UGMutex m_mutex;
	SQLHDBC m_hDbc;
protected:
	UGbool m_bInitialed;
	UGbool m_bConnected;
	UGbool m_bDriverConnect;
	DSNINFO m_dsnInfo;
	DRIVERINFO m_drvInfo;
	SQLCHAR m_szConnStr[255]; 
	UGbool m_bConnPool;
};


struct ODBCERRORINFO 
{
	SDWORD  dwNativeError;
	UGuchar	szSqlState[SQL_MAX_MESSAGE_LENGTH];
	UGuchar	szErrorMsg[SQL_MAX_MESSAGE_LENGTH];
};
typedef ODBCERRORINFO odbc_error;
typedef UGArray<odbc_error> aryOdbcErrors;

//普通意外处理
class UGEXPORT UGODBCException
{
public:
	UGODBCException(){};
	~UGODBCException(){};
public:
	aryOdbcErrors m_aryErrors;
};

class UGEXPORT UGODBCCursor  
{
public:
	UGODBCConnection * m_pConnection;
	
	SQLHSTMT m_hStmt;
private:
	SQLUSMALLINT m_nOnceFetchCount;
	SQLUINTEGER * m_pnRowsFetched;
	UGbool m_bRowsetInited;

	UGint m_nUseConnectIndex;

public:
	//! \brief　执行SQL语句
	SQLRETURN Execute();
	//! \brief　执行SQL语句
	//! \param　nLineNumber　执行出错输出的信息
	//! \param　szFileName　 执行出错输出的信息
	SQLRETURN Execute(const UGuint nLineNumber,const UGchar * szFileName);
	//! \brief　执行SQL语句
	//! \param　nLineNumber　执行出错输出的信息
	//! \param　szFileName　 执行出错输出的信息
	SQLRETURN Execute(const UGuint nLineNumber,const UGchar * szFunctionName,const UGchar * szFileName);
	
	//! \brief　刷新绑定的数目
	void ClearRowset();
	//! \brief　设置绑定的数目
	//! \param　nOnceFetchCount　指定的数目
	//! \param　pnRowsFetched　  从数据库中确定的数目(如数据库内数据量小于指定的数目，则按此数目绑定)
	UGbool InitRowset(SQLUSMALLINT nOnceFetchCount,UGint * pnRowsFetched, SQLUSMALLINT * pRowStatusArray);
	//! \brief　输出错误信息
	void CheckError(const UGchar * strFileName, const UGchar * strFuncName, UGuint nLineNumber);
	
	//! \brief　执行SQL语句
	//! \param　strSQL　SQL语句
	SQLRETURN DirectExecute(const UGString &strSQL);
	//! \brief　执行SQL语句
	//! \param　szSQL　SQL语句
	SQLRETURN DirectExecute(const UGchar * szSQL);

	//! \brief　绑入
	UGint BindByPos(SQLUSMALLINT nParNumber,void *value,UGint nSize,void *indicator,UGint nDataType);
	UGint BindByPos(UGODBCBind &bind);
	UGint Bind(UGODBCBinds &aryBinds);

	//! \brief　绑出
	UGint DefineByPos(SQLUSMALLINT pos,void *value,UGint nSize,void *indicator,UGint nDataType);
	UGint DefineByPos(UGODBCBind &define);
	UGint Define(UGODBCBinds &aryDefines);
	
	//! \brief　设置连接
	void SetConnection(UGODBCConnection * conn);

	UGbool Open(UGint nCursorType = SQL_CURSOR_FORWARD_ONLY);
	//! \brief　释放句柄
	UGbool FreeStmt();

	//! \brief　检查SQL语句
	UGint Prepare(const UGString &strSQL);
	UGint Prepare(const UGchar * szSQL);
	UGint PrepareColumns(UGString strTableName);

	//! \brief　获取数据
	SQLRETURN Fetch();
	SQLRETURN FetchScroll(UGshort FetchOrientation, UGint nFetchOffset);
	UGbool Close();

	//! \brief　获取字段信息
	UGbool GetFieldInfo(SQLUSMALLINT nField ,
						UGString &strFieldName,
						SQLSMALLINT &nDataType,
						SQLUINTEGER &nColSize,
						SQLSMALLINT &nPrecision,
						SQLSMALLINT &nScale,
						SQLSMALLINT &nNullable);


	void SetOption(SQLUSMALLINT nConcurrency,SQLINTEGER nKey,SQLUSMALLINT nRowset);

	//! \brief　批处理
	SQLRETURN BulkOpration(SQLINTEGER nOnceCount, UGshort OprationType);
	SQLRETURN PutData(void *pData, UGint nBinaryLenght);
	SQLRETURN ParamData();

	UGODBCCursor();
	UGODBCCursor(UGODBCConnection * pConnection);
	virtual ~UGODBCCursor();
};

typedef enum SQLBulkOperationEnum{
		SQLInit = 1,
		SQLADD  = 2,
		SQLUpdate = 3
} SQLBulkOperationEnum;

class UGEXPORT UGColumnBind
{
public:
	//! \brief 定长字段
	UGColumnBind(UGshort Type, UGint nOnceFetch);
	//! \brief 不定长,char, text, memo , binary as so on;
	UGColumnBind(UGshort Type, UGint nOnceFetch, UGint nFieldLength);

	//! \brief　为字段赋值
	//! \param ItemIndex 字段索引[in]
	//! \param var		 字段值　[in]
	UGbool SetFieldValue(UGint ItemIndex, UGVariant& var);
	//! \brief　二进制值
	//! \param ItemIndex 字段索引[in]
	//! \param pData	 字段值　[in]
	//! \param nLength	 字段值长度　[in]
	UGint SetBinaryValue(UGint ItemIndex, void* pData, UGuint nLength);
	UGbool GetBinaryValue(UGint ItemIndex, UGbyte* &pData, UGuint &nLength);

	//! \brief　获取字段大小
	UGint GetFieldSize();
	//! \brief　获取字段类型
	UGshort GetFieldType();

	//! \brief　绑定的值
	UGbyte * GetData();

	SQLINTEGER * GetIndicator();

	~UGColumnBind();
private:
	UGint m_nFieldLength;
	UGint m_nFieldSize;
	UGint m_nOnceBulkCount;
	UGshort m_nType;
	
	UGbyte * m_pData;
	SQLINTEGER * m_pIndicator;
	UGuint * m_pBindOffSet;
};

class  UGEXPORT UGColumnBinds : public UGArray<UGColumnBind *>
{
public:
	
	UGColumnBinds()
	{
	};

	~UGColumnBinds()
	{
		ReleaseAll();
	};

public:

	void ReleaseAll();
	UGColumnBind * operator [](UGint nIndex) const;
};

}
#endif // !defined(AFX_UGODBCCONNECTION_H__173F3F2B_C652_4D91_B169_0BD07F4AA6C8__INCLUDED_)

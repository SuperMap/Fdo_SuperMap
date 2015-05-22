// UGODBCDatasource.h: interface for the UGODBCDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_)
#define AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_

#include "Engine/UGDataSource.h"
#include "UGODBCConnection.h"

namespace UGC
{

class UGEXPORT UGODBCDatasource : public UGDataSource
{
public:
	UGODBCDatasource();
	virtual ~UGODBCDatasource();

public:

	//! \brief  元数据操作
	virtual UGMetadata* GetMetaData();
	
	//! \brief  关闭数据源
	virtual void Close();

	//! \brief  保存数据信息
	virtual UGbool SaveInfo();

	//! \brief  数据源是否和数据连接
	virtual UGbool IsConnected();
		
	//! \brief  仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

	virtual UGEngineProc * GetEngineProc();

	//事务递交和撤销
	virtual UGbool BeginTrans();
	virtual void Commit();
	virtual void Rollback();

public:
	//! \brief 得到序列化的值，如果MODE为1 表示NEXT。否则CUR
	virtual UGuint GetSeqValue(UGString &strSeq,UGint nMode = 1);
	
	//! \brief 获取系统表的nextval,为了与SFC52保持兼容
	virtual UGuint GetSysTableSelValue(UGString strTableName, UGString strFieldName);
	
	//! \brief  得到各类系统表中序列化字段中的最大值
	virtual UGint GetMaxTableID();

	//! \brief  执行SQL语句，主要用于在数据库级执行的数据操作
	virtual UGbool Execute(const UGString& strSQL);

	//! \brief 获取数据集的记录数目
	//! \param strTableName 数据集名[in]
	//! \param strFilter	条件[in]
	UGint GetRecordCount(UGString strTableName,UGString strFilter = "");
protected:
	//! \brief 设置数据源信息
	UGbool SetDatasourceInfo();
	//! \brief　读取数据源信息
	UGbool ReadDatasourceInfo();
	
public:
	UGODBCConnection *m_pConnection;
	UGbool m_bConnected;

public:
	//! \brief 工作空间关联相关接口
	//! \brief　保存工作空间信息
	//! \param　conn　数据源连接信息[in]
	//! \param　strWksName 设置保存的名称[in]
	//! \param　nVersion   设置的版本号[in]
	//! \param	pbyte	　 工作空间文件[in]
	//! \param  nbyteSize  文件大小[in]
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	//! \brief　根据名称，加载工作空间
	//! \param　conn　数据源连接信息[in]
	//! \param　strWksName 名称[in]
	//! \param　nVersion   设置的版本号[out]
	//! \param	pbyte	　 工作空间文件[out]
	//! \param  nbyteSize  文件大小[out]
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	//! \brief　根据名称，获取工作空间相关信息
	//! \param　conn　数据源连接信息[in]
	//! \param  wksInfos  存储工作空间信息[out]
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	//! \brief　根据名称，删除工作空间信息
	//! \param　conn　数据源连接信息[in]
	//! \param　strWksName 名称[in]
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);
	
};

}


#endif // !defined(AFX_UGODBCDATASOURCE_H__BCB6E431_4D66_4B77_B645_8E75B07625EA__INCLUDED_)

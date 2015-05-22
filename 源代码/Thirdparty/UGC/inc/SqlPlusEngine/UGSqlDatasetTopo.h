// UGSqlDatasetTopo.h: interface for the UGSqlDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_)
#define AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "ODBCEngine/UGODBCConnection.h"
#include "SqlPlusEngine/UGSqlDatasource.h"

namespace UGC{

class SQLENGINE_API UGSqlDatasetTopo : public UGDatasetTopo  
{
	friend class UGSqlDatasource;

public:
	UGSqlDatasetTopo();
	UGSqlDatasetTopo(UGDataSource *pDS);
	virtual ~UGSqlDatasetTopo();

public:
	//! \brief 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! \brief 关闭数据集
	virtual void Close();

	//! \brief 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! \brief 返回创建时间
	virtual UGTime GetDateCreated();
	
	//! \brief 返回数据集名(可以和表名不同)
	virtual UGString GetName();

	//! \brief 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief 返回数据集的选项信息(用四字节的整型数据代表一些属性)
	virtual UGint GetOptions();

	//! \brief 保存数据集信息
	virtual UGbool SaveInfo();
	
	//! \brief 刷新数据集信息
	virtual UGbool RefreshInfo();

	//! \brief 设置数据集的选项信息
	virtual void SetOptions(UGint nOptions);

public:
	//! \brief 添加Topo数据集
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	//! \brief 为Topo数据集添加Topo规则
	// param pDatasetVector	源数据集	
	// param pdatasetCheck	目标数据集
	// param nRule			Topo规则
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	//! \brief 为Topo数据集添加Topo规则
	// param pDatasetVector	数据集	
	// param nRule			Topo规则
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! \brief 可以选择数据集及有关联的数据集来确定删除的Rule
	//!	\brief 要注意一个或两个数据集有多个Rule的情况，小心删错了噢
	// param nRule			Topo规则
	// param strSrcName		源数据集名
	// param strCheckName	目标数据集名
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

public:
	//! \brief 创建Topo数据集
	// param strName	数据集名称	
	UGbool Create(const UGString &strName);
	//! \brief　获取连接
	UGODBCConnection * GetConnection() const;	
};

}

#endif // !defined(AFX_UGSQLDATASETTOPO_H__22002727_16F3_4A2E_8D4A_1537DDD6DCAB__INCLUDED_)

// UGODBCDatasetTopo.h: interface for the UGODBCDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_)
#define AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "ODBCEngine/UGODBCConnection.h"
namespace UGC{

class UGEXPORT UGODBCDatasetTopo : public UGDatasetTopo  
{
public:
	UGODBCDatasetTopo();
	UGODBCDatasetTopo(UGDataSource *pDS);
	virtual ~UGODBCDatasetTopo();

public:
	//! \brief  打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! \brief  关闭数据集
	virtual void Close();

	//! \brief  返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! \brief  返回创建时间
	virtual UGTime GetDateCreated();
	
	//! \brief  返回数据集名(可以和表名不同)
	virtual UGString GetName();

	//! \brief  数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief  返回数据集的选项信息(用四字节的整型数据代表一些属性)
	virtual UGint GetOptions();

	//! \brief  保存数据集信息
	virtual UGbool SaveInfo();
	
	//! \brief  刷新数据集信息
	virtual UGbool RefreshInfo();

	//! \brief  设置数据集的选项信息
	virtual void SetOptions(UGint nOptions);

public:
	//! \brief　为Topo添加数据集
	//! \param　pDatasetVector　添加的数据集[in]
	//! \param　nPricision		优先级[in]
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	//! \brief　为Topo数据集添加Topo规则
	//! \param　pDatasetVector　源Topo数据集[in]
	//! \param　pdatasetCheck　	目标Topo数据集[in]
	//! \param　nRule			Topo规则[in]
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	//! \brief　为Topo数据集添加Topo规则
	//! \param　pDatasetVector　Topo数据集[in]
	//! \param　nRule			Topo规则[in]
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! \brief 可以选择数据集及有关联的数据集来确定删除的Rule
	//!	\brief 要注意一个或两个数据集有多个Rule的情况，小心删错了噢
	// param nRule			Topo规则
	// param strSrcName		源数据集名
	// param strCheckName	目标数据集名
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

public:
	//! \brief　创建Topo数据集
	// param strName Topo数据集名[in]
	UGbool Create(const UGString &strName);

	//! \brief 获得连接
	UGODBCConnection * GetConnection() const;
};

}

#endif // !defined(AFX_UGODBCDATASETTOPO_H__9C1FD9BA_1546_404F_9BDB_BCBFA5C28518__INCLUDED_)

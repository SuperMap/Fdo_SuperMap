// UGOrcDatasetTopo.h: interface for the UGOrcDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_)
#define AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_

#include "Engine/UGTopoDataset.h"
#include "Engine/UGDataSource.h"
#include "OrcEngine/UGOCIConnection.h"

namespace UGC{

class ORCENGINE_API UGOrcDatasetTopo : public UGDatasetTopo
{
	friend class UGOrcDataSource;
public:
	UGOrcDatasetTopo();
	UGOrcDatasetTopo(UGDataSource *p);
	virtual ~UGOrcDatasetTopo();

public:
	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据集
	virtual void Close();

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! 返回创建时间
	virtual UGTime GetDateCreated();
	
	//! 返回数据集名(可以和表名不同)
	virtual UGString GetName();

	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! 返回数据集的选项信息(用四字节的整型数据代表一些属性)
	virtual UGint GetOptions();

	//! 保存数据集信息
	virtual UGbool SaveInfo();
	
	//! 刷新数据集信息
	virtual UGbool RefreshInfo();

	//! 设置数据集的选项信息
	virtual void SetOptions(UGint nOptions);

public:
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

	void U_CheckError() const;
	
public:
	UGbool Create(const UGString &strName);
	UGOCIConnection * GetConnection() const;

	friend class UGOrcDataSource;
};
}
#endif // !defined(AFX_UGORCDATASETTOPO_H__2749D3DB_8387_4EC3_B436_5D6784AEB79D__INCLUDED_)

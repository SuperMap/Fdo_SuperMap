// UGDatasetTopo.h: interface for the UGDatasetTopo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)
#define AFX_UGDATASETTOPO_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_

#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"

namespace UGC{

	struct UGTopoDTPricision
	{
		UGDatasetVector *pDataset;
		UGint nPricision;
	};

	struct UGTopoRule
	{
		UGint nID;
		UGDatasetVector *pDataset;
		UGDatasetVector *pCheckDataset;
		UGint nRule;
	};

class ENGINE_API UGDatasetTopo : public UGDataset
{
public: 
	UGDatasetTopo();
	virtual ~UGDatasetTopo();

public:
	enum TopoRuleMode
	{
		UGTopoRegionOverlapB			=0,	
		UGTopoRegionGapsS				=1,	
		UGTopoRegionNotCoveredM			=2,	
		UGTopoRegionNotCoveredEachM		=3,	
		UGTopoRegionNotContainedM		=4,	
		UGTopoRegionNotContainPointM	=5,	
		UGTopoLineOverlapB				=6,	
		UGTopoLineOverlapSelfS			=7,	
		UGTopoLineIntersectS			=8,	
		UGTopoLineIntersectSelfS		=9,	
		UGTopoLineIntersectORTouchS		=10,
		UGTopoLineDangleNodeS			=11,
		UGTopoLinePseudoNodeS			=12,
		UGTopoLineEndPointNotCoveredM	=13,
		UGTopoPointNotContainedM		=14,
		UGTopoPointNotCoveredByEndPointM=15,
		UGTopoBoundaryNotCoveredM		=16,
		UGTopoMultiPartS				=17,
	};
	
	//! 返回数据集类型
	virtual DatasetType GetType() const{
		return Topo;
	};

	//! 返回数据集对应表名
	virtual UGString GetTableName();

	//! 返回最小高程
	virtual UGdouble GetMinZ();

	//! 设置最小高程
	virtual void SetMinZ(UGdouble d);

	//! 返回最大高程
	virtual UGdouble GetMaxZ();

	//! 设置最大高程
	virtual void SetMaxZ(UGdouble d);

	//! 返回数据集的维数
	virtual UGint GetDimension();

	//! 判断是否是矢量数据集
	virtual UGbool IsVector();

	//! 判断是否是topo数据集
	virtual UGbool IsTopoDataset();

	//! 判断是否是栅格数据集
	virtual UGbool IsRaster();

	virtual UGbool IsLinkTable(){return FALSE; };

	//! 返回数据集的范围
	virtual const UGRect2D& GetBounds() const
	{
		return m_rcBounds;
	};

	//! 设置数据集的范围
	virtual void SetBounds(const UGRect2D& r);

	//! 返回空间数据编码方式
	virtual UGDataCodec::CodecType GetCodecType();
	
	//! 设置空间数据编码方式
	virtual void SetCodecType(UGDataCodec::CodecType c);

public:
	UGdouble GetInterval();
	void SetInterval(UGdouble dInterval);
	UGbool SaveDirtyRegion(UGGeoRegion *pGeo);
public:
	//topo相关
	//! \brief 向Topo数据集里添加一个数据集
	//! \param *pDatasetVector [in] 数据集
	//! \param dInterval [in] 容限
	//! \return 。
	//! \remarks 必须是同一个数据源的数据集
	//! \attention 
	virtual UGbool AddDataset(UGDatasetVector *pDatasetVector,UGint nPricision);

	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,UGDatasetVector *pdatasetCheck,TopoRuleMode nRule);
	virtual UGbool AddRule(UGDatasetVector *pDatasetVector,TopoRuleMode nRule);

	//! 可以选择数据集及有关联的数据集来确定删除Rule
	//　要注意一个或两个数据集有多个Rule的情况，小心删错了噢
	virtual UGbool DeleteRule(TopoRuleMode nRule, const UGString &strSrcName, const UGString &strCheckName = "");

	//! 获得Topo子数据集,基类实现
	virtual UGbool GetAllRelation(UGArray<UGTopoDTPricision> &aryTopoRelations);

	virtual UGbool GetAllRules(UGArray<UGTopoRule> &aryRules);

	//! 获得Topo错误数据集,基类实现
	virtual UGDatasetVector * GetPointErrorDataset();
	virtual UGDatasetVector * GetLineErrorDataset();
	virtual UGDatasetVector * GetRegionErrorDataset();
	virtual UGDatasetVector * GetDirtyAreaDataset();

	UGGeoRegion * GetDirtyArea();

protected:
	virtual UGbool AddSubDataset(UGTopoDTPricision structTopo);
	
protected:
	//! 数据集的子数据集指针
	UGSubDtArray m_ArySubDataset;
	UGArray<UGTopoDTPricision> m_aryTopoRelationDts;
	UGArray<UGTopoRule> m_aryTopoRules;
	UGString m_strName;
	UGint m_nOptions;
	UGRect2D m_rcBounds;
	UGdouble m_dInterval;
};

}

#endif // !defined(AFX_UGDatasetTopo_H__6F79F774_FF2A_4EB2_AB64_A5958D572828__INCLUDED_)

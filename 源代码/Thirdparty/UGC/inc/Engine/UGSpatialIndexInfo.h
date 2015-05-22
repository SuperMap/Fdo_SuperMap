// UGSpatialIndexInfo.h: interface for the UGSpatialIndexInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)
#define AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDatasetVectorInfo.h"

namespace UGC {

class ENGINE_API UGSpatialIndexInfo  
{
public:
	UGSpatialIndexInfo();

	//索引类型构造
	UGSpatialIndexInfo(IndexType nIndexType);

	//多级网格索引构造函数
	UGSpatialIndexInfo(UGPoint2D	pntCenter,
						UGdouble	dGrid0,
						UGdouble	dGrid1,
						UGdouble	dGrid2,
						UGdouble	dGridRatio);

	//R树索引构造函数
	UGSpatialIndexInfo(UGint nQuality,UGString strSort);

	//图幅索引
	UGSpatialIndexInfo(UGString	strTileFieldName);

	//图幅索引
	UGSpatialIndexInfo(UGdouble	dWidth,UGdouble	dHeight);

	//四叉树索引
	UGSpatialIndexInfo(UGint nLevel);

	virtual ~UGSpatialIndexInfo();

public:
	IndexType	nIndexType; 
	UGint		nQuality;	//R树，这个值 * 50，为叶子包的对象个数
	UGString	strSort;	//扩展，R树索引权重字段，如果为了显示，并且QueryMode 为FuzzyQuery的时候使用

	UGString	strTileFieldName;	//图幅索引，创建索引依赖的字段
	UGdouble	dWidth;				//图幅索引，创建索引格子的宽度
	UGdouble	dHeight;			//图幅索引，创建索引格子的高度

	UGPoint2D	pntCenter;	//多级网格索引中中心点的位置
	UGdouble	dGrid0;		//多级网格索引中0级的格子的宽度
	UGdouble	dGrid1;		//多级网格索引中1级的格子的宽度
	UGdouble	dGrid2;		//多级网格索引中2级的格子的宽度
	UGdouble	dGridRatio;	//多级网格索引中格子的大小
};

}

#endif // !defined(AFX_UGSPATIALINDEXINFO_H__DFDA261E_05C0_46C7_A3E6_08A2A6CAA872__INCLUDED_)

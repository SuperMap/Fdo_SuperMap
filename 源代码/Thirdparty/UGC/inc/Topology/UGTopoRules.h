/* 
	\file UGTopoRulesCheck.h
	\brief 拓扑规则类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTOPORULESCHECK_H
#define UGTOPORULESCHECK_H

#include "Engine/UGTopoDataset.h"
#include "Topology/UGTopoOperators.h"
#include "Topology/UGTopoSpatialQuery.h"

namespace UGC {

class TOPOLOGY_API UGTopoRulesCheck
{
public:
	UGTopoRulesCheck();
	virtual ~UGTopoRulesCheck();
	
	//! \brief 设置容限
	/**
	 \param		dInterval	设置的容限
	 \return	设置成功返回TRUE，无错误返回FALSE
	 \remarks	如dInterval<EP,则种子动设置为EP
	*/
	void SetInterval(UGdouble dInterval);
	
	//! \brief 获取已设置的容限
	/**
	 \param		dInterval	设置的容限
	 \return	返回容限值
	 \remarks	
	*/
	UGdouble GetInterval();
	
	//! \brief 拓扑预处理结点捕捉
	/**
	  \param	arrDTPricision		数据集指针以及精度信息数组
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	适用于点、线、面数据集
	*/
	UGbool TopoIniNodeSnap(UGArray<UGTopoDTPricision> &arrDTPricision);
	
	//! \brief 拓扑预处理插入交点
	/**
	  \param	arrpDatasets		数据集指针数组
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	适用于点、线、面数据集
	*/
	UGbool TopoIniIntersectPnt(UGArray<UGDatasetVector*>arrpDatasets);
	
	//! \brief 拓扑预处理检查多边形岛洞关系
	/**
	  保证复杂对象岛、洞多边形坐标顺序按顺、逆时针排序
	  \param	arrpDatasets		数据集指针数组
	 \return	参数合法返回TRUE，	无错误返回FALSE
	 \remarks	适用于面数据集
	*/
	UGbool TopoIniCheckPolygon(UGArray<UGDatasetVector*>arrpDatasets);
	
	//! \brief 检查出交叠的面对象
	/**
	同一数据集内相互交叠的对象
	 \param		pDTRegion			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionOverlap(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	
	//! \brief 检查出交叠的面对象
	/**
	必须是pDTRegion和pDTOverlap相互交叠的对象
	 \param		pDTRegion			面数据集指针
	 \param		pDTOverlap			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionOverlap(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
									UGArray<UGint> &arrCheckIDs);
	
	//! \brief 检查出面数据集的内部间隙(错误边界)
	/**
	 \param		pDTRegion			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionGaps(UGRecordset *pRecordset, UGArray<UGGeoLine*> &arrpGeoLines);
	
	//! \brief 检查出没有被完全覆盖的面对象
	/**
	检查出pDTRegion内没有被pDTCover内的对象完全覆盖的对象,可以是几个对象覆盖一个对象
	 \param		pDTRegion			面数据集指针
	 \param		pDTCover			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotCovered(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
									UGArray<UGGeoRegion*> &arrpGeoRegion);
	
	//! \brief 检查出没有被完全覆盖的面对象
	/**
	pDTRegion中的对象与pDTCover中的对象必须完全互相覆盖
	 \param		pDTRegion			面数据集指针
	 \param		pDTCover			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotCoveredEach(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs,
										UGArray<UGGeoRegion*> &arrpGeoRegion);
	
	//! \brief 检查出没有被完全包含的面对象
	/**
	pDTRegion中的每个面对象必须被pDTContain中的某个面对象包含
	 \param		pDTRegion			面数据集指针
	 \param		pDTContain			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckRegionNotContained(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief 查找出内部没有点的面对象
	/**
	 \param		pDTRegion			面数据集指针
	 \param		pDTPoint			点数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	面对象内必须至少包含一个点，否则就是错误面对象
	*/
	UGbool TopoCheckRegionNotContainPoint(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出数据集内相互交叠的对象
	/**
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlap(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	
	//! \brief 检查出数据集内自交叠的对象
	/**
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlapSelf(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief 线数据集之间不能有相互交叠的对象
	/**
	在pDTLine中查出与pDTOverlap中对象有重叠部分的线对象
	 \param		pDTLine			线数据集指针
	 \param		pDTOverlap			线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineOverlap(UGRecordset *pRecordset, UGRecordset *pRSCheck, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrCheckIDs);
	
	//! \brief 检查出有相交关系的线对象
	/**
	  这里相交指的是线与线之间的内部相交，也就是不包括交点是某条线的端点的情况，
	  但包括线之间有重叠的情况
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersect(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出有自相交关系的线对象
	/**
	  自相交包括内部交叠或内部交叉良种情况
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersectSelf(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出有自相交或接触关系的线对象
	/**
	  与Intersect相比，这种情况增加了边界和内部相交的情况
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineIntersectORTouch(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出具有悬点的线对象
	/**
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineDangleNode(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts);
	
	//! \brief 检查出具有伪结点的线对象
	/**
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLinePseudoNode(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts);
	
	//! \brief 检查出端点没有被点覆盖的线对象
	/**
	 \param		pDTLine				线数据集指针
	 \param		pDTPoint			点数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckLineEndPointNotCovered(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs, 
											UGArray<UGPoint2D> &arrpnts);
	
	//! \brief 检查出没有被面完全包含的点对象
	/**
	 \param		pDTPoint			点数据集指针
	 \param		pDTRegion			面数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	点在面的边界上也算错误
	*/
	UGbool TopoCheckPointNotContained(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出没有被线的端点覆盖的点对象
	/**
	 \param		pDTPoint			点数据集指针
	 \param		pDTLine				线数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	
	*/
	UGbool TopoCheckPointNotCoveredByEndPoint(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出pDataset中对象的边界没有被pDTCover中对象的边界完全覆盖的对象
	/**
	 \param		pDataset			数据集指针
	 \param		pDTCover			数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	pDataset可以是点、线、面数据集；pDTCover可以线、面数据集
	*/
	UGbool TopoCheckBoundaryNotCovered(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs);
	
	//! \brief 检查出pDataset中的复合对象
	/**
	  对于有些数据需要保证内部不能有复合对象,我们可以通过这个规则进行检查
	  \param	UGTopoDTPricision	数据集指针
	 \return	参数合法返回TRUE，无错误返回FALSE
	 \remarks	适用于线、面数据集
	*/
	UGbool TopoCheckMultiPart(UGRecordset *pRecordset, UGArray<UGint> &arrIDs);
	
private:
	
	UGdouble m_dInterval;
	UGGeoRegion *m_pGeoDirtyArea;
	UGTopoOperators m_TopoOperators;
	UGTopoSpatialQuery m_TopoSpatialQuery;
	
	UGbool GetObjectIDs(TopoGridEnv &TopoGridUnit, UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrCheckIDs);
	/*!	\brief	二分查找\n	
*	\param nValue		要查询的值
*	\param pData		数据指针
*	\param nCount		数据长度
  *	\return	 返回nValue在pData的位置索引，不存在则返回-1；
  *	\remarks pData必须已经排好序
	*/
	UGint FindIndex(UGint nValue, UGint* pData, UGint nCount);
	UGbool GetSnapSegment(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
							UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
							UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs, 
							UGArray<UGint> &arrPricision);
	UGbool GetSnapPnt(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
						UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
						UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs, 
						UGArray<UGint> &arrPricision);
	UGbool GetIntersectPnt(UGRect2D& rcBounds, UGArray<UGRecordset*> &arrpRecordset, 
							UGArray<UGTopoGridUnitNodesEx*> &parrArcIntersetPoints,
							UGArray<UGPoint2D> &pIntersetPoints, UGArray<UGint*> &arrpIDs);
	UGbool TopoIniVertexSnapSegment(UGArray<UGDatasetVector*>parrDatasets, UGArray<UGint>arrPricision);
	UGbool TopoIniVertexSnapVertex(UGArray<UGDatasetVector*>parrDatasets, UGArray<UGint>arrPricision);
	UGbool RegionsCovered(UGDatasetVector *pDTRegion, UGDatasetVector *pDTCover);
	UGbool RegionsOverlap(UGDatasetVector *pDTRegion, UGDatasetVector *pDTOverlap);
	UGbool RegionsOverlap(UGDatasetVector *pDTRegion);
	UGbool RegionGaps(UGDatasetVector *pDTRegion);
	UGbool PntCoverByLine(UGDatasetVector *pDatasetPoint, UGDatasetVector *pDTLine);
	UGbool EndPointCoverByPnt(UGDatasetVector *pDTLine, UGDatasetVector *pDatasetPoint);
	UGbool PointCoverPoint(UGPoint2Ds &arrPoint1, UGPoint2Ds &arrPoint2, UGRect2D &rcBound, 
							UGArray<UGint> &arrPointIndex);
	UGbool ContainPiont(UGDatasetVector *pDatasetRegion, UGDatasetVector *pDatasetPoint);
	UGbool LineBeCoverByLine(UGDatasetVector *pDatasetLine1, UGDatasetVector *pDatasetLine2, UGbool bCover);
	UGbool NotOverlap(UGDatasetVector *pDTLine, UGbool bSelf);
	UGbool NotIntersect(UGDatasetVector *pDTLine, UGbool bSelf);
	
	UGbool PointCoverPoint(UGPoint2Ds &arrPoint1, UGPoint2Ds &arrPoint2, UGRect2D &rcBound, 
		UGArray<UGint> &arrPointIndex, UGdouble dTolerance);
	UGbool PickUpBoundary(UGDatasetVector *pDTRegion, UGArray<UGint*> &parrSegment, 
		UGArray<UGint> &arrSegmentCount);
	UGbool CheckOverlap(UGDatasetVector *pDTRegion, UGArray<UGint*> &parrSegment, UGArray<UGint> &arrSegmentCount);
	UGbool PickUpGaps(UGDatasetVector *pDTRegion, UGArray<int*> &parrSegment, 
		UGArray<UGint> &arrSegmentCount);
	UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset,
		UGArray<UGint*> &parrSegment, UGArray<UGint> &arrSegmentCount,
		UGArray<UGint>& arrIDs, UGbool IsDelCommonLine);
	void MakeCommonLine(UGDatasetVector *pRegion, UGArray<int*> &parrSegment,
		UGDatasetVector *pDataset, UGbool bAddMaidenLine);
	
	UGbool GetDisJointID(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrResIDs);
};

}

#endif


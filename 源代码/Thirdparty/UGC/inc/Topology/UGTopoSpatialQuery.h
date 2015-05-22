/* 
	\file UGTopoSpatialQuery.h
	\brief 空间查询拓扑实现类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTOPOSPATIALQUERY_H
#define UGTOPOSPATIALQUERY_H

#include "Topology/UGTopoOperators.h"

namespace UGC {

class UGTopoGrid;
class TOPOLOGY_API UGTopoSpatialQuery
{
public:
	UGTopoSpatialQuery();
	virtual ~UGTopoSpatialQuery();
	
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
	
	//! \brief 对象查询记录集
	/**
	\param		pGeoQuery	设置的容限
	\param		pGeoQuery	设置的容限
	\param		pGeoQuery	设置的容限
	\return		设置成功返回TRUE，无错误返回FALSE
	\remarks	如dInterval<EP,则种子动设置为EP
	*/
	UGbool LineIntersectPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIntersectLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIntersectRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIntersectPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIntersectLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIntersectRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineTouchPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineTouchLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineTouchRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionTouchPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionTouchLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionTouchRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineOverlapLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionOverlapRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineCrossLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineCrossRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineContainPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineContainLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionContainPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionContainLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionContainRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineWithinLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineWithinRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionWithinRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIdenticalLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset,UGArray<UGint> &arrResIDs,UGint nDimension=1);
	UGbool RegionIdenticalRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionContainCentroid(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool CommonSegment(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool CommonPoint(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIIPoints(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIIRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIIRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIBRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIBLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIBRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIELines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineIERegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionIERegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineBILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionBILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionBIRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineBBLines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionBELines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionBERegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineEILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionEILines(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionEIRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LineEBRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionEBRegions(UGGeometry* pGeoQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	
	UGbool PointsIntersectPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsIntersectLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsIntersectRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIntersectPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIntersectLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIntersectRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIntersectRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsTouchLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsTouchRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesTouchLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesTouchRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsTouchRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesOverlapLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsOverlapRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesCrossLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesCrossRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesContainLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsContainLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsContainRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsWithinRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesWithinRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesWithinLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsTouchLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsTouchPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesTouchPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIntersectPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIntersectLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIdenticalLines(UGRecordset *pRSQuery,UGRecordset *pRecordset,UGArray<UGint> &arrResIDs,UGint nDimension=1);
	UGbool RegionsIdenticalRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsContainLinesCentroid(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsContainRegionsCentroid(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool CommonSegment(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool CommonPoint(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsIIPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsIILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool PointsIIRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIIPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIIRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIIPoints(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIIRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIBRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIBRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIELines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesIERegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsIERegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesBILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsBILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsBIRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesBBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesBBRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsBBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesBELines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesBERegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsBELines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsBERegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesEILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsEILines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsEIRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesEBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool LinesEBRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsEBLines(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool RegionsEBRegions(UGRecordset *pRSQuery, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	
	UGbool BuildTopoGrid(UGGeometry* pGeometry, TopoGridEnv& TopoGridUnit, UGTopoOperators::UGTopoGridType GridType);
	UGbool BuildTopoGrid(UGRecordset *pRecordset, UGdouble dGridCount, TopoGridEnv& TopoGridUnit, UGTopoOperators::UGTopoGridType GridType);
	
	UGbool GetTouchPointIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool GetPointIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	
	UGbool GetPLineIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	UGbool GetPRegionIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	
	UGbool GetLLineIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	UGbool GetLRegionIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	
	UGbool GetGeoRLineIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	UGbool GetRSRLineIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	
	UGbool GetRRegionIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	UGbool GetRSRRegionIDs(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, UGTopoOperators::UGTopoType nType);
	
	UGbool IsRectIntersect(const UGRect2D& rcBound, TopoGridEnv& TopoGridUnit);

private:	
	UGint IsWithin(const UGPoint2D& pnt, TopoGridEnv& TopoGridUnit, UGTopoGrid *pGridUnit, UGbool bBorder=TRUE);
	UGbool IsWithin(const UGPoint2D* pPoints, UGint nPointCount, TopoGridEnv& TopoGridUnit, UGTopoGrid *pGridUnit, UGbool bBorder=TRUE);
	UGbool IsOverlap(const UGPoint2D* pPoints, UGint nPointCount, TopoGridEnv& TopoGridUnit, UGTopoGrid *pGridUnit);
	
private:
	UGdouble m_dInterval;
	UGTopoOperators m_TopoOperators;
};


}

#endif 



/* 
	\file UGTopoOperators.h
	\brief 拓扑操作类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTOPOOPERATORS_H
#define UGTOPOOPERATORS_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoTypes.h"

namespace UGC {

	
class TOPOLOGY_API UGTopoOperators
{
public:
	UGTopoOperators();
	virtual ~UGTopoOperators();
	
	//!	\brief	拓扑网格化模式
	enum UGTopoGridType
	{
		//! \brief 网格化端点
		UGTopoEndPoint	= 1,	
		//! \brief 网格化顶点
		UGTopoVertex	= 2,	
		//! \brief 网格化线段
		UGTopoSegment	= 3,	
		//! \brief 网格化Bounds
		UGTopoBounds	= 4,	
	};
	
	enum UGTopoType
	{
		UGTopoNULL					= 0,
		UGTopoCommonSegment			= 1,
		UGTopoContain				= 2,
		UGTopoCross					= 3,
		UGTopoDisjoint				= 4,
		UGTopoIdentical				= 5,
		UGTopoIntersect				= 6,
		UGTopoOverlap				= 7,
		UGTopoTouch					= 8,
		UGTopoWithin				= 9,
		UGTopoInteriorToInterior	= 10,
		UGTopoInteriorToBoundary	= 11,
		UGTopoInteriorToExterior	= 12,
		UGTopoBoundaryToInterior	= 13,
		UGTopoBoundaryToBoundary	= 14,
		UGTopoBoundaryToExterior	= 15,
		UGTopoExteriorToInterior	= 16,
		UGTopoExteriorToBoundary	= 17,
	};

//	/*!	\brief	拓扑网格化模式： */
//	enum UGTopoGridType
//	{
//		UGTopoEndPoint	= 1,	//网格化端点
//		UGTopoVertex	= 2,	//网格化顶点
//		UGTopoSegment	= 3,	//网格化线段
//	};
	
	//! \brief 设置容限
	
	 //! \param		dInterval	设置的容限
	 //! \return	设置成功返回TRUE，无错误返回FALSE
	 //! \remarks	如dInterval<EP,则种子动设置为EP
	
	void SetInterval(UGdouble dInterval);
	
	//! \brief 获取已设置的容限
	
	//!  \param		dInterval	设置的容限
	//!  \return	返回容限值

	UGdouble GetInterval();
	
	UGbool IniTopoGridEnv(TopoGridEnv& TopoGridUnit, UGRect2D& rcBounds, UGdouble dGridCount);
	
	UGbool BuildTopoGrid(TopoGridEnv& TopoGridUnit, UGPoint2D* pPoints, UGint* pPolyCount, UGint nSubCount,
						UGTopoGridType GridType);
	
	UGbool GetPointIDs(TopoGridEnv &TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, 
						UGbool bIntersect);
	
	UGbool BuildTopoGrid(UGRecordset *pRecordset, TopoGridEnv& TopoGridUnit, UGTopoGridType GridType);
	
	UGbool GetBoundPointIDs(TopoGridEnv &TopoGridUnit, UGArray<UGPoint2D> &arrPoints, UGArray<UGint> &arrIDs,
							UGArray<UGint> &arrResIDs, UGbool bContain=TRUE);
	
	UGbool GetLineIDs(TopoGridEnv &TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs, 
						UGTopoGridType GridType);
	
	UGbool BuildTopoGridBounds(UGRecordset *pRecordset, TopoGridEnv& TopoGridUnit);
	
	UGbool PickUpPolygon(UGRecordset* pRecordset, UGDatasetVector *pDataset, UGbool IsShowProgress=TRUE);
	
	UGbool PickUpLine(UGDatasetVector *pDataset, UGDatasetVector *pDTLine, UGbool IsShowProgress=TRUE);
	UGbool PickUpLine(UGRecordset* pRecordset, UGDatasetVector *pDTLine, UGbool IsShowProgress=TRUE);
	
	UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset,
							UGArray<UGint*> &parrSegment, UGArray<UGint>& arrIDs,
							UGbool IsDelCommonLine);
	
	UGbool MakeCommonLine(UGRecordset *pRecordset, UGArray<UGint*> &parrSegment,
						UGDatasetVector *pDataset, UGbool bAddMaidenLine, UGbool IsShowProgress);
	
	void TopoBoundsToGrid(UGRecordset* pRecordSet,UGRect2D FullMapExtent,UGArray<UGint>&arrIDs,
							UGTopoGrid *&pGridUnit, UGdouble &dGridCount);
	
	UGbool PolygonIntersect(const TopoGridEnv &TopoGridUnit, UGArray<UGGeoRegion*> &arrpRegion, 
							TOverlayID* pID, UGbool bIgnoreSrc, UGbool bSrc);
	
	UGbool IniDataset(UGDataSource *& pDataSource, UGDatasetVector *&pDatasetSrcTemp,
					UGDatasetVector *&pDatasetTagTemp);
	
	UGbool IsRectIntersect(const UGRect2D& rcBound, TopoGridEnv& TopoGridUnit);
	UGbool BuildGridBounds(UGRecordset *pRecordset, TopoGridEnv& TopoGridUnit);

private:
	
	UGbool BuildTopoGridSegment(TopoGridEnv& TopoGridUnit, UGPoint2D* pPoints, UGint* pPolyCount, UGint nSubCount);
	
	UGbool BuildTopoGridPoint(TopoGridEnv& TopoGridUnit, UGPoint2D* pPoints, UGint nCount);

private:	
	UGdouble m_dInterval;
};

}

#endif


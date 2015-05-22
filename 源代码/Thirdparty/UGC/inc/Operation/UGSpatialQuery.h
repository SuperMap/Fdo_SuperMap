/* 
	\file UGSpatialQuery.h
	\brief 空间查询类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGSPATIALQUERY_H
#define UGSPATIALQUERY_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoSpatialQuery.h"

namespace UGC {

class OPERATION_API UGSpatialQuery  
{
public:
	UGSpatialQuery();
	virtual ~UGSpatialQuery();
	
	enum UGSpatialQueryMode
	{
		UGIdentical						=0,	
		UGDisjoint						=1,	
		UGIntersects					=2,	
		UGTouches						=3,	
		UGOverlaps						=4,	
		UGCrosses						=5,	
		UGWithin						=6,	
		UGContains						=7,	
		UGExtentIntersect				=8,	
		UGRelate						=9,	
		
		UGCommonPoint					=10,
		UGCommonSegment					=11,
		UGCentroidInPolygon				=12,
	};
	
public:
	//! \brief 对象查询记录集
	/**
	\param		pRecordset		被查询记录集
	\param		pGeoQuery		查询对象
	\param		nMode			查询模式
	\param		strRelate		UGRelate模型的字符串表达式
	\return		返回查询出来的记录集,无结果返回NULL
	\remarks	
	*/
	UGRecordset* Query(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief 对象查询数据集
	/**
	\param		pDataset		被查询数据集
	\param		pGeoQuery		查询对象
	\param		nMode			查询模式
	\param		strRelate		UGRelate模型的字符串表达式
	\return		返回查询出来的记录集,无结果返回NULL
	\remarks	strRelate只有在自定义模型(UGRelate)下才有意义
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief 记录集查询记录集
	/**
	\param		pRecordset		被查询记录集
	\param		pRSQuery		查询记录集
	\param		nMode			查询模式
	\param		strRelate		UGRelate模型的字符串表达式
	\return		返回查询出来的记录集,无结果返回NULL
	\remarks	strRelate只有在自定义模型(UGRelate)下才有意义
	*/
	UGRecordset* Query(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief 记录集查询数据集
	/**
	\param		pDataset		被查询数据集
	\param		pRSQuery		查询记录集
	\param		nMode			查询模式
	\param		strRelate		UGRelate模型的字符串表达式
	\return		返回查询出来的记录集,无结果返回NULL
	\remarks	strRelate只有在自定义模型(UGRelate)下才有意义
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGRecordset *pRSQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
	//! \brief 数据集查询数据集
	/**
	\param		pDataset		被查询数据集
	\param		pDTQuery		查询数据集
	\param		nMode			查询模式
	\param		strRelate		UGRelate模型的字符串表达式
	\return		返回查询出来的记录集,无结果返回NULL
	\remarks	strRelate只有在自定义模型(UGRelate)下才有意义
	*/
	UGRecordset* Query(UGDatasetVector *pDataset, UGDatasetVector *pDTQuery, UGSpatialQueryMode nMode,
						const UGString& strRelate=(""), UGQueryDef::CursorType nCursorType=UGQueryDef::OpenStatic);
	
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
	
private:
	UGbool Query(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGSpatialQueryMode nMode, UGArray<UGint> &arrIDs, 
				const UGString& strRelate);
	UGbool InteriorToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToExterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToExterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToInterior(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToBoundary(UGRecordset *pRecordset, UGGeometry *pGeoQuery, UGArray<UGint> &arrResIDs);
	
	UGbool InteriorToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool InteriorToExterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool BoundaryToExterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToInterior(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool ExteriorToBoundary(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryIdentical(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryIdentical(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryDisjoint(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGRecordset *pRecordset, UGArray<UGint> &arrResIDs);
	UGbool QueryDisjoint(UGDatasetVector *pDataset, UGDatasetVector *pDTQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryIntersects(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryIntersects(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryTouches(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryTouches(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryOverlaps(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryOverlaps(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryCrosses(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCrosses(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryWithin(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryWithin(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryContains(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryContains(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryExtentIntersect(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryExtentIntersect(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryRelate(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs, const UGString& strRelate);
	UGbool QueryRelate(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs, const UGString& strRelate);
	
	UGbool QueryCommonPoint(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCommonPoint(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
	UGbool QueryCommonSegment(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCommonSegment(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);	
	
	UGbool QueryCentroidInPolygon(UGRecordset *pRecordset, UGGeometry* pGeoQuery, UGArray<UGint> &arrResIDs);
	UGbool QueryCentroidInPolygon(UGRecordset *pRecordset, UGRecordset *pRSQuery, UGArray<UGint> &arrResIDs);
	
private:
	
	UGdouble m_dInterval;
	UGTopoSpatialQuery m_SpatialQuery;
	UGTopoOperators m_TopoOperators;
	
	//=======================这个方法需要放到算法库里===============================
	UGint FindIndex(UGint nValue, UGint* pData, UGint nCount);
	UGbool GetDisJointID(UGRecordset *pRecordset, UGArray<UGint> &arrIDs, UGArray<UGint> &arrResIDs);
	UGbool GetExtentIntersectID(const UGRect2D& rcBoundsSrc, UGRecordset *pRecordset, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrResIDs);
	UGbool GetExtentIntersectID(TopoGridEnv& TopoGridUnit, UGRecordset *pRecordset, UGArray<UGint> &arrIDs, 
								UGArray<UGint> &arrResIDs);
	
};

}

#endif // !defined(UGSPATIALQUERY_H)

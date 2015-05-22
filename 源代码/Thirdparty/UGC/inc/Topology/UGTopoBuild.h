#ifndef UGTOPOBUILD_H
#define UGTOPOBUILD_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoTypes.h"
#include "Base/UGBitArray.h"

namespace UGC {

class UGTopoFile;

class TOPOLOGY_API UGTopoBuild  
{

public:
	UGTopoBuild();
	UGTopoBuild(UGDatasetVector *pDataset);
	virtual ~UGTopoBuild();
	
public:
	
	void SetInterval(UGdouble dInterval);
	UGdouble GetInterval();
	UGbool LineDTIntersect(UGDatasetVector *pDatasetArc, UGint nApartIndex);
	UGbool LineDTClearRepeateLine(UGDatasetVector *pDatasetArc, UGint nApartIndex);
	UGbool TopoBuildPolygon(UGDatasetVector *pDatasetArc, UGArray<UGGeoRegion*> &arrRegions);
	
	//! \brief弧段求交
	UGbool TopoEditIntersectAllLine(UGDatasetVector *pDatasetArc, 
		UGbool IsAbandonMinLine = false,UGdouble dMinLineLength = 0);
	
	//! \brief长悬线延伸
	UGbool TopoEditLongDangleLineExtend(UGDatasetVector *pDatasetArc);
	
	//! \brief合并假节点
	UGbool TopoEditMergePseudoNode(UGDatasetVector *pDatasetArc);
	
	//! \brief临近节点合并
	UGbool TopoEditMergeCloseNode(UGDatasetVector *pDatasetArc);
	
	//! \brief去除悬线
	UGbool TopoEditClearSmallDangleLine(UGDatasetVector *pDatasetArc);
	
	//! \brief去除重复线
	UGbool TopoEditClearRepeatedLine(UGDatasetVector *pDatasetArc);
	
	//! \brief	去除冗余点
	UGbool TopoEditClearRedundanceVertex(UGDatasetVector *pDatasetArc);
	
	//! \brief	拓扑构面
	//! \param	pDatasetArc			线数据集
	//! \param	pDatasetPoly		被创建的面数据集
	//! \param	pDatasetPolyTmp		被创建的临时面数据集
	//! \param	IsAddBoundPolygon	是否添加边界多边形
	//! \remark	pDatasetPolyTmp由用户临时创建,用完后,由用户负责删除!
	UGbool TopoBuildPolygon(UGDatasetVector *pDatasetArc, 
		UGDatasetVector *pDatasetPoly, 
		UGDatasetVector *pDatasetPolyTmp,
		UGbool IsAddBoundPolygon = false);
	
	//! brief	拓扑构面
	//! \param	pDatasetArc			线数据集
	//! \param	pDatasetPoly		被创建的面数据集
	//! \param	pDatasetPolyTmp		被创建的临时面数据集
	//! \param	IsAddBoundPolygon	
	//! \remark	pDatasetPolyTmp由用户临时创建,用完后,由用户负责删除!
	UGbool TopoBuildHatchPolygon(UGRecordset *pArcRecordset,const UGPoint2D& pntHit,
								UGGeoRegion& HitRegion);
	
	//! \brief	生成拓扑错误信息
	UGbool TopoEditCreateTopoErrorInfo(UGDatasetVector *pDatasetArc);
	
	//! brief	创建网络数据集
	//! \param pDatasetArc			线数据集
	//! \param	pDatasetNode		节点数据集
	//! \param	pDatasetNet			被创建的网络数据集
	UGbool TopoBuildNetwork(UGDatasetVector *pDatasetArc,UGDatasetVector *pDatasetNode,
		UGDatasetVector *pDatasetNet);
	
	//! \brief 分解复合对象
	UGbool TopoSeparateComplex(UGDatasetVector *pDatasetArc);

	UGbool SetFilterElement(UGDatasetVector *pDatasetFilter,const UGString& strEdgeFilter,const UGdouble& dNodeInterval);
	
	void CancelNodeFilter();
	//UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset, UGbyte* pWeight, UGArray<UGint>& arrIDs);
	UGbool MarkUpCommonLine(UGRect2D& rcBounds, UGRecordset* pRecordset, UGTopoGrid* pWeight, UGArray<UGint>& arrIDs);
	
	UGbool TopoEditExtendDangleLine(UGbool IsShowProgress, UGDatasetVector *pDatasetArc, UGdouble ExtendedLength,
									UGbool IsOutToLogFile);

	UGbool TopoBuildPolygonEx(UGDatasetVector *pDatasetArc, UGArray<UGGeoRegion*> &arrRegion);

	// 合并、光滑等值线
	UGbool TopoSmoothAfterMerge(UGDatasetVector *pDatasetArc, UGString& strElev, UGint nSmoothDegree);

protected:
	
	UGbool GetIntersectPnt(UGRect2D &rectBounds,UGRecordset* &partRecordset,
							UGArray<UGTopoGridUnitNodesEx>&pArcIntersetPntNo,
							UGint &RealArcCount,UGArray<UGint> &fieldIndexs,
							UGArray<UGPoint2D>&pIntersetPoints,UGArray<UGint> &ArcIDs);
	
	UGint GetArcIDIndex(UGint nArcId,UGArray<UGint> &ArcIds);
	
	UGbool TopoBuildPolygonFile(UGDatasetVector *pDatasetArc, 
		UGDatasetVector * &pDatasetPoly, 
		UGDatasetVector * &pDatasetPolyTmp,
		UGbool IsAddBoundPolygon);
	
	UGbool TopoBuildPolygonArray(UGDatasetVector *pDatasetArc, 
		UGDatasetVector * &pDatasetPoly, 
		UGDatasetVector * &pDatasetPolyTmp,
		UGbool IsAddBoundPolygon,
		UGint ArcsCount);
	
	UGbool ComposeRegion(UGGeoRegion &geoRegion, UGRecordset *pRecordsetArc,
		UGint *pPolyArcs,UGint nArcCount);
	UGbool ComposeRegion(UGGeoRegion*& pgeoRegion, UGRecordset *pRecordsetArc, 
		UGint *pPolyArcs, UGint nArcCount,UGArray<UGint> &arrIDs);
	
	UGbool TopoEditNodesIdentify(UGDatasetVector *pDatasetArc, 
		UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGint& IndexNodesCount,
		UGTopoFile **pFileNodeFrom = NULL,
		UGTopoFile **pFileNodeTo = NULL,
		UGTopoFile **pFileNodeFromNext = NULL,
		UGTopoFile **pFileNodeToPrev = NULL,
		UGTopoFile **pFileArcNodeIDFrom = NULL,
		UGTopoFile **pFileArcNodeIDTo = NULL,
		UGbool bIsReturnNodePoints = false);
	
	UGbool TopoEditNodeID(UGDatasetVector *pDatasets, 
		UGArray<TNodeIndexPN> &pNodeIndex,
		UGint **pNodeArcs,
		UGint  &IndexNodesCount,
		UGint **pArcNodeIDFrom,
		UGint **pArcNodeIDTo);
	
	UGbool TopoEditNodesIdentifyEx(UGDatasetVector *pDatasetArc, 
		UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGint& IndexNodesCount,							
		UGTopoFile **pFileArcNodeIDFrom,
		UGTopoFile **pFileArcNodeIDTo	);
	
	void RemoveErrorArc(UGTopoFile **pFileNodeIndex,
		UGTopoFile **pFileNodeArcs,
		UGTopoFile **pFileArcNodeIDFrom,
		UGTopoFile **pFileArcNodeIDTo,
		UGint **pArcsLCode,
		UGint **pArcsRCode,
		UGint ArcNo);
	
	void RemoveErrorArcEx(UGArray<TNodeIndexPN> &pNodeIndex,
		UGint **pArcIndex,
		UGint **pArcNodeFromID,
		UGint **pArcNodeToID,
		UGint **pArcsLCode,
		UGint **pArcsRCode,
		UGint ArcNo);
	
	UGint IntersectLineSect(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, 
		UGPoint2D &pntStart2, UGPoint2D &pntEnd2,
		UGPoint2D &pntResult1, UGPoint2D &pntResult2);
	
	void InitTopoFile(UGTopoFile **pTopoFile, UGint ArcsCount, UGuint nRecordSize, 
		UGuint nRecordsCount);
	
	void ReleaseTopoFile(UGTopoFile **pTopoFile);

public:
	
	UGdouble dMinDangleLength;
	UGdouble dMinVertexInterval;
	UGdouble dMinNodeInterval;
	UGdouble dMinArea;
	UGdouble dExtendedLength;
	UGdouble dMinRatioOfAreaToPerimeter;
	
private:
	UGint FindInsetPos(UGint nID,UGint* arrIDs,UGint nCount);
	UGbool TopoBuildHatchPolygon(UGDatasetVector *pDatasetArc, const UGPoint2D& pntLabel,
								UGGeoRegion &geoRegion);
	UGbool GetHatchNodeID(UGDatasetVector *pDatasetArc,UGTopoGridUnitNodes *&pGridUnitNodes,
						UGTopoFile *&pFileNode,UGPoint2D* &pFPoints,UGPoint2D* &pTPoints);
	
	UGbool GetHatchHead(UGDatasetVector *pDatasetArc,UGPoint2D pntLabel,
						UGArray<THatchHead&> &arrHatchHead);
	
	UGint TopoBuildHatchPolygon(UGDatasetVector *pDatasetArc, UGPoint2D pntLabel);
	
	void TopoPreprocess(UGDatasetVector *pDatasetArc);
	
	UGbool IsTopoLineValid(UGGeoLine*& pSingleLine);
	
	UGbool bIsPreProcess;
	
	UGbool GetNodeXYFromDT();
	UGbool IsFilterNode(const UGPoint2D &pntIntersect);
	
	UGbool GetApartIntersectPnt(UGRect2D &rectBounds, UGint nApartIndex,
								UGRecordset * &partRecordset,
								UGArray<UGTopoGridUnitNodesEx> &pArcIntersetPntNo,
								UGArray<UGPoint2D> &pIntersetPoints,
								UGArray<UGint>& arrIDs);
	
	UGDatasetVector* m_pDatasetFilter;
	UGString m_strEdgeFilter;
	UGdouble m_dNodeInterval;
	UGbool m_bNodeFilter;
	UGPoint2Ds m_NodeXY;
	UGdouble m_dInterval;
};

}

#endif

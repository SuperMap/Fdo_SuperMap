/* 
	\file UGTopoOverlay.h
	\brief 叠加分析拓扑处理类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTOPOOVERLAY_H
#define UGTOPOOVERLAY_H

#include "Engine/UGDatasetVector.h"
#include "Topology/UGTopoOperators.h"
#include "Topology/UGTopoBuild.h"

namespace UGC {

typedef UGArray<UGVariant> UGVarArray;

typedef UGArray<UGVarArray> UGVarArrays;

class TOPOLOGY_API UGTopoOverlay
{
public:
	UGTopoOverlay();
	virtual ~UGTopoOverlay();
	
	enum UGTopoOverlayMode
	{
		UGTopoIntersect	= 0,
		UGTopoErase		= 1,
		UGTopoIdentity	= 2,
		UGTopoSymmetric	= 3,
		UGTopoUnion		= 4,
		UGTopoUpdate	= 5,
	};
	
	//! \brief 设置容限
	
	//!  \param		dInterval	设置的容限
	 //! \return	设置成功返回TRUE，无错误返回FALSE
	//!  \remarks	如dInterval<EP,则种子动设置为EP

	void SetInterval(UGdouble dInterval);
	
	//! \brief 获取已设置的容限
	 //! \param		dInterval	设置的容限
	 //! \return	返回容限值
	//!  \remarks	
	UGdouble GetInterval();
	
	UGbool OverlayPoints(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGRecordset *pRecordsetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGTopoOverlayMode TopoMode);
	
	UGbool OverlayLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGRecordset *pRecordsetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGTopoOverlayMode TopoMode);
	
	UGbool OverlayRegions(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGTopoOverlayMode TopoMode);

private:	
	UGbool OverlayProcess(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetSrcTemp,
							UGDatasetVector *pDatasetTagTemp, UGArray<UGGeoRegion*> &arrRegions);
	
	UGbool IntersectObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
							UGRecordset *pRecordsetSrc, 
							UGRecordset *pRecordsetTag, 
							UGDatasetVector *pDatasetRes, 
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes);
	
	UGbool EraseObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
						UGRecordset *pRecordsetSrc, 
						UGRecordset *pRecordsetTag, 
						UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, 
						UGStrArray& arrFieldTag, 
						UGStrArray& arrFieldRes);
	
	UGbool IdentityObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
							UGRecordset *pRecordsetSrc, 
							UGRecordset *pRecordsetTag, 
							UGDatasetVector *pDatasetRes, 
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes);
	
	UGbool SymmetricObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
							UGRecordset *pRecordsetSrc, 
							UGRecordset *pRecordsetTag, 
							UGDatasetVector *pDatasetRes, 
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes);
	
	UGbool UnionObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
						UGRecordset *pRecordsetSrc, 
						UGRecordset *pRecordsetTag, 
						UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, 
						UGStrArray& arrFieldTag, 
						UGStrArray& arrFieldRes);
									
	UGbool UpdateObjects(TOverlayID* pID, UGArray<UGGeoRegion*> &arrRegions, 
						UGRecordset *pRecordsetSrc, 
						UGRecordset *pRecordsetTag, 
						UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, 
						UGStrArray& arrFieldTag, 
						UGStrArray& arrFieldRes);
	
	UGbool GetVariants(UGRecordset *pRecordsetSrc, 
						UGRecordset *pRecordsetTag, 
						UGStrArray& arrFieldSrc, 
						UGStrArray& arrFieldTag, 
						UGVarArrays& VarArraysSrc,
						UGVarArrays& VarArraysTag, 
						UGArray<UGPoint> &arrIDIndexSrc,
						UGArray<UGPoint> &arrIDIndexTag);
	
	UGint FindIndex(UGint nID, UGPoint* arrNetIndex,UGint nCount);
	//{{Just test
	UGbool IntersectLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGRecordset *pRecordsetRes, 
							UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes);
	
	UGbool EraseLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGRecordset *pRecordsetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldRes);
	
	UGbool IdentityLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGRecordset *pRecordsetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, 
						UGStrArray& arrFieldRes);
	//}}Just test
private:	
	UGdouble m_dInterval;
	UGTopoOperators m_TopoOperators;
	UGTopoBuild m_TopoBuild;
};

}

#endif


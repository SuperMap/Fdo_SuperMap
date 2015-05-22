/* 
	\file UGFourColor.h
	\brief 四色算法
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGFOURCOLOR_H
#define UGFOURCOLOR_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeoRegion.h"
#include "Engine/UGDataset.h"
#include "Topology/UGTopoTypes.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {
//!	\brief 图度信息结构
struct tagdegreeID
{
	UGint nID;
	UGint ndegree;
};

typedef struct tagdegreeID UGDegreeIDInfo,*pUGDegreeIDInfo;//规范变量定义

class OPERATION_API UGFourColor  
{
public:
	UGFourColor();
	virtual ~UGFourColor();
	
	//!	\brief	着色函数
	//! \param  pDTRegion 数据集指针[in]
	//!	\param strColorValue 颜色字段[in]
	//!	\return 如果着色函数成功返回TRUE，否则返回FALSE
	UGbool FourColor(UGDatasetVector* pDTRegion, const UGString& strColorValue = "ColorValue");
private:
	UGbool ColorNew(UGArray<UGDegreeIDInfo> &arrDegreeIDInfo, UGint* pColorClass);
	UGint Color(UGint nPos,UGint CurrentColor, UGint nCountColor, UGbyte* pHandled, 
				UGint* pColorCount, UGint* pOrder, UGint** ppColorAdj, UGint*pColorClass, UGint nRegionCount);
	UGint Maxclique(UGArray<UGDegreeIDInfo> &arrDegreeIDInfo, UGint* pColorClass, 
					UGint *pClique, UGArray<UGint> &arrOrderClique);
	UGbool AssignColor(UGint nNodeIndex, UGint nColorType, UGint* pColorClass, UGint** ppColorAdj, UGint* pColorCount);
	UGbool RemoveColor(UGint nNodeIndex, UGint nColorType, UGint* pColorClass, UGint** ppColorAdj, UGint* pColorCount);
	UGbool IsAdjacent(UGint nPos1, UGint nPos2);
	
	UGTopoGrid* m_pTopoGrid;
	UGint m_BestColoring;
};

}

#endif // !defined(UGFOURCOLOR_H)

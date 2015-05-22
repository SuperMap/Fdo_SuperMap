/*! \file	 UGRelLineRegion.h
 *  \brief	 线面空间位置关系判断
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelLineRegion.h,v 1.4 2007/10/16 02:23:22 guohui Exp $
 */


#if !defined(AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_)
#define AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

//! \brief 线面空间位置关系判断
class ALGORITHM_API UGRelLineRegion  
{
private:
	UGRelLineRegion();
	
public: // 线面基本空间位置关系判断
	
	//! \brief 线是否在面的内部
	//! \remarks 面和线的交集等于线,线可以和面的边界有交点
	static UGbool IsWithin(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//{{ add by guohui 2007.10.12
	//! \brief 线是否在面的内部
	static UGbool IsWithin(const UGPoint2D* pLinePoints, const UGint* pLinePolyCount,UGint nLineSubCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);

	//! \brief 线是否在面的内部
	static UGbool IsWithin(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);
	//}} add by guohui 2007.10.12

	//! \brief 线是否跨越面
	//! \remarks 线和面的内部、外部的交集都为一维
	static UGbool IsCross(const UGPoint2D* pLinePoints, UGint nLinePntCount,
						  const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//{{ add by guohui 2007.10.12	
	//! \brief 线是否接触面
	//! \remarks 线和面的边界有交集
	static UGbool IsTouch(const UGPoint2D* pLinePoints, const UGint* pLinePolyCount,UGint nLineSubCount,
							const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount,UGint nRgnSubCount);
	//}} add by guohui 2007.10.12

	//! \brief 线是否接触面
	//! \remarks 线和面的边界有交集
	static UGbool IsTouch(const UGPoint2D* pLinePoints, UGint nLinePntCount,
						  const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

	//! \brief 线是否和面相离
	//! \remarks 线和面的边界、外部的交集都为空
	static UGbool IsDisjoint(const UGPoint2D* pLinePoints, UGint nLinePntCount,
							 const UGPoint2D* pRgnPoints, UGint nRgnPntCount);

public: // 线面其他空间位置关系判断

	// add by guohui 2007.10.12	copy from UGGeoRelation::IsRegionIIntersectLineB
	//! \brief 线是否和面相交 
	static UGbool IsRegionIIntersectLine(UGPoint2D *pRegionPoints,UGint *pRegionCounts,UGint nRegionSubCount,
										  UGPoint2D *pLinePoints,UGint *pLineCounts,UGint nLineSubCount);
private: // 内部函数

	//! \brief 线和面的边界无交集
	static UGbool IsIrrelative(const UGPoint2D *pLinePoints, UGint lLinePntCount, 
						const UGPoint2D *pRegPoints, UGint lRegPntCount);
};

}

#endif // !defined(AFX_UGRELLINEREGION_H__9DE64C51_B071_45AB_AC10_B9487CE80304__INCLUDED_)

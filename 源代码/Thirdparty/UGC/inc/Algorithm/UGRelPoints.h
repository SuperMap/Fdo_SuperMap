/*! \file	 UGRelPoints.h
 *  \brief	 点点之间的空间关系判断
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPoints.h,v 1.8 2007/11/09 10:06:21 qiuli Exp $
 */



#if !defined(AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_)
#define AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_


#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"


namespace UGC {

//! \brief 点点之间的空间关系判断
class ALGORITHM_API UGRelPoints  
{
private:
	UGRelPoints();

#if PACKAGE_TYPE==PACKAGE_UGC
	
public: // 共线/共圆 等的判断

	//! \brief		三点是否共线
	//! \remarks 	有重合点，也共线
	static UGbool IsOnSameLine(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief 四点是否共圆
	static UGbool IsOnSameCircle(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
								 const UGPoint2D& pnt3, const UGPoint2D& pnt4);
#endif // end declare ugc API

public: // 其他判断

	//! \brief 三点是否逆时针排列
	static UGbool IsCounterClockwise(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief 点集的Bounds是否相交
	//! \remarks 很多空间位置判断可以先用Bounds是否相交进行过滤
	static UGbool IsExtentOverlap(const UGPoint2D* pPoints1, UGint nPntCount1,
								const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief	 判断是否有共同点
	static UGbool IsCommonPoint(const UGPoint2D* pPoints1, UGint nPntCount1,
								const UGPoint2D* pPoints2, UGint nPntCount2);

	static UGbool EQ(const UGPoint2D& pnt1, const UGPoint2D& pnt2, UGdouble dTolerance);
};

}

#endif // !defined(AFX_UGRELPOINTS_H__737795B6_7D1B_46C4_95CB_0A7A648655FB__INCLUDED_)

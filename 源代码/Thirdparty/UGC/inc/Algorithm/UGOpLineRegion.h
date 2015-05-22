/*! \file	 UGOpLineRegion.h
 *  \brief	 线和面 进行的空间运算
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpLineRegion.h,v 1.6 2007/10/12 06:06:52 guohui Exp $
 */


#ifndef UGOPLINEREGION_H
#define UGOPLINEREGION_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGArray.h"
#include "Base/UGList.h"

namespace UGC {

//! \brief 线和面 进行的空间运算
class ALGORITHM_API UGOpLineRegion  
{
private:
	UGOpLineRegion();


	//{{ by guohui 2007.10.12
public: // 距离

	//! \brief 求线到面的最小距离
	static UGdouble MinDistance(const UGPoint2D* pPointsLine,const UGint* pPolyCountLine,UGint nSubCountLine, 
					   const UGPoint2D* pPointsRegion,const UGint* pPolyCountRegion,UGint nSubCountRegion );
	//}} by guohui 2007.10.12

public: // 分割

	//! \brief 用折线分割简单面，面不包含子对象。
	//! \brief 线与面交点个数不为2，返回False. 返回的面点数据是不封闭的.
	static UGbool Split(const UGPoint2D* pLinePoints, UGint nLinePntCount, 
					   const UGPoint2D* pRgnPoints, UGint nRgnPntCount, 
					   UGPoint2Ds& pntResRegion1, UGPoint2Ds& pntResRegion2);

public: // 裁减	

    //! \brief 用rect裁减线
	//! \param resPoints	 被裁剪后的线的控制点 
	//! \param resPolyCount	 每条线所包含的控制点个数  
	//! \param nResSubCount	 被裁剪后的线的个数 
	//! \param bInside		 true,则返回在矩形内部的线;false,返回在矩形外部的线
	static UGbool Clip(const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount, 
					 const UGRect2D& rectClip, UGPoint2Ds& resPoints,
					 UGArray<UGint>& resPolyCount, UGint& nResSubCount, UGbool bInside=TRUE);


    //! \brief 用多个面裁减线(位于多边形边上的线，归于结果线中)
	//! \param pPointsRes	 被裁剪后的线的控制点 
	//! \param pPolyCountRes 每条线所包含的控制点个数  
	//! \param nSubCountRes	 被裁剪后的线的个数 
	//! \param bInside		 true,则返回在多边形内部的线;false,返回在多边形外部的线
	static UGbool Clip(const UGPoint2D* pPointsLine,const UGint* pPolyCountLine,UGint nSubCountLine, 
					   const UGPoint2D* pPointsRegion,const UGint* pPolyCountRegion,UGint nSubCountRegion,
					   UGPoint2D*& pPointsRes,UGint*& pPolyCountRes,UGint& nSubCountRes,
					   UGbool bInside=TRUE);
	
#if PACKAGE_TYPE==PACKAGE_UGC
public: 

	//! \brief 计算一个椭圆和通过椭圆中心的射线的交点
	//! \param a			椭圆长半轴
	//! \param b			椭圆短半轴
	//! \param x0			椭圆圆心横坐标
	//! \param y0			椭圆圆心纵坐标
	//! \param dRadian		射线的弧度(以正东方向为0，弧度单位)
	static UGPoint2D IntersectEllipseRay(UGdouble a, UGdouble b,
										UGdouble x0, UGdouble y0, UGdouble dRadian);
#endif // end declare ugc API
private:
	
	//! \brief 用rect裁减线(返回矩形内部的线)
	static UGbool ClipLine(const UGPoint2D* pPoints, const UGint* plPolyCounts, UGint lCount, 
					const UGRect2D& rectClip, UGPoint2Ds& resPoints, 
					UGArray<UGint>& resPolyCount, UGint& nResSubCount);

	//! \brief 计算矩形边界和线段的关系
	static UGbool ClipLineTest(UGdouble p, UGdouble q, UGdouble& u1, UGdouble& u2);

	//! \brief 用rect裁减线(返回矩形外部的线)
	static UGbool ClipLine2(const UGPoint2D* pPoints, const UGint* plPolyCounts, UGint lCount, 
					const UGRect2D& rectClip, UGPoint2Ds& resPoints, 
					UGArray<UGint>& resPolyCount, UGint& nResSubCount);

	static UGbool Clip(const UGPoint2D* pLinePoints,UGint nCount,const UGPoint2D* pRegionPoints,
						const UGint* pRegionPolyCount,UGint nRegionSubCount,
						UGList<UGPoint2D>&pntArray,UGArray<UGuint> &PolyArray,UGbool bInside=TRUE);

};

}

#endif

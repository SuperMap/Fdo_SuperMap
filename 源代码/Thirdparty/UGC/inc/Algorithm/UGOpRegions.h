/*! \file	 UGOpRegions.h
 *  \brief	 面, 或者面之间的运算
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpRegions.h,v 1.7 2007/10/10 08:17:56 guohui Exp $
 */


#ifndef UGOPREGIONS_H
#define UGOPREGIONS_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief 面, 或者面之间的运算
//! \remarks 术语解释:
//!				质心:质量中心
class ALGORITHM_API UGOpRegions  
{
private:
	UGOpRegions();


public: // 得到图形的特殊点(特殊值)
	
	//! \brief		得到复杂多边形的内点(在多边形内,靠近中心的点)
	static UGPoint2D InnerPoint(const UGPoint2D* pPoints, const UGint* pPolyCount, 
								UGint nSubCount, UGRect2D* pBounds=NULL);
public:
	//! \brief		用Rect裁减一个多边形	
	//! \return		得到裁减后,在rect内的多边形
	//! \param 		pntResults	结果多边形的点坐标
	//! \param 		PolyCountResult	各个多边形的点个数
	//! \param		bInside		 true,则返回在矩形内部;false,返回在矩形外部
	static void ClipRegionWithRect(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult, 
								UGbool bInside=TRUE);

public: // 面(or rect)裁减面
	//! \brief		多边形求交
	//! \return		
	//! \param 		nMode		求交模式。取值为 UGGeneralPolygonClip::Difference,UGGeneralPolygonClip::Intersect
	//!							UGGeneralPolygonClip::Union,UGGeneralPolygonClip::Xor
	static UGbool Intersects(UGPoint2D* pPoints1,UGint* lPolyCount1,UGint lCount1,
							UGPoint2D* pPoints2,UGint* lPolyCount2,UGint lCount2,
							UGPoint2D*& pPoints,UGint*& lPolyCount,UGint& lCount,
							UGint nMode);

#if PACKAGE_TYPE==PACKAGE_UGC
	
	//! \brief 得到三角形质心.也就是三角形的重心。
	static UGPoint2D TriangleCentroid(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief 得到三角形外心(外接圆圆心)
	//! \remarks Circumcenter: n.外心(数学上外接圆的中心) 三条垂直平分线的交点
	static UGPoint2D TriangleCircumcenter(const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3);

	//! \brief 得到椭圆Pie的质心(质量中心)
	//! \param pntCenter 椭圆的中心点; 
	//! \param a 长轴;
	//! \param b 短轴; 
	//! \param dAngleStart 起始实际角度; 角度
	//! \param  dAngleEnd: 终止实际角度; 角度
	static UGPoint2D PieCentroid(const UGPoint2D& pntCenter, UGdouble a, UGdouble b, 
									UGdouble dAngleStart, UGdouble dAngleEnd);

	//! \brief 得到三角面的法向量
	//! \remarks 得到三点构成的平面的平面方程 Ax+By+Cz+D=0 的三个ABC参数的值
	static void TriangleNormal(const UGPoint3D& pnt1, const UGPoint3D& pnt2, const UGPoint3D& pnt3, 
							   UGdouble& A, UGdouble& B, UGdouble& C);

	// 这个函数好像没有必要
	//! \brief 用多边形1裁减一个多边形2
	//! \return 得到裁减后,在多边形1内的多边形
	// static void ClipRegionWithRegion(const UGPoint2D* pRgnPoints, const UGint* pRgnPolyCount, UGint nRgnSubCount, 
	// 								const UGPoint2D* pClipPoints, const UGint* pClipPolyCount, UGint nClipSubCount, 
	//								UGPoint2Ds& pntResults, UGArray<UGint>& PolyCountResult, UGint& nResSubCount);

private: 

	//! \brief		用Rect裁减一个多边形	
	//! \return		得到裁减后,在rect内的多边形
	static void ClipRegionWithRectInside(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult);

	//! \brief		用Rect裁减一个多边形	
	//! \return		得到裁减后,在rect外的多边形
	static void ClipRegionWithRectOutside(const UGPoint2D* pRgnPoints,const UGint* pRgnPolyCount,UGint nRgnSubCount, 
								const UGRect2D& rect,UGPoint2Ds& pntResults,UGArray<UGint>& PolyCountResult);

#endif // end declare ugc API
};

}

#endif

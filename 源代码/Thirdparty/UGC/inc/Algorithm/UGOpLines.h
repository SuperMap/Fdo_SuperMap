/*! \file	 UGOpLines.h
 *  \brief	 线 以及线线之间的运算
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpLines.h,v 1.32 2007/12/27 09:14:08 maoqin Exp $
 */


#ifndef UGOPLINES_H
#define UGOPLINES_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint.h"

namespace UGC {

//! \brief 线 以及线线之间的运算
class ALGORITHM_API UGOpLines  
{
private:
	UGOpLines();

public: // 得到图形的属性

	//! \brief 得到折线的长度
	static UGdouble Length(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 得到直线的斜率
	//! \return 如果斜率为 无穷大 或者两点重合, 则返回UGdouble数值的无穷大值: INFINITEBIG
	// static UGdouble Slope(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);


public: // 距离计算

	//! \brief 计算线段和线段之间极大距离
	static UGdouble MaxDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 计算线段和线段之间极大距离
	static UGdouble MaxDistance(const UGPoint2D* pPoints1, UGint nPntCount1,  
								const UGPoint2D* pPoints2, UGint nPntCount2  );

	//! \brief 计算线段和线段之间极大距离
	static UGdouble MaxDistance(const UGPoint2D* pPoints1, const UGint* plPolyCount1, UGint lSubCount1, 
								const UGPoint2D* pPoints2, const UGint* plPolyCount2, UGint lSubCount2);

	//! \brief 计算线段和线段之间极小距离
	static UGdouble MinDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 计算折线段和折线段之间最小距离	
	static UGdouble MinDistance(const UGPoint2D* pPointsSrc1, const UGint* plPolySrc1, UGint lSubCount1, 
								const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2);

	//! \brief 计算折线段和折线段之间最小距离	
	static UGdouble MinDistance(const UGPoint2D* pPoints1, UGint nPntCount1,  
								const UGPoint2D* pPoints2, UGint nPntCount2  );
	//! \brief 计算线段和线段之间极小距离
	static UGdouble MinDistance(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
								const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2);


public: // 找到符合一定规则的一个点

	//! \brief 沿着直线的方向, 在直线上找一个点, 到起始点(pntStart)的距离等于dDistance
	//! \remarks 标记直线的两个点不得重合
	static UGPoint2D FindPoint(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
								UGdouble dDistance);

	//! \brief 在折线上找一个点, 到起始点的距离等于dDistance, 如果长度不够,就延长最后一段线段
	static UGPoint2D FindPoint(const UGPoint2D* pPoints, UGint nPntCount, 
								UGdouble dDistance);

	//! \brief 在直线(pntStart,pntEnd)绕pntStart逆时针旋转dAngle度(角度单位)所成的直线上，寻找到pntStart的距离为dDistance的点
	//! \remarks 标记直线的两个点不得重合
	static UGPoint2D FindPoint(const UGPoint2D& pntStart, const UGPoint2D&pntEnd,
								UGdouble dDistance, UGdouble dAngle);

	
public: // 求线线之间的交点

	//! \brief 求两条直线之间的交点
	//! \remarks 交点通过 引用参数返回, 重叠认为是平行的
	//! \return 平行返回false
	static UGbool IntersectLines(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGPoint2D& pntResult);

	//! \brief 直线和线段的交点
	//! \remarks 交点通过 引用参数返回, 重叠认为是平行的
	//! \return 平行返回false
	static UGbool IntersectLineLineSeg(const UGPoint2D& pntLineStart, const UGPoint2D& pntLineEnd, 
									const UGPoint2D& pntLineSegStart, const UGPoint2D& pntLineSegEnd, 
									UGPoint2D& pntResult);

	//! \brief 线段和线段的交点
	//! \remarks 交点通过引用参数返回; 
	//! \return 在同一条直线上时,如果重叠部分只有一个点, 返回true,并得到这个点, 
	//!			如果没有重叠部分,或者重叠部分是一个集合, 则返回false
	static UGbool IntersectLineSegs(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGPoint2D& pntResult);
	
	//! \brief 得到容限，如果没有设置，得到的是默认设置的容限
	static UGdouble UGGetEPSILON();

	//! \brief 设置容限
    static void UGSetEPSILON(UGdouble dEpsilon);

	//! \brief 线段和线段的交点
	//! \param pntStart1 线段1的起点[in]。
	//! \param pntEnd1   线段1的终点[in]。
	//! \param pntStart2 线段2的起点[in]。
	//! \param pntEnd2 线段2的终点[in]。
	//! \param pntResult 计算结果--交点坐标[out]。
	//! \remarks 交点通过引用参数返回; 
	//! \return 返回TRUE表示有交点，否则无交点
	//!         计算两条线段（注意：不是直线）的交点
	static UGbool IntersectLineSect(	
		UGPoint2D &pntStart1,			
		UGPoint2D &pntEnd1,			
		UGPoint2D &pntStart2,			
		UGPoint2D &pntEnd2,			
		UGPoint2D &pntResult
		);							

	//! \brief 线段内部和线段内部的交点
	//! \remarks 交点通过引用参数返回; 
	//! \return 内部交集为一个点, 返回true,并得到这个点, 
	//!			交集为空、为部分线段(交叠)、为线段的端点都返回false
	static UGbool IntersectLineSegsInterior(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
											const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
											UGPoint2D& pntResult);
	
	//! \brief 线段和线段的交点X,Y坐标
	//! \remarks 交点通过引用参数返回; 
	//! \return 在同一条直线上时,如果重叠部分只有一个点, 返回true,并得到这个点, 
	//!			如果没有重叠部分,或者重叠部分是一个集合, 则返回false
	static UGbool IntersectLineSegs(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, 
									const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, 
									UGdouble &dx, UGdouble &dy, UGdouble &dParameter1,
									UGdouble &dParameter2);
	
	//! \brief 计算两条折线的所有交点
	//! \return 没有交点,返回false; 交点添加到pntResults中,pntResults原有信息不会被删除/覆盖
	static UGbool IntersetPolylines(const UGPoint2D* pPoints1, UGint nPntCount1, 
								   const UGPoint2D* pPoints2, UGint nPntCount2, 
								   UGPoint2Ds& pntResults);

	//! \brief 计算两条折线的所有交点
	//! \param pntResults 传入时, pntResults应该为空集
	//! \return 没有交点,返回false; 
	static UGbool IntersetPolyPolylines(const UGPoint2D* pPointsSrc1, const UGint* plPolySrc1, UGint lSubCount1, 
										const UGPoint2D* pPointsSrc2, const UGint* plPolySrc2, UGint lSubCount2, 
										UGPoint2Ds& pntResults);
	
	//判断两条线段的关系!!!
	// return: 相交：1；    重合：2
	//         相离：0；    重叠: 3
	//CPoint2D& pntResult1,CPoint2D& pntResult2：
	//如果重叠或部分重叠，结果是重叠线段的顶点;pntResult1->pntResult1的方向与
	//pntStart1->pntStart2的一致如果只有一个交点，结果保存在pntResult1中，pntResult2无效。
	static UGint IntersectLineSegs(const UGPoint2D &pntStart1,const UGPoint2D &pntEnd1,
								 const UGPoint2D &pntStart2,const UGPoint2D &pntEnd2,
								 UGPoint2D& pntResult1,UGPoint2D& pntResult2);
	//! \brief 传入的折线段l1和l2，返回 l1 和 l2 互相打断后的线段 l1' 和 l2' 
	static UGbool IntersectLine(UGPoint2D *pPoints1, UGPoint2D *pPoints2, UGint nPointsCount1, UGint nPointsCount2,
								  UGPoint2Ds &arrLine1Out, UGPoint2Ds &arrLine2Out, UGArray<UGint> &arrVertexNumber1,
								  UGArray<UGint> &arrVertexNumber2,UGdouble dTolerance);

	// add by guohui 2007.10.09 
	//! \brief		用线来打断线，返回被打断线
	//! \remarks	pSrcLinePoints 被打断后，通过打断点，分别存放在  arrLine1 和 arrLine2 中。arrLine1 与 arrLine1 相互隔开
	static UGbool SplitLine(UGPoint2D *pSrcLinePoints, UGint nSrcPointsCount, UGPoint2D *pSplitLinePoints2, UGint nSplitPointsCount,
								  UGPoint2Ds &arrLine1,UGArray<UGint> &arrlPolyCount1, 
								  UGPoint2Ds &arrLine2,UGArray<UGint> &arrlPolyCount2);

public: // 求平行线

	//! \brief 求折线的平行线
	//! \remark dDistance 为正，则是线 pPoints 的左边平行线;为负，为右边
	static UGbool Parallel(const UGPoint2D* pPoints, UGint nPntCount,
						 UGdouble dDistance, UGPoint2Ds& pntResults);

	//! \brief 求折线的平行线
	//! \remark dDistance 为正，则是线的左边平行线;为负，为右边
	static UGbool Parallel(const UGPoint2D &pntStart,const UGPoint2D &pntEnd,
						 UGdouble dDistance, UGPoint2D &pntResStart,UGPoint2D &pntResEnd);

// private: // 内部辅助函数, 暂不提供给外面使用

	//! \brief 得到两条直线的角平分线上 求一点, 该点引出的与原直线平行的直线 到 原直线的距离为dDistance
	//! \remarks 两条直线分别为 (pnt1, pntJoint) 和 (pnt2, pntJoint), 两条直线相交于 pntJoint点
	//!			本函数仅在 Parallel 函数中使用
	
	// by guohui 2007.09.13 这个接口只能被 Parallel 调用。
	// 接口内部有错误。返回的点实际是 -dDistance 的点。外部调用慎行。
	static UGPoint2D FindBisectorPoint(const UGPoint2D& pnt1, const UGPoint2D& pntJoint, 
										const UGPoint2D& pnt2, UGdouble dDistance);

public: // 重采样

	//! \brief		距离重采样
	static UGbool ReSample(const UGPoint2D* pPoints, UGint nPntCount,
						 UGdouble dTolerance, UGPoint2Ds& pntResults);
public: // 获取线上的点

	//! \brief		查找线上距pntStartPoint距离为dDistance的点
	//!  \param		pntStartPoint	开始点
	//!  \param		pntEndPoint		结束点
	//!  \param		dDistance	距离，可以为负数，可以大于整体长度
	//! \return		pntStartPoint 和 pntEndPoint重合，则返回pntEndPoint. 
	//! \remarks	dDistance<0,则为反向延长线上的点
	static UGPoint2D FindPointOnLineByDistance(const UGPoint2D& pntStartPoint, const UGPoint2D& pntEndPoint, 
											UGdouble dDistance);
	
	//! \brief		查找线上距pntStartPoint距离为dDistance的点
	static UGPoint2D FindPointOnLineByDistance(const UGPoint2D* pPoints, UGint nPntCount,
											UGdouble dDistance);

	//! \brief		查找线上 距pntStartPoint 距离 为整条线段的长度的 dRatio 倍的点
	//!  \param		pntStartPoint	开始点
	//!  \param		pntEndPoint		结束点
	//!  \param		dRatio	比例，可以为负数，可以大于1.0
	//! \return		pntStartPoint 和 pntEndPoint重合，则返回pntEndPoint. 
	//! \remarks	dDistance<0,则为反向延长线上的点
	static UGPoint2D FindPointOnLineByRatio(const UGPoint2D& pntStartPoint, const UGPoint2D& pntEndPoint, 
											UGdouble dRatio);
	
	//		return 0: 相离
	//		return 1: 相交,交点不是两线段的端点						返回交点pntResult1
	//		return 2: 相交,交点是线段1的起点						返回交点pntResult1
	//		return 3: 相交,交点是线段1的终点						返回交点pntResult1
	//		return 4: 相交,交点不是是线段1的端点，是线段2的起点		返回交点pntResult1
	//		return 5: 相交,交点不是是线段1的端点，是线段2的终点		返回交点pntResult1
	//		return 6: S1-----S2(E2)-----E1-----E2(S2)				返回交点pntResult1(S2(E2)),	pntResult2(E1)
	//		return 7: S2(E2)-----S1-----E2(S2)-----E1				返回交点pntResult1(S1),		pntResult2(E2(S2))
	//		return 8: S1-----S2(E2)-----E2(S2)-----E1				返回交点pntResult1(S2(E2)),	pntResult2(E2(S2))
	//		return 9: S2-----S1(E1)-----E1(S1)-----E2				返回交点pntResult1(S1(E1)),	pntResult2(E1(S1))
	//		return 10: 重合
	static UGint IntersectLineSegs(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, 
									UGPoint2D &pntStart2, UGPoint2D &pntEnd2, 
									UGPoint2D &pntResult1, UGPoint2D &pntResult2,
									UGdouble &dInterval);


public: // 

	//! \brief 合并两条交叠的线
	static UGbool UnionMatchLine(const UGPoint2D &pntStart1,const UGPoint2D &pntEnd1,
								 const UGPoint2D &pntStart2,const UGPoint2D &pntEnd2,
								 UGPoint2D& pntResult1,UGPoint2D& pntResult2);

public: // 其他

	//! \brief 两个矢量之间的叉乘
	//! \remarks 在很多地方都可以运用的上
	
	// by guohui 2007.09.13 和CPP文件中统一
	//	static UGdouble XMultiply(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
	//							const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);
	static UGdouble XMultiply(const UGPoint2D& pntFrom1, const UGPoint2D& pntTo1,
						const UGPoint2D& pntFrom2, const UGPoint2D& pntTo2);

	/*!	\brief	参数化对象转成线\n
	  *	\param pPoints			存放返回结果的点数组
	  *	\param pntCenter		参数化对象的中心点
	  *	\param dSemiMajorAxis			长半轴
	  *	\param dSemiMinorAxis			短半轴
	  *	\param dRotation		对象的倾斜角度(弧度单位)
	  *	\param dRadianBegin		对象的起始角度(弧度单位)
	  *	\param dRadianEnd		对象的终止角度(弧度单位)
	  *	\param lPointCount		返回点的个数
	  *	\param dRadianGrain		取点间隔密度(弧度单位)
	  *	\return 成功:点串通过pPoints引用返回，lPointCount引用返回点的个数；
	  *	\remarks 角度单位为弧度；起始角可以比终止角大，内部会进行自动规格化；
	*/
#if PACKAGE_TYPE==PACKAGE_UGC
	static UGbool BuildArc(UGPoint2D *&pPoints,const UGPoint2D& pntCenter,
							UGdouble dSemiMajorAxis,UGdouble dSemiMinorAxis,UGdouble dRotation,
							UGdouble dRadianBegin,UGdouble dRadianEnd,UGint &lPointCount,
							UGdouble dRadianGrain = 0.05);

	/*!	\brief	参数化对象转成线\n
	  *	\param pPoints			存放返回结果的点数组
	  *	\param pntCenter		参数化对象的中心点
	  *	\param dSemiMajorAxis			长半轴
	  *	\param dSemiMinorAxis			短半轴
	  *	\param dRotation		对象的倾斜角度(弧度单位)
	  *	\param dRadianBegin		对象的起始角度(弧度单位)
	  *	\param dRadianEnd		对象的终止角度(弧度单位)
	  *	\param lPointCount		返回点的个数
	  *	\param dRadianGrain		取点间隔密度(弧度单位)
	  *	\return 成功:点串通过pPoints引用返回，lPointCount引用返回点的个数；
	  *	\remarks 角度单位为弧度；起始角可以比终止角大，内部会进行自动规格化；
	*/
	static UGbool BuildArc(UGPoint *&pPoints,const UGPoint2D& pntCenter,
							UGdouble dSemiMajorAxis,UGdouble dSemiMinorAxis,UGdouble dRotation,
							UGdouble dRadianBegin,UGdouble dRadianEnd,UGint &lPointCount,
							UGdouble dRadianGrain = 0.05);

	static UGdouble CalcEllipseRadian(const UGdouble &dPntRadian, const UGdouble &dSemiMajorAxis,
									 const UGdouble &dSemiMinorAxis, const UGdouble& dRotateRadian);

	//! \brief 给定一个椭圆，求给定角度椭圆上点的坐标。
	//! \param pntCenter [in] 椭圆圆心。
	//! \param dSemiMajorAxis [in] 椭圆长半轴。
	//! \param dSemiMinorAxis [in] 椭圆短半轴。
	//! \param dRotationAngle [in] 椭圆的旋转角度
	//! \param dPntAngle [in] 椭圆上的点和圆心连线 与 椭圆长轴方向的夹角， 
	//!			注意不是和X方向的夹角， 因为椭圆自身有旋转角度
	//! \return 返回求出的点坐标。
	static UGPoint2D EllipsePoint(const UGPoint2D& pntCenter, UGdouble dSemiMajorAxis, 
									UGdouble dSemiMinorAxis, UGdouble dRotationAngle, UGdouble dPntAngle);	

	static UGbool Cardinal(UGPoint2D * pPntControls, UGPoint2D * pPntCurve,UGint nCurvePoints);

	//{{ by guohui 2007.12.26 该方法无人使用，注释吧!
	//static UGbool CardinalToLine(UGPoint2D *pCtrlPnts, UGint nCtrlPntCount,UGPoint2D *pPntCurve, 
	//								UGint nPntPreSeg);
	//}} by guohui 2007.12.26 该方法无人使用，注释吧!

	static UGbool Cardinal2Line(UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
								UGPoint2D *&pResultPoints, UGint &lResultPointCount,
								UGint nPointCountPerSegment = 20);

	static UGbool Curve2Line(UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
							UGPoint2D *&pResultPoints, UGint &lResultPointCount, 
							UGint nPointCountPerSegment = 20);

	//! \brief 三次B样条曲线转直线
	static UGbool BSpline2Line(const UGPoint2D *pCtrlPoints, UGint lCtrlPointCount,
		UGPoint2D *&pResultPoints, UGint &lResultPointCount, UGint nPointCountPerSegment = 20);

private:
	
	static UGdouble CalcEllipseRadian(const UGdouble &dPntRadian, const UGdouble &dSemiMajorAxis,
									 const UGdouble &dSemiMinorAxis);
	
	static UGdouble GetCAR(UGint nCoefficient, UGdouble fSegment);
#endif // end declare ugc API
};

}

#endif 

/*! \file	 UGOpPointLine.h
 *  \brief	 点/线 之间的空间运算
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpPointLine.h,v 1.11 2007/10/19 03:01:30 guohui Exp $
 */


#if !defined(AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_)
#define AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGPoint3D.h"

namespace UGC {
//! \brief 点/线 之间的空间运算
class ALGORITHM_API UGOpPointLine  
{
private:
	UGOpPointLine();
	
public: // 求点到线的距离
	
	//! \brief 用点分割简单线
	static UGbool Split(const UGPoint2D& pntSplit, const UGPoint2D* pLinePoints, 
						UGint nLinePntCount, UGPoint2Ds& pntResLine1, 
						UGPoint2Ds& pntResLine2);

	//! \brief 用Point2D分割三维线，如LineM.打断点的Z值将插值
	static UGbool Split(const UGPoint2D& pntSplit, const UGPoint3D* pLinePoints, 
						UGint nLinePntCount, UGPoint3Ds& pntResLine1, 
						UGPoint3Ds& pntResLine2);

	//! \brief 点到线段的距离
	//! \return 如果点到线段的垂足在线段上,则返回点到垂足的距离; 
	//!			否则返回点到线段两个端点距离的较小值
	static UGdouble DistanceToSegment(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 点到直线的距离
	static UGdouble DistanceToLine(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 点到直线的距离的平方
	static UGdouble DistanceToLineSquare(const UGPoint2D& pnt, 
							 const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 点到折线的距离
	//! \remarks 是到vertex的最小值, 和 到线段垂足的最小值 中的最小值
	static UGdouble Distance(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount);
	//{{ by guohui 2007.10.12
	//! \brief 点到折线的距离
	static UGdouble Distance(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount);
	//}} by guohui 2007.10.12

	//! \brief 点到折线上点的距离的最小值 和 折线上该点的Index
	//! \remarks 需要的最小值必须比dMinValue参数小,否则返回0,nPntIndex==-1
	static UGdouble MinDistanceToVertex(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGint& nPntIndex, UGdouble dMinValue=INFINITEBIG);

	// by guohui 2007.09.13
	//! \brief 点到折线的距离的最小值以及对应的点
	//! \param pntHitTest	[in]		点
	//! \param pPoints		[in]		折线的点
	//! \param nPntCount	[in]		折线点个数
	//! \param pntProject	[in]		映射点
	//! \return 成功,返回true
	static UGbool NearestPointToVertex(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGPoint2D & pntProject,UGdouble &dDistance);

	// by guohui 2007.10.09
	//! \brief 点到折线的距离的最小值以及对应的点
	//! \param pntHitTest	[in]		点
	//! \param pPoints		[in]		折线的点
	//! \param pPolyCounts	[in]		折线点个数
	//! \param pntProject	[in]		映射点
	//! \return 成功,返回true
	static UGbool NearestPointToVertex(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount, 
							 UGPoint2D & pntProject,UGdouble &dDistance);

	//! \brief 点到折线上线段的距离的最小值 和 该线段的起始点Index
	//! \remarks 需要的最小值必须比dMinValue参数小,否则返回0,nPntIndex==-1
	static UGdouble MinDistanceToSegment(const UGPoint2D& pnt, 
							 const UGPoint2D* pPoints, UGint nPntCount, 
							 UGint& nPntIndex, UGdouble dMinValue=INFINITEBIG);
	
	//!  \brief 点到折线上线段的距离
	//! \remarks 网络分析坐标点转换需要用到
	static  UGdouble DistPtToLinesect(const UGPoint2D &pntStart, const UGPoint2D &pntEnd, 
									const UGPoint2D &pntHitTest, UGdouble& dDistToFrom);

	//! \brief	 点到线段的最大距离
	//! \remarks 最大距离: 线段上存在一点pntTest,使得Ditance(pntTest,pntHitTest)最大
	static  UGdouble MaxDistance(const UGPoint2D &pntHitTest, 
								 const UGPoint2D &pntStart, const UGPoint2D &pntEnd );
	
	//! \brief	 点到线段的最大距离
	//! \remarks 最大距离: 线段上存在一点pntTest,使得Ditance(pntTest,pntHitTest)最大
	static  UGdouble MaxDistance(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, UGint nPntCount );

	//! \brief	 点到线段的最大距离
	//! \remarks 最大距离: 线段上存在一点pntTest,使得Ditance(pntTest,pntHitTest)最大
	static  UGdouble MaxDistance(const UGPoint2D& pntHitTest, 
							 const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount);

	//! \brief		球面上，点到直线的距离
	//! \param		pntHitTest  传入的点(x,y坐标分别表示经度和维度)
	//! \param		pntStart	传入的点(x,y坐标分别表示经度和维度)
	//! \param		pntEnd		传入的点(x,y坐标分别表示经度和维度)
	//! \param		dRadius		球体半径
	static  UGdouble RadianDistPointToLinesect(const UGPoint2D &pntHitTest, 
					 const UGPoint2D &pntStart, const UGPoint2D &pntEnd , double dRadius=6371118);
public: // 求点到线的垂足

	//! \brief 求点到直线的垂足
	static UGPoint2D ProjectPoint(const UGPoint2D& pnt,
								  const UGPoint2D& pnt1, const UGPoint2D& pnt2);


public: // 用点打断线

	//! \brief 用点打断线
	//! \param pntResults 传入时,必须为空数组
	//! \return 成功打断,返回true
	static UGbool Break(const UGPoint2D& pnt, 
						  const UGPoint2D* pPoints, UGint nPntCount, 
						  UGArray<UGPoint2Ds*>& pntResults);

	//! \brief 用点打断线
	//! \param pntResults 传入时,必须为空数组
	//! \return 成功打断,返回true
	static UGbool Break(const UGPoint2D& pnt, 
						  const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint nSubCount, 
						  UGArray<UGPoint2Ds*>& pntResults);

};

}

#endif // !defined(AFX_UGOPPOINTLINE_H__7A4B3872_A489_4650_8358_D2B6A03AFA6C__INCLUDED_)

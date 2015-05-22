/*! \file	 UGRelPointLine.h
 *  \brief	 判断点线之间的空间位置关系
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPointLine.h,v 1.8 2007/11/12 07:42:24 guohui Exp $
 */

#if !defined(AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_)
#define AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

//! \brief 判断点线之间的空间位置关系
class ALGORITHM_API UGRelPointLine  
{
private:
	UGRelPointLine();
	 
public: // 点 线段基本空间位置关系判断

	//! \brief 判断点是否在线段的左边
	static UGbool IsLeft(const UGPoint2D& pnt, 
						 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断点是否在线段的右边
	static UGbool IsRight(const UGPoint2D& pnt, 
						  const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断点是否在线段上(不算延长线)
	static UGbool IsOnLineSegment(const UGPoint2D& pnt, const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									UGdouble dTolerance=EP);

public: // 点线 扩展空间位置关系判断(可用基本位置关系判断推导得到)

	//! \brief 判断点是否在直线上(包括线段及其延长线)
	static UGbool IsOnLine(const UGPoint2D& pnt, 
						   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 得到点和直线的位置关系
	//! \return 1表示点在直线的左边, -1表示在右边, 0 表示在直线上
	static UGint PntMatchLine(const UGPoint2D& pnt, 
							   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断点是否在折线的左边
	//! \remarks 采用距离点最近的线段代替折线,判断是左边还是右边
	static UGbool IsLeft(const UGPoint2D& pnt, 
						 const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 判断点是否在折线上
	static UGbool IsOnPolyline(const UGPoint2D& pnt, 
							   const UGPoint2D* pPoints, UGint nPntCount);
	// add by guohui 2007.10.08
	//! \brief 判断点是否在折线上
	static UGbool IsOnPolyline(const UGPoint2D &pnt, 
							   const UGPoint2D *pPoints,const UGint* pPolyCount,UGint nSubCount);

	//! \brief 判断两个点是否在直线的同一侧
	//! \return 0,在同一条直线上; 1,在同一侧; 2, 在两侧; 3,有一点在直线上
	static UGuint IsOnSameSide(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
							   const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

public: // 其他关系判断

	//! \brief 判断点在线段的垂足是否在线段上
	static UGbool IsProjectOnLineSegment(const UGPoint2D& pnt, 
										 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断点在线段的垂足是否在线段内部(不包括线段的两个端点)
	static UGbool IsProjectOnLineSegmentInterior(const UGPoint2D& pnt, 
										 const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断点到线段的距离是否在指定的容限内
	static UGbool IsNearToLineSegment(const UGPoint2D& pnt, 
									  const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									  UGdouble dTolerance);
	
	//! \brief 判断点到线段的距离是否在指定的容限内
	//! \return -1不在容限内；如果返回值属于[0,1]，表示与pnt最近点在pntStart-penEnd上的位置比例。
	static UGdouble NearToLineSegment(const UGPoint2D& pnt, const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
									UGdouble dTolerance);
	
	//! \brief 判断点到折线的距离是否在指定的容限内
	static UGbool IsNearToPolyline(const UGPoint2D& pnt, 
								   const UGPoint2D* pPoints, UGint nPntCount,
								   UGdouble dTolerance);
	
	//! \brief 判断点到线的距离是否在指定的容限内
	//!	\remark 两端线段使用射线判断；中间线段使用线段判断。
	static UGbool IsPointOnLine(const UGPoint2D &pntTest, UGPoint2D *pPoints, UGint nCount, UGdouble dTolerance);
	
	//! \brief 判断点到线的距离是否在指定的容限内
	static UGbool IsPointOnLine(const UGPoint2D &pntTest, const UGPoint2D &pntStart, const UGPoint2D &pntEnd,
								UGdouble dTolerance);


};

}

#endif // !defined(AFX_UGRELPOINTLINE_H__5CEDF8F8_5E21_43F5_B5E5_1F502EEE435C__INCLUDED_)

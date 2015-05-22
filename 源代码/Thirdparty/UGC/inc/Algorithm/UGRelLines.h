/*! \file	 UGRelLines.h
 *  \brief	 线线空间位置关系
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelLines.h,v 1.10 2007/11/02 10:20:58 qiuli Exp $
 */


#if !defined(AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_)
#define AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"

namespace UGC {

// 术语定义：
// LineSeg: 线段，由两点组成，仅包括两个端点及其之间的部分; 两点不能相同
// Polyline: 折线, 多点组成一个连续的点串; 多点不能为同一个点
// PolyPolyline: 复杂折线, 由多个折线组成, 折线间首尾可不相交
// 

//! \brief 线线空间位置关系类
class ALGORITHM_API UGRelLines
{
private:
	UGRelLines();

public:	// 线线基本空间关系判断

/// 完全相等
	//! \brief 判断线段和线段是否相等
	//! \remarks 相等: 点的个数,对应坐标值
	static UGbool IsIdentical(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线和折线是否相等
	//! \remarks 相等: 点的个数,对应坐标值
	static UGbool IsIdentical(const UGPoint2D* pPoints1, UGint nPntCount1,
							  const UGPoint2D* pPoints2, UGint nPntCount2);

	// by guohui 2007.10.16
	//! \brief 判断折线和折线是否相等
	//! \remarks 相等: 点的个数,对应坐标值
	static UGbool IsIdentical(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);

/// 包含
	//! \brief 判断线段1是否包含线段2
	//! \remarks 包含: 线段1和线段2的交集等于线段2
	static UGbool IsContain(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线是否包含线段
	//! \remarks 包含: 折线和线段的交集等于线段
	static UGbool IsContain(const UGPoint2D* pPoints, UGint nPntCount,
							const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	static UGbool IsContain(const UGPoint2D* pPoints,const   UGint* lPolyCount, UGint nSubCount,
							const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! \brief 判断折线1是否包含折线2
	//! \remarks 包含: 折线1和折线2的交集等于折线2
	static UGbool IsContain(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);


	// by guohui 2007.10.16 copy from UGGeoRelation::IsLineBContainLineB
	//! \brief 判断折线1是否包含折线2
	static UGbool IsContain(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
							const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);
// 相互包含
	//! \brief 判断线段和线段是否重合
	//! \remarks 重合: 两者互相包含
	static UGbool IsContainEachOther(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线和折线是否重合
	//! \remarks 重合: 两者互相包含
	static UGbool IsContainEachOther(const UGPoint2D* pPoints1, UGint nPntCount1,
						  const UGPoint2D* pPoints2, UGint nPntCount2);


// 交叠
	//! \brief 判断线段和线段是否交叠
	//! \remarks 交叠: 两者交集必须有一维部分,且不能重合
	static UGbool IsOverlap(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						    const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线和折线是否交叠
	//! \remarks 交叠: 两者交集必须有一维部分,且不能重合
	static UGbool IsOverlap(const UGPoint2D* pPoints1, UGint nPntCount1,
						    const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断折线和折线是否交叠
	//! \remarks 交叠: 两者交集必须有一维部分,且不能重合
	static UGbool IsOverlap(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);


// 相交
	//! \brief 判断线段和线段是否相交
	//! \remarks 相交: 两者的交集必须有零维部分
	static UGbool IsIntersect(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, UGdouble dTolerance=EP);

	//! \brief 判断折线和折线是否相交
	//! \remarks 相交: 两者的交集必须有零维部分
	static UGbool IsIntersect(const UGPoint2D* pPoints1, UGint nPntCount1,
							  const UGPoint2D* pPoints2, UGint nPntCount2);

//跨越
	//! \brief 判断线段1是否跨越线段2
	//! \remarks 跨越: 线段1被线段2分割为至少两个部分,分别位于2的两侧,且分离点不等于端点(起点or终点)
	static UGbool IsCross(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线1是否跨越折线2
	//! \remarks 跨越: 折线1被折线2分割为至少两个部分,分别位于2的两侧,且分离点不等于端点(起点or终点)
	static UGbool IsCross(const UGPoint2D* pPoints1, UGint nPntCount1,
						  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断折线1是否跨越折线2
	//! \remarks 跨越: 折线1被折线2分割为至少两个部分,分别位于2的两侧,且分离点不等于端点(起点or终点)
	static UGbool IsCross(const UGPoint2D* pPoints1,const  UGint* lPolyCount1, UGint nSubCount1,
						  const UGPoint2D* pPoints2,const  UGint* lPolyCount2, UGint nSubCount2);

	
// 相离
	//! \brief 判断线段和线段是否相离
	//! \remarks 相离: 两者交集为空集
	static UGbool IsDisjoint(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
							 const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线和折线是否相离
	//! \remarks 相离: 两者交集为空集
	static UGbool IsDisjoint(const UGPoint2D* pPoints1, UGint nPntCount1,
							 const UGPoint2D* pPoints2, UGint nPntCount2);


public: // 上述基本关系的组成实用关系判断

	//! \brief 判断线段1是否和线段2接触
	//! \remarks 接触: 交集不为空,即不相离
	static UGbool IsTouch(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断折线1是否和折线2接触
	//! \remarks 接触: 交集不为空,即不相离
	static UGbool IsTouch(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 线段交集有一维部分
	//! \remarks 等于 Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
						  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 线段交集有一维部分
	//! \remarks 等于 Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	// add by guohui 2007.10.08
	//! \brief 线段交集有一维部分
	//! \remarks 等于 Contain(A,B) || Contain(B,A) || Overlap
	static UGbool IsMatch(const UGPoint2D* pPoints1, const UGint* pPolyCount1,UGint nSubCount1,
							const UGPoint2D* pPoints2, const UGint* pPolyCount2,UGint nSubCount2);
	
	//! \brief 线和线内部是否相交
	//! \remarks 线内部的定义是：除了线的两个端点外的线的其他部分
	static UGbool IsInteriorIntersect(const UGPoint2D* pPoints1, UGint nPntCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);


public:	// 其他一下实用判断算法

	//! \brief 判断线段是否垂直, 可以没有交点
	static UGbool IsPerpendicular(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断线段是否平行, 可以在同一条直线上,也可以重叠,甚至重合
	static UGbool IsParallel(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

	//! \brief 判断线段的最小距离是否在容限范围之内
	static UGbool IsNear(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2,
								  const UGdouble dDistance);



public: // 内部辅助使用,空间算法库外不得使用

	//! \brief 返回值精确的描述两条线段相交的情况
	static UGint IntersectLineSegment(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
									  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);
	//! \brief 得到一条线段中距离From点很近的点,求之点离From点不超过一个单位
	static UGPoint2D GetTestPoint(const UGPoint2D* pPointFrom, const UGPoint2D* pPointTo);

	//! \brief 线段1和线段2 是否同向
	//! \remarks 矢量方向在同一个象限内
	static UGbool IsSameQuadrant(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1,
								  const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2);

};

}

#endif // !defined(AFX_UGRELLINELINE_H__98175692_7F5B_4534_A287_7F7C990E4436__INCLUDED_)

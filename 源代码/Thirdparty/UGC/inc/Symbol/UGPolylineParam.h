
// UGPolylineParam.h

/*!
   **************************************************************************************
    \file     UGPolylineParam.h
   **************************************************************************************
    \author   郑元满
    \brief    『线段参数类』和『折线参数类』；
	          这2个类用于辅助『线型基线绘制器UGLineSymbolBaseDrawer』实现基线的模式循环绘制；
			  在循环绘制模式之前，先把折线的参数计算好，避免在循环绘制时多次重复计算，
			  其主要目的是提高绘制效率，
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-18  郑元满    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UG_POLYLINEPARAM_H
#define UG_POLYLINEPARAM_H

#include "Algorithm/UGPoint.h"
#include "Algorithm/UGPoint2D.h"
#include "Base/UGThread.h"

namespace UGC
{

// 绘制线形时, 需要的一些参数,提前计算好, 以提高绘制效率

/** 线段参数：记录一条线段的x和y方向上的间距，以及长度
    @remarks
	   
*/
struct UGSegmentParam
{

private:
	//modified by xielin 2007-12-27 现在要支持多线程，全局就不行了，改掉
	//! 仅仅是为了CalcVPoint()和CalcHPoint()计算时不必分配临时变量，提高一点效率，该2个函数会在系统中频繁调用
	//UGdouble ratio;

public:
	UGdouble m_dx;
	UGdouble m_dy;
	UGdouble m_dLen;
	
	UGSegmentParam() : m_dx(0), m_dy(0), m_dLen(0){}
    
	//! 计算沿着线段的正方向或反方向(dLength为负值), 起点为ptStart, 长度为dLength的点的坐标
	UGPoint2D CalcHPoint(UGdouble xPtStart, UGdouble yPtStart, UGdouble dLength) const;
	
	//! 计算垂直线段, 垂足点为ptAnchor, 高度为 dHeight 的点的坐标
	UGPoint2D CalcVPoint(UGdouble xPtAnchor, UGdouble yPtAnchor, UGdouble dHeight) const;
	
	
};


class UGPolylineParam
{
public:

	UGPolylineParam();
	
	UGdouble GetTotalLength();

	const UGSegmentParam& GetSegParam(UGint nIndex) const;
	UGSegmentParam& GetSegParam(UGint nIndex);

	const UGSegmentParam& GetCurrentSegParam() const;
	void SetCurrentSegIndex(UGint nCurSegIndex);

	void CalculateParams(const UGPoint* pPoints, UGint nPntCount);

private:
	//! 折线的线段参数的集合
	UGArray<UGSegmentParam> m_SegParams;
	
	//! 折线的总体长度
	UGdouble m_dTotalLength;

	//! 当前正在处理的线段索引号
	UGint m_nCurSegIndex;

	//added by xielin 2007-12-27 加锁一下
	UGMutex m_mutex;
	
};


}// namesapce UGC

#endif


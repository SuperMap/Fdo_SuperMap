// UGRasterScan.h: interface for the UGRasterScan class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRasterScan.h
   **************************************************************************************
    \author   陈国雄
    \brief    矢量栅格扫描类                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-26  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_)
#define AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_

#include "UGRect.h"
#include "Base/UGString.h"
#include "Base/UGTextStyle.h"

namespace UGC{

typedef void (*RASTERSCANPROC)(UGint X, UGint Y, UGuint pData);

class ALGORITHM_API UGRasterScan  
{
public:
	UGRasterScan();
	virtual ~UGRasterScan();

public:

	//! \brief 线段
	static UGbool Line(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData);	
	
	//! \brief 线段
	static UGbool Line(const UGPoint& pntStart, const UGPoint& pntEnd, RASTERSCANPROC pProcFunc, UGuint pData);	
	
	//! \brief 折线
	static UGbool Polyline(const UGPoint* pPoints, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bClosed = false);
	
	//! \brief 多条折线
	static UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bClosed = false);
	
	//! \brief 多边形
	static UGbool Polygon(const UGPoint* pPoints, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 多个多边形
	static UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 矩形
	static UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 矩形
	static UGbool Rectangle(const UGRect& rect, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 椭圆
	static UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 椭圆
	static UGbool Ellipse(const UGRect& rect, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

	//! \brief 弧
	static UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData);
	
	//! \brief 弧
	static UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData);

	//! \brief 弓形
	static UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 弓形
	static UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 扇形
	static UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 扇形
	static UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

	//! \brief 圆角矩形
	static UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 圆角矩形
	static UGbool RoundRect(const UGRect& rect, UGPoint point, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 文本 
	//! \remark  本接口还未实现
	static UGbool TextOut(UGint x, UGint y, const UGString& str, const UGTextStyle& textStyle, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);
	
	//! \brief 文本 
	//! \remark  本接口还未实现
	static UGbool TextOut(const UGPoint& point, const UGString& str, const UGTextStyle& textStyle, RASTERSCANPROC pProcFunc, UGuint pData, UGbool bFilled = true);

};

}

#endif // !defined(AFX_UGRASTERSCAN_H__4477CA04_A5A3_4196_BDB3_212AED1B043D__INCLUDED_)

// UGRegionSelect.h: interface for the UGRegionSelect class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGRegionSelect.h
   **************************************************************************************
    \author   陈国雄
    \brief    多边形选择类，用于放大，缩小，矩形、圆形、多边形选择的显示。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_)
#define AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_

#include "Geometry/UGGeoRegion.h"

namespace UGC {

class UGGraphics;
class UGMapWnd;

class EDITOR_API UGRegionSelect  
{
public:
	enum
	{
		Rectangle,		//矩形选择
		Circle,			//圆选择
		Polygon		//多边形选择
	};
public:
	UGRegionSelect();
	virtual ~UGRegionSelect();
	
public:
	UGbool IsTrackingEnable();
	UGbool IsTracking();

	void OnDraw(UGGraphics* pGraphics);
	void StartTracking(UGMapWnd* pMapWnd, UGint nSelectType);
	void EndTracking(UGGraphics* pGraphics, UGbool bJava = false);	

	UGbool AddHandle(UGGraphics* pGraphics, const UGPoint2D& point, UGbool bJava = false);
	UGbool MoveHandle(UGGraphics* pGraphics, const UGPoint2D& point, UGbool bJava = false);
	void RemoveAll();

	UGbool ConvertToGeoRegion(UGGeoRegion& region);
	UGbool ConvertToRect(UGRect2D& rect);

	UGbool ComputeBounds();	
	UGRect2D GetBounds();

protected:
	UGbool InvalidRect(UGGraphics* pGraphics, UGbool bJava = false);

protected:
	UGint m_nType;				//类型:Rectangle,Circle,Polygon
	UGArray<UGPoint2D> m_Points;	//跟踪开始后，鼠标左击点集的地理坐标
	UGPoint2D m_pntLastMove;	//最后一个点
	UGbool m_bIsTracking;		//判断是否正在跟踪
	UGbool m_bTrackingEnable;	//是否可以跟踪
	UGRect2D m_rcBounds;		//刷新范围
	UGMapWnd *m_pMapWnd;

};

}

#endif // !defined(AFX_UGREGIONSELECT_H__669C9A60_C4D6_483E_892D_6575FB1A128A__INCLUDED_)

// UGWGraphics.h: interface for the UGWGraphics class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWGraphics.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    Windows图形显示类                                                      
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_)
#define AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_

#include "Graphics/UGGraphics.h"

// added by zengzm 2007-4-29 添加类型定义, 该类型gdiplus需要,但只在vc8的头文件中定义
#if defined(_WIN64)
    typedef unsigned __int64 ULONG_PTR;
#elif (_MSC_VER == 1200) //Defined as 1200 for Microsoft Visual C++ 6.0. 
//#else
    typedef unsigned long ULONG_PTR;
#else // VC8
	typedef _W64 unsigned long ULONG_PTR;
#endif

namespace UGC
{

class WGRAPHICS_API UGWGraphics : public UGGraphics  
{
public:
	UGWGraphics();
	virtual ~UGWGraphics();
	
	//! 获取实际对象
	virtual void GetGraphicsData(UGGraphicsData &data) const;
	//! 设置实际对象
	virtual void SetGraphicsData(const UGGraphicsData &data);
	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics);
	virtual UGbool DeleteGraphics();

	virtual UGbool IsPrinting() const;

	virtual UGImage* SelectImage(UGImage *pImage);
	virtual UGFont* SelectFont(UGFont *pFont);
	virtual UGBrush* SelectBrush(UGBrush *pBrush);
	virtual UGPen* SelectPen(UGPen *pPen);
	
	// 获取前景色
	virtual UGColor GetForeColor() const;
	// 设置前景色
	virtual UGColor SetForeColor(UGColor color);
	// 获取背景色
	virtual UGColor GetBackColor() const;
	// 设置背景色
	virtual UGColor SetBackColor(UGColor color);

	// 获取背景模式
	virtual UGint GetBackMode() const;
	// 设置背景模式
	virtual UGint SetBackMode(UGint nBKMode);

	virtual UGint SetROP2(UGint nDrawMode);
	virtual UGint GetROP2();

	// 获取映射模式
	virtual UGint GetMapMode() const;
	// 设置映射模式
	virtual UGint SetMapMode(UGint nMapMode);	

	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1);
	virtual void DPtoLP(UGRect& rect);
	virtual void DPtoLP(UGSize& size);
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1);
	virtual void LPtoDP(UGRect& rect);
	virtual void LPtoDP(UGSize& size);
	
	virtual void LPtoHIMETRIC(UGSize& size);
	virtual void DPtoHIMETRIC(UGSize& size);
	virtual void HIMETRICtoLP(UGSize& size);
	virtual void HIMETRICtoDP(UGSize& size);

	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode);

	virtual UGPoint GetCurrentPosition() const;

	// 获取像素值
	virtual UGColor GetPixel(UGint x,UGint y);
	// 设置像素值
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color);

	// 
	virtual UGPoint MoveTo(UGint x,UGint y);
	// 
	virtual UGbool LineTo(UGint x,UGint y);
	// 
	virtual UGPoint MoveTo(UGPoint point);
	// 
	virtual UGbool LineTo(UGPoint point);

	// 画直线
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2);
	// 画直线
	virtual UGbool Line(UGPoint point1, UGPoint point2);

	// 画折线
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount);
	// 画多条折线
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	// 画多边形
	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount);
	// 画多个多边形
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	// 画矩形
	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool Rectangle(const UGRect& rect);

	// 画椭圆
	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool Ellipse(const UGRect& rect);

	// 画弧
	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 

	// 画弓形
	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 
	// 画饼形
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 );
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd); 

	// 画圆角矩形
	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point); 

	// 画图片
	virtual UGbool DrawImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight, 
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 							
							UGint nDrawMode);
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGint nDrawMode);
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGImage::UGImageData& ImageData);

	//added by lugw 2007-04-28 实现图片旋转
	//! \brief 绘制旋转后的栅格图片
	/**
	\param x，y           新图起始点[in]
	\param nWidthRotate   新图宽度[in]
	\param nHeightRotate  新图高度[in]
	\param dAngle         旋转角度[in]
	\param pMemGraphics   原图所在graphics[in]
	\param xSrc，ySrc     原图起始点[in]
	\param nWidth         原图宽度[in]
	\param nHeight        原图高度[in]
	\param nDrawMode      绘制模式[in]
	\remarks 绘制模式暂时还没有用到，无作用
	*/
	virtual UGbool RotateImage(UGint x, UGint y, 
							UGint nWidthRotate, UGint nHeightRotate,
							UGdouble dAngle,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nWidth, UGint nHeight,
							UGint nDrawMode);

	// 写字符串
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle());	
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat);
	
	// 获取文本对齐信息
	virtual UGint GetTextAlign() const;
	// 设置文本对齐信息
	virtual UGint SetTextAlign(UGint nTextAlign);
	virtual UGSize GetTextExtent(const UGString& str);	

	//! 设置光滑模式
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);
	//! \brief 获取基线离锚点（左上角）的距离
	virtual UGint GetBaselinetoAnchor();
public:
	static UGRect ConvertUGPoint2POINT(const UGPoint* pPoints, LPPOINT lpPoints, int nCount);	
	static void ConvertPOINT2UGPoint(const LPPOINT lpPoints, UGPoint* pPoints, int nCount);

protected:
	int DPtoLP_X(int x);
	int DPtoLP_Y(int y);
	int LPtoDP_X(int x);
	int LPtoDP_Y(int y);	
	void LPtoDP(LPPOINT pPoints, int nCount = 1);

	UGRect PreProcessPoints(const UGPoint* pPoints, int nCount);
	void ProcessBrushOrg(int x, int y);

	UGbool RegionWithBitmap(UGRgn *pClipRgn, UGbool bRect = TRUE);
	virtual UGint GetTextPath(const UGString& strText, const UGint x, const UGint y, UGFont* pFont, 
						   UGArray<UGPoint>* pPointArray, UGArray<UGbyte>* pTypes);
private:
	UGbool m_bNeedReleaseDC;

	LPPOINT m_lpPoints;	
	int m_nPntCountMax;



	//unsigned long m_nGdiplusToken;
	ULONG_PTR m_nGdiplusToken;

//friend class UGPSGraphics;
};

}

#endif // !defined(AFX_UGWGRAPHICS_H__DF5DB089_3725_4D76_963F_BF593DB7D870__INCLUDED_)

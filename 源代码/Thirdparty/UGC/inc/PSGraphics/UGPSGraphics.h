// UGPSGraphics.h: interface for the UGPSGraphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_)
#define AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Graphics/UGGraphics.h"
#include "PSGraphics/CreEPS.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{
#define BITSPERPIXEL  8								//一个像素的单色位数（即红绿蓝各占多少位）

class PSGRAPHICS_API UGPSGraphics : public UGGraphics  
{
public:
	UGPSGraphics();
	UGPSGraphics(const UGchar* filename, const UGfloat startX, const UGfloat startY,
		                                    const UGfloat   endX, const UGfloat   endY,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL);
	UGPSGraphics(const UGchar* filename, const UGfloat width, const UGfloat height,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	virtual ~UGPSGraphics();
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
	// 设置前景色	文本颜色
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

public:
//	static UGRect ConvertUGPoint2POINT(const UGPoint* pPoints, LPPOINT lpPoints, int nCount);	
//	static void ConvertPOINT2UGPoint(const LPPOINT lpPoints, UGPoint* pPoints, int nCount);
	void NewFile( const UGchar* filename, const UGfloat startX, const UGfloat startY,
		                                    const UGfloat   endX, const UGfloat   endY,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	void NewFile( const UGchar* filename, const UGfloat width, const UGfloat height,
		              const UGbool latex = false, const UGchar* altEPSFilename = NULL );
	virtual void SetCoordRatio(UGfloat dRatioX,UGfloat dRatioY);
	
	//将线和文本反走样分开，和SFC一致
	//virtual void SetSmoothingMode(UGbool bSmoothingMode);//psgraphics中不考虑反走样
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);//psgraphics中不考虑反走样
	virtual void SetTextSmoothingMode(UGbool bSmoothingMode);//psgraphics中不考虑反走样

	////! \brief 矩形裁剪
	virtual UGbool RectClip(UGint left, UGint top, UGint right, UGint bottom);
	virtual UGbool RectClip(const UGRect& rect);

protected:
	UGint DPtoLP_X(UGdouble x);
	UGint DPtoLP_Y(UGdouble y);
	UGdouble LPtoDP_X(UGint  x);
	UGdouble LPtoDP_Y(UGint  y);	
	
	void DPtoLP(const UGPoint2D* pPnts2D,UGPoint* pPoints, UGint nCount = 1);
	void DPtoLP(const UGRect2D& rect2D,UGRect& rect);
	void DPtoLP(const UGSize2D& size2D,UGSize& size);
	void LPtoDP(const UGPoint* pPoints, UGPoint2D* pPnts2D,UGint nCount = 1);
	void LPtoDP(const UGRect& rect, UGRect2D& rect2D);
	void LPtoDP(const UGSize& size,UGSize2D& size2D);

	UGint GetBits(UGImage::UGImageData& bmpData,UGint* pIntBits);

	//! \biref 将UGImageData中的pBits转为RGB独立的颜色值，每个UGchar表示R、G、B中的一个
	/*
	\param bmpData 包含要转出颜色值的pBits的imagedata
	\param pBits	转出的RGB值数组一个R、G或B值是数组中独立的一项，按R、G、B、R、G、B...排列
	*/
	UGint GetBitsChar(UGImage::UGImageData& bmpData, UGint xSrc, UGint ySrc, UGint nWidth, UGint nHeight, UGchar* pBits);

	void PointstoLine(const UGPoint* pPoints, UGint nCount);
private:
	UGbool m_bNeedReleaseDC;

	UGPoint2D* m_lpPoints;	
	UGint m_nPntCountMax;

	// 象素/逻辑单位。
//	UGdouble m_dCoorRatioX;
//	UGdouble m_dCoorRatioY;

	CreEPS *  m_pCreEPS;	
//	UGString m_strPath;
//	UGGraphics* pGraphics;		//这个与平台相关
	UGbool m_bTransparentMode;	//设置是否背景透明
	UGbool m_bCompatible;		//如果是CreateCompatibleGraphics 则为真 直接new的为假
};
}
#endif // !defined(AFX_UGPSGRAPHICS_H__C9316B6D_6F60_4137_942A_4811741085EB__INCLUDED_)

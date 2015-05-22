// UGDrawing.h: interface for the UGDrawing class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawing.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    显示类                                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)
#define AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_

#include "UGDrawCache.h"
#include "UGDrawParamaters.h"
#include "UGDrawMaker.h"
#include "Engine/UGDataSource.h"
#include "Base/ugplatform.h"
#include "Base/UGProgress.h"
namespace UGC {	

typedef void (UGSTDCALL *DRAWPAINTPROC)(UGGraphics* pGraphics, UGlong pPaintWnd);

// by zengzm 2007-3-26 把__stdcall定义到ugplatform中
typedef void (UGSTDCALL *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGlong pWnd);
//#ifdef WIN32
//typedef void (__stdcall *DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#else
//typedef void (*DRAWCALLBACKPROC)(UGint nPercent, UGbool &bCancel, UGuint pWnd);
//#endif
//added by xielin 2007-04-30 
//! \brief 回调函数，用于扩展对象绘制
//! \param 		pGraphics		当前绘制的Graphics，用于在该Graphics上绘制对象
//! \param 		pGeometry		扩展对象
//! \param 		pWnd			实现该回调函数对象的指针
typedef void (UGSTDCALL *DRAWCUSTOMGEOMETRYCALLBACKPROC)(UGGraphics* pGraphics,UGGeometry* pGeometry,UGlong pWnd);

class UGGeoPoint;
class UGGeoLine;
class UGGeoRegion;
class UGGeoText;
class UGGeoArc;
class UGGeoBSpline;
class UGGeoCardinal;
class UGGeoCircle;
class UGGeoCompound;
class UGGeoDonut;	
class UGGeoEllipse;
class UGGeoEllipticArc;
class UGGeoLineM;	
class UGGeoLwpline;
class UGGeoMultiPoint;	
class UGGeoPath;
class UGGeoPie;
class UGGeoRect;
class UGGeoRectRound;
class UGGeoEquilateral;
class UGGeoCurve;
class UGTINBlock;

class DRAWING_API UGDrawing  
{
public:
	UGDrawing();
	virtual ~UGDrawing();

public:
	//! \brief 绘制几何对象
	//! \param pGeometry 几何对象
	//! \return 绘制是否成功
	UGbool Draw(UGGeometry* pGeometry);
	//! \brief 绘制文本
	//! \param UGGeoText 文本对象
	//! \param bThemeStyle 是否是标签样式
	//! \param bSingleTextStyle 是否和当前图层是同一个文本形式
	//! \return 绘制是否成功
	UGbool Draw(UGGeoText* pGeoText, UGbool bThemeStyle, UGbool bSingleTextStyle = true);
    //! \brief 绘制数据集
	//! \param pDataset 文本对象
	//! \param nTransparentRate 透明度
	//! \param UGProgress 进程条类
	//! \return 绘制是否成功
	UGbool Draw(UGDataset* pDataset, UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	//! \brief 绘制点
	//! \param point 要绘制的点
	//! \return 绘制是否成功
	UGbool Point(const UGPoint& point);
	//! \brief 绘制点
	//! \param x 要绘制的点x坐标
    //! \param y 要绘制的点y坐标
	//! \return 绘制是否成功
	UGbool Point(UGint x, UGint y);
	 //! \brief 画一条折线
    //! \param pPoints 折线的点列指针
	//! \param nCount 有多少个点
	//! \return 如果成功返回TRUE,失败返回FALSE
	UGbool Polyline(const UGPoint* pPoints, UGint nCount);
	//! \brief 画多个折线
    //! \param pPoints 多条折线的点列指针
	//! \param pPntCount 每个折线的点数
	//! \param nCount 折线的个数
	//! \return 如果成功返回TRUE,失败返回FALSE
	UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);
   //! \brief 画一个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param nCount 有多少个点
	//! \return 如果成功返回TRUE,失败返回FALSE
	UGbool Polygon(const UGPoint* pPoints, UGint nCount);
	//! \brief 画多个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param pPntCount 每个多边形的点数
	//! \param nCount 多边形的个数
	//! \return 如果成功返回TRUE,失败返回FALSE
	UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount);

	//! \brief 画矩形
	//! \param x1 矩形的左上角的X坐标 
    //! \param y1 矩形的左上角的Y坐标 
	//! \param x2 矩形的右下角的X坐标
	//! \param y2 矩形的右下角的Y坐标
	//! \return 返回绘图是否成功
	UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief 画矩形
	//! \param rect 需要绘制的矩形 
	//! \return 返回绘图是否成功
	UGbool Rectangle(const UGRect& rect);
	//! \brief 画椭圆
	//! \param x1 绘制的矩形的左上角的X坐标 
    //! \param y1 绘制的矩形的左上角的Y坐标 
	//! \param x2 绘制的矩形的右下角的X坐标
	//! \param y2 绘制的矩形的右下角的Y坐标
	//! \return 返回绘图是否成功
	UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2);
	//! \brief 画椭圆
	//! \param rect 绘制的矩形 
	//! \return 返回绘图是否成功
	UGbool Ellipse(const UGRect& rect);

	//! \brief    画弧线
	//! \param x1 绘制的矩形的左上角的X坐标 
    //! \param y1 绘制的矩形的左上角的Y坐标 
	//! \param x2 绘制的矩形的右下角的X坐标
	//! \param y2 绘制的矩形的右下角的Y坐标
	//! \param x3 弧线起始射线点 
	//! \param y3 弧线结束射线点
	//! \return 返回绘图是否成功
	UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
	//! \brief    画弧线
	//! \param pntStart 弧线起始射线点 
	//! \param pntEnd 弧线结束射线点
	//! \return 返回绘图是否成功
	UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    画弓形
	//! \param x1 绘制的矩形的左上角的X坐标 
    //! \param y1 绘制的矩形的左上角的Y坐标 
	//! \param x2 绘制的矩形的右下角的X坐标
	//! \param y2 绘制的矩形的右下角的Y坐标
	//! \param x3 弓形起始射线点 
	//! \param y3 弓形结束射线点
	//! \return 返回绘图是否成功
	UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
//! \brief    画弓形
	//! \param pntStart 弓形起始射线点 
	//! \param pntEnd 弓形结束射线点
	//! \return 返回绘图是否成功
	UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief    画扇形
	//! \param x1 绘制的矩形的左上角的X坐标 
    //! \param y1 绘制的矩形的左上角的Y坐标 
	//! \param x2 绘制的矩形的右下角的X坐标
	//! \param y2 绘制的矩形的右下角的Y坐标
	//! \param x3 扇形起始点 
	//! \param y3 扇形结束点
	//! \return 返回绘图是否成功
	UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4);
  //! \brief    画扇形
	//! \param pntStart 扇形起始射线点 
	//! \param pntEnd 扇形结束射线点
	//! \return 返回绘图是否成功
	UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd);
	//! \brief 画圆角矩形
	//! \param x1 绘制的矩形的左上角的X坐标 
    //! \param y1 绘制的矩形的左上角的Y坐标 
	//! \param x2 绘制的矩形的右下角的X坐标
	//! \param y2 绘制的矩形的右下角的Y坐标
	//! \param x3 圆角矩形X轴宽度
	//! \param y3 圆角矩形Y轴宽度
	//! \return 返回绘图是否成功
	UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	//! \brief    画圆角矩形
	//! \param rect 绘制的矩形 
	//! \param point 圆角矩形XY轴宽度
	//! \return 返回绘图是否成功
	UGbool RoundRect(const UGRect& rect, UGPoint point); 
	//! \brief 画一个文本对象
	//! \param UGPoint 文本基点
	//! \param str 文本
	//! \param style 文本风格
	//! \param bThemeStyle 是否是标签样式
	//! \param bSingleTextStyle 是否和当前图层是同一个文本形式
	//! \return 绘制是否成功
	UGbool Text(const UGPoint &pnt, const UGString &str, const UGTextStyle &style, UGbool bThemeStyle = FALSE,UGbool bSingleTextStyle = true);
	//! \brief 获取文本风格
	//! \return 文本风格 
	UGTextStyle GetTextStyle() const;
    //! \brief 几何对象风格
	//! \return 几何对象风格 
	UGStyle GetStyle() const;
	//! \brief 设置当前显示对象
	//! \param style 设置几何类对象风格
	//! \param nDimesion 集合对象的维数
	//! \return 当前的显示尺寸
	UGbool Prepare(const UGStyle& style, const UGint nDimesion);
	//! \brief 设置当前显示对象
	//! \param style 设置几何类对象风格
	//! \param nDimesion 集合对象的维数
	//! \设置是否成功 当前的显示尺寸
	UGbool Prepare(const UGTextStyle& style, UGbool bThemeStyle = FALSE);
	//! \brief 释放当前对象
	void Release();
	//! \brief 获取Graphics对象
	//! \return 返回Graphics对象
	UGGraphics* GetGraphics() const;
	//! \brief 设置Graphics对象
	//! \param pGraphics 要设置的Graphics对象 
	//! \return 返回旧的Graphics对象
	UGGraphics* SetGraphics(UGGraphics* pGraphics);
	//! \brief 计算开始绘制的时间
	//! \param pGraphics 使用的Graphics对象。
	void BeginCalculateTime(UGGraphics* pGraphics);
	//! \brief 计算结束绘制的时间
	void EndCalculateTime();
	//! \brief 判断是否开始绘制
	//! \return 是否开始绘制
	UGbool IsBeginCalculateTime();
	//! \brief 刷新图层
	void OvertimeRefresh();
	//! \brief  显示中断和显示刷新消息
	UGbool DrawCallBack();
	//! \brief 在Graphics图层绘制对象
	//! \param  Graphics图层绘制对象
	void OnPaint(UGGraphics* pGraphics);
	//! \brief 设置扩展对象绘制函数
	//! \param pDrawCustomGeometryFunc 设置扩展对象的函数指针
	//! \param pWnd 函数指针的Hand 
	void SetDrawCallBackFunc(DRAWCALLBACKPROC pDrawCallBackFunc, UGlong pWnd);
    //! \brief 设置扩展对象绘制函数
	//! \param pDrawCustomGeometryFunc 设置扩展对象的函数指针
	//! \param pWnd 函数指针的Hand 
	void SetDrawPaintFunc(DRAWPAINTPROC pDrawPaintFunc, UGlong pPaintWnd);
	//added by xielin 2007-04-30 
    //! \brief 设置扩展对象绘制函数
	//! \param pDrawCustomGeometryFunc 设置扩展对象的函数指针
	//! \param pWnd 函数指针的Hand 
	void SetDrawCustomGeometryFunc(DRAWCUSTOMGEOMETRYCALLBACKPROC pDrawCustomGeometryFunc,
		UGlong pWnd);
		
	// 过滤文本使用  //modified by dongfei 2007-04-11 添加两个参数 一个传缓冲距离，一个传是否强行加入此文本范围
	//! \brief 判断是否压盖图层文本对象
	//! \param pText 要判断的文本的对象
	//! \param bThemeStyle 是否为标签专题图
	//! \param szBuffer 缓冲距离 
	//! \param bSingleTextStyle 是否和当前是一样的文本样式 
	//! \param bSelfOverlap 是否自压盖 
	//! \param bOverlapBounds 是否与图层边界相交 
	//! \return 是否压盖文本对象 

	UGbool	IsOverlapText(UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0), 
		UGbool bSingleTextStyle = true, UGbool bSelfOverlap = false,UGbool bOverlapBounds = false);
    //! \brief 判断是否压盖图层文本对象
	//! \param UGGeoCompound 要判断的符合对象
	//! \param bThemeStyle 是否为标签专题图
	//! \param bOverlapBounds 是否与图层边界相交 
	//! \return 是否压盖文本对象 

	UGbool	IsOverlapText(UGGeoCompound* pGeoCompound, UGbool bThemeStyle = false,UGbool bOverlapBounds = false);
    //! \brief 判断矩形对象是否压盖图层文本对象
	//! \param pRect 要判断的矩形对象
	//! \param szBuffer 缓冲区距离
	//! \return 是否压盖文本对象 
	UGbool	IsOverlapText(UGRect* pRect,UGSize szBuffer = UGSize(-1,-1));
	//! \brief 添加一个文本对象的四个边角到绘制到屏幕的文本数组m_arrTextVertexs中
	//! \param pText 要添加的文本对象
    //! \param bThemeStyle 是否为标签专题图
	//! \param szBuffer 缓冲区距离
	void	AddTextVertexs(UGGeoText* pText, UGbool bThemeStyle = false,UGSize2D szBuffer = UGSize2D(-1.0,-1.0));
	//本来想把IsOverlapText和AddTextVertexs函数中求子文本的四个边角抽象出来 发现还是有些麻烦 稍后再做
	//UGbool  GetSubTextVertexs(UGSubText* pSubText,const UGPoint2D& pntAnchor, UGArray<UGPoint>& pnts);
	//! \brief 移除屏幕的文本数组的内容
	void	RemoveAllTextVertexs();
	//! \brief 分割复合对象
	//! \param  pGeoCompound 要分割的复合对象
	//! \param  arrGeometry  分割后的数组 
	//! \return 分割是否成功
	static UGbool SplitGeoCompound(UGGeoCompound *pGeoCompound, UGArray<UGGeometry*>& arrGeometry);
	//! \brief 判断某点是否在文本对象中
	//! \param pGeoText 文本对象
	//! \param pntHitTest 要判断的点
	//! \return 是否在文本对象中
	static UGbool HitTestGeoText(UGGeoText* pGeoText, const UGPoint2D& pntHitTest, UGDrawParamaters *pDrawParam);
	//! \brief 判断某点是否在几何点中
	//! \param pGeoText 几何点
	//! \param style 几何对象风格
	//! \param pntHitTest 要判断的点
	//! \return 是否在几何点
	static UGbool HitTestGeoPoint(UGGeoPoint* pGeoPoint, const UGStyle& style, const UGPoint2D& pntHitTest, UGdouble dTolerance, UGDrawing *pDrawing);
	//! \brief 获得的文本对象大小
	//! \param pGraphics 绘制的Graphics对象
	//! \param strText 文本对象
	//! \return 文本对象的大小
	static UGSize GetTextSize(UGGraphics *pGraphics, const UGString &strText);
	//! \brief 获得每行的文本对象
	//! \param strText 判断的文本
	//! \param strRows 分割后的文本
	//! \return 文本的大小，UGSize.cx 所有行的最多文本数 UGSize.cy 文本行数
	static UGSize GetRowStrings(const UGString &strText, UGArray<UGString> &strRows);
	//! \brief 计算文本的逻辑边界
	//! \param pGraphics 绘制的Graphics对象
	//! \param pntAnchor 文本的基点
	//! \param strText  计算的文本
	//! \param btAlign 文本的对齐方式
	//! \return 文本的逻辑边界
	static UGRect CalcTextLogBounds(UGGraphics *pGraphics, const UGPoint& pntAnchor, const UGString& strText, UGbyte btAlign);
	//! \brief 获得文本的行数
	//! \param strText 文本对象
	//! \return 文本行数
	static UGint CalcTextRowCount(const UGString &strText);

protected:
	UGbool DrawDataset(UGDatasetVector* pDatasetV,UGProgress* pProgress = NULL);
	UGbool DrawDataset(UGDatasetRaster* pDatasetR, UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	UGbool DrawGeometry(UGGeoPoint* pGeo);
	UGbool DrawGeometry(UGGeoLine* pGeo);
	UGbool DrawGeometry(UGGeoRegion* pGeo);
	UGbool DrawGeometry(UGGeoText* pGeo, UGbool bThemeStyle = false, UGbool bSingleTextStyle = true);	
	UGbool DrawGeometry(UGGeoArc* pGeo);
	UGbool DrawGeometry(UGGeoBSpline* pGeo);
	UGbool DrawGeometry(UGGeoCardinal* pGeo);
	UGbool DrawGeometry(UGGeoCurve* pGeo);
	UGbool DrawGeometry(UGGeoCircle* pGeo);
	UGbool DrawGeometry(UGGeoCompound* pGeo);
	//UGbool DrawGeometry(UGGeoDonut* pGeo);	
	UGbool DrawGeometry(UGGeoEllipse* pGeo);
	UGbool DrawGeometry(UGGeoEllipticArc* pGeo);
	UGbool DrawGeometry(UGGeoLineM* pGeo);	
	UGbool DrawGeometry(UGGeoLwpline* pGeo);
	UGbool DrawGeometry(UGGeoMultiPoint* pGeo);	
	UGbool DrawGeometry(UGGeoPath* pGeo);
	UGbool DrawGeometry(UGGeoPie* pGeo);
	UGbool DrawGeometry(UGGeoRect* pGeo);
	UGbool DrawGeometry(UGGeoRectRound* pGeo);
	UGbool DrawGeometry(UGGeoEquilateral* pGeo);
	UGbool DrawGeometry(UGTINBlock* pGeo);

	UGbool GetArcPoints(UGRect &rect, UGdouble dAngleStart, UGdouble dAngleEnd, 
		UGArray<UGPoint> &arr);

	///////////////////////////////////////////////////////
	// 这一组成员是绘制栅格数据集时需要的
	UGbool PaintRaster(UGint nTransparentRate = 0,UGProgress* pProgress = NULL);
	void PaintImgBegin();
	UGbool PaintImgBlock(UGImgBlock* pIBlock, UGint nTransparentRate);
	UGColor ImageIndexToColor(UGint nColor);
	///////////////////////////////////////////////////////

	// 为了过滤文本使用
	UGbool IsOverlapRects(const UGPoint* pPntObliqueRect, const UGRect& rect)const;
	UGint IsPointInRect(const UGPoint& Pnt, const UGRect& rect)const;
	UGint IsPointInObliqueRect(const UGPoint& pnt, const UGPoint* pPntObliqueRect)const;

	//! \brief 获取文本左上角坐标 added by dongfei 2007-03-21
	UGbool GetTextLeftTop(UGPoint & pntAnchor1, const UGString & strText, const UGTextStyle & style);
	
public:
	UGDrawParamaters m_DrawParam;
	UGDrawCache m_DrawCache;
	UGDrawMaker m_DrawMaker;

protected:
	DRAWCALLBACKPROC m_pDrawCallBackFunc;
	UGlong m_pWnd;
	DRAWPAINTPROC m_pDrawPaintFunc;
public:
	UGlong m_pPaintWnd;
protected:
	//added by xielin 2007-04-30扩展对象绘制回调函数
	DRAWCUSTOMGEOMETRYCALLBACKPROC m_pDrawCustomGeometryFunc;
	UGlong m_pDrawCustomGeometryWnd;

protected:
	UGStyle m_Style;
	UGTextStyle m_TextStyle;
	UGGraphics* m_pGraphics;

	UGGraphics* m_pRefreshGraphics;
	UGbool m_bBeginCalculateTime;
	UGbool m_bBeginDrawImg;
	clock_t m_clockBegin;
	UGint m_nCalculateNum;

	///////////////////////////////////////////////////////
	//这一组成员是绘制栅格数据集时需要的
	UGRect m_rcImgPaint;
	UGSize2D m_szImgViewOffset;
	UGSize2D m_szImgViewRatio;
	UGImage::UGImageData m_ImgInfo;

	UGDatasetRaster *m_pDTRaster;
	UGImgBlock *m_pDemBlock;
	///////////////////////////////////////////////////////
	//显示在屏幕上的文字的屏幕顶点座标
	UGArray<UGPoint> m_arrTextVertexs;	

public:

#if PACKAGE_TYPE==PACKAGE_UGC
	//!专题图显示模式
	//0, theme none; 1, theme unique; 2, theme range;
	UGint m_nDrawMode;
	
	//!分段专题图的KEYS
	UGArray <UGdouble> *m_pAryDoubleKeys;
	
	//!单值专题图的KEYS,也用ugdouble来存储吧。
	UGArray <UGdouble> *m_pAryIntKeys;
	
	//!专题图风格
	UGColorset *m_pStyles;
	
	//!专题图默认风格
	UGColor m_DefaultStyle;
#endif // end declare ugc sdk

	//由于需要多线程出图，栅格数据集的部分变量信息保存到Drawing类中
	UGColor m_NoDataStyle;
	UGColor m_BackColor;
	UGbyte m_btBackColorTolerance;
	UGchar m_btBrightness;
	UGchar m_btContrast;
	UGColorTable m_ColorsetTable;

	UGColorTable* GetColorsetTable();

};

}

#endif // !defined(AFX_UGDRAWING_H__AAC47E2E_B5B6_476C_9462_FBF34F02DFF5__INCLUDED_)

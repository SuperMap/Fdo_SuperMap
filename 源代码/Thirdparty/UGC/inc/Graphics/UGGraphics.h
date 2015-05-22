
/*!
   **************************************************************************************
    \file     UGGraphics.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    图形显示基类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGGRAPHICS_H
#define UGGRAPHICS_H

#include "UGImage.h"
#include "UGRgn.h"
#include "UGBrush.h"
#include "UGFont.h"
#include "UGPen.h"

namespace UGC
{

//! \brief 虚拟显示对象
class GRAPHICS_API UGGraphics 
{
public:	
	struct UGGraphicsData
	{
		UGuint nWidth;       //! \brief Graphics的宽
		UGuint nHeight;      //! \brief Graphics的高
		UGbyte btBitsPixel;  //! \brief 每个象素的bit数，比如32，24
		UGint nType;	     //! \brief 显示引擎类型 0:CDC, 1:hDC, 2:hPixmap, 3:hXWindow, 4:UGImage 5:PostScript
		void *pNative;       //! \brief 指向设备上下文的指针
		void *pReverse;      //! \brief 内存数组，通常用来储存颜色值
		UGGraphicsData()
		{
			nWidth = 1;
			nHeight = 1;
			btBitsPixel = 1;
			nType = 0;
			pNative = NULL;
			pReverse = NULL;
		}
	};
	
	//! \brief 显示引擎类型
	enum GraphicsType
	{
		GT_Windows = 1,    //! \brief windows类型 
		GT_Unix = 2,       //! \brief Linux\Unix类型
		GT_Universal = 3,  //! \brief 跨平台通用类型
		GT_PostScript = 4  //! \brief 打印类型
	};

	//! \brief 显示引擎数据类型
	enum GraphicsDataType
	{
		GDT_WCDC = 0,       //! \brief windows cdc 类型
		GDT_WhDC = 1,       //! \brief windows hdc 类型
		GDT_XhPixmap = 2,   //! \brief linux  pixmap 类型
		GDT_XhWindow = 3,   //! \brief linux xwindow 类型
		GDT_UImage = 4,     //! \brief UGImage 类型
		GDT_PostScript = 5  //! \brief PostScript 类型
	};

	//! \brief 背景模式，同Windows上的BackMode
	enum BackMode
	{
		BackOpaque = 2,			//! \brief 不透明
		BackTransparent = 1		//! \brief 透明
	};	
	
	//! \brief 文本对齐方式
	enum TextAlign
	{ 
		TopLeft = 0,			//! \brief 左上角对齐
		TopCenter = 1,			//! \brief 上面居中对齐
		TopRight = 2,			//! \brief 右上角对齐
		BaselineLeft = 3,		//! \brief 基准线左对齐
		BaselineCenter = 4,		//! \brief 基准线居中对齐
		BaselineRight = 5,		//! \brief 基准线右对齐
		BottomLeft = 6,			//! \brief 左下角对齐
		BottomCenter = 7,		//! \brief 底线居中对齐
		BottomRight = 8	,		//! \brief 右下角对齐
		CenterLeft = 9,			//! \brief 左中对齐
		Center = 10,			//! \brief 中心对齐
		CenterRight = 11		//! \brief 右中对齐
	};	

	//! \brief 映射模式
	enum MapMode
	{
		Text = 0,				//! \brief pixel	
		Lometric = 10,			//! \brief 0.1mm
		IsoTropicLometric = 11,	//! \brief 0.1mm, x比例和y比例一样
		Himetric = 100,			//! \brief 0.01mm		
		IsoTropicHimetric = 101,//! \brief 0.01mm, x比例和y比例一样
		PostScript  = 102		//! \brief Postscript
	};
    //! \brief 画刷模式 
	enum BrushOrgMode
	{
		Absolute = 0,			// 所给坐标与前面操作无关
		Relative = 1			// 所给坐标与前面操作相关
	};
    //! \brief 画图前景模式
	enum DrawMode
	{
		DM_BLACK =			1,   //! \brief  0       
		DM_NOTMERGEPEN =    2,   //! \brief DPon  
		DM_MASKNOTPEN =     3,   //! \brief DPna     
		DM_NOTCOPYPEN =     4,   //! \brief PN       
		DM_MASKPENNOT =     5,   //! \brief PDna     
		DM_NOT =            6,   //! \brief Dn       
		DM_XORPEN =         7,   //! \brief DPx      
		DM_NOTMASKPEN =     8,   //! \brief DPan     
		DM_MASKPEN =        9,   //! \brief DPa      
		DM_NOTXORPEN =      10,  //! \brief DPxn     
		DM_NOP =            11,  //! \brief D        
		DM_MERGENOTPEN =    12,  //! \brief DPno     
		DM_COPYPEN =        13,  //! \brief P        
		DM_MERGEPENNOT =    14,  //! \brief PDno     
		DM_MERGEPEN =       15,  //! \brief DPo      
		DM_WHITE =          16	 //! \brief  1       
	};

	//! \brief 绘制位图方式
	enum ImageRop
	{
		IMAGE_SRCAND = 0x008800C6,   //! \brief boolean and
		IMAGE_SRCCOPY = 0x00CC0020,  //! \brief copy
		IMAGE_SRCINVERT = 0x00660046,//! \brief boolean xor
		IMAGE_SRCPAINT = 0x00EE0086  //! \brief boolean or
	};

protected:
	// 
	UGGraphics();
public:
	// destructor
	virtual ~UGGraphics();
	//! \brief 创建一个 pGraphics对象
	//! \param pGraphics 引用的pGraphics对象
	//! \return 返回创建是否成功 
	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics) = 0;
	//! \brief 删除当前对象
	//! \return 删除是否成功
	virtual UGbool DeleteGraphics() = 0;
	//! \brief 获取当前图片
	//! \return 返回当前图片
	virtual UGImage* GetCurrentImage() const;
	//! \brief 获取当前字体
	//! \return 返回当前字体
	virtual UGFont* GetCurrentFont() const;
	//! \brief 获取当前画刷
	//! \return 返回当前画刷
	virtual UGBrush* GetCurrentBrush() const;
	//! \brief 获取当前画笔
	//! \return 返回当前画笔
	virtual UGPen* GetCurrentPen() const;
    //! \breif 判断当前是否要打印到文件中
	//! \reutrn 返回当前是否可以打印到文件中
	virtual UGbool IsPrintToFile() const;
	//! \brief 设置是否打印到文件当中
	//! \param UGbool 是否打印到文件中
	virtual void SetPrintToFile(UGbool bPrintToFile = TRUE);
    //! \breif 判断当前是否在打印
	//! \reutrn 返回当前是否在打印
	virtual UGbool IsPrinting() const = 0;
	//! \breif 获取填充原点的模式
	//! \reutrn 返回当前的填充原点模式
	virtual UGint GetBrushOrgMode() const;
	//! \brief 设置填充原点模式
	//! \param nBrushOrgMode 要设置的原点填充模式
	//! \return 原来的原点填充模式 
	virtual UGint SetBrushOrgMode(UGint nBrushOrgMode);
	//! \brief 获取填充原点
	//! \return 返回填充原点
	virtual UGPoint GetBrushOrg() const;
	//! \brief 设置填充原点
	//! \param point 要设置的填充原点
	//! \return 返回原来的填充原点
	virtual UGPoint SetBrushOrg(const UGPoint& point);
	//! \brief 选择当前图片
	//! \param pPen 要选择的图片
	//! \return 返回原来的图片
	virtual UGImage* SelectImage(UGImage *pImage) = 0;
	//! \brief 选择当前字体
	//! \param pPen 要选择的字体
	//! \return 返回原来的字体
	virtual UGFont* SelectFont(UGFont *pFont) = 0;
	//! \brief 选择当前画刷
	//! \param pPen 要选择的画刷
	//! \return 返回原来的画刷
	virtual UGBrush* SelectBrush(UGBrush *pBrush) = 0;
	//! \brief 选择当前画笔
	//! \param pPen 要选择的画笔
	//! \return 返回原来的画笔
	virtual UGPen* SelectPen(UGPen *pPen) = 0;
	
	//! \brief 获取前景颜色
	//! \return 返回前景颜色
	virtual UGColor GetForeColor() const = 0;
	//! \brief 设置前景颜色
	//! \param color 要设置的前景颜色
	//! \return 返回原来的前景颜色
	virtual UGColor SetForeColor(UGColor color) = 0;	
	//! \brief 获取背景颜色
	//! \return 返回背景颜色
	virtual UGColor GetBackColor() const = 0;
	//! \brief 设置背景颜色
	//! \param color 要设置的背景颜色
	//! \return 返回原来的背景颜色
	virtual UGColor SetBackColor(UGColor color) = 0;

	//! \brief 获取背景模式
	//! \return 返回背景模式
	virtual UGint GetBackMode() const = 0;
	//! \breif 设置背景模式
	//! \param nBKMode 要设置的背景模式
	//! \return 返回原来的背景模式
	virtual UGint SetBackMode(UGint nBKMode) = 0;
    //! \brief 设置前景模式
	//! \param nDrawMode 要设置的模式
	//! \return 返回原来的前景模式
	virtual UGint SetROP2(UGint nDrawMode) = 0;
	//! \brief 获取前景模式
	//! \return 返回前景模式
	virtual UGint GetROP2() = 0;	
     
	//! \brief 获取映射模式
	//! \return 返回映射模式
	virtual UGint GetMapMode() const = 0;
	//! \brief 设置映射模式
	//! \param nMapMode 要设置的映射模式
	//! \return UGint 返回原来的映射模式
	virtual UGint SetMapMode(UGint nMapMode) = 0;
	//! \brief 获取窗口的原点坐标
	//! \return 返回原始的原点坐标
	virtual UGPoint GetWindowOrg() const;
	//! \brief 设置窗口的原点坐标
	//! \param point 要设置的坐标,
	//! \return 返回原始的原点坐标
	virtual UGPoint SetWindowOrg(const UGPoint& point);
	//! \brief 设置窗口的原点坐标
	//! \param x 要设置的x坐标,
	//! \param y 要设置的y坐标
	//! \return 返回原始的原点坐标
	virtual UGPoint SetWindowOrg(UGint x, UGint y);
	//! \brief 实际坐标转换到逻辑坐标
	//! \param pPoints 要转换的坐标列指针,返回转换后的逻辑坐标
	//! \param nCount 坐标个数
	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1) = 0;
	//! \brief 实际坐标转换到逻辑坐标
	//! \param rect 要转换的矩形,返回转换后的逻辑坐标的矩形
	virtual void DPtoLP(UGRect& rect) = 0;
	//! \brief 实际坐标转换到逻辑坐标
	//! \param size 要转换的实际坐标,返回转换后的逻辑坐标
	virtual void DPtoLP(UGSize& size) = 0;
	//! \brief 逻辑坐标转换到实际坐标
	//! \param pPoints 要转换的坐标列指针,返回转换后的实际坐标
	//! \param nCount 坐标个数
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1) = 0;
	//! \brief 逻辑坐标转换到实际坐标
	//! \param rect 要转换的矩形,返回转换后的实际坐标的矩形
	virtual void LPtoDP(UGRect& rect) = 0;
	//! \brief 逻辑坐标转换到实际坐标
	//! \param size 要转换的逻辑坐标,返回转换后的逻辑坐标
	virtual void LPtoDP(UGSize& size) = 0;
    //! \brief 逻辑坐标转换到mm
	//! \param size 要转换的实际坐标,返回转换后的mm
	virtual void LPtoHIMETRIC(UGSize& size) = 0;
	//! \brief 实际坐标转换到mm
	//! \param size 要转换的实际坐标,返回转换后的mm
	virtual void DPtoHIMETRIC(UGSize& size) = 0;
	//! \brief mm转换到逻辑坐标
	//! \param size 要转换的mm,返回转换后的坐标
	virtual void HIMETRICtoLP(UGSize& size) = 0;
	//! \brief mm转换到实际坐标
	//! \param size 要转换的mm,返回转换后的坐标
	virtual void HIMETRICtoDP(UGSize& size) = 0;
    //! \brief 选择区域为Graphics当前区域
	//! \param pRgn 要选择的区域
	//! \param nMode 操作类型, 如与操作,或操作
	//! \return 返回上一个区域
	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode) = 0;
    //! \brief 获取当前画笔的坐标
	//! \return 返回当前画笔的坐标
	virtual UGPoint GetCurrentPosition() const = 0;

	//! \brief 获取像素值
    //! \param x 像素的X坐标
	//! \param y 像素的Y坐标
	//! \return 返回像素的颜色
	virtual UGColor GetPixel(UGint x,UGint y) = 0;
	//! \brief 设置像素值
    //! \param x 像素的X坐标
	//! \param y 像素的Y坐标
	//! \param color 设定像素的颜色
	//! \return 返回原始颜色
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color) = 0;
	//! \brief 将画笔移动到指定坐标
    //! \param x 指定的X坐标
	//! \param y 指定的Y坐标
	//! \return 返回原始坐标 
	virtual UGPoint MoveTo(UGint x,UGint y) = 0;
	//! \brief 画一条直线
    //! \param x 直线的终点X坐标
	//! \param y 直线的终点Y坐标
	//! \return 如果成功返回TRUE,失败返回FALSE 
	virtual UGbool LineTo(UGint x,UGint y) = 0;
	//! \brief 将画笔移动到指定坐标
    //! \param point 指定的坐标
	//! \return 返回原始坐标
	virtual UGPoint MoveTo(UGPoint point) = 0;
	//! \brief 画一条直线
    //! \param point 直线的终点坐标
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool LineTo(UGPoint point) = 0;
    //! \brief 画一条直线
    //! \param x1 直线的起始点的x坐标
	//! \param y1 直线的起始点的y坐标
	//! \param x2 直线的终点的x坐标
	//! \param y2 直线的终点的y坐标
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2) = 0;
	//! \brief 画一条直线
    //! \param point1 直线的起始点
	//! \param point2 直线的终点
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool Line(UGPoint point1, UGPoint point2) = 0;
    //! \brief 画一条折线
    //! \param pPoints 折线的点列指针
	//! \param nCount 有多少个点
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief 画多个折线
    //! \param pPoints 多条折线的点列指针
	//! \param pPntCount 每个折线的点数
	//! \param nCount 折线的个数
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) = 0;
    //! \brief 画一个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param nCount 有多少个点
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount) = 0;
	//! \brief 画多个多边形区域
    //! \param pPoints 多边形的点列指针
	//! \param pPntCount 每个多边形的点数
	//! \param nCount 多边形的个数
	//! \return 如果成功返回TRUE,失败返回FALSE
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) = 0;

	//! \brief 画矩形
	//! \param x1 矩形的左上角的X坐标 
    //! \param y1 矩形的左上角的Y坐标 
	//! \param x2 矩形的右下角的X坐标
	//! \param y2 矩形的右下角的Y坐标
	//! \return 返回绘图是否成功
	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief 画矩形
	//! \param rect 需要绘制的矩形 
	//! \return 返回绘图是否成功
	virtual UGbool Rectangle(const UGRect& rect) = 0;

	//! \brief 画椭圆
	//! \param x1 倚赖的矩形的左上角的X坐标 
    //! \param y1 倚赖的矩形的左上角的Y坐标 
	//! \param x2 倚赖的矩形的右下角的X坐标
	//! \param y2 倚赖的矩形的右下角的Y坐标
	//! \return 返回绘图是否成功
	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2) = 0;
	//! \brief 画椭圆
	//! \param rect 倚赖的矩形 
	//! \return 返回绘图是否成功
	virtual UGbool Ellipse(const UGRect& rect) = 0;

	//! \brief    画弧线
	//! \param x1 倚赖的矩形的左上角的X坐标 
    //! \param y1 倚赖的矩形的左上角的Y坐标 
	//! \param x2 倚赖的矩形的右下角的X坐标
	//! \param y2 倚赖的矩形的右下角的Y坐标
	//! \param x3 弧线起始射线点 
	//! \param y3 弧线结束射线点
	//! \return 返回绘图是否成功
	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
	//! \brief    画弧线
	//! \param pntStart 弧线起始射线点 
	//! \param pntEnd 弧线结束射线点
	//! \return 返回绘图是否成功
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 

	//! \brief    画弓形
	//! \param x1 倚赖的矩形的左上角的X坐标 
    //! \param y1 倚赖的矩形的左上角的Y坐标 
	//! \param x2 倚赖的矩形的右下角的X坐标
	//! \param y2 倚赖的矩形的右下角的Y坐标
	//! \param x3 弓形起始射线点 
	//! \param y3 弓形结束射线点
	//! \return 返回绘图是否成功
	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
	//! \brief    画弓形
	//! \param pntStart 弓形起始射线点 
	//! \param pntEnd 弓形结束射线点
	//! \return 返回绘图是否成功
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 
	//! \brief    画扇形
	//! \param x1 倚赖的矩形的左上角的X坐标 
    //! \param y1 倚赖的矩形的左上角的Y坐标 
	//! \param x2 倚赖的矩形的右下角的X坐标
	//! \param y2 倚赖的矩形的右下角的Y坐标
	//! \param x3 扇形起始点 
	//! \param y3 扇形结束点
	//! \return 返回绘图是否成功
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) = 0;
    //! \brief    画扇形
	//! \param pntStart 扇形起始射线点 
	//! \param pntEnd 扇形结束射线点
	//! \return 返回绘图是否成功
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) = 0; 
	
	//! \brief 画圆角矩形
	//! \param x1 倚赖的矩形的左上角的X坐标 
    //! \param y1 倚赖的矩形的左上角的Y坐标 
	//! \param x2 倚赖的矩形的右下角的X坐标
	//! \param y2 倚赖的矩形的右下角的Y坐标
	//! \param x3 圆角矩形X轴宽度
	//! \param y3 圆角矩形Y轴宽度
	//! \return 返回绘图是否成功
	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) = 0;
	//! \brief    画圆角矩形
	//! \param rect 倚赖的矩形 
	//! \param point 圆角矩形XY轴宽度
	//! \return 返回绘图是否成功
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point) = 0; 

	//! \brief 画图像
	//! \param x 目的Graphics的矩形的左上角的x坐标 
    //! \param y 目的Graphics的矩形的左上角的y坐标 
	//! \param nWidth  目的Graphics的矩形的宽度
	//! \param nHeight 目的Graphics的矩形的高度
	//! \param pMemGraphics 源Graphics
	//! \param xSrc 源Graphics的矩形的左上角的x坐标 
	//! \param ySrc 源Graphics的矩形的右上角的y坐标
	//! \param nDrawMode 绘制位图方式
	//! \return 返回绘制是否成功
	virtual UGbool DrawImage(UGint x, UGint y,
							UGint nWidth, UGint nHeight,  
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 							
							UGint nDrawMode) = 0;
	//! \brief 伸展图像
	//! \param x 目的Graphics的矩形的左上角的x坐标 
    //! \param y 目的Graphics的矩形的左上角的y坐标 
	//! \param nWidth  目的Graphics的矩形的宽度
	//! \param nHeight 目的Graphics的矩形的高度
	//! \param pMemGraphics 源Graphics
	//! \param xSrc 源Graphics的矩形的左上角的x坐标 
	//! \param ySrc 源Graphics的矩形的右上角的y坐标
	//! \param nSrcWidth 源Graphic的矩形的宽度
	//! \param nSrcHeight 源Graphic的矩形的高度
	//! \param nDrawMode 绘制位图方式
	//! \return 返回绘制是否成功
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGint nDrawMode) = 0;
	//! \brief 伸展图像
	//! \param x 目的Graphics的矩形的左上角的x坐标 
    //! \param y 目的Graphics的矩形的左上角的y坐标 
	//! \param nWidth  目的Graphics的矩形的宽度
	//! \param nHeight 目的Graphics的矩形的高度
	//! \param xSrc 源Graphics的矩形的左上角的x坐标 
	//! \param ySrc 源Graphics的矩形的右上角的y坐标
	//! \param nSrcWidth 源Graphic的矩形的宽度
	//! \param nSrcHeight 源Graphic的矩形的高度
	//! \param ImageData 源图像的数据
	//! \return 返回绘制是否成功
	virtual UGbool StretchImage(UGint x, UGint y, 
							UGint nWidth, UGint nHeight,
							UGint xSrc, UGint ySrc, 
							UGint nSrcWidth, UGint nSrcHeight, 
							UGImage::UGImageData& ImageData) = 0;
	//! \brief 画旋转图像
	//! \param x 目的Graphics的矩形的左上角的x坐标 
    //! \param y 目的Graphics的矩形的左上角的y坐标 
	//! \param nWidthRotate  目的Graphics的矩形的宽度
	//! \param nHeightRotate 目的Graphics的矩形的高度
	//! \param dAngle   旋转的角度
	//! \param pMemGraphics 源Graphics
	//! \param xSrc 源Graphics的矩形的左上角的x坐标 
	//! \param ySrc 源Graphics的矩形的右上角的y坐标
	//! \param nWidth 源Graphic的矩形的宽度
	//! \param nHeight 源Graphic的矩形的高度
	//! \param nDrawMode 绘制位图方式
	//! \return 返回绘制是否成功
	virtual UGbool RotateImage(UGint x, UGint y, 
							UGint nWidthRotate, UGint nHeightRotate,
							UGdouble dAngle,
							UGGraphics* pMemGraphics,
							UGint xSrc, UGint ySrc,
							UGint nWidth,UGint nHeight,
							UGint nDrawMode) = 0;

	//! \brief 书写字符串
	//! \param x 字符串的对齐位置的x坐标
	//! \param y 字符串的对齐位置的y坐标
	//! \param str 指向字符串的指针
	//! \param textStyle 文本的样式
	//! \return 返回书写是否成功
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle()) = 0;	
	//! \brief 书写字符串
	//! \param rect 文本的倚赖的矩形
	//! \param str 所需要书写的字符串
	//! \param nFormat
	//! \return 返回文本的高度
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat) = 0;
	
	//! \brief 获取文本对齐方式
    //! \return 文本对齐方式
	virtual UGint GetTextAlign() const  = 0;
	//! \brief 设置文本对齐方式
    //! \param nTextAlign 对齐方式
	virtual UGint SetTextAlign(UGint nTextAlign) = 0;
	//! \brief 获取文本字符串的所占大小
	//! \return返回所占大小
	virtual UGSize GetTextExtent(const UGString& str) = 0;
	
	//! \brief 获取实际对象
	//! \param data 保存实际对象
	virtual void GetGraphicsData(UGGraphicsData &data) const;
	//! \brief 设置实际对象
	//! \param data 实际对象数据
	virtual void SetGraphicsData(const UGGraphicsData &data);
    //! \brief  获取显示引擎类型
	//! \return 显示引擎类型
	virtual UGint GetGraphicsType();
	
	//将线和文本区反走样分开，和SFC保持一致
	//virtual UGbool IsSmoothingMode() const;
	//virtual void SetSmoothingMode(UGbool bSmoothingMode);
	//! \brief 是否光滑模式
	//! \return 光滑模式
	virtual UGbool IsLineSmoothingMode() const;
	//! \brief 设置光滑模式
	//! \param bSmoothingMode 光滑模式
	virtual void SetLineSmoothingMode(UGbool bSmoothingMode);
	//! \brief 是否光滑模式
	//! \return 光滑模式
	virtual UGbool IsTextSmoothingMode() const;
	//! \brief 设置光滑模式
	//! \param bSmoothingMode 光滑模式
	virtual void SetTextSmoothingMode(UGbool bSmoothingMode);
	//! \biref用于psgraphics显示引擎
	virtual void SetCoordRatio(UGfloat dRatioX,UGfloat dRatioY);
	virtual void GetCoordRatio(UGfloat& dRatioX,UGfloat& dRatioY);
	//! \brief 获取基线离锚点（左上角）的距离
	//! \return 基线离锚点（左上角）的距离
	virtual UGint GetBaselinetoAnchor();
	//! \brief 设置/返回文字是否转为矢量
	void SetTextConvertToVector(UGbool bTextConvertToVector);
	UGbool IsTextConvertToVector();
	//! \brief 矩形裁剪 for PSGraphics
	virtual UGbool RectClip(UGdouble left, UGdouble top, UGdouble right, UGdouble bottom);
	virtual UGbool RectClip(const UGRect& rect);
protected:		
	UGPoint m_pntCurPos;
	UGint m_nMapMode;
	UGPoint m_pntWindowOrg;
	UGint m_nBrushOrgMode;
	UGPoint m_pntBrushOrg;	
	UGbool m_bPrintToFile;

	UGImage* m_pImage;
	UGFont* m_pFont;
	UGBrush* m_pBrush;
	UGPen* m_pPen;
	UGRgn* m_pRgn;
	UGGraphicsData m_Data;	// 个引擎的实际设备

	UGint m_nGraphicsType;
	UGbool m_bLineSmoothingMode;
	UGbool m_bTextSmoothingMode;

		// 象素/逻辑单位。
	double m_dCoorRatioX;
	double m_dCoorRatioY;
	UGbool m_bTextToVector;	//文字是否转为矢量
	virtual UGint GetTextPath(const UGString& strText, const UGint x, const UGint y, UGFont* pFont, 
						   UGArray<UGPoint>* pPointArray, UGArray<UGbyte>* pTypes); 
	friend class UGPSGraphics;
};

}

#endif

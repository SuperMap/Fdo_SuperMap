// UGXGraphics.h: interface for the UGXGraphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_)
#define AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_

#include "Graphics/UGGraphics.h"
#include "XGraphics/UGXPen.h"
#include "XGraphics/UGXBrush.h"
#include "XGraphics/UGXRgn.h"
#include "XGraphics/UGXFont.h"
#include "Base/UGArray.h"
#include <X11/Xlib.h>	// for XPoint
#include "XGraphics/UGFreeTypeLib.h"
  
#include   <libart_lgpl/art_misc.h>
#include   <libart_lgpl/art_svp.h>
#include   <libart_lgpl/art_vpath.h>
#include   <libart_lgpl/art_svp_vpath.h>
#include   <libart_lgpl/art_gray_svp.h>
#include   <libart_lgpl/art_svp_vpath_stroke.h>

namespace UGC
{
typedef UGArray<XPoint> arrayPoints;
class XGRAPHICS_API UGXGraphics : public UGGraphics  
{
	friend void UGXFont::Draw_Bitmap(UGXGraphics&,void*,UGint,UGint);
	friend void UGXFont::DrawString(UGXGraphics&,UGint,UGint,const UGString&,UGint,UGint);
	friend class UGXFont;

	//added by xielin 2007-08-16 为XFont优化，因为X11下绘制文本是配合Freetype来做的
	//为了尽可能少从Freetype读取字形和把字形转换成，需要把gettextextend和drawstring
	//优化，方法就是换成下上次的字符串和字符串的一些属性，包括字体，高度，宽度，旋转角度
	//每次绘制或者需要和freetype打交道的时候，判断一下上次是否缓存，如果有缓存，那么
	//判断是否是同样的字符串，同样的高度、宽度等，如果是，那么直接用缓存中的内容，节省效率
	struct UGCacheFontInfo
	{		
		UGint nHeight;
		UGint nWidth;
		UGint nAngle;
		UGString strFontName;  //字体名称
		UGString strText;	//文本内容
		FT_Vector fvMax;   //字符串最大坐标值（设备坐标）
		FT_Vector fvMin;	//字符串最小坐标值(设备坐标)
		UGArray<FT_Glyph> glyphs;  //保存drawstring过程中的glyph
		UGArray<FT_Vector> glyphsPos; //保存drawstring过程中glyph位置
		UGint nMaxDxS;	//计算@字体的变量，缓存起来
		UGint nMinDy;	//计算@字体的变量，缓存起来
		UGint nMaxDxE; //计算@字体的变量，缓存起来
		UGCacheFontInfo()
		{					
			nHeight = 0;
			nWidth = 0;
			nAngle = 0;
			strFontName = "";
			strText = "";
			fvMax.x = 0;
			fvMax.y = 0;
			fvMin.x = 0;
			fvMin.y = 0;
			nMaxDxS = 0;
			nMinDy = 0;
			nMaxDxE = 0;
		}
	};

	//added by xielin 2007-08-22 记录走样点的一个结构，包括xy坐标，还有一个灰度值（0～255之间）
	struct UGAntiPoint
	{
		UGint nX;
		UGint nY;
		UGuchar charColor;
		UGAntiPoint()
		{
			nX = 0;
			nY = 0;
			charColor = 0;
		}
	};

public:
	
	UGXGraphics();
	virtual ~UGXGraphics();

	virtual UGbool CreateCompatibleGraphics(UGGraphics* pGraphics) ;
	virtual UGbool DeleteGraphics() ;

	virtual UGbool IsPrinting() const ;
	
	virtual UGImage* SelectImage(UGImage *pImage) ;
	virtual UGFont* SelectFont(UGFont *pFont) ;
	virtual UGBrush* SelectBrush(UGBrush *pBrush) ;
	virtual UGPen* SelectPen(UGPen *pPen) ;
	
	virtual UGColor GetForeColor() const ;
	virtual UGColor SetForeColor(UGColor color) ;	
	
	virtual UGColor GetBackColor() const ;
	virtual UGColor SetBackColor(UGColor color) ;

	
	virtual UGint GetBackMode() const ;
	virtual UGint SetBackMode(UGint nBKMode) ;

	virtual UGint SetROP2(UGint nDrawMode) ;
	virtual UGint GetROP2() ;	

	virtual UGint GetMapMode() const ;
	virtual UGint SetMapMode(UGint nMapMode) ;

	virtual void DPtoLP(UGPoint* pPoints, UGint nCount = 1) ;
	virtual void DPtoLP(UGRect& rect) ;
	virtual void DPtoLP(UGSize& size) ;
	virtual void LPtoDP(UGPoint* pPoints, UGint nCount = 1) ;
	virtual void LPtoDP(UGRect& rect) ;
	virtual void LPtoDP(UGSize& size) ;
	
	virtual void LPtoHIMETRIC(UGSize& size) ;
	virtual void DPtoHIMETRIC(UGSize& size) ;
	virtual void HIMETRICtoLP(UGSize& size) ;
	virtual void HIMETRICtoDP(UGSize& size) ;

	virtual UGRgn* SelectClipRgn(UGRgn* pRgn, UGint nMode) ;

	virtual UGPoint GetCurrentPosition() const ;

	
	virtual UGColor GetPixel(UGint x,UGint y)  ;
	virtual UGColor SetPixel(UGint x,UGint y, UGColor color) ;

	virtual UGPoint MoveTo(UGint x,UGint y) ;
	virtual UGPoint MoveTo(UGPoint point) ;
	
	virtual UGbool LineTo(UGint x,UGint y) ;
	virtual UGbool LineTo(UGPoint point) ;
	
	virtual UGbool Line(UGint x1,UGint y1,UGint x2,UGint y2) ;
	virtual UGbool Line(UGPoint point1, UGPoint point2) ;
		
	virtual UGbool Polyline(const UGPoint* pPoints, UGint nCount) ;
	
	virtual UGbool PolyPolyline(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) ;

	virtual UGbool Polygon(const UGPoint* pPoints, UGint nCount) ;
	
	virtual UGbool PolyPolygon(const UGPoint* pPoints, const UGint* pPntCount, UGint nCount) ;

	virtual UGbool Rectangle(UGint x1, UGint y1, UGint x2, UGint y2) ;
	virtual UGbool Rectangle(const UGRect& rect) ;

	virtual UGbool Ellipse(UGint x1, UGint y1, UGint x2, UGint y2) ;
	virtual UGbool Ellipse(const UGRect& rect) ;

	virtual UGbool Arc(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Arc(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 

	virtual UGbool Chord(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Chord(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 
	
	virtual UGbool Pie(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3, UGint x4, UGint y4 ) ;
	virtual UGbool Pie(const UGRect& rect, UGPoint pntStart, UGPoint pntEnd) ; 

	virtual UGbool RoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3) ;
	virtual UGbool RoundRect(const UGRect& rect, UGPoint point) ; 

	virtual UGbool DrawImage(UGint x, UGint y,
		UGint nWidth, UGint nHeight,  
		UGGraphics* pMemGraphics,
		UGint xSrc, UGint ySrc, 
		UGint nDrawMode) ;

	virtual UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGGraphics* pMemGraphics,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGint nDrawMode) ;

	virtual UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGImage::UGImageData& ImageData) ;
	
	virtual UGbool _textOut(UGint x, UGint y, const UGString& str, UGint nPaintOption=0/*PaintOption::PaintAll*/) ;	
	virtual UGbool TextOut(UGint x, UGint y, const UGString& str, UGTextStyle textStyle = UGTextStyle()) ;	
	virtual UGint DrawText(const UGRect& rect, const UGString& str, UGint nFormat) ;
	
	virtual UGint GetTextAlign() const ;
	virtual UGint SetTextAlign(UGint nTextAlign) ;
	virtual UGSize GetTextExtent(const UGString& str) ;
	virtual void SetGraphicsData(const UGGraphicsData &data);

	//added by lugw 2007-04-07 添加或删除反走样的点的信息
	//! \brief  添加反走样点的位置
	/**
	\param nBuffer  该点在FT中的值（透明度）
	\param point    该点的位置
	*/
	void AddBuffer(UGint nBuffer,XPoint point);
	//deleted by xielin 2007-08-23 下面这个函数不需要了
	//void RemoveAllBuffer();

	//added by xielin 2007-04-20 从XImage的内存数组中获取指定位置的Color，主要用于反走样点绘制时候频繁读取底图颜色值操作
	//! \brief 从image的buffer数组中中获取color
	/**
	\param x  x坐标，逻辑单位
	\param y  y坐标，逻辑单位
	\remarks  x，y坐标对应的颜色值
	*/
	UGColor GetPixelFromBuffer(UGint x,UGint y) ;

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
	//! \brief 获取基线离锚点（左上角）的距离
	virtual UGint GetBaselinetoAnchor();
	
protected:
	inline UGint DPtoLP_X(UGint x);
	inline UGint DPtoLP_Y(UGint y);
	inline UGint LPtoDP_X(UGint x);
	inline UGint LPtoDP_Y(UGint y);

	
	void drawPoints(UGArray<XPoint> &points);
	//added by xielin 2007-08-15 为了提高效率，重写一个drawPoints函数，传入指针和个数
	void drawPoints(XPoint* pPoints,UGint nCount);
	void *calcMask(const UGPoint *pPoints, const UGint* pPntCount, UGint nCount);
	void create();
	//added by lugw 2007-04-07 处理反走样的RGB值
	//! \brief  添加反走样点的位置
	/**
	\param nForeColor  前景色，指绘制的线的颜色
	\param nBackFore   背景色，指底图的颜色
	\param nC   透明度
	\remarks 调整后的RGB值
	*/
	UGColor AntiForeColor(UGColor& nForeColor,UGColor nBackFore,UGdouble nC);

	//! \brief  预处理反走样线，主要实现传入绘制线的坐标点串，然后通过计算获取需要透明处理的点坐标和透明度
	/**
	\param pPoints  构成线的点串，设备坐标
	\param nCount   点串中点的数量
	\param nLineWidth   线的宽度
	\remarks 成功返回true，结果放到成员变量m_nAntiArray中
	*/
	virtual UGbool PrePareForPolyLineAnti(const XPoint* pPoints, UGint nCount,UGint nLineWidth);

	//! \brief  绘制反走样的透明点到指定位置，用于文本的反走样点绘制
	virtual void drawPointOfAnti();

	//! \brief  绘制反走样的透明点到指定位置，用于线（包括多边形的边线）的反走样点绘制
	virtual void drawLinePointOfAnti();

	//added by xielin 2007-04-20 用来判断是否需要平滑处理，然后绘制线的反走样点，传入的都是设备坐标
	//! \brief  绘制反走样的透明点到指定位置，用于线（包括多边形的边线）的反走样点绘制
	virtual void drawLinePointOfAnti(const XPoint* pPoints, UGint nCount,UGint nLineWidth = -1);
	//virtual void drawLinePointOfAnti(UGint x1,UGint y1,UGint x2,UGint y2);
	virtual void drawLinePointOfAnti(UGint x1,UGint y1,UGint x2,UGint y2,UGint nLineWidth = -1);
	//! \brief 清除字体缓存
	void ClearCacheFontInfo();

protected:
	UGbool m_bNeedRelease;
	UGbool m_bUpdate;
	UGint m_nBkMode;
	UGint m_nDrawMode;
	UGint m_nTextAlign;
	
	UGRgn *m_pRgn;
	
	// 象素/逻辑单位。
//	double m_dCoorRatioX; 移到Graphics中了
//	double m_dCoorRatioY;
	
	void *m_gc;
	//added by lugw 2007-04-07 存储反走样的点位置
	
	UGArray<arrayPoints> m_nAntiArray;

	//added by xielin 2007-04-19 通过x11取前景背景色有点慢，用成员变量保存下来提高速度 
	UGColor m_backcolor;
	UGColor m_forecolor; 
//added by xielin 2007-08-15 对XGraphics优化，用一个成员变量记录点串，不用每次new
protected:
	//! \brief LPtoDP转换XPoint指针
	void LPtoDP(XPoint* pPoints, UGint nCount = 1);
	//! \brief 预处理传入的点串，执行的操作有把点串放到成员点串中，lp坐标转换成dp坐标
	void PreProcessPoints(const UGPoint* pPoints, UGint nCount,UGint nXPointSize = 0);
	//! \brief UGPoint转换成XPoint
	static void ConvertUGPoint2POINT(const UGPoint* pPoints, XPoint* pXPoints, UGint nCount);	
	//! \brief XPoint转换成UGPoint
	static void ConvertPOINT2UGPoint(const XPoint* pXPoints, UGPoint* pPoints, UGint nCount);
	//! \brief 专门为X11优化的函数，因为X11不能直接绘制polypolygon，所以是多次绘制polygon，那么就调用这个优化的函数来绘制polygon
	//! \brief 和开放出去的polygon函数不一样的是，该函数传入的已经是设备坐标的XPoint了，内部不需要做任何处理，直接绘制既可，提高效率
	UGbool PolygonFromMemory(XPoint* pPoints, UGint nCount) ;

	XPoint* m_lpPoints;	
	UGint m_nPntCountMax;	

	//! \brief 为字体绘制做优化，保存每次绘制的从freetype中取出来的一些信息
	UGCacheFontInfo m_CacheFontInfo;

	void PreCachAntiPoints(UGint nCount);
	//! \brief 下面四个参数用来缓存线型反走样时候需要的内存数据
	art_u8 *m_pLineArtbuffer;
	UGint m_nLineArtBufferMaxCount;
	ArtVpath *m_pLineArtVpath;
	UGint m_nLineArtVpathMaxCount;

	//! \brief 记录反走样点的信息
	UGAntiPoint* m_pAntiPoints;
	UGint m_nAntiPointsCount;
	UGint m_nAntiPointsMaxCount;

	//设置graphics当前使用的内存Image是否需要更新（也就是从pixmap中同步数据）
	void SetImageNeedUpdate(UGbool bNeedUpdate=true);

	//added by xielin ^_^ 为StretchImage、RotateImage做优化，用成员变量保存变换过程中的数组，加快显示速度
	//这样会多占用一点内存，但是综合来看，应该是值得的。
	//! \brief 变换源图片的Colors数组
	UGColor *m_pSrcImageColors;
	//! \brief 源图片colors数组的最大大小
	UGint m_nMaxSrcImageColorsCount;
	//! \brief 变换目标图片的Colors数组
	UGColor *m_pDesImageColors;
	//! \brief 目标图片colors数组的最大大小
	UGint m_nMaxDesImageColorsCount;

	UGbool StretchImage(UGint x, UGint y, 
		UGint nWidth, UGint nHeight,
		UGImage* pImage,
		UGint xSrc, UGint ySrc, 
		UGint nSrcWidth, UGint nSrcHeight, 
		UGint nDrawMode) ;
		

};

}

#endif // !defined(AFX_UGXGRAPHICS_H__0B8ABC21_18A2_4B88_8E1E_15D7EB407EE5__INCLUDED_)


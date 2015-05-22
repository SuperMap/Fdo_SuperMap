// UGMarkerSymStroke.h: 

#ifndef UG_MARKERSYMSTROKE_H
#define UG_MARKERSYMSTROKE_H

#include "UGMarkerSymParam.h"
#include "UGBitmapStroke.h"
#include "UGIconStroke.h"

namespace UGC 
{

/** 点符号的构成要素Stroke( 称为：笔画 )
	@remarks
		1。一个点符号由多个笔划构成；
		2。笔划分为点状、线状、面状、文本笔划四大类；
		3。每种笔划都可根据需要具有自己的属性，如：线宽、颜色、填充等；
		4。每个笔划都有控制点，对于不同的笔划，所拥有的控制点的个数不一，
		   这些控制点存放在m_SymPoints中
*/
class SYMBOL_API UGMarkerSymStroke  
{     
public:

	//点符号笔画支持的类型(12种) -->类型顺序和SFC5.0保持一致
	enum StorkeType
	{  
		//点状
		ST_Point     = 0,   //点

        //线状
		ST_Polyline  = 1,   //折线
		ST_Arc       = 2,   //弧线

		//面状
		ST_Polygon   = 3,   //多边形
		ST_Ellipse   = 4,   //椭圆
		ST_Rectangle = 5,   //矩形
		ST_Roundrect = 6,   //圆角矩形

		//文本
		ST_Text      = 7,   //文本注记   
		
		ST_Pie       = 8,   //扇形
		ST_Chord     = 9,   //弓形			
		
		//栅格扩展类型
		ST_Bitmap    = 10,  //导入位图 
		ST_Icon      = 11   //导入图标

	};
	
	enum BrushStyle//面状笔划的填充类型 (8种)
	{           
		BS_Solid      = 0,	// 实填充画刷
		BS_Null       = 1,	// 无画刷
		BS_Vertical   = 2,	/* ||||| */
		BS_Horizontal = 3,	/* ----- */
		BS_Fdiagonal  = 4,	/* \\\\\ */
		BS_Bdiagonal  = 5,	/* ///// */
		BS_Cross      = 6,	/* +++++ */
		BS_Diagcross  = 7,	/* xxxxx */
	};
	
	enum PenStyle //线状笔划的画笔类型(4种)
	{
		PS_Solid   = 0,
		PS_Dash    = 1,
		PS_Dot     = 2,
		PS_DashDot = 3
	};
	
public:
	UGMarkerSymStroke();
	~UGMarkerSymStroke();
	UGMarkerSymStroke(const UGMarkerSymStroke& rhs);
	UGMarkerSymStroke& operator = (const UGMarkerSymStroke& rhs);
	
public:	
	//! \brief 读取函数
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief 存储函数
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! 绘制函数
	/**
	\param graphics  绘制到的视图[in]
	\param symParam  绘制参数[in]
	*/
	void   Draw(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

public:
	//! 点击事件
	/**
	\param pntHitTest	点击点位置[in]
	\param symParam		点符号参数[in]
	\param nTolerance	容限[in]
	\return 
	*/
	UGbool HitTest(const UGPoint& pntHitTest, UGMarkerSymParam& SymParam, UGint nTolerance) const;
	
	//! 得到符号类型
	StorkeType GetType() const;
	//! 设置符号类型
	void  SetType(StorkeType type);

	//! 是否固定符号画笔颜色
	UGbool IsFixedPenColor() const;
	//! 是否固定符号画刷颜色
	UGbool IsFixedBrushColor() const;
	//! 是否固定符号文本颜色
	UGbool IsFixedTextColor() const;
	//! \brief 点符号中笔划绘制时得到是否固定笔划宽度信息。
	/**
	得到是否固定画笔，实现符号宽度的固定。
	\remarks 对符号中固定宽度的实现，遵循符号的优先级大于符号中笔划的优先级，如果在符号信息中选择固定符号宽度，则符号中所有笔划无论是否设置固定宽度都设置为固定宽度；如果符号中没有选择固定宽度，则在符号中的笔划信息读取时来确定各个笔划的宽度是否固定。
	*/
	UGbool IsFixedPenWidth() const;
	//! \brief 点符号中笔划绘制时得到是否固定笔划透明度信息。
	UGbool IsFixedTransPercent() const;
	//! \brief 点符号中笔划绘制时得到是否固定笔划渐变信息。
	UGbool IsFixedGradient() const;
	
	//! \brief 设置点符号中笔划绘制时是否固定笔划宽度信息。
	/**
	设置是否固定画笔。
	\remarks 对符号中固定宽度的实现，遵循符号的优先级大于符号中笔划的优先级，如果在符号信息中选择固定符号宽度，则符号中所有笔划无论是否设置固定宽度都设置为固定宽度；如果符号中没有选择固定宽度，则在符号中的笔划信息读取时来确定各个笔划的宽度是否固定。
	*/
	void SetFixedPenColor(UGbool bFixed);
	//! 设置是否固定符号画刷颜色
	void SetFixedBrushColor(UGbool bFixed);
	//! 设置是否固定符号文本颜色
	void SetFixedTextColor(UGbool bFixed);
	//! 设置是否固定符号宽度
	void SetFixedPenWidth(UGbool bFixed);
	//! \brief 设置点符号中笔划绘制时是否固定透明度
	void SetFixedTransPercent(UGbool bFixed);
	//! \brief 设置点符号中笔划绘制时是否固定渐变效果
	void SetFixedGradient(UGbool bFixed);
	
	//! 得到符号画笔宽度
	UGuchar  GetPenWidth() const;	
	//! 得到符号画笔颜色
	UGColor  GetPenColor() const;	
	//! 得到符号画刷颜色
	UGColor  GetBrushColor() const;
	//! 得到符号文本颜色
	UGColor  GetTextColor() const;
	//! 得到符号画笔风格
	PenStyle GetPenStyle() const;	
	//! 得到符号画刷风格
	BrushStyle GetBrushStyle() const;
	//! 得到符号字体名称
	const UGString& GetFontName() const;
	//! 得到符号字体名称
	const UGString& GetTxtNotes() const;

	UGBitmapStroke* GetBitmapStroke() const;
	UGIconStroke*   GetIconStroke() const;

	void SetPenWidth(UGuchar nPenWidth);
	void SetPenColor(UGColor color);
	void SetBrushColor(UGColor color);
	void SetTextColor(UGColor color);
	void SetPenStyle(PenStyle nStyle);
	void SetBrushStyle(BrushStyle nStyle);	
	void SetFontName(const UGString& strFontName);
	void SetTxtNotes(const UGString& strTxtNotes);
	
	void MakeDefault();
	
	UGint GetCountOfPoints() const;		
	void  Add(const UGSymPoint& symPoint);
	void  InsertAt(UGint nIndex, const UGSymPoint& symPoint);
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	void  RemoveAll();
	
	void SetAt(UGint nIndex, UGSymPoint symPoint);	
	UGSymPoint GetAt(UGint nIndex);

	//! 该笔划的字节数(用于辅助保存为5.0格式)
	UGint GetStrokeBytesNum() const;
	
	
	//! \brief 计算笔画的bounds dongfei 2007-03-28
	/**
	\return 返回笔画的范围，以符号的坐标系（0-255）为参考 
	*/
	void GetStrokeRect(UGRect  * pRect);

	//! \brief 设置透明度
	void SetTransPercent(UGint nTransPercent);
	UGint GetTransPercent();

	//! \brief 设置渐变参数
	void SetGradientEndColor(UGColor EndColor);
	UGColor GetGradientEndColor();

	void SetGradientRadian(UGdouble dRadian);
	UGdouble GetGradientRadian();

	void SetGradientHOffsetCenter(UGint nHOffsetCenter);
	UGint GetGradientHOffsetCenter();

	void SetGradientVOffsetCenter(UGint nVOffsetCenter);
	UGint GetGradientVOffsetCenter();

	void SetGradientGradientType(UGint nType);
	UGint GetGradientGradientType();

protected:
	void  ClearUp();

protected:
	//------文件存取相关函数-------------------
	//! \brief 读取得到笔划中的数据、信息。
	/**
	\param stream  符号库文件笔划的数据流信息[in]
	\return 读取是否成功。
	\remarks UGC第二版本，同第一版本相比基本相同，只是多了一个是否固定笔划宽度的数据信息m_bPenFixedWidth的读取。
	*/
	UGbool Load_Version2007(UGStream& stream);
	//! \brief 保存笔划信息保存到流文件中。
	/**
	\param stream  符号库文件笔划的数据流信息[out]
	\return 保存是否成功。
	\remarks UGC第二版本，同第一版本相比基本相同，只是多了一个是否固定笔划宽度的数据信息m_bPenFixedWidth的保存。
	*/
	UGbool Save_Version2007(UGStream& stream) const;

	//! UGC第一版本
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2005(UGStream& stream) const;

	UGbool Load_Version2003(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;

	UGbool LoadDetails(UGStream& stream, UGuint nVersion = 0);
	UGbool LoadDetails2007(UGStream& stream, UGuint nVersion = 0);
	UGbool LoadDetails2005(UGStream& stream, UGuint nVersion = 0);
	UGbool SaveDetails(UGStream& stream, UGuint nVersion = 0) const;
	UGbool SaveDetails2007(UGStream& stream, UGuint nVersion = 0) const;
	UGbool SaveDetails2005(UGStream& stream, UGuint nVersion = 0) const;


protected:
	//! 绘制点、线、多边形(这三种笔划的绘制方式相似)
	void DrawPoints(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	//! 绘制Arc、Pie、Chord、Ellipse
	void DrawEllipseArcWithRotation(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void DrawEllipseArcWithoutRotation(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	void      DrawRect(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void DrawRoundRect(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

	void      DrawText(UGGraphics& graphics, UGMarkerSymParam& symParam) const;
	void     DrawImage(UGGraphics& graphics, UGMarkerSymParam& symParam) const;

protected:
	//! 构造圆角矩形
	void BuildRoundRect(UGSymPoint*& pPoints, UGint& nPntCount, 
		                  const UGSymPoint& ptUpLeft, const UGSymPoint& ptLowRight,
						  UGint nWidth, UGint nHeight ) const;

	//! 构建Arc、Pie、Chord、Ellipse的弧段
	void BuildArc(UGPoint*& pPoints, UGint& nPntCount) const;

	void BuildArc2(UGSymPoint*& pPoints, UGint& nPntCount) const;

	//! \brief 构建一个矩形，它是『point1和point2所围矩形』的4倍，同时遵循一定的方向性
	//! \remarks 弧段ST_Arc的显示时需要由2个控制点来构造外框矩形
	UGRect ConvertEllipseRect(const UGPoint& point1, const UGPoint & point2, UGbool bGraphicsYAxisUp ) const;

	//! 计算点笔划绘制时的半径(用于点笔划的绘制和点笔划的HitTest)
	UGint CalcPointRadius() const;

protected:

	//! 根据参数param以及笔划的内部参数来设置Graphics的新GDI对象(画笔、画刷、字体)
	void PrepareGraphics(UGGraphics& graphics, UGMarkerSymParam& param) const;
	//! 恢复Graphics
	void RestoreGraphics(UGGraphics& graphics, UGMarkerSymParam& param) const;
	
	//! 根据stroke和param中的参数来创建相应的画笔、画刷(仅在PrepareGraphics中被调用)
	void PrepareNewPen(UGGraphics& graphics, UGMarkerSymParam& param) const;
	void PrepareNewBrush(UGGraphics& graphics, UGMarkerSymParam& param) const;
	//! \brief 判断是否绘制渐变效果
	/**
	\param symParam        绘制参数[in]
	\param EndColor        背景色[in\out]
	\param dRadian         角度 [in\out]
	\param nHOffsetCenter  水平偏移 [in\out]
	\param nVOffsetCenter  竖直偏移 [in\out]
	\param nType           绘制类型 [in\out]
	\return 是否绘制渐变
	*/
	UGbool IsDrawGradient(UGMarkerSymParam& symParam,UGColor& EndColor,UGdouble& dRadian,UGint& nHOffsetCenter,UGint& nVOffsetCenter,UGint& nType,UGColor& PenColor)const;

	//! 将stroke定义的Brush风格转换为UGBrush的风格
	UGBrush::BrushStyle StrokeBs2UGBs(UGMarkerSymStroke::BrushStyle StrokeBs) const;

	//! 解析字符串strSrc，统计其中的行数，以及这些行的字符个数的最大值
	void ParseTextNotes(const UGString& strSrc, UGArray<UGString>& Lines, UGint& nMaxCharCount)const;

	//! 计算『点pnt和点pntOrgin的连线』与水平线之间的角度值(-pi～pi，单位为弧度)，以x轴正方向为起始角度，逆时针方向。
	UGdouble CalculateAngle(UGdouble pntOrgX, UGdouble pntOrgY, UGdouble pntX, UGdouble pntY) const
	{
		UGdouble dAngle = atan2( pntY - pntOrgY, pntX - pntOrgX  );
		if ( dAngle < 0 )
		{
			dAngle += 2 * PI;
		}

		return dAngle;
	}

	//! 计算椭圆弧上的点
	void CalculateEllipsePoint(UGdouble a, UGdouble b, UGdouble x0, UGdouble y0, UGdouble dParamRadian, UGSymPoint& ptResult ) const
	{
		// 椭圆上特定 参数角(弧度单位) 的点的坐标
		// 椭圆方程: [(x-x0)^2 / a^2] + [(y-y0)^2 / b^2] = 1
		// 解为: x = x0 + a*cos(alpha)
		//		 y = y0 + b*sin(alpha)

		ptResult.x = UGROUND ( x0 + a * cos(dParamRadian) );

		//注：基于Y轴正向向下的坐标系，所以用减
		ptResult.y = UGROUND ( y0 - b * sin(dParamRadian) );
	}

	//! 得到由点pt1和pt2确定的矩形(注:坐标系y正轴朝下)的左上角的点(仅用于DrawText中)
	void GetRectTopLeftPnt(const UGSymPoint& pt1, const UGSymPoint& pt2, UGSymPoint& ptTopLeft) const;

protected:
	/*   8 7 6 5 4 3 2 1---------- 1 画笔颜色是否固定--(第1位，最低位)
		 | | | | | | +------------ 2 画刷颜色是否固定--(第2位)
		 | | | | | +-------------- 3 画笔风格(4种)--(3、4共两位，表示4种状态)
		 | | | | +---------------- 4 
		 | | | +------------------ 5 BrushStyle(8种)--(5、6、7共三位，表示8种状态)
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 IsFixedTextColor--(第8位，最高位) */
	//! 属性和类型
	UGuchar               m_nProperties;   //笔划的属性选项(见上图)
	//! \brief 保存是否固定符号宽度。
	/**
	\remarks 默认为false，不固定。
	*/

	/*   8 7 6 5 4 3 2 1---------- 1 画笔宽度是否固定-------(第1位，最低位)
		 | | | | | | +------------ 2 笔划半透明效果是否固定-(第2位)
		 | | | | | +-------------- 3 笔划渐变效果是否固定－－(第三位)
		 | | | | +---------------- 4 
		 | | | +------------------ 5 
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 */
	//! 属性和类型
	UGuchar               m_nProperties2;
	StorkeType            m_emType;        //笔划的类型

	//! 画笔和画刷
	UGuchar              m_PenWidth;       //画笔的宽度(单位：0.01mm)
	UGColor              m_PenColor;       //画笔颜色
	UGColor              m_BrushColor;     //画刷颜色

	//! \brief 保存渐变的相关参数
	UGColor              m_EndColor;       //渐变的背景色
	UGdouble             m_dRadian;        //渐变的角度
	UGint                m_nHOffsetCenter; //渐变的水平偏移量
	UGint                m_nVOffsetCenter; //渐变的竖直偏移量
	UGint				 m_nGradientType;  //渐变的类型
	
	//! 文本
	UGColor              m_TextColor;
	UGString             m_strFontName;
	UGString             m_strNotes;

	//! 扩展笔划
	UGBitmapStroke*      m_pBitmapStroke;  //栅格笔划的指针：只对栅格符号的有用
	UGIconStroke*        m_pIconStroke;    //Icon笔划的指针：只对Icon符号有用

	//! 控制点数组
	UGArray<UGSymPoint>  m_SymPoints;      //一个笔划的控制点的数组
	UGint m_nTransPercent;                 //笔划的透明度 
	
};


}

#endif



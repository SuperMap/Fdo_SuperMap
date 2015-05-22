// UGLineSymBaseData.h:

#if !defined(UG_LINESYMBASEDATA_H)
#define UG_LINESYMBASEDATA_H

#include "Base/UGString.h"

namespace UGC 
{
	
class SYMBOL_API UGLineSymBaseData  
{
public:
	friend class UGLineSymbolBase;

public:
	/** 基线的风格类型
		@remarks
		   1.系统内部定义了49种风格的类型
		   2.不同风格的类型有具体不同的绘制方法
		   3.对于有些风格类型，有些类成员的参数信息会用不到；
	*/
	enum StyleType
	{
		DSV_DEFAULT					=0,			//短横线(系统线型)

		DSV_VCENTER 				=1,			//短竖线(中心对齐)
		DSV_VUP						=2,			//短竖线(上边对齐)
		DSV_VDOWN					=3,			//短竖线(下边对齐)

		DSV_VUPDOWN					=4,			//上下交错
		DSV_VSHORTLONGUP			=5,			//长短交错(向上)
		DSV_VSHORTLONGDOWN			=6,			//长短交错(向下)
		DSV_VSHORTLONGUPDOWN		=7,			//长短交错(上长下短)
		DSV_VSHORTLONGDOWNUP		=8,			//长短交错(上短下长)

		DSV_VBEVEL					=9,			//倾斜线( \ )
		DSV_VBEVEL2					=10,		//倾斜线( / )
		DSV_VBEVELUPDOWN			=11,		//倾斜线(上下交错)

		DSV_VTRIANGLE				=12,		//箭头式( < )
		DSV_VTRIANGLE2				=13,		//箭头式( > )

		DSV_VWAVE					=14,		//波浪线
		DSV_VWALL					=15,		//长城符号5
		DSV_VBOX					=16,		//长方盒

		DSV_VUPDOWNCROSS			=17,		//横竖交错
		DSV_VXCROSS					=18,		//交叉符号( X )
		DSV_VCROSSUP				=19,		//交叉符号(向上)
		DSV_VCROSSDOWN				=20,		//交叉符号(向下)
		DSV_VCROSSUPDOWN			=21,		//交叉符号(上下交错)

		DSV_VBIARCUP				=22,		//半圆弧(向上)
		DSV_VBIARCDOWN				=23,		//半圆弧(向下)
		DSV_VBIARCUPDOWN			=24,		//半圆弧(上下交错)

		DSV_VCIRCLESOLID			=25,		//圆弧(实心、线中心)
		DSV_VCIRCLEHOLLOW			=26,		//圆弧(空心、线中心)
		DSV_VCIRCLEUPDOWN			=27,		//圆弧(上下交错)

		DSV_VTRUETYPEHORIZON		=28,		//字型符号(水平)
		DSV_VTRUETYPEHORIZONREV		=29,		//字型符号(水平反向)
		DSV_VTRUETYPEVERTICAL		=30,		//字型符号(垂直)
		DSV_VTRUETYPEVERTICALREV	=31,		//字型符号(垂直反向)
		DSV_VTRUETYPEFIXED			=32,		//字型符号(固定方向)
		DSV_VTRUETYPEFREEANGLE		=33,		//字型符号(自由角度方向)

		DSV_DASHWITHTAILARROW		=34,		//短线带尾箭头->
		DSV_DASHWITHHEADERARROW		=35,		//短线带头箭头<-
		DSV_DASHWITHDOUBLEARROW		=36,		//短线带双箭头<->
		DSV_DASHWITHMIDIUMARROW		=37,		//短线中间带正箭头->-
		DSV_DASHWITHMIDIUMREVERSEARROW=38,		//短线中间带反箭-<-

		DSV_ELECTRIC				=39,		//电力线段
		DSV_ELECTRICEX				=40,		//电力线段(带中间线)
		DSV_ELECTRIC_SPECIAL		=41,		//电力线段(特殊)
		DSV_ELECTRICEX2				=42,		//电力线段(圆心)

		DSV_DOUBLEPARELLEL			=43,		//平行双线(中心对齐)
		DSV_LEFTPARELLEL			=44,		//平行双线(上边对齐)
		DSV_RIGHTPARELLEL			=45,		//平行双线(下边对齐)

		DSV_GRADIENT				=46,		//渐变线

		DSV_SYMBOL					=47,		//自定义符号（相对角度）
		DSV_SYMBOLFIXED				=48			//自定义符号（固定角度）			
	};

public:
	UGLineSymBaseData();
	~UGLineSymBaseData();

	//{{--对于该类使用默认的拷贝和动作就ok----commented by Y.M.Zheng--
	//UGLineSymBaseData(const UGLineSymBaseData& LineSymBaseData);
	//void operator = (const UGLineSymBaseData& LineSymBaseData);
	//}}--------------------------------------------------------------
	
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;
	UGbool Save_Version2005(UGStream& stream) const;
	
public:
	UGshort GetVertLength() const;
	void SetVertLength(UGshort nVertLength);
	
	StyleType GetStyleType() const;
	void SetStyleType(StyleType eType);
	
	UGshort GetHoriOffset() const;
	void SetHoriOffset(UGshort nHoriOffset);
	
	UGshort GetVertOffset() const;
	void    SetVertOffset(UGshort nVertOffset);
	

	//! 是否水平补绘: 仅对 系统短横线起作用
	UGbool IsHoriRepair() const;
	//! 是否垂直补绘: 仅对 前三种短竖线起作用
	UGbool IsVertRepair() const;
	
	UGbool IsPenFixedColor() const;
	UGbool IsPenFixedWidth() const;

	//! \brief 线型绘制时宽度是否固定。
	/**
	在线型选中符号缩放时，得到是否固定线型宽度信息。
	\return 是否固定宽度，1代表固定宽度，0代表不固定，默认为0。
	*/
	UGbool IsPenFixedLineWidth() const;
	UGint  GetPenJoinType() const;	
	UGint  GetPenCapType() const;	
	UGint  GetPenDotDashType() const;
	
	void SetHoriRepair(UGbool bHoriRepair);
	void SetVertRepair(UGbool bVertRepair);
	void SetPenFixedColor(UGbool bPenFixedColor);
	void SetPenFixedWidth(UGbool bPenFixedWidth);
	//! \brief 线型绘制时设置宽度是否固定。
	/**
	设定是否固定线型宽度，在符号缩放下宽度是否固定不变。
	\param bPenFixedLineWidth  是否固定宽度[in]
	*/
	void SetPenFixedLineWidth(UGbool bPenFixedLineWidth);
	void SetPenJoinType(UGint nPenJoin);
	void SetPenCapType(UGint nPenCap);		
	void SetPenDotDashType(UGint nPenStyle);
	
	UGColor GetFixedColor() const;
	void    SetFixedColor(UGColor color);
	UGint   GetFixedWidth() const;
	void    SetFixedWidth(UGint nWidth);
	
	UGString GetFontName() const;
	void SetFontName(const UGString& strFontName);

	UGint GetAsciiCode() const;
	void SetAsciiCode(UGint nCode);
	
	UGdouble GetAngle() const;
	void SetAngle(UGdouble dAngle);
	
	void Reset();
	
protected:
	//! 基线的风格类型(49种中之一)
	StyleType  m_eStyleType;
	
	//! 纵向长度(只对具有上下方向性的风格类型有用)
	UGshort m_nVertLength;

	//! 该基线绘制时的水平(横向)偏移量(绘制前根据该值来计算真正绘制的起始端点)
	UGshort m_nHoriOffset;		

	//! 该基线绘制时的垂直(纵向)偏移量(绘制前根据该值来计算折线纵向偏移后的所有点)
	UGshort m_nVertOffset;		
		
	/*   8 7 6 5 4 3 2 1---------- 1 画笔颜色是否固定
		 | | | | | | +------------ 2 画笔宽度是否固定
		 | | | | | +-------------- 3 是否水平补绘
		 | | | | +---------------- 4 是否垂直补绘
		 | | | +------------------ 5 符号缩放时是否固定画笔宽度
		 | | +-------------------- 6 保留
		 | +---------------------- 7 保留
		 +------------------------ 8 */
	//! 线型属性，用其中的比特位来标志一些属性
	UGint   m_nAttr;   

	/*记录画笔的三种类型信息：点划类型、端头类型、转角类型
	  第1~4位(共4位)来记录PenDotDashStyle的类型
	  第9~12位(共4位)来记录PenCap的端头类型
	  第13~16位(共4位)来记录PenJoin转角类型*/
	//! 内部画笔的线型代码和转角等线型风格.0~7为系统线型,>=8为用户定义线型,与MFC的设置相同
	UGint   m_nPenStyle; 		    

	//! 线型内置的固定颜色(如果m_nAttr中的固定颜色标志位设置了，在绘制时就使用该值；如果没有设置，该值就不会被用到)
	UGColor m_FixedColor;		

	//! 线型内置的固定宽度(如果m_nAttr中的固定宽度标志位设置了，在绘制时就使用该值；如果没有设置，该值就不会被用到)
	UGshort m_nFixedWidth;
	
	//! 字符旋转角度(单位:0.1度)(只对字型符号风格有用)  
	UGint   m_nAngle;		

	//! 字符ASCII码(只对字型符号风格有用)
	UGshort m_nAsciiCode;		

	//! 符号字体名称(只对字型符号风格有用)
	UGchar  m_FontName[32];		

	//! 保留备用
	UGint m_nReserved;
};

}//namespace UGC

#endif


// UGThemeSymbol.h: interface for the UGThemeSymbol class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeSymbol.h
   **************************************************************************************
    \author   陈国雄
    \brief    符号专题图类，所有通过对象中心点来显示图形的专题图类都通过它派生。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_)
#define AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_

#include "UGTheme.h"
#include "Geometry/UGGeoText.h"
#include "Drawing/UGDrawing.h"

#define	UG_THEME_OPTIONS_GRADUATED_MODE		0x000000ff	// 分级方式位操作模板

#define UG_THEME_OPTIONS_ENABLE_FLOW		0x00000100	// 是否流动
#define UG_THEME_OPTIONS_SHOW_LEADERLINE	0x00000200	// 是否显示牵引线
#define UG_THEME_OPTIONS_AUTO_AVOID			0x00000400	// 是否自动避让

#define	UG_THEME_OPTIONS_ENABLE_NEGATIVE	0x00000800	// 是否显示负值
#define UG_THEME_OPTIONS_ENABLE_ZERO		0x00800000	// 是否显示零值

#define UG_THEME_OPTIONS_ALONG_LINE			0x00001000	// 是否沿线
#define UG_THEME_OPTIONS_FIXED_ANGLE		0x00002000	// 是否固定角度
#define UG_THEME_OPTIONS_IGNORE_OBJECT		0x00008000	// 是否忽略小对象
#define SM_THEME_LABEL_OPTIONS_FIXED_REPEAT 0x00400000	// 是否固定
#define UG_THEME_OPTIONS_SELF_OVERLAP		0x01000000	// 是否子相交

#define UG_THEME_OPTIONS_FIXED_OFFSET		0x00004000	// 是否固定偏移

#define UG_THEME_OPTIONS_SHOW_AXES			0x00010000
#define UG_THEME_OPTIONS_SHOW_AXESTEXT		0x00020000
#define UG_THEME_OPTIONS_SHOW_ITEMTEXT		0x00040000
#define UG_THEME_OPTIONS_SHOW_AXESGRID		0x00080000
#define UG_THEME_OPTIONS_BAR_LIE			0x00100000
#define UG_THEME_OPTIONS_FIXED_SIZE			0x00200000


namespace UGC {


//const UGdouble dtan30 = 0.57735026918962576450914878050196;
const UGdouble dtan60 = 1.7320508075688772935274463415059;

class MAP_API UGThemeSymbol : public UGTheme  
{
public:
	typedef	enum				//注记选取的标注位置 added by dongfei 2007-04-10
	{
		UG_POS_TOPLEFT = 0,		
		UG_POS_TOPCENTER = 1,
		UG_POS_TOPRIGHT = 2,
		UG_POS_CENTERLEFT = 3,
		UG_POS_CENTER = 4,
		UG_POS_CENTERRIGHT = 5,
		UG_POS_BOTTOMLEFT = 6,
		UG_POS_BOTTOMCENTER = 7,
		UG_POS_BOTTOMRIGHT = 8
	}   emTextPositionType;

public:
	UGThemeSymbol();
	virtual ~UGThemeSymbol();

public:
	//! \brief  得到X的偏移
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const = 0;
	//! \brief  得到Y的偏移
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const = 0;

	//! \brief  得到对应记录集的偏移
	UGSize2D FindOffset(UGRecordset *pRecordset)const;
	//! \brief  检查偏移字段是否合法
	UGbool CheckOffsetFieldType(UGint nType);

	//! \brief  得到X的偏移的表达式
	UGString GetOffsetXExpression()const;
	//! \brief  设置X的偏移的表达式
	void SetOffsetXExpression(const UGString& strOffsetXExpression);

	//! \brief  得到Y的偏移的表达式
	UGString GetOffsetYExpression()const;
	//! \brief  设置Y的偏移的表达式
	void SetOffsetYExpression(const UGString& strOffsetYExpression);
	
	//! \brief  是否固定偏移量
	UGbool IsFixedOffset()const;
	//! \brief  设置是否偏移
	void SetFixedOffset(UGbool bFixedOffset = false);

	//! \brief  是否流动显示
	UGbool IsEnableFlow()const;
	//! \brief  设置是否流动显示
	void SetEnableFlow(UGbool bEnableFlow = true);

	//! \brief  是否自动避让
	UGbool IsAutoAvoid()const;
	//! \brief  设置是否自动避让
	void SetAutoAvoid(UGbool bAutoAvoid = false);

	//! \brief  是否显示牵引线
	UGbool IsShowLeaderLines()const;
	//! \brief  设置是否显示牵引线
	void SetShowLeaderLines(UGbool bShowLeaderLines = false);

	//! \brief  得到牵引线风格
	const UGStyle& GetLeaderLineStyle()const;
	//! \brief  设置牵引线风格
	void SetLeaderLineStyle(const UGStyle& Style);	
	
	//added by lugw 2007-03-12 提供固定统计图接口
	//! \brief  设置是否固定统计图不随图缩放
	/**
	\param bFixedGraph  是否固定统计图[in]
	\remarks 缺省值为false，不固定
	*/
	void SetFixedGraph(UGbool bFixedGraph = false);
	//! \brief  得到是否固定统计图不随图缩放
	/**
	\return 得到是否固定的值
	*/
	UGbool IsFixedGraph() const;

	//! \brief  added by dongfei 2007-04-12
	/*	设置/返回文字避让的缓冲距离
	**
	*/
	void SetBuffer(UGdouble dBufferX,UGdouble dBufferY)
	{
		m_dBufferX = dBufferX;
		m_dBufferY = dBufferY;
	}
	UGdouble GetBufferX(){return m_dBufferX;};
	UGdouble GetBufferY(){return m_dBufferY;};

	//! \brief 设置文字候选位置的优先级  added by dongfei 2007-04-09
	/*
	**文字优先级分为0-9级，0级不考虑该候选位置，1-9级优先级依次降低 可重复设置同一优先级别
	*/
	void SetPosPriority(UGuint* pPosPriority);
	void SetTopLeftPriority(UGuint priority = 1)			{m_uPosPriority[0] = priority;};
	void SetTopCenterPriority(UGuint priority = 1)			{m_uPosPriority[1] = priority;};
	void SetTopRightPriority(UGuint priority = 1)			{m_uPosPriority[2] = priority;};
	void SetCenterLeftPriority(UGuint priority = 1)			{m_uPosPriority[3] = priority;};
	void SetCenterPriority(UGuint priority = 1)				{m_uPosPriority[4] = priority;};
	void SetCenterRightPriority(UGuint priority = 1)		{m_uPosPriority[5] = priority;};
	void SetBottomLeftPriority(UGuint priority = 1)			{m_uPosPriority[6] = priority;};
	void SetBottomCenterPriority(UGuint priority = 1)		{m_uPosPriority[7] = priority;};
	void SetBottomRightPriority(UGuint priority = 1)		{m_uPosPriority[8] = priority;};

	void	GetPosPriority(UGArray<UGuint>& posPriorityArray);
	UGuint	GetPosPriority(UGint index)		{return m_uPosPriority[index];};
	UGuint	GetTopLeftPriority()			{return m_uPosPriority[0];};
	UGuint	GetTopCenterPriority()			{return m_uPosPriority[1];};
	UGuint	GetTopRightPriority()			{return m_uPosPriority[2];};
	UGuint	GetCenterLeftPriority()			{return m_uPosPriority[3];};
	UGuint	GetCenterPriority()				{return m_uPosPriority[4];};
	UGuint	GetCenterRightPriority()		{return m_uPosPriority[5];};
	UGuint	GetBottomLeftPriority()			{return m_uPosPriority[6];};
	UGuint	GetBottomCenterPriority()		{return m_uPosPriority[7];};
	UGuint	GetBottomRightPriority()		{return m_uPosPriority[8];};
	//! \brief added by dongfei 2007-04-10
	/*
	**根据注记的候选相对位置重新计算注记的显示位置
	*/
	void  ReCalcTextPos(const UGSize2D *szOffset, UGGeoText* pGeoText, emTextPositionType emTextPos);
	void  ReCalcRectPos(UGRect *pRect, const UGSize& szOffset, emTextPositionType emTextPos);
	//! \brief added by dongfei 2007-04-10
	/*
	** 从候选位置中选出注记标注的位置，为0则不标注，1-9对应位置如下
	**													 ___________ 
	**													|1	|2  |3  |
	**													|___|___|___|
	**													|4	|5  |6  |				
	**													|___|___|___|
	**													|7  |8  |9  |	
	**													|___|___|___|
	\param pOffset 文字相对于定位点的偏移量
	\param pGeoText 需定位的文字，文字都采用中心对齐，便于偏移
	*/
	UGint SelectLabelPos( UGGeoText* pGeoText,UGDrawing *pDrawing,const UGSize2D *pOffset,UGSize2D szBuffer = UGSize2D(-1.0,-1.0),UGbool bChangeTextStyle = true);
	UGint SelectLabelPos( UGGeoCompound* pCompound, UGDrawing *pDrawing,const UGSize2D *pOffset, const UGPoint2D& pntCentroid, const UGTextStyle& textstyle);
	//这个使用逻辑坐标 反正是用逻辑坐标比较 最后总是要转成逻辑坐标的
	UGint SelectRectPos(UGRect* pRect,UGDrawing *pDrawing,const UGSize& szOffset,UGSize szBuffer = UGSize(-1,-1));

	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const = 0;

	void GeometryOffsetByAlign(UGGeoCompound* pCompound, const UGPoint2D& pntCentroid, UGint nAlign);
protected:  
	void Swap(const UGThemeSymbol& theme);	

protected:	
	UGString m_strOffsetXExpression;
	UGString m_strOffsetYExpression;
	UGStyle m_LeaderLineStyle;	
	UGuint m_unOptions;					//流动标签，自动避让等选项
	//! \brief  保存是否固定统计图信息
	/**
	\remarks 默认为否，值为0
	*/
	UGbool m_bFixedGraph;

	UGuchar m_uPosPriority[9];	//added by dongfei 2007-04-09 文字候选位置的优先级 
								//候选位置在数组中的存放顺序是 
								//						 ___________ 
								//						|1	|2  |3  |
								//						|___|___|___|
								//						|4	|5  |6  |				
								//						|___|___|___|
								//						|7  |8  |9  |	
								//						|___|___|___|
	//added by dongfei 2007-04-12
	UGdouble	m_dBufferX;				//x方向上避让的缓冲距离
	UGdouble	m_dBufferY;				//y方向上避让的缓冲距离
	UGchar		m_nThemePriority;		//专题图的优先级 默认为0，优先级最低，1级最高，级别最多支持到255级 1-255级优先级依次降低

};

}

#endif // !defined(AFX_UGTHEMESYMBOL_H__12471BD8_C034_4AEB_ABDD_174C09E209D4__INCLUDED_)

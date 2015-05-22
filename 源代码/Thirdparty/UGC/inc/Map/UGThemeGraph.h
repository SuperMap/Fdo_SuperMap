// UGThemeGraph.h: interface for the UGThemeGraph class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGraph.h
   **************************************************************************************
    \author   陈国雄
    \brief    统计专题图类。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_)
#define AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_

#include "UGThemeSymbol.h"
#include "UGGraph.h"
#include "UGLayer.h"

namespace UGC {

class MAP_API UGThemeGraph : public UGThemeSymbol  
{
public:
	UGThemeGraph();
	virtual ~UGThemeGraph();
	UGThemeGraph(const UGThemeGraph& ThemeGraph);
	UGThemeGraph& operator = (const UGThemeGraph& ThemeGraph);

public:
	//! \brief 专题图是否有效
	/**
	专题图是否有效
	*/
	virtual UGbool IsValid()const;
	//! \brief 专题图数据信息导成XML格式
	/**
	*/
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML中读取专题图信息
	/**
	*/
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 检测查询字段是否为有效类型
	/**
	*/
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief 获取查询字段
	/**
	*/
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief 获取X方向偏移量
	/**
	*/
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief 获取Y方向偏移量
	/**
	*/
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief 获取查询字段组
	/**
	*/
	UGbool GetFieldName(UGArray<UGString>& strArray)const; 
	//! \brief 将Recordset转化为对应的Geometry
	/**
	\param pRecordset 所选的记录集[in]
	\param point      绘制点[in]
	\param pDrawParam 绘制参数[in]
	\remarks 所要绘制的Geometry
	*/
	UGGeometry *ConvertToGeometry(UGRecordset *pRecordset, const UGPoint2D &point, UGDrawParamaters *pDrawParam);
	
	//! \brief 设置统计专题图中所需绘制对象的绘制参数，计算默认参数大小
	/**
	\param pDrawParam 绘制参数[in]
	*/
	void SetDrawParamaters(UGDrawParamaters *pDrawParam);
	//! \brief 实现对专题图的某个对象绘制
	/**
	\param pDrawing       绘制类[in] 
	\param pRecordset     记录集[in]
	\param point          绘制点[in]
	\param pntAnchor	绘制定位点[in]
	\param szOffset       偏移量[in]
	\param pHitTestInfo   是否有点击信息[in]
	\remarks 
	*/
	UGbool DrawTheme(UGDrawing *pDrawing, UGRecordset *pRecordset, const UGPoint2D &point, const UGPoint2D &pntAnchor, UGSize2D szOffset,HitTestInfo* pHitTestInfo = NULL);
	//! \brief 实现对专题图的某段值进行绘制
	/**
	\param pDrawing        绘制类[in] 
	\param pValues         所需绘制的段值[in]
	\param unItemCount     段的个数[in]
	\param pntAnchorPoint  锚点[in]
	\param szGraph         绘制大小[in]
	*/
	UGbool DrawItem(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntAnchorPoint, UGSize szGraph);
	//! \brief 为各个段设置默认风格
	/**
	*/
	UGbool MakeDefaultStyles();
	//! \brief 计算统计专题图各个段的极值，计算各段的大小
	/**
	\param pDatasetV      计算的矢量数据集[in] 
	\remarks 
	*/
	UGbool CalculateExtremum(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems);
	//! \brief 检查极值数否有效
	/**
	*/
	UGbool IsValidExtremum()const;
	
	// 统计图字段表达式操作函数
	//! \brief 删除所有段的数值
	/**
	*/
	void RemoveAll();
	//! \brief 增加某字段表达式
	/**
	*/
	UGint Add(const UGString& strExpression);
	//! \brief 交换统计专题图两个段位置
	/**
	*/
	UGbool Swap(UGint nOldIndex, UGint nNewIndex);	
	//! \brief 删除某个段
	/**
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief 得到段的总数
	/**
	*/
	UGint GetCount()const;
	//! \brief 设置段的总数
	/**
	*/
	void SetCount(UGint nCount);	
	
	//! \brief 得到指定字段的表达式
	/**
	*/
	UGString GetExpressionAt(UGint nIndex)const;
	//! \brief 设置某段的字段表达式
	/**
	*/
	void SetExpressionAt(UGint nIndex, const UGString& strExpression );

	//! \brief 得到某段的标题
	/**
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置某段的标题
	/**
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief 得到某字段的风格
	/**
	*/
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief 设置某段的风格
	/**
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& style);
	
	//added by lugw 2007-04-28 对二维字段风格设置提供接口
	//! \brief 设置某段的二维字段风格
	/**
	\param nIndex      字段索引[in] 
	\param styleArray  该字段各个子字段的风格数组[in] 
	*/
	const UGArray<UGStyle>& GetStyleArrayAt(UGint nIndex)const;
	void SetStyleArrayAt(UGint nIndex, const UGArray<UGStyle>& styleArray);

	//! \brief 设置统计图绘制类型
	/**
	*/
	void SetGraphType(UGint nGraphType);		//nGraphType 为统计图类型，其取值范围为enum Type的任意值
	//! \brief 得到统计图绘制类型
	/**
	*/
	UGint GetGraphType()const;						//nGraphType 为统计图类型，其取值范围为enum Type的任意值
	
	//! \brief 设置柱状图宽度
	/**
	*/
	void SetBarWidth(UGdouble dBarWidth );
	//! \brief 得到柱状图宽度
	/**
	*/
	UGdouble GetBarWidth()const;

	//! \brief 得到默认风格下的颜色
	/**
	*/
	UGColor GetDefaultColor()const;
	//! \brief 设置默认风格下的颜色
	/**
	*/
	void SetDefaultColor(UGColor color);	

	//! \brief 得到段值和的最小值
	/**
	*/
	UGdouble GetMinSumSize()const;
	//! \brief 设置段值和的最小值
	/**
	*/
	void SetMinSumSize(UGdouble dMinSumSize );
	
	//! \brief 得到段值和的最大值
	/**
	*/
	UGdouble GetMaxSumSize()const;
	//! \brief 设置段值和的最大值
	/**
	*/
	void SetMaxSumSize(UGdouble dMaxSumSize );

	//! \brief 得到起始角度
	/**
	*/
	UGdouble GetStartAngle()const;
	//! \brief 设置起始角度
	/**
	*/
	void SetStartAngle(UGdouble dStartAngle);

	//! \brief 设置分级模式
	/**
	*/
	void SetGraduatedMode(UGint nGraduatedMode);
	//! \brief 得到分级模式
	/**
	*/
	UGint GetGraduatedMode()const;
	
	//! \brief 是否固定大小
	/**
	*/
	UGbool IsFixedSize()const;
	//! \brief 设置是否固定大小
	/**
	*/
	void SetFixedSize(UGbool bFixedSize = false);

	UGbool IsBarLie()const;
	void SetBarLie(UGbool bBarLie = false);

	//! \brief 得到设置是否绘制坐标轴
	/**
	*/
	UGbool IsShowAxes()const;							
	//! \brief 设置是否绘制坐标轴
	/**
	*/
	void SetShowAxes(UGbool bShowAxes = true);			

	//! \brief 得到设置是否画出坐标轴文本
	/**
	*/
	UGbool IsShowAxesText()const;
	//! \brief 设置是否画出坐标轴文本
	/**
	*/
	void SetShowAxesText(UGbool bShowAxesText = true);	
	//! \brief 得到设置是否画出坐标轴文本风格
	/**
	*/
	const UGTextStyle& GetAxesTextStyle()const;			
	//! \brief 设置是否画出坐标轴文本风格
	/**
	*/
	void SetAxesTextStyle(UGTextStyle& TextStyle);		
	
	//! \brief 得到设置是否画出坐标轴网格
	/**
	*/
	UGbool IsShowAxesGrid()const;						
	//! \brief 设置是否画出坐标轴网格
	/**
	*/
	void SetShowAxesGrid(UGbool bShowAxesGrid = false);	
	
	//! \brief 得到字段文本风格
	/**
	*/
	UGbool IsShowItemText()const;						
	//! \brief 设置字段文本风格
	/**
	*/
	void SetShowItemText(UGbool bShowItemText = true);	
	//! \brief 得到字段文本风格
	/**
	*/
	const UGTextStyle& GetItemTextStyle()const;
	//! \brief 设置字段文本风格
	/**
	*/
	void SetItemTextStyle(UGTextStyle& TextStyle);

	//! \brief 得到文本格式
	/**
	*/
	UGint GetItemTextFormat()const;							
	//! \brief 设置文本格式
	/**
	*/
	void SetItemTextFormat(UGint TextFormat);
	
	//! \brief 专题图绘制是否显示负值
	/**
	得到是否显示负值。
	\return 是否显示绘制负值，1代表是，0代表否，默认为否。
	*/
	UGbool IsSupportNegative() const;
	//! \brief 专题图绘制是否显示负值
	/**
	设定是否显示负值。
	\param bFixed  是否显示绘制负值[in]
	\remarks 默认下显示负值。
	\remarks 负值处理原则：（始终处理负值情况）对于面积图、阶梯图、折线图、点状图、柱状图、三维柱状图（含坐标轴）绘制按坐标轴方向，
	\remarks （用户选择是否处理）对于饼图、三维饼图、玫瑰图、三维玫瑰图、金字塔专题图-条形、金字塔专题图-面形，如果用户选择支持负值，负值按正值处理（参照Excel）；如果不支持负值，则不对其进行绘制
	*/
	void SetSupportNegative(UGbool bNegative = true);
	
	//! \brief 返回/设置偏移文字还是统计图表
	/*
	**added by dongfei 2007-04-17
	*/
	UGbool	IsTextOffset() {return m_bTextOffset;};
	void	SetTextOffset(UGbool bText) {m_bTextOffset = bText;};
	
	//! \brief 统计专题图鼠标响应
	/*
	\param pntHitTest    点击位置[in]
	\param pDrawing      绘制参数[in]
	\param pLayer        专题图所在层[in]
	\param geoTextArray  返回字段信息[in/out]
	**
	*/
	UGbool HitTest(const UGPoint2D& pntHitTest,UGDrawing *pDrawing,UGLayer* pLayer,UGArray<UGGeoText>& geoTextArray);

	//! \brief 统计专题图子项的分段专题图信息
	/*
	\param nIndex         子项索引[in]
	\return 该子项的分段专题图信息
	**
	*/
	UGThemeRange& GetItemThemeRangeAt(UGint nIndex)const;
	//! \brief 统计专题图子项的分段专题图是否存在
	/*
	\param nIndex         子项索引[in]
	\return 是否存在分段
	**
	*/
	UGbool IsItemThemeRangeExistAt(UGint nIndex)const;
	//! \brief 统计专题图子项的分段专题图信息
	/*
	\param nIndex         子项索引[in]
	\param pThemeRange    设置子项分段专题图信息[in]
	**
	*/
	void SetItemThemeRangeAt(UGint nIndex,UGThemeRange& pThemeRange);
	
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;
	
	//! \brief 设置统计专题图是否置顶
	/*
	*/
	void SetGraphAlwaysOnTop(UGbool bAlwaysOnTop);
	//! \brief 得到统计专题图是否置顶
	/*
	*/
	UGbool IsGraphAlwaysOnTop()const;

	//! \brief 得到统计专题图玫瑰图形的玫瑰角度
	/*
	*/
	UGdouble GetRoseAngle()const;
	//! \brief 设置统计专题图玫瑰图形的玫瑰角度
	/*
	*/
	void SetRoseAngle(UGdouble dRoseAngle);

	UGDict<UGint, UGPoint2D> m_arrCustomGraph;

	//! \brief 设置外部值
	void SetExternalValue(const UGString& strItemExpression, const UGString& strKey, const UGString& strExternalValue);

	//! \brief 获取指定Item
	const UGGraphItem& GetItem(UGint nIndex)const;

	void Insert(const UGString& strExpression,UGint nIndex);
	


protected:  
	void Swap(const UGThemeGraph& theme);	
	UGSize2D CalculateGraphSize(UGdouble dSumValue);

	//! \brief 得到外部值
	UGbool GetExternalValue(const UGString& strItemExpression, const UGString& strKey, UGString& strExternalValue)const;

protected:	
	UGGraph m_Graph;				// 统计图对象
	UGdouble m_dBarWidth;			// 柱状图宽度	
	UGdouble m_dMaxSum;				// 字段之和的最大值
	UGdouble m_dMinSum;				// 字段之和的最小值	
	UGdouble m_dSqrtMaxSum;			// == sqrt(m_dMaxSum)
	UGdouble m_dSqrtMinSum;			// == sqrt(m_dMinSum)
	UGdouble m_dLogMaxSum;			// == log(m_dMaxSum)
	UGdouble m_dLogMinSum;			// == log(m_dMinSum)	

	UGSize2D m_szMin;				// 图的最小尺寸（地理坐标）
	UGSize2D m_szMax;				// 图的最大尺寸（地理坐标）	
	
	UGTextStyle m_ItemTextStyle;	// 每个子项的文本风格
	UGTextStyle m_ThemeTextStyle;	// 整个统计图的文本风格	
	UGbool		m_bTextOffset;		// 文字偏移还是整个统计图表偏移
	UGbool m_bAlwaysOnTop;

	typedef UGDict<UGString,UGString> UGGraphDict;
	UGDict<UGString,UGGraphDict> m_GraphExternalData;

};

}

#endif // !defined(AFX_UGTHEMEGRAPH_H__BF50002A_00EF_41B1_B119_14ADACC6FB9A__INCLUDED_)

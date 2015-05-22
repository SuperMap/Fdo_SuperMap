// UGGraph.h: interface for the UGGraph class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGraph.h 
   **************************************************************************************
    \author   陈国雄
    \brief    统计图图形类，负责统计图显示和参数管理。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_)
#define AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_

#include "UGGraphItem.h"
#include "Geometry/UGGeometry.h"
#include "Drawing/UGDrawing.h"
#include "Base/UGTextStyle.h"
namespace UGC {

	struct ItemValues 
	{
		UGint nIndex;
		UGdouble* pItemValues;
		UGint nCount;
		ItemValues()
		{
			nIndex = -1;
			pItemValues = NULL;
			nCount = 1;
		};
	};

	struct HitTestInfo 
	{
		UGPoint2D pntHitTest;
		UGArray<UGGeoText> geoTextArray;
	};



class UGThemeGraph;

class MAP_API UGGraph  
{
	friend class UGThemeGraph;
public:	
	enum UGGraphType		//! \brief 统计图类型
	{
		gtArea = 0,	//! \brief 面积图
		gtStep = 1,	//! \brief 阶梯图
		gtLine = 2,	//! \brief 折线图
		gtPoint = 3,//! \brief 点状图	
		gtBar = 4,	//! \brief 柱状图
		gtBar3D = 5,//! \brief 三维柱状图
		gtPie = 6,	//! \brief 饼图
		gtPie3D = 7,//! \brief 三维饼图
		gtRose = 8,	//! \brief 玫瑰图
		gtRose3D = 9, //! \brief 三维玫瑰图
		gtPyramidBar = 10,	  //! \brief  金字塔专题图-条形
		gtPyramidPolygon = 11,//! \brief  金字塔专题图-面形
		gtStackedBar = 12,		//! \brief 
		gtStackedBar3D = 13,	
		gtRing = 14,			//! \brief  环状
		
	};

	enum UGGraphTextFormat		//! \brief 统计图文本格式
	{
		gtfPercent = 1,			//! \brief 百分数
		gtfValue = 2,			//! \brief 真实数值
		gtfCaption = 3,			//! \brief 标题
		gtfCaptionPercent = 4,	//! \brief 标题+百分数	
		gtfCaptionValue = 5	//! \brief 标题+真实数值		
	};

	enum UGGraphDataValue		//! \brief 统计图数据
	{
		allPositive = 1,         //! \brief 全为正数
		allNegative= 2,			//! \brief 全为负值
		others = 3,			    //! \brief 都有
	};


public:
	UGGraph();
	virtual ~UGGraph();
	UGGraph(const UGGraph& Graph);	
	UGGraph& operator = (const UGGraph& Graph);	

public:
	//! \brief 关联到UGDrawing
	/*
	\remarks 由于文本避让的时候需要UGDrawing对象判断是否压盖，所以要先关联到UGDrawing对象
	*/
	UGbool AttachDrawing(UGDrawing* pDrawing);
	//! \brief 统计专题图转为几何对象
	/**
	\param pdValues			各段值[in]
	\param unValueCount		段个数[in]
	\param pntAnchorPoint	锚点[in]
	\param szGraph			图形大小[in]
	\param ItemValuesArray	多维数组[in]
	\return 返回转成的几何对象
	\remarks ItemValuesArray信息只会在柱状图多维数组时需要
	*/
	UGGeometry* ConvertToGeometry(UGdouble *pdValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));
	//! \brief 设置绘制参数
	void SetDrawParamaters(UGDrawParamaters *pDrawParam);

	//! \brief 统计图字段表达式操作函数
	//! \brief 清空所有段
	void RemoveAll();
	//! \brief 增加字段
	UGint Add(const UGString& strExpression);
	//! \brief 交换字段的位置
	UGbool Swap(UGint nOldIndex, UGint nNewIndex);
	//! \brief 删除某字段
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);

	//! \brief 获取字段个数
	UGint GetCount()const;
	//! \brief 设置字段个数
	void SetCount(UGint nItemCount);	


	//! \brief 获取某字段表达式
	UGString GetExpressionAt(UGint nIndex)const;
	//! \brief 设置某字段表达式
	void SetExpressionAt(UGint nIndex, const UGString& strExpression );

	//! \brief 获取某字段标题
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置某字段标题
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief 获取某字段风格
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief 设置某字段风格
	void SetStyleAt(UGint nIndex, const UGStyle& style);

	//! \brief 获取某字段风格数组，多维数组中用到
	const UGArray<UGStyle>& GetStyleArrayAt(UGint nIndex)const;
	//! \brief 设置某字段风格数组，多维数组中用到
	void SetStyleArrayAt(UGint nIndex, const UGArray<UGStyle>& styleArray);
	
	//! \brief 绘制统计图
	/**
	\param pDrawing			绘制类[in]
	\param pRecord			绘制的记录集[in]
	\param pValues			绘制值[in]
	\param unValueCount		值的个数[in]
	\param pntAnchorPoint	绘制的锚点[in]
	\param szGraph			绘制的大小[in]
	\param ItemValuesArray	柱状图多维数组的值[in]
	\return 返回转成的几何对象
	\remarks 绘制是否成功
	*/
	UGbool Draw(UGDrawing *pDrawing,UGRecordset* pRecord, UGdouble *pValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph,UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));

	//! \brief nGraphType 为统计图类型，其取值范围为enum Type的任意值
	void SetGraphType(UGint nGraphType);		
	//! \brief 得到统计图类型
	UGint GetGraphType()const;						
	
	//! \brief 设置柱状图宽度
	void SetBarWidth(UGint nBarWidth );
	//! \brief 得到柱状图宽度
	UGint GetBarWidth()const;

	//! \brief 得到默认颜色
	UGColor GetDefaultColor()const;
	//! \brief 设置默认颜色
	void SetDefaultColor(UGColor color);

	//! \brief 得到起始角度
	UGint GetStartAngle()const;
	//! \brief 设置起始角度
	void SetStartAngle(UGint nStartAngle);

	//! \brief 是否固定大小
	UGbool IsFixedSize()const;
	//! \brief 设置是否固定大小
	void SetFixedSize(UGbool bFixedSize = false);

	UGbool IsBarLie()const;
	void SetBarLie(UGbool bBarLie = false);

	//! \brief 判断是否画出坐标轴
	UGbool IsShowAxes()const;							
	//! \brief 设置是否画出坐标轴;
	void SetShowAxes(UGbool bShowAxes = true);			

	//! \brief  判断是否画出坐标轴文本
	UGbool IsShowAxesText()const;						
	//! \brief  设置是否画出坐标轴文本
	void SetShowAxesText(UGbool bShowAxesText = true);	
	//! \brief  得到坐标轴文本风格
	UGTextStyle GetAxesTextStyle()const;				
	//! \brief  设置坐标轴文本风格
	void SetAxesTextStyle(const UGTextStyle& TextStyle);
	
	//! \brief  得到画坐标轴时是否画出网格
	UGbool IsShowAxesGrid()const;					
	//! \brief  设置画坐标轴时是否画出网格
	void SetShowAxesGrid(UGbool bShowAxesGrid = false);
	
	//! \brief  得到字段文本风格
	UGbool IsShowItemText()const;						
	//! \brief  设置字段文本风格
	void SetShowItemText(UGbool bShowItemText = true);	

	//! \brief  得到字段文本风格
	UGTextStyle GetItemTextStyle()const;				
	//! \brief  设置字段文本风格
	void SetItemTextStyle(const UGTextStyle& TextStyle);

	//! \brief 得到文本格式
	UGint GetItemTextFormat()const;						
	//! \brief 设置文本格式
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
	\remarks 默认下不显示负值。
	\remarks 负值处理原则：（始终处理负值情况）对于面积图、阶梯图、折线图、点状图、柱状图、三维柱状图（含坐标轴）绘制按坐标轴方向，
	\remarks （用户选择是否处理）对于饼图、三维饼图、玫瑰图、三维玫瑰图、金字塔专题图-条形、金字塔专题图-面形，如果用户选择支持负值，负值按正值处理（参照Excel）；如果不支持负值，则不对其进行绘制
	*/
	void SetSupportNegative(UGbool bNegative = false);

	//! \brief 设置/返回是否显示牵引线 added by dongfei 2007-04-17
	void		SetAllowLeaderLine(UGbool bAllowLeaderLine){m_bAllowLeaderLine = bAllowLeaderLine;};
	UGbool		IsAllowLeaderLine()const {return m_bAllowLeaderLine;};
	//! \brief 设置/返回牵引线分割
	void		SetLeaderLineStyle(UGStyle & style){m_LeaderLineStyle = style;};
	UGStyle		GetLeaderLineStyle()const {return m_LeaderLineStyle;};
	void		SetTextOffset(UGdouble offsetX,UGdouble offsetY);
	void		SetTextOffset(UGSize2D size);
	UGSize2D	GetTextOffset()const {return m_szOffset;};
	//! \brief 读/写xml
	virtual UGString ToXML(UGint nVersion = 0)const;
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 设置避让缓冲距离
	void SetTextBuffer(UGSize2D& sz) {m_szBuffer = sz;};
	void SetTextBuffer(UGdouble dBufferX, UGdouble dBufferY) 
	{
		m_szBuffer.cx = dBufferX;
		m_szBuffer.cy = dBufferY;
	}
	UGSize2D	GetTextBuffer()const {return m_szBuffer;};

	//added by lugw 2007-05-09 鼠标响应的相关函数
	//! \brief 专题图鼠标响应
	/**
	\param pHitTestInfo    鼠标点击信息[in/out]
	\param pDrawing        绘制信息[in]
	\param pValues         绘制数据[in]
	\param unValueCount    绘制个数[in]
	\param pntAnchorPoint  绘制锚点[in]
	\param szGraph         绘制大小[in]
	\remarks 默认下不显示负值。
	*/
	UGbool HitTest(HitTestInfo* pHitTestInfo, UGDrawing *pDrawing, UGdouble *pValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph,UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));
	
	//! \brief 专题图子图形鼠标响应
	/**
	\param pHitTestInfo    鼠标点击信息[in/out]
	\param pDrawing        绘制信息[in]
	\param pValues         绘制数据[in]
	\param unValueCount    绘制个数[in]
	\param pntAnchorPoint  绘制锚点[in]
	\param szGraph         绘制大小[in]
	\remarks 默认下不显示负值。
	*/
	UGbool HitTestGeometry(HitTestInfo* pHitTestInfo ,UGdouble *pdValues, UGuint unValueCount, const UGPoint& pntAnchorPoint, const UGSize& szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0));

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

	//! \brief 得到玫瑰图形的设置角度
	UGint GetRoseAngle()const;
	//! \brief 设置玫瑰图形的角度
	void SetRoseAngle(UGint nRoseAngle);

	//! \brief 获取指定Item
	const UGGraphItem& GetItem(UGint nIndex)const;

	void Insert(const UGString& strExpression,UGint nIndex);


protected:
	UGRect GetBoundingRect(UGPoint pntGraph, UGSize szGraph);	//! \brief 统计图的外框
	UGRect GetCircleSize(UGSize szGraph);						//! \brief 饼图,玫瑰图的外框，比整个统计图的外框小一些.
	UGdouble GetThickness(UGSize szGraph, UGuint unItemCount);	//! \brief 统计图的宽度，比外框小一些

	void MaxMin(UGdouble *pValues, UGuint unItemCount);			//! \brief 计算统计数据的最大和最小值(m_minValue,m_maxValue)
	UGString GetItemString(UGdouble dValue, UGint nIndex);

	//! \brief  以下是绘制函数
protected:
	//! \brief  绘画坐标轴
	void DrawAxes(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph, UGuint unItemCount);
	void DrawAxes(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph);
	void DrawAxes3D(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph, UGuint unItemCount);
	void DrawAxes3D(UGDrawing *pDrawing, UGPoint pntAnchorPoint, UGSize szGraph);	

	//! \brief 显示各种专题图，统一参数说明：
	/*
	\param UGGraphics *pGraphics: 显示Graphics
	\param UGdouble *pValues 统计数据数组
	\param UGuint unItemCount: 统计数据数组长度
	\param UGPoint pntGraph : 统计图的定位点(中心点)
	\param UGSize szGraph : 统计图大小
	**
	*/
	UGbool DrawRose3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawRose(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPoint(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawLine(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawArea(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawStep(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	
	UGbool DrawBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawBar3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPie(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPie3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);

	//{{
	UGbool DrawPyramidBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawPyramidPoly(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);

	UGbool DrawStackBar(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGbool DrawStackBar3D(UGDrawing *pDrawing, UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	//}}

	//以下是转Geometry函数
protected:
	//转坐标轴为Geometry
	UGGeometry* AxesToGeometry(UGPoint pntAnchorPoint, UGSize szGraph, UGint unItemCount);
	UGGeometry* Axes3DToGeometry(UGPoint pntAnchorPoint, UGSize szGraph, UGint unItemCount);

	/*
	\param UGdouble *pValues 统计数据数组
	\param UGuint unItemCount: 统计数据数组长度
	\param UGPoint pntGraph : 统计图的定位点(中心点)
	\param UGSize szGraph : 统计图大小
	**
	*/
	UGGeometry* Rose3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph,HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* RoseToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph,HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PointToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* LineToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph);
	UGGeometry* AreaToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* StepToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	
	UGGeometry* BarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, UGArray<ItemValues*> ItemValuesArray = UGArray<ItemValues*>(0), HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* Bar3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PieToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* Pie3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);

	UGGeometry* PyramidBarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* PyramidPolyToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);

	UGGeometry* StackBarToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* StackBar3DToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	UGGeometry* RingToGeometry(UGdouble *pValues, UGuint unItemCount, UGPoint pntGraph, UGSize szGraph, HitTestInfo* pHitTestInfo = NULL);
	//! \brief 将牵引线添加到复合对象中
	/**	
	\param pCompound  待添加牵引线的复合对象
	\return	返回偏移后的点，即文字定位点	
	*/
	UGbool	 AddLeaderLine(UGGeoCompound * pCompound, UGPoint& pntFrom, UGPoint& pntTo);
	//! \brief 选取文本避让的位置
	/**	
	\param pOffset		待添加牵引线的复合对象
	\param pTheme		调用专题图计算文字偏移后的bounds
	\param pGeoText		待选取位置的文本
	\param pDrawing		调用该对象判断是否压盖
	\param szBuffer		文字压盖的缓冲距离
	\return	返回避让后的文字定位点	
	*/
	UGint SelectTextPos(const UGSize2D *pOffset, UGThemeGraph *pTheme, UGGeoText* pGeoText,UGSize2D szBuffer = UGSize2D(-1.0,-1.0));
protected:
	inline UGColor DarkColor(UGColor color, UGdouble dRatio);		//! \brief 把颜色变暗，
	UGint GetMinUnit(UGdouble& dUnit);							//! \brief  得到一个刻度单位的大小,返回多少个刻度单位，如果为0就不成功
	
//Attributes
protected:	
	UGArray<UGGraphItem> m_Items;
	UGint m_nType;					//! \brief  make type member var	
	
	UGint m_nStartAngle;			//! \brief  饼图和玫瑰图等的起始角度，默认为0(0.1度)
	UGint m_nBarWidth;				//! \brief  柱状图的柱宽（逻辑坐标）
	UGColor m_DefaultColor;			//! \brief  默认的颜色
	UGint m_TextFormat;				//! \brief  文本格式		
	UGuint m_unOptions;				//! \brief  各种选项

//! \brief  以下为临时使用数据
protected:	
	UGDrawParamaters* m_pDrawParam; //! \brief  地图显示参数,为了计算文本显示大小
	UGTextStyle m_ItemTextStyle;	//! \brief  每个子项的文本风格
	UGTextStyle m_ThemeTextStyle;	//! \brief  整个统计图的文本风格	
	UGdouble m_dMinValue;			//! \brief 统计数据的最小值
	UGdouble m_dMaxValue;			//! \brief 统计数据的最大值
	UGdouble m_dSum;				//! \brief 统计数据的总和
	//! \brief added by lugw 以下三个变量在支持负值的绘制情况下需要用到，记录数据的最大最小值,此时上面的最大最小值为其绝对值的最大最小值
	UGint m_bNegative;
	UGdouble m_dMinValueN;           //! \brief 统计数据的最小值
	UGdouble m_dMaxValueN;           //! \brief 统计数据的最大值
	
	UGbool   m_bAllowLeaderLine;	 //! \brief 是否显示牵引线 added by dongfei 2007-04-17
	UGSize2D m_szOffset;			 //! \brief 文本的偏移量
	UGStyle  m_LeaderLineStyle;		 //! \brief 牵引线风格
	UGSize2D m_szBuffer;			 //! \brief 避让缓冲范围

	UGDrawing* m_pDrawing;			//! \brief 用于判断是否压盖 

	UGint m_nRoseAngle;
	UGRecordset* m_pRecordet;
};

}

#endif // !defined(AFX_UGGRAPH_H__CF2642C9_F414_4403_BA26_CE72B9E54AAB__INCLUDED_)

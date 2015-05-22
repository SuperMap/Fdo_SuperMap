// UGLayer.h: interface for the UGLayer class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayer.h 
   **************************************************************************************
    \author   陈国雄
    \brief    图层类，负责数据集对象显示和专题图显示。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)
#define AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_

#include "Drawing/UGDrawing.h"
#include "Engine/UGDataSource.h"
#include "UGThemeUnique.h"
#include "UGThemeRange.h"
#include "UGThemeLabel.h"
#include "UGThemeGraph.h"
#include "UGThemeCustom.h"
#include "UGThemeDotDensity.h"
#include "UGThemeGraduatedSymbol.h"
#include "UGThemeGridUnique.h"
#include "UGThemeGridRange.h"
#include "UGThemes.h"
#include "UGSelection.h"
#include "Geometry/UGTINBlock.h"

#include "Base/UGList.h"

namespace UGC {

class UGProgress;
class UGLayers;

//! \brief AfterGeometryDraw 事件回调函数
typedef void (UGSTDCALL *AfterGeometryDrawProc)(UGlong pWnd,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);
//! \brief BeforeGeometryDraw 事件回调函数
typedef void (UGSTDCALL *BeforeGeometryDrawProc)(UGlong pWnd,UGbool& bCancel,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);

typedef UGArray<UGbyte> UGbyteArray;

enum UGLayerOptions
{
	UG_LO_VISIBLE						=	0x00000001,	//是否显示
	UG_LO_SELECTABLE					=	0x00000002,	//是否可选择
	UG_LO_EDITABLE						=	0x00000004,	//是否可编辑
	UG_LO_SNAPABLE						=	0x00000008,	//是否可捕捉
	UG_LO_SYMBOL_SCALABLE				=	0x00000010,	//是否缩放符号
	UG_LO_LINE_ADJUST   				=	0x00000100,	//是否完整显示线型虚实部
	UG_LO_KEEP_ORDER					=	0x00000020,	//是否在显示的时候按ID排序,只对SDX引擎数据有效(SDB,DGN已经默认按照ID排序)
	UG_LO_IS_3D							=	0x00000040,	//是否在3D窗口中立体显示，如果立体显示，就需要设定高度字段 m_strHeightField
	UG_LO_IS_MODIFIED					=   0x00000080, //是否已经修改，是否需要保存

	UG_LO_DATABASE_MODE					=	0x00040000, //是否是数据库引擎数据，与SDB相对应
	UG_LO_SPATIAL_DB_MODE				=	0x00080000, //是否是SuperMap的数据库引擎
	UG_LO_NEED_CK_GEO_BOUND				=	0x00100000,	//是否在显示的时候需要检查bounds
	
	UG_LO_EDITABLE_LOCK					=   0x00200000, //编辑锁定
	UG_LO_IS_VIRTUAL					=   0x01000000, //是否是虚拟图层 
	UG_LO_USE_LAYER_CACHE				=   0x02000000, //false:不需要图层缓存，true：需要图层缓存
	UG_LO_CACHE_NEED_REFRESH			=   0x04000000, //图层缓存是否需要刷新
	UG_LO_ALLOW_TEXT_OVERLAP			=	0x10000000,	//是否允许显示重叠文本
	UG_LO_IS_ORDER_OVERLAP		    	=   0x20000000,	//是否定制图层内的对象压盖顺序 added by dongfei 2007-04-27

	UG_LO_IS_DISPLAYCLIP				=   0x40000000, //是否使用显示裁剪区域
	UG_LO_CROSSROAD_OPTIMIZED			=   0x80000000, //是否使用道路优化显示
};

struct ScaleStyle
{	
	UGdouble dMinScale;
	UGdouble dMaxScale;
	UGStyle  style;
} ;

class MAP_API UGLayer  
{
public:
	enum UGLayerType
	{
		UG_Layer_Normal                     = 1,//普通图层
		UG_Layer_NetworkLine                = 2,//网络线层
		UG_Layer_NetworkPoint               = 3,//网络点层
		UG_Layer_TopoParent                 = 4,//拓扑错误父层
		UG_Layer_TopoLayer                  = 5,//拓扑错误数据层
		UG_Layer_TopoPointError             = 6,//拓扑错误点层
		UG_Layer_TopoPointException         = 7,//拓扑错误点层
		UG_Layer_TopoLineError              = 8,//拓扑错误线层
		UG_Layer_TopoLineException          = 9,//拓扑错误线层
		UG_Layer_TopoRegionError            = 10,//拓扑错误面层
		UG_Layer_TopoRegionException        = 11,//拓扑错误面层
		UG_Layer_TopoDirty                  = 12,//拓扑脏区，暂没使用
		//修改后不再有子层的类型
		//UG_Layer_Child                      = 13,//子层
	};
	


public:
	UGLayer();
	virtual ~UGLayer();
	UGLayer(const UGLayer& layer);	
	UGLayer& operator =(const UGLayer& layer);	

public:	
	//*********属性Options***********//
	//! \brief 某中选项是否可用
	UGbool Enable(UGuint unOptions);
	//! \brief 是否设置某中选择
	UGbool IsSupportOptions(UGuint unOptions);
	//! \brief 设置使用某中选择
	virtual void SetOptions(UGuint unOptions);
	//! \brief 设置禁用某中选择
	virtual void UnsetOptions(UGuint unOptions);	
	//! \brief 得到图层选择设置的信息
	UGuint GetOptionsInfo();
	//! \brief 设置图层选择的信息
	void SetOptionsInfo(UGuint unOptions);

	//! \brief 是否显示
	UGbool IsVisible()const;
	//! \brief 设置为可显示
	void SetVisible(UGbool bVisible = true);

	//! \brief 是否可以选择
	UGbool IsSelectable()const;	
	//! \brief 设置为可选择
	void SetSelectable(UGbool bSelectable = true);			

	//! \brief 是否可以编辑
	UGbool IsEditable()const;
	//! \brief  设置是否可以编辑
	/**
	\remarks 这个最好内部使用，外部就调用UGLayers::SetEditableLayer，added by xielin 2007.8.9
	*/
	void SetEditable(UGbool bEditable = true);

	//! \brief 是否可以捕捉
	UGbool IsSnapable()const;									// 是否可以捕捉
	//! \brief 设置为可捕捉
	void SetSnapable(UGbool bSnapable = true);				// 

	//! \brief 是否锁定编辑
	UGbool IsEditableLock()const;
	//! \brief 设置锁定编辑
	void SetEditableLock(UGbool bEditableLock = true);   

	//! \brief 是否符号随着图层的缩放而缩放
	UGbool IsSymbolScalable()const;
	//! \brief 设置符号可缩放
	void SetSymbolScalable(UGbool bSymbolScalable = true);

	//! \brief 线型绘制时是否完整显示虚实部。
	/**
	得到是否完整显示虚实部。
	\return 是否完整显示虚实部，1代表是，0代表否，默认为1。
	*/
	UGbool IsLineAdjust() const;
	//! \brief 线型绘制时设置完整显示虚实部。
	/**
	设定是否完整显示虚实部，在放大缩小时都能完整显示线型。
	\param bFixed  是否完整显示虚实部[in]
	\remarks 默认下绘制线型会采用此方法。
	*/
	void SetLineAdjust(UGbool bLineAdjust = true);

	//! \brief 是否对象显示时候按照ID排序
	UGbool IsKeepOrder()const;	
	//! \brief 设置对象显示时候是否按ID排序
	void SetKeepOrder(UGbool bKeepOrder = true);		

	//! \brief 是否设置文本叠盖
	UGbool IsAllowTextOverlap()const;							
	//! \brief 设置文本叠盖
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = true);

	//! \brief 本图层的设置是否修改过
	UGbool IsModified()const;		
	//! \brief 设置图层修改标志
	void SetModifiedFlag(UGbool bModified = true);

	//! \brief 返回是否允许图层缓冲区
	UGbool IsAllowCache()const;		
	//! \brief 设置是否允许图层缓冲区
	void SetAllowCache(UGbool bCache = true);				
	
	//! \brief 取得图层刷新标记
	UGbool GetRefreshFlag()const;								
	//! \brief 设置图层刷新标志，强制刷新图层
	void SetRefreshFlag(UGbool bRefresh = true);			
	
	//! \brief 图层的缓冲区是否可用
	UGbool IsCacheAvailable()const;						
	//*********显示属性Options***********//

	//! \brief 得到栅格不透明度
	UGint GetRasterOpaqueRate()const;					
	//! \brief 设置栅格不透明度
	void SetRasterOpaqueRate(UGint nRasterOpaqueRate);		
	
	//! \brief 设置图层风格
	void SetStyle(const UGStyle& style);
	//! \brief 得到栅格不透明度
	const UGStyle& GetStyle()const;

	//! \brief 得到图层查询语句
	const UGQueryDef& GetQueryDef()const;
	//! \brief 得到图层查询语句
	/**
	\param QueryDef  查询语句[in\out]
	*/
	void GetQueryDef(UGQueryDef& QueryDef)const;	
	//! \brief 设置图层查询语句
	void SetQueryDef(UGQueryDef& QueryDef);
	//! \brief 返回数据集的维数，如点是0维，线是1维，面是2维，其他返回-1
	UGint GetDimension()const;								
	
	//! \brief 检查制作专题图的条件是否合法
	/**
	\param strExpression   字段表达式[in]
	\remarks 条件查询出来的属性值类型,如果失败,返回0
	*/
	UGint CheckThemeExpression(const UGString& strExpression);
	//! \brief 重新计算Bounds
	UGRect2D RecalcBounds(UGDrawParamaters *pDrawParam, UGbool bComputeDatasetBounds = false);

	//! \brief 导成XML信息
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief 读取XML信息
	UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief 得到父层,如果没有则为空
	UGLayer* GetParentLayer()const;
	//! \brief 如果是网络图层，返回节点图层
	UGLayer* GetChildLayer()const;						

	//! \brief 设置父层,如果没有则为空
	void SetParentLayer(UGLayer* pLayer);
	//! \brief 如果是网络图层，设置节点图层
	void SetChildLayer(UGLayer* pLayer);								
	
//	UGString GetName()const;										// 图层名

	//! \brief  设置描述信息
	void SetDescription(const UGString&  strDescription);		
	//! \brief 获取图层描述信息
	UGString GetDescription()const;								

	//! \brief 设置数据集名称
	void SetDatasetName(const UGString&  strDatasetName);		
	//! \brief 获取数据集名称
	UGString GetDatasetName()const;								

	//! \brief 设置数据源别名
	void SetDataSourceAlias(const UGString& strDataSourceAlias);	
	//! \brief 获取数据源别名
	UGString GetDataSourceAlias()const;								

	//! \brief 设置图层标题
	void SetCaption(const UGString&  strCaption);		
	//! \brief 获取图层标题
	UGString GetCaption()const;								

	//! \brief 获取图层最大比例尺
	UGdouble GetVisibleScaleMax()const;
	//! \brief 获取图层最小比例尺
	UGdouble GetVisibleScaleMin()const;
	//! \brief 设置图层最大比例尺
	void SetVisibleScaleMax(UGdouble dVisibleScaleMax);
	//! \brief 取消图层最大比例尺
	void CancelVisibleScaleMax();
	//! \brief 设置图层最小比例尺
	void SetVisibleScaleMin(UGdouble dVisibleScaleMin);
	//! \brief 取消图层最小比例尺
	void CancelVisibleScaleMin();

	//! \brief 重新设置图层信息
	void Reset();	

	//! \brief 添加图层不可显示的Geometry的ID
	void AddInvisibleGeoID(UGint nID);
	//! \brief 清空图层不可显示的Geometry的IDs
	void ClearInvisibleGeoIDs();
	
	//! \brief 清除显示用的记录集
	void ClearDisplayRecordset();						
	//! \brief 释放所有记录集，在关闭数据集和修改数据集子段结构之前必须调用
	void ClearRecordsets();									
	//! \brief 清除编辑用的记录集	
	void ClearEditRecordset();								
	//! \brief 准备显示用的记录集,UGQueryDef *pQueryDef是编辑纪录集查询参数定义
	void PrepareEditRecordset(UGQueryDef *pQueryDef = NULL);
	//! \brief 设置编辑用的记录集
	void SetEditRecordset(UGRecordset *pEditRecordset);
	//! \brief 得到编辑用的记录集
	UGRecordset* GetEditRecordset() const;
	//! \brief 得到显示用的记录集
	UGRecordset* GetDisplayRecordset() const;

	//! \brief 与数据集建立关联
	void SetDataset(UGDataset *pDataset, UGbool bInit = true);
	//! \brief 获取当前联接的数据集	
	UGDataset* GetDataset()const;	

	//! \brief 判断当前比例尺下是否需要显示图层(使用：m_dVisibleScaleMax和m_dVisibleScaleMin判断)
	UGbool IsVisibleScale(UGdouble dScale)const;
	//! \brief 点击图层事件
	/**
	\param pntHitTest           鼠标响应点，地理坐标[in]
	\param dTolerance           点击容限[in]
	\param Selection            [in]
	\param nByPassCount         [in]
	\param pDrawing             绘制类[in]
	\return                     点击成功返回true，反之为false
	*/
	virtual UGbool HitTest(const UGPoint2D& pntHitTest, UGdouble dTolerance, UGSelection &Selection, UGint &nByPassCount, UGDrawing *pDrawing);
	//! \brief 计算符号的大小
	/**
	\param dScale           比例尺[in]
	\return                 符号缩放的比例
	*/
	UGdouble CalculateSymbolScale(UGdouble dScale)const;

	//! \brief 得到系统比例尺
	UGdouble GetSymScaleDefinition() const;
	//! \brief 设置系统比例尺
	void SetSymScaleDefinition(UGdouble dSymScaleDefinition);
	
	//! \brief 获取填充原点的模式
	UGint GetFillOrgMode() const;				
	//! \brief 设置填充原点模式
	void SetFillOrgMode(UGint nFillOrgMode);		
	
	//! \brief 获取最小显示大小
	UGdouble GetMinimumVisible() const;				
	//! \brief 设置最小显示大小
	void SetMinimumVisible(UGdouble dMinimumVisible);	

	//! \brief 绘制图层
	/**
	\param pGraphics			绘制到的Graphics[in]
	\param pDrawing				绘制类[in]
	\param pRecordSet           绘制的记录集[in]
	\param bSingle              记录集是否自由该图层自己使用[in]
	\return                     绘制成功返回true，反之为false
	*/
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordset* pRecordSet, UGbool bSingle = false,UGProgress* pProgress = NULL);

	//! \brief 转换专题图为复合数据集
	UGbool ConvertThemeToDataset(UGDrawing* pDrawing, UGDatasetVector *pDatasetCAD, UGbool bProgress = true);
	//added by xielin 2007-04-13
	//! \brief 返回图层中的选择集 
	UGSelection* GetSelection();

	//added by lugw 2007-04-12
	//! \brief  计算分段数组
	/**
	\param pntHitTest           鼠标响应点，地理坐标[in]
	\param pThemeLabel          所选标签专题图[in]
	\param pGraphics            pDrawing类中对应的pGraphics[in]
	\param pDrawing             绘制信息[in]
	\param geoTextArray         选中标签的字段标签信息[in/out]
	\param strFieldExpression   所需查询的字段表达式，默认为空
	\return                     成功返回true，反之为false
	\remarks                    对于查询后的geoTextArray，如果用户只需要得到选中标签的字段信息，则此数组将每个标签的信息以GeoText的形式输出，如果字段表达式不为空而且表达式正确，则数组按照：【符合条件的标签信息＋该标签的字段表达式的值】的形式输出所有在此Bounds下的标签。
	*/
	UGbool HitTestThemeLable(const UGPoint2D& pntHitTest,/*UGThemeLabel* pThemeLabel,*/UGGraphics* pGraphics, UGDrawing *pDrawing,UGArray<UGGeoText>& geoTextArray,UGString strFieldExpression = (""));

	//! \brief 点击Tin图层事件
	/**
	\param pntHitTest           鼠标响应点，地理坐标[in]
	\param dTolerance           点击容限[in]
	\param triInfo				返回Tin三角网信息[in\out]
	\param pDrawing             绘制类[in]
	\return                     点击成功返回true，反之为false
	*/
	UGbool HitTestTinBlock(const UGPoint2D& pntHitTest,UGdouble dTolerance, TriInfo& triInfo, UGDrawing *pDrawing);
	
	//added by dongfei 2007-04-24 
	//! \brief 设置/返回 图层名
	void SetName(UGString strLayerName);
	UGString GetName()const {return m_strName;};
	//! \brief 设置/返回特定比例尺下图层风格
	void SetStyle(UGdouble dMinScale,UGdouble dMaxScale,const UGStyle& style);
	const UGStyle GetStyle(UGdouble dScale);
	//! \brief 删除所有非默认风格(保留默认)
	void RemoveAllStyle();
	//! \brief 获取风格个数(不包括默认风格)
	UGint GetStyleCount()const {return m_scaleStyle.GetSize();};
	//! \brief 获取所有指定比例尺下风格
	void GetScalStyle(UGArray<ScaleStyle>& styles){styles = m_scaleStyle;};
	//! \brief 设置/获取查询排序字段,该接口主要用于调整同一个图层几何对象的叠盖关系，该字段最好设置为自动增长字段
	UGbool SetOrderField(UGString strField);
	//! \brief 设置/获得是否按某一字段(非SmID)顺序查询
	UGString GetOrderField();
	//! \brief 把给定ID号的对象放到最前面
	UGbool BringToFront(UGlong nID);
	//! \brief 把给定ID号的对象放到最后面
	UGbool SendToBack(UGlong nID);
	//! \brief 设置图层压盖处理
	void SetOrderOverlap(UGbool bOrderOverlap = true);
	//! \brief 是否对图层压盖处理
	UGbool IsOrderOverlap();
	
	//! \brief 几何对象是否可见
	/**
	\param pGeometry             几何对象[in]
	\param dMinimumVisible       最小显示比例尺[in]
	\return                      可见返回true，反之为false
	*/
	UGbool IsGeometryVisible(UGGeometry *pGeometry, UGdouble dMinimumVisible)const;

	//! \brief 几何对象是否可见
	/**
	\param pGraphics            绘制到的Graphics[in]
	\param pDrawing				绘制类[in]
	\param querfdef				得到的查询语句[in]
	\return                     成功返回true，反之为false
	*/
	UGbool PrepareQueryDef(UGGraphics* pGraphics, UGDrawing* pDrawing, UGQueryDef*& querfdef);

	//added by lugw 2007-06-05 
	//! \brief 得到图层类型
	UGint GetType();
	//! \brief 设置图层类型
	void SetType(UGint nType);

	//! \brief 设置父图层名称
	void SetParentDsName(UGString strName);
	//! \brief 得到父图层名称
	UGString GetParentDsName();

	//! \brief 几何对象绘制完后的回调函数
	void SetAfterGeometryDrawFunc(AfterGeometryDrawProc pAfterGeometryDrawFunc,UGlong pWnd);
	//! \brief 几何对象绘制前的回调函数
	void SetBeforeGeometryDrawFunc(BeforeGeometryDrawProc pBeforeGeometryDrawFunc,UGlong pWnd);
	void SendAfterGeometryDrawFunc(UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);
	void SendBeforeGeometryDrawFunc(UGbool& bCancel,UGString strLayerName,UGint nGeometryID,UGGraphics* pGraphics);

	//! \brief 得到栅格不透明度
	UGint GetOpaqueRate();	
	//! \brief 设置栅格不透明度
	void SetOpaqueRate(UGint nOpaqueRate);	
	
	//! \brief 得到亮度
	UGint GetBrightness();
	//! \brief 设置亮度
	void SetBrightness(UGint nBrightness);

	//! \brief 得到对比度
	UGint GetContrast();
	//! \brief 设置对比度
	void SetContrast(UGint nContrast);

	//! \brief 是否背景透明
	UGbool IsRasterBackTransparent() const;
	//! \brief 设置是否背景透明
	void SetRasterBackTransparent(UGbool bBackTransparent);

	//! \brief 得到背景颜色容限
	UGbyte GetRasterBackColorTolerance() const;
	//! \brief 设置背景颜色容限
	void SetRasterBackColorTolerance(UGbyte nBackColorTolerance);

	//! \brief 得到栅格背景色
	UGColor GetImageBackColor() const;
	//! \brief 设置栅格背景色
	void SetImageBackColor(UGColor crBack);

	//! \brief 得到无值风格
	UGColor GetGridNoDataColor() const;
	//! \brief 设置无值风格
	void SetGridNoDataColor(UGColor crNoDataColor);
	
	//! \brief 得到设置是否使用显示裁剪区域
	UGbool IsDisplayClip() const;							
	//! \brief 得到是否使用显示裁剪区域
	void SetDisplayClip(UGbool bIsDisplayClip);		

	//! \brief 是否优化十字路口
	UGbool IsCrossroadOptimized()const;
	//! \brief 设置是否优化十字路口
	void SetCrossroadOptimized(UGbool bIsCrossroadOptimized);
	//! \brief 内部调用函数
	void SetLayers(UGLayers *pLayers);

	//! \brief 获取网络数据集所有图层
	UGbool GetWebSubLayers(UGArray<UGString>& aryLayerNames) const;
	//! \brief 设置网络数据集所有图层是否可见属性
	void SetWebSubLayersVisble(const UGbyteArray& arrLayersVisible);
	//! \brief 得到网络数据集所有图层是否可见属性
	void GetWebSubLayersVisble(UGbyteArray& arrLayersVisible) const;

	UGColorTable m_ColorsetTable;

protected:
	UGbool OnDrawRaster(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawVector(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	UGbool OnDrawThemeNone(UGDrawing *pDrawing,UGProgress* pProgress = NULL);	
	UGbool OnDrawThemeStyle(UGThemeStyle* pThemeStyle, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeGraph(UGThemeGraph* pThemeGraph, UGDrawing *pDrawing,UGProgress* pProgress = NULL);	
	UGbool OnDrawThemeGraduatedSymbol(UGThemeGraduatedSymbol* pThemeGraduatedSymbol, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeDotDensity(UGThemeDotDensity* pThemeDotDensity, UGDrawing *pDrawing,UGProgress* pProgress = NULL);
	UGbool OnDrawThemeLabel(UGThemeLabel* pThemeLabel, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	UGbool OnDrawThemeNoneCrossroad(UGDrawing *pDrawing);

	UGbool OnDrawStyleThemeCrossroad(UGThemeUnique *pThemeUnique, UGDrawing *pDrawing);

	UGbool IsCancelByUser(UGDrawing *pDrawing) const; 
	UGbool IsVisibleByGeoID(const UGint& nID)const;

	UGbool ThemeStyleToDataset(UGThemeStyle *pThemeStyle, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeDotDensityToDataset(UGThemeDotDensity *pThemeDotDensity, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraphToDataset(UGThemeGraph *pThemeGraph, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeGraduatedSymbolToDataset(UGThemeGraduatedSymbol *pThemeGraduatedSymbol, UGRecordset *pRecordset, UGDrawParamaters *pDrawParam, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGbool ThemeLabelToDataset(UGThemeLabel *pThemeLabel, UGRecordset *pRecordset, UGDrawing *pDrawing, UGDatasetVector *pDatasetCAD, UGProgress *pProgress = NULL);
	UGGeometry* ThemeLabelBackToGeometry(UGThemeLabel *pThemeLabel, UGGeoText* pGeoText, UGDrawParamaters *pDrawParam,const UGPoint2D& pntObjCenter);
	UGGeometry* LabelBoundsToGeometry(const UGRect2D& rcBounds, const UGPoint2D& pntCentroid, UGdouble dAngle, UGint nLabelBackType, const UGStyle& backStyle,  UGDrawParamaters *pDrawParam);
	//added by dongfei 2007-04-23
	//! \brief 计算牵引线对象，这个对象用于和需要牵引线的对象求交
	/*
	\param rect			需要牵引线对象的外接矩形
	\param pntFrom      牵引线起始点  
	\param pntAnchor		旋转基点
	\param dAngle	          旋转角度
	\return				牵引现对象 为起始点和矩形中心点附近两点围成的等腰三角形		
	\remarks			需要外部释放返回的region			
	*/	
	UGGeoRegion* GetLeaderObject(const UGRect2D& rect,const UGPoint2D& pntFrom, const UGPoint2D& pntAnchor, UGdouble dAngle);

	
public:	
	UGThemes m_Themes;

	UGTheme* m_pTheme;
	//added by xielin 2007-04-13
	//! \brief 多图层编辑模式下，每个Layer都有一个selection 
	UGSelection m_Selection;  
	
	//! \brief 图层是否能绘制的变量，这个变量用来控制该图层是否可以绘制
	//以后绘制图层，判断visible为true，并且该变量为true，这样设计的原因是
	//因为sfc中的图层如果有单值专题图，读取到ugc中分层，但是为了优化，就要设置原始
	//图层的visible为false，但是这样就导致保存工作空间的时候图层状态就错了
	//(获取hashcode的时候也错了），所以就增加该变量，专门用来控制，而不去改变图层的可见状态
	//UGbool m_bCanDraw;
	UGArray<UGint> m_arrInvisibleGeoIDs;   // 图层中不可见的几何对象的ID--Add by litao,2001/8/3
protected:
	//! \brief 以0.1mm为单位
	UGint m_nMinimumVisible;
	
	UGRecordset *m_pDisplayRecordset;	
	UGRecordset *m_pEditRecordset;		
	UGStyle m_Style;					// 图层显示风格
public:
	UGQueryDef m_QueryDef;
protected:	
	UGString m_strDescription;			// 图层描述
	UGString m_strCaption;				// caption for this layer
	UGString m_strDataSourceAlias;		// 保存该图层的数据集所在的数据源别名
	UGString m_strDatasetName;

	UGdouble m_dVisibleScaleMax;		// 当地图比例尺大于该值的时候，本图层不显示，若该值等于0，则该限制无效。默认为0
	UGdouble m_dVisibleScaleMin;		// 当地图比例尺小于该值的时候，本图层不显示，若该值等于0，则该限制无效。默认为0
	UGdouble m_dSymScaleDefinition;		// 如果地图的符号随着图层缩放而缩放，当地图比例尺等于该值的时候，图层的符号按geoStyle的符号大小显示

	UGLayer* m_pParentLayer;
	UGLayer* m_pChildLayer;
	UGDataset *m_pDataset;
	UGuint m_unOptions;

	UGint m_nFillOrgMode;					// 画刷原点模式
	UGbool m_bSingle;
	UGint m_nType;
	UGString m_strParentDsName;
	
	
	
	//added by dongfei 2007-04-24
	//! \brief 图层名 不一定是“数据集@数据源”了
	UGString m_strName;
	//! \brief 不同比例尺下的风格
	UGArray<ScaleStyle> m_scaleStyle;
	UGString m_strOrderField;
	
	UGchar m_btBrightness;	// 栅格图层亮度，值域范围为-100到100，增加亮度为正，降低亮度为负
	UGchar m_btContrast;		// 栅格图层对比度，值域范围为-100到100，增强对比度为正，减弱对比度为负
	UGbyte m_btOpaqueRate;			// 不透明度0----100% 100为不透明，0为完全透明，只对栅格数据集有效

	UGColor m_ImageBackColor;  // 栅格背景色。
	UGColor m_GridNoDataStyle; // 无值风格。
	UGbool m_bRasterBackTransparent; // 背景透明。
	UGbyte m_btBackColorTolerance; // 背景颜色容限

	AfterGeometryDrawProc m_pAfterGeometryDrawFunc;
	BeforeGeometryDrawProc m_pBeforeGeometryDrawFunc;

	UGlong m_pEventView;  //调用事件回调函数的对象指针，统一为一个吧，节省内存
	//added by xielin 2007-09-29 记录所在的图层集合，用于修改图层的锁定编辑状态，
	//通过Layers中回调函数通知相应的模块
	UGLayers* m_pLayers; 

	UGbyteArray m_arrWebLayersVisible;
};

}

#endif // !defined(AFX_UGLAYER_H__A4B430F7_6A63_4275_BB13_EF15BA12DDAD__INCLUDED_)

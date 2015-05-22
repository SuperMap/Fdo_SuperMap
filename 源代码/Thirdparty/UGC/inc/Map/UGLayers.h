// UGLayers.h: interface for the UGLayers class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayers.h
   **************************************************************************************
    \author   陈国雄
    \brief    图层集合类，负责图层的管理。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_)
#define AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_

#include "UGLayer.h"
#include "Workspace/UGWorkspace.h"
#include "Map/UGLayersRecordsetsManager.h"

namespace UGC {
//added by xielin 
//! \brief 图层绘制的报告，目前包括绘制之前的查询时间，绘制时间，绘制对象数,栅格数据查询时间就为0，全部算到绘制时间中,以毫秒为单位
struct LayerDrawReport
{
	UGint nQueryTime;
	UGint nDrawTime;
	UGint nGeometryCount;
	LayerDrawReport()
	{
		nQueryTime = 0;
		nDrawTime = 0;
		nGeometryCount = 0;
	}
};

typedef void (*LayersModifiedProc)(UGLayer* pLayer, UGuint nModifyLayerFlag, UGlong pData);
//! \brief BeforeLayerDraw 事件回调函数
typedef void (UGSTDCALL *BeforeLayerDrawProc)(UGlong pWnd,UGbool& bCancel,UGint nLayerIndex,UGGraphics* pGraphics);
//! \brief AfterLayerDraw 事件回调函数
typedef void (UGSTDCALL *AfterLayerDrawProc)(UGlong pWnd,UGint nLayerIndex,UGGraphics* pGraphics,LayerDrawReport& layerDrawReport);

struct LayersForSaveSFC 
{
	UGLayer* pLayer;
	UGbool bDel;
	LayersForSaveSFC()
	{
		pLayer = NULL;
		bDel = false;
	}
};



class MAP_API UGLayers  
{
	friend class UGMap;
	friend class UGLayer;
public:
	//! 修改图层标识
	enum UGModifyLayerFlag	
	{
		mlAddLayer,					//! 添加图层
		mlDeleteLayer,				//! 删除图层
		mlChangeEditLayer,			//! 可编辑图层改变
		mlChangeEditableLock		//! 图层编辑锁定改变
	};

public:
	UGLayers();
	virtual ~UGLayers();
	UGLayers(const UGLayers &Layers);
	UGLayers& operator =(const UGLayers &Layers);

public:
	//!brief 设置绘制参数
	void SetDrawParam(UGDrawParamaters *pDrawParam);
	//!brief 绘制图层
	UGbool OnDraw(UGGraphics* pGraphics, UGDrawing *pDrawing,UGProgress* pProgress = NULL);

	//!brief 更改图层中数据集名称
	/**
	\param strOldName    原数据集名称[in]
	\param strNewName    修改的数据集名称[in]
	\remarks 是否有修改
	*/
	UGbool OnDatasetNameChanged(const UGString &strOldName, const UGString &strNewName);
	//!brief 更改图层中数据源别名名称
	/**
	\param strOldAlias    原数据源别名[in]
	\param strNewAlias    修改的数据源别名[in]
	\remarks 是否有修改
	*/
	UGbool OnDataSourceAliasChanged(const UGString &strOldAlias, const UGString &strNewAlias);

	//!brief 将图层中指定数据源别名的数据集设置为空
	/**
	\param strDataSourceAlias    原数据源别名[in]
	*/
	void OnDataSourceClose(const UGString &strDataSourceAlias);
	//!brief 将图层中指定数据源别名的数据集打开
	/**
	\param strDataSourceAlias    指定图层数据源别名[in]
	\param pDataSource			 指定的数据源[in]
	*/
	void OnDataSourceOpen(const UGString &strDataSourceAlias,UGDataSource* pDataSource);

	//!brief  是否有图层修改
	UGbool IsModified()const;
	//!brief  设置图层修改标志
	void SetModifiedFlag(UGbool bModified = true);	

	//!brief  指定图层是否存在
	UGbool IsLayerExisted(const UGString &strName)const;
	//!brief  指定图层是否存在
	UGbool IsLayerExisted(UGLayer *pLayer)const;
	//!brief  计算图层的范围
	UGRect2D ComputeBounds(UGbool bComputeDatasetBounds = false);
	//!brief  得到图层的范围
	UGRect2D GetBounds()const;

	//!brief  设置图层为可编辑
	//modified by xielin 2007-8-9 加一个参数，可以设置图层编辑状态为false
	UGbool SetEditableLayer(UGint nIndex,UGbool bEditable = true);
	//!brief  得到指定图层名的索引
	UGint GetLayerIndex(const UGString &strName) const;
	//modified by dongfei 2007-04-24 改为返回图层数目，并修改传入的图层数组
	//!brief  得到指定图层数据集的所有图层
	/**
	\param pDataset		指定数据集[in]
	\param layersArr    符合条件的图层数组[in/out]
	\remarks 符合的图层数目
	*/
	UGint FindLayerWithDataset(UGDataset *pDataset,UGArray<UGLayer*>& layersArr) const;
	//!brief  得到指定图层索引
	/**
	\param pLayer		指定图层[in]
	\remarks 图层索引
	*/
	UGint FindLayer(UGLayer *pLayer) const;

	//!brief  得到图层个数
	UGint GetCount()const;
	//!brief  清空所有图层
	void Clear();
	//modified by dongfei 2004-04-24 增加一个默认参数参如图层名	
	//modified by xielin 2007-7-26 数据源别名就不传入了，自己从数据集取吧
	//!brief  添加图层
	/**
	\param pDataset			指定数据集[in]
	\param bAddToHead		是否置顶[in]
	\param nType			图层类型[in]
	\param strLayerName		图层名[in]
	\param pTheme			图层的专题图[in]
	\remarks 创建的该图层
	*/
	UGLayer* AddDataset(UGDataset *pDataset,UGbool bAddToHead = true,UGint nType = UGLayer::UG_Layer_Normal,UGString strLayerName = "",UGTheme *pTheme = NULL);
//	UGLayer *AddDataset(UGDatasetVector *pDatasetV, const UGEventProperty& RouteEvent, UGbool bAddToHead = TRUE);
	//!brief  删除指定图层
	UGint RemoveAt(UGint nIndex, UGint nCount = 1, UGbool bComputeBounds = true);
	//!brief  删除所有图层
	void RemoveAll();

	//modified by xielin 2007-05-16 引入多图层编辑，修改返回的可编辑图层为一个List
	//!brief  获取编辑图层对了
	UGList<UGLayer*> GetEditableLayer()const;
	//!brief  获取指定索引图层
	UGLayer* GetLayerAt(UGint nIndex)const;
	//!brief  获取指定名称的图层
	UGLayer* GetLayer(const UGString &strName)const;
	//added by dongfei 2004-04-24 
	//! \brief 获取图层名对应的一组图层 即'#'前面的名称相同
	UGint GetLayers(const UGString &strName,UGArray<UGLayer*>& pLayers)const;

	//! \brief 移动图层位置
	/**
	\param nIndexFrom		起始位[in]
	\param nIndexTo			终点位[in]
	*/
	UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
	//! \brief 指定索引移动到底部
	UGbool MoveBottom(UGint nIndex);
	//! \brief 指定索引下移一位
	UGbool MoveDown(UGint nIndex);
	//! \brief 指定索引上移一位
	UGbool MoveUp(UGint nIndex);
	//! \brief 指定索引移至顶部
	UGbool MoveTop(UGint nIndex);

	//! \brief 设置对应的工作空间
	void SetWorkspace(UGWorkspace* pWorkspace);
	//! \brief 得到对应的工作空间
	UGWorkspace* GetWorkspace()const;

	//! \brief 使图层中的数据集生效
	UGbool ValidateDatasets();
//	void (UGLayers::*m_pLayersModified)(UGLayer* pLayer, UGuint nModifyLayerFlag);

	//! \brief 导出成XML
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief 读取XML信息
	UGbool FromXML(const UGString& strXML,UGbool bIgnoreCaption = true, UGint nVersion = 0);

	//! \brief 回调函数，在图层修改时调用
	void SetLayersModifiedFunc(LayersModifiedProc pLayersModifiedFunc, UGlong pMapWnd);

	//added by dongfei 2007-04-24
	//! \brief 找出一个与图层集合中所有图层不同的名字
	UGbool FindAvailableName(UGString& strLayerName)const;

	//! \brief 找出一个与图层集合中所有专题图图层不同的专题图名字，用于绘制专题图的时候根据这个名字获取字段别名
	UGbool FindAvailableThemeName(UGString& strThemeName);

	//! \brief 判断图层名是否与图层集合中其它图层名不同
	UGbool IsvalidName(const UGString& strLayerName);

	//added by xielin 2007-04-13
	//! \brief 设置是否允许多图层编辑模式 
	void SetMultiLayerEditEnable(UGbool bMultiLayerEditEnable);
	//added by xielin 2007-04-13
	//! \brief 返回是否允许多图层编辑模式 
	UGbool IsMultiLayerEditEnable();

	//added by xielin 2007-04-13
	//! \brief 设置当前图层，用于多图层编辑，在多图层编辑中，因为允许多个图层同时编辑，如果设定当前图层后，添加的对象就放到
	//设置的当前图层中，如果不设置当前图层，默认就是可编辑的第一个图层 
	void SetCurrentLayer(UGLayer* pLayer);

	//added by xielin 2007-04-13
	//! \brief 获取当前图层，用于多图层编辑，在多图层编辑中，因为允许多个图层同时编辑，如果设定当前图层后，添加的对象就放到
	//设置的当前图层中，如果不设置当前图层，默认就是可编辑的第一个图层 
	UGLayer* GetCurrentLayer();
	
	//added by xielin 2007-05-16
	//! \brief 清空所有图层的选择集
	void ClearLayersSelection();

	//added by xielin 2007-05-16
	//! \brief 获取所有选中对象的个数
	UGint GetSelectedGeometryCount();

	//added by lugw 2007-05-31
	//! \brief 兼容以前的标签专题图置顶功能，将专题图图层放在前面
	void AdjustableLayers(UGuint unOnTop);

	//!brief 设置是否发送事件，默认为true
	void SetNeedSendEvent(UGbool bNeedSendEvent = true);
	//!brief 返回是否设置了发送事件
	UGbool IsNeedSendEvent();

	void SetBeforeLayerDrawFunc(BeforeLayerDrawProc pBeforeLayerDrawFunc,UGlong pWnd);
	void SetAfterLayerDrawFunc(AfterLayerDrawProc pAfterLayerDrawFunc,UGlong pWnd);
		
	void SendBeforeLayerDrawFunc(UGbool& bCancel,UGint nLayerIndex,UGGraphics* pGraphics);
	void SendAfterLayerDrawFunc(UGint nLayerIndex,UGGraphics* pGraphics,LayerDrawReport& layerDrawReport);

	UGDataset* GetTopoLayerDs(UGDatasetTopo* pParentDataset, UGString strDatasetName)const;

	//是否图层的记录集
	void ReleaseRecordset();

	UGbool m_bIsDisplayClip;
	UGGeoRegion m_DisplayClipRegion;

	UGbool m_bIsUserEntireBounds;
	UGRect2D m_rc2UserEntireBounds;	
	UGbool m_bRealeaseRecordSet;
protected:
	void CheckBounds(UGLayer *pLayer, UGbool bComputeDatasetBounds);

protected:
	LayersModifiedProc m_pLayersModifiedFunc;
	UGlong m_pMapWnd;
	UGbool m_bFireMapEvent;//是否需要发送控件的事件消息,added by xielin 主要是图层的绘制事件
protected:
	//delete by xielin 这个变量不用了，删除吧
	//UGList<UGLayer*> m_EditableLayers;
	UGList<UGLayer*> m_Layers;
	UGArray<LayersForSaveSFC> m_LayersForSaveSFC;
	UGbool m_bModified;				//是否修改
	UGRect2D m_rcBounds;	
	UGbool m_bIsBoundsNull;			//图层们的Bounds之和是否为空.m_rc2Bounds是显示时候调用的。
									//一定要注意：m_rc2Bounds不为空时，m_bIsBoundsNull仍然可能为空.
	UGWorkspace* m_pWorkspace;
	UGDrawParamaters *m_pDrawParam;
	
	//added by xielin 2007-04-13
	//! \brief 允许多图层编辑模式 
	UGbool m_bMultiLayerEditEnable;
	//added by xielin 2007-04-13
	//! \brief 当前图层，用于多图层编辑，在多图层编辑中，因为允许多个图层同时编辑，如果设定当前图层后，添加的对象就放到
	//设置的当前图层中，如果不设置当前图层，默认就是可编辑的第一个图层 
	UGLayer* m_pCurrentLayer;        

	UGLayersRecordsetsManager m_RecordsetsManager;

	
	BeforeLayerDrawProc m_pBeforeLayerDrawFunc;
	AfterLayerDrawProc m_pAfterLayerDrawFunc;

public:
		UGlong m_pEventView;  //调用事件回调函数的对象指针，统一为一个吧，节省内存
};

}

#endif // !defined(AFX_UGLAYERS_H__4AF37668_F0B9_4C2D_B3A1_8E638AA1B00F__INCLUDED_)

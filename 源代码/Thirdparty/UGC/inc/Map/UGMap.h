// UGMap.h: interface for the UGMap class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMap.h   
   **************************************************************************************
    \author   陈国雄
    \brief    地图类，负责地图显示环境的管理。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)
#define AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_

#include "UGLayers.h"
#include "UGTrackingLayer.h"
#include "Project/UGSpatialRef.h"

namespace UGC {

class MAP_API UGMapVersionManager  
{
public:
	UGMapVersionManager();
	virtual ~UGMapVersionManager();
};

extern MAP_API UGMapVersionManager g_MapVersionManager;


//! \brief MapOpened事件回调函数
typedef void (UGSTDCALL *MapOpenedProc)(UGlong pWnd);

class MAP_API UGMap  
{
public:
	UGMap();
	UGMap(const UGMap& Map);
	virtual ~UGMap();
	UGMap& operator = (const UGMap &Map);

	enum OnTopType
	{
		LabelOnTop = 1,                    //标签置顶
		GraphOnTop = 2,                    //统计专题图置顶
		GraduatedSymbolOnTop = 4,          //等级符号置顶
	};

public:
	//! \brief  与工作空间建立联系,设置工作空间
	void SetWorkspace(UGWorkspace *pWorkspace);
	//! \brief  得到设置工作空间
	UGWorkspace* GetWorkspace()const;

	//! \brief  初始化地图模式
	void MapModeInitialize(UGGraphics* pGraphics, const UGRect& rcDevBounds);
	//! \brief  存储地图模式
	void MapModeRestore(UGGraphics* pGraphics);

	//! \brief  得到地图名称
	UGString GetName()const;
	//! \brief  得到地图描述信息
	UGString GetDescription()const;
	//! \brief  设置地图描述信息
	void SetDescription(const UGString& strDescription);

	//! \brief  重新设置初始化状态
	void Reset();
	//! \brief  设置刷新标志
	void SetRefreshFlag(UGbool bRefresh = true);

	//! \brief  设置更新标志
	void SetModifiedFlag(UGbool bModified = true);
	//! \brief  是否更新
	UGbool IsModified()const;

	//! \brief  设置地图投影信息
	void SetPrjCoordSys(const UGPrjCoordSys& PrjCoordSys);
	const UGPrjCoordSys& GetPrjCoordSys();
	void SetPrjCoordSysUnit(UGlong nUnits);
	UGlong GetPrjCoordSysUnit();

	//! \brief  得到颜色模式
	UGint GetColorMode()const;
	//! \brief  设置颜色模式
	void SetColorMode(UGint nColorMode);

	//! \brief  是否文本固定角度
	UGbool IsTextFixedAngle()const;
	//! \brief  设置为文本固定角度
	void SetTextFixedAngle(UGbool bTextFixedAngle = true);
	//! \brief  是否符号固定角度
	UGbool IsMarkerFixedAngle()const;
	//! \brief  设置为符号固定角度
	void SetMarkerFixedAngle(UGbool bMarkerFixedAngle = true);
	
	//将文本和线分开，和SFC保持一致
	//UGbool IsSmoothingMode()const;									
	//void SetSmoothingMode(UGbool bSmoothingMode = true);
	//! \brief  是否为线光滑模式
	UGbool IsLineSmoothingMode()const;
	//! \brief  设置线光滑模式
	void SetLineSmoothingMode(UGbool bSmoothingMode = true);			
	//! \brief  是否为文本光滑模式
	UGbool IsTextSmoothingMode()const;									
	//! \brief  设置文本光滑模式
	void SetTextSmoothingMode(UGbool bSmoothingMode = true);			
	
	//! \brief 设置\获取地图平滑显示的最大记录数 dongfei 2007-03-26
	void SetSmoothingMaxRecord(UGint nRecordCount);	
	UGint GetSmoothingMaxRecord()const;

	//! \brief   是否允许显示重叠文本 
	UGbool IsAllowTextOverlap()const;
	//! \brief   设置为允许重叠文本
	void SetAllowTextOverlap(UGbool bAllowTextOverlap = false);		
	//! \brief   是否固定文本朝向
	UGbool IsFixedTextOrientation()const;							
	//! \brief   设置为固定文本朝向
	void SetFixedTextOrientation(UGbool bFixedTextOrientation = true);	

	//! \brief   是否标签专题图置顶	
	UGbool IsLabelAlwaysOnTop()const;								
	//! \brief   设置标签专题图置顶
	void SetLabelAlwaysOnTop(UGbool bLabelAlwaysOnTop = false);		

	//! \brief   设置等级分段专题图置顶
	void SetGraduatedSymbolAlwaysOnTop(UGbool bGraduatedSymbolAlwaysOnTop = false);
	//! \brief   是否等级分段专题图置顶
	UGbool IsGraduatedSymbolAlwaysOnTop()const;
	
	void SetGraphAlwaysOnTop(UGbool bGraphAlwaysOnTop = false);
	//! \brief   是否等级分段专题图置顶
	UGbool IsGraphAlwaysOnTop()const;

	//! \brief   是否为第一次绘制
	UGbool IsFirstTimeDraw() const;

	//! \brief   得到最小可见文本大小
	UGdouble GetMinVisibleTextSize()const;
	//! \brief   设置最小可见文本大小
	void SetMinVisibleTextSize(UGdouble dVisibleTextSizeMin);		
	//! \brief   得到最大可见文本大小
	UGdouble GetMaxVisibleTextSize()const;							
	//! \brief   设置最大可见文本大小
	void SetMaxVisibleTextSize(UGdouble dVisibleTextSizeMax);		

	//! \brief   是否动态投影
	UGbool IsProjectionOnTheFly()const;									
	//! \brief   设置动态投影
	void SetProjectionOnTheFly(UGbool bProjectionOnTheFly = true);		

	//! \brief   判断是否处于忙碌阶段，是否允许中断等操作
	UGbool IsBusy()const;							
	//! \brief   设置处于忙碌阶段，不允许中断等操作
	void SetBusy(UGbool bBusy = true);	

	UGbool IsBusyEnable()const;							
	void SetBusyEnable(UGbool bBusyEnable = true);	

	//! \brief   得到背景风格
	const UGStyle& GetBkStyle()const;								
	//! \brief   设置背景风格
	void SetBkStyle(const UGStyle& style);							
	//! \brief   得到旋转角度
	double GetAngle()const;											
	//! \brief   设置旋转角度
	void SetAngle(double dAngle);									

	//! \brief   是否绘制背景
	UGbool IsPaintBackground() const;
	//! \brief   设置是否绘制背景
	void SetPaintBackground(UGbool bPaintBackground = true);
	
	//! \brief   读取地图的XML信息
	UGbool FromXML(const UGString& strXML, UGbool bIgnoreLayerCaption = true, UGint nVersion = 0);
	//! \brief   保存地图为XML
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief   打开工作空间中指定的地图
	UGbool Open(const UGString& strMap);
	//! \brief   另存为工作空间中指定的地图
	UGbool SaveAs(const UGString& strMap, UGbool bOverWrite = false);	
	//! \brief   保存地图
	UGbool Save();

	//! \brief   判断是否有selection需要高亮
	UGbool RequireHignlightSelection();
	//! \brief   高亮所有图层的m_Selection
	void HignlightSelection(UGGraphics* pGraphics);
	//! \brief   绘制背景
	UGbool PaintBackground(UGGraphics* pGraphics, UGRect rcErase);
	//! \brief   绘制地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param rcDevBounds				所需绘制的设备范围[in]
	\param rcInvalid				还没有用到[in]
	\param bIsPrinting				是否打印[in]
	\param bIsPrinting				是否合适一页的打印大小，只用于打印[in]
	\param bMapModeInitialize		是否初始化地图模式[in]
	\param pProgress				进程条参数[in]
	\param bOnlyPaintBackground		是否只绘制背景
	\return 绘制是否成功
	*/
	UGbool OnDraw(UGGraphics* pGraphics, UGRect rcDevBounds, UGRect rcInvalid, UGbool bIsPrinting = false, UGbool bFitToPage = false, UGbool bMapModeInitialize = true,UGProgress* pProgress = NULL,UGbool bOnlyPaintBackground = false);
	//! \brief   绘制地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param rcDevBounds				所需绘制的设备范围[in]
	\param rcMapBounds				地图范围[in]
	\param dPrintScale				设置打印的比例[in]
	\param bCentered				是否按照绘制的设备范围的中心打印[in]
	\param bMapModeInitialize		是否初始化地图模式[in]
	\param bPaintBackground			是否打印背景[in]
	\return 打印是否成功
	*/
	UGbool OnPrint(UGGraphics* pGraphics, UGRect rcDevBounds, const UGRect2D& rcMapBounds, UGdouble dPrintScale, UGbool bCentered = true, UGbool bMapModeInitialize = true, UGbool bPaintBackground = false);
	//! \brief   绘制几何对象
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param pGeometry				绘制的几何对象[in]
	\param pStyle					绘制风格[in]
	\return 
	*/
	UGbool DrawGeometry(UGGraphics* pGraphics, UGGeometry* pGeometry, UGStyle* pStyle = NULL);

	//! \brief   输出为地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param rcBounds					绘制图片大小[in]
	\param bNoBackground			是否绘制背景[in]
	\param bClipContent				没有用到[in]
	\param bCopyFromCache			没有用到[in]
	\param bEntireMap 				是否整幅输出[in]
	\return 输出地图是否成功
	*/
	UGbool OutputMap(UGGraphics* pGraphics, UGRect rcBounds, UGbool bNoBackground = false, UGbool bClipContent = false, UGbool bCopyFromCache = false,UGbool bEntireMap = false);

	//! \brief   输出跟踪图层
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param rcBounds					绘制图片大小[in]
	\param nTransparentColor		透明色（背景色）[in]
	\param bClipContent				没有用到[in]
	\param bEntireMap 				是否整幅输出[in]
	\return 输出地图是否成功
	*/
	UGbool OutputTrackingLayer(UGGraphics* pGraphics, UGRect rcBounds, UGColor nTransparentColor = UGRGB(1,1,1), UGbool bClipContent = false, UGbool bEntireMap = false);

	//! \brief   输出为地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param szBitmap					绘制图片大小[in]
	\param strFileName				图片输出的路径和名称[in]
	\param nImageType				图片类型[in]
	\param bEntireMap				是否整幅输出[in]
	\param nCompress  				是否压缩[in]
	\return 输出地图是否成功
	*/
	UGbool OutputMapToFile(UGGraphics* pGraphics, UGSize szBitmap, const UGString& strFileName, UGint nImageType, UGbool bEntireMap = false, UGint nCompress = 100);
	//! \brief   输出为地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param pDestDataSource			绘制的数据源[in]
	\param strDatasetName			绘制的数据源中数据集名[in]
	\param dResolution				绘制的比例[in]
	\param rcBounds					显示范围[in]
	\param bShowProgress   			是否显示进度条[in]
	\return 输出地图是否成功
	*/
	UGDatasetRaster* OutputMapEx(UGGraphics* pGraphics, UGDataSource* pDestDataSource, const UGString& strDatasetName, double dResolution, UGRect2D& rcBounds, UGbool bShowProgress = true);
	//! \brief   输出为地图
	/**
	\param pGraphics				绘制到的Graphics[in]
	\param strFileName				图片输出路径和名称[in]
	\param rcBounds					显示范围[in]
	\param nDPI						图片类型[in]
	\param bShowProgress 			是否显示进度条[in]
	\return 输出地图是否成功
	*/
	UGbool OutputMapToBMP(UGGraphics* pGraphics, const UGString& strFileName, UGRect2D& rcBounds, UGint nDPI = 200, UGbool bShowProgress = true);
	//! \brief   输出地图为eps文件
	/**	
	\param strFileName				图片输出路径和名称[in]	
	\param bTextToVector				是否将文字矢量化[in]	
		\param bEntireMap				是否全幅输出[in]	
	\return 输出地图是否成功
	*/
	UGbool OutputMapToEPS(UGSize szBitmap, const UGString& strFileName, UGbool bTextToVector = false, UGbool bEntireMap = false);
	//! \brief   得到地图比例尺
	UGdouble GetScale()const;
	//! \brief   设置地图比例尺
	void SetScale(UGdouble dScale);
	//! \brief   得到地图中心点
	UGPoint2D GetCenter()const;										
	//! \brief   设置地图中心点
	void SetCenter(const UGPoint2D& pntCenter);						

	//! \brief   平移
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);
	//! \brief   放大、缩小
	void Zoom(UGdouble dZoomRatio);
	//! \brief   整幅
	UGbool ViewEntire(const UGRect rcDevice = UGRect(0,0,0,0));
	
	//! \brief   获取地图范围
	UGRect2D GetBounds();
	//! \brief   得到地图显示范围
	UGRect2D GetViewBounds();
	//! \brief   设置地图显示范围
	void SetViewBounds(const UGRect2D& rcMapViewBounds);

	//! \brief   鼠标点击事件
	UGbool HitTest(UGPoint2D pntHitTest, UGdouble dTolerance, UGbool bAppendMode = false, UGbool bControlMode = false);
	//! \brief   得到绘制类
	UGDrawing* GetDrawing();

	//added by xielin 2007-04-13
	//! \brief 设置是否允许多图层编辑模式 
	void SetMultiLayerEditEnable(UGbool bMultiLayerEditEnable);
	//added by xielin 2007-04-13
	//! \brief 返回是否允许多图层编辑模式 
	UGbool IsMultiLayerEditEnable();


	
	//added by xielin 2007-04-13
	//! \brief 设置是否允许编辑过程中提示 
	void SetShowTrackingTooltips(UGbool bTrackingTooltips);
	//added by xielin 2007-04-13
	//! \brief 返回是否允许编辑过程中提示 
	UGbool IsShowTrackingTooltips();
	
	//added by xielin 2007-04-13

	//! \brief 设置当前图层，用于多图层编辑，在多图层编辑中，因为允许多个图层同时编辑，如果设定当前图层后，添加的对象就放到
	//! 设置的当前图层中，如果不设置当前图层，默认就是可编辑的第一个图层 
	void SetCurrentLayer(UGLayer* pLayer);

	//added by xielin 2007-04-13
	//! \brief 获取当前图层，用于多图层编辑，在多图层编辑中，因为允许多个图层同时编辑，如果设定当前图层后，添加的对象就放到
	//!设置的当前图层中，如果不设置当前图层，默认就是可编辑的第一个图层 
	UGLayer* GetCurrentLayer();

	//! \brief 获取地图对象的hashcode
	UGString GetHashCode(UGint nImageFileType) const;

	//! \brief 得到设置是否使用显示裁剪区域
	UGbool IsDisplayClip() const;						
	//! \brief 得到是否使用显示裁剪区域
	void SetDisplayClip(UGbool bIsDisplayClip);			

	//! \brief 得到显示裁剪区域
	void GetDisplayClipRegion(UGGeoRegion& geoClipRegion);
	//! \brief 得到是否使用显示裁剪区域
	void SetDisplayClipRegion(UGGeoRegion& geoClipRegion);

	//! \brief 是否显示用户指定范围
	UGbool IsUserEntireBounds();
	//! \brief 设定是否显示用户指定范围
	void SetIsUserEntireBounds(UGbool bIsUserEntireBounds);

	//! \brief 得到用户指定显示范围
	UGRect2D GetUserEntireBounds();
	//! \brief 用户指定显示范围
	void SetUserEntireBounds(const UGRect2D& rc2UserEntireBounds);

	//! \brief 设置用户指定显示比例
	void SetDisplayScales(UGArray<UGdouble> arrDisplayScales);
	//! \brief 得到用户指定显示比例
	void GetDisplayScales(UGArray<UGdouble>& arrDisplayScales);
	//! \brief 是否采用用户显示比例
	void SetDisplayByScales(UGbool bDisplayByScales);
	//! \brief 设置是否采用用户显示比例
	UGbool IsDisplayByScales() const;
	//! \brief 获取/设置能显示的对象最大节点数，超过这个节点的对象就不显示
	UGint GetMaxVisibleVertex() const;
	void SetMaxVisibleVertex(UGint nMaxVisibleVertex);

	//added by xielin 2007-11-15 增加一个接口，用来设置绘制图层后是否马上释放记录集
	//! \brief 获取/设置绘制图层后是否马上释放记录集，默认iserver产品马上释放，组件桌面产品不马上释放，因为捕捉和选择都会用到显示的记录集
	void SetReleaseDisplayRecordset(UGbool bRelease = true);
	UGbool IsReleaseDisplayRecordset();
	
protected:	
	void ZoomWhenFirstViewMap();
	void SetMapOpenedFunc(MapOpenedProc pMapOpenedFunc, UGlong pMapWnd);
	void SendMapOpenedFunc();
public:
	UGLayers m_Layers;
	UGTrackingLayer m_TrackingLayer;
	UGint m_nMarginWidthViewEntire;
	//deleted by xielin 2007-05-16 改为每个layer都有一个m_Selection,该成员变量废弃掉
	//UGSelection	m_Selection;
	//added by xielin 2007-08-21 
	//! \brief 判断地图是否重新刷新。并且重新绘制对象了。在编辑的时候用到
	UGbool m_bRefresh;
	MapOpenedProc m_MapOpenedFunc;

protected:	
	UGDrawing m_Drawing;

public:
	UGString m_strName;

protected:	
	UGString m_strDescription;			//图层描述
	
	UGbool m_bForceToRefresh;
	UGbool m_bModified;
	UGPrjCoordSys m_PrjCoordSys;

	UGbool m_bAllowTextOverlap;			//允许文本叠盖
	UGuint m_unOnTop;
	//UGbool m_bLabelAlwaysOnTop;			//标签专题图置顶
	//UGbool m_bGraduatedSymbolAlwaysOnTop;//等级符号专题图置顶
	//UGbool m_bGraphAlwaysOnTop;			//统计专题图置顶
	UGbool m_bFirstTimeDraw;	

	UGint m_nPreMapMode;
	UGPoint m_pntWndOrg;

	UGbool m_bPaintBackground;

	//added by xielin 2007-04-13  
	//! \brief 允许显示编辑过程中的提示 
	UGbool m_bShowTrackingTooltips;

	UGbool m_bDisplayByScales;
	UGArray<UGdouble> m_arrDisplayScales;

	
	UGlong m_pMapWnd;
};

}

#endif // !defined(AFX_UGMAP_H__37037E0D_8ABC_413E_B8BE_2B8916F0319E__INCLUDED_)

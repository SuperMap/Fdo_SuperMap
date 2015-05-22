// UGMapWnd.h: interface for the UGMapWnd class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapWnd.h
   **************************************************************************************
    \author   陈国雄
    \brief    地图窗口模拟类，负责地图的绘制及地图窗口的消息处理。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_)
#define AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_

#include "Map/UGMap.h"
#include "Editor/UGEditToolPack.h"
#include "Editor/UGRegionSelect.h"
#include "Base/ugplatform.h"
#include "Engine/UGDataHistory.h"

namespace UGC {

// by zengzm 2007-3-26 把__stdcall定义到ugplatform中
typedef void (UGSTDCALL *INVALIDATEPROC)(UGlong pData);
//#ifdef WIN32
//typedef void (__stdcall *INVALIDATEPROC)(UGuint pData);
//#else
//typedef void (*INVALIDATEPROC)(UGuint pData);
//#endif
//added by xielin 2007-06-05 增加mapwnd的事件，用回调函数来实现
//! \brief BeforeGeometryDeleted事件回调函数
typedef void (UGSTDCALL *BeforeGeometryDeletedProc)(UGlong pWnd,UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
//! \brief AfterGeometryAdded 事件回调函数
typedef void (UGSTDCALL *AfterGeometryAddedProc)(UGlong pWnd,UGint nGeometryID,UGLayer* pLayer);
//! \brief AfterGeometryModified 事件回调函数
typedef void (UGSTDCALL *AfterGeometryModifiedProc)(UGlong pWnd,UGint nGeometryID,UGLayer* pLayer);
//! \brief BeforeGeometryModified 事件回调函数
typedef void (UGSTDCALL *BeforeGeometryModifiedProc)(UGlong pWnd,UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
//! \brief BeforeTrackingLayerDraw 事件回调函数
typedef void (UGSTDCALL *BeforeTrackingLayerDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);
//! \brief AfterTrackingLayerDraw 事件回调函数
typedef void (UGSTDCALL *AfterTrackingLayerDrawProc)(UGlong pWnd,UGGraphics* pGraphics);
//! \brief BeginEditHandle 事件回调函数
typedef void (UGSTDCALL *BeginEditHandleProc)(UGlong pWnd,UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief MovingEditHandle 事件回调函数
typedef void (UGSTDCALL *MovingEditHandleProc)(UGlong pWnd,UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief EditHandleCanceled 事件回调函数
typedef void (UGSTDCALL *EditHandleCanceledProc)(UGlong pWnd,UGint nHandle);
//! \brief EndEditHandle 事件回调函数
typedef void (UGSTDCALL *EndEditHandleProc)(UGlong pWnd,UGint nHandle,
											  UGdouble dx,UGdouble dy);
//! \brief GeometrySelected 事件回调函数
typedef void (UGSTDCALL *GeometrySelectedProc)(UGlong pWnd,UGint nSelectedGeometryCount);
//! \brief Tracking 事件回调函数
typedef void (UGSTDCALL *TrackingProc)(UGlong pWnd,UGdouble dx,UGdouble dy,UGint nButtonClicked,
											   UGdouble dCurrentLength,UGdouble dCurrentAngle,UGdouble dTotalLength,
											   UGdouble dTotalArea);
//! \brief Tracked 事件回调函数
typedef void (UGSTDCALL *TrackedProc)(UGlong pWnd);

//! \brief AfterPointInput 事件回调函数
typedef void (UGSTDCALL *AfterPointInputProc)(UGlong pWnd,UGdouble& dx,UGdouble& dy,UGdouble& dz);

//! \brief BeforeMapDraw 事件回调函数
typedef void (UGSTDCALL *BeforeMapDrawProc)(UGlong pWnd,UGbool& bCancel,UGGraphics* pGraphics);

//! \brief AfterMapDraw 事件回调函数
typedef void (UGSTDCALL *AfterMapDrawProc)(UGlong pWnd,UGGraphics* pGraphics);


class EDITOR_API UGMapWnd  
{

	friend class UGEditToolPack;
public:
	enum UGMarginPanMode
	{
		Other		=0,
		Left		=1,
		Top			=2,
		Right		=3,
		Bottom		=4,
		TopLeft		=5,
		TopRight	=6,
		BottomRight	=7,
		BottomLeft	=8
	};
	// 选择模式
	enum UGSelectionMode
	{
		smContainCentroid,		//包含质心
		smAreaIntersect,		//面积相交
		smContainObject		//包含对象
	};

	//added by xielin 2007-06-19 加入鼠标形状枚举变量，鼠标形状的处理还是在ugc中处理，上层设置鼠标形状的时候直接通过一个函数获取枚举变量就可以，上面就省事情了
	enum UGCursorShape
	{
		ecBusy = 1,				//忙光标
		ecArrow,				//普通箭头光标
		ecMarginPanLeft,		//自动滚屏往左光标
		ecMarginPanRight,		//自动滚屏往右光标
		ecMarginPanTop,			//自动滚屏往上光标
		ecMarginPanBottom,		//自动滚屏往下光标
		ecMarginPanTopLeft,		//自动滚屏左上光标
		ecMarginPanTopRight,	//自动滚屏右上光标
		ecMarginPanBottomRight,	//自动滚屏右下光标
		ecMarginPanBottomLeft,	//自动滚屏左下光标
		ecZoomFree,				//自由缩放光标
		ecZoomFree2,			//自由缩放光标
		ecPan,					//平移光标
		ecPan2,					//平移光标
		ecZoomIn,				//放大光标
		ecZoomOut,				//缩小光标
		ecPointModeSelect,		//点选光标
		ecPointModeSelectTrue,	//纯点选光标
		ecRectModeSelect,		//矩形选择光标
		ecCircleModeSelect,		//圆形选择光标
		ecRegionModeSelect,		//多边形选择光标
		ecLineModeSelect,		//线性选择光标
		ecDrawPoint,			//绘制点光标
		ecDrawLineSect,			//绘制直线光标
		ecDrawPolyLine,			//绘制折线、半自动矢量化线等光标
		ecDrawEllipseArc,		//绘制椭圆弧光标
		ecDrawArc3P,			//绘制三点弧光标
		ecDrawCurve,			//绘制曲线光标，包括b样条，cardinal，贝兹曲线
		ecDrawRectangle,		//绘制矩形光标
		ecDrawRoundRect,		//绘制圆角矩形光标
		ecDrawCircle,			//绘制圆心圆光标
		ecDrawCircle3P,			//绘制三点圆光标
		ecDrawCircle2P,			//绘制两点圆光标
		ecDrawEllipse,			//绘制椭圆光标
		ecDrawObliqueEllipse,	//绘制斜椭圆光标
		ecDrawPolyGon,			//绘制多边形、半自动矢量化面等光标
		ecDrawText,				//绘制文本光标
		ecDrawStreamText,		//绘制沿线注记光标
		ecDrawParallel,			//绘制平行线光标
	    ecCross,				//十字光标
        ecRotation,				//旋转光标
        ecBeam,					//工字光标
        ecMove,					//移动光标
		ecNorthSouth,			//南北移动光标
		ecWestEast,				//东西移动光标
		ecNorthwestSoutheast,	//西北<->东南移动光标
		ecNortheastSoutnwest,	//东边<->西南移动光标
		ecCrossSnapPoint,		//点捕捉光标
		ecCrossSnapVertex,		//顶点捕捉光标
		ecCrossSnapMidpoint,	//线段中点捕捉光标
		ecCrossSnapLine,		//线上捕捉光标
		ecCrossSnapVertical,	//垂直捕捉光标
		ecCrossSnapParallel,	//平行捕捉光标
		ecMoveRotateBase,		//旋转基点光标
	};

public:
	UGMapWnd();
	virtual ~UGMapWnd();

public:	
	void Initialize(UGbool bInitEditEnvironment = true);
	void Reset(UGbool bClearWorkspace = false);
	void SetEditEnvironment();							//设置编辑环境
	UGWorkspace* GetWorkspace();						//取得工作空间
	void AttachWorkspace(UGWorkspace *pSmWorkspace);	//与工作空间建立联系
	void OnClose();

	UGbool IsEditEnabled()const;								//当前地图是否可编辑
	//根据坐标点确定地图的选中对象
	UGbool HitTest(UGPoint2D pntHitTest, UGbool bAppendMode = false, UGbool bControlMode = false);
	UGbool IsHittestBorderOnly()const;
	void SetHittestBorderOnly(UGbool bBorderOnly = true);	
	UGbool IsHotKeyEnabled() const;
	void SetHotKeyEnabled(UGbool bEnabled);

	void ViewEntire(const UGRect rcDevice = UGRect(0,0,0,0));									//全副显示地图
	void Pan(UGdouble dOffsetX, UGdouble dOffsetY);	//平移
	void Zoom(UGdouble dZoomRatio);						//放大、缩小
	void SetCenter(const UGPoint2D& pnt2Center);		//设置地图中心点
	void SetScale(UGdouble dScale);					//设置比例尺
	UGPoint2D GetCenter()const;								//取得中心点

	void Refresh();									//刷新
	void RefreshTrackingLayer(UGbool bValidateRect = false);//刷新跟踪图层
	UGbool OnDraw(UGGraphics* pGraphics, UGRect rcDevBounds, UGRect rcInvalid, UGbool bIsPrinting = false, UGbool bFitToPage = false);
	UGbool OnPrint(UGGraphics* pGraphics, UGRect rcDevBounds, const UGRect2D& rcMapBounds, UGdouble dPrintScale, UGbool bCentered = true, UGbool bPaintBackground = false);
	
	UGint GetUserAction();			//取得当前的地图操作
	void SetUserAction(UGint nUserAction, UGint nEditUserAction = 0);
	UGint SetSubAction(UGint nSubAction);

	void OnLayersModified(UGLayer* pLayer, UGuint nModifyLayerFlag);
	void OnMapOpened();

	UGbool OnChar(UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	UGbool OnKeyDown(UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	UGbool OnLButtonDblClk(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnLButtonDown(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnLButtonUp(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnMouseMove(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnMouseWheel(UGGraphics* pGraphics, UGuint nFlags, UGshort zDelta, UGPoint point);
	UGbool OnRButtonDblClk(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnRButtonDown(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnRButtonUp(UGGraphics* pGraphics, UGuint nFlags, UGPoint point);
	UGbool OnSize(UGGraphics* pGraphics, const UGRect& rcNewClient);

	UGint GetSelectionMode()const;
	void SetSelectionMode(UGint nSelectionMode); 
	
	UGdouble GetSelectionTolerance()const;
	void SetSelectionTolerance(UGdouble dSelectionTolerance); 

	UGRect GetClipRect()const;
	void SetClipRect(const UGRect &rcClipRect);

	//撞墙漫游
	void CheckMarginPanMode(UGPoint point);

	UGRect2D GetBounds();
	UGRect2D GetViewBounds();
	void SetViewBounds(const UGRect2D& rcMapViewBounds);
	
	//deleted by xielin 2007-05-16 这里不返回selection了
	//UGSelection* GetSelection();
	UGEditToolPack* GetEditToolPack();//取得编辑工具包

	UGbool SelectWithCircle(const UGPoint2D &pnt2Center, UGdouble dRadius, UGbool bShiftMode = false, UGbool bControlMode = false);
	UGbool SelectWithRect(const UGRect2D &rcSelection, UGbool bShiftMode = false, UGbool bControlMode = false);
	UGbool SelectWithRegion(UGGeoRegion &regSelection, UGbool bShiftMode = false, UGbool bControlMode = false);
	
	UGint GetMarginPanWidth();						//撞墙漫游边宽
	void SetMarginPanWidth(UGint nMarginPanWidth);	

	UGint GetMarginPanMode();						//撞墙漫游模式

	UGdouble GetMarginPanPercent();					//撞墙漫游百分比
	void SeMarginPanPercent(UGdouble dMarginPanPercent);	

	UGbool IsMarginPanEnable();					//撞墙漫游许可
	void SetMarginPanEnable(UGbool bMarginPanEnable);	

	UGbool IsCursorBusy()const;							
	void SetCursorBusy(UGbool bCursorBusy = true);	

	UGbool IsBusyCursorEnable()const;							
	void SetBusyCursorEnable(UGbool bBusyCursorEnable = true);	

	void SetInvalidateFunc(INVALIDATEPROC pInvalidateFunc, UGlong pWnd);	
	void SetDrawCallBackFunc(DRAWCALLBACKPROC pDrawCallBackFunc, UGlong pWnd);
	void SetDrawPaintFunc(DRAWPAINTPROC pDrawPaintFunc, UGlong pPaintWnd);
	
	void SendInvalidateFunc();

	//added by xielin 2007-04-30 
	//! \brief 设置扩展对象的编辑结束的点数，如果达到这个点数，鼠标左键就结束绘制工作
	//! \param nCount 鼠标点下的点数
	void SetEndEditDragCount(UGint nCount);

	//modified by xielin 2007-09-12 因为undo等操作需要去刷行graphics，这个graphics还是从外部传入比较保险
	//那么修改一下接口，外部调用得时候必须传入graphics
	//added by xielin 2007-05-15
	//! \brief 删除选中对象
	UGbool OnDelete(UGGraphics* pGraphics);
	//! \brief 是否可以剪切
	UGbool CanCut();
	//! \brief 是否可以粘贴
	UGbool CanPaste();
	//! \brief 是否可以拷贝
	UGbool CanCopy();
	//! \brief 是否可以重干
	UGbool CanRedo();
	//! \brief 是否可以撤消
	UGbool CanUndo();
	//! \brief 剪切
	UGbool Cut(UGGraphics* pGraphics);//
	//! \brief 粘贴
	UGbool Paste(UGGraphics* pGraphics);
	//! \brief 复制
	UGbool Copy(UGGraphics* pGraphics);
	//! \brief 撤消
	UGbool Redo(UGGraphics* pGraphics);
	//! \brief 恢复
	UGbool Undo(UGGraphics* pGraphics);
	
	//! \brief 设置是否是java程序在调用，注意，如果是java调用，一定要在wrapj中设置一下，因为java和.net的刷新机制不一样
	void SetUsedByJava(UGbool bJava = true);
	
	//! \brief 返回是否java程序在调用
	UGbool GetUsedByJava();

	//回调函数，用于实现mapwnd的事件
	void SetBeforeGeometryDeletedFunc(BeforeGeometryDeletedProc pBeforeGeometryDeletedFunc,UGlong pWnd);
	void SetAfterGeometryAddedFunc(AfterGeometryAddedProc pAfterGeometryAddedFunc,UGlong pWnd);
	void SetAfterGeometryModifiedFunc(AfterGeometryModifiedProc pAfterGeometryModifiedFunc,UGlong pWnd);
	void SetBeforeGeometryModifiedFunc(BeforeGeometryModifiedProc pBeforeGeometryModifiedFunc,UGlong pWnd);
	void SetBeforeTrackingLayerDrawFunc(BeforeTrackingLayerDrawProc pBeforeTrackingLayerDrawFunc,UGlong pWnd);
	void SetAfterTrackingLayerDrawFunc(AfterTrackingLayerDrawProc pAfterTrackingLayerDrawFunc,UGlong pWnd);
	void SetBeginEditHandleFunc(BeginEditHandleProc pBeginEditHandleFunc,UGlong pWnd);
	void SetMovingEditHandleFunc(MovingEditHandleProc pMovingEditHandleFunc,UGlong pWnd);
	void SetEditHandleCanceledFunc(EditHandleCanceledProc pEditHandleCanceledFunc,UGlong pWnd);
	void SetEndEditHandleFunc(EndEditHandleProc pEndEditHandleFunc,UGlong pWnd);
	void SetGeometrySelectedFunc(GeometrySelectedProc pGeometrySelectedFunc,UGlong pWnd);
	void SetTrackingFunc(TrackingProc pTrackingFunc,UGlong pWnd);
	void SetTrackedFunc(TrackedProc pTrackedFunc,UGlong pWnd);
	void SetAfterPointInputFunc(AfterPointInputProc pAfterPointInputFunc,UGlong pWnd);
	void SetBeforeMapDrawFunc(BeforeMapDrawProc pBeforeMapDrawFunc,UGlong pWnd);
	void SetAfterMapDrawFunc(AfterMapDrawProc pAfterMapDrawFunc,UGlong pWnd);

	void SendBeforeGeometryDeletedFunc(UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
	void SendAfterGeometryAddedFunc(UGint nGeometryID,UGLayer* pLayer);
	void SendAfterGeometryModifiedFunc(UGint nGeometryID,UGLayer* pLayer);
	void SendBeforeGeometryModifiedFunc(UGbool& bCancel,UGint nGeometryID,UGLayer* pLayer);
	void SendBeforeTrackingLayerDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	void SendAfterTrackingLayerDrawFunc(UGGraphics* pGraphics);
	void SendBeginEditHandleFunc(UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
	void SendMovingEditHandleFunc(UGbool& bCancel,UGint nHandle,
											  UGdouble dx,UGdouble dy);
	void SendEditHandleCanceledFunc(UGint nHandle);
	void SendEndEditHandleFunc(UGint nHandle,UGdouble dx,UGdouble dy);
	void SendGeometrySelectedFunc(UGint nSelectedGeometryCount);
	void SendTrackingFunc(UGdouble dx,UGdouble dy,UGint nButtonClicked,
											   UGdouble dCurrentLength,UGdouble dCurrentAngle,UGdouble dTotalLength,
											   UGdouble dTotalArea);
	void SendTrackedFunc();
	void SendAfterPointInputFunc(UGdouble& dx,UGdouble& dy,UGdouble& dz);
	void SendBeforeMapDrawFunc(UGbool& bCancel,UGGraphics* pGraphics);
	void SendAfterMapDrawFunc(UGGraphics* pGraphics);
	//回调函数，用于实现mapwnd的事件 end
	
	//!brief 设置拉框放大，拉框选择等操作时在tracking上绘制的风格
	void SetTrackingZoomAndSelectStyle(const UGStyle& style);
	//!brief 返回拉框放大，拉框选择等操作时在tracking上绘制的风格
	const UGStyle&  GetTrackingZoomAndSelectStyle();
	//!brief 设置是否发送事件，默认为true
	void SetNeedSendEvent(UGbool bNeedSendEvent = true);
	//!brief 返回是否设置了发送事件
	UGbool IsNeedSendEvent();

	//编辑相关的风格设置

	//!brief 设置交互式绘制几何对象时的颜色
	void SetTrackingStyle(const UGStyle& style);
	//!brief 返回交互式绘制几何对象时的颜色
	const UGStyle& GetTrackingStyle();

	//!brief 设置捕捉线的颜色
	void SetSnapedLineColor(UGColor color);
	//!brief 返回捕捉线的颜色
	const UGColor GetSnapedLineColor();

	//!brief 设置捕捉到的点的颜色
	void SetSnapedPointColor(UGColor color);
	//!brief 返回捕捉到的点的颜色
	const UGColor GetSnapedPointColor();
	
	//!brief 设置具体捕捉的捕捉对象风格，比如设置点在点上的捕捉风格,注意，内部实现是复制了一个pStyle，该指针外部自己处理释放
	void SetSnapedStyle(UGint nSnapType,UGStyle* pStyle);

	//!brief 获取具体捕捉的捕捉对象风格，比如获取点在点上的捕捉风格，如果不设置，默认都是NULL，注意，返回的是内部指针引用，请不要外部释放
	UGStyle* GetSnapedStyle(UGint nSnapType);

	//!brief 设置绘制对象时辅助线的风格
	void SetAssistantLineStyle(const UGStyle& style);
	//!brief 返回绘制对象时辅助线的风格
	const UGStyle& GetAssistantLineStyle();
	//!brief 设置绘制对象的默认风格，该风格将保存到对象中
	void SetDefaultStyle(const UGStyle& style);
	//!brief 获取绘制对象的默认风格，该风格将保存到对象中
	const UGStyle& GetDefaultStyle();
	//编辑相关的风格设置 end

	//!brief 设置鼠标形状，主要是内部使用，在交互式编辑的时候设置鼠标形状枚举变量
	void SetCursorShape();
	//!brief 获取鼠标形状，主要是外部使用，在交互式编辑的时候通过该函数返回鼠标枚举变量，上层再设置相应鼠标形状
	UGMapWnd::UGCursorShape GetCursorShape();

	//!brief 是否开放编辑模块，设置以后就算设置了图层的可编辑状态，也无法编辑,默认值为true
	void SetOpenEditMode(UGbool bOpenEditMode = false);
	UGbool IsOpenEditMode();
public:
	UGMap m_Map;
	UGRegionSelect m_RgnSelect;				//矩形、圆形、多边形选择使用的选择区域
	UGRegionSelect m_RgnZoom;				//ZoomIn、ZoomOut使用的选择区域 
	UGbool m_bFireMapEvent;//是否需要发送控件的事件消息,added by xielin 地图编辑的时候有用，现在用回调函数来代替消息
	//added by xielin 2007-05-22 历史对象
	UGDataHistory* m_pDataHistory;
protected:
	INVALIDATEPROC m_pInvalidateFunc;

public:
	UGlong m_pView;
protected:
	
	//!brief 历史记录修改后(回退/重做),需要刷新地图和选择集状态,这个函数就用来做这个工作
	UGbool RefreshEditDataHistory();
	
	//!brief 拾取对象，放到toolpack中，要考虑多图层编辑的清空
	UGbool PickObjects(UGGraphics* pGraphics); 

	//!brief 设置对象选中编辑时的鼠标形状，内部使用，不对外开放，主要在SetCursorShape中使用,返回值表示是否有设置对象编辑鼠标形状
	UGbool SetEditCursorShape();
protected:
	UGEditToolPack m_EditToolPack;

	UGint m_nSelectionMode;
	UGint m_nMaxSelBufSize;			//随机选择集的缓冲区大小
	UGint m_nToleranceSelection;

	UGint m_nMarginPanWidth;					//撞墙漫游边宽
	UGint m_nMarginPanMode;						//撞墙漫游模式
	UGdouble m_dMarginPanPercent;				//撞墙漫游百分比
	UGbool m_bMarginPanEnable;					//撞墙漫游许可
		
	UGPoint m_pntLastPoint;
	UGbool m_bLBtnDown;
	UGbool m_bHotKeyEnabled;
	UGbool m_bNewObjAutoSelected;				//新添加的对象是否立即被选中
	UGbool m_bHittestBorderOnly;

	UGRect m_rcClipRect;

	UGString m_strCopyDsFileName ;              //拷贝粘贴的时候保存的udb数据源文件名
	UGString m_strCopyDsAlias;					//拷贝粘贴的时候保存的udb数据源别名

	//! \brief 设置是否是java程序在调用，注意，如果是java调用，一定要在wrapj中设置一下，因为java和.net的刷新机制不一样
	UGbool m_bIsJava;					
	
	//事件相关变量
	UGlong m_pEventView;  //调用事件回调函数的对象指针，统一为一个吧，节省内存
	BeforeGeometryDeletedProc m_pBeforeGeometryDeletedFunc;
	AfterGeometryAddedProc m_pAfterGeometryAddedFunc;
	AfterGeometryModifiedProc m_pAfterGeometryModifiedFunc;
	BeforeGeometryModifiedProc m_pBeforeGeometryModifiedFunc;
	BeforeTrackingLayerDrawProc m_pBeforeTrackingLayerDrawFunc;
	AfterTrackingLayerDrawProc m_pAfterTrackingLayerDrawFunc;
	
	BeginEditHandleProc m_pBeginEditHandleFunc;
	MovingEditHandleProc m_pMovingEditHandleFunc;
	EditHandleCanceledProc m_pEditHandleCanceledFunc;
	GeometrySelectedProc m_pGeometrySelectedFunc;
	TrackingProc m_pTrackingFunc;
	TrackedProc m_pTrackedFunc;
	EndEditHandleProc m_pEndEditHandleFunc;
	AfterPointInputProc m_pAfterPointInputFunc;
	BeforeMapDrawProc m_pBeforeMapDrawFunc;
	AfterMapDrawProc m_pAfterMapDrawFunc;
	//事件相关变量 end

	//added by xielin 2007-06-13
	//!brief 用来保存用户在LButtonDown等事件中传入的Graphics，因为在回退等操作中要用到
	UGGraphics* m_pUserGraphics;

	UGPoint3D m_pnt3DInput;

	//!brief 拉框放大、缩小、选择时候的风格
	UGStyle m_ZoomAndSelectStyle;
	//!brief 绘制对象的风格，保存到对象中
	UGStyle m_DefaultStyle;
	//!brief 保存鼠标形状枚举变量
	UGCursorShape m_nCursorShape; 
	
	//!brief 加一个变量，用来设置是否开放编辑模块，如果设为false，不论是否设置图层可编辑，都不开放编辑模块
	//2.0中就先不开放编辑模块，
	UGbool m_bOpenEditMode;
	
	

};

}

#endif // !defined(AFX_UGMAPWND_H__68C39D42_D336_4C1A_8C4D_FCEB87806120__INCLUDED_)

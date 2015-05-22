// UGEditToolPack.h: interface for the UGEditToolPack class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGEditToolPack.h
   **************************************************************************************
    \author   陈国雄
    \brief    编辑工具包类，是所有编辑操作的入口，编辑对象、选择高亮显示、
			  跟踪图层都在这里显示。                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_)
#define AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_

#include "Map/UGMap.h"
#include "Editor/UGEditOperater.h"
#include "Editor/UGEditTool.h"
#include "Editor/UGEditCompoundTool.h"
#include "Algorithm/UGPoint.h"
#include "Editor/UGEditDef.h"
#include "Editor/UGEditSnapGrid.h"
#include "Editor/UGEditSnapBuffer.h"
#include "Editor/UGEditToolSnapPack.h"
#include "Base/UGDict.h"

namespace UGC {



// 编辑手柄选项 cgx-2004-2-18
enum UGEditHandleOption
{
	UG_EHO_LEFTBOTTOM					=	0x00000001,	//左下角
	UG_EHO_BOTTOMCENTER					=	0x00000002,	//下中点
	UG_EHO_BOTTOMRIGHT					=	0x00000004,	//右下角
	UG_EHO_LEFTCENTER					=	0x00000008,	//左中点
	UG_EHO_RIGHTCENTER					=	0x00000010,	//右中点
	UG_EHO_TOPLEFT						=	0x00000020,	//左上角
	UG_EHO_TOPCENTER					=	0x00000040,	//上中点
	UG_EHO_TOPRIGHT						=	0x00000080,	//右上角
	UG_EHO_ROTATION						=	0x00000100,	//旋转
	UG_EHO_ROTATEBASE					=	0x00000200,	//旋转基点
	UG_EHO_MOVE							=	0x00000400,	//移动
	UG_EHO_VERTEX						=	0x00000800,	//编辑顶点
};


//added by xielin 2007-05-24
//当前的编辑对象,由三部分构成,geometry对象,对象的id,对象所在的图层
struct EditGeometry {
	UGGeometry* pGeometry;
	UGint nID;
	UGLayer* pLayer;
	EditGeometry()
	{
		nID = -1;
		pLayer = NULL;
		pGeometry = NULL;
	}
};

class EDITOR_API UGTrackParameter
{
public:
	UGTrackParameter();
	virtual ~UGTrackParameter();
public:
	UGdouble		m_dFilter;						//过滤参数，值越大点越少；
	UGlong		m_lSmooth;						//光滑参数，插值的点数；
	UGlong		m_lColorTolerance;				//颜色容限值；
	UGbool		m_bAutoPan;						//是否自动移屏；
	UGColor	m_crRasterBack;					//指定栅格背景色；
	UGDatasetRaster *m_pDatasetRaster;			//栅格数据集
};

class UGMapWnd;

class EDITOR_API UGEditToolPack  
{

	friend class UGMapWnd;
	//added by xielin 
	friend class UGEditTool;
    friend class UGEditCompoundTool;
    friend class UGEditSingleObjTool;
    friend class UGEditSelectTool;

	friend class UGEditOperater;
	//added by xielin end 
public:
	UGEditToolPack();
	virtual ~UGEditToolPack();

public:	
	void Reset();

	void SetUserAction(UGint nAction);
	UGint SetSubAction(UGint nSubAction);
	UGint GetUserAction();
	UGint GetSubAction();

	void AttachMapWnd(UGMapWnd* pMapWnd);
    UGbool SetEditEnvironment();
    UGbool ClearSelection(UGGraphics* pGraphics, UGbool bSave = false);         //清除选择
	UGbool OnDraw(UGGraphics* pGraphics, UGbool bDrawHandle = true, UGbool bDrawTool = true, UGbool bIsRefresh = false, UGbool bJava = false);
	UGbool InvalidRect(UGGraphics* pGraphics, const UGRect& rect, UGbool bDrawHandle = true, UGbool bDrawTool = false, UGbool bJava = false);

	UGImage* GetMemImage();
	UGGraphics* GetMemGraphics();	
	void InflateRect(UGRect& rect);

	//added by xielin ^_^
	UGbool OnRButtonDblClk(UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnRButtonUp    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnRButtonDown  (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonUp    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonDown  (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnLButtonDblClk(UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnMouseMove    (UGGraphics* pGraphics,UGuint nFlags, UGPoint point);
    UGbool OnSetCursor    (UGGraphics* pGraphics,UGuint nHitTest, UGuint message);
    UGbool OnKeyDown      (UGGraphics* pGraphics,UGuint nChar, UGuint nRepCnt, UGuint nFlags);
    UGbool OnChar         (UGGraphics* pGraphics,UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	//deleted by xielin ^_^
	//UGbool OnKillFocus    (CWnd *pNewWnd);
	//deleted by xielin end ^_^
    //UGbool OnDraw         (UGGraphics* pGraphics, UGbool bDrawHandle = TRUE, UGbool bDrawTool = TRUE,UGbool bIsRefresh = FALSE);
	//deleted by xielin end ^_^
//  }}Afx_Win_Call窗体消息处理
	//added by xielin end ^_^


	//捕捉相关设置函数
		
	//给定旋转后的坐标点，返回旋转后的捕捉点
	//设置捕捉设置中的用户自定义角度
    void SetUserAngle( UGdouble dAngle = 0 );

	//取得捕捉设置中的用户自定义角度
    void GetUserAngle( UGdouble& dAngle );

	//设置捕捉类型
    void SetSnapType( UGint uSnapType );
	
	//取得捕捉类型
    UGint GetSnapType();

	//取得捕捉缓冲区的最大值
    UGint GetSnapBufferMaxSize();

	//设置捕捉缓冲区的最大值
    UGint SetSnapBufferMaxSize( UGint lSize );

	//取得捕捉缓冲区的最大值
    UGint GetSnapLayerMaxSize();

	//设置捕捉缓冲区的最大值
    UGint SetSnapLayerMaxSize( UGint lSize );

	//取得捕捉容限
    UGdouble GetSnapTolerance();
	
	//捕捉相关设置函数 end


protected:
	UGbool PrepareEditBoard(UGGraphics *pGraphics);
	UGbool ClearMapSelection();         //清除地图选择

	//捕捉相关函数
	

	//! \brief 设置捕捉容限
    UGdouble SetSnapTolerance( const UGdouble& dTolerance );
	
	void SnapPoint(UGPoint2D &pnt2D);

	//! \brief 实现捕捉
    void Snap(UGint                        uSnapPackType,
              UGPoint2D*                   pPntSnaping,
              UGint                        uChangedType = AFC_SNAP_CHANGED_NONE,
              UGGeometry*                pObj = NULL ,
              UGint                         nSnapHandle = 0 );

	//! \brief 设置捕捉参数
    void SetSnapParam(UGint                uSnapPackType,
                      UGPoint2D*           pPntSnaping,
                      UGint                uChangedType = AFC_SNAP_CHANGED_NONE,
                      UGGeometry*        pObj = NULL ,
                      int                 nSnapHandle = 0 );

		
	//! \brief 将编辑的线段过某一点时，将捕捉到的节点加到对象中
	//! \param point2D:捕捉到的点的坐标
	//! \param bPrev:是否为前一条线段
    UGbool GetSnapAddPoint( UGPoint2D& pnt2D, int& nIndex, UGbool& bPrev );

	//! \brief 根据索引取得捕捉线和他对应的节点的索引
    UGbool GetLineIndex( int& nIndex, UGint& lLineIndex, UGint& lVertexIndex );

	//! \brief 添加一个控制点到当前编辑对象中
	UGbool InsertPointToGeometry( const UGPoint2D& pnt2D );
	
	//! \brief 清除捕捉对象
    UGbool SnapClearDraw ( UGGraphics* pGraphics );

	//! \brief 画出捕捉标记
    UGbool SnapDraw      ( UGGraphics* pGraphics);

	//! \brief 画出捕捉标记
    UGbool SnapDrawExt   ( UGGraphics* pGraphics ,UGbool bDrawHandle=TRUE);

	//! \brief 将指定的区域内的捕捉标记重画
    UGbool UpdateReMakeSnap( UGRect2D& rc2D );

	//! \brief 生成捕捉网格
    void SnapMakeGrid();

	//! \brief 生成捕捉网格
	void SnapMakeGrid(UGLayer * pLayer, UGRecordset * pRecordset);

	//! \brief 目前未用
    void SnapMakeEdiObjGrid();

	//! \brief 点在线的端点上
	void Point_On_LineStartOrEnd();

	//! \brief 点和别的图素点重合
    void Point_On_Point();

	//! \brief 点在别的图素线上
    void Point_On_Line();

	//! \brief 点在线性图素的中点
    void Point_In_Line_Middle();

	//! \brief 在其他线性图素的延长线上
    void Point_At_Line_Extend();

	//! \brief 和其他图素点水平、垂直
    void Point_Extend_On_Point();

	//! \brief 同一线段成固定角度
    void Line_Fix_Angle();

	//! \brief 固定长度
    void Line_Fix_Length();

	//! \brief 线和其他图素相交
    void Line_On_Point();

	//! \brief 线段水平、垂直
    void Line_Is_Horv();

	//! \brief 和其他图素线段平行
    void Line_Parallel_Line();

	//! \brief 和其他图素线段垂直
    void Line_Vertical_Line();

	//! \brief 栅格中线
	void Raster_Middle();

	//! \brief 栅格边缘线
	void Raster_Edge();

	//! \brief 选中对象后，可以设置选中对象的捕捉点，然后按照这个捕捉点来捕捉
	void SetUserSnapPoint(UGPoint2D pnt2D);

	//捕捉相关函数 end

	//地图改变后作相应的处理，如：重新设置捕捉格网
    UGbool OnMapChanged();

	//! \brief 绘制默认的捕捉标记
	void DrawDefaultSnapStyle(UGGraphics* pGraphics,UGEditSnapElement* pElement);

protected:
	//! \brief 		用于最终显示的内存Graphics。
	UGGraphics* m_pMemGraphics;
	//! \brief 		用于最终显示的内存Image。
	UGImage* m_pMemImage;

	//! \brief 当前正在操作的编辑图层，是m_EditableLayers中的一个，保存对象的时候动态设置当前操作的编辑图层
	//! \brief 如果是添加对象，那么让m_pCurEditLayer等于m_pCurrentLayer既可
	UGLayer* m_pCurEditLayer;

	//! \brief 当前图层，添加的对象都放在当前图层中
	UGLayer* m_pCurrentLayer;

	//! \brief 		可编辑图层list，用于多图层编辑模式。 added by xielin 2007-04-13
	UGList<UGLayer*> m_EditableLayers;
	
	//! \brief 		资源库的指针。
	UGResources* m_pResources;
	//! \brief 		显示环境的指针。
    UGDrawing* m_pDrawing;
	
	
	//! \brief 		地图图层集合的指针。
	UGLayers* m_pLayers;
	//! \brief 		地图模拟窗口的指针。
	UGMapWnd* m_pMapWnd;

	UGbool						m_bTrackingGeometryLocked;//是否进入了tracked事件，用以判断是否可以释放trackGeometry! ——黎涛,2001/4/13
	UGbool						m_bDelyReleaseTrackingGeometry;//解除锁定时是否释放trackGeometry ——黎涛,2001/4/13
    
	// Snap 
    UGEditSnapPointGrid        m_SnapPointGrid;//捕捉点格网
    UGEditSnapLineGrid         m_SnapLineGrid;  //捕捉线格网
    UGEditSnapBuffer           m_SnapBuffer;   //编辑捕捉缓存 
    UGEditToolSnapPack         m_SnapParamPack;//编辑捕捉工具包
    //UGEditSnapLineChart        m_SnapLineChart;//捕捉线表

public:
	//捕捉对外public的成员变量
	UGdouble                       m_dUserAngle; //固定角度捕捉时的固定角度
	UGint                        m_uSnapType;//当前的地图操作
    UGint                        m_lLocateZone;  // 定位区
    UGint                        m_lSmallLine;   // 短线大小
    UGbool                        m_bEditGeometry; //捕捉时是否打断捕捉线
	//捕捉的风格这样来设计，提供可以设置捕捉线颜色、捕捉点颜色的变量，和sfc一样，然后提供一个dict，可以设置每种捕捉的风格
	//绘制的时候先判断某种捕捉是否在dict中style不为NULL，如果不为NULL，就按照这个style来绘制，包括线型，点符号风格等
	//如果为NULL，就按照捕捉线颜色，捕捉点颜色来绘制，默认dict中的style都是NULL
	UGDict<UGint,UGStyle*> m_snapStyles;  //所有捕捉绘制的风格集合
	UGColor                    m_SnapLineColor; //捕捉线的颜色(最好不同的捕捉能设置不同的风格，这样效果更好,等待修改)
    UGColor                    m_SnapPntColor;//捕捉点的颜色(最好不同的捕捉能设置不同的风格，这样效果更好,等待修改))
    UGint                        m_lLogicZone;   
    UGint                        m_lSnapLayerMaxSize;//最大捕捉图层可视范围内对象个数
    UGdouble                      m_dFixLength;   // 固定线长
    UGdouble                     m_dLocateZone;  // 定位区
    UGdouble                      m_dSmallLine;   // 短线大小
	UGint                         m_SnapSequence[AFC_SNAP_KIND_COUNT];//捕捉队列
	UGPoint2D					m_UserSetSnapPoint;   //用户设置的选中对象的捕捉点,移动，拉伸，旋转的时候就按照这个设置的捕捉点来捕捉，否则就用鼠标点来捕捉
	UGbool						m_bUseSnapPoint;
	//捕捉对外public的成员变量 end
protected:
 	void                        ( UGEditToolPack::* m_pSnapFunction[AFC_SNAP_KIND_COUNT] ) ( void );
    // image snap attributes
	
	

    UGint                        m_lImgZone;   // 影像定位区
    UGint                        m_lImgMaxBackColor;
    UGint                        m_lImgMinBackColor;
    UGint                        m_lImgThinCount;
    UGdouble                      m_dImgGrad;
    
	UGuint                        m_edittoolshape;//编辑类型，几何对象的形状
	UGuint 						m_uSubToolShape;//子工具类型
    UGuint                        m_eAccessibilityActionPointMode;//节点编辑模式
    
	
    UGEditSelectTool           m_SelectTool;//选择工具
    UGEditSingleObjTool        m_SingleObjTool;//节点编辑和绘制对象工具
	UGEditCompoundTool	        m_CompoundTool;//复合编辑工具

    UGEditOperater				m_EditOperater;//编辑操作
    
	UGList<EditGeometry*>                 m_SelectedEditGeometrys;  //选中编辑对象数组
	
    // editing attributes
	//{{由于要支持同时选中多个对象，所以需要保存所有编辑对象的ID,
	//而不是一个对象的ID，在此用数组来保存一组对象的ID--黎涛，2000.1.10
    
	UGint                       m_lCurEditGeometryID;//当前编辑对象的ID
	
	

	//}}由于要支持同时选中多个对象，所以需要保存所有编辑对象的ID,
	//而不是一个对象的ID，在此用数组来保存一组对象的ID--黎涛，2000.1.10
	
	UGRect2D						m_rectPosition;//选择对象的范围——黎涛，2001/2/6

	
    UGint                        m_lCurEditGeometryType;//当前编辑对象的类型
    UGbool                        m_bCurEditObjModified;//当前编辑对象是否有所改变
    
    UGbool                        m_bSnapNeedReMakeGrid;//是否需要重新建立捕捉格网
    
    UGbool                        m_bNeedInvalid;//是否要刷新
    UGRect2D                     m_rcNeedInvalid;//刷新范围
    UGPoint2D                    m_pntNeedInvalid;//需更新的点
    UGPoint                      m_MouseDevicePoint;
    // text attributes
    UGColor                    m_colorDrawingObj;
    // text attributes
    UGTextStyle                m_textparam;//注记参数
    // how many point do you want to make from each two point
    UGint                         m_nPointCountEach;//用于样条
    UGint                         m_nPixCountEach;//用于样条
    // geometry style
    UGStyle                 m_geoStyle;//编辑对象的风格
    UGStyle                 m_DrawGeoStyle;//绘制风格
	UGStyle					m_AssistantLineStyle;  //辅助线风格
    // symbol attributes
	UGMarkerSymParam				m_symParam;//符号参数
    UGMarkerSymParam          m_DrawsymParam;//绘图的符号风格
	UGMarkerSymbol                   m_symbol;//符号
	UGPoint2D m_pntInputed;      //输入点，该点记录了用户输入的坐标，与m_bPointInputed
	UGbool m_bPointInputed;       //是否存在输入点，如果存在，在处理mousedown消息时，用m_pntImputed代替屏幕上选取的点

	UGint       m_nEditCursorShape;//编辑光标得形状
	UGbool m_bForceCancel;    //在进行一些地图操作（如：绘制图层时），强制停止操作
protected:
	UGPoint2D m_pntOldMapCenter; //上一次地图旋转中心
	UGdouble   m_dOldMapRotation; //上一次地图旋转角度

	UGuint m_dwEditHandleOption; // 编辑手柄选项
	UGbool m_bEditCancel;
	UGbool m_bNeedSendEditEvent;

	UGDrawParamaters*			m_pMapDrawParamaters;//绘图参数
    UGDrawCache*				m_pMapDrawCache;//绘图缓存

	//取得跟踪几何对象的指针
	UGGeometry *m_pTrackedGeometry;		//by sgf -- 1999.10.16

	UGArray<UGGeometry*> m_TrackerGeometrys; //绘制时候的控制点等对象数组，added by xielin 2007.4.3

	UGEditGeometryParam        m_structGeometryParam;

	UGbool m_bAutoBreak;          //编辑线或网络数据集时是否自动打断

	UGbool m_bAutoAlongClip;		//是否自动进行沿线裁减

	
	UGbool                        m_bNeedSendGeometryParam;

	UGint  m_nEndEditDragCount;

	
public:
	//! \brief 设置编辑Handle选项
	UGbool IsEditHandleEnable(UGint dwHandleOption);
	void SetEditHandleEnable(UGint dwHandleOption,UGbool bEnable);

	//! \brief 获取当前编辑对象的类型
    UGuint GetMapAction();

	//! \brief 判断该控制点是否在选中控制点的范围之内
	//! \param nHandle:当前控制点句柄
	UGbool IntheSeletPointsRange(UGGeometry* pGeometry, UGint nHandle );
	
	//以下函数用于坐标转换
	//MapToDevice:地理坐标转为屏幕坐标
	//DeviceToMap:屏幕坐标转为地理坐标
    //{{ change coordinate between map and mapmoded device_context, but not real wnd coordinate
	void MapToDevice(const UGSize2D & szSource, UGSize & szTarget);
	void DeviceToMap(const UGSize & szSource, UGSize2D & szTarget);
	void MapToDevice(const UGRect2D & rcSource, UGRect & rcTarget);
	void DeviceToMap(const UGRect & rcSource, UGRect2D & rcTarget);
	void MapToDevice(const UGPoint2D & pntSource, UGPoint & pntTarget);
	void DeviceToMap(const UGPoint & pntSource, UGPoint2D & pntTarget);
	UGlong MapToDevice(UGdouble lSize);
	UGdouble DeviceToMap(UGlong lSize);
    //}} change coordinate between map and mapmoded device_context, but not real wnd coordinate

	//! \brief 刷新选择对象
    UGbool InvalidSelect(UGGraphics* pGraphics,UGbool bDrawHandle=TRUE);
	void CommitEdit(UGGraphics* pGraphics);          //确认编辑  //add by litao
	UGbool CalcSelPosition();				//计算选中对象总的范围——黎涛，2001/2/6
	//! \brief 刷新指定范围内的地图
    void UpdateMap( UGRect2D& rcInvalid );
	//{{为了支持多个对象的Resize,添加以下函数——黎涛，20001/2/6
	void Rotate(	         //旋转选中对象
		UGGraphics* pGraphics,            
		UGPoint pntRotateBase,//旋转基点
		UGPoint pntNew,       //旋转放开鼠标处的点 （终止点）
		UGPoint pntOld);      //按下鼠标时的点（起始点）
	//! \brief 刷新指定对象
    UGbool InvalidObj( UGGraphics* pGraphics, UGGeometry* pEditObj, UGbool bReDraw = TRUE, UGbool bDrawHandle = FALSE );

	//! \brief 刷新指定对象
    UGbool InvalidObj( UGGraphics* pGraphics, UGGeometry* pEditObj, UGRect& rtAdd, UGbool bDrawHandle = FALSE );

	//! \brief 由圆等对象转换为折线时根据长度和这个东东判断应生成多少点
    UGdouble GetTolerenceDist();
	
	//! \brief 返回计算样条时是每断的插入数目
    UGint  GetPointCountEach();

	UGdouble GetMapTolerenceSelect();

	//! \brief 通过编辑获得一个几何对象
    void GetGeoObjFromEditObj( UGGeometry** ppGeometry, UGGeometry** ppEditObj );// create a new geometry obj

	void UserAdjustInputPoint(	//允许用户调整输入点的坐标
			UGdouble &dx,
			UGdouble &dy,
			UGdouble &dz,
			UGlong lFlag=0);//输入的点是是否为三维点，如果是lFlag=1,否则lFlag=0

	//! \brief 读取节点编辑模式
    UGuint GetAccessibilityActionPointMode();

	//! \brief 设置节点编辑模式
	UGbool SetAccessibilityActionPointMode( UGuint eMode);

// 	UGint HitTest(UGGeometry* pGeometry,UGPoint& point);//取得鼠标位置对应的拖动句柄——黎涛，2001/2/7

	//! \brief 根据光标坐标获得控制点句柄
	//! \param point:光标位置（屏幕坐标）
	//! \param bSelected:
	//! \param bPointEdit
	UGint  HitTest(UGGeometry* pGeometry, UGPoint& point, UGbool bSelected = TRUE, UGbool bPointEdit = TRUE );
	
	UGint HitTestHandle( UGGeometry* pGeometry,UGPoint& point, UGint nThisDragMode );

	void DrawTracker(UGGraphics* pGraphics);//画出控制点——黎涛，2000/2/7

	//added by xielin ^_^ 画出单一编辑对象的控制点,把obj中的DrawTracker移动到这里了
	//! \brief 画出拖动或旋转的控制点
    void DrawTracker( UGGraphics* pGraphics,UGGeometry* pGeometry,UGuint state);

	UGGeometry * PickObject(  //拾取几何对象
		UGGraphics* pGraphics,			  //设备描述表	
		UGPoint point		  //选中点	
		);// ——add by 黎涛,2001/2/26 

	UGGeometry* PickSymbolAt(//选出点中的符号
		UGGraphics* pGraphics,			 //设备描述表	
		UGPoint point 		 //选中点	
		);// ——add by 黎涛,2001/2/26 

	//! \brief 重新设置编辑参数
    void ResetEditingParam();                                                   // reset editing parameter such as: id,type

	//! \brief 删除当前编辑对象
    UGbool DeleteCurEditObj( UGGraphics* pGraphics );                                          // delete the editing obj

	//! \brief 当前编辑时跟踪状态
	UGbool IsTrackEnable();					//by sgf -- 1999.10.16

	//! \brief 释放跟踪的几何对象
	void ReleaseTrackedGeometry();			//by sgf -- 1999.10.16

	//modified by xielin 加一个geometry参数，用于获取指定对象的句柄，如果geometry为null，就获取选中对象的句柄
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle,UGRect& rect);//取得句柄对应的矩形区域

	//added by xielin ^_^ 把EditObj的函数放在这里来实现
	//根据句柄查询较大范围，此范围通常用来画出选中节点
	//nHandle  句柄
	//rect   查询到的范围
    UGint GetLargeHandle( UGGeometry* pGeometry,UGint nHandle, UGRect& rect);

	//根据句柄查询较大范围，此范围通常用来画出选中节点
	//point  指定点（屏幕坐标）
	//rect   查询到的范围
    void GetLargeHandleRect( UGPoint& pnt, UGRect& rect);



	void GetHandleRect(UGPoint& point,UGRect& rect);//取得句柄点对应的一个矩形区域

	//modified by xielin 加一个geometry参数，用于获取指定对象的句柄，如果geometry为null，就获取选中对象的句柄
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle,UGPoint2D &point);//取得句柄对应的点（地理坐标）

	//modified by xielin 加一个geometry参数，用于获取指定对象的句柄，如果geometry为null，就获取选中对象的句柄
	UGint GetHandle(UGGeometry* pGeometry,UGint nHandle, UGPoint& point);//取得句柄对应的点（屏幕坐标）

	//! \brief 获取文本对象的编辑节点
	UGint GetGeoTextHandle(UGGeoText* pGeoText,UGint nHandle,UGPoint2D& point);

	//! \brief 取得当前的编辑工具
    UGEditTool* FindEditTool();

	//! \brief 返回是否可以编辑
	UGbool IsEditEnabled();

	//! \brief 返回某种编辑类型是否可用
	UGbool IsEditToolEnabled(UGuint nEditToolType);

	void OnObjectPicked(										//将编辑图层中选中的对象变为编辑状态	 
					UGGraphics* pGraphics,								//地图窗口的设描述表指针
					UGSelection* pSmRandomSelection,	//选择集指针
					UGbool bReQuery=FALSE);					//是否重新查询
	//★★★★★★★★★★★★★★★★★★★★★★★★注意！！★★★★★★★★★★★★★★★★★★★★★★★★★//
	//★    在通常情况下，bRequery参数为false,此时必须满足的条件是可编辑图层的可编辑数据集(m_pEditableLayer-> ★//
	//★m_pEditRecordset)必须没有变化，在交互式编辑中，即进行点选、框选、圆选时此条件是满足的，如果类库使用者 ★//
	//★通过别的方式比如CSmRandomSelection::FromRecrodset方法得到可编辑图层的选择集时，该图层可编辑数据集改变 ★//
	//★，此时，bReQuery参数应该设为TRUE!                                                                     ★//
	//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★//


	//通过几何对象来取得一个编辑对象
    void GetEditObjFromGeoObj( UGGeometry* pGeometry, UGGeometry** ppEditObj );// create a new edit obj
	
	//建立编辑环境
	//pSmResources:当前工作空间中的资源对象指针
	//pMapDrawParamaters:地图的绘制参数
	//pMapDrawCache:地图缓冲区
	//pMapRandomSelection:地图选择对象指针
	//pListLayers:图层指针链表
//    UGbool AttachDrawEnvironment(UGResources *pSmResources, 
//			UGDrawParamaters* pMapDrawParamaters,
//            UGDrawCache* pMapDrawCache,
//            UGSelection * pMapRandomSelection ,
//            UGLayers * pListLayers );


	UGbool IsSelected(UGGeometry* pEditObj);

	//! \brief 添加一个新的编辑对象
    UGbool AddNewEditObj( UGGraphics* pGraphics, UGGeometry* pEditObj );                      // by user create a new obj

	//! \brief 更新指定的编辑对象
    UGbool UpdateEditObj( UGGraphics* pGraphics, UGGeometry* pEditObj );                      // by user modify the editing obj (it is not save to map)
    
	//将编辑对象保存到地图
    UGbool SaveGeoObjIntoMap( UGGeometry* pEditObj );                            // save to map

	//设置编辑光标
	void SetEditCursorShape(UGint nCursorShape);

	//清除编辑工具
    void ClearEditingTool();// clear the tool when user's action changed

		//返回可编辑图层的类型,如果是跨图层编辑，那么获取的是当前图层，等待添加跨图层编辑相关 ^_^
	UGint  GetEditableLayerType();

	//设置记录集到编辑图层，如果是跨图层编辑，这里要做修改，等待添加跨图层编辑相关 ^_^
	void SetEditRecordsetToLayer();

	//在地图上指定的点处取一个对象
    UGGeometry* ObjectAt(const UGPoint& point);

	void Clear();//清除所有参数

	//! \brief 取得需要发送的编辑参数
    UGbool GetNeedSendGeometryParam();
	
	//! \brief 设置需要发送的编辑参数
    UGbool SetNeedSendGeometryParam( UGbool bNeedSendGeometryParam );

	//! \brief 取得编辑对象的编辑参数
    void GetGeometryParam( UGEditGeometryParam& structGeometryParam );

	//! \brief 设置编辑对象的编辑参数
    void SetGeometryParam( const UGEditGeometryParam& structGeometryParam );

	//! \brief 取得编辑对象的编辑参数
    void GetGeometryParam( UGPoint2D &pntCurrent, UGdouble &dCurrentLength, UGdouble &dCurrentAngle, UGdouble &dTotaleLength, UGdouble &dTotaleArea );

	//! \brief 设置编辑对象的编辑参数
    void SetGeometryParam( const UGPoint2D &pntCurrent, UGdouble dCurrentLength = 0, UGdouble dCurrentAngle = 0, UGdouble dTotaleLength = 0, UGdouble dTotaleArea = 0 );

	//! \brief 绘制编辑对象，用于取代EditObj中的绘制
	//! \brief 第三个参数表示是否是绘制选中对象，如果是选中对象，用选中对象的图层风格来绘制，否则用geometry的style来绘制
	void DrawEditObj(UGGeometry* pGeometry,UGGraphics* pGraphics,UGbool bIsSelectionGeometry = true);
	
	//! \brief 处理单个geometry对象的旋转，主要是因为点符号的旋转和其他对象的旋转处理方式不同，所以统一处理一下
	//! \brief 传入的第一个对象为修改的对象，第二个对象为备份的对象
	void RotateGeometry(UGGeometry* pGeometry,UGGeometry* pGeoBak, UGPoint pntRotateBase, UGPoint pntNew, UGPoint pntOld);

	//! \brief 处理单个对象的resize
	void ResizeGeometry(UGGeometry* pGeometry,UGGeometry* pGeoBak,UGint nDragHandle,UGPoint2D pnt2D);


	UGdouble GetTotalLength(UGGeometry* pGeometry);

	UGdouble GetTotalArea(UGGeometry* pGeometry);

	void GetPosition(UGGeometry* pGeometry,UGRect& rect);

	//! \brief 根据句柄值设置当前的光标形状
	//! \param nHandle:操作句柄
    UGint  GetHandleCursor(UGGeometry* pGeometry,UGint nHandle);

	//! \brief 判断给定对象是否选中,传入的是设备坐标
	UGbool IsSelectedEditObj(UGGeometry* pGeometry,const UGPoint &point);

	//! \brief  处理编辑事件函数
	UGbool GetNeedSendEditEvent();
	void SetNeedSendEditEvent( UGbool bNeedSendEditEvent);

	UGint InsertPoint( UGGraphics* pGraphics, UGGeometry* pGeometry,const UGPoint point);


	//栅格矢量化
	//! \brief  自动跟踪参数
	void SetTrackParameter(UGTrackParameter &TrackParameter);
	void GetTrackParameter(UGTrackParameter &TrackParameter);
	void AutoPan(UGPoint2D pntViewCenter);
	UGbool IsAutoTracking();
	//栅格矢量化 end
	

	//! \brief 是否可以剪切
	UGbool IsCutToolEnabled();

	//! \brief 是否可以删除
	UGbool IsDeleteToolEnabled();

	//! \brief 是否可以被拷贝
	UGbool IsCopyToolEnabled();

	//! \brief 是否允许粘贴
	UGbool IsPasteToolEnabled();

	//! \brief 是否能够撤销
	UGbool IsUndoToolEnabled();

	//! \brief 是否可以恢复
	UGbool IsRedoToolEnabled();

	//! \brief 剪切
    UGbool OnCut(UGGraphics* pGraphics);

	//! \brief 删除
    UGbool OnDelete(UGGraphics* pGraphics);

	//! \brief 编辑
    UGbool OnCopy(UGGraphics* pGraphics);

	//! \brief 粘贴
    UGbool OnPaste(UGGraphics* pGraphics);

	//! \brief 撤销
    UGbool OnUndo(UGGraphics* pGraphics);

	//! \brief 恢复
    UGbool OnRedo(UGGraphics* pGraphics);

	UGbool Break(                            //在数据集中寻找与指定对象相交，然后从交点将其断开
		UGDatasetVector *pDtV,              //数据集
		UGGeometry * pGeoBreak,         //打断所用的几何对象，只能是线、点对象
		UGSelection *pSelectionNew=NULL,//打断生成对象选择集 
		UGbool bBreakSelf=TRUE,              //是否打断对象本身（只有打断对象为线对象时此参数才有用）
		UGbool bUseEditHistory=TRUE);             //是否放入EditHistory

	UGbool Clip(                             //在数据集中寻找与指定对象相交的对象，然后用查询出的对象对制定对象进行裁减
		UGDatasetVector *pDtV,              //数据集
		UGGeometry * pGeoClip);         //需要裁减几何对象，只能是面对象
										   //如果对象被裁减了则返回TRUE,如果没有被裁减则返回FALSE 	

	//! \brief 取得跟踪的几何对象
	UGGeometry * GetTrackedGeometry();	//by sgf -- 1999.10.16


};

}

#endif // !defined(AFX_UGEDITTOOLPACK_H__5911E61C_A45F_4FC6_BD25_09F9F966F03F__INCLUDED_)

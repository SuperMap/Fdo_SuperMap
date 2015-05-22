// UGEditTool.h: interface for the UGEditTool class.
//=====================================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 2.0
// 作  者：			宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGEditTool.h
// 类  名：			UGEditTool、UGEditSelectTool、UGEditFixHandleTool、UGEditSingleObjTool、UGEditSubTextTool
// 父  类：			UGEditSelectTool-->UGEditTool
//					UGEditFixHandleTool-->UGEditTool
//					UGEditSingleObjTool-->UGEditTool
//					UGEditSubTextTool-->UGEditTool
// 子  类：			
// 功能说明：		处理各种编辑对象的消息
// 调用说明：		
//=====================================================================================

#if !defined(AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_)
#define AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Base/UGList.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Geometry/UGEditType.h"
#include "Map/UGLayer.h"


#define UG_EDIT_TRACKING_MOVE	0
#define UG_EDIT_TRACKING_LEFT	1
#define UG_EDIT_TRACKING_RIGHT	2

namespace UGC {

class UGEditToolPack;
class UGEditObj;
class UGRasterToVector;
class UGEditCompoundTool;
class EDITOR_API UGEditTool  
{
public:
	UGEditTool();
	virtual ~UGEditTool();
public:
// Virtual Implementation
	virtual UGbool OnRButtonDblClk(UGGraphics *pGraphics,UGuint nFlags, UGPoint point);
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);     //编辑对象鼠标右键弹起的消息处理
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);   //编辑对象鼠标右键按下的消息处理
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);     //编辑对象鼠标左键弹起的消息处理
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);   //编辑对象鼠标左键按下的消息处理
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //编辑对象鼠标左键双击的消息处理
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);		//编辑对象鼠标移动的消息处理
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);             //根据鼠标的位置来改变光标得形状 
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//键盘消息的响应
    virtual UGbool OnChar( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);   //键盘消息的响应
    virtual UGbool OnDraw( UGGraphics *pGraphics);       //在指定设备中画出编辑对象   
    virtual UGbool OnKillFocus( UGGraphics *pGraphics ); //失去焦点
    virtual UGbool Clear( UGGraphics *pGraphics );       //清除编辑对象

    virtual UGbool OnUndo( UGGraphics *pGraphics);       //撤销操作  
    virtual UGbool OnRedo( UGGraphics *pGraphics);       //恢复操作

// Real Implementation
    UGbool AttachToolPack( UGEditToolPack* pToolPack );  //和指定的UGEditToolPack对象建立联系

	virtual UGbool IsUndoToolEnabled();		//判断是否可以撤销上一步操作
	virtual UGbool IsRedoToolEnabled();		//判断是否可以恢复上一步操作

	virtual UGbool EditCompleted(UGGraphics *pGraphics);   //新增一个对象的编辑操作完成



	
//判断该控制点是否在选中控制点的范围之内
//nHandle:当前控制点句柄
	virtual UGbool IntheSeletPointsRange( UGint nHandle );
// 这个函数是在Sizeing时调用的，可以使外接矩形成为正方形   *note19991202
    virtual void MakeSquareBoundConer( UGGraphics* pGraphics, UGGeometry* pEditObj, UGint nHandle, UGPoint2D& pnt2D );

	//通过编辑类型获取结束编辑的点击次数，如果自定义对象，就用传入的点击次数
	UGint GetEndEditDragCountFromType(UGint nType);
	//added by xielin 2007-04-25 把编辑对象的一些函数放到这里来实现  end
//Attribute
protected:  //改为保护成员变量——黎涛，2000.12.18
    // Undo buffer is a stack which bottom is open
	//deleted by xielin ^_^
    // UGEditUndoBuffer  m_UndoBuffer; //撤销缓冲区
	//deleted by xielin end ^_^
    UGEditToolPack*   m_pToolPack;  //指向编辑工具包的指针
    UGPoint2D           m_pnt2DDown;  //记录鼠标按下时的坐标
    UGPoint2D           m_pnt2DLast;  //记录鼠标放开时的坐标
	UGPoint2D			m_pnt2DMouseMove;  //记录鼠标移动时候的坐标

	UGArray<UGPoint2D> m_arrayPnts;  //用来记录点击过的点
	UGArray<UGPoint2D> m_arrayUndoPnts; //用来记录undo的点（绘制对象过程中）
public:
    UGGeometry*        m_pEditObj;   //指向编辑对象的指针 
	UGGeometry*		   m_pAssistantObj;  //指向辅助线对象的指针
	//added by xielin 2007-05-11 增加一个辅助点数组，用来保存辅助点数组
	UGArray<UGEditType::EditAssistantPoint> m_arrayAssistantPoints;

public:
	virtual UGGeometry * GetEditObj();

	

	static void HilightRecordset(										//高亮显示记录集
								UGGraphics *pGraphics,							//设备描述表指针
								UGRecordset *pRs,					//记录集
								UGDrawParamaters *pDrawParamater,  //地图绘制参数
								UGStyle *pGeoStyle);            //高亮风格
	static void DrawDotLine(				//画点线
							UGGraphics *pGraphics,		//设备	
							UGPoint pntHead, //起点
							UGPoint pntTail,	//终点
							UGlong crPen);

	static void DrawControlPoint(				//画控制点
								UGGraphics *pGraphics,       //设备描述表指针
								UGPoint point,	//坐标点
								UGColor crPen);  

	static void DrawHandleRect(				//画编辑手柄
								UGGraphics *pGraphics,       //设备描述表指针
								UGRect rect,	//坐标范围
								UGbool bEditable = TRUE,
								UGint nHandleType = UGEditType::NormalHandle);//是否可编辑

	static void DrawRotationRect(				//画旋转手柄
								UGGraphics *pGraphics,       //设备描述表指针
								UGRect rect,	//坐标范围
								UGbool bEditable = TRUE);//是否可编辑
								  
	

    UGint                 m_DragHandle;//操作句柄，通过该句柄可以确定用户正在做什么操作 
	UGEditCompoundTool* m_pMainEditTool;//编辑多段线或复合对象时的主工具,应该定义为UGEditCompoundTool，先定义为UGEditTool吧
	
};

class EDITOR_API UGEditSelectTool : public UGEditTool
{
//Constructer
public:
    UGEditSelectTool();
    virtual ~UGEditSelectTool();
//Implementation
public:
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //选择对象鼠标右键弹起的消息处理
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标右键按下的消息处理
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键弹起的消息处理
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键按下的消息处理
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键双击的消息处理
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标移动消息
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//选择光标的形状
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//选择按键消息处理
    virtual UGbool OnDraw( UGGraphics *pGraphics);//画出选择对象

	UGbool IsMirrorToolEnabled();//选择的对象是否允许被镜像
    UGbool OnMirror( UGGraphics *pGraphics, int nMirrorType );//镜像选择对象  
	
	//下面几个接口的功能在mapwnd中实现了，这里就不实现了。
	UGbool IsCutToolEnabled();//是否允许被剪切
	UGbool IsDeleteToolEnabled();//是否允许被删除
	UGbool IsCopyToolEnabled();//是否允许被复制
	UGbool IsPasteToolEnabled();//是否允许被粘贴
    UGbool OnCut( UGGraphics *pGraphics );//剪切对象
    UGbool OnDelete( UGGraphics *pGraphics );//删除对象
    UGbool OnCopy();//复制对象
    UGbool OnPaste( UGGraphics *pGraphics );//粘贴对象
	//上面几个接口的功能在mapwnd中实现了，这里就不实现了。
    virtual UGbool OnUndo( UGGraphics *pGraphics );//取消操作
    virtual UGbool OnRedo( UGGraphics *pGraphics );//恢复操作
// Real Implementation
    UGbool ClearParam();//清除所有参数
	virtual UGbool ClearSelection();       //清除编辑对象
// Static Implementation
	//deleted by xielin ^_^
    //响应Timmer消息
	//static VOID CALLBACK UGEditSelectTool::TimerProc(  HWND hwnd, UGuint uMsg, UGuint lpThis, DWORD dwTime );
	//deleted by xielin ^_^ end 
//Attribute
public:
	UGbool PntInRotateBaseRect(          //测试一个点是否在旋转基点范围之内
		UGPoint pntHittest);            //测试点

	virtual UGGeometry* GetEditObj();
    UGGeometry*        m_pEditObjBak;//编辑对象的备份
    UGGeometry*        m_pCopyedObj;//复制对象时保存复制对象
	//modified by xielin ^_^
	UGList<UGGeometry*>        m_Selection;//选中编辑对象数组备份
	//modified by xielin end ^_^
    UGuint               m_editSelType;//选择类型
    UGRect       m_skewBound;  //外接矩形，好像没有用到嘛
	UGRect2D				m_rectPosition;//改变区域大小
	UGint                 m_nDragNodeBegin;//选中的起始节点
    UGint                 m_nDragNodeEnd;//选中的尾节点
    UGuint                m_uDragNodeMode;//拖拽模式
    clock_t                m_dwTickCount;//保存时钟信息
	
	UGPoint2D			m_pntRotateBase;//旋转基点
	//double				m_dAngleRotateStart;//旋转起始角
protected:
	void MoveHandle(				//移动控制点以改变对象的大小	
		UGGraphics *pGraphics,					//设备描述表
		UGint &nHandle,				//控制点的句柄
		const UGPoint2D &pntOld,		//控制点原来的坐标
		const UGPoint2D &pntNew		//控制点现在的坐标
		);//ADD BY LITAO ——黎涛，20001/2/7
};

class EDITOR_API UGEditSingleObjTool : public UGEditTool
{
//Constructer
public:
    UGEditSingleObjTool ();
    virtual ~UGEditSingleObjTool ();
//Implementation
public:
	virtual UGbool OnRButtonDblClk(UGGraphics *pGraphics,UGuint nFlags, UGPoint point);
    virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //选择对象鼠标右键弹起的消息处理
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标右键按下的消息处理
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键弹起的消息处理
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键按下的消息处理
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键双击的消息处理
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标移动消息
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//选择光标的形状
    virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//选择按键消息处理
    virtual UGbool OnDraw( UGGraphics *pGraphics); //在指定设备中画出编辑对象   
    virtual UGbool OnUndo( UGGraphics *pGraphics); //撤销操作
    virtual UGbool OnRedo( UGGraphics *pGraphics); //恢复操作
//Attribute
	virtual UGbool EditCompleted(UGGraphics *pGraphics); //新增一个对象的编辑操作完成


	//added by xielin 2007-04-25 把编辑对象的一些函数放到这里来实现 
	
	//判断该控制点是否在选中控制点的范围之内
	//nHandle:当前控制点句柄
    virtual UGbool IntheSeletPointsRange( UGint nHandle );
	//added by xielin 2007-04-25 把编辑对象的一些函数放到这里来实现  end

	//! \brief 重新计算辅助线和辅助点（在mousemove和回退重做的时候都要用到）
	UGbool CalAssistantLineAndAssistantPoint();
public:
	void SetPathObjSubShape(UGbyte subShape);
	//通过编辑的类型创建一个Geometry对象，创建的对象放到成员变量m_pEditObj
	UGbool CreateEditObjFromEditType(UGint nType);
	
    UGbool                m_bAutoAddPoint;//是否自动加入点
    UGbool                m_bSubMode;//是否编辑子对象模式
	//deleted by xielin ^_^
	UGRasterToVector*	m_pSmRasToVec;//半自动矢量化工具
	//deleted by xielin end ^_^
	UGbool				m_bFreeLineStart;//自由画线开始
	UGlong				m_nFreeLineStartIndex;//自由画线开始位置
	UGLayer*			m_pHatchLayer;//生成Hatch的图层
};

class EDITOR_API UGEditSubTextTool : public UGEditTool
{
//Constructer
public:
    UGEditSubTextTool ();
    virtual ~UGEditSubTextTool ();
//Implementation
public:
// Virtual Implementation
	virtual UGbool OnRButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point); //选择对象鼠标右键弹起的消息处理
    virtual UGbool OnRButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标右键按下的消息处理
    virtual UGbool OnLButtonUp( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键弹起的消息处理
    virtual UGbool OnLButtonDown( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键按下的消息处理
    virtual UGbool OnLButtonDblClk( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键双击的消息处理
    virtual UGbool OnMouseMove( UGGraphics *pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标移动消息
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//选择光标的形状
	virtual UGbool OnChar( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);   //键盘消息的响应
	virtual UGbool OnKeyDown( UGGraphics *pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//键盘消息的响应
    virtual UGbool OnDraw( UGGraphics *pGraphics); //在指定设备中画出编辑对象   
    virtual UGbool OnKillFocus( UGGraphics *pGraphics );//处理失去焦点消息
    virtual UGbool OnUndo( UGGraphics *pGraphics); //撤销操作
    virtual UGbool OnRedo( UGGraphics *pGraphics); //恢复操作
	virtual UGbool IsUndoToolEnabled();		//判断是否可以撤销上一步操作
	virtual UGbool IsRedoToolEnabled();		//判断是否可以恢复上一步操作	
// Real Implementation



	//added by xielin 2007-04-25 把编辑对象的一些函数放到这里来实现  end
//Attribute
public:
	//deleted by xielin ^_^
	//void TextEditCallBack(LPVOID pThis);
	//deleted by xielin ^_^ end 
	void SaveInputText();
	UGGeoText * HitTest(       //判断是否选中注记对象，是的话就编辑它
		UGPoint2D pntHitTest);

    UGbool        m_bSubMode;//是否对子对象操作

	UGint m_nSubTextAngle;  //在输入注记时，需要先将注记的m_nRotateAngle设置为0，所以要先将原来的角度保存，以便输入结束后恢复
};

}

#endif // !defined(AFX_UGEDITTOOL_H__87F97B9D_527B_4539_A119_32ABBECC8E1F__INCLUDED_)

// UGEditObj.h: interface for the UGEditObj class.
//
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
// 文件名：			UGEditObj.h
// 类  名：			UGEditObj、UGEditObList、UGDynPointList、UGEditFixHandleObj、UGEditDynHandleObj
// 父  类：			UGEditFixHandleObj-->UGEditObj
//					UGEditDynHandleObj-->UGEditObj
// 子  类：			
// 功能说明：		UGEditObj：对象编辑基类，提供对象编辑的基本方法
//                  UGEditObList：编辑对象链表
//                  UGDynPointList：二维点链表
//					UGEditFixHandleObj：固定句柄对象，用于改变对象大小，移动等操作
//					UGEditDynHandleObj：动态句柄对象，用于编辑节点，添加节点等操作
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_)
#define AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Editor/UGEditToolPack.h"

namespace UGC {

class UGEditToolPack;

class EDITOR_API UGEditObj  
{
public:
    enum 
	{
		ecArrow,				//箭头
        ecCross,				//十字
        ecRotation,				//旋转
        ecBeam,					//工字
        ecMove,					//移动
		ecNorthSouth,			//南北移动
		ecWestEast,				//东西移动
		ecNorthwestSoutheast,   //西北到东南的移动
		ecNortheastSoutnwest,   //东北到西南的移动
		ecCrossSnapPoint,		//点捕捉
		ecCrossSnapVertex,		//顶点捕捉
		ecCrossSnapMidpoint,	//线段中点捕捉
		ecCrossSnapLine,		//线上捕捉
		ecCrossSnapVertical,	//垂直捕捉
		ecCrossSnapParallel,	//平行捕捉
		ecMoveRotateBase,		//旋转基点

    };//编辑工具光标类型

public:
	UGEditObj( UGEditToolPack* pToolPack, UGuint shape);
	virtual ~UGEditObj();

public:
	//克隆一个编辑对象
    virtual UGEditObj* Clone();
	
	//画出编辑对象
	virtual void Draw( UGGraphics* pGraphics);
	
	//获得编辑对象的句柄的数目
	//对于固定句柄对象为9包括了改变大小的8个控制点和一个旋转控制点
    virtual UGint  GetHandleCount();

	//根据句柄获得相应控制点的值
	//nHandle:的值与控制点的关系如右图                         
	//									1---+   	  +--2    	+----3	
	//                                      |         |         |  
	//                                      |         |         |  
	//										x---------x---------x     9
    //										|   ____________    |     |
    //										|  /            \   | x---+
	//									4---x |              |  x-----5
	//										|  \____________/   |
	//										|                   |
	//										x---------x---------x
	//										|		  |         |
	//										|		  |         |
	//								    6---+         +-----7   +-----8
	//point:句柄对应的控制点的坐标值
    virtual UGbool GetHandle( UGint nHandle, UGPoint2D& point);


	//移动控制点到指定坐标
	//nHandle:控制点句柄
	//point:控制点坐标
    virtual void MoveHandle( UGint nHandle, const UGPoint2D& point );

	//移动控制点到指定坐标
	//pDC:设备描述表指针
	//nHandle:控制点句柄
	//point:控制点屏幕坐标
	//bInvalid：是否重画
    virtual void MoveHandle( UGGraphics* pGraphics, UGint nHandle, const UGPoint& point, UGbool bInvalid = TRUE );

	//移动控制点到指定坐标
	//pDC:设备描述表指针
	//nHandle:控制点句柄
	//pnt:控制点地图坐标
	//bInvalid：是否重画
    virtual void MoveHandle( UGGraphics* pGraphics, UGint nHandle, const UGPoint2D& pnt, UGbool bInvalid = TRUE );

	//移动给定的编辑对象的控制点到指定坐标
	//pDC:设备描述表指针
	//pEditObj:编辑对象
	//nHandle:控制点句柄
	//pnt2D:控制点地图坐标
    virtual void MoveHandle( UGGraphics* pGraphics, UGEditObj* pEditObj, UGint nHandle, const UGPoint2D& pnt2D );
	
    
	// 这个函数是在Sizeing时调用的，可以使外接矩形成为正方形   *note19991202
    virtual void MakeSquareBoundConer( UGGraphics* pGraphics, UGEditObj* pEditObj, UGint nHandle, UGPoint2D& pnt2D );

	//该函数只用于动态句柄对象，节点编辑时可用来插入一个控制点
	//nHandle:插入位置
	//point:插入点的屏幕坐标
    virtual void AddHandle( UGint nHandle, const UGPoint& point);
	
	//该函数只用于动态句柄对象，节点编辑时可用来插入一个控制点
	//nHandle:插入位置
	//point:插入点的地理坐标
    virtual void AddHandle( UGint nHandle, const UGPoint2D& pnt2D);

	//该函数只用于动态句柄对象，节点编辑时可用来插入一个控制点
	//point:插入点的地理坐标
    virtual void AddHandle( UGPoint2D& point);

	//deleted by xielin ^_^
	//该函数只用于动态句柄对象，删除节点编辑对象被选中的节点
	//pUndoElement:恢复堆栈元素
    //virtual UGuint DelNode( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^
	
	//该函数只用于动态句柄对象，删除编辑对象的指定节点
	//nHandle:节点句柄
    virtual UGuint DelNode( UGint nHandle );

	//deleted by xielin ^_^
	//该函数只用于动态句柄对象，插入一个控制点到编辑对象中
	//pDC:设备描述表指针
	//point:要插入点的屏幕坐标
	//pUndoElement:“恢复”堆栈元素指针
	//virtual UGint  InsertPoint( UGGraphics* pGraphics, const UGPoint point, UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//响应编辑属性事件，但目前没有用
    virtual void OnEditProperties();

	//将编辑对象移动一段指定距离
	//pDC:设备描述表指针，用于重画对象
	//sizeDelta:偏移距离，在此为屏幕坐标
    virtual void MoveTo( UGGraphics* pGraphics, const UGSize& sizeDelta);

	//将编辑对象移动一段指定距离
	//pDC:设备描述表指针，用于重画对象
	//sizeDelta:偏移距离，在此为地理坐标
    virtual void MoveTo( UGGraphics* pGraphics, const UGSize2D& sizeDelta);

	//判断点是否在对象上
	//point:选取点
    virtual UGbool IsSelect( const UGPoint& point );

	//根据句柄值设置当前的光标形状
	//nHandle:操作句柄
    virtual UGint  GetHandleCursor(int nHandle);

	//重新计算对象的范围
    virtual UGbool RecalcBounds();

	//在画圆角矩形或弧段，调整圆角矩形圆角的弯曲度或弧段的弧长时，使控制点的轨迹始终在对象上
	//nHandle:调整控制点句柄
	//point:控制点坐标（屏幕坐标）
	//nFlags:暂时没用
    virtual void AdjustPoint( UGint nHandle, UGPoint& point, UGuint nFlags = 0X00 );

	//在画圆角矩形或弧段，调整圆角矩形圆角的弯曲度或弧段的弧长时，使控制点的轨迹始终在对象上
	//nHandle:调整控制点句柄
	//point:控制点坐标（地理坐标）
	//nFlags:暂时没用
    virtual void AdjustPoint( UGint nHandle, UGPoint2D& point, UGuint nFlags = 0X00 );

	//计算需要保存的控制点数目
    virtual UGlong GetSavePointsCount();

	//取得保存的控制点的链表
	//pPoints:保存的控制点列表
    virtual void GetSavePoints( UGPoint2D* pPoints );
	
	//取得保存的控制点的链表,同时返回控制点的数目
	//pPoints:保存的控制点列表
	//nPoint:控制点的数目
	virtual void GetSavePoints( UGPoint2D*& pPoints, UGlong &nPointCount );

	//调整对象的大小
	//pDC:设备描述表
	//pEditObj:所编辑的对象
	//rtNew:对象的新范围（屏幕坐标）
    virtual void Size( UGGraphics* pGraphics, UGEditObj* pEditObj, const UGRect& rtNew);

	//调整对象的大小
	//pDC:设备描述表
	//pEditObj:所编辑的对象
	//rtNew:对象的新范围（地理坐标）
    virtual void Size( UGGraphics* pGraphics, UGEditObj* pEditObj, const UGRect2D& rtNew);

	//判断鼠标位置是否落到了控制点上，并选中控制点
	//point:光标位置
	//uThisDragMode:选中控制点的模式
    virtual UGint  HitTestHandle( UGPoint& point, UGuint uThisDragMode );

	//判断该控制点是否在选中控制点的范围之内
	//nHandle:当前控制点句柄
    virtual UGbool IntheSeletPointsRange( UGint nHandle );

	//添加一个子编辑对象
	//pEditObj:子编辑对象的指针
    virtual UGbool AddSubObj( UGEditObj* pEditObj );

	//旋转编辑对象
	//pDC:设备描述表指针
	//pEditObj:编辑对象指针
	//pntNew:旋转控制点的新位置
	//pntOld:旋转控制点的老位置
    virtual void Rotate( UGGraphics* pGraphics, UGEditObj* pEditObj,const UGPoint &pntRtOrg, const UGPoint& pntNew, const UGPoint& pntOld);

	//deleted by xielin ^_^
	//撤销操作
    //virtual UGbool Undo( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//deleted by xielin ^_^
	//重复操作
    //virtual UGbool Redo( UGEditUndoElement* pUndoElement );
	//deleted by xielin end ^_^

	//在对多边形编辑时才有用，为多边形指定位置插入一个新的控制点
	//lSubLineIndex:子对象索引
	//lVertexIndex:节点索引
	//pnt2D:插入控制点坐标
    virtual UGbool InsertNewPoint( UGlong lSubLineIndex, UGlong lVertexIndex, const UGPoint2D& pnt2D);

	//镜像
	//nMirrorType:镜像类型
	//nMirrorType:参见SmEditType
    virtual void Mirror( UGint /*nMirrorType*/ ){};

	//获取对象的总长度
    virtual UGdouble GetTotalLength(){ return 0; };

	//获取对象的总面积
    virtual UGdouble GetTotalArea(){ return 0; };

	//画出拖动或旋转的控制点
    virtual void DrawTracker( UGGraphics* pGraphics, UGuint state);
 
	//Real Implementation
	
	//获得对象范围
	//rect:范围（地理坐标）
	virtual void GetPosition( UGRect2D& rect);
	
	//获得对象范围
	//rect:范围（屏幕坐标）
    virtual void GetPosition( UGRect& rect);
	
	//根据光标坐标获得控制点句柄
	//point:光标位置（屏幕坐标）
	//bSelected:
	//bPointEdit
    
	virtual UGint  HitTest( UGPoint& point, UGbool bSelected = TRUE, UGbool bPointEdit = TRUE );
	
	//根据句柄查询控制点
	//nHandle  句柄
	//point   查询到的点
    UGbool GetHandle( UGint nHandle, UGPoint& point);
	
	//根据句柄查询范围
	//nHandle  句柄
	//rect   查询到的范围
    UGbool GetHandle( UGint nHandle, UGRect& rect);

	//根据句柄查询较大范围，此范围通常用来画出选中节点
	//nHandle  句柄
	//rect   查询到的范围
    UGbool GetLargeHandle( UGint nHandle, UGRect& rect);

	//根据指定点查询较小范围，此范围通常用来画出未选中节点
	//point  指定点（屏幕坐标）
	//rect   查询到的范围
    void GetHandleRect( UGPoint& pnt, UGRect& rect);

	//根据句柄查询较大范围，此范围通常用来画出选中节点
	//point  指定点（屏幕坐标）
	//rect   查询到的范围
    void GetLargeHandleRect( UGPoint& pnt, UGRect& rect);

	//判断是否对象范围足够小，以至于可以不显示
	//rect:对象所在范围（屏幕坐标）
    UGbool RectTooSmall( const UGRect& rect);

	//判断是否对象范围足够小，以至于可以不显示
	//rect:对象所在范围（地理坐标）
    UGbool RectTooSmall( const UGRect2D& rect);

	//获取编辑对象的形状
    UGuint GetType(){ return m_editshape; };

    static UGdouble GetCAR(UGint nCoefficient, UGdouble fSegment);

	//{{这一组静态函数将几何图形转换成折线，并返回折线的节点链表
	//pPntControls:几何图形的关键点（控制点）
	//pPntCurve:返回的节点链表
	//nCurvePoints:节点个数
    //static UGbool Cardinal ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    //static UGbool Cardinal ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool Arc      ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool RoundRect( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool Ellipse  ( UGPoint * pPntControls, UGPoint * pPntCurve, UGint nCurvePoints );
    static UGbool Arc      ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool RoundRect( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
    static UGbool Ellipse  ( UGPoint2D * pPntControls, UGPoint2D * pPntCurve, UGint nCurvePoints );
	//}}这一组静态函数将几何图形转换成折线，并返回折线的节点链表
	
	static UGbool ClipLinesectWithRect(			//将一条线段限定在矩形区域内
						   UGPoint2D &pntBegin,  //线段的端点
						   UGPoint2D &pntEnd,	//线段的端点	
						   UGRect2D rcClip);		//限定的范围	
//Attribute
public:
	virtual void Resize(                 //改变编辑对象的大小
		UGEditObj *pEditObjBk,          //备份的编辑对象
		UGPoint2D pntOldOrg,              //对象原来的参考点 
		UGPoint2D pntNewOrg,              //新的参考点
		UGdouble dXRatio,                  //x方向上的伸缩倍率
		UGdouble dYRatio);                 //y方向上的伸缩备率

    UGEditToolPack*       m_pToolPack;   //编辑工具包指针
    UGuint                   m_editshape;   //编辑几何对象的形状
    UGRect2D                m_rectPosition;//编辑对象的当前范围
	UGStyle*	       m_pStyle;      //编辑对象的风格
	UGbool				   m_bCADObj;	  //是否为参数化对象

};

//deleted by xielin ^_^
//typedef CTypedPtrList<CObList, UGEditObj*> CEditObList;
//typedef CTypedPtrList<CPtrList, UGPoint2D*> CDynPointList;
//typedef CTypedPtrList<CPtrList, UGPoint3D*> C3DPointList;
//deleted by xielin end ^_^

}

#endif // !defined(AFX_UGEDITOBJ_H__D54EB6A7_FAD5_4F29_BD46_1C5907AB4AC7__INCLUDED_)

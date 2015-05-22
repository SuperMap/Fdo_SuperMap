// UGEditType.h: interface for the UGEditType class.
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
// 文件名：			UGEditType.h
// 类  名：			UGEditType
// 父  类：			
// 子  类：			
// 功能说明：		定义SuperMap中的编辑常数
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)
#define AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace UGC {

typedef UGArray<UGPoint2D> UGPnt2DArray;
typedef UGArray<UGPnt2DArray*> UGLineArray;

class GEOMETRY_API UGEditType  
{
public:
	//编辑工具形状（类型）
    enum EditToolShape{						
        ET_None             = 0,			//空
        ET_Selection        = 1,            //选择
        ET_Point            = 21,           //点 
        ET_LineSect         = 22,           //直线
        ET_EllipseArc       = 23,			//椭圆弧
        ET_PolyLine         = 24,			//折线,支持subaction
        ET_BezierCurve      = 25,			//贝兹曲线,支持subaction
        ET_Rectangle        = 26,			//矩形
        ET_RoundRect        = 27,			//圆角矩形
        ET_Parallelogram    = 28,			//平行四边形
        ET_Circle           = 29,			//圆心圆
        ET_Ellipse          = 30,			//椭圆	
        ET_ObliqueEllipse      = 31,			//斜椭圆
        ET_PolyGon          = 32,			//多边形,支持subaction
		ET_MulitiPoint		= 33,			//多点
		//ET_ARC3P			= 33,	        //三点弧（圆弧）
        ET_Text             = 34,			//注记
        ET_BSpline          = 35,			//B样条,支持subaction
        //sET_SameDistline     = 36,			//等值线
        ET_StreamText       = 37,			//沿线注记	
		//ET_Mulitiline       = 38,           //多段线,已废除，请使用ET_PolyLineEx、ET_PolygonEx代替
		ET_Path				= 39,           //路径（不知道怎么翻译）
		ET_PolyLineEx       = 42,
		ET_PolygonEx        = 43,
		ET_Arc3P            = 44,           //三点弧
		ET_Circle3P         = 45,           //三点圆
		ET_Pie              = 46,           //派对象 
		ET_Circle2P			= 47,           //两点圆
		ET_Parallel         = 48,			//平行线,支持subaction
		//ET_Custom           = 49,	        //扩展对象

		ET_TrackPolyLine	= 55,			//半自动跟踪线
		ET_TrackBreak		= 56,			//半自动跟踪回退
		ET_TrackPolyPolygon	= 57,			//跟踪面
		ET_FreeLine			= 58,			//画笔，自由画线，支持subaction		
        ET_Cardinal		    = 59,			//Cardinal曲线，支持subaction
		ET_Hatch			= 60,			//Hatch面

		ET_SetSnapPoint		= 70,			//设置选中对象的捕捉点，移动的时候就用设置的这个捕捉点捕捉，否则就用鼠标点
    };

    enum {
        EditTool_Select = 0,
        EditTool_FixHandle ,
        EditTool_DynHandle ,
        EditTool_Text      ,
    };

	//选择模式
    enum EditSelectMode{
        ESM_None,				//空
        ESM_Move,				//移动
        ESM_MoveNode,			//移动节点
        ESM_Size,				//改变大小
		ESM_MoveRotateBase,     //移动旋转基点
    };

	//跟踪状态
	enum EditTrackerState{
        ETS_Normal,		
        ETS_Selected,
        ETS_CtrlPoints
    };
	
	//编辑交互方式
	enum EditAccessibilityAction{
        EAA_None,				//无
        EAA_EditPoint,			//编辑节点
        EAA_AddPoint,			//添加节点
        EAA_RgnMode,			
        EAA_LineMode
    };

	//删除节点返回值
    enum EditDelNodeReturnValue{
        EDHRV_NoChange,			//无变动
        EDHRV_Deleted,			//已经被删除
        EDHRV_DelObj,			//对象被删除
    };

	//节点编辑模式
    enum EditDragNodeMode{
        EDHM_NoNode = 0,		//无
        EDHM_SingleNode = 1,	//对单个节点进行操作
        EDHM_LessNode = 2,		//选择节点方式
        EDHM_MoreNode = 3,		//选择节点方式
    };

	//撤销缓冲区类型
    enum EditUndoMode{
        EUNM_CanntUndo   ,		//无法撤销
        EUNM_NewObj      ,		//新对象
        EUNM_DelObj      ,		//删除对象
        EUNM_AddSubObj   ,		//添加子对象
        EUNM_DelSubObj   ,		//删除子对象
        EUNM_AddNode     ,		//添加节点
        EUNM_DelNode     ,		//删除节点
        EUNM_MoveNode    ,		//移动节点
        EUNM_Move        ,		//移动对象
        EUNM_Size        ,		//改变对象大小
        EUNM_Rotate      ,		//旋转对象
		EUNM_CharChange  ,		//注记对象文本发生变化
        EUNM_SaveNewObj  ,		//保存新的对象
        EUNM_SaveOldObj  ,		//保存旧对象
    };
    
	//捕捉对象类型
    enum EditSnapObjType{
        ESOT_PointObj   ,		//点对象
        ESOT_LineRgnObj ,		//线或面对象
        ESOT_SpecialObj ,		//特殊对象
    };
    
	//镜像方式
    enum EditMirrorType{
		EMiRT_Horizontal = 0,	//水平镜像
        EMiRT_Vertical   = 1,	//垂直镜像
        EMiRT_LeftTop    = 2,	//从左上到右下镜像
        EMiRT_RightTop   = 3,	//从右下到左上镜像
    };

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

	//编辑handle的类型，暂时分为三类，一种是普通的handle，一种是改变了颜色的handle
	//主要用于弧段等对象修改长短轴的弧段，一种是辅助点类型，画一个小叉
	enum EditHandleType
	{
		NormalHandle  = 1,
		LittleHandle  = 2,
		ControlHandle = 3,
	};

	//编辑的辅助点，包括点坐标和辅助点类型
	struct EditAssistantPoint {
		EditHandleType nType;
		UGPoint2D	pnt2D;
	};
};



}

#endif // !defined(AFX_UGEDITTYPE_H__87D77BB2_EE0B_4864_B131_DA7B320AC881__INCLUDED_)

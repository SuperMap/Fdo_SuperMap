// UGEditDef.h: interface for the UGEditDef class.
//
//////////////////////////////////////////////////////////////////////
//=====================================================================================
// 项目名：			Supermap Foundation Class (SFC) Library 2.0
// 作  者：			宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGEditDef.h
// 类  名：			
// 父  类：			
// 子  类：			
// 功能说明：		本头文件定义了编辑模块中的常量及基本类型
// 调用说明：		
//=====================================================================================



#if !defined(AFX_UGEDITDEF_H__77A08583_51B4_11D2_A87E_0080C878A624__INCLUDED_)
#define AFX_UGEDITDEF_H__77A08583_51B4_11D2_A87E_0080C878A624__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace UGC {
//added by xielin ^_^ 可显示的几何对象的最大点数
const	 UGint VisibleGeometrySize             =   65535;

#define  WM_USER_EDIT_GEOMETRY_PARAM	 WM_USER + 200
#define  WM_USER_TRACKED_GEOMETRY		 WM_USER + 210
#define	 WM_USER_AFTER_INPUT_POINT       WM_USER + 1200 

// 编辑手柄消息定义
#define  WM_USER_EDIT_HANDLE_BEGIN		 WM_USER + 2000
#define  WM_USER_EDIT_HANDLE_MOVING		 WM_USER + 2010
#define  WM_USER_EDIT_HANDLE_END		 WM_USER + 2020
#define  WM_USER_EDIT_HANDLE_CANCEL		 WM_USER + 2030

#define  SMALLRECT_BUFFER               1//3
#define  EDIT_SELECT_BUFFER             10//3
#define  HANDLE_WIDTH                   10//3
#define  BOUND_HANDLE                   9      //固定句柄数目
#define  ROT_HANDLE                     9      //旋转句柄  

#define  MOVE_WAIT_TICK_COUNT           300     //在鼠标点中对象300毫秒后开始可以编辑对象

#define AFC_SNAP_BUFFER_MAX_SIZE        99      // 最大捕捉对象数目

#define AFC_SNAP_MAX_LINE_COUNT         99      // 最大捕捉线段数目

#define AFC_SNAP_KIND_COUNT             14      // 所有捕捉种类数目

#define AFC_SNAP_CHANGED_NONE           0X00    // 无捕捉
#define AFC_SNAP_CHANGED_X              0X01    // 已捕捉X
#define AFC_SNAP_CHANGED_Y              0X02    // 已捕捉Y
#define AFC_SNAP_CHANGED_TAN            0X04    // 已捕捉斜率
#define AFC_SNAP_CHANGED_ALL            0X07    // 已捕捉

#define AFC_SNAP_PACK_NONE              0X00    // 无动作
#define AFC_SNAP_PACK_POINT             0X01    // 仅捕捉点
#define AFC_SNAP_PACK_ONE_LINE          0X02    // 仅捕捉单线、点
#define AFC_SNAP_PACK_TWO_LINE          0X03    // 捕捉双线、单线、点

#define AFC_SNAP_NONE                   0X00    // 00000000 00000000 无动作
#define AFC_SNAP_POINT_ON_LINESTARTOREND    0X01  // 00100000 00000000 输入点是否在栅格图素边缘上  //added by xielin
#define AFC_SNAP_POINT_ON_POINT         0X02    // 00000000 00000001 输入点是否同其它图素点重合
#define AFC_SNAP_POINT_ON_LINE          0X04    // 00000000 00000010 输入点是否在其它图素上
#define AFC_SNAP_POINT_IN_LINE_MIDDLE   0X08    // 00000000 00000100 输入点是否在其它线性图素中点上
#define AFC_SNAP_POINT_AT_LINE_EXTEND   0X10    // 00000000 00001000 输入点是否在其它线性图素延长线上
#define AFC_SNAP_POINT_EXTEND_ON_POINT  0X20    // 00000000 00010000 输入点的水平、竖直延长线是否同其它图素点重合
#define AFC_SNAP_LINE_FIX_ANGLE         0X40    // 00000000 00100000 输入线段是否同上一线段成固定角度
#define AFC_SNAP_LINE_FIX_LENGTH        0X80    // 00000000 01000000 输入线段是否固定长度
#define AFC_SNAP_LINE_ON_POINT          0X100    // 00000000 10000000 输入线段是否同其它图素点相交
#define AFC_SNAP_LINE_IS_HORV           0X200   // 00000001 00000000 输入线段是否水平、竖直
#define AFC_SNAP_LINE_PARALLEL_LINE     0X400   // 00000010 00000000 输入线段是否同其它线性图素平行
#define AFC_SNAP_LINE_VERTICAL_LINE     0X800   // 00000100 00000000 输入线段是否同其它线性图素垂直（包括延长线）
#define AFC_SNAP_RASTER_MIDDLE          0X1000   // 00001000 00000000 输入点是否在栅格图素中点上
#define AFC_SNAP_RASTER_EDGE            0X2000  // 00010000 00000000 输入点是否在栅格图素边缘上

#define AFC_SNAP_ALL                    0X3FFF  // 00111111 11111111 所有编辑开关   //这里需要和sfc统一，看看xiongxiong那边怎么设置的，设为一样既可

#define AFC_SNAP_PREV_LINE              0X00000 // 捕捉到前一条线段
#define AFC_SNAP_NEXT_LINE              0X10000 // 捕捉到后一条线段

#define AFC_SNAP_CURRENT_OBJ            -1      // 捕捉当前编辑对象

#define  IS_HAVE_SNAP_FLAG(a)  ( (a) & AFC_SNAP_ALL ) //判断某一捕捉开关是否打开
#define  ISZERO(a) ( -1.0e-10 < (a) && (a) < 1.0e-10 ) //判断是否为0

#ifndef PI
#define PI	3.14159265358979323846264338327950288     //圆周率
#endif

#define AFC_SNAP_ARRAY_INCREASE         10      // 数组动态增长量

//注记风格改变常量
#define AFC_CHANGETEXTSTYLE_NONE                 0X0000 
#define AFC_CHANGETEXTSTYLE_FONTNAME	         0X0001
#define AFC_CHANGETEXTSTYLE_FONTCOLOR            0X0002
#define AFC_CHANGETEXTSTYLE_ROTATEANGLE          0X0004 
#define AFC_CHANGETEXTSTYLE_SIZE                 0X0008
#define AFC_CHANGETEXTSTYLE_BOLD                 0X0010
#define AFC_CHANGETEXTSTYLE_ITALIC               0X0020  
#define AFC_CHANGETEXTSTYLE_TRANSPARENT          0X0040
#define AFC_CHANGETEXTSTYLE_STROKE               0X0080
#define AFC_CHANGETEXTSTYLE_UNDERLINE            0X0100
#define AFC_CHANGETEXTSTYLE_ALIGN                0X0200
#define AFC_CHANGETEXTSTYLE_FIXED                0X0400 
#define AFC_CHANGETEXTSTYLE_FIXEDSIZE            0X0800
#define AFC_CHANGETEXTSTYLE_FONTBACKCOLOR        0X1000
#define AFC_CHANGETEXTSTYLE_FONTWEIGHT	         0X2000 
#define AFC_CHANGETEXTSTYLE_ALL                  0XFFFF 
//注记风格改变常量

//风格改变常量
#define AFC_CHANGESTYLE_NONE					0X0000 
#define AFC_CHANGESTYLE_PENCOLOR				0X0001 
#define AFC_CHANGESTYLE_PENWIDTH			    0X0002
#define AFC_CHANGESTYLE_PENSTYLE			    0X0004  
#define AFC_CHANGESTYLE_BRUSHCOLOR				0X0008 
#define AFC_CHANGESTYLE_BRUSHBACKCOLOR			0X0010
#define AFC_CHANGESTYLE_BRUSHSTYLE				0X0020 
#define AFC_CHANGESTYLE_SYMBOLROTATION			0X0040  
#define AFC_CHANGESTYLE_SYMBOLSIZE				0X0080 
#define AFC_CHANGESTYLE_SYMBOLSTYLE				0X0100 
#define AFC_CHANGESTYLE_BRUSHOPAQUERATE			0X0200 
#define AFC_CHANGESTYLE_BRUSHGRADIENTTYPE		0X0400 
#define AFC_CHANGESTYLE_BRUSHCENTEROFFSETX		0X0800 
#define AFC_CHANGESTYLE_BRUSHCENTEROFFSETY		0X1000 
#define AFC_CHANGESTYLE_BRUSHGRADIENTANGLE		0X2000 
#define AFC_CHANGESTYLE_ALL						0XFFFF 
//风格改变常量

//事件常量
#define AFC_FIREEVENT_AFTERGEOMETRYADDED         0X001
#define	AFC_FIREEVENT_BEFOREGEOMETRYDELETEED     0X002
#define	AFC_FIREEVENT_AFTERGEOMETRYMODIFIED      0X003
#define	AFC_FIREEVENT_BEFOREGEOMETRYMODIFIED     0X004
#define	AFC_FIREEVENT_BEFORELAYERDRAW            0X005
#define	AFC_FIREEVENT_AFTERLAYERDRAW             0X006
#define	AFC_FIREEVENT_DRAWINGCANCELED            0X007
#define	AFC_FIREEVENT_BEFORETRACINGLAYERDRAW     0X008
#define	AFC_FIREEVENT_AFTERTRACKINGLAYERDRAW     0X009 
//事件常量

#define UGEDIT_INTERMEDIATE_FIXHANDLEOBJ_POINTS     72//36
#define UGEDIT_TOTAL_POINTS_MAX                     1000
#define UGEDIT_TOTAL_POINTS_MIN                     36

#define  IS_HAVE_SNAP_POINT_FLAG(a)  ( (a) & (  AFC_SNAP_POINT_ON_POINT          | \
                                                AFC_SNAP_POINT_EXTEND_ON_POINT   | \
                                                AFC_SNAP_LINE_ON_POINT           ) )
#define  IS_HAVE_SNAP_LINE_FLAG(a)   ( (a) & (  AFC_SNAP_POINT_ON_LINE           | \
												AFC_SNAP_POINT_ON_LINESTARTOREND           | \
                                                AFC_SNAP_POINT_IN_LINE_MIDDLE    | \
                                                AFC_SNAP_POINT_AT_LINE_EXTEND    | \
                                                AFC_SNAP_LINE_PARALLEL_LINE      | \
                                                AFC_SNAP_LINE_VERTICAL_LINE      ) )
#define  IS_HAVE_SNAP_P_A_L_FLAG(a)  ( (a) & (  AFC_SNAP_POINT_ON_POINT          | \
                                                AFC_SNAP_POINT_EXTEND_ON_POINT   | \
                                                AFC_SNAP_LINE_ON_POINT           | \
                                                AFC_SNAP_POINT_ON_LINE           | \
												AFC_SNAP_POINT_ON_LINESTARTOREND           | \
                                                AFC_SNAP_POINT_IN_LINE_MIDDLE    | \
                                                AFC_SNAP_POINT_AT_LINE_EXTEND    | \
                                                AFC_SNAP_LINE_PARALLEL_LINE      | \
                                                AFC_SNAP_LINE_VERTICAL_LINE      ) )
typedef struct strUGEditGeometryParam
{
    UGPoint2D    m_pntCurrent;
    UGdouble      m_dCurrentLength;
    UGdouble      m_dCurrentAngle;
    UGdouble      m_dTotaleLength;
    UGdouble      m_dTotaleArea;
}UGEditGeometryParam, *PCUGEditGeometryParam;

}
#endif // !defined(AFX_AFCEDITDEF_H__77A08583_51B4_11D2_A87E_0080C878A624__INCLUDED_)


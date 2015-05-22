/**  \file UGRenderWindow.h
   \brief   跨平台窗口类
   \auothor malq
   \attetion 目前还没有完全实现跨平台化
             有一些函数直接与window相关
			 后期工作改进
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>更新说明：</b>\n
	<em>1、第一条说明。\n
	<em>2、第二条说明。\n
*/
#if !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)
#define AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "RenderWindow/UG3DWorkThread.h"
#include "RenderWindow/UG3DWindowTypes.h"
#include "Scene/UGScene.h"
#include "Scene/UGAngle.h"
#include "Scene/UGMathEngine.h"
#include "Scene/DrawArgs.h"
#include "Algorithm/UGPoint.h"

namespace UGC
{

//! \brief 重定义数据类型,重定义函数指针	
typedef  UGRenderSys* (*CREATEGLRENDERSYS)();
typedef  UGRenderSys* (*CREATED3DRENDERSYS)(Window hwnd);

//! \brief 渲染窗口类
/**
  渲染管理类管理所有与窗口相关操作
*/
class RENDERWINDOW_API UGRenderWindow
{

public:
	
	//! \brief 定义渲染方式枚举常量
	typedef enum _RenderSysType
	{
		RST_NONE = 0, 
		RST_OGL = 1, 
		RST_D3D = 2
	} RenderSysType;
	
	//! \brief 构造函数
	UGRenderWindow();

	//! \brief 析构函数
	virtual ~UGRenderWindow();
	
	//! \brief 清除使用过资源，析构函数中调用该函数
	void fini();

	//! \brief 初始化UGRenderWindow对象
	void Initialize();
	
	//! \brief 更新渲染参数对象
	void Update();

	//! \brief 渲染
	void Render();

	void SetupRenderSys(Window wnd);
	//! \brief 设置窗口渲染类型
	void SetRenderSysType(RenderSysType renderSysType);
	
	//! \brief 得到激活渲染类型
	RenderSysType  GetRenderSysType();

	//! \brief 获取渲染参数对象
	DrawArgs &GetDrawArgs();

	//! \brief 获取场景对象
	UGScene &GetScene();

	UGDict<RenderSysType, UGRenderSys*> &GetRenderSysList();

	//! \brief 鼠标滚动事件处理方法
	/**
	  \param nFlags   鼠标键代码[in]
	  \param zDelta   滚动度数[in]
	  \param pt       坐标位置[in]
	*/
	void OnMouseWheel(UGuint nFlags, UGshort zDelta, UGPoint pt);
	
	//! \brief 鼠标移动事件处理方法
	/**
	  \param nFlags  鼠标键代码[in]
	  \param point   鼠标坐标位置[in]
	*/
	void OnMouseMove(UGuint nFlags, UGPoint point);

	//! \brief 鼠标左键按下事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnLButtonDown(UGuint nFlags, UGPoint point);

	//! \brief 鼠标左键抬起事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnLButtonUp(UGuint nFlags, UGPoint point);
	
	//! \brief 鼠标右键按下事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnRButtonDown(UGuint nFlags, UGPoint point);

	//! \brief 鼠标右键抬起事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnRButtonUp(UGuint nFlags, UGPoint point);

	//! \brief 鼠标左键双击事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnLButtonDblClk(UGuint nFlags, UGPoint point);

	//! \brief 鼠标右键双击事件处理方法
	/**
	  \param nFlags 鼠标键代码[in]
	  \param point  鼠标坐标位置[in]
	*/
	void OnRButtonDblClk(UGuint nFlags, UGPoint point);

	//! \brief 窗口改变大小事件处理方法
	/**
	  \param cx  窗口宽度
	  \param cy  窗口高度
	*/
	void OnSize(UGint cx, UGint cy);
	
	//! \brief 按下键事件处理方法
	/**
	  \param nChar   按下键数值[in]
	  \param nRepCnt 按下该键次数[in]  参数没有使用到????
	  \param nFlags  ?????
	*/
	void OnKeyDown(UGuint nChar, UGuint nRepCnt, UGuint nFlags);
	
	//! \brief 空闲处理函数
	/**
	  这个函数完成场景渲染,包括对场景所有处理都在该函数中完成
	  \param lCount 没有用到,建议删除
	*/
	void OnApplicationIdle(UGlong lCount);	
	
	//! \brief 设置光标操作速度因子
	/**
	  \param dblVKOperatorRatio  光标操作速度因子
	*/
	void SetVKOperatorRation(UGdouble dblVKOperatorRatio);
	
	//! \biref 设置顺逆时针旋转速度因子
	/**
	  \param dblRotateClockwiseRatio 顺逆时针旋转速度因子
	*/
	void SetRotateClockwiseRatio(UGdouble dblRotateClockwiseRatio);
	
	//! \brief 设置上下旋转速度因子
	/**
	  \param dblRotateUpDownRatio  上下翻转速度因子
	*/
	void SetRotateUpDownRatio(UGdouble dblRotateUpDownRatio);
	
	//! \brief 设置放大缩小速度因子
	/**
	  \param  dblZoomRatio  放大缩小速度因子
	*/
	void SetZoomRatio(UGdouble dblZoomRatio);

private:
	//! \brief 交换缓存
	void swapBuffers(void);

	//! \brief 准备OpenGL使用环境
	/**
	  \remark   这个函数直接使用window函数
	  \attetion 不具备跨平台功能
	            后期改进
	*/
	UGbool makeCurrent(void) const;

	//! \brief 删除OpenGL窗口
	void KillGLWindow();
	//! \brief 初始化window使用OpenGL环境
	UGbool InitGLWindow();
	
	//! \brief 程序是否空闲
	UGbool IsAppStillIdle();	
	UGRenderSys* SetupGLRenderSys();
	UGRenderSys* SetupD3DRenderSys();
protected:
    
	//! \brief 设备句柄
	Display3D m_dpy;

	//! \brief 窗口句柄
	Window m_wnd;

	//! \brief OpenGL上下文句柄
	GLContext m_glcontext;

	//! \brief 像素描述格式
	VisualInfo m_VisualInfo;
    
	//! \brief ??? 
	void* m_hRSLibHandle;
	
	//! \brief 鼠标按下开始位置
	UGPoint m_pntMouseDownStartPosition;
	
	//! \brief 鼠标是否拖拽
	UGbool m_bMouseDragging;
	
	//!  \brief  渲染参数
	/**
	  \remark 包括设置视点位置(调整相机位置)
	  设置激活渲染系统等
	*/
	DrawArgs m_DrawArgs;

	//! \brief 场景类
	/**
	  管理相机,渲染对象列表,地形数据等
	*/
	UGScene m_Scene;
	
	//! \brief 渲染对象类型
	RenderSysType m_nRenderSysType;
	
	//! \brief 工作线程指针
	UG3DWorkThread *m_pWorkThread;

	UGDict<RenderSysType, UGRenderSys*> m_RenderSys;
	UGDict<RenderSysType, void*> m_RSLibHandle;	 
	
	//! \brief 激活渲染系统
	UGRenderSys* m_pActiveRenderSys;
	
	//! \brief 光标操作速度因子
	UGdouble   m_dblVKOperatorRatio;
	//! \brief 顺利时针旋转速度因子
	UGdouble   m_dblRotateClockwiseRatio;
	//! \brief 上下翻转速度因子 
	UGdouble   m_dblRotateUpDownRatio;
	//! \brief 放大缩小速度因子
	UGdouble   m_dblZoomRatio;
};

}
#endif // !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)

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

#include "Scene/UGPrerequisites.h"
#include "Scene/UG3DWorkThread.h"
#include "Scene/UG3DWindowTypes.h"
#include "Scene/UGRenderTarget.h"


namespace UGC
{

typedef UGDict<UGString, UGString> NameValuePairList;

//! \brief 渲染窗口类
/**
  渲染管理类管理所有与窗口相关操作
*/
class SCENE_API UGRenderWindow : public UGRenderTarget
{
public:
	enum UGMap3DUserAction
	{	
		ua3DNull				=0,	// 什么也不干
		ua3DPickModel		    =1,	// 选择模型
		ua3DPickVector          =2  // 选择矢量对象
	};
public:	
	//! \brief 构造函数
	UGRenderWindow();
	//! \brief 析构函数
	virtual ~UGRenderWindow();		
	
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams) = 0;
	virtual void Destroy(void) = 0;
	
	//! \brief 更新渲染参数对象
	void Update();
	void Update(UGbool bSwapBuffers);	
	virtual void SwapBuffers(UGbool waitForVSync = true) = 0;

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
	// 得到渲染对象的渲染设备
	Display3D GetDisplay();
	// 设置渲染窗口得字体 
	void SetRenderTargetsFont(const UGTextStyle& textStyle);

	UGMap3DUserAction SetUserAction(UGMap3DUserAction action);	
	UGbool   IsNullUserAction();

protected:
	UGMomentumCamera *GetActiveCamera();

protected:
	UGPoint m_pntLastMousePosition;
	
	UGbool m_bLeftMouseButtonDown;
	UGbool m_bLeftMouseButtonUp;
	
	//! \brief记录按键时间
	//! \remark 用于判断操作类型
	UGlong m_nLeftMouseDownTime;
	UGlong m_nLeftMouseUpTime;

	UGbool m_bRightMouseButtonDown;
	//! \brief 鼠标按下开始位置
	UGPoint m_pntMouseDownStartPosition;
	UGPoint m_pntMouseUpStartPosition;
	
	//! \brief 鼠标是否拖拽
	UGbool m_bMouseDragging;	
	
	//! \brief 光标操作速度因子
	UGdouble   m_dblVKOperatorRatio;
	//! \brief 顺利时针旋转速度因子
	UGdouble   m_dblRotateClockwiseRatio;
	//! \brief 上下翻转速度因子 
	UGdouble   m_dblRotateUpDownRatio;
	//! \brief 放大缩小速度因子
	UGdouble   m_dblZoomRatio;

	//! \brief 窗口句柄
	Window m_wnd;
	//! \brief 设备句柄
	Display3D m_hDisplay;
	//! \brief 设备使用的字体
	Font3D    m_hFont;

	UGMap3DUserAction m_emUserAction;
	
	

};

}
#endif // !defined(AFX_UGRENDERWINDOW_H__951EEDAF_4364_4D61_A736_9DCC181F5F52__INCLUDED_)

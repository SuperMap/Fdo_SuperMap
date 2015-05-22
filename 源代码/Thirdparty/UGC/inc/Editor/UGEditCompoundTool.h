// SmEditCompoundTool.h: interface for the UGEditCompoundTool class.
//
//////////////////////////////////////////////////////////////////////
//=====================================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 2.0
// 作  者：		    黎涛
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//				    2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：	     SmEditCompoundTool.h
// 类  名：		 SmEditCompoundTool
// 父  类：		 UGEditTool
// 子  类：			
// 功能说明：	 复合对象编辑工具	
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_)
#define AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Editor/UGEditTool.h"
namespace UGC {

class EDITOR_API UGEditCompoundTool : public UGEditTool  //复合对象编辑工具
{
public:
	UGEditCompoundTool();
	virtual ~UGEditCompoundTool();
public:
	UGint m_nCurObjIndex;									 //当前编辑对象索引	
	UGbool m_bEditGIS;									 //是否编辑GIS数据集，这决定了最终编辑产生的对象是否是参数化对象
	UGint m_lSubAction;									 //子编辑工具的类型	
	UGbool m_bClosed;										//是否闭合
protected:
	UGEditTool * m_pSubEditTool;                        //子编辑工具
public:
	UGbool  Merge();								//将子对象合并为一个多线形对象
	void SetSubEditTool(								//设置子编辑工具								
						UGGraphics* pGraphics,						//设备描述表指针
						UGlong lSubAction,                //新的SubAction 
						UGEditTool * pSubEditTool);	//子编辑工具
	UGEditTool * GetSubEditTool();					    //取得子编辑工具
public:
	virtual UGbool OnRButtonUp( UGGraphics* pGraphics, UGuint nFlags, UGPoint point); //选择对象鼠标右键弹起的消息处理
    virtual UGbool OnRButtonDown( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标右键按下的消息处理
    virtual UGbool OnLButtonUp( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键弹起的消息处理
    virtual UGbool OnLButtonDown( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键按下的消息处理
    virtual UGbool OnLButtonDblClk( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标左键双击的消息处理
    virtual UGbool OnMouseMove( UGGraphics* pGraphics, UGuint nFlags, UGPoint point);//选择对象鼠标移动消息
    virtual UGbool OnSetCursor( UGuint nHitTest, UGuint message);//选择光标的形状
    virtual UGbool OnKeyDown( UGGraphics* pGraphics, UGuint nChar, UGuint nRepCnt, UGuint nFlags);//选择按键消息处理
    virtual UGbool OnDraw( UGGraphics* pGraphics); //在指定设备中画出编辑对象   
    virtual UGbool Clear( UGGraphics* pGraphics ); //清除编辑对象
	virtual UGbool OnUndo( UGGraphics* pGraphics); //撤销操作
    virtual UGbool OnRedo( UGGraphics* pGraphics); //恢复操作

	virtual UGbool IsUndoToolEnabled();		//判断是否可以撤销上一步操作
	virtual UGbool IsRedoToolEnabled();		//判断是否可以恢复上一步操作
};

}

#endif // !defined(AFX_UGEDITCOMPOUNDTOOL_H__E6084E9B_4146_4D16_B578_CE3B0C9B957F__INCLUDED_)

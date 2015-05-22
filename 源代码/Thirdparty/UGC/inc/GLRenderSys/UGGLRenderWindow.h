/* 
	\file UGGLRenderWindow.h
	\brief GL窗口类文件。
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_)
#define AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGRenderWindow.h"

namespace UGC
{

//! \brief GL窗口类。
class GLRENDERSYS_API UGGLRenderWindow : public UGRenderWindow
{
public:

	//! \brief 构造函数。
	UGGLRenderWindow();	
	
	//! \brief 析构函数。
	virtual ~UGGLRenderWindow();	
	
	//! \brief 创建窗口函数。
	//! \param name 名称[in]。
	//! \param hWnd 外部句柄[in]。
	//! \param *miscParams 配置参数列表[in]。
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams);	
	
	//! \brief 交换前后缓存。
	//! \param waitForVSync true为等待垂直刷新，false为不等待[in]。
	void SwapBuffers(UGbool waitForVSync);	

protected:
	
	//! \brief 创建GL资源。
	void CreateGLResources();	
	//! \brief 释放函数。
	void Destroy(void);	
	
	//! \brief 释放GL资源函数。
	void DestroyGLResources();	

protected:

	//! \brief OpenGL上下文句柄
	GLContext m_glcontext;

	//! \brief 像素描述格式
	VisualInfo m_VisualInfo;	

};

}


#endif // !defined(AFX_UGGLRENDERWINDOW_H__AD8A9CEA_3B6A_46DB_B7C8_DC094C053271__INCLUDED_)

/**  \file UGGLSupport.h
   \brief   管理OpenGL版本信息以及三维显示效果支持程度
   \auothor malq
   \attetion
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>更新说明：</b>\n
	<em>1、第一条说明。\n
	<em>2、第二条说明。\n
*/

#if !defined(AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_)
#define AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGConfigOptionMap.h"


namespace UGC 
{

//! \brief 管理OpenGL版本信息以及显卡信息	
class GLRENDERSYS_API UGGLSupport  
{

public:

	//! \brief 构造函数
	UGGLSupport();

	//! \brief 析构函数
	virtual ~UGGLSupport();
	
	//! \brief 判断是否支持多重纹理
	UGbool HasMultiTexture(void);

	//! \brief 检查是否为合法的OpenGL版本号
	UGbool CheckMinGLVersion(const UGString& version);

	//! \brief 检查是否为合法的扩展名
	UGbool CheckExtension(const UGString& extension);
	
	//! \brief 获取系统扩展相关信息
	void InitializeExtentions(void);

	//! \brief 获取最大纹理数
	const GLint GetMaxTextureSize();
	
	const GLfloat GetMaxPointSize();

	//! \brief 获取配置参数。
	//! \return 配置参数Map。
	UGConfigOptionMap& GetConfigOptions();
	
	//! \brief 设置配置参数。
	//! \param &name 名称[in]。
	//! \param &value 值[in]。
	void SetConfigOption(const UGString &name, const UGString &value);	
	
	//! \brief 增加配置。
	void AddConfig();	
	
	//! \brief 初始化WGL。
	void InitialiseWGL();	
	//! \brief 刷新配置。
	void RefreshConfig();	
	
	//! \brief 该函数无用。
	static LRESULT CALLBACK DummyWndProc(HWND hwnd, UINT umsg, WPARAM wp, LPARAM lp);	
	
protected:
	
	//! \brief Stored options
    UGConfigOptionMap m_Options;
	
	//! \brief 显示模式列表。
	UGList<DEVMODE> m_DevModes;

	//! \remarks FSAA列表。
	UGList<UGint> m_FSAALevels;

private:

	//! \brief 扩展列表
	UGList<UGString> m_ExtensionList;
	//! \brief 版本号
	UGString m_strVersion;
	//! \brief 厂商
	UGString m_strVender;
	//! \brief 是否初始化
	UGbool m_bInited;

};

}

#endif // !defined(AFX_UGGLSUPPORT_H__2BCCA983_4E86_4CDB_A75C_FD151B10C754__INCLUDED_)

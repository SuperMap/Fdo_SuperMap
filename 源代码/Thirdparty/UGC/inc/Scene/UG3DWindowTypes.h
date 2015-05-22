/**  \file UG3DWindowTypes.h
   \brief   定义与窗口相关数据类型
   \auothor malq
   \attetion 考虑跨平台因素
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>更新说明：</b>\n
	<em>1、第一条说明。\n
	<em>2、第二条说明。\n
*/

#ifndef UG3DWINDOWTYPES_H
#define  UG3DWINDOWTYPES_H

//! \brief 定义window数据类型
#ifdef WIN32
#include <WINDOWS.H>

namespace UGC
{
	typedef HDC Display3D;                     //定义window设备句柄
	typedef HWND Window;                       //定义window窗口句柄
	typedef HGLRC GLContext;                   //定义OpenGL上下文句柄
	typedef PIXELFORMATDESCRIPTOR VisualInfo;  //像素格式描述
	typedef HFONT Font3D;
}
#endif

//! \brief 定义非window中数据类型
#ifndef WIN32
#include <X11/Xlib.h>
#include <GL/glx.h>  
namespace UGC
{
	typedef ::Display* Display3D;              //定义设备句柄
	typedef ::Window   Window;                 //定义窗口句柄
	typedef GLXContext GLContext;              //定义OpenGL上下文句柄
	typedef XVisualInfo* VisualInfo;           //像素描述格式
}
#endif

#endif

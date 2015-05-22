/* 
	\file UGGLCondition.h
	\brief 包含必要头文件。
	\author malq zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef _UG_GL_CONDITION_H__
#define _UG_GL_CONDITION_H__

#define GL_GLEXT_PROTOTYPES

#ifdef WIN32
#include <windows.h>
#include <WINGDI.H>
#endif


#include "gl.h"
#include "glprocs.h"
#include "glext.h"
#include <GL/glu.h>


//! \briefWindows library does not include glSecondaryColorPointer even though it's standard now
#define glSecondaryColorPointer glSecondaryColorPointerEXT

extern "C" {
//! \brief Pointer to glActiveTextureARB function
typedef void (APIENTRY *GL_ActiveTextureARB_Func)(GLenum);
extern GL_ActiveTextureARB_Func glActiveTextureARB_ptr;

//! \brief Pointer to glClientActiveTextureARB function
typedef void (APIENTRY *GL_ClientActiveTextureARB_Func)(GLenum);
extern GL_ClientActiveTextureARB_Func glClientActiveTextureARB_ptr;

//! \brief Pointer to glSecondaryColorPointerEXT function
typedef void (APIENTRY *GL_SecondaryColorPointerEXT_Func)(GLint, GLenum, GLsizei, const GLvoid*);
extern GL_SecondaryColorPointerEXT_Func glSecondaryColorPointerEXT_ptr;

//! \brief Pointer to glGenBuffersARB function
typedef void (APIENTRY *GL_GenBuffersARB_Func)(GLsizei, GLuint*);
extern GL_GenBuffersARB_Func glGenBuffersARB_ptr;

//! \brief Pointer to glBindBufferARB function
typedef void (APIENTRY *GL_BindBufferARB_Func)(GLenum, GLuint);
extern GL_BindBufferARB_Func glBindBufferARB_ptr;

//! \brief Pointer to glDeleteBuffersARB function
typedef void (APIENTRY *GL_DeleteBuffersARB_Func)(GLsizei, const GLuint*);
extern GL_DeleteBuffersARB_Func glDeleteBuffersARB_ptr;

//! \brief Pointer to glMapBufferARB function
typedef GLvoid* (APIENTRY *GL_MapBufferARB_Func)(GLenum, GLenum);
extern GL_MapBufferARB_Func glMapBufferARB_ptr;

//! \brief Pointer to glUnmapBufferARB function
typedef GLboolean (APIENTRY *GL_UnmapBufferARB_Func)(GLenum);
extern GL_UnmapBufferARB_Func glUnmapBufferARB_ptr;

//! \brief Pointer to glBufferSubDataARB function
typedef void (APIENTRY *GL_BufferSubDataARB_Func)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid*);
extern GL_BufferSubDataARB_Func glBufferSubDataARB_ptr;

//! \brief Pointer to glBufferDataARB function
typedef void (APIENTRY *GL_BufferDataARB_Func)(GLenum, GLsizeiptrARB, const GLvoid* , GLenum);
extern GL_BufferDataARB_Func glBufferDataARB_ptr;

//! \brief Pointer to glGetBufferSubDataARB function
typedef void (APIENTRY *GL_GetBufferSubDataARB_Func)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid*);
extern GL_GetBufferSubDataARB_Func glGetBufferSubDataARB_ptr;

};

#endif

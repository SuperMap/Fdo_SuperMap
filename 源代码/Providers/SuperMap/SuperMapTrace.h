/** \file		SuperMapTrace.h
*  \brief		¸ú×ÙÄ£¿é
*  \author		ºÂÓñ½­
*  \attention 
*  Copyright(C) 1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-8-8
*/

#if !defined(__TRACE_H__)
#define __TRACE_H__

#if _MSC_VER > 1000
#	pragma once
#endif // _MSC_VER > 1000

#include <tchar.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void _cdecl Trace(const TCHAR* lpszFormat, ...);

#ifdef TRACE
#	undef TRACE
#endif

// YuJiang 2007.10.23

#ifdef SUPERMAP_PROVIDER_DEBUG
#	define TRACE			::Trace
#	define ASSERT(f)		assert(f)
#else
#	define TRACE			1?(void)0: ::Trace
#	define ASSERT(f)		((void)0)
#endif


#endif // !defined(__TRACE_H__)

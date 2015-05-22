/* 
	\file ugwin32.h
	\brief Win32平台的头文件定义
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef _UGWIN32_H
#define _UGWIN32_H

// 2003-5-28-by-malq-base的线程类会使用
#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0400	// Change this to the appropriate value to target Windows 2000 or later.
#endif	

//#undef LoadString
//#undef DeleteFile
//#undef GetCurrentTime

#pragma warning(disable: 4018)  // signed/unsigned mismatch
#pragma warning(disable: 4097)
#pragma warning(disable: 4100)
#pragma warning(disable: 4164)
#pragma warning(disable: 4244)
// 以下几个警告太常见，还是放到ugdefs.h中
//#pragma warning(disable: 4251)
//#pragma warning(disable: 4275)
//#pragma warning(disable: 4786)
#pragma warning(disable: 4514)
#pragma warning(disable: 4663)
//#pragma warning(disable: 4710) // 为内联展开选定了给定函数，但编译器没有执行内联。

// 头文件包含 
#include <io.h>
//#include <WinDef.h>

// by zengzm 2007-4-16 vsnprintf 在windows上没有定义,而是有_vsnprintf作为替代品,
// 故而重定义一下
//	#define vsnprintf _vsnprintf
#ifndef vsnprintf
	#define vsnprintf _vsnprintf
#endif


#define UGopen	_open
#define UGwrite	_write
#define UGread	_read
#define UGseek	_lseeki64
#define UGclose	_close

#define UGBINARY O_BINARY
#define UGREADWRITE _S_IREAD|_S_IWRITE

#define PATHSEP '\\'
#define PATHSEPSTRING "\\"
#define PATHLISTSEP ';'
#define PATHLISTSEPSTRING ";"
#define ISPATHSEP(c) ((c)=='/' || (c)=='\\')
#define EOLSTRING "\r\n"
#define WEOLSTRING L"\r\n"

// copy from <windef.h>
#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
	#define CALLBACK    __stdcall
#else
	#define CALLBACK
#endif

#define UGCALLBACK CALLBACK
#define UGSTDCALL __stdcall

namespace UGC {

// 变量定义
typedef void*         UGThreadID;
typedef unsigned int  UGHandle;

}

#endif

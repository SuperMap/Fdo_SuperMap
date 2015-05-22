/* 
	\file ugnowin.h
	\brief 非Windows平台（Linux、Unix等）的头文件定义
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef _UGNOWIN_H
#define _UGNOWIN_H

// commited by zengzm 2007-3-30 把link.h放在这里，避免在Solaris中编译不过，
// 因为后面会定义_FILE_OFFSET_BITS为64，而link.h中include的libelf.h中
// 判断_FILE_OFFSET_BITS不等于32，且_ILP32也已经被定义，就会输出编译错误
// 估计是中间的某个头文件中定义了_ILP32，因此把link.h放到最前面中，以避免此编译错误
#ifdef _AIX
#include <dlfcn.h> // for dlopen() & dlsym()
#else 
#include <link.h>  // for dlopen() & dlsym()
#endif               

// 头文件包含
// 定义宏，使得可以处理大文件（>4GB）
#undef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <dirent.h>	
#include <fcntl.h>
#define UGopen	open
#define UGwrite	write
#define UGread	read
#define UGseek	lseek
#define UGclose	close

#define UGBINARY 0
#define UGREADWRITE 0666

//#ifndef O_BINARY
//	#define O_BINARY 0
//#endif	//O_BINARY

#define PATHSEP '/'
#define PATHSEPSTRING "/"
#define PATHLISTSEP ':'
#define PATHLISTSEPSTRING ":"
#define ISPATHSEP(c) ((c)=='/')
#define EOLSTRING "\n"
#define WEOLSTRING L"\n"

#define UGCALLBACK  
#define UGSTDCALL 


#include <X11/Xlib.h>  

namespace UGC {

// 变量类型定义
typedef unsigned long UGThreadID;
typedef void*		  UGHandle;

//deleted by xielin 2007-06-26 这两个没人用还引起冲突，删除
//typedef ::Display*  Display;
//typedef ::Window   DisplayWnd;

}


#endif // _UGNOWIN_H

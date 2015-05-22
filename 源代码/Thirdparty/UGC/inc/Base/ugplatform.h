/* 
	\file ugplatform.h
	\brief 不同平台特定实现的总入口
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef _UGPLATFORM_H
#define _UGPLATFORM_H

#ifdef WIN32
	#include "ugwin32.h"
#endif

#ifdef _WIN32_WCE
	#include "ugwince.h"
#endif

#ifndef WIN32
	#include "ugnowin.h"
#endif

#endif

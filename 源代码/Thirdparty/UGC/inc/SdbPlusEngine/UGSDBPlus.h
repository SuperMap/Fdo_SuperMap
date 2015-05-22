#if !defined(_SM_ENGINE_SDBPLUS_H__)
#define _SM_ENGINE_SDBPLUS_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

#ifndef __AFXPRIV_H__
#include <afxpriv.h>
#endif

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include "../SmEng/SmEng.h"
#include "../SmCSF/SmCSF.h"

#ifdef _AFXDLL
	extern "C" AFX_EXT_API void  WINAPI InitSmeSDBPlusDLL();
	#ifdef _DEBUG
		#pragma message("自动连接SDB引擎 SmeSDBPlus50.dll ...")
		#pragma comment(lib,"../BinD/SmeSDBPlus50.lib") 
	#else
		#pragma message("自动连接SDB引擎 SmeSDBPlus50.dll ...") 
		#pragma comment(lib,"../Bin/SmeSDBPlus50.lib") 
	#endif
#else
	#ifdef _SM_APP
		#ifdef _DEBUG
			#pragma message("自动连接SDB引擎 SmeSDBPlusStatic50.lib ...") 
			#pragma comment(lib,"../BinD/SmeSDBPlusStatic50.lib") 
		#else
			#pragma message("自动连接SDB引擎 SmeSDBPlusStatic50.lib ...") 
			#pragma comment(lib,"../Bin/SmeSDBPlusStatic50.lib") 
		#endif
	#endif
#endif

#include "resource.h"

#include "SdbDataSourcePlus.h"
#include "SdbDatasetVectorPlus.h"
#include "SdbDatasetRasterPlus.h"
#include "SdbRecordsetPlus.h"
 

#endif//_SM_ENGINE_SDBPLUS_H__
#ifndef _UGC_H_ZHOUX
#define _UGC_H_ZHOUX

/*#ifdef WIN32

#ifndef WINVER
#define WINVER 0x0502	// (Windows Server 2003)

#endif
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#endif*/

//UGC_support
#include "Base/UGUnit.h"
#include "Base/UGFile.h"
#include "Base/UGLogFile.h"
#include "Workspace/UGWorkspace.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDsConnection.h"
#include "Engine/UGDataSourceManager.h"
#include "Base/UGAutoPtr.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/ugeng.h"

#pragma warning( disable : 4800 )	// 屏蔽UGC::UGbool到bool转换的警告
//#pragma warning( disable : 4955 )	// 屏蔽UGC::CDaoTableDef': name was marked as #pragma deprecated

#endif

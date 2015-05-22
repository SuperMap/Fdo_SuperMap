/** \file		SuperMapTrace.cpp
*  \brief		¸ú×ÙÄ£¿é
*  \author		ºÂÓñ½­
*  \attention 
*  Copyright(C) 1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-8-8
*/

#include <windows.h>
#include "SuperMapTrace.h"

//VC8:resolved the redefinition error, macro is already defined in stdlib.h
#ifdef _COUNTOF
#	undef _COUNTOF
#endif 

// determine number of elements in an array (not bytes)
#define		_COUNTOF(array) (sizeof(array)/sizeof(array[0]))

void _cdecl Trace(const TCHAR* lpszFormat, ...)
{
	va_list args;
	va_start(args, lpszFormat);
	int nBuf;
	TCHAR szBuffer[2048];
	nBuf = _vsntprintf(szBuffer, _COUNTOF(szBuffer), lpszFormat, args);
	// was there an error?
	ASSERT(nBuf >= 0);
	::OutputDebugString(szBuffer);
	va_end(args);
}


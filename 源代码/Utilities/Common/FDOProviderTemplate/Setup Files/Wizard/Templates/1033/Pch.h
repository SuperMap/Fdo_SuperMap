/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifdef _WIN32
#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#include <afxwin.h>         // MFC core and standard components
// Undefine GetMessage
#ifdef GetMessage
#undef GetMessage
#endif
#endif

#define _CRTDBG_MAP_ALLOC

#ifdef _WIN32
#include <crtdbg.h>
#include <Windows.h>
#endif // _WIN32

#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <Fdo.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef __TSTRING_H__
#define __TSTRING_H__

#include <string>
#include <fstream>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// Typedefs
///////////////////////////////////////////////////////////////////////////////
///added by zhoux 2007-9-20 增加宽字节转多字节字符串
#include "Util.h"
#include <tchar.h>

#ifdef _UNICODE
	typedef std::wstring		_tstring;
	typedef std::wfstream		_tfstream;
	typedef std::wios			_tios;
	typedef std::wostream		_tostream;
	typedef std::wistream		_tistream;
#else
    typedef std::string			_tstring;
	typedef std::fstream		_tfstream;
	typedef std::ios			_tios;
	typedef std::ostream		_tostream;
	typedef std::istream		_tistream;
#endif

///added by zhoux 2007-9-20 增加宽字节转多字节字符串
#ifdef _UNICODE
	#define ASCII_STRING(c)		WcharToString(c.c_str()) 

	#define UNICODE_STRING(c)	StringToWString(c)
#else 
	#define ASCII_STRING(c)		c
	#define UNICODE_STRING(c)	c
#endif
///over added by zhoux 2007-9-20


#endif // __TSTRING_H__

///////////////////////////////////////////////////////////////////////////////
// End of file: tstring.h
///////////////////////////////////////////////////////////////////////////////


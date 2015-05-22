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
  *
 */

#ifndef _FDOCOMMONSTRINGUTIL_H_
#define _FDOCOMMONSTRINGUTIL_H_

#ifdef _WIN32
#pragma once
#endif

#include <Common/FdoTypes.h>

#ifdef _WIN32

#include <winnls.h>
#include <malloc.h>

// macro to convert a multibyte string into a wide character string, allocating space on the stack
#define multibyte_to_wide(w,mb)\
{\
    const char* p = (mb);\
    size_t i = strlen (p);\
    i++;\
    w = (wchar_t*)alloca(i * sizeof (wchar_t));\
    i = MultiByteToWideChar (\
        CP_THREAD_ACP,\
        0,\
        p,\
        (int)i,\
        w,\
        (int)i);\
    if (0 == i)\
        w = NULL;\
    if (NULL==w) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string, allocating space on the stack
#define wide_to_multibyte(mb,w)\
{\
    const wchar_t* p = (w);\
    size_t i = wcslen (p);\
    i++;\
    mb = (char*)alloca (i * 6);\
    i = WideCharToMultiByte (\
        CP_THREAD_ACP,\
        0,\
        p,\
        (int)i,\
        mb,\
        (int)i * 6,\
        NULL,\
        NULL);\
    if (0 == i)\
        mb = NULL;\
    if (NULL==mb) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a multibyte string into a wide character string,
// assuming adequate space has already been provided in w
#define multibyte_to_wide_noalloc(w,mb)\
{\
    const char* p = (mb);\
    size_t i = strlen (p);\
    i++;\
    i = MultiByteToWideChar (\
        CP_THREAD_ACP,\
        0,\
        p,\
        (int)i,\
        w,\
        (int)i);\
    if (0 == i)\
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string,
// assuming adequate space has already been provided in mb
#define wide_to_multibyte_noalloc(mb,w)\
{\
    const wchar_t* p = (w);\
    size_t i = wcslen (p);\
    i++;\
    i = WideCharToMultiByte (\
        CP_THREAD_ACP,\
        0,\
        p,\
        (int)i,\
        mb,\
        (int)i * 6,\
        NULL,\
        NULL);\
    if (0 == i)\
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

#else
// macro to convert a multibyte string into a wide character string, allocating space on the stack
#define multibyte_to_wide(w,mb)\
{\
    const char* p = (mb);\
    size_t i = strlen (p);\
    i++;\
    w = (wchar_t*)alloca (i * sizeof (wchar_t));\
    i = mbstowcs (w, p, i);\
    if (0 > i)\
        w = NULL;\
    if (NULL==w) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string, allocating space on the stack
#define wide_to_multibyte(mb,w)\
{\
    const wchar_t* p = (w);\
    size_t i = wcslen (p);\
    i++;\
    mb = (char*)alloca (i * 6);\
    i = wcstombs (mb, p, i*6);\
    if (0 > i)\
        mb = NULL;\
    if (NULL==mb) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a multibyte string into a wide character string,
// assuming adequate space has already been provided in w
#define multibyte_to_wide_noalloc(w,mb)\
{\
    const char* p = (mb);\
    size_t i = strlen (p);\
    i++;\
    i = mbstowcs (w, p, i);\
    if (0 > i)\
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string,
// assuming adequate space has already been provided in w
#define wide_to_multibyte_noalloc(mb,w)\
{\
    const wchar_t* p = (w);\
    size_t i = wcslen (p);\
    i++;\
    i = wcstombs (mb, p, i*6);\
    if (0 > i)\
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}
#endif

// Conversions with CODEPAGE support

#ifdef _WIN32
// macro to convert a multibyte string into a wide character string, allocating space on the stack
#define multibyte_to_wide_cpg(w,mb,cpg)\
{\
    const char* p = (mb);\
    size_t i = strlen (p);\
    i++;\
    w = (wchar_t*)alloca (i * sizeof (wchar_t));\
    i = MultiByteToWideChar (\
        cpg,\
        0,\
        p,\
        (int)i,\
        w,\
        (int)i);\
    if (0 == i)\
        w = NULL;\
    if (NULL==w) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string, allocating space on the stack
#define wide_to_multibyte_cpg(mb,w,cpg)\
{\
    const wchar_t* p = (w);\
    size_t i = wcslen (p);\
    i++;\
    mb = (char*)alloca (i * 6);\
    i = WideCharToMultiByte (\
        cpg,\
        0,\
        p,\
        (int)i,\
        mb,\
        (int)i * 6,\
        NULL,\
        NULL);\
    if (0 == i)\
        mb = NULL;\
    if (NULL==mb) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}
#else 


#include <iconv.h>

#define conv_wide_to_utf8(utf8,w)\
{\
    bool convFailed = true;\
    if (NULL != w)\
    {\
        size_t szStr = wcslen (w)+1;\
        utf8 = (char*)alloca (szStr * 6);\
        iconv_t rOpen = iconv_open("UTF-8", "WCHAR_T");\
        if ((iconv_t)-1 != rOpen)\
        {\
           size_t iSize_Out = szStr * 6;\
           size_t iSize_In = sizeof (wchar_t)*szStr;\
           char* p_utf8 = utf8;\
           const wchar_t* p_w = w;\
           size_t rConv = iconv(rOpen, (char**)&p_w, &iSize_In, &p_utf8,&iSize_Out);\
           if ((size_t)-1 != rConv &&  iSize_Out != (szStr * 6))\
               convFailed = false;\
           iconv_close(rOpen);\
        }\
    }\
    if (convFailed)\
        utf8 = NULL;\
    if (NULL==utf8) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

#define conv_utf8_to_wide(w,utf8)\
{\
    bool convFailed = true;\
    if (NULL != utf8)\
    {\
        size_t szStr = strlen (utf8)+1;\
        w = (wchar_t*)alloca (szStr * sizeof(wchar_t));\
        iconv_t rOpen = iconv_open("WCHAR_T", "UTF-8");\
        if ((iconv_t)-1 != rOpen)\
        {\
           size_t iSize_Out = szStr * sizeof(wchar_t);\
           size_t iSize_In = szStr;\
           const char* p_utf8 = utf8;\
           wchar_t*p_w = w;\
           size_t rConv = iconv(rOpen, (char**)&p_utf8, &iSize_In, (char**)&p_w, &iSize_Out);\
           if ((size_t)-1 != rConv &&  iSize_Out != (szStr * sizeof(wchar_t)))\
               convFailed = false;\
           iconv_close(rOpen);\
        }\
    }\
    if (convFailed)\
        w = NULL;\
    if (NULL==w) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

//macro to convert a multibyte string into a wide character string, allocating space on the stack
#define multibyte_to_wide_cpg(w,mb,cpg)\
{\
    const char* p = (mb);\
    size_t i = strlen (p)+1;\
    size_t mbsize = i; \
    size_t wsize = i * sizeof(wchar_t)*3; \
    w = (wchar_t*)alloca (wsize);\
    char  *wc = (char *)w; \
    char  *p2 = (char *)p; \
    iconv_t cd = iconv_open("WCHAR_T", cpg);  \
    if ( cd != (iconv_t)-1 ) {\
     	i = iconv( cd, (char **)&p2, &mbsize, (char **)&wc, &wsize); \
        iconv_close( cd ); \
    } \
    if ( cd == (iconv_t)-1 || i == (size_t)-1 ) {\
     	i = mbstowcs (w, p, wsize);\
    	if (0 > i)\
       	    w = NULL;\
    }\
    if (NULL==w) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}

// macro to convert a wide character string into a multibyte string, allocating space on the stack
#define wide_to_multibyte_cpg(mb,w,cpg)\
{\
    const wchar_t* p = (w);\
    size_t i = sizeof(wchar_t)*(wcslen (p)+1);\
    size_t wsize = i; \
    size_t mbsize = i * 3; \
    mb = (char*)alloca (mbsize);\
    char *mb2 = mb;\
    char *p2 = (char *)p; \
    iconv_t cd = iconv_open(cpg, "WCHAR_T");  \
    if ( cd != (iconv_t)-1 ) {\
     	i = iconv( cd, (char **)&p2, &wsize, (char **)&mb2, &mbsize); \
        iconv_close( cd ); \
    } \
    if ( cd == (iconv_t)-1 || i == (size_t)-1 ) {\
    	i = wcstombs (mb, w, mbsize);\
    	if (0 > i)\
       	     mb = NULL;\
    }\
    if (NULL==mb) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));\
}
#endif


// COPY BEGIN -  THIS CODE IS COPIED FROM FdoUnmanagedsrccommon

//converts utf8 string to unicode
//returns length of unicode string (excluding null character)
//returns -1 if invalid character code was encountered
int _ut_utf8_to_unicode(const char* str_in, size_t in_size, wchar_t* Wtext, size_t out_size);

//converts unicode string to utf8
//returns number of bytes in output utf8 string (excluding trailing null char)
//returns -1 if invalid character encountered
int _ut_utf8_from_unicode(const wchar_t* Wtext, size_t in_size, char* str_out, int out_size);

// COPY END -  THIS CODE IS COPIED FROM FdoUnmanagedsrccommon


class FdoCommonStringUtil
{
public:
    static void     ClearString(wchar_t*& psz);
    static wchar_t* MakeString(FdoString* psz1, FdoString* psz2 = NULL, FdoString* psz3 = NULL, FdoString* psz4 = NULL, FdoString* psz5 = NULL);
    static wchar_t* MakeString(FdoInt32 numStrings, FdoString* * strings, FdoString* separator = NULL);
    static wchar_t* MakeString(FdoByte* data, FdoInt32 iDataSize);
    static void     FormatDouble(double d, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale = true);
    static void     FormatSingle(float f, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale = true);
    static void     FormatNumber(double d, FdoInt32 precision, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale);
    static wchar_t* QuoteString(FdoString* psz, wchar_t chQuote);

    /// Hides Windows and Linux string to int64 conversion specifics.
    static FdoInt64 StringToInt64( FdoString* str );

    /// Hides Windows and Linux int64 to string conversion specifics.
    /// Handles allocation of string buffer so not appropriate for 
    /// extremely performance-sensitive callers.
    static FdoStringP Int64ToString( FdoInt64 val );

    static size_t   StringLength(FdoString* string);
    static FdoInt32 StringCompare(FdoString* string1, FdoString* string2);
    static FdoInt32 StringCompareNoCase(FdoString* string1, FdoString* string2);
    static FdoInt32 StringCompareNoCaseN(FdoString* string1, FdoString* string2, FdoSize count);
    static void     StringCopy(wchar_t* string1, FdoString* string2);
    static void     SubstringCopy(wchar_t* string1, FdoString* string2, size_t length);
    static void     StringConcatenate(wchar_t* string1, FdoString* string2);
    static FdoString* FindCharacter(FdoString* string, wchar_t character);
/**
 * Remove blanks from the two ends of a string.
 */
    static wchar_t* StringTrim (wchar_t *str);

    static void PrintString(FdoString * string);
    /// check for a string composed entirely of ASCII characters
    static bool AllASCII (FdoString* string);

    static FdoString*   NullString;
};

// Short name for easy invocation from debugger, especially in Linux.
void fdoprints(FdoString * string);

#endif // _FDOCOMMONSTRINGUTIL_H_



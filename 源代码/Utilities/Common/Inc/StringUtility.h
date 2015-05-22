#ifndef _STRINGUTILITY_H_
#define _STRINGUTILITY_H_
// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#ifdef _WIN32
#pragma once
#endif
#include <FdoCommon.h>

class FdoStringUtility
{
public:
    static void ClearString(wchar_t*& psz);
    static wchar_t* MakeString(FdoString* psz1, FdoString* psz2 = NULL, FdoString* psz3 = NULL, FdoString* psz4 = NULL, FdoString* psz5 = NULL);
    static wchar_t* MakeString(FdoInt32 numStrings, FdoString* * strings, FdoString* separator = NULL);
    static wchar_t* MakeString(FdoByte* data, FdoInt32 iDataSize);
    static void     FormatDouble(double d, wchar_t* pszBuffer, FdoInt32 iLen);
    static void     FormatSingle(float f, wchar_t* pszBuffer, FdoInt32 iLen);
    static void     FormatNumber(double d, FdoInt32 precision, wchar_t* pszBuffer, FdoInt32 iLen);
    static wchar_t* QuoteString(FdoString* psz, wchar_t chQuote);

    static size_t StringLength(FdoString* string);
    static FdoInt32 StringCompare(FdoString* string1, FdoString* string2);
    static FdoInt32 StringCompareNoCase(FdoString* string1, FdoString* string2);
    static void StringCopy(wchar_t* string1, FdoString* string2);
    static void SubstringCopy(wchar_t* string1, FdoString* string2, size_t length);
    static void StringConcatenate(wchar_t* string1, FdoString* string2);
    static FdoString* FindCharacter(FdoString* string, wchar_t character);

    static FdoString*   NullString;
};
#endif


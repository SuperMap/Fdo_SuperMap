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

#ifndef _PARSETYPES_H_
#define _PARSETYPES_H_

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>

#ifdef _WIN32
typedef unsigned _int16	FdoUInt16;
typedef unsigned _int32	FdoUInt32;
#else
typedef uint16_t    FdoUInt16;
typedef uint32_t    FdoUInt32;
#endif

// This structure should be just like FdoDateTime except without constructors.
// If a class (or structure has a constructor, it cannot be a part of a union
// such as the _YYSTYPE unions.
struct _FdoDateTime
{
    void Set(FdoDateTime tm)
    {
        year = tm.year;
        month = tm.month;
        day = tm.day;
        hour = tm.hour;
        minute = tm.minute;
        seconds = tm.seconds;
    }

    operator FdoDateTime()
    {
        FdoDateTime retVal(year, month, day, hour, minute, seconds);
        return retVal;
    }

    FdoInt16    year;       // 100-3000
    FdoInt8     month;      // 1-12
    FdoInt8     day;        // 1-31
    FdoInt8     hour;       // (0-23)
    FdoInt8     minute;     // 0-59
    float       seconds;    // 0-59.99999999
};

typedef enum FdoToken 
{
    /// bad stuff/processing...
  FdoToken_Undefined = -3,     // Token is undefined
  FdoToken_End = -2,           // End of string 
  FdoToken_Start = -1,         // Start of line 
  FdoToken_Error = 0,          // Lexical analyzer error or erroneous token

    /// data values
  FdoToken_Literal = 1         // Literal

} FdoToken;

// FDO keywords
typedef struct _FdoKeyWord
{
	FdoString*	word;
	FdoInt32	token;
} FdoKeyWord;


#endif // _PARSETYPES_H_



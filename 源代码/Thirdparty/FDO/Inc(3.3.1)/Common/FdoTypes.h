#ifndef _FDOTYPES_H_
#define _FDOTYPES_H_
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef _WIN32
#pragma once
#endif

#ifndef _WIN32
#include <stdint.h>
#endif

/// \ingroup (typedefs)
/// \brief
/// FdoByte is used to store a single byte of data
typedef unsigned char   FdoByte;
#ifdef _WIN32
/// \ingroup (typedefs)
/// \brief
/// FdoInt8 is used to store a 8 bit signed integer
typedef _int8           FdoInt8;
/// \ingroup (typedefs)
/// \brief
/// FdoInt16 is used to store a 16 bit signed integer
typedef _int16          FdoInt16;
/// \ingroup (typedefs)
/// \brief
/// FdoInt32 is used to store a 32 bit signed integer
typedef _int32          FdoInt32;
/// \ingroup (typedefs)
/// \brief
/// FdoInt64 is used to store a 64 bit signed integer
typedef _int64          FdoInt64;
#else
/// \cond DOXYGEN-IGNORE
typedef int8_t		FdoInt8;
typedef int16_t		FdoInt16;
typedef int32_t		FdoInt32;
typedef int64_t		FdoInt64;
/// \endcond
#endif
/// \ingroup (typedefs)
/// \brief
/// FdoCharacter is used to store a wide character
typedef wchar_t         FdoCharacter;
/// \ingroup (typedefs)
/// \brief
/// FdoString is used to store a constant wide character.
/// Variables declared as FdoString* point to constant wide character strings.
typedef const wchar_t   FdoString;
/// \ingroup (typedefs)
/// \brief
/// FdoBoolean is used to store a boolean (true/false) value
typedef bool            FdoBoolean;
/// \ingroup (typedefs)
/// \brief
/// FdoVoid is used to reference a void (type undetermined)
typedef void            FdoVoid;
/// \ingroup (typedefs)
/// \brief
/// FdoDouble is used to store a double precision floating point number
typedef double          FdoDouble;
/// \ingroup (typedefs)
/// \brief
/// FdoFloat is used to store a single precision floating point number
typedef float           FdoFloat;

/// \ingroup (typedefs)
/// \brief
/// FdoSize is used to store a size value (e.g. number of elements in an array)
typedef size_t          FdoSize;

/// \brief
/// FdoDateTime is used to store dates, times, or both.  After constructing 
/// the class you determine which portion has been specified.  The data members
/// are public so they can be accessed directly. No range checking is performed.
/// <ul>
/// <li>Year is in the range of 1 to 9999</li>
/// <li>Month is in the range of 1 to 12 inclusive (January = 1)</li>
/// <li>Day of the month is in the range of 1 to 31 inclusive</li>
/// <li>Hour is since midnight in the range of 0 to 23</li>
/// <li>Minutes are after hour in the range of 0 to 59</li>
/// <li>Seconds are after minute in the range of 0 to 59.9999999</li>
/// </ul>
class FdoDateTime
{
public:
    /// \brief
    /// Construct a NULL date time value
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FdoDateTime()
    {
        year = -1; month = -1; day = -1;
        hour = -1; minute = -1; seconds = 0.0f;
    }

    /// \brief
    /// Construct a date value
    /// 
    /// \param _year 
    /// Input year
    /// \param _month 
    /// Input month
    /// \param _day 
    /// Input day of month
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FdoDateTime(FdoInt16 _year, FdoInt8 _month, FdoInt8 _day)
    {
        year = _year; month = _month; day = _day;
        hour = -1; minute = -1; seconds = 0.0f;
    }

    /// \brief
    /// Construct a time value
    /// 
    /// \param _hour 
    /// Input hour
    /// \param _minutes 
    /// Input minutes
    /// \param _seconds 
    /// Input seconds
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FdoDateTime(FdoInt8 _hour, FdoInt8 _minutes, float _seconds)
    {
        year = -1; month = -1; day = -1;
        hour = _hour; minute = _minutes; seconds = _seconds;
    }

    /// \brief
    /// Construct a date time value
    /// 
    /// \param _year 
    /// Input year
    /// \param _month 
    /// Input month
    /// \param _day 
    /// Input day of month
    /// \param _hour 
    /// Input hour
    /// \param _minutes 
    /// Input minutes
    /// \param _seconds 
    /// Input seconds
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FdoDateTime(FdoInt16 _year, FdoInt8 _month, FdoInt8 _day, FdoInt8 _hour, FdoInt8 _minutes, float _seconds)
    {
        year = _year; month = _month; day = _day;
        hour = _hour; minute = _minutes; seconds = _seconds;
    }

    /// \brief
    /// Returns true if the date is valid
    /// 
    /// \return
    /// Returns true if date has been defined.
    /// 
    bool IsDate() {return year != -1 && hour == -1;}

    /// \brief
    /// Returns true if the time is valid
    /// 
    /// \return
    /// Returns true if time has been defined.
    /// 
    bool IsTime() {return year == -1 && hour != -1;}

    /// \brief
    /// Returns true if both the date and time is valid
    /// 
    /// \return
    /// Returns true if both the date and time has been defined.
    /// 
    bool IsDateTime() {return year != -1 && hour != -1;}
    
    FdoInt16    year;
    FdoInt8     month;
    FdoInt8     day;
    FdoInt8     hour;
    FdoInt8     minute;
    float       seconds;
};
#endif // _FDOTYPES_H_



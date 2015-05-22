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

#ifndef FdoCommonOSUtil___H
#define FdoCommonOSUtil___H	1


// Operating-System-independent c-style declarations:
#ifdef _WIN32
#define OS__cdecl __cdecl
#else // not _WIN32
#define OS__cdecl
#endif


// This class define methods that run on both Windows and Linux.
class FdoCommonOSUtil
{
public:
    /// format a wide-char string to a wide-char string:
    static int swprintf(wchar_t* buffer, size_t bufferSize, const wchar_t* format, ...);

    /// convert a double to an ascii string:
    static char* gcvt(double number, size_t ndigit, char *buf);

    /// compare two ascii strings in a case-insensitive manner:
    static int stricmp(const char *s1, const char *s2);
    static int strnicmp(const char *s1, const char *s2, size_t len);

    /// compare two unicode strings in a case-insensitive manner:
    static int wcsicmp(const wchar_t *s1, const wchar_t *s2);
    static int wcsnicmp(const wchar_t *s1, const wchar_t *s2, size_t len);

    /// convert an int to an ascii string (radix is always 10):
    static char* itoa(int value, char* buffer);

    /// convert a long to an ascii string (radix is always 10):
    static char* ltoa(long value, char* buffer);

    /// convert an int to a wide string (radix is always 10):
    static wchar_t* itow(int value, wchar_t* buffer, size_t bufferSize);

    /// convert a long to a wide string (radix is always 10):
    static wchar_t* ltow(long value, wchar_t* buffer, size_t bufferSize);

    /// convert a string to an int (radix is always 10):
    static int wtoi(const wchar_t* value);

    /// convert a string to a floating point value
    static double wtof(const wchar_t* value);

    /// multibyte character string functions:
    static int ismbslead(const unsigned char *string, const unsigned char *current);
    static int ismbstrail(const unsigned char *string, const unsigned char *current);
    static int ismbcalnum(const unsigned char *string, long stringLength, const unsigned char *current);
    static int ismbcalpha(const unsigned char *string, long stringLength, const unsigned char *current);
    static char* mbscat(char *strDestination, const char *strSource);

    /// get current system time:
    static void getsystime(struct tm *systime);

    /// tokenize a unicode string:
    static wchar_t* wcstok(wchar_t *tokens, const wchar_t *delimiters, wchar_t **state);

    /// Convert a wide string to uppercase:
    static wchar_t* wcsupr(wchar_t* str);

    /// Return a duplicate copy of a wide string (use free() to deallocate):
    static wchar_t* wcsdup(wchar_t* str);

    /// Tests for Not-A-Number (NaN), returns non-zero if value is NaN, returns zero otherwise:
    static int _isnan(double value);

    /// Fetch a wide char from input:
    static wint_t _getwch(void);

    /// Set an environment variable:
    static void setenv(const char *varname, const char *varvalue);

    /// Get the current user's name:
    static FdoStringP GetCurrentUserName(void);
};

#endif // FdoCommonOSUtil___H



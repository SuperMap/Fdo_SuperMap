/*
 * 
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

#include "stdafx.h"
#include "FdoCommonStringUtil.h"
#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#ifndef _WIN32
#include <wctype.h>
#endif

FdoString*  FdoCommonStringUtil::NullString = L"NULL";

void FdoCommonStringUtil::ClearString(wchar_t*& psz)
{
    if (psz != NULL)
        delete [] psz;
    psz = NULL;
}

wchar_t* FdoCommonStringUtil::MakeString(FdoString* psz1, FdoString* psz2, FdoString* psz3, FdoString* psz4, FdoString* psz5)
{
    if (!psz1 && !psz2 && !psz3 && !psz4 && !psz5)
        return NULL;

    size_t  iLen = 1;   // 1 for EOS
    if (psz1 != NULL)
        iLen += FdoCommonStringUtil::StringLength(psz1);
    if (psz2 != NULL)
        iLen += FdoCommonStringUtil::StringLength(psz2);
    if (psz3 != NULL)
        iLen += FdoCommonStringUtil::StringLength(psz3);
    if (psz4 != NULL)
        iLen += FdoCommonStringUtil::StringLength(psz4);
    if (psz5 != NULL)
        iLen += FdoCommonStringUtil::StringLength(psz5);

    wchar_t*    pszRet = new wchar_t[iLen];
    *pszRet = L'\0';

    if (psz1 != NULL)
        FdoCommonStringUtil::StringConcatenate(pszRet, psz1);
    if (psz2 != NULL)
        FdoCommonStringUtil::StringConcatenate(pszRet, psz2);
    if (psz3 != NULL)
        FdoCommonStringUtil::StringConcatenate(pszRet, psz3);
    if (psz4 != NULL)
        FdoCommonStringUtil::StringConcatenate(pszRet, psz4);
    if (psz5 != NULL)
        FdoCommonStringUtil::StringConcatenate(pszRet, psz5);

    return pszRet;
}

wchar_t* FdoCommonStringUtil::MakeString(FdoInt32 numStrings, FdoString* * strings, FdoString* separator)
{
    size_t  iLen = 1;   // 1 for EOS
    FdoInt32     i;          // index

    for (i = 0;  i < numStrings;  i++)
    {
        if (NULL != separator && i > 0)
            iLen += FdoCommonStringUtil::StringLength(separator);
        if (strings[i] != NULL)
            iLen += FdoCommonStringUtil::StringLength(strings[i]);
    }

    wchar_t*    pszRet = new wchar_t[iLen];
    *pszRet = L'\0';

    for (i = 0;  i < numStrings;  i++)
    {
        if (NULL != separator && i > 0)
            FdoCommonStringUtil::StringConcatenate(pszRet, separator);
        if (strings[i] != NULL)
            FdoCommonStringUtil::StringConcatenate(pszRet, strings[i]);
    }

    return pszRet;
}

wchar_t* FdoCommonStringUtil::MakeString(FdoByte* pData, FdoInt32 iDataSize)
{
    if (pData == NULL || iDataSize == 0)
    {
        return FdoCommonStringUtil::MakeString(FdoCommonStringUtil::NullString);
    }

    size_t  iLen = 3;       // 1 for eos, 2 for braces {}
    iLen += 5 * iDataSize;  // "\x12 " for each byte
    wchar_t*    szGeom = new wchar_t[iLen];

    FdoInt32 iByte;
    FdoCommonStringUtil::StringCopy(szGeom, L"{");
    for (iByte = 0; iByte < iDataSize; iByte++)
    {
        wchar_t szByte[6];  // " \x12"
        FdoInt32     iChar;

        iChar = 0;
        if (iByte != 0)
            szByte[iChar++] = L' ';

        szByte[iChar++] = L'\\';
        szByte[iChar++] = L'x';

        FdoByte     bNibble = (pData[iByte] >> 4) & 0x0F;
        if (bNibble > 0x09)
            szByte[iChar++] = L'A' + (bNibble - 10);
        else
            szByte[iChar++] = L'0' + bNibble;

        bNibble = pData[iByte] & 0x0F;
        if (bNibble > 0x09)
            szByte[iChar++] = L'A' + (bNibble - 10);
        else
            szByte[iChar++] = L'0' + bNibble;

        szByte[iChar++] = L'\0';
        FdoCommonStringUtil::StringConcatenate(szGeom, szByte);
    }
    FdoCommonStringUtil::StringConcatenate(szGeom, L"}");
	return szGeom;
}

void FdoCommonStringUtil::FormatDouble(double d, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale)
{
    FormatNumber(d, DBL_DIG, pszBuffer, iLen, bUseLocale);
}

void FdoCommonStringUtil::FormatSingle(float f, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale)
{
    FormatNumber(f, FLT_DIG, pszBuffer, iLen, bUseLocale);
}

void FdoCommonStringUtil::FormatNumber(double d, FdoInt32 precision, wchar_t* pszBuffer, FdoInt32 iLen, bool bUseLocale)
{
    int             left;               // digits to left of decimal
    int             right;              // digits to right of decimal
    wchar_t*        end;                // end of formatted string
    wchar_t         radix = L'\0';      // radix character
    struct lconv    *nls;               // NLS info

    
    // Get NLS Info and extract the decimal separator character (if available)
    nls = localeconv();
    if (nls && bUseLocale)
        radix = nls->decimal_point[0];
    if (radix == '\0')
        radix = '.';    // if not there, default to '.'

    // determine digits to left of decimal point.  note: add 1.0 before int cnv
    // so that: 1.n=>1, 0.n=>0 not 0.n=>1
    if (d > 0)
        left = (int)(log10(d) + 1.0);
    else if (d < 0)
        left = (int)(log10(-d) + 1.0);
    else
        left = 0;
    //  treat 0 like .nnnn ...
    if (left < 0)
        left = 0;

    // determine digits allowed on right, within precision
    right = precision - left;

    //  format with appropriate decimals
    if (right < 0)      // go to exponential format
    {
        right = 0;
#ifdef _WIN32
        _snwprintf(pszBuffer, iLen, L"%.*g", precision, d);
#else
        swprintf(pszBuffer, iLen, L"%.*g", precision, d);
#endif
        return;
    }
    else
#ifdef _WIN32
        _snwprintf(pszBuffer, iLen, L"%.*f", right, d);
#else
        swprintf(pszBuffer, iLen, L"%.*f", right, d);
#endif
    end = pszBuffer + FdoCommonStringUtil::StringLength(pszBuffer) - 1;

    //  note: sprintf rounds dec remove trailing '0's if there is a decimal
    if (right > 0) {
        while (*end == '0')
            end--;
    }

    //  remove radix if no decimal
    if (*end == radix)
        *end = L'\0';
    else
        *(end+1) = L'\0';   //  keep last non-zero

    // special case for "-0".  Change to "0"
    if (FdoCommonStringUtil::StringCompare(pszBuffer, L"-0") == 0)
        FdoCommonStringUtil::StringCopy(pszBuffer, L"0");
}

wchar_t* FdoCommonStringUtil::QuoteString(FdoString* pszIn, wchar_t chQuote)
{
    // string functions below fail when pszIn == NULL
    if (pszIn == NULL || *pszIn == L'\0')
    {
        wchar_t*    pszRet = new wchar_t[3];
        pszRet[0] = chQuote;
        pszRet[1] = chQuote;
        pszRet[2] = L'\0';
        return pszRet;
    }

    size_t  iLen = FdoCommonStringUtil::StringLength(pszIn) + 3; // 1 for EOS and 2 for quotes.

    FdoString*  psz = FdoCommonStringUtil::FindCharacter(pszIn, chQuote);
    while (psz != NULL)
    {
        iLen++;     // add 1 more for double quote

        psz++;
        psz = FdoCommonStringUtil::FindCharacter(psz, chQuote);
    }

    size_t      iPos = 0;
    wchar_t*    pszOut = new wchar_t[iLen];
    pszOut[iPos++] = chQuote;
    pszOut[iPos] = L'\0';

    FdoString*  pszStart = pszIn;
    FdoString*  pszEnd = FdoCommonStringUtil::FindCharacter(pszStart, chQuote);
    while (pszEnd != NULL)
    {
        // copy up to (but not including) quote char.
        FdoCommonStringUtil::SubstringCopy(&pszOut[iPos], pszStart, (pszEnd - pszStart));
        iPos += (pszEnd - pszStart);

        // copy quote char 2x
        pszOut[iPos++] = chQuote;
        pszOut[iPos++] = chQuote;
        pszOut[iPos] = L'\0';

        // skip over quote char and go again
        pszStart = pszEnd + 1;
        pszEnd = FdoCommonStringUtil::FindCharacter(pszStart, chQuote);
    }

    // no more quote chars, copy rest of string
    FdoCommonStringUtil::StringConcatenate(pszOut, pszStart);

    iPos = FdoCommonStringUtil::StringLength(pszOut);
    pszOut[iPos++] = chQuote;
    pszOut[iPos] = L'\0';
    return pszOut;
}

FdoInt64 FdoCommonStringUtil::StringToInt64( FdoString* str )
{
    FdoInt64 ret =
#ifdef _WIN32
        _wtoi64( str );
#else
       atoll ( (const char*) FdoStringP(str) );   
#endif

    return ret;
}

FdoStringP FdoCommonStringUtil::Int64ToString( FdoInt64 val ) 
{
    return FdoStringP::Format(
#ifdef _WIN32
        L"%I64d",
#else
        L"%lld",
#endif
        val
    );
}

size_t FdoCommonStringUtil::StringLength(FdoString* string)
{
    if (string == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcslen(string);
}

FdoInt32 FdoCommonStringUtil::StringCompare(FdoString* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcscmp(string1, string2);
}

FdoInt32 FdoCommonStringUtil::StringCompareNoCase(FdoString* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

#ifdef _WIN32
    return _wcsicmp(string1, string2);
#else
    return wcscasecmp(string1, string2);
#endif
}

FdoInt32 FdoCommonStringUtil::StringCompareNoCaseN(FdoString* string1, FdoString* string2, FdoSize count)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

#ifdef _WIN32
    return _wcsnicmp(string1, string2, count);
#else
    return wcsncasecmp(string1, string2, count);
#endif
}

void FdoCommonStringUtil::StringCopy(wchar_t* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    wcscpy(string1, string2);
}

void FdoCommonStringUtil::SubstringCopy(wchar_t* string1, FdoString* string2, size_t length)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    wcsncpy(string1, string2, length);
}

void FdoCommonStringUtil::StringConcatenate(wchar_t* string1, FdoString* string2)
{
    if (string1 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    if (string2 == NULL)
        return;

    wcscat(string1, string2);
}

FdoString* FdoCommonStringUtil::FindCharacter(FdoString* string, wchar_t character)
{
    if (string == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcschr(string, character);
}

wchar_t* FdoCommonStringUtil::StringTrim (wchar_t *str)
{
    wchar_t *p;
    wchar_t *q;

    p = str;
    q = str;
    while (iswspace (*p))
        p++;
    if (p != str)
    {
        while ('\0' != *p)
            *q++ = *p++;
        *q = *p;
    }
    else
        while ('\0' != *q)
            q++;
    // q now at terminating 0 of str
    if (q > str)
        while (iswspace (*(q - 1)) && ((q - 1) >= str))
            q--;
    *q = '\0';

    return (str);
}


void FdoCommonStringUtil::PrintString (FdoString * string)
{
    printf("'%ls'\n", string);
    fflush(stdout);
}

void fdoprints(FdoString * string)
{
    FdoCommonStringUtil::PrintString(string);
}

bool FdoCommonStringUtil::AllASCII (FdoString* string)
{
    FdoString* p;
    bool ret;
    
    ret = true;

    p = &string[0];
    while (ret && (L'\0' != *p))
    {
        if (0 != ((*p) & ~0x7F)) // could use iswascii if it was portable
            ret = false;
        p++;
    }

    return (ret);
}



// COPY BEGIN -  THIS CODE IS COPIED FROM Fdo\Unmanaged\src\common

//----------------------------------------------------------------------------
//
// Fast and portable UTF-8 conversion
// Taken from DWF Toolkit string class
//
//----------------------------------------------------------------------------

#ifdef _WIN32

#define _WCHAR_MAX      SHRT_MAX
#define _SHRT_MAX       SHRT_MAX
#define _INT_MAX        INT_MAX

typedef char                    ASCII_char_t;
typedef wchar_t                 UCS2_char_t;
typedef unsigned __int32        UCS4_char_t;

#else

#define _WCHAR_MAX      __WCHAR_MAX
#define _SHRT_MAX       __SHRT_MAX__
#define _INT_MAX        __INT_MAX__

#if (_WCHAR_MAX == _SHRT_MAX)

typedef char         ASCII_char_t;
typedef wchar_t      UCS2_char_t;
typedef uin32_t UCS4_char_t;

#else

typedef char        ASCII_char_t;
typedef uint16_t      UCS2_char_t;
typedef wchar_t     UCS4_char_t;

#endif

#endif

#define LITTLE_ENDIAN_SYSTEM

int _EncodeUTF8(     const UCS2_char_t*   zUCS2String,
                    size_t               nUCS2StringBytes,
                    ASCII_char_t*        pUTF8Buffer,
                    size_t               nUTF8BufferBytes )
{
    unsigned char cHi = 0,
                  cLo = 0;
    char* pIn = (char*)zUCS2String;
    char* pOut = (char*)pUTF8Buffer;

    size_t nUsed = 0;
    size_t nAllowed = nUTF8BufferBytes - sizeof(ASCII_char_t);
    size_t nLen = nUCS2StringBytes >> 1;

    for (register size_t i = 0; i < nLen; i++, pIn+=2)
    {
        //check for null terminated string
        if (zUCS2String[i] == 0)
            break;

#ifdef LITTLE_ENDIAN_SYSTEM

        cHi = *pIn;
        cLo = *(pIn+1);
#else

        cLo = *pIn;
        cHi = *(pIn+1);
#endif

        if ((cLo == 0) && (cHi < 0x80))
        {
            if ((++nUsed > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }
 
            if (pOut)
            {
                *(pOut++) = cHi;
            }
        }
        else if (cLo < 0x08)
        {
            if (((nUsed+=2) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }
 
            if (pOut)
            {
                *(pOut++) = (0xc0 | (cLo << 2) | (cHi >> 6));           // 110lllhh
                *(pOut++) = (0x80 | (cHi & 0x3f));                      // 10hhhhhh
            }
        }
        else
        {
            if (((nUsed+=3) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }
 
            if (pOut)
            {
                *(pOut++) = (0xe0 | (cLo >> 4));                        // 1110llll
                *(pOut++) = (0x80 | ((cLo & 0x0f) << 2) | cHi >> 6);    // 10llllhh
                *(pOut++) = (0x80 | (cHi & 0x3f));                      // 10hhhhhh
            }
        }
    }

    if (pOut)
    {
        *(pOut++) = 0;
    }

    return (int)nUsed;
}


int _EncodeUTF8( const UCS4_char_t*   zUCS4String,
                       size_t               nUCS4StringBytes,
                       ASCII_char_t*        pUTF8Buffer,
                       size_t               nUTF8BufferBytes )
{
    unsigned char a = 0,
                  b = 0,
                  c = 0,
                  d = 0;
    char* pIn = (char*)zUCS4String;
    char* pOut = (char*)pUTF8Buffer;

    size_t nUsed = 0;
    size_t nAllowed = nUTF8BufferBytes - sizeof(ASCII_char_t);
    size_t nLen = nUCS4StringBytes >> 2;
    register size_t i;

    for (i = 0; i < nLen; i++, pIn+=4)
    {
        //check for null terminated string
        if (zUCS4String[i] == 0)
            break;

#ifdef  LITTLE_ENDIAN_SYSTEM

        d = *pIn;
        c = *(pIn+1);
        b = *(pIn+2);
        a = *(pIn+3);
#else

        a = *pIn;
        b = *(pIn+1);
        c = *(pIn+2);
        d = *(pIn+3);
#endif

        if (a >= 0xd8)
        {
            return -1;
            //_DWFCORE_THROW( DWFNotImplementedException, L"Unicode surrogate pairs not yet supported" );
        }
        else if (a >= 0x80)
        { 
            return -1;
            //_DWFCORE_THROW( DWFInvalidArgumentException, L"Not a valid Unicode string" );
        }
        else if (a >= 0x04)
        {
            if (((nUsed+=6) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = (0xfc | (a >> 6));                          // 1111110a
                *(pOut++) = (0x80 | (a & 0x3f));                        // 10aaaaaa
                *(pOut++) = (0x80 | (b >> 2));                          // 10bbbbbb
                *(pOut++) = (0x80 | ((b & 0x03) << 4) | (c >> 4));      // 10bbcccc
                *(pOut++) = (0x80 | ((c & 0x0f) << 2) | (d >> 6));      // 10ccccdd
                *(pOut++) = (0x80 | (d & 0x3f));                        // 10dddddd
            }
        }
        else if ((a > 0x0) || (b >= 0x20))
        {
            if (((nUsed+=5) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = (0xf8 | a);                                 // 111110aa
                *(pOut++) = (0x80 | (b >> 2));                          // 10bbbbbb
                *(pOut++) = (0x80 | ((b & 0x03) << 4) | (c >> 4));      // 10bbcccc
                *(pOut++) = (0x80 | ((c & 0x0f) << 2) | (d >> 6));      // 10ccccdd
                *(pOut++) = (0x80 | (d & 0x3f));                        // 10dddddd
            }
        }
        else if (b >= 0x01)
        {
            if (((nUsed+=4) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = (0xf0 | (b >> 2));                          // 11110bbb
                *(pOut++) = (0x80 | ((b & 0x03) << 4) | (c >> 4));      // 10bbcccc
                *(pOut++) = (0x80 | ((c & 0x0f) << 2) | (d >> 6));      // 10ccccdd
                *(pOut++) = (0x80 | (d & 0x3f));                        // 10dddddd
            }
        }
        else if (c >= 0x08)
        {
            if (((nUsed+=3) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = (0xe0 | (c >> 4));                          // 1110cccc
                *(pOut++) = (0x80 | ((c & 0x0f) << 2) | d >> 6);        // 10ccccdd
                *(pOut++) = (0x80 | (d & 0x3f));                        // 10dddddd
            }
        }
        else if ((c > 0x0) || (d >= 0x80))
        {
            if (((nUsed+=2) > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = (0xc0 | (c << 2) | (d >> 6));               // 110cccdd
                *(pOut++) = (0x80 | (d & 0x3f));                        // 10dddddd
            }
        }
        else 
        {
            if ((++nUsed > nAllowed) && pOut)
            {
                *pOut = 0;
                return -1;
                //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small" );
            }

            if (pOut)
            {
                *(pOut++) = d;
            }
        }
    }

    if (pOut)
    {
        *(pOut++) = 0;
    }

    return (int)nUsed;
}

int _DecodeUTF8(     const ASCII_char_t*  zUTF8String,
                       size_t               nUTF8StringBytes,
                       UCS2_char_t*         pUCS2Buffer,
                       size_t               nUCS2BufferBytes )
{
    unsigned char  c1 = 0,
                   c2 = 0,
                   c3 = 0;
    char* pIn = (char*)zUTF8String;
    char* pOut = (char*)pUCS2Buffer;
    size_t nUsed = 0;
    size_t nAllowed = nUCS2BufferBytes - sizeof(UCS2_char_t);

    for (register size_t i = 0; i < nUTF8StringBytes; i++, pIn++)
    {
        if (*pIn == 0)
            break;

        if (((nUsed+=2) > nAllowed) && pOut)
        {
            *pOut = 0;
            return -1;
            //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small." );
        }

        c1 = *pIn;

            //
            // one byte
            //
        if (c1 < 0x80)
        {

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = c1;
            *(pOut++) = 0x00;
#else

            *(pOut++) = 0x00;
            *(pOut++) = c1;
#endif

        }
            //
            // three bytes
            //
        else if ((c1 & 0xf0) == 0xe0)
        {
            c2 = *(pIn+1);
            c3 = *(pIn+2);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = (((c2 & 0x03) << 6) |  (c3 & 0x3f));
            *(pOut++) = (((c1 & 0x0f) << 4) | ((c2 & 0x3c) >> 2));
#else

            *(pOut++) = (((c1 & 0x0f) << 4) | ((c2 & 0x3c) >> 2));
            *(pOut++) = (((c2 & 0x03) << 6) |  (c3 & 0x3f));
#endif

            i += 2;
            pIn += 2;
        }
            //
            // two bytes
            //
        else
        {
            c2 = *(pIn+1);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = (((c1 & 0x03) << 6) | (c2 & 0x3f));
            *(pOut++) = ((c1 & 0x1c) >> 2);
#else

            *(pOut++) = ((c1 & 0x1c) >> 2);
            *(pOut++) = (((c1 & 0x03) << 6) | (c2 & 0x3f));
#endif

            i++;
            pIn++;
        }
    }

    *(pOut++) = 0;
    *(pOut++) = 0;

    return (int)nUsed;
}


int _DecodeUTF8(     const ASCII_char_t*  zUTF8String,
                       size_t               nUTF8StringBytes,
                       UCS4_char_t*         pUCS4Buffer,
                       size_t               nUCS4BufferBytes )
{
    unsigned char  a = 0,
                   b = 0,
                   c = 0,
                   d = 0,
                   e = 0,
                   f = 0;

    char* pIn = (char*)zUTF8String;
    char* pOut = (char*)pUCS4Buffer;
    size_t nUsed = 0;
    size_t nAllowed = nUCS4BufferBytes - sizeof(UCS4_char_t);
    register size_t i;

    for (i = 0; i < nUTF8StringBytes; i++, pIn++)
    {
        if (*pIn == 0)
            break;

        if ((nUsed+=4) > nAllowed)
        {
            *pOut = 0;
            return -1;
            //_DWFCORE_THROW( DWFOverflowException, L"Buffer too small." );
        }

        a = *pIn;

            //
            // six bytes
            //
        if ((a & 0xfc) == 0xfc)
        {
            b = *(pIn+1);
            c = *(pIn+2);
            d = *(pIn+3);
            e = *(pIn+4);
            f = *(pIn+5);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = ((e << 6) | (f & 0x3f));
            *(pOut++) = ((d << 4) | ((e & 0x3c) >> 2));
            *(pOut++) = ((c << 2) | ((d & 0x30) >> 4));
            *(pOut++) = ((a << 6) | (b & 0x3f));
#else

            *(pOut++) = ((a << 6) | (b & 0x3f));
            *(pOut++) = ((c << 2) | ((d & 0x30) >> 4));
            *(pOut++) = ((d << 4) | ((e & 0x3c) >> 2));
            *(pOut++) = ((e << 6) | (f & 0x3f));
#endif

            pIn += 5;
        }
            //
            // five bytes
            //
        else if ((a & 0xf8) == 0xf8)
        {
            b = *(pIn+1);
            c = *(pIn+2);
            d = *(pIn+3);
            e = *(pIn+4);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = ((d << 6) | (e & 0x3f));
            *(pOut++) = ((c << 4) | ((d & 0x3c) >> 2));
            *(pOut++) = ((b << 2) | ((c & 0x30) >> 4));
            *(pOut++) = (a & 0x03);
#else

            *(pOut++) = (a & 0x03);
            *(pOut++) = ((b << 2) | ((c & 0x30) >> 4));
            *(pOut++) = ((c << 4) | ((d & 0x3c) >> 2));
            *(pOut++) = ((d << 6) | (e & 0x3f));
#endif

            pIn += 4;
        }
            //
            // four bytes
            //
        else if ((a & 0xf0) == 0xf0)
        {
            b = *(pIn+1);
            c = *(pIn+2);
            d = *(pIn+3);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = ((c << 6) | (d & 0x3f));
            *(pOut++) = ((b << 4) | ((c & 0x3c) >> 2));
            *(pOut++) = (((a & 0x07) << 2) | ((b & 0x30) >> 4));
            *(pOut++) = 0x00;
#else

            *(pOut++) = 0x00;
            *(pOut++) = (((a & 0x07) << 2) | ((b & 0x30) >> 4));
            *(pOut++) = ((b << 4) | ((c & 0x3c) >> 2));
            *(pOut++) = ((c << 6) | (d & 0x3f));
#endif

            pIn += 3;
        }

            //
            // one byte
            //
        else if (a < 0x80)
        {

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = a;
            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
#else

            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
            *(pOut++) = a;
#endif

        }
            //
            // three bytes
            //
        else if ((a & 0xf0) == 0xe0)
        {
            b = *(pIn+1);
            c = *(pIn+2);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = (((b & 0x03) << 6) |  (c & 0x3f));
            *(pOut++) = (((a & 0x0f) << 4) | ((b & 0x3c) >> 2));
            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
#else

            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
            *(pOut++) = (((a & 0x0f) << 4) | ((b & 0x3c) >> 2));
            *(pOut++) = (((b & 0x03) << 6) |  (c & 0x3f));
#endif

            i += 2;
            pIn += 2;
        }
            //
            // two bytes
            //
        else
        {
            b = *(pIn+1);

#ifdef  LITTLE_ENDIAN_SYSTEM

            *(pOut++) = (((a & 0x03) << 6) | (b & 0x3f));
            *(pOut++) = ((a & 0x1c) >> 2);
            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
#else

            *(pOut++) = 0x00;
            *(pOut++) = 0x00;
            *(pOut++) = ((a & 0x1c) >> 2);
            *(pOut++) = (((a & 0x03) << 6) | (b & 0x3f));
#endif

            i++;
            pIn++;
        }
    }

    *((UCS4_char_t*)pOut++) = 0;

    return (int)nUsed;
}

//------------------------------------------------------------------------
//
// The public interface
//
//------------------------------------------------------------------------

int _ut_utf8_to_unicode(const char* str_in, size_t in_size, wchar_t* Wtext, size_t out_size)
{
    int ret = _DecodeUTF8(str_in, in_size, Wtext, out_size * sizeof(wchar_t));
    return ret / sizeof(wchar_t);
}

int _ut_utf8_from_unicode(const wchar_t* Wtext, size_t in_size, char* str_out, int out_size)
{
    return _EncodeUTF8(Wtext, in_size * sizeof(wchar_t), str_out, out_size);
}

// COPY END -  THIS CODE IS COPIED FROM Fdo\Unmanaged\src\common


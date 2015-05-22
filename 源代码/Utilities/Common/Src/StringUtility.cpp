// 
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
//  
#include "stdafx.h"
#include "StringUtility.h"
#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>

FdoString*  FdoStringUtility::NullString = L"NULL";

void FdoStringUtility::ClearString(wchar_t*& psz)
{
    if (psz != NULL)
        delete [] psz;
    psz = NULL;
}

wchar_t* FdoStringUtility::MakeString(FdoString* psz1, FdoString* psz2, FdoString* psz3, FdoString* psz4, FdoString* psz5)
{
    if (!psz1 && !psz2 && !psz3 && !psz4 && !psz5)
        return NULL;

    size_t  iLen = 1;   // 1 for EOS
    if (psz1 != NULL)
        iLen += FdoStringUtility::StringLength(psz1);
    if (psz2 != NULL)
        iLen += FdoStringUtility::StringLength(psz2);
    if (psz3 != NULL)
        iLen += FdoStringUtility::StringLength(psz3);
    if (psz4 != NULL)
        iLen += FdoStringUtility::StringLength(psz4);
    if (psz5 != NULL)
        iLen += FdoStringUtility::StringLength(psz5);

    wchar_t*    pszRet = new wchar_t[iLen];
    *pszRet = L'\0';

    if (psz1 != NULL)
        FdoStringUtility::StringConcatenate(pszRet, psz1);
    if (psz2 != NULL)
        FdoStringUtility::StringConcatenate(pszRet, psz2);
    if (psz3 != NULL)
        FdoStringUtility::StringConcatenate(pszRet, psz3);
    if (psz4 != NULL)
        FdoStringUtility::StringConcatenate(pszRet, psz4);
    if (psz5 != NULL)
        FdoStringUtility::StringConcatenate(pszRet, psz5);

    return pszRet;
}

wchar_t* FdoStringUtility::MakeString(FdoInt32 numStrings, FdoString* * strings, FdoString* separator)
{
    size_t  iLen = 1;   // 1 for EOS
    FdoInt32     i;          // index

    for (i = 0;  i < numStrings;  i++)
    {
        if (NULL != separator && i > 0)
            iLen += FdoStringUtility::StringLength(separator);
        if (strings[i] != NULL)
            iLen += FdoStringUtility::StringLength(strings[i]);
    }

    wchar_t*    pszRet = new wchar_t[iLen];
    *pszRet = L'\0';

    for (i = 0;  i < numStrings;  i++)
    {
        if (NULL != separator && i > 0)
            FdoStringUtility::StringConcatenate(pszRet, separator);
        if (strings[i] != NULL)
            FdoStringUtility::StringConcatenate(pszRet, strings[i]);
    }

    return pszRet;
}

wchar_t* FdoStringUtility::MakeString(FdoByte* pData, FdoInt32 iDataSize)
{
    if (pData == NULL || iDataSize == 0)
    {
        return FdoStringUtility::MakeString(FdoStringUtility::NullString);
    }

    size_t  iLen = 3;       // 1 for eos, 2 for braces {}
    iLen += 5 * iDataSize;  // "\x12 " for each byte
    wchar_t*    szGeom = new wchar_t[iLen];

    FdoInt32 iByte;
    FdoStringUtility::StringCopy(szGeom, L"{");
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
        FdoStringUtility::StringConcatenate(szGeom, szByte);
    }
    FdoStringUtility::StringConcatenate(szGeom, L"}");
	return szGeom;
}

void FdoStringUtility::FormatDouble(double d, wchar_t* pszBuffer, FdoInt32 iLen)
{
    FormatNumber(d, DBL_DIG, pszBuffer, iLen);
}

void FdoStringUtility::FormatSingle(float f, wchar_t* pszBuffer, FdoInt32 iLen)
{
    FormatNumber(f, FLT_DIG, pszBuffer, iLen);
}

void FdoStringUtility::FormatNumber(double d, FdoInt32 precision, wchar_t* pszBuffer, FdoInt32 iLen)
{
    int             left;               // digits to left of decimal
    int             right;              // digits to right of decimal
    wchar_t*        end;                // end of formatted string
    wchar_t         radix = L'\0';      // radix character
    struct lconv    *nls;               // NLS info

    
    // Get NLS Info and extract the decimal separator character (if available)
    nls = localeconv();
    if (nls)
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
    end = pszBuffer + FdoStringUtility::StringLength(pszBuffer) - 1;

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
    if (FdoStringUtility::StringCompare(pszBuffer, L"-0") == 0)
        FdoStringUtility::StringCopy(pszBuffer, L"0");
}

wchar_t* FdoStringUtility::QuoteString(FdoString* pszIn, wchar_t chQuote)
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

    size_t  iLen = FdoStringUtility::StringLength(pszIn) + 3; // 1 for EOS and 2 for quotes.

    FdoString*  psz = FdoStringUtility::FindCharacter(pszIn, chQuote);
    while (psz != NULL)
    {
        iLen++;     // add 1 more for double quote

        psz++;
        psz = FdoStringUtility::FindCharacter(psz, chQuote);
    }

    size_t      iPos = 0;
    wchar_t*    pszOut = new wchar_t[iLen];
    pszOut[iPos++] = chQuote;
    pszOut[iPos] = L'\0';

    FdoString*  pszStart = pszIn;
    FdoString*  pszEnd = FdoStringUtility::FindCharacter(pszStart, chQuote);
    while (pszEnd != NULL)
    {
        // copy up to (but not including) quote char.
        FdoStringUtility::SubstringCopy(&pszOut[iPos], pszStart, (pszEnd - pszStart));
        iPos += (pszEnd - pszStart);

        // copy quote char 2x
        pszOut[iPos++] = chQuote;
        pszOut[iPos++] = chQuote;
        pszOut[iPos] = L'\0';

        // skip over quote char and go again
        pszStart = pszEnd + 1;
        pszEnd = FdoStringUtility::FindCharacter(pszStart, chQuote);
    }

    // no more quote chars, copy rest of string
    FdoStringUtility::StringConcatenate(pszOut, pszStart);

    iPos = FdoStringUtility::StringLength(pszOut);
    pszOut[iPos++] = chQuote;
    pszOut[iPos] = L'\0';
    return pszOut;
}

size_t FdoStringUtility::StringLength(FdoString* string)
{
    if (string == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcslen(string);
}

FdoInt32 FdoStringUtility::StringCompare(FdoString* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcscmp(string1, string2);
}

FdoInt32 FdoStringUtility::StringCompareNoCase(FdoString* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

#ifdef _WIN32
    return _wcsicmp(string1, string2);
#else
    return wcscasecmp(string1, string2);
#endif
}

void FdoStringUtility::StringCopy(wchar_t* string1, FdoString* string2)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    wcscpy(string1, string2);
}

void FdoStringUtility::SubstringCopy(wchar_t* string1, FdoString* string2, size_t length)
{
    if (string1 == NULL || string2 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    wcsncpy(string1, string2, length);
}

void FdoStringUtility::StringConcatenate(wchar_t* string1, FdoString* string2)
{
    if (string1 == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    if (string2 == NULL)
        return;

    wcscat(string1, string2);
}

FdoString* FdoStringUtility::FindCharacter(FdoString* string, wchar_t character)
{
    if (string == NULL)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_14_NULLSTRING)));

    return wcschr(string, character);
}



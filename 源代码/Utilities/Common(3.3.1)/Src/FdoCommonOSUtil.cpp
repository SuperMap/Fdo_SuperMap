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

#include <math.h>

#ifdef _WIN32
#include "mbstring.h" // for multibyte functions
#include <time.h>
#else //_WIN32
#include <wctype.h>  // for wide-char functions
#include <inttypes.h>
#include <unistd.h>
#include <termios.h>
#include <pwd.h>
#endif

#include "FdoCommonOSUtil.h"
#include "FdoCommonStringUtil.h"


#pragma warning(push)
#pragma warning(disable: 4100)  // Disable warning C4100: 'xxxx' : unreferenced formal parameter


int FdoCommonOSUtil::swprintf(wchar_t* buffer, size_t bufferSize, const wchar_t* format, ...)
{
    int retVal = 0;
    va_list  varargs;
    
    va_start(varargs, format);

    retVal = vswprintf(buffer, bufferSize, format, varargs);

    va_end(varargs);

    return retVal;
}

int FdoCommonOSUtil::scprintf(char* buffer, size_t bufferSize, const char* format, ...)
{
    int retVal = 0;
    va_list  varargs;
    
    va_start(varargs, format);

    retVal = vsprintf(buffer, format, varargs);

    va_end(varargs);

    return retVal;
}

char *FdoCommonOSUtil::gcvt(double number, size_t ndigits, char *buf)
{
#ifdef _WIN32
    return _gcvt (number, (int)ndigits, buf);
#else
    return ::gcvt (number, (int)ndigits, buf);
#endif
}


int FdoCommonOSUtil::stricmp(const char *s1, const char *s2)
{
#ifdef _WIN32
    return _stricmp(s1, s2);
#else
    return strcasecmp(s1, s2);
#endif
}

int FdoCommonOSUtil::strnicmp(const char *s1, const char *s2, size_t len)
{
#ifdef _WIN32
    return _strnicmp(s1, s2, len);  
#else
    return strncasecmp(s1, s2, len);
#endif
}

int FdoCommonOSUtil::wcsicmp(const wchar_t *s1, const wchar_t *s2)
{
#ifdef _WIN32
    return _wcsicmp(s1, s2);
#else
    return wcscasecmp(s1, s2);
#endif
}

int FdoCommonOSUtil::wcsnicmp(const wchar_t *s1, const wchar_t *s2, size_t len)
{
#ifdef _WIN32
    return _wcsnicmp (s1, s2, len);
#else
    return wcsncasecmp (s1, s2, len);
#endif
}

char* FdoCommonOSUtil::itoa(int value, char* buffer)
{
#ifdef _WIN32
    return _itoa(value, buffer, 10); // radix is always 10
#else
    sprintf(buffer, "%d", value);
    return buffer;
#endif
}

char* FdoCommonOSUtil::ltoa(long value, char* buffer)
{
#ifdef _WIN32
    return _ltoa(value, buffer, 10); // radix is always 10
#else
    sprintf(buffer, "%ld", value);
    return buffer;
#endif
}

wchar_t* FdoCommonOSUtil::itow(int value, wchar_t* buffer, size_t bufferSize)
{
#ifdef _WIN32
    return _itow(value, buffer, 10); // radix is always 10
#else
    swprintf(buffer, bufferSize, L"%d", value);
    return buffer;
#endif
}

wchar_t* FdoCommonOSUtil::ltow(long value, wchar_t* buffer, size_t bufferSize)
{
#ifdef _WIN32
    return _ltow(value, buffer, 10); // radix is always 10
#else
    swprintf(buffer, bufferSize, L"%ld", value);
    return buffer;
#endif
}

int FdoCommonOSUtil::wtoi(const wchar_t* value)
{
#ifdef _WIN32
    return _wtoi(value);
#else
    return (int)wcstol(value, NULL, 10);  // radix is always 10
#endif
}

double FdoCommonOSUtil::wtof(const wchar_t* value)
{
#ifdef _WIN32
    return _wtof(value);
#else
    return wcstod(value, NULL);
#endif
}

int FdoCommonOSUtil::ismbslead(const unsigned char *string, const unsigned char *current)
{
#ifdef _WIN32
    return _ismbslead(string, current);
#else // _WIN32
    mbstate_t pstate;
    int i = 0;
    int curPos = 0;
    int inquiryPos = (int)(current - string);
    int ret = 0;

    memset(&pstate, 0, sizeof(pstate));

    do
    {
        if (inquiryPos == curPos)
        {
            ret = -1;
            break;
        }

        i = mbrlen((const char*)(string + curPos), MB_CUR_MAX, &pstate);
        if (i < 0)
	        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                                   L"FdoCommonOSUtil::ismbslead",
                                                                   L"string"));

        if (i > 0)
	    curPos += i;
    }
    while (i > 0);

    return ret;
#endif
}

int FdoCommonOSUtil::ismbstrail(const unsigned char *string, const unsigned char *current)
{
#ifdef _WIN32
    return _ismbstrail(string, current);
#else // _WIN32
    return FdoCommonOSUtil::ismbslead(string, current)==-1 ? 0 : -1;
#endif
}

int FdoCommonOSUtil::ismbcalnum(const unsigned char *string, long stringLength, const unsigned char *current)
{
    wchar_t wBuffer;
    mbstate_t pstate;
    memset(&pstate, 0, sizeof(pstate));
    size_t lStatus = mbrtowc(&wBuffer, (const char*)current, stringLength - (current-string), &pstate);
    if (lStatus<0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonOSUtil::ismbcalnum",
                                                               L"string/current"));

    return iswalnum(wBuffer) ? -1 : 0;
}

int FdoCommonOSUtil::ismbcalpha(const unsigned char *string, long stringLength, const unsigned char *current)
{
    wchar_t wBuffer;
    mbstate_t pstate;
    memset(&pstate, 0, sizeof(pstate));
    size_t lStatus = mbrtowc(&wBuffer, (const char*)current, stringLength - (current-string), &pstate);
    if (lStatus<0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                               L"FdoCommonOSUtil::ismbcalpha",
                                                               L"string/current"));

    return iswalpha(wBuffer) ? -1 : 0;
}

void FdoCommonOSUtil::getsystime(struct tm *systime)
{
#ifdef _WIN32
#pragma warning(disable : 4996)
    _getsystime (systime);
#pragma warning(default : 4996)

#else
     time_t current;
     time (&current);
     localtime_r (&current, systime);
#endif
}


wchar_t* FdoCommonOSUtil::wcstok(wchar_t *tokens, const wchar_t *delimiters, wchar_t **state)
{
#ifdef _WIN32
    return ::wcstok(tokens, delimiters);
#else
    return ::wcstok(tokens, delimiters, state);
#endif
}



wchar_t* FdoCommonOSUtil::wcsupr(wchar_t* str)
{
    // Convert each letter to uppercase:
    wchar_t* pStringTerminator = str + wcslen(str);
    for (wchar_t* p=str; p < pStringTerminator; p++)
    {
        *p = towupper(*p);
    }

    // Return pointer to given string:
    return str;
}

wchar_t* FdoCommonOSUtil::wcslwr(wchar_t* str)
{
    // Convert each letter to lowercase:
    wchar_t* pStringTerminator = str + wcslen(str);
    for (wchar_t* p=str; p < pStringTerminator; p++)
    {
        *p = towlower(*p);
    }

    // Return pointer to given string:
    return str;
}




wchar_t* FdoCommonOSUtil::wcsdup(wchar_t* str)
{
#ifdef _WIN32
    return _wcsdup (str);
#else
    return wcsdup (str);
#endif
}


int FdoCommonOSUtil::_isnan(double value)
{
#ifdef _WIN32
    return ::_isnan(value);
#else
    return isnan(value);
#endif
}




char* FdoCommonOSUtil::mbscat(char *strDestination, const char *strSource)
{
#ifdef _WIN32
    return (char*)_mbscat((unsigned char *) strDestination, (const unsigned char*) strSource);
#else
    return strcat(strDestination, strSource);
#endif
}


wint_t FdoCommonOSUtil::_getwch(void)
{
#ifdef _WIN32
    return ::_getwch();
#else
    char   ch;
    int   error;
    struct termios ttyCurrent, tty;

    fflush(stdout);
    tcgetattr(0, &ttyCurrent);
    tty = ttyCurrent;

    tty.c_iflag  =  0;
    tty.c_oflag  =  0;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_cc[VMIN]  = CMIN;
    tty.c_cc[VTIME] = CTIME;

    if (0 == (error = tcsetattr(0, TCSAFLUSH, &tty))) {
        error  = read(0, &ch, 1 );
        error += tcsetattr(0, TCSAFLUSH, &ttyCurrent);
    }

    if (error == 1)
    {
        char string[2];
        wchar_t outputStringW[16];
        string[0] = ch;
        string[1] = '\0';
        _ut_utf8_to_unicode(string, strlen(string), outputStringW, sizeof(outputStringW)/sizeof(wchar_t)); 
        return outputStringW[0];
    }
    else
    {
       return WEOF; 
    }    
#endif
}

void FdoCommonOSUtil::setenv(const char *varname, const char *varvalue)
{
#ifdef _WIN32
    char* setstring = (char*)alloca(sizeof(char) * strlen(varname) + strlen(varvalue) + 2);
    sprintf(setstring, "%hs=%hs", varname, varvalue);
    _putenv(setstring);
#else
    if ((varvalue==NULL) || (strlen(varvalue)==0))
        ::unsetenv(varname);
    else
        ::setenv(varname, varvalue, 1);
#endif
}


FdoStringP FdoCommonOSUtil::GetCurrentUserName(void)
{
    const int usernamesize = 256;

#ifdef _WIN32
    DWORD intsize = usernamesize;
    wchar_t wusername[256];
    ::GetUserNameW(wusername, &intsize);
    return FdoStringP(wusername);
#else
    char username[256];
    struct passwd *passwd_ptr;
    static int real_uid;
    real_uid = getuid();
    passwd_ptr = getpwuid(real_uid);
    strncpy(username, passwd_ptr->pw_name, usernamesize);
    username[usernamesize-1] = 0;  // NOTE: not safe for utf-8 characters with trailing bytes; but 256-char utf8 usernames are highly unlikely
    return FdoStringP(username);
#endif
}  



#pragma warning(pop) // Enable warning C4100: 'xxxx' : unreferenced formal parameter



#ifdef _UNICODE

#ifndef _UTIL_STRING_ 
#define _UTIL_STRING_ 

#include <string>
#include <windows.h>
#include <tchar.h>

// ¿í×Ö·û±ß×ªASCII
std::string WcharToString(const wchar_t* wstr);
// ASCII×ª»»Îª¿í×Ö·û
std::wstring StringToWString(const std::string &str);

#endif

#endif



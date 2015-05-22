#ifdef _UNICODE

#include "Util.h"
// øÌ◊÷∑˚±ﬂ◊™ASCII
std::string WcharToString(const wchar_t* wstr)
{
	size_t		nSize;
	char	*ASCIITemp;

	nSize = _tcslen(wstr) * 2;

	ASCIITemp = (char*) malloc (nSize + 1);

	WideCharToMultiByte(
		CP_ACP, /* ANSI code page */
		0, /* no flags */
		wstr, /* wchar_t */
		(int)nSize,
		ASCIITemp,
		(int)nSize,
		NULL, /* Don't worry about other characters */
		NULL  /* Don't worry about other characters */
		);

	ASCIITemp[nSize] = '\0';

	std::string StringTemp(ASCIITemp);

	free(ASCIITemp);

	return StringTemp;
}

std::wstring StringToWString(const std::string &str)
{
	int		nSize;
	wchar_t *WTemp = NULL;

	nSize = MultiByteToWideChar(
		CP_ACP,
		MB_PRECOMPOSED,
		str.c_str(),
		-1,
		NULL,
		0
		);

	if (nSize > 0)
	{
		// ∑÷≈‰ø’º‰£®try£©
		WTemp = (wchar_t *) malloc (nSize * sizeof(wchar_t));

		if(NULL != WTemp)
		{
			if (!MultiByteToWideChar(
				CP_ACP,
				MB_PRECOMPOSED,
				str.c_str(),
				-1,
				WTemp,
				nSize
				))
			{
				free(WTemp);
				*WTemp = NULL;
			}
		}
	}

//	return WTemp;
	std::wstring WStringTemp(WTemp);

	free(WTemp);

	return WStringTemp;
}

#endif

#include "SuperMapUtil.h"


// 宽字符边转ASCII
std::string SuperMapUtil::WcharToString(const wchar_t* wstr)
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

std::wstring SuperMapUtil::StringToWString(const std::string &str)
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
		// 分配空间（try）
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


// 转换成小写字符
std::string SuperMapUtil::MakeLower(const std::string& str)
{
	std::string s(str);

	std::string::iterator iter = s.begin();
	while(iter != s.end())
	{
		*iter = tolower(*iter);
		iter++;
	}

	return s;
}

// 转换成大写字符
std::string SuperMapUtil::MakeUpper(const std::string& str)
{
	std::string s(str);

	std::string::iterator iter = s.begin();
	while(iter != s.end())
	{
		*iter = toupper(*iter);
		iter++;
	}

	return s;
}

// 转换正数
int SuperMapUtil::ToInt(const std::string& str)
{
	int i = 0;
	std::string os = str;
	if (!os.empty())
	{
		std::istringstream is(os);
		is >> i;
	}
	return i;
}

// 转换成Double
double SuperMapUtil::ToDouble(const std::string& str)
{
	double d = 0.0;

	if(!str.empty())
	{
		d = atof(str.c_str());
	}
	return d;
}

// 转换成bool
bool SuperMapUtil::ToBool(const std::string& str)
{
	// Check for true or false, yes or no, y or n, and 1 or 0...
	std::string s = MakeLower(str);
	if (s.empty())
	{
		return false;
	}

	if ( (s == "true") ||
		(s == "yes")  ||
		(s == "y")    ||
		(s == "1") )
	{
		return true;
	}

	else if ( (s == "false") ||
		(s == "no")    ||
		(s == "n")     ||
		(s == "0") )
	{
		return false;

	}
	else if (ToInt(str))
		return true;

	return false;
}


// 返回文件扩展名
std::string  SuperMapUtil::GetFileExt(const std::string &strFileName)
{
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath( strFileName.c_str(), drive, dir, fname, ext ); // C4996

	return std::string(ext);
}

// 返回文件名
std::string  SuperMapUtil::GetFileName(const std::string &strPathName)
{
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath( strPathName.c_str(), drive, dir, fname, ext ); // C4996

	return std::string(fname);
}

std::vector<std::string> SuperMapUtil::SplitString(const std::string & str, const std::string& SeparatorList)
{
	std::vector<std::string> result;
	if(str.empty()) return result;

	std::string CopyString = str;
	char* s = strtok(const_cast<char*>(CopyString.c_str()), SeparatorList.c_str());
	for(std::string::size_type i = 0; i < SeparatorList.size(); ++ i)
	{
		if((*(str.begin())) == SeparatorList.c_str()[i])
		{
			result.push_back("");
		}
	}

	while(s)
	{
		result.push_back(std::string(s));
		s = strtok(NULL, SeparatorList.c_str());
	}

	for(std::string::size_type i = 0; i < SeparatorList.size(); ++ i)
	{
		if((*(str.end()-1)) == SeparatorList.c_str()[i])
		{
			result.push_back("");
		}
	}

	return result;
}

std::string SuperMapUtil::JoinString(const std::vector<std::string>& StringList, const std::string& Separator)
{
	std::string str = "";

	if(StringList.size())
	{
		for(long i = 0; i < ((long)StringList.size() - 1); ++i)
		{
			str += StringList[i];
			str += Separator;
		}
		str += StringList[StringList.size() - 1];
	}

	return str;
}
/*! 
	\file	SMCStringHelper.h
    \brief	字符串操作类
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-28 初始化版本
*/

#include "SMCStringHelper.h"

std::vector<_tstring> SMCStringHelper::Explode(const _tstring &strSorce, const _tstring &delimeter)
{
	_tstring exp_str = strSorce;
	std::vector<_tstring> result;
	TCHAR * tokenPtr;
	tokenPtr = _tcstok((TCHAR *)exp_str.c_str(), delimeter.c_str());
	while(tokenPtr != NULL)
	{
		result.push_back(tokenPtr);
		tokenPtr = _tcstok(NULL, delimeter.c_str());
	}
	return result;
}

void SMCStringHelper::ProKeyAndVal(const std::vector<_tstring> &strSource, std::map<_tstring, _tstring> &connInfo)
{
	std::vector<_tstring>::const_iterator nPos = strSource.begin();
    while(nPos != strSource.end())
    {
		_tstring strItem = *nPos;
		_tstring::size_type nIdx = strItem.find('=');
		if(nIdx == _tstring::npos)//没有找到=,直接跳过
		{
			++nPos;
			continue;
		}
		_tstring strKey = strItem.substr(0,nIdx);
		strKey = MakeStrLower(strKey);
		_tstring strVal = strItem.substr(nIdx+1);
		strVal = MakeStrLower(strVal);
		connInfo.insert(std::make_pair(strKey, strVal));
		++nPos;
    }
}

_tstring SMCStringHelper::MakeStrLower(const _tstring &strSource)
{
   _tstring strDest(strSource);

   _tstring::iterator iter = strDest.begin();
   while(iter != strDest.end())
   {
      *iter = tolower(*iter);
      ++iter;
   }
   return strDest;
}
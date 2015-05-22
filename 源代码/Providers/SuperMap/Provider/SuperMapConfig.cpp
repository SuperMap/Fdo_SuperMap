/** \file	 SuperMapConfig.cpp
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-25
*/

#include <SuperMap.h>

extern wchar_t home_path[];

bool SuperMapConfig::m_IsReadSmField = false;

SuperMapConfig::SuperMapConfig()
{
}

SuperMapConfig::~SuperMapConfig()
{
}

void SuperMapConfig::Init()
{
	SuperMapIniFile iniFile;
	std::string strpath = SuperMapUtil::WcharToString(home_path);
	strpath +="\\";
	strpath +="ProviderConfig.ini";
	
	iniFile.Load(strpath.c_str());

	//读取配置文件的值
	iniFile.GetValue(COMMON_SECTION, SMFIELD_KEY, m_IsReadSmField, 0);

	iniFile.ClearAll();
}
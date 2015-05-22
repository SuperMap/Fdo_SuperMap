/** \file	 SuperMapConfig.h
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-25
*/

#ifndef _SUPERMAP_CONFIG_H_
#define _SUPERMAP_CONFIG_H_

#ifdef _WIN32
#pragma once
#endif // _WIN32

#define CONFIG_FILE     "ProviderConfig.ini"
#define COMMON_SECTION  "CommonConfig" 
#define SMFIELD_KEY     "ReadSuperMapSystemField"

class SuperMapConfig
{
public:
	SuperMapConfig();
	~SuperMapConfig();

	//从配置文件初始化成员变量
	static void Init();
public:
	static bool m_IsReadSmField;  //是否读取SuperMap系统字段

};

#endif

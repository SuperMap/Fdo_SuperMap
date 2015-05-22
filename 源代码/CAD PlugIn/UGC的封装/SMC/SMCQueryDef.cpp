/*! 
	\file	SMCQueryDef.cpp
    \brief	查询定义类
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-25 初始化版本
*/

#include "SMCQueryDef.h"

SMCQueryDef::SMCQueryDef()
{
	m_nType = General;
	m_nOptions = Both;
	m_nMode = GeneralQuery;
}

SMCQueryDef::~SMCQueryDef()
{
}
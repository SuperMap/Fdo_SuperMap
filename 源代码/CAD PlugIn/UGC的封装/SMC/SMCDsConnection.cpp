/*! 
	\file	SMCDsConnection.cpp
    \brief	数据源连接信息类，当前版本主要用来打开或者创建数据源
	\author	马 俊
	\attention	在打开或者创建数据源时，必须先对连接信息进行配置
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-20 初始化版本
*/

//#include "UGC.h"
#include "SMCDsConnection.h"

SMCDsConnection::SMCDsConnection()
{
	m_nEngineType	= SDBPlus; 
	m_bReadOnly  	= false;
	m_bTransacted	= false;
	m_bExclusive 	= false;
	m_bEncrypt   	= true;
	m_strDatabase	= _T("");
	m_strDriver  	= _T("");
	m_strServer  	= _T("");
	m_strUser    	= _T("");
	m_strPassword	= _T("");
	m_strAlias   	= _T("");
	m_bAutoConnect  = true;
	m_nConnMaxNum   = 0;
	m_nConnMinNum   = 0;
	m_nConnIncNum   = 0;

}

SMCDsConnection::~SMCDsConnection()
{
	
}
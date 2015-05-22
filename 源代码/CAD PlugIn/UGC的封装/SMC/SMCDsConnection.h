/*! 
	\file	SMCDsConncetion.h
    \brief	数据源连接信息类，当前版本主要用来打开或者创建数据源
	\author	马 俊
	\attention	在打开或者创建数据源时，必须先对连接信息进行配置	
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-20 初始化版本
*/

#ifndef SMCDSCONNECTION_H
#define SMCDSCONNECTION_H

#include "SMC.h"



class SMC_API SMCDsConnection
{
public:
	//! \brief		数据引擎类型
	enum SMEngineType
	{	
		SDB				=0,		//SdbPlus引擎
		//MDB			=1,
		//SQLServer		=2,		//SDX for SQL Server
		Oracle			=3,
		SDE				=4,		//SDX for SDE
		ImagePlugins	=5,		//用户可以自定义的显示image格式的插件
		//SIT			=6,		//SIT格式影像文件引擎
		MicroStation	=8,		
		AutoCAD			=9,		//AutoCAD File, *.DXF , *.DWG
		OracleSpatial	=10,	//11,	//Oracle Spatial类型引擎，Added by lsj at 2001年6月7日 08:32:05
		OraclePlus		=12,	//SDX Plus for Oracle
		SDBPlus			=14,		
		SybasePlus      =15,	//6,    //第三代SyBase引擎
		SQLPlus			=16,	//3,	//第三代Sql
		DMPlus			=17,	//7,    //第三代DM
		DB2             =18,
		Kingbase		=19,	//Kingbase金仓数据库
		Memory			=20,    //内存数据源
		ROF             =21,    //Ready only file 只读文件引擎
		UDB				=30,    //跨平台文件引擎 add by xll
		WEB				=31,	//跨平台网络数据引擎 add by duxiaomin
		ExtFile			=101	//外部文件只读引擎
	};

public:		
	//! \brief		默认构造函数
	SMCDsConnection();
	~SMCDsConnection();

public:
	//! \brief		引擎类型
	SMEngineType    m_nEngineType;

	//! \brief		是否只读打开
	bool			m_bReadOnly;

	//! \brief		是否以事务方式打开
	bool			m_bTransacted;

	//! \brief		是否独占打开
	bool			m_bExclusive;

	//! \brief		数据源是否需要密码打开
	bool			m_bEncrypt;

	//!\brief		 数据库名
	_tstring		m_strDatabase;

	//! \brief		ODBC Driver
	_tstring		m_strDriver;	

	//! \brief		服务名
	_tstring		m_strServer;

	//! \brief		用户名
	_tstring		m_strUser;

	//! \brief		密码
	_tstring		m_strPassword;

	//! \brief		别名
	_tstring		m_strAlias;

	//! \brief		打开工作空间时是否自动打开数据源
	bool			m_bAutoConnect;

	//! \brief		数据库连接池的最大连接数
	int				m_nConnMaxNum;

	//! \brief		数据库连接池的最小连接数
	int			    m_nConnMinNum;

	//! \brief		数据库连接池的增长连接数
	int				m_nConnIncNum;
};

#endif
/*! \file	 UGDsConnection.h
*  \brief	 数据源连接信息类定义
*  \author	 ugc team
*  \attention 
*  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version $Id: UGDsConnection.h,v 1.24 2007/10/25 01:00:57 yanmb Exp $
*/

#ifndef UGDSCONNECTION_H
#define UGDSCONNECTION_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"

namespace UGC {
	
	//! 数据引擎类型
	enum UGEngineType
	{	
			NOEngine		=-1,
			SDB				=0,		//SdbPlus引擎
			//MDB				=1,
			//SQLServer		=2,		//SDX for SQL Server
			Oracle			=3,
			SDE				=4,		//SDX for SDE
			ImagePlugins	=5,		//用户可以自定义的显示image格式的插件
			//SIT				=6,		//SIT格式影像文件引擎
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
			WEB				=23,	//跨平台网络数据引擎 add by duxiaomin
			UDB				=30,    //跨平台文件引擎 add by xll
			ExtFile			=101		//外部文件只读引擎
	};
	
	//! 数据源连接信息类
	class ENGINE_API UGDsConnection  
	{	
	public:		
		//! 默认构造函数
		UGDsConnection();
		//! 构造函数
		UGDsConnection(
			UGEngineType nEngineType,
			const UGString& strServer,
			const UGString& strDriver,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGbool bEncrypt = TRUE,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE,		
			UGbool bExclusive = FALSE,		
			UGbool bAutoConnect = TRUE);
		
		//!构造函数:SqlServer等ODBC类 DriverConnect
		UGDsConnection(
			const UGString& strServer,
			const UGString& strDriverName,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = SQLPlus,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE);
		
		
		//! 构造函数: Oracle;SQL Server本地数据源连接 
		UGDsConnection(const UGString& strDNSOrServerName,
			const UGString& strDatabase,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = OraclePlus,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE);
		
		//!构造函数:本地文件型引擎 UDB,SDBPlus,MEMORY 如果strFilePath为空
		UGDsConnection(const UGString& strFilePath,
			const UGString& strUser,
			const UGString& strPassword,
			const UGString& strAlias,
			UGEngineType nEngineType = UDB,
			UGbool bTransacted = FALSE,
			UGbool bReadonly = FALSE,
			UGbool bEncrypt = TRUE,
			UGbool bExclusive = FALSE);
		
		//! 析构函数
		~UGDsConnection();
		
		//! 将数据源连接信息存为XML格式
		//! \param nVersion 版本号
		//! \return 导出的XML格式字符串
		UGString ToXML(UGint nVersion,UGString strRefPath = "") const;
		
		//! 从XML中解析数据源连接信息
		//! \param strXML XML格式字符串
		//! \param nVersion 版本号	
		UGbool FromXML(const UGString& strXML,UGint nVersion,UGString strRefPath = "");
		
		void operator =(const UGDsConnection &conn);
		
		UGbool operator ==(const UGDsConnection &conn);
		
	public:
		//! 引擎类型
		UGEngineType	m_nEngineType;
		
		//! 是否只读打开
		UGbool			m_bReadOnly;
		
		//! 是否以事务方式打开
		UGbool			m_bTransacted;
		
		//! 是否独占打开
		UGbool			m_bExclusive;
		
		//! 数据源是否需要密码打开
		UGbool			m_bEncrypt;
		
		//! 数据库名
		UGString		m_strDatabase;
		
		//! ODBC Driver
		UGString		m_strDriver;	
		
		//! 服务名
		UGString		m_strServer;
		
		//! 用户名
		UGString		m_strUser;
		
		//! 密码
		UGString		m_strPassword;
		
		//! 别名
		UGString		m_strAlias;
		
		//! 打开工作空间时是否自动打开数据源
		UGbool			m_bAutoConnect;
		
		//! brief 数据库连接池的最大连接数
		UGint			m_nConnMaxNum;
		
		//! brief 数据库连接池的最小连接数
		UGint			m_nConnMinNum;
		
		//! brief 数据库连接池的增长连接数
		UGint			m_nConnIncNum;

		//! brief 数据库是否扩展打开	
		UGbool			m_bExpandOpen;
};

}

#endif

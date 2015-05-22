
/** \file	 SuperMapConnectionPool.h
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/


#ifndef __SUPERMAPCONNECTIONPOOL_H__
#define __SUPERMAPCONNECTIONPOOL_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "UGC.h"

// 转换NULL为""
#define		_(X)	(X)?(X):("")

class SuperMapConnection;

/*! \class SuperMapConnectionPool
*	\brief 缓存连接信息
*/
class SuperMapConnectionPool
{
public:
	/*! \fn static SuperMapConnectionPool* GetInstance()
	* \brief 返回实例
	*/
	static SuperMapConnectionPool* GetInstance();
	virtual ~SuperMapConnectionPool();
	virtual void Dispose();

public:

	/*! \class ConnectionInfo
	*	\brief 连接信息
	*/
	class ConnectionInfo
	{
	public:
		ConnectionInfo();
		virtual ~ConnectionInfo();
		// 初始化
		void Cleanup(bool bForce = false);
	public:
		//! 数据源
		UGC::UGDataSource* pDataSource;
		//! 数据引擎类型
		UGC::UGEngineType nEngineType;
		//! 使用记数
		int nUseCount;
		bool bAutoDelete;
		std::string strUserName;
		std::string strPassword;
		std::string strServer;
		//! 文件全名或服务器中数据库
		std::string strDatabase;
		// 是否以影像方式打开
		bool bIsImage;
	};

	/*! \fn std::string GetConnectionInfo(SuperMapConnection* conn)
	* \brief 连接数据库，返回SESSION
	*/
	std::string GetConnectionInfo(SuperMapConnection* conn);

	/*! \fn UGC::UGDataSource* GetDataSource(const std::string &strSession)
	* \brief 获取数据源
	*/
	UGC::UGDataSource* GetDataSource(const std::string &strSession);

	// bForceClose 为真，强制关闭数据源，不管是否还在使用
	/*! \fn void CloseDataSource(std::string &strSession, bool bForceClose = false)
	* \brief 关闭数据源  bForceClose 为真，强制关闭数据源，不管是否还在使用
	*/
	void CloseDataSource(const std::string &strSession, bool bForceClose = false);

	/*! \fn bool IsDatabase(const std::string &strSession)
	* \brief 是否支持高级操作（文件和数据库的判断）
	*/
	bool IsDatabase(const std::string &strSession);

	/*! \fn bool IsImage(const std::string &strSession)
	* \brief 是否是影像
	*/
	bool IsImage(const std::string &strSession);

private:
	// 转换连接类型
	int GetEngineType(const std::string &strType);
	// 判断是否已经存在
	SuperMapConnectionPool::ConnectionInfo*  FindConnectionInfo(const std::string &session);
	// 生成SESSION
	std::string MakeSession(const ConnectionInfo* conninfo);
	// 设置使用和废弃
	void Disuse(const std::string &strSession);
	void Use(const std::string &strSession);
	// 根据SESSION删除一个连接
	void DeleteConnInfo(const std::string &strSession);

	// 测试函数
	void ShowDataSourceInfo(const std::string &session);

private:
	typedef std::map<std::string, ConnectionInfo*> ConnectionInfoMap;
	SuperMapConnectionPool();
	ConnectionInfoMap m_ConnInfoMap;
	static SuperMapConnectionPool* m_Instance;
	
};

#endif
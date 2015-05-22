
/** \file	 SuperMapConnectionPool.cpp
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#include <SuperMap.h>

SuperMapConnectionPool* SuperMapConnectionPool::m_Instance = NULL;


SuperMapConnectionPool::SuperMapConnectionPool()
{
}

SuperMapConnectionPool::~SuperMapConnectionPool()
{
	for (ConnectionInfoMap::iterator iter = m_ConnInfoMap.begin (),
		end = m_ConnInfoMap.end ();
		iter != end; ++iter)
	{
		ConnectionInfo* conninfo = (*iter).second;
		delete conninfo;
	}
}

SuperMapConnectionPool* SuperMapConnectionPool::GetInstance()
{
	//TODO: Synchronize this for threads?
	if(NULL == m_Instance)
	{
		m_Instance = new SuperMapConnectionPool(); 
	}

	return m_Instance;
}

void SuperMapConnectionPool::Dispose()
{
	delete SuperMapConnectionPool::m_Instance;
	SuperMapConnectionPool::m_Instance = 0;
}


SuperMapConnectionPool::ConnectionInfo::ConnectionInfo()
{
	pDataSource = NULL;
	nEngineType = (UGC::UGEngineType) 0;
	nUseCount = 0;
	bAutoDelete = false;
	strUserName = "";
	strPassword = "";
	strServer = "";
	strDatabase = "";
	bIsImage = false;
}   

SuperMapConnectionPool::ConnectionInfo::~ConnectionInfo()
{
	Cleanup(true);
}

void SuperMapConnectionPool::ConnectionInfo::Cleanup(bool bForce)
{

	if(!bForce)
	{
		if(nUseCount != 0)
			return ;
	}

	if (NULL != pDataSource)
	{
		if (pDataSource->IsConnected() || pDataSource->IsOpen())
		{
			pDataSource->Close();
		}
		// 在此释放数据源
		delete pDataSource;
	}

	pDataSource = NULL;
	nEngineType = (UGC::UGEngineType) 0;
	nUseCount = 0;
	bAutoDelete = false;
	strUserName = "";
	strPassword = "";
	strServer = "";
	strDatabase = "";
	bIsImage = false;
}


std::string SuperMapConnectionPool::GetConnectionInfo(SuperMapConnection* conn)
{
	if (NULL == conn)
	{
		return "";
	}

	FdoPtr<FdoIConnectionInfo> info = conn->GetConnectionInfo ();
	FdoPtr<FdoCommonConnPropDictionary> dictionary = dynamic_cast<FdoCommonConnPropDictionary*>(info->GetConnectionProperties ());
	
	FdoCommonConnStringParser parser (NULL, conn->GetConnectionString ());
	if (!parser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'",
			conn->GetConnectionString ()));

	}
	if (parser.HasInvalidProperties(dictionary))
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_PROPERTY_NAME,
			"Invalid connection property name '%1$ls'", 
			parser.GetFirstInvalidPropertyName (dictionary)));
	}

	FdoCommonConnStringParser againparser (NULL, dictionary->GetProperty(CONNECTIONPROPERTY_DATASOURCE));
	if (!againparser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			conn->GetConnectionString ()));
	}
																													
	/**************检验类型***************/
	if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_CONN_TYPE) )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_TYPE,
			"Invalid connection type"));
	}

	std::string strType = SuperMapUtil::MakeLower(againparser.GetPropertyValue(CONNECTIONPROPERTY_CONN_TYPE));
	
	int nType = GetEngineType(strType);
	if (-1 == nType )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			conn->GetConnectionString ()));
	}

	/**************检验数据库***************/
	if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE) )
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_DATABASE, 
			"Invalid connection datebase"));
	}

	/**************检验细节***************/
	UGC::UGEngineType nEngType = (UGC::UGEngineType)nType;
	switch(nEngType)
	{
	case UGC::SDBPlus:
		break;
	case UGC::OraclePlus:
	case UGC::SQLPlus:
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_SERVER) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_SERVER,
				"Invalid connection datebase server"));
		}
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_USER) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_USER, 
				"Invalid connection datebase user"));
		}
		if ( NULL == againparser.GetPropertyValue(CONNECTIONPROPERTY_PASSWORD) )
		{
			throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_NOT_PASSWORD, 
				"Invalid connection datebase password"));
		}
		break;
	case UGC::AutoCAD:
		break;
	}

	/**************建立连接信息***************/
	ConnectionInfo *newConnInfo = new ConnectionInfo();
	newConnInfo->nEngineType = nEngType;
	newConnInfo->strDatabase = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE));
	newConnInfo->strServer = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_SERVER));
	newConnInfo->strUserName = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_USER));
	newConnInfo->strPassword = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_PASSWORD));
	//if( UGC::ImagePlugins == nEngType)
	//	newConnInfo->bIsImage = true;
	//else
	newConnInfo->bIsImage = SuperMapUtil::ToBool(_(againparser.GetPropertyValue(CONNECTIONPROPERTY_IMAGE))); // added by zhouxu

	newConnInfo->nUseCount = 1;	// 

	/**************判断是否已经存在***************/
	std::string session = this->MakeSession(newConnInfo);
	::OutputDebugStringA(session.c_str());
	if(NULL != FindConnectionInfo(session))
	{
		delete newConnInfo;
		// 又一个再使用
		Use(session);
		ShowDataSourceInfo(session);
		return session;
	}
	/**************打开数据源***************/
	bool IsSucceed = false;
	newConnInfo->pDataSource = UGC::UGDataSourceManager::CreateDataSource(newConnInfo->nEngineType);
	if(newConnInfo->pDataSource != NULL)
	{
		UGC::UGDsConnection &conn = newConnInfo->pDataSource->GetConnectionInfo();
		conn.m_nEngineType = newConnInfo->nEngineType;


		if(newConnInfo->nEngineType != -1 )//UGC::SDBPlus)   //为了方便与deskpro联调，暂时注释掉 by zhouxu 2008-6-2
		{
			// 设置文件类型的自动删除连接信息
			// 如果ORA and SQL不设置自动关闭数据库操作的话，
			// 用户更新不到最新的数据库信息
			newConnInfo->bAutoDelete = true;
		}
		
		//added by zhouxu 2008-1-17
		if(newConnInfo->bIsImage)
			conn.m_bReadOnly = true;  // 影像模式以只读方式打开

		// NOTE:: 文件和数据库不一样之处，如添加文件类型的，还要再修改
		if(newConnInfo->nEngineType == UGC::SDBPlus
			|| newConnInfo->nEngineType == UGC::ImagePlugins)
		{
			conn.m_strServer = UGC::UGString(newConnInfo->strDatabase);
			conn.m_strDatabase = "";

		}
		else
		{
			conn.m_strServer = UGC::UGString(newConnInfo->strServer);
			conn.m_strDatabase = UGC::UGString(newConnInfo->strDatabase);
		}

		conn.m_strUser = UGC::UGString(newConnInfo->strUserName);
		conn.m_strPassword = UGC::UGString(newConnInfo->strPassword);
		conn.m_strAlias = UGC::UGString(session.c_str());//added by zhouxu 2008-2-21

		if ( newConnInfo->nEngineType == UGC::SQLPlus )
		{
			conn.m_strDriver = "SQL Server";
		}

		IsSucceed = newConnInfo->pDataSource->Open()?true:false;

		if(!IsSucceed)
		{
			delete newConnInfo->pDataSource;
			newConnInfo->pDataSource = NULL;
		}
	}

	if(!IsSucceed)
	{
		delete newConnInfo;
		throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_FAIL, "connection datebase fail"));
	}

	/**************加入连接池***************/
	m_ConnInfoMap[session] = newConnInfo;
	return session;
}

int SuperMapConnectionPool::GetEngineType(const std::string &strType)
{
	if(strType == "sdb")
		return (int)UGC::SDBPlus;
	else if(strType == "ora")
		return (int)UGC::OraclePlus;
	else if (strType == "sql")
		return (int)UGC::SQLPlus;
	else if (strType == "sit")
		return (int)UGC::ImagePlugins;

	return -1;
}

// 获取数据源
UGC::UGDataSource* SuperMapConnectionPool::GetDataSource(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		return conninfo->pDataSource;
	}
	return NULL;
}

// 关闭数据源
void SuperMapConnectionPool::CloseDataSource(const std::string &strSession, bool bForceClose)
{
	// 不用了
	Disuse(strSession);

	if (bForceClose)
	{
		DeleteConnInfo(strSession);
	}
}

SuperMapConnectionPool::ConnectionInfo*  SuperMapConnectionPool::FindConnectionInfo(const std::string &session)
{
	ConnectionInfoMap::iterator iter = m_ConnInfoMap.find (session);
	if (iter == m_ConnInfoMap.end ())
	{
		return NULL;
	}

	return (*iter).second;
}

// 生成SESSION
std::string SuperMapConnectionPool::MakeSession(const ConnectionInfo* conninfo)
{
	if (NULL == conninfo)
	{
		return "";
	}

	char session[1024];

	if (conninfo->nEngineType == UGC::SDBPlus || conninfo->nEngineType == UGC::ImagePlugins)
	// 文件SESSION
	{
		// 类型+路径+文件名+扩展名
		std::vector<std::string> dirarr = SuperMapUtil::SplitString(SuperMapUtil::MakeLower(conninfo->strDatabase),
			"\\/.: ");
		sprintf(session, "SM%d%d%s", 
			conninfo->nEngineType,
			(conninfo->bIsImage)?1:0,
			SuperMapUtil::JoinString(dirarr, "").c_str());
	}
	else 
	// 空间数据SESSION
	{
		// 类型+数据服务器名+数据用户名+数据库名
		std::vector<std::string> strser = SuperMapUtil::SplitString(SuperMapUtil::MakeLower(conninfo->strServer), 
			".\\/ ");
		sprintf(session, "SM%d%d%s%s%s", 
				conninfo->nEngineType,
				(conninfo->bIsImage)?1:0,
				SuperMapUtil::JoinString(strser, "").c_str() , 
				SuperMapUtil::MakeLower(conninfo->strUserName).c_str(), 
				SuperMapUtil::MakeLower(conninfo->strDatabase).c_str());
	}

	return std::string(session);
}

void SuperMapConnectionPool::Disuse(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		conninfo->nUseCount --;

		// 自动删除
		if(conninfo->bAutoDelete)
		{
			DeleteConnInfo(strSession);
		}
	}
}

void SuperMapConnectionPool::Use(const std::string &strSession)
{
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		conninfo->nUseCount ++;

		if (!conninfo->pDataSource->IsOpen())
		{
			if(!conninfo->pDataSource->Open())
			{
				throw FdoException::Create (NlsMsgGet(SUPERMAP_CONNECTION_FAIL, 
					"reconnection datebase fail"));
			}
		}
	}
}

void SuperMapConnectionPool::DeleteConnInfo(const std::string &strSession)
{
	ConnectionInfoMap::iterator iter = m_ConnInfoMap.find(strSession);
	if (iter != m_ConnInfoMap.end ())
	{
		ConnectionInfo* conninfo = (*iter).second;
		delete conninfo;

		m_ConnInfoMap.erase(iter);
	}
}

bool SuperMapConnectionPool::IsDatabase(const std::string &strSession)
{
	bool isdatabase = false;
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		switch(conninfo->nEngineType)
		{
		case UGC::OracleSpatial:
		case UGC::OraclePlus:
		case UGC::SybasePlus:
		case UGC::SQLPlus:
		case UGC::Kingbase:
		case UGC::DB2:
			isdatabase = true;
			break;
		}
	}
	return isdatabase;
}

bool SuperMapConnectionPool::IsImage(const std::string &strSession)
{
	bool isdatabase = false;
	ConnectionInfo* conninfo = FindConnectionInfo(strSession);
	if(conninfo)
	{
		return conninfo->bIsImage;
	}
	return false;
}

// 测试函数
void SuperMapConnectionPool::ShowDataSourceInfo(const std::string &session)
{
	ConnectionInfo* conninfo = FindConnectionInfo(session);
	if(conninfo)
	{

		TRACE(_T("开始 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> "));

		TRACE(_T("数据源[%ls]"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetAlias().Cstr()).c_str());

		TRACE(_T("数据源路径： %ls"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetName().Cstr()).c_str());
		TRACE(_T("  引擎类型： %ls"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetEngineName().Cstr()).c_str());
		TRACE(_T("数据源描述： %ls"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetDescription().Cstr()).c_str());
		TRACE(_T("是否打开： %ls"),  conninfo->pDataSource->IsOpen()?_T("是"):_T("否"));
		TRACE(_T("是否以只读方式打开： %ls"),  conninfo->pDataSource->IsReadOnly()?_T("是"):_T("否"));
		TRACE(_T("是否支持事务： %ls"),  conninfo->pDataSource->IsTransStarted()?_T("是"):_T("否"));
		TRACE(_T("是否改动： %ls"),  conninfo->pDataSource->IsModified()?_T("是"):_T("否"));
		
		TRACE(_T("数据集共：%d "), conninfo->pDataSource->GetDatasetCount());

		for(int j = 0; j < conninfo->pDataSource->GetDatasetCount(); j++)
		{
			TRACE(_T("| -- %ls   \t[%d]"),  SuperMapUtil::StringToWString(conninfo->pDataSource->GetDataset(j)->GetName().Cstr()).c_str(),
				conninfo->pDataSource->GetDataset(j)->GetType());

			TRACE(_T("|        是否打开： %ls"), conninfo->pDataSource->GetDataset(j)->IsOpen()?_T("是"):_T("否"));
		}	

		TRACE(_T("坐标系名称： %s"), SuperMapUtil::StringToWString(conninfo->pDataSource->GetPrjCoordSys().GetName().Cstr()).c_str());

		TRACE(_T("结束 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< "));

	}
}
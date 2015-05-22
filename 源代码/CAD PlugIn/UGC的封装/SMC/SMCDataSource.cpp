/*! 
	\file	SMCDataSource.cpp
    \brief	数据源管理类，当前版本主要用来管理数据集集合
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 初始化版本
*/

#include "UGC.h"
#include "SMCDataSource.h"
#include "SMCDataset.h"

#include "SMCDsOperate.h"
#include "SMCStringHelper.h"


SMCDataSource::SMCDataSource()
{
	m_pDataSource = NULL;
}

SMCDataSource::~SMCDataSource()
{
	m_pDataSource = NULL;
}

_tstring SMCDataSource::GetSchema() const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return UNICODE_STRING(pDatasource->GetSchema().Cstr());
	}
	else
	{
		return _T("");
	}
}

bool SMCDataSource::IsOpen() const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return pDatasource->IsOpen();
	}
	else
	{
		return false;
	}
}

_tstring SMCDataSource::GetName() const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return UNICODE_STRING(pDatasource->GetName().Cstr());
	}
	else
	{
		return _T("");
	}
}

_tstring SMCDataSource::GetEngineName() const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return UNICODE_STRING(pDatasource->GetEngineName().Cstr());
	}
	else
	{
		return _T("");
	}
}

_tstring SMCDataSource::GetUnoccupiedDatasetName(const _tstring& strDatasetName)
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		_tstring strDatasetname = UNICODE_STRING((pDatasource->GetUnoccupiedDatasetName(ASCII_STRING(strDatasetName).c_str())).Cstr());
		return strDatasetname;
	}
	else
	{
		return _T("");
	}
}

bool SMCDataSource::IsModified()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return pDatasource->IsModified();
	}
	else
	{
		return false;
	}
}

void SMCDataSource::SetModifiedFlag(bool bModified)
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return pDatasource->SetModifiedFlag(bModified);
	}
	else
	{
		return;
	}
}

int SMCDataSource::GetDatasetCount() const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		return pDatasource->GetDatasetCount();
	}
	else
	{
		return -1;
	}
}

void SMCDataSource::SetConnection(const SMCDsConnection& dsconn)
{

	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource =(UGC::UGDataSource*)m_pDataSource;
		UGC::UGDsConnection &conn		  =	pDatasource->GetConnectionInfo();

		conn.m_nEngineType  = (UGC::UGEngineType)conn.m_nEngineType;
		conn.m_bReadOnly    =	dsconn.m_bReadOnly;
		conn.m_bTransacted  =	dsconn.m_bTransacted;
		conn.m_bExclusive   =	dsconn.m_bExclusive;
		conn.m_bEncrypt     =	dsconn.m_bEncrypt;
		conn.m_strDatabase  =	ASCII_STRING(dsconn.m_strDatabase).c_str();
		conn.m_strDriver    =	ASCII_STRING(dsconn.m_strDriver).c_str();	
		conn.m_strServer    =	ASCII_STRING(dsconn.m_strServer).c_str();
		conn.m_strUser      =	ASCII_STRING(dsconn.m_strUser).c_str();
		conn.m_strPassword  =	ASCII_STRING(dsconn.m_strPassword).c_str();
		conn.m_strAlias     =	ASCII_STRING(dsconn.m_strAlias).c_str();
		conn.m_bAutoConnect =	dsconn.m_bAutoConnect;
//		conn.m_nConnMaxNum  =	dsconn.m_nConnMaxNum;
//		conn.m_nConnMinNum  =	dsconn.m_nConnMinNum;
//		conn.m_nConnIncNum  =	dsconn.m_nConnIncNum;
	}
	else
	{
		return;
	}
}

bool SMCDataSource::CreateDataSource(SMCDsConnection::SMEngineType nEngineType)
{
	m_pDataSource = UGC::UGDataSourceManager::CreateDataSource((UGC::UGEngineType)nEngineType);
	if(m_pDataSource != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SMCDataSource::GetDataset(int nIndex, SMCDataset *&pDdataset) const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		(UGC::UGDataset*&)(pDdataset->m_pDataset) = pDatasource->GetDataset(nIndex);
		if(pDdataset->m_pDataset != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool SMCDataSource::GetDataset(const _tstring& strDatasetName, SMCDataset *&pDdataset) const
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource* pDatasource = (UGC::UGDataSource*)m_pDataSource;
		UGC::UGString strDtsetName = ASCII_STRING(strDatasetName).c_str();
		(UGC::UGDataset*&)(pDdataset->m_pDataset) = pDatasource->GetDataset(strDtsetName);
		if(pDdataset->m_pDataset != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool SMCDataSource::Create()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->Create();
	}
	else
	{
		return false;
	}
}

bool SMCDataSource::Open()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->Open();
	}
	else
	{
		return false;
	}	
}

void SMCDataSource::Close()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->Close();
	}
	else
	{
		return;
	}	
}

bool SMCDataSource::SaveInfo()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->SaveInfo();
	}
	else
	{
		return false;
	}	
}

bool SMCDataSource::DeleteDataset(const _tstring& strName)
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		UGC::UGString strDsetName = ASCII_STRING(strName).c_str();
		return pDatasource->DeleteDataset(strDsetName);
	}
	else
	{
		return false;
	}	
}

bool SMCDataSource::IsConnected()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->IsConnected();
	}
	else
	{
		return false;
	}	
}


bool SMCDataSource::ChangePassword(const _tstring& strNewPassword)
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		UGC::UGString strNewPwd = UGC::UGString(ASCII_STRING(strNewPassword).c_str());
		return pDatasource->ChangePassword(strNewPwd);
	}
	else
	{
		return false;
	}	
}

bool SMCDataSource::Connect()
{
	if(m_pDataSource != NULL)
	{
		UGC::UGDataSource *pDatasource = (UGC::UGDataSource *)m_pDataSource;
		return pDatasource->Connect();
	}
	else
	{
		return false;
	}	
}

bool SMCDataSource::OpenDataSource(SMCDataSource &sdbDs, _tstring strConnection)
{
	std::vector<_tstring> strName = SMCStringHelper::Explode(strConnection, _T(";"));
	std::map<_tstring, _tstring> connInfo;
	SMCStringHelper::ProKeyAndVal(strName, connInfo);

	SMCDsConnection::SMEngineType nEngine;

	_tstring strEngineName = connInfo[SMC_CONNECTION_TYPE];
	nEngine = EngNameToEngType(strEngineName);

	//创建数据源
	bool bCreDs = sdbDs.CreateDataSource(nEngine);
	if(!bCreDs)
	{
		return false;
	}

	UGC::UGDsConnection &conn = ((UGC::UGDataSource *&)(sdbDs.m_pDataSource))->GetConnectionInfo();
	//类别判断
	if(strEngineName == _T("sdb"))
	{
		conn.m_strServer	  = ASCII_STRING(connInfo[SMC_CONNECTION_FILE]).c_str();
		conn.m_strUser		  = ASCII_STRING(connInfo[SMC_CONNECTION_USER]).c_str();
		conn.m_strPassword    = ASCII_STRING(connInfo[SMC_CONNECTION_PWD]).c_str();
	}
	else if(strEngineName == _T("ora") || strEngineName == _T("sql server"))
	{
		conn.m_strDatabase    = ASCII_STRING(connInfo[SMC_CONNECTION_SERVER]).c_str();
		conn.m_strDatabase    = ASCII_STRING(connInfo[SMC_CONNECTION_DATABASE]).c_str();
		conn.m_strUser		  = ASCII_STRING(connInfo[SMC_CONNECTION_USER]).c_str();
		conn.m_strPassword    = ASCII_STRING(connInfo[SMC_CONNECTION_PWD]).c_str();
	}
	else//目前不支持的引擎类型
	{
		return false;
	}
	//对数据源进行打开
	if(sdbDs.Open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SMCDataSource::OpenOraDS()
{
	UGC::UGDataSource *pds;
	pds = UGC::UGDataSourceManager::CreateDataSource(UGC::OraclePlus);

	UGC::UGDsConnection &conn = pds->GetConnectionInfo();
	conn.m_bAutoConnect = true;
	conn.m_strDatabase = "majun2";
	conn.m_strServer   = "UGCES";
	conn.m_strUser	   = "majun2";
	conn.m_strPassword = "majun2";
	bool bOpen = pds->Open();
	return true;
}

#include "stdafx.h"

#include "FDOConnection.h"

FdoIConnection * GetFDOConnection(char * strEngineType, bool bImage)
{
	
	FdoPtr<FdoProviderRegistry> registry = (FdoProviderRegistry *)FdoFeatureAccessManager::GetProviderRegistry();
	FdoPtr<FdoConnectionManager> connectMgr = (FdoConnectionManager *)FdoFeatureAccessManager::GetConnectionManager();
	FdoPtr<FdoIConnection> fdoConnection = connectMgr->CreateConnection(_T("SuperMap.SuperMap SDX.1.0"));

	FdoPtr<FdoIConnectionInfo> info = fdoConnection->GetConnectionInfo();
	FdoPtr<FdoIConnectionPropertyDictionary> ConnDict = info->GetConnectionProperties();
	if( strcmp(strEngineType, "sdb")== 0 )
	{
		if(bImage)
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=sdb;database=C:\\world.sdb;IsImage=true"));
		}
		else
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=sdb;database=C:\\world.sdb;IsImage=false"));
		}
	}
	else if( strcmp(strEngineType, "sql")== 0 )
	{
		if(bImage)
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=sql;server=192.168.1.76;database=FDO_test;user=sa;password=123456;IsImage=true"));
		}
		else
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=sql;server=192.168.1.76;database=FDO_test;user=sa;password=123456;IsImage=false"));
		}
	}
	else if( strcmp(strEngineType, "ora")== 0 )
	{
		if(bImage)
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=ora;server=TEST;database=majun;user=majun;password=majun;IsImage=true"));
		}
		else
		{
			ConnDict->SetProperty(_T("DataSource"), _T("type=ora;server=TEST;database=majun;user=majun;password=majun;IsImage=false"));
		}
	}
	FdoConnectionState state = fdoConnection->Open();

	return FDO_SAFE_ADDREF(fdoConnection.p);
}
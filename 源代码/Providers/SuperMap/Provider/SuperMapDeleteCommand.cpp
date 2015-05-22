
/** \file	 SuperMapDeleteCommand.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

SuperMapDeleteCommand::SuperMapDeleteCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIDelete, SuperMapConnection> (connection)
{

}

SuperMapDeleteCommand::~SuperMapDeleteCommand (void)
{

}

/// <summary>Executes the delete command and returns the number of instances
/// deleted</summary>
/// <returns>Returns the number of instances deleted.</returns> 
FdoInt32 SuperMapDeleteCommand::Execute ()
{
	//******* 从FDO连接中获取数据源，并从数据源中按照要素类名获取记录集 *********
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)GetConnection ();
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDatasetVector *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	if(!superMapConn.p)
	{
		TRACE(_T("SuperMapDeleteCommand::得到空的连接类... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_NOT_ESTABLISHED, "SuperMap connection is invalid'%1$ls'.", L"Execute"));
	}

	pDataSource = superMapConn->GetDataSource(); //得到数据源

	if(NULL == pDataSource)
	{
		TRACE(_T("SuperMapDeleteCommand::数据源为空... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}
	if( !pDataSource->IsOpen() )
	{
		TRACE(_T("SuperMapDeleteCommand::数据源未打开... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	UGC::UGString strDatasetName = SuperMapUtil::WcharToString(mClassName->GetName()).c_str();
	pDataset = (UGC::UGDatasetVector *)pDataSource->GetDataset(strDatasetName); //得到数据集

	if(pDataset)
	{
		if(!pDataset->IsOpen()) //打开数据集
		{
			pDataset->Open();
		}
		UGC::UGQueryDef querydef;
		if(NULL != mFilter)
		{
			SuperMapFilterProcessor filterPro(pDataSource->GetEngineType());
			mFilter->Process( &filterPro );
			querydef.m_strFilter = filterPro.GetFilterText();
		}
		//************* 按照查询条件获取记录集************
		pRecordset = pDataset->Query(querydef);
	}
	else
	{
		TRACE(_T("SuperMapDeleteCommand::获取数据集失败... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}
	if(pRecordset)
	{
		//执行删除命令
		int nRecNum = pRecordset->GetRecordCount();
		pRecordset->DeleteAll();
		pDataset->ReleaseRecordset(pRecordset);
		pRecordset = NULL;
		pDataset->Close();
		return nRecNum;
	}
	else
	{
		TRACE(_T("SuperMapDeleteCommand::获取记录集失败... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'!.", L"SuperMapInsertCommand::Execute"));
	}
}

/// <summary> Deleting objects might result in lock conflicts if objects
/// to be deleted are not exclusively locked for the user attempting to
/// delete the object. A lock conflict report is generated.
/// The function GetLockConflicts returns a lock conflict reader that provides
/// access to the list of lock conflicts that occurred during the execution
/// of the delete operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* SuperMapDeleteCommand::GetLockConflicts ()
{
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockConflicts"));
}






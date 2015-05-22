
/** \file	 SuperMapSelectCommand.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

// TODO::关键是在数据库中查询中用到，再研究一下！

SuperMapSelectCommand::SuperMapSelectCommand (SuperMapConnection* connection) :
    FdoCommonFeatureCommand<FdoISelect, SuperMapConnection> (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapSelectCommand::SuperMapSelectCommand (const SuperMapSelectCommand &right) { }

SuperMapSelectCommand::~SuperMapSelectCommand (void)
{
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing.</returns> 
void SuperMapSelectCommand::Dispose ()
{
    delete this;
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
/// return with the result. If empty all properties of the specified class
/// are returned.</summary>
/// <returns>Returns the list of property names.</returns> 
FdoIdentifierCollection* SuperMapSelectCommand::GetPropertyNames ()
{
	//TODO::再研究一下，是否可以把B(C)LOB类似的字段屏蔽掉！
	// 
	TRACE(_T("调用 SuperMapSelectCommand::GetPropertyNames()... \n"));
    if (m_PropertiesToSelect == NULL)
        m_PropertiesToSelect = FdoIdentifierCollection::Create();

    return (FDO_SAFE_ADDREF(m_PropertiesToSelect.p));
}

/// <summary>Gets the FdoLockType value (see "Locking Commands").</summary>
/// <returns>Returns the lock type.</returns> 
FdoLockType SuperMapSelectCommand::GetLockType ()
{
	TRACE(_T("调用 SuperMapSelectCommand::GetLockType()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockType"));
}

/// <summary>Sets the FdoLockType value (see "Locking Commands").</summary>
/// <param name="value">Input the lock type.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectCommand::SetLockType (FdoLockType value)
{
	TRACE(_T("调用 SuperMapSelectCommand::SetLockType()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"SetLockType"));
}

/// <summary>Gets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <returns>Returns the lock strategy.</returns> 
FdoLockStrategy SuperMapSelectCommand::GetLockStrategy ()
{
	TRACE(_T("调用 SuperMapSelectCommand::GetLockStrategy()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockStrategy"));
}

/// <summary>Sets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <param name="value">Input the lock strategy.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapSelectCommand::SetLockStrategy (FdoLockStrategy value)
{
	TRACE(_T("调用 SuperMapSelectCommand::SetLockStrategy()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"SetLockStrategy"));
}

/// <summary>Executes the select command and returns a reference to an FdoIFeatureReader.</summary>
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* SuperMapSelectCommand::Execute ()
{
	
	TRACE(_T("调用 ShpMapSelectCommand::Execute()... \n"));
	if(mFilter == NULL)
	{
		TRACE(_T("SuperMapSelectCommand::查询参数为空... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectCommand::查询参数为:[%ls]\n"), mFilter->ToString());
	}
	if(mClassName == NULL)
	{
		TRACE(_T("SuperMapSelectCommand::要素类名为空... \n"));
	}
	else
	{
		TRACE(_T("SuperMapSelectCommand::要素类名为[%ls]... \n"), mClassName->GetName());
	}
	//*********************** 从模式描述中获取要素类定义 ***********************
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)GetConnection ();
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDataset *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	if(!superMapConn.p)
	{
		TRACE(_T("SuperMapSelectCommand::得到空的连接类... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_NOT_ESTABLISHED, "SuperMap connection is invalid'%1$ls'.", L"Execute"));
	}

	FdoPtr<SuperMapLpFeatureSchemaCollection> pLPFeatureSchemaCollection = superMapConn->GetLpSchemas();
	FdoPtr<FdoFeatureSchemaCollection> pFeatureSchemaCollection = pLPFeatureSchemaCollection->GetLogicalSchemas();

	// modified by zhouxu 2007-12-6 需要考虑多个模式的情况
	// 大容量COPY的后，在一个数据源中可能对应多个模式，在这种情况下就可能需要在多个模式中查询所需要素类。
	FdoPtr<FdoFeatureSchema> pFeatureSchema;
	FdoPtr<FdoClassCollection> pClassCollection;
	FdoPtr<FdoClassDefinition> pClassDef;
	for(FdoInt32 i = 0; i < pFeatureSchemaCollection->GetCount(); ++i)
	{
		pFeatureSchema = pFeatureSchemaCollection->GetItem(i);
		pClassCollection = pFeatureSchema->GetClasses();
		pClassDef = pClassCollection->FindItem(mClassName->GetName());
		
		// 找到就跳出循环，多个模式都在同一个数据源中，而一个数据源不可能有同名的数据集，因此多个模式中也不会有同名的要素类
		if(pClassDef != NULL)
			break;        
	}

	//******* 从FDO连接中获取数据源，并从数据源中按照要素类名获取记录集 *********
	pDataSource = superMapConn->GetDataSource(); //Get UGC DataSource
	if (NULL == pDataSource)
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));

	if ( !pDataSource->IsOpen() )    
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));


	UGC::UGString strDatasetName = SuperMapUtil::WcharToString(mClassName->GetName()).c_str();
	pDataset = pDataSource->GetDataset(strDatasetName); //get the dataset
	if(pDataset)
	{
		//TODO:: 不要默认查询，要把每个字段都列出来查询！可以再做一下测试！
		pDataset->Open();
		if(pDataset->IsVector()) //矢量数据集
		{
			UGC::UGQueryDef querydef;
			querydef.m_nCursorType = UGC::UGQueryDef::OpenStatic;
			UGC::UGGeometry *pQueryGeometry = NULL; //used for spatial query
			SuperMapFilterProcessor filterPro(pDataSource->GetEngineType());

			if(NULL != mFilter) // 处理过滤条件
			{			
				mFilter->Process( &filterPro );
				pQueryGeometry = filterPro.GetGeometry();
				if(NULL != filterPro.GetFilterText())
				{
					querydef.m_strFilter = filterPro.GetFilterText();
				}
			}		
			pRecordset = ( (UGC::UGDatasetVector *)pDataset )->Query(querydef); //这次查询为非空间查询
 			for(int i = 0; i < filterPro.m_GeometryArray.size(); ++i) //可以进行多次空间查询
			{
				UGC::UGSpatialQuery spatialquery;
				if( filterPro.m_GeometryArray[i] )
				{
					pRecordset = spatialquery.Query(pRecordset, 
						filterPro.m_GeometryArray[i], 
						(UGC::UGSpatialQuery::UGSpatialQueryMode)filterPro.GetSpatialQueryType());
					delete filterPro.m_GeometryArray[i];
				}
			}	
		}
	}
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	FdoPtr<FdoIFeatureReader> ret;
	if(pDataset->IsVector()) //矢量数据集
	{
		ret = new SuperMapFeatureReader(FDO_SAFE_ADDREF(pClassDef.p), pRecordset);
	}
	else if(pDataset->IsRaster()) //栅格数据集
	{
		FdoPtr<FdoIdentifierCollection> selProp = GetPropertyNames();
		if(selProp->GetCount() > 0)
		{
			TRACE(_T("调用 SuperMapSelectCommand::已经创建栅格数据集的FeatureReader...[%ls] \n"), selProp->GetItem(0)->ToString());
		}
		TRACE(_T("调用 SuperMapSelectCommand::已经创建栅格数据集的FeatureReader...[%d] \n"), selProp->GetCount());
		ret = new SuperMapFeatureReader(FDO_SAFE_ADDREF(pClassDef.p), (UGC::UGDatasetRaster *)pDataset);
	}
	return FDO_SAFE_ADDREF(ret.p);
}

/// <summary>Executes the select command and returns a reference to an
/// IFeatureReader.</summary> 
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* SuperMapSelectCommand::ExecuteWithLock ()
{
	TRACE(_T("调用 SuperMapSelectCommand::ExecuteWithLock()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"ExecuteWithLock"));
}

/// <summary> When executing the operation ExecuteWithLock lock 
/// conflicts may occur. Those lock conflicts are reported. The 
/// function GetLockConflicts returns a lock conflict reader 
/// providing access to the list of lock conflicts that occurred 
/// during the execution of the operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* SuperMapSelectCommand::GetLockConflicts ()
{
	TRACE(_T("调用 SuperMapSelectCommand::GetLockConflicts()... \n"));
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockConflicts"));
}

/*! 
	\file	SMCDatasetVector.cpp
    \brief	矢量数据集类（抽象类）
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-21 初始化版本
*/

#include "UGC.h"
#include "SMCDatasetVector.h"

SMCDatasetVector::SMCDatasetVector()
{
}

SMCDatasetVector::~SMCDatasetVector()
{
}

bool SMCDatasetVector::Open()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->Open();
}

void SMCDatasetVector::Close()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	pDatasetVector->Close();
}

bool SMCDatasetVector::Rename(const _tstring& strNewName)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->Rename(ASCII_STRING(strNewName).c_str());
}

bool SMCDatasetVector::SaveInfo()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->SaveInfo();
}

SMCDataset::DatasetType SMCDatasetVector::GetType() const
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset ;
	return (SMCDataset::DatasetType)(pDatasetVector->GetType());
}

_tstring SMCDatasetVector::GetName()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset ;
	return UNICODE_STRING(pDatasetVector->GetName().Cstr());
}

bool SMCDatasetVector::IsVector()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset ;
	return pDatasetVector->IsVector();
}

bool SMCDatasetVector::HasGeometry() const
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->HasGeometry();
}

int SMCDatasetVector::GetRecordsetCount()
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->GetRecordsetCount();
}

bool SMCDatasetVector::Query(const SMCQueryDef &queryDef, SMCRecordset *&pRecordset)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	UGC::UGQueryDef tmpQuery;
	tmpQuery.m_nType = (UGC::UGQueryDef::QueryType)queryDef.m_nType;
	tmpQuery.m_nOptions = (UGC::UGQueryDef::QueryOption)queryDef.m_nOptions;
	tmpQuery.m_nMode = (UGC::UGQueryDef::QueryMode)queryDef.m_nMode;
	(UGC::UGRecordset*&)(pRecordset->m_pRecordset) = pDatasetVector->Query(tmpQuery);
	if(pRecordset->m_pRecordset != NULL)
		return true;
	else
		return false;
	
}

bool SMCDatasetVector::Append(SMCRecordset *pSrcRecordset, bool bShowProgress, _tstring strTileName)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	UGC::UGRecordset* pRecordset = (UGC::UGRecordset*)(pSrcRecordset->m_pRecordset);
	return pDatasetVector->Append(pRecordset, bShowProgress, ASCII_STRING(strTileName).c_str());
}

bool SMCDatasetVector::GetRecordsetAt(int nIndex, SMCRecordset *&pRecordset)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	(UGC::UGRecordset*&)(pRecordset->m_pRecordset) = pDatasetVector->GetRecordsetAt(nIndex);
	if(pRecordset->m_pRecordset != NULL)
		return true;
	else
		return false;
}

bool SMCDatasetVector::ReleaseRecordset(int nIndex)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	return pDatasetVector->ReleaseRecordset(nIndex);
}

bool SMCDatasetVector::ReleaseRecordset(SMCRecordset *pRecordset)
{
	UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;
	UGC::UGRecordset* pUGRecordset = (UGC::UGRecordset*)(pRecordset->m_pRecordset);
	return pDatasetVector->ReleaseRecordset(pUGRecordset);
}




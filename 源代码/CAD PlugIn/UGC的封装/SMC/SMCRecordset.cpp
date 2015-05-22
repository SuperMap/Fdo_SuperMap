/*! 
	\file	SMCRecordset.cpp
    \brief	记录集类，当前版本主要管理查询得到的记录
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#include "UGC.h"
#include "SMCRecordset.h"
#include "SMCVariant.h"
#include "SMCDatasetVector.h"
#include "SMCFieldInfo.h"

void UGCFieldInfoToSMCFieldInfo(SMCFieldInfo& Smc, const UGC::UGFieldInfo& Ugc)
{
	Smc.m_strName 			= UNICODE_STRING(Ugc.m_strName.Cstr());
	Smc.m_nType   			= SMCFieldInfo::FieldType(Ugc.m_nType);
	Smc.m_nSize   			= Ugc.m_nSize;
	Smc.m_nAttributes   	= Ugc.m_nAttributes;
	Smc.m_nOrdinalPosition  = Ugc.m_nOrdinalPosition;
	Smc.m_bRequired			= Ugc.m_bRequired;
	Smc.m_bAllowZeroLength  = Ugc.m_bAllowZeroLength;
	Smc.m_nCollatingOrder   = Ugc.m_nCollatingOrder;
	Smc.m_strForeignName	= UNICODE_STRING(Ugc.m_strForeignName.Cstr());
	Smc.m_strSourceField    = UNICODE_STRING(Ugc.m_strSourceField.Cstr());
	Smc.m_strSourceTable	= UNICODE_STRING(Ugc.m_strSourceTable.Cstr());
	Smc.m_strValidationRule = UNICODE_STRING(Ugc.m_strValidationRule.Cstr());
	Smc.m_strValidationText = UNICODE_STRING(Ugc.m_strValidationText.Cstr());
	Smc.m_strDefaultValue   = UNICODE_STRING(Ugc.m_strDefaultValue.Cstr());
	Smc.m_nScale			= Ugc.m_nScale;
	Smc.m_nPrecision		= Ugc.m_nPrecision;
	Smc.m_strFormat			= UNICODE_STRING(Ugc.m_strFormat.Cstr());
	Smc.m_strDomain			= UNICODE_STRING(Ugc.m_strDomain.Cstr());
	Smc.m_bUpdatable		= Ugc.m_bUpdatable;
    Smc.m_strIndexTab		= UNICODE_STRING(Ugc.m_strIndexTab.Cstr());
}



SMCRecordset::SMCRecordset()
{
	m_pRecordset = NULL;
}

SMCRecordset::~SMCRecordset()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		pRecordset->GetDataset()->ReleaseRecordset(pRecordset);
	}
	m_pRecordset = NULL;
}

bool SMCRecordset::GetDataset(SMCDatasetVector *&pDatasetVector) const
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		pDatasetVector->m_pDataset = NULL;
		(UGC::UGDatasetVector *&)(pDatasetVector->m_pDataset) = pRecordset->GetDataset();
		if(pDatasetVector->m_pDataset != NULL)
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

bool SMCRecordset::HasDBInfo()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->HasDBInfo();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::HasGeometry()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->HasGeometry();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::DeleteAll()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->DeleteAll();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::Statistic(const _tstring& strField,SMCStatisticMode nMode, SMCVariant &varVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGVariant ugvar = pRecordset->Statistic(ASCII_STRING(strField), UGC::UGStatisticMode(nMode));
		//memcpy(&varVal, &ugvar, min(sizeof(varVal), sizeof(ugvar)));
		memcpy(&varVal, &ugvar, sizeof(ugvar));
		return true;
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::Refresh()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Refresh();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::CopyField(const _tstring& strSrcField,const _tstring& strDestField)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->CopyField(ASCII_STRING(strSrcField).c_str(), ASCII_STRING(strDestField).c_str());
	}
	else
	{
		return false;
	}
}

int SMCRecordset::GetID()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->GetID();
	}
	else
	{
		return -1;
	}
}

bool SMCRecordset::IsEmpty()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->IsEmpty();
	}
	else
	{
		return false;
	}
}

int SMCRecordset::Update()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Update();
	}
	else
	{
		return -1;
	}
}

bool SMCRecordset::CancelUpdate()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->CancelUpdate();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::Edit()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Edit();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::Delete()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Delete();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::CanUpdate()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->CanUpdate();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::CanAppend()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->CanAppend();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::IsBOF()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->IsBOF();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::IsEOF()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->IsEOF();
	}
	else
	{
		return false;
	}
}

void SMCRecordset::Close()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Close();
	}
	else
	{
		return;
	}
}

bool SMCRecordset::GetFieldValue(const _tstring& strName,SMCVariant &varVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGVariant ugvar;
		if(pRecordset->GetFieldValue(ASCII_STRING(strName).c_str(), ugvar))
		{
			//memcpy(&varVal, &ugvar, min(sizeof(varVal), sizeof(ugvar)));
			memcpy(&varVal, &ugvar, sizeof(ugvar));
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

bool SMCRecordset::GetFieldValue(int nIndex,SMCVariant &varVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGVariant ugvar;
		if(pRecordset->GetFieldValue(nIndex, ugvar))
		{
			//memcpy(&varVal, &ugvar, min(sizeof(varVal), sizeof(ugvar)));
			memcpy(&varVal, &ugvar, sizeof(ugvar));
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

bool SMCRecordset::FindFirst(const _tstring& strFilter)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->FindFirst(ASCII_STRING(strFilter).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::FindLast(const _tstring& strFilter)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->FindLast(ASCII_STRING(strFilter).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::FindNext(const _tstring& strFilter)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->FindNext(ASCII_STRING(strFilter).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::FindPrev(const _tstring& strFilter)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->FindPrev(ASCII_STRING(strFilter).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::Move(int nRows)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->Move(nRows);
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::MoveFirst()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->MoveFirst();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::MoveLast()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->MoveLast();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::MoveNext()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->MoveNext();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::MovePrev()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->MovePrev();
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::MoveTo(int nRow)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->MoveTo(nRow);
	}
	else
	{
		return false;
	}
}

int SMCRecordset::GetRecordCount()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->GetRecordCount();
	}
	else
	{
		return -1;
	}
}

int SMCRecordset::GetFieldCount()
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->GetFieldCount();
	}
	else
	{
		return -1;
	}
}

bool SMCRecordset::SetFieldValueNull(const _tstring& strName)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->SetFieldValueNull(ASCII_STRING(strName).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::SetFieldValueNull(int nIndex)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->SetFieldValueNull(nIndex);
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::SetFieldValue(int nIndex, const _tstring& strVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->SetFieldValue(nIndex, ASCII_STRING(strVal).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::SetFieldValue(int nIndex,const SMCVariant& varVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGVariant ugvar;
		memcpy(&ugvar, &varVal, sizeof(varVal));
		return pRecordset->SetFieldValue(nIndex, ugvar);
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::SetFieldValue(const _tstring& strName,const _tstring& strVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		return pRecordset->SetFieldValue(ASCII_STRING(strName).c_str(), ASCII_STRING(strVal).c_str());
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::SetFieldValue(const _tstring& strName,const SMCVariant& varVal)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGVariant ugvar;
		memcpy(&ugvar, &varVal, sizeof(varVal));
		return pRecordset->SetFieldValue(ASCII_STRING(strName), ugvar);
	}
	else
	{
		return false;
	}
}

bool SMCRecordset::GetFieldInfos(SMCFieldInfos& fieldInfos)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGFieldInfos ugfieldInfos;
		if(pRecordset->GetFieldInfos(ugfieldInfos))
		{
			int nSize = ugfieldInfos.GetSize();
			for(int i = 0; i< nSize; i++)
			{
				UGC::UGFieldInfo ugfieldInfo = ugfieldInfos.GetAt(i);
				SMCFieldInfo fieldInfo;
				UGCFieldInfoToSMCFieldInfo(fieldInfo, ugfieldInfo);
				fieldInfos.push_back(fieldInfo);
			}
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

bool SMCRecordset::GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGFieldInfo ugfieldInfo;
		if(pRecordset->GetFieldInfo(ASCII_STRING(strName).c_str(), ugfieldInfo))
		{
			UGCFieldInfoToSMCFieldInfo(fieldInfo, ugfieldInfo);
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

bool SMCRecordset::GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo)
{
	if(m_pRecordset != NULL)
	{
		UGC::UGRecordset *pRecordset =  (UGC::UGRecordset *)m_pRecordset;
		UGC::UGFieldInfo ugfieldInfo;
		if(pRecordset->GetFieldInfo(nIndex, ugfieldInfo))
		{
			UGCFieldInfoToSMCFieldInfo(fieldInfo, ugfieldInfo);
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


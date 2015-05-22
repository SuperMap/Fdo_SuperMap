/*! 
	\file	SMCDataSources.cpp
    \brief	数据源指针管理类，通过数据源指针与数据源别名的一一对应关系进行管理.
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 初始化版本
*/

#include"UGC.h"
#include "SMCDataSources.h"

SMCDataSources::SMCDataSources()
{
}

SMCDataSources::~SMCDataSources()
{
}

int SMCDataSources::GetCount() const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->GetCount();
}

bool SMCDataSources::IsEmpty() const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->IsEmpty();
}

void SMCDataSources::Reset()
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	pDataSources->Reset();
}

bool SMCDataSources::ReleaseAt(const _tstring &strAlias)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->ReleaseAt(ASCII_STRING(strAlias).c_str());
}

bool SMCDataSources::ReleaseAt(int nIndex)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->ReleaseAt(nIndex);
}

int SMCDataSources::FindAlias(const _tstring &strAlias) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->FindAlias(ASCII_STRING(strAlias).c_str());
}

_tstring SMCDataSources::GetAliasAt(int nIndex) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return UNICODE_STRING(pDataSources->GetAliasAt(nIndex).Cstr());
}


void SMCDataSources::SetModifiedFlag(bool bModified)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	pDataSources->SetModifiedFlag(bModified);
}

bool SMCDataSources::IsModified() const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->IsModified();
}

bool SMCDataSources::Rename(const _tstring &strAlias, const _tstring &strNewAlias)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->Rename(ASCII_STRING(strAlias).c_str(), ASCII_STRING(strNewAlias).c_str());
}

bool SMCDataSources::IsAliasExisted(const _tstring &strAlias) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->IsAliasExisted(ASCII_STRING(strAlias).c_str());
}

bool SMCDataSources::FromXML(const _tstring &strXML, const _tstring &strWorkspaceName, int nVersion)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->FromXML(ASCII_STRING(strXML).c_str(), ASCII_STRING(strWorkspaceName).c_str(), nVersion);
}

_tstring SMCDataSources::ToXML(const _tstring &strWorkspaceName, int nVersion) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return UNICODE_STRING(pDataSources->ToXML(ASCII_STRING(strWorkspaceName).c_str(), nVersion).Cstr());
}

///加SMCDataSource后所添加接口（以下都是）
bool SMCDataSources::Lookup(const _tstring &strAlias, SMCDataSource *&pResDataSource) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->Lookup(ASCII_STRING(strAlias).c_str(), (UGC::UGDataSource*&)(pResDataSource->m_pDataSource));
}

void SMCDataSources::SetAt(const _tstring &strAlias, SMCDataSource *pDataSource)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	pDataSources->SetAt(ASCII_STRING(strAlias).c_str(), (UGC::UGDataSource*&)(pDataSource->m_pDataSource));
}

bool SMCDataSources::GetAt(int nIndex, _tstring &strAlias, SMCDataSource *&pDataSource) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	UGC::UGString tmpAlias = ASCII_STRING(strAlias).c_str();
	bool IsGet = pDataSources->GetAt(nIndex, tmpAlias,(UGC::UGDataSource*&)(pDataSource->m_pDataSource));
	strAlias = UNICODE_STRING(tmpAlias.Cstr());
	return IsGet;
}

_tstring SMCDataSources::GetAlias(SMCDataSource *pDataSource) const
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return UNICODE_STRING(pDataSources->GetAlias((UGC::UGDataSource*&)(pDataSource->m_pDataSource)).Cstr());
}

bool SMCDataSources::Insert(const _tstring &strAlias, SMCDataSource *pDataSource)
{
	UGC::UGDataSources* pDataSources = (UGC::UGDataSources*)m_pDataSources;
	return pDataSources->Insert(ASCII_STRING(strAlias).c_str(), (UGC::UGDataSource*&)(pDataSource->m_pDataSource));
}



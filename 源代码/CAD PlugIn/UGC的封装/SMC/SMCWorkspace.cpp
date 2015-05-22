/*! 
	\file	SMCWorkspace.cpp
    \brief	工作空间管理类，当前版本主要用来管理数据源集合
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 初始化版本
*/

#include "UGC.h"
#include "SMCWorkspace.h"

SMCWorkspace::SMCWorkspace()
{
	m_pWorkspace = new UGC::UGWorkspace;
	if(m_pWorkspace != NULL)
	{
		UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
		m_DataSources.m_pDataSources = &pWorkspace->m_DataSources;
	}
	else
	{
		m_DataSources.m_pDataSources = NULL ;
	}
}

SMCWorkspace::~SMCWorkspace()
{
	delete m_pWorkspace ;
}

bool SMCWorkspace::Open(const _tstring &strWorkspaceName, const _tstring &strPassword )
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	return pWorkspace->Open(ASCII_STRING(strWorkspaceName).c_str(), ASCII_STRING(strPassword).c_str());
}

void SMCWorkspace::Close()
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	pWorkspace->Close();
}

void SMCWorkspace::Reset()
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	pWorkspace->Reset();
}

void SMCWorkspace::SetModifiedFlag(bool bModified )
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	pWorkspace->SetModifiedFlag(bModified);
}

bool SMCWorkspace::IsModified()const
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	return pWorkspace->IsModified();
}

bool SMCWorkspace::Save()
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	return pWorkspace->Save();
}

bool SMCWorkspace::SaveAs(const _tstring& strWorkspaceName, 
			bool bFailIfExists ,
			bool bIsXMLFormat ,
			int nVersion ,
			const _tstring& strNewPassword )
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace ;
	return pWorkspace->SaveAs(ASCII_STRING(strWorkspaceName).c_str(), bFailIfExists, bIsXMLFormat, nVersion, ASCII_STRING(strNewPassword).c_str());

}

_tstring SMCWorkspace::GetName() const
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	_tstring strWorkspaceName = UNICODE_STRING(pWorkspace->GetName().Cstr());
	return strWorkspaceName;
}

int SMCWorkspace::GetType() const
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	return pWorkspace->GetType();
}

_tstring SMCWorkspace::GetPassword() const
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	return UNICODE_STRING(pWorkspace->GetPassword().Cstr());
}


void SMCWorkspace::ChangePassword(const _tstring &strNewPassword)
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	pWorkspace->ChangePassword(ASCII_STRING(strNewPassword).c_str());
}

bool SMCWorkspace::GetDataSource(const _tstring &strAlias, SMCDataSource *&pDataSource)
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	(UGC::UGDataSource*&)(pDataSource->m_pDataSource) = pWorkspace->GetDataSource(ASCII_STRING(strAlias).c_str());
	if(pDataSource->m_pDataSource != NULL)
		return true;
	else
		return false;
}

bool SMCWorkspace::GetDataSource(int nIndex, SMCDataSource *&pDataSource)
{
	UGC::UGWorkspace* pWorkspace = (UGC::UGWorkspace*)m_pWorkspace;
	(UGC::UGDataSource*&)(pDataSource->m_pDataSource) = pWorkspace->GetDataSource(nIndex);
	if(pDataSource->m_pDataSource != NULL)
		return true;
	else
		return false;
}



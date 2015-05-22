/*! 
	\file	SMCDataset.cpp
    \brief	数据集管理类
	\author	周旭
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


SMCDataset::SMCDataset()
{
	m_pDataset = NULL ;
}

SMCDataset::~SMCDataset()
{
	m_pDataset = NULL;
}

int SMCDataset::GetID() const
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	return pDataset->GetID();
}

void SMCDataset::SetID(int nID)
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	pDataset->SetID(nID);
}

bool SMCDataset::GetDataSource(SMCDataSource *&pDataSource) const
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	(UGC::UGDataSource*&)(pDataSource->m_pDataSource) = pDataset->GetDataSource();
	if(pDataSource->m_pDataSource != NULL)
		return true;
	else
		return false;
}

void SMCDataset::SetDataSource(SMCDataSource *pDataSource)
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	if(pDataSource->m_pDataSource != NULL)
	{
		pDataset->SetDataSource((UGC::UGDataSource*)(pDataSource->m_pDataSource));
	}
	else
	{
		return;
	}
}

bool SMCDataset::IsModified() const
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	return pDataset->IsModified();
}

void SMCDataset::SetModifiedFlag(bool bModified)
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	pDataset->SetModifiedFlag(bModified);
}

bool SMCDataset::IsOpen() const
{
	UGC::UGDataset* pDataset = (UGC::UGDataset*)m_pDataset;
	return pDataset->IsOpen();
}
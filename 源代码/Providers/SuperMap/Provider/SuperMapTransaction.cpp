/** \file	 SuperMapTransaction.cpp
*  \author	 郝玉江
*  \attention 事务中没有加入线程安全问题，如果要支持多线程，需加线程安全。
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-03-03
*/

#include <SuperMap.h>

SuperMapTransaction::SuperMapTransaction () :
m_pConnection (NULL),
m_bSpent(false)
{
}

SuperMapTransaction::~SuperMapTransaction (void)
{
	if (!m_bSpent)	// 如果什么操作都不做，默认提交事务
		Commit();
}

/// <summary> Gets the FdoIConnection object associated with the transaction.</summary>
/// <returns>Returns FdoIConnection object</returns>
FdoIConnection* SuperMapTransaction::GetConnection ()
{
	return (FDO_SAFE_ADDREF(m_pConnection));
}

/// <summary> Commits the transaction.</summary>
/// <returns>Returns nothing</returns>
void SuperMapTransaction::Commit ()
{
	TRACE(_T("调用 SuperMapTransaction::Commit [提交事务]...\n"));
	if (m_bSpent)
		throw FdoException::Create (NlsMsgGet(SUPERMAP_TRANSACTION_SPENT, 
								"This transaction has already been committed or rolled back."));

	if (NULL != m_pConnection)
	{
		// finish edit session
		m_pConnection->Flush ();

		// Commit
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// 判断数据源是否支持短事务操作
		{
			pDataSource->Commit();
		}

		m_bSpent = true;
		m_pConnection->EndTransaction();
	}
}

/// <summary> Rolls back a transaction from a pending state.</summary>
/// <returns>Returns nothing</returns>
void SuperMapTransaction::Rollback ()
{
	TRACE(_T("调用 SuperMapTransaction::Rollback [回滚事务]...\n"));
	if (m_bSpent)
		throw FdoException::Create (NlsMsgGet(SUPERMAP_TRANSACTION_SPENT, 
						"This transaction has already been committed or rolled back."));

	if (NULL != m_pConnection)
	{
		// finish edit session
		m_pConnection->Flush ();

		// rollback
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// 判断数据源是否支持短事务操作
		{
			pDataSource->Rollback();
		}

		m_bSpent = true;
		m_pConnection->EndTransaction();
	}
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void SuperMapTransaction::Dispose ()
{
	TRACE(_T("调用 SuperMapTransaction::Dispose [析构]...\n"));
	m_bSpent = true;
	m_pConnection = NULL;
}

void SuperMapTransaction::SetConnection (SuperMapConnection* pConnection)
{
	// 事务开始
	m_pConnection = pConnection;
	if (NULL != m_pConnection)
	{
		TRACE(_T("调用 SuperMapTransaction::SetConnection [开始事务]...\n"));
		UGC::UGDataSource* pDataSource = m_pConnection->GetDataSource();
		if(pDataSource->IsTransacted())	// 判断数据源是否支持短事务操作
		{
			if(!pDataSource->BeginTrans())
			{
				throw FdoException::Create(NlsMsgGet(SUPERMAP_TRANSACTIONS_NOT_START, 
										"Failed to start transaction."));
			}
		}
	}
}

bool SuperMapTransaction::IsSpent ()
{
	return (m_bSpent);
}


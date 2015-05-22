/** \file	 CSuperMapGetSpatialContextsCommandTest.cpp
*  \brief    负责对SuperMapGetSpatialContextsCommand及空间语义相关类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-19
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapGetSpatialContextsCommandTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapGetSpatialContextsCommandTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapGetSpatialContextsCommandTest::m_connection;

CSuperMapGetSpatialContextsCommandTest::CSuperMapGetSpatialContextsCommandTest()
{
	m_connection = NULL;
}

CSuperMapGetSpatialContextsCommandTest::~CSuperMapGetSpatialContextsCommandTest()
{
}

void CSuperMapGetSpatialContextsCommandTest::setUp()
{
	if(NULL == m_connection)
	{
		m_connection = GetSuperMapConnection();
	}
}

void CSuperMapGetSpatialContextsCommandTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapGetSpatialContextsCommandTest::GetSuperMapConnection()
{
	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapGetSpatialContextsCommandTest::testExecute1()
{
	// 测试WKT串是否正确只能通过MAP3D等来测，单元测试只测试对各种类型的坐标系空间语义读取器的迭代是否正确，是否出现死循环
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"普通平面坐标系\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);
		//FdoPtr<FdoISpatialContextReader> spatialReader = getSpatialContexts->Execute();
		       // Get a SC reader
        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

		m_connection->Close();
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapGetSpatialContextsCommandTest::testExecute2()
{
	//测经纬度坐标情况
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"经纬坐标系\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);

        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

		m_connection->Close();
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}

void CSuperMapGetSpatialContextsCommandTest::testExecute3()
{
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"投影坐标系\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoPtr<FdoIGetSpatialContexts> getSpatialContexts = (FdoIGetSpatialContexts*)m_connection->CreateCommand(FdoCommandType_GetSpatialContexts);

        FdoPtr<FdoISpatialContextReader> reader = getSpatialContexts->Execute();

        // Iterate ...
        while ( reader->ReadNext() )
        {
			reader->GetExtent();
		}

		m_connection->Close();
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
	}
	catch (FdoException* ex)
    {
        FdoException* nex = ex;
        while (nex)
        {
			AfxMessageBox(nex->GetExceptionMessage());
            nex = nex->GetCause();
        }
		ex->Release();
    }
}
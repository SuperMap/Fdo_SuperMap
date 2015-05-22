/** \file	 CSuperMapConnectionTest.cpp
*  \brief    负责对SuperMapConnection类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapConnectionTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

//CPPUNIT_TEST_SUITE_REGISTRATION (CSuperMapConnectionTest);
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapConnectionTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapConnectionTest::m_connection;

CSuperMapConnectionTest::CSuperMapConnectionTest()
{
	m_connection = NULL;
	
}

CSuperMapConnectionTest::~CSuperMapConnectionTest()
{
}

void CSuperMapConnectionTest::setUp()
{
	if(m_connection == NULL)
	{
		m_connection = GetSuperMapConnection();
	}
	
}

void CSuperMapConnectionTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapConnectionTest::GetSuperMapConnection()
{
	/*FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
	FdoPtr<FdoIConnection> connection = manager->CreateConnection (L"OSGeo.SuperMap.1.0");
	return (FDO_SAFE_ADDREF(connection.p));*/

	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapConnectionTest::testConnect()
{
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
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

void CSuperMapConnectionTest::testSetConnectionString()
{
	try
	{
		// 是否支持中英文,连接状态为关闭时是否可以设置连接字符串
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"English中文");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString failed!", 0 == wcscmp(L"English中文", m_connection->GetConnectionString()));
		FdoConnectionState state = m_connection->Open();
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
	try
	{
		// 连接状态为Pending时，是否仍然可以设置连接字符串(我们的provider只有一个连接属性，不可能出现连接状态为pending的情况)
		/*CPPUNIT_ASSERT_MESSAGE("connection state not pending", FdoConnectionState_Pending == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"test");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString failed when connection state is pending", 0 == wcscmp(L"test", m_connection->GetConnectionString()));*/
		
		// 连接状态为Open时，是否不允许重新设置连接字符串
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"test");
		CPPUNIT_ASSERT_MESSAGE("SetConnectionString when Open!", 0 == wcscmp(L"test", m_connection->GetConnectionString()));
		m_connection->Open();
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
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
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

//void CSuperMapConnectionTest::connect2()
//{
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"DataSource=" LOCATION L"world");
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		FdoConnectionState state = m_connection->Open();
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
//		m_connection->Close();
//	}
//	catch (FdoException* ex)
//    {
//        FdoException* nex = ex;
//        while (nex)
//        {
//			AfxMessageBox(nex->GetExceptionMessage());
//            nex = nex->GetCause();
//        }
//		ex->Release();
//    }
//	catch (...)
//	{
//		AfxMessageBox(L"non-FdoException");
//	}
//	CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Closed == m_connection->GetConnectionState());
//}

//void CSuperMapConnectionTest::connect3()
//{
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"DataSource=" LOCATION L"world");
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//		FdoConnectionState state = m_connection->Open();
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
//		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
//		
//		// Verify results of DescribeSchema:
//		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
//		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
//		CPPUNIT_ASSERT_MESSAGE("并不是预期的一个数据源对应一个schema", schemas->GetCount() == 1);
//		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
//		CPPUNIT_ASSERT_MESSAGE("模式名不是数据源名", 0 == wcscmp(schema->GetName(),L"world")); // world 为测试数据源名。不同测试数据源测试需修改此参数 
//		CPPUNIT_ASSERT_MESSAGE("模式描述不为缺省模式描述", 0 == wcscmp(schema->GetDescription(),L"Default schema."));
//		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
//		CPPUNIT_ASSERT_MESSAGE("不是预期的要素类个数", 8 == classes->GetCount()); // world中有8个数据集
//		FdoPtr<FdoClassDefinition> classDef = classes->GetItem(0);
//		CPPUNIT_ASSERT_MESSAGE("不是预期的要素类名", 0 == wcscmp(classDef->GetName(),L"Ocean")); //第一个数据集名为Ocean
//
//		m_connection->Close();
//		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
//
//	}
//	catch (FdoException* ex)
//    {
//        FdoException* nex = ex;
//        while (nex)
//        {
//			AfxMessageBox(nex->GetExceptionMessage());
//            nex = nex->GetCause();
//        }
//		ex->Release();
//    }
//	catch (...)
//	{
//		AfxMessageBox(L"non-FdoException");
//	}
//}

//void CSuperMapConnectionTest::testSetConnectionString()
//{
//	// 主要测试：
//	// 1. 连接状态为closed和pending时，可以正确设置连接字符串
//	// 2. 连接状态为open时，是否不允许改变设置连接字符串
//	try
//	{
//		CPPUNIT_ASSERT_MESSAGE("连接未关闭",FdoConnectionState_Closed == m_connection->GetConnectionState());
//		m_connection->SetConnectionString(L"dd")
//	}
//}




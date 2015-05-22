/** \file	 CSuperMapDescribeSchemaCommandTest.cpp
*  \brief    负责对SuperMapDescribeSchemaCommand类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapDescribeSchemaCommandTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapDescribeSchemaCommandTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapDescribeSchemaCommandTest::m_connection;

CSuperMapDescribeSchemaCommandTest::CSuperMapDescribeSchemaCommandTest()
{
	m_connection = NULL;
}

CSuperMapDescribeSchemaCommandTest::~CSuperMapDescribeSchemaCommandTest()
{
}

void CSuperMapDescribeSchemaCommandTest::setUp()
{
	if(NULL == m_connection)
	{
		m_connection = GetSuperMapConnection();
	}
}

void CSuperMapDescribeSchemaCommandTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapDescribeSchemaCommandTest::GetSuperMapConnection()
{
	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapDescribeSchemaCommandTest::testExecute1()
{
	// 测试对基本的含点、线、面、文本类型数据集的数据源是否能够成功建立逻辑模式
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"world\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("并不是预期的一个数据源对应一个schema", schemas->GetCount() == 1);
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("不是预期的要素类个数", 8 == classes->GetCount()); // world中有8个数据集
		FdoPtr<FdoClassDefinition> classDef = classes->GetItem(0);
		CPPUNIT_ASSERT_MESSAGE("不是预期的要素类名", 0 == wcscmp(classDef->GetName(),L"Ocean")); //第一个数据集名为Ocean

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

void CSuperMapDescribeSchemaCommandTest::testExecute2()
{
	//测试对CAD复合类型数据集能否建立逻辑模式
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//打开一个含两个CAD数据集的数据源
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"CAD\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("模式数并非预期的1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("要素类数并非预期的2", 2 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition = classes->GetItem(1); //取第二个要素类为例
		CPPUNIT_ASSERT_MESSAGE("要素类并非指定数据集", 0 == wcscmp(L"CAD_2",classDefinition->GetName()));

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

void CSuperMapDescribeSchemaCommandTest::testExecute3()
{
	//测试对中文的数据源名，数据集名，属性字段名的支持
	//测试数据范围包括点、线、面、文本、复合等所有provider支持类型数据集
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//打开一个含两个CAD数据集的数据源
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"数据源\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("模式数并非预期的1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("要素类数并非预期的5", 5 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition1 = classes->GetItem(0);
		CPPUNIT_ASSERT_MESSAGE("点数据集中文名错误", 0 == wcscmp(L"点数据集",classDefinition1->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition2 = classes->GetItem(1); 
		CPPUNIT_ASSERT_MESSAGE("线数据集中文名错误", 0 == wcscmp(L"线数据集",classDefinition2->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition3 = classes->GetItem(2); 
		CPPUNIT_ASSERT_MESSAGE("面数据集中文名错误", 0 == wcscmp(L"面数据集",classDefinition3->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition4 = classes->GetItem(3); 
		CPPUNIT_ASSERT_MESSAGE("文本数据集中文名错误", 0 == wcscmp(L"文本数据集",classDefinition4->GetName()));
		FdoPtr<FdoClassDefinition> classDefinition5 = classes->GetItem(4); 
		CPPUNIT_ASSERT_MESSAGE("复合数据集中文名错误", 0 == wcscmp(L"复合数据集",classDefinition5->GetName()));
		
		FdoPtr<FdoPropertyDefinitionCollection> properties = classDefinition1->GetProperties();
		CPPUNIT_ASSERT_MESSAGE("中文名属性字段有问题", NULL != properties->FindItem(L"中文字段"));

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

void CSuperMapDescribeSchemaCommandTest::testExecute4()
{
	//测试对SuperMap点、线、面、文本、复合数据集以外的数据集是否可以成功屏蔽
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//打开一个含所有不支持类型数据集的数据源
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"不支持\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("模式数并非预期的1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("要素类数并非预期的0", 0 == classes->GetCount());

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

void CSuperMapDescribeSchemaCommandTest::testExecute5()
{
	//测试所有类型的属性字段是否都能成功转到FDO逻辑属性字段
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		//打开一个含所有不支持类型数据集的数据源
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"fieldtest\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of DescribeSchema:
		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();
		CPPUNIT_ASSERT_MESSAGE("模式数并非预期的1", 1 == schemas->GetCount());
		FdoPtr<FdoFeatureSchema> schema = schemas->GetItem(0);
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();
		CPPUNIT_ASSERT_MESSAGE("要素类数并非预期的1", 1 == classes->GetCount());
		FdoPtr<FdoClassDefinition> classDefinition = classes->GetItem(0);
		FdoPtr<FdoPropertyDefinitionCollection> properties = classDefinition->GetProperties();
		CPPUNIT_ASSERT_MESSAGE("属性个数并非预期的10", 10 == properties->GetCount());

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

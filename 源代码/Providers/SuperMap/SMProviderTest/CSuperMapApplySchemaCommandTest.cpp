/** \file	 CSuperMapApplySchemaCommandTest.CPP
*  \brief    负责对SuperMapApplySchemaCommand类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-19
*  \note :
*/

#include "stdafx.h"
#include "CSuperMapApplySchemaCommandTest.h"
#include "SMProviderSuite.h"
// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

#define LOCATION L".\\TestData\\"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(CSuperMapApplySchemaCommandTest,SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> CSuperMapApplySchemaCommandTest::m_connection;

CSuperMapApplySchemaCommandTest::CSuperMapApplySchemaCommandTest()
{
	m_connection = NULL;
}

CSuperMapApplySchemaCommandTest::~CSuperMapApplySchemaCommandTest()
{
}

void CSuperMapApplySchemaCommandTest::setUp()
{
	if(NULL == m_connection)
	{
		m_connection = GetSuperMapConnection();
	}
}

void CSuperMapApplySchemaCommandTest::tearDown()
{
	FDO_SAFE_RELEASE(m_connection.p);
}

FdoIConnection* CSuperMapApplySchemaCommandTest::GetSuperMapConnection()
{
	FdoPtr<IConnectionManager> manager = FdoFeatureAccessManager::GetConnectionManager ();
    return (manager->CreateConnection (L"SuperMap.SDB&SDX.1.0"));
}

void CSuperMapApplySchemaCommandTest::testExecute1()
{
	// 测试一般情况下增加一个模式的操作
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"testApplySchema\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoString* NEW_SCHEMA_NAME = L"TestSchema";
		FdoString* NEW_CLASS_NAME = L"TestClass3";
		
		FdoPtr<FdoIApplySchema> apply = (FdoIApplySchema*)m_connection->CreateCommand(FdoCommandType_ApplySchema);
		FdoPtr<FdoFeatureSchema> schema = FdoFeatureSchema::Create(NEW_SCHEMA_NAME, L"");
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();

		FdoPtr<FdoDataPropertyDefinition> id = FdoDataPropertyDefinition::Create(L"Id",L"integer");
		id->SetDataType(FdoDataType_Int32);
		FdoPtr<FdoDataPropertyDefinition> street = FdoDataPropertyDefinition::Create(L"Street", L"text");
		street->SetDataType(FdoDataType_String);
		street->SetLength(64);
		FdoPtr<FdoGeometricPropertyDefinition> location = FdoGeometricPropertyDefinition::Create(L"Geometry",L"geometry");
		FdoGeometryType  geomTypesDest[30];
	    FdoInt32 geomTypeCount = 0;
		geomTypesDest[0] = FdoGeometryType_Polygon;
		geomTypeCount = 1;
	    //location->SetGeometryTypes(FdoGeometryType_Point);
		location->SetSpecificGeometryTypes(geomTypesDest, geomTypeCount);
		
		location->SetHasMeasure(false);
		location->SetHasElevation(false);

		FdoPtr<FdoFeatureClass> feature = FdoFeatureClass::Create(NEW_CLASS_NAME, L"test class created with apply schema");
		FdoPtr<FdoPropertyDefinitionCollection> properties = feature->GetProperties();
		properties->Add(id);                        
		properties->Add(street);                
		properties->Add(location); 
		feature->SetGeometryProperty(location);
		FdoPtr<FdoDataPropertyDefinitionCollection> identities = feature->GetIdentityProperties();
		identities->Add(id);

		classes->Add(feature);
		apply->SetFeatureSchema(schema);
		apply->Execute();

		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();

		CPPUNIT_ASSERT_MESSAGE("模式个数并非预期的2",2 == schemas->GetCount());

		
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

void CSuperMapApplySchemaCommandTest::testExecute2()
{
	// 测试对中文模式名、中文要素类名的支持
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"testApplySchema\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoString* NEW_SCHEMA_NAME = L"测试模式";
		FdoString* NEW_CLASS_NAME = L"测试类";
		
		FdoPtr<FdoIApplySchema> apply = (FdoIApplySchema*)m_connection->CreateCommand(FdoCommandType_ApplySchema);
		FdoPtr<FdoFeatureSchema> schema = FdoFeatureSchema::Create(NEW_SCHEMA_NAME, L"");
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();

		FdoPtr<FdoDataPropertyDefinition> id = FdoDataPropertyDefinition::Create(L"Id",L"integer");
		id->SetDataType(FdoDataType_Int32);
		FdoPtr<FdoDataPropertyDefinition> street = FdoDataPropertyDefinition::Create(L"Street", L"text");
		street->SetDataType(FdoDataType_String);
		street->SetLength(64);
		FdoPtr<FdoGeometricPropertyDefinition> location = FdoGeometricPropertyDefinition::Create(L"Geometry",L"geometry");
		FdoGeometryType  geomTypesDest[30];
	    FdoInt32 geomTypeCount = 0;
		geomTypesDest[0] = FdoGeometryType_Polygon;
		geomTypeCount = 1;
		//location->SetGeometryTypes(FdoGeometryType_Point);
	    location->SetSpecificGeometryTypes(geomTypesDest, geomTypeCount);
		
		location->SetHasMeasure(false);
		location->SetHasElevation(false);

		FdoPtr<FdoFeatureClass> feature = FdoFeatureClass::Create(NEW_CLASS_NAME, L"test class created with apply schema");
		FdoPtr<FdoPropertyDefinitionCollection> properties = feature->GetProperties();
		properties->Add(id);                        
		properties->Add(street);                
		properties->Add(location); 
		feature->SetGeometryProperty(location);
		FdoPtr<FdoDataPropertyDefinitionCollection> identities = feature->GetIdentityProperties();
		identities->Add(id);

		classes->Add(feature);
		apply->SetFeatureSchema(schema);
		apply->Execute();

		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();

		CPPUNIT_ASSERT_MESSAGE("模式个数并非预期的2",2 == schemas->GetCount());

		
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

void CSuperMapApplySchemaCommandTest::testExecute3()
{
	// 测试对"缺省模式"名的支持，即要添加模式集合中同名模式但内容不同的模式时
	try
	{
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		m_connection->SetConnectionString(L"DataSource=" L"\"type=sdb;database=" LOCATION L"testApplySchema\"");
		CPPUNIT_ASSERT_MESSAGE("connection state not closed", FdoConnectionState_Closed == m_connection->GetConnectionState());
		FdoConnectionState state = m_connection->Open();
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == state);
		CPPUNIT_ASSERT_MESSAGE("connection state not open", FdoConnectionState_Open == m_connection->GetConnectionState());
		
		// Verify results of GetSpatialContext:
		FdoString* NEW_SCHEMA_NAME = L"缺省模式";
		FdoString* NEW_CLASS_NAME = L"class123";
		
		FdoPtr<FdoIApplySchema> apply = (FdoIApplySchema*)m_connection->CreateCommand(FdoCommandType_ApplySchema);
		FdoPtr<FdoFeatureSchema> schema = FdoFeatureSchema::Create(NEW_SCHEMA_NAME, L"");
		FdoPtr<FdoClassCollection> classes = schema->GetClasses();

		FdoPtr<FdoDataPropertyDefinition> id = FdoDataPropertyDefinition::Create(L"Id",L"integer");
		id->SetDataType(FdoDataType_Int32);
		FdoPtr<FdoDataPropertyDefinition> street = FdoDataPropertyDefinition::Create(L"Street", L"text");
		street->SetDataType(FdoDataType_String);
		street->SetLength(64);
		FdoPtr<FdoGeometricPropertyDefinition> location = FdoGeometricPropertyDefinition::Create(L"Geometry",L"geometry");
		FdoGeometryType  geomTypesDest[30];
	    FdoInt32 geomTypeCount = 0;
		geomTypesDest[0] = FdoGeometryType_Polygon;
		geomTypeCount = 1;
		//location->SetGeometryTypes(FdoGeometryType_Point);
	    location->SetSpecificGeometryTypes(geomTypesDest, geomTypeCount);
		
		location->SetHasMeasure(false);
		location->SetHasElevation(false);

		FdoPtr<FdoFeatureClass> feature = FdoFeatureClass::Create(NEW_CLASS_NAME, L"test class created with apply schema");
		FdoPtr<FdoPropertyDefinitionCollection> properties = feature->GetProperties();
		properties->Add(id);                        
		properties->Add(street);                
		properties->Add(location); 
		feature->SetGeometryProperty(location);
		FdoPtr<FdoDataPropertyDefinitionCollection> identities = feature->GetIdentityProperties();
		identities->Add(id);

		classes->Add(feature);
		apply->SetFeatureSchema(schema);
		apply->Execute();

		FdoPtr<FdoIDescribeSchema> descSchema = (FdoIDescribeSchema*)m_connection->CreateCommand(FdoCommandType_DescribeSchema);
		FdoPtr<FdoFeatureSchemaCollection> schemas = descSchema->Execute();

		CPPUNIT_ASSERT_MESSAGE("模式个数并非预期的2",2 == schemas->GetCount());

		
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


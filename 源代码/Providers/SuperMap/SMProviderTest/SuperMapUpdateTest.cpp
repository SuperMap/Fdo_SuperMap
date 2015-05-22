#include "StdAfx.h"
#include "SuperMapUpdateTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapUpdateTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapUpdateTest::m_connection = NULL;

SuperMapUpdateTest::SuperMapUpdateTest(void)
{

}

SuperMapUpdateTest::~SuperMapUpdateTest(void)
{

}

void SuperMapUpdateTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection();
	}
}
void SuperMapUpdateTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}

void SuperMapUpdateTest::update_point()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"点");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Update->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);

		//设置几何属性字段
		FdoPtr<FdoGeometryValue> sampleGeometryValue;
		sampleGeometryValue = FdoGeometryValue::Create();
		FdoPtr<FdoFgfGeometryFactory> sampleGeometryFactory;
		sampleGeometryFactory = FdoFgfGeometryFactory::GetInstance();

		double coordinates[] = {254.949628, 245.662514};
		FdoPtr<FdoIPoint> samplePoint;
		samplePoint = sampleGeometryFactory->CreatePoint(FdoDimensionality_XY, coordinates);

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(samplePoint);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		int nUpdateNum = 0;

		FdoString *strFilter = L"SmID = 6 and SmUserID = 0";
		Update->SetFilter( strFilter );
		CPPUNIT_ASSERT_NO_THROW( nUpdateNum = Update->Execute() );

		CPPUNIT_ASSERT_EQUAL( 1, nUpdateNum );
	}
}

void SuperMapUpdateTest::update_line()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"线");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Update->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);

		//设置几何属性字段
		FdoPtr<FdoGeometryValue> sampleGeometryValue;
		sampleGeometryValue = FdoGeometryValue::Create();
		FdoPtr<FdoFgfGeometryFactory> sampleGeometryFactory;
		sampleGeometryFactory = FdoFgfGeometryFactory::GetInstance();

		double coordinates[] = {549.594786, 952.727511, 1280.723956, 1590.145962};
		FdoPtr<FdoILineString> FdoLine;
		FdoPtr<FdoIMultiLineString> FdoMultiLine;
		FdoPtr<FdoLineStringCollection> linecollection; 

		linecollection = FdoLineStringCollection::Create();

		FdoLine = sampleGeometryFactory->CreateLineString(FdoDimensionality_XY, 4, coordinates); //create line
		linecollection->Add(FdoLine.p); //add the line to the collection
		FdoMultiLine = sampleGeometryFactory->CreateMultiLineString(linecollection.p);

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(FdoMultiLine);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		int nUpdateNum = 0;

		FdoString *strFilter = L"SmID = 29 or SmUserID > 5";
		Update->SetFilter( strFilter );
		CPPUNIT_ASSERT_NO_THROW( nUpdateNum = Update->Execute() );

		CPPUNIT_ASSERT_EQUAL( 1, nUpdateNum );
	}
}

void SuperMapUpdateTest::update_region()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"面");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Update->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);

		//设置几何属性字段
		FdoPtr<FdoGeometryValue> sampleGeometryValue;
		sampleGeometryValue = FdoGeometryValue::Create();
		FdoPtr<FdoFgfGeometryFactory> sampleGeometryFactory;
		sampleGeometryFactory = FdoFgfGeometryFactory::GetInstance();
		FdoPtr<FdoIPolygon> FdoPolygon;
		FdoPtr<FdoILinearRing> exteriorRing; //used for create polygon(outer Ring)
		FdoPtr<FdoILinearRing> innerRing; //used for create polygon(inner Ring)
		FdoPtr<FdoLinearRingCollection> interiorRings; //used for create polygon(inner Rings)

		interiorRings = FdoLinearRingCollection::Create();//to create an empty collection

		double exCoordinates[] = {-610.443260, 1934.743025, 292.065025, 1923.906760, 121.780443, 1064.743642, -690.941426, 1095.704475, -610.443260, 1934.743025};
		exteriorRing = sampleGeometryFactory->CreateLinearRing(FdoDimensionality_XY, 10, exCoordinates);

		double inCoordinates[] = {-427.774344, 956.380727, -176.991596, 959.476810, -172.347471, 639.032188, -664.500176, 669.993021, -427.774344, 956.380727};
		innerRing = sampleGeometryFactory->CreateLinearRing(FdoDimensionality_XY, 10, inCoordinates);
		interiorRings->Add(innerRing.p);

		FdoPolygon = sampleGeometryFactory->CreatePolygon(exteriorRing.p, interiorRings.p); //exterior + collection

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(FdoPolygon);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		int nUpdateNum = 0;

		FdoString *strFilter = L"SmID = 16";
		Update->SetFilter( strFilter );
		CPPUNIT_ASSERT_NO_THROW( nUpdateNum = Update->Execute() );

		CPPUNIT_ASSERT_EQUAL( 1, nUpdateNum );
	}
}

void SuperMapUpdateTest::update_cad()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"NEW_CAD");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Update->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);

		//设置几何属性字段
		FdoPtr<FdoGeometryValue> sampleGeometryValue;
		sampleGeometryValue = FdoGeometryValue::Create();
		FdoPtr<FdoFgfGeometryFactory> sampleGeometryFactory;
		sampleGeometryFactory = FdoFgfGeometryFactory::GetInstance();
		FdoPtr<FdoIMultiPoint> FdoMultiPoint;
		
		double Coordinates[] = {-610.443260, 1834.743025, 290.065025, 1923.906760, 121.780443, 1064.743642, -690.941426, 1095.704475};

		FdoMultiPoint = sampleGeometryFactory->CreateMultiPoint(FdoDimensionality_XY, 8, Coordinates); //exterior + collection

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(FdoMultiPoint);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		int nUpdateNum = 0;

		FdoString *strFilter = L"SmID = 10";
		Update->SetFilter( strFilter );
		CPPUNIT_ASSERT_NO_THROW( nUpdateNum = Update->Execute() );

		CPPUNIT_ASSERT_EQUAL( 1, nUpdateNum );
	}
}

void SuperMapUpdateTest::update_text()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"文本");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Update->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);

		//设置文本内容属性字段
		FdoPtr<FdoDataValue> sampleTextDataValue;
		sampleTextDataValue = FdoDataValue::Create(L"中华人民共和国");
		FdoPtr<FdoPropertyValue> samplePropertyValueText;
		samplePropertyValueText = FdoPropertyValue::Create(L"TxtString", sampleTextDataValue);
		samplePropertyValues->Add(samplePropertyValueText);

		//设置文本大小属性字段
		FdoPtr<FdoDataValue> sampleTextSizeDataValue;
		sampleTextSizeDataValue = FdoDataValue::Create(37, FdoDataType_Double);
		FdoPtr<FdoPropertyValue> samplePropertyValueTextSize;
		samplePropertyValueTextSize = FdoPropertyValue::Create(L"TextSize", sampleTextSizeDataValue);
		samplePropertyValues->Add(samplePropertyValueTextSize);


		//设置几何属性字段
		FdoPtr<FdoGeometryValue> sampleGeometryValue;
		sampleGeometryValue = FdoGeometryValue::Create();
		FdoPtr<FdoFgfGeometryFactory> sampleGeometryFactory;
		sampleGeometryFactory = FdoFgfGeometryFactory::GetInstance();

		double coordinates[] = {254.949628, 245.662514};
		FdoPtr<FdoIPoint> samplePoint;
		samplePoint = sampleGeometryFactory->CreatePoint(FdoDimensionality_XY, coordinates);

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(samplePoint);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		int nUpdateNum = 0;

		FdoString *strFilter = L"SmID = 3";
		Update->SetFilter( strFilter );
		CPPUNIT_ASSERT_NO_THROW( nUpdateNum = Update->Execute() );

		CPPUNIT_ASSERT_EQUAL( 1, nUpdateNum );
	}
}

void SuperMapUpdateTest::update_no_featureclass()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIUpdate> Update;
	Update = (FdoIUpdate *)m_connection->CreateCommand(FdoCommandType_Update);
	if(NULL != Update)
	{
		Update->SetFeatureClassName(L"");

		int nUpdateNum = 0;
		try
		{
			nUpdateNum = Update->Execute();
		}
		catch (FdoException* ex)
		{
			FdoException* nex = ex;
			while (nex)
			{
				AfxMessageBox(ex->GetExceptionMessage());
				nex = nex->GetCause();
			}
			ex->Release();
		}
		catch(...)
		{
			CPPUNIT_FAIL("unresolved exception");
		}
	}
}
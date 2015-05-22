#include "StdAfx.h"
#include "SuperMapInsertTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapInsertTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapInsertTest::m_connection = NULL;

SuperMapInsertTest::SuperMapInsertTest(void)
{

}

SuperMapInsertTest::~SuperMapInsertTest(void)
{

}

void SuperMapInsertTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection();
	}
}
void SuperMapInsertTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}

void SuperMapInsertTest::insert_point()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"点");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Insert->GetPropertyValues();
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

		FdoPtr<FdoIFeatureReader> ret;
		ret = Insert->Execute();

		int count = 0;
		int SmID;
		int UserID;
		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Point == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_EQUAL( 1, count );
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
void SuperMapInsertTest::insert_line()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"线");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Insert->GetPropertyValues();
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

		FdoPtr<FdoIFeatureReader> ret;
		ret = Insert->Execute();

		int count = 0;
		int SmID;
		int UserID;
		double Length;
		int ToPoError;
		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"SmLength"))
				{
					Length = ret->GetDouble (L"SmLength");
				}
				if(!ret->IsNull(L"SmTopoError"))
				{
					ToPoError = ret->GetInt32 (L"SmTopoError");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_MultiLineString == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_EQUAL( 1, count );
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
void SuperMapInsertTest::insert_region()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"面");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Insert->GetPropertyValues();
		FdoPtr<FdoDataValue> sampleUserIDDataValue;
		sampleUserIDDataValue = FdoDataValue::Create(2);
		FdoPtr<FdoPropertyValue> samplePropertyValue;
		samplePropertyValue = FdoPropertyValue::Create(L"SmUserID", sampleUserIDDataValue);
		samplePropertyValues->Add(samplePropertyValue);
		
		//设置TestDate字段
		FdoPtr<FdoDataValue> sampleDateDataValue;
		FdoDateTime datetime(2007,12,20,10,59,24);
		sampleDateDataValue = FdoDataValue::Create(datetime);
		FdoPtr<FdoPropertyValue> sampleDateValue;
		sampleDateValue = FdoPropertyValue::Create(L"TestDate", sampleDateDataValue);
		samplePropertyValues->Add(sampleDateValue);

		//设置TestBoolen字段
		FdoPtr<FdoDataValue> sampleBoolDataValue;
		sampleBoolDataValue = FdoDataValue::Create(true);
		FdoPtr<FdoPropertyValue> sampleBoolValue;
		sampleBoolValue = FdoPropertyValue::Create(L"TestBoolen", sampleBoolDataValue);
		samplePropertyValues->Add(sampleBoolValue);

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

		FdoPtr<FdoIFeatureReader> ret;
		ret = Insert->Execute();

		int count = 0;
		int SmID;
		int UserID;
		double SmArea;
		double SmPerimeter;
		bool TestBoolen;
		short TestShort;
		float TestFloat;
		FdoString *str;
		FdoDateTime date;
		int length;
		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"SmArea"))
				{
					SmArea = ret->GetDouble (L"SmArea");
				}
				if(!ret->IsNull(L"SmPerimeter"))
				{
					SmPerimeter = ret->GetDouble (L"SmPerimeter");
				}
				if(!ret->IsNull(L"TestBoolen"))
				{
					TestBoolen = ret->GetBoolean (L"TestBoolen");
				}
				if(!ret->IsNull(L"TestShort"))
				{
					TestShort = ret->GetInt16(L"TestShort");
				}
				if(!ret->IsNull(L"TestFloat"))
				{
					TestFloat = ret->GetSingle(L"TestFloat");
				}
				if(!ret->IsNull(L"TestString"))
				{
					str = ret->GetString(L"TestString");
				}
				if(!ret->IsNull(L"TestDate"))
				{
					date = ret->GetDateTime(L"TestDate");
				}
				if(!ret->IsNull(L"长度"))
				{
					length = ret->GetInt32(L"长度");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_EQUAL( 1, count );
			CPPUNIT_ASSERT_EQUAL( true, TestBoolen );
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

void SuperMapInsertTest::insert_cad()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"NEW_CAD");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Insert->GetPropertyValues();
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
		
		double Coordinates[] = {-610.443260, 1934.743025, 292.065025, 1923.906760, 121.780443, 1064.743642, -690.941426, 1095.704475};

		FdoMultiPoint = sampleGeometryFactory->CreateMultiPoint(FdoDimensionality_XY, 8, Coordinates); //exterior + collection

		FdoByteArray * geometryByteArray = sampleGeometryFactory->GetFgf(FdoMultiPoint);
		sampleGeometryValue->SetGeometry(geometryByteArray);
		FdoPtr<FdoPropertyValue> sampleGeometryPropertyValue;
		sampleGeometryPropertyValue = FdoPropertyValue::Create(L"Geometry", sampleGeometryValue);
		samplePropertyValues->Add(sampleGeometryPropertyValue);

		FdoPtr<FdoIFeatureReader> ret;
		ret = Insert->Execute();

		int count = 0;
		int SmID;
		int UserID;
		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_MultiPoint == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_EQUAL( 1, count );
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

void SuperMapInsertTest::insert_text()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"文本");

		//设置UserID属性字段
		FdoPtr<FdoPropertyValueCollection> samplePropertyValues;
		samplePropertyValues = Insert->GetPropertyValues();
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

		FdoPtr<FdoIFeatureReader> ret;
		ret = Insert->Execute();

		int count = 0;
		int SmID;
		int UserID;
		FdoString *Text;
		double TextSize;
		FdoPtr<FdoByteArray> geometry;

		try
		{
			while (ret->ReadNext ())
			{
				count++;
				if(!ret->IsNull(L"SmID"))
				{
					SmID = ret->GetInt32 (L"SmID");
				}
				if(!ret->IsNull(L"SmUserID"))
				{
					UserID = ret->GetInt32 (L"SmUserID");
				}
				if(!ret->IsNull(L"TxtString"))
				{
					Text = ret->GetString (L"TxtString");
				}
				if(!ret->IsNull(L"TextSize"))
				{
					TextSize = ret->GetDouble (L"TextSize");
				}
				if(!ret->IsNull(L"Geometry"))
				{
					geometry = ret->GetGeometry (L"Geometry");
				}
				CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Point == *(int*)geometry->GetData());
			}
			CPPUNIT_ASSERT_EQUAL( 1, count );
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

void SuperMapInsertTest::insert_no_featureclass()
{
 	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIInsert> Insert;
	Insert = (FdoIInsert *)m_connection->CreateCommand(FdoCommandType_Insert);
	if(NULL != Insert)
	{
		Insert->SetFeatureClassName(L"");

		FdoPtr<FdoIFeatureReader> ret;
		try
		{
			ret = Insert->Execute();
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

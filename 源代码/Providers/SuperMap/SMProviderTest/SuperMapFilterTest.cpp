#include "StdAfx.h"
#include "SuperMapFilterTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapFilterTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapFilterTest::m_connection = NULL;

SuperMapFilterTest::SuperMapFilterTest(void)
{

}

SuperMapFilterTest::~SuperMapFilterTest(void)
{

}

void SuperMapFilterTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection();
	}
}

void SuperMapFilterTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}
//test = 、>、 <、 <>
void SuperMapFilterTest::testComparisonCondition()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	//test equal
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID = 21")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
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

	//test less than
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID < 21")));
	FdoPtr<FdoIFeatureReader> retless;
	try
	{
		retless = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retless != NULL);
	count = 0;
	try
	{
		while (retless->ReadNext ())
		{
			count++;
			if(!retless->IsNull(L"SmID"))
			{
				SmID = retless->GetInt32 (L"SmID");
			}
			if(!retless->IsNull(L"SmUserID"))
			{
				UserID = retless->GetInt32 (L"SmUserID");
			}
			if(!retless->IsNull(L"Geometry"))
			{
				geometry = retless->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 4, count );
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

	//test greater than
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID < 21")));
	FdoPtr<FdoIFeatureReader> retgreater;
	try
	{
		retgreater = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retgreater != NULL);
	count = 0;
	try
	{
		while (retgreater->ReadNext ())
		{
			count++;
			if(!retgreater->IsNull(L"SmID"))
			{
				SmID = retgreater->GetInt32 (L"SmID");
			}
			if(!retgreater->IsNull(L"SmUserID"))
			{
				UserID = retgreater->GetInt32 (L"SmUserID");
			}
			if(!retgreater->IsNull(L"Geometry"))
			{
				geometry = retgreater->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 4, count );
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


	//test not equal
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID <> 21")));
	FdoPtr<FdoIFeatureReader> retnotequal;
	try
	{
		retnotequal = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retnotequal != NULL);
	count = 0;
	try
	{
		while (retnotequal->ReadNext ())
		{
			count++;
			if(!retnotequal->IsNull(L"SmID"))
			{
				SmID = retnotequal->GetInt32 (L"SmID");
			}
			if(!retnotequal->IsNull(L"SmUserID"))
			{
				UserID = retnotequal->GetInt32 (L"SmUserID");
			}
			if(!retnotequal->IsNull(L"Geometry"))
			{
				geometry = retnotequal->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 9, count );
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

	//test LIKE
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"TestString LIKE '中国'")));
	FdoPtr<FdoIFeatureReader> retlike;
	try
	{
		retlike = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retnotequal != NULL);
	count = 0;
	try
	{
		while (retlike->ReadNext ())
		{
			count++;
			if(!retlike->IsNull(L"SmID"))
			{
				SmID = retlike->GetInt32 (L"SmID");
			}
			if(!retlike->IsNull(L"SmUserID"))
			{
				UserID = retlike->GetInt32 (L"SmUserID");
			}
			if(!retlike->IsNull(L"Geometry"))
			{
				geometry = retlike->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
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
//test in
void SuperMapFilterTest::testInCondition()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID in (16,18,19,20)")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 4, count );
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
//test null
void SuperMapFilterTest::testNullCondition()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"TestDate NULL")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 7, count );
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
//test spatial
void SuperMapFilterTest::testSpatialCondition()
{
	//test line
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"Geometry INTERSECTS GeomFromText('LINESTRING XYZ (-723.301911 1810.068614 0, 225.307736 682.578291 0)')")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
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

	//test polygon
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"Geometry INTERSECTS GeomFromText('POLYGON XYZ ((-202.921762 514.538868 0, -528.159355 132.926759 0, 288.187004 210.983781 0, 219.887109 609.521269 0, -202.921762 514.538868 0))')")));
	FdoPtr<FdoIFeatureReader> retpolygon;
	try
	{
		retpolygon = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retpolygon != NULL);
	count = 0;
	try
	{
		while (retpolygon->ReadNext ())
		{
			count++;
			if(!retpolygon->IsNull(L"SmID"))
			{
				SmID = retpolygon->GetInt32 (L"SmID");
			}
			if(!retpolygon->IsNull(L"SmUserID"))
			{
				UserID = retpolygon->GetInt32 (L"SmUserID");
			}
			if(!retpolygon->IsNull(L"Geometry"))
			{
				geometry = retpolygon->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 6, count );
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


	//test point
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"Geometry INTERSECTS GeomFromText('MULTIPOINT XYZ (49.679436 235.918663 0)')")));
	FdoPtr<FdoIFeatureReader> retpoint;
	try
	{
		retpoint = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retpoint != NULL);
	count = 0;
	try
	{
		while (retpoint->ReadNext ())
		{
			count++;
			if(!retpoint->IsNull(L"SmID"))
			{
				SmID = retpoint->GetInt32 (L"SmID");
			}
			if(!retpoint->IsNull(L"SmUserID"))
			{
				UserID = retpoint->GetInt32 (L"SmUserID");
			}
			if(!retpoint->IsNull(L"Geometry"))
			{
				geometry = retpoint->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("查询要素成功", 0 == count);
		CPPUNIT_ASSERT_EQUAL( 0, count );
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
//test or/and
void SuperMapFilterTest::testBinaryLogicalOperator()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	//test and
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"TestDate NULL and TestString LIKE '中国'")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
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

	//test or
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"SmID = 21 or TestBoolen = true")));
	FdoPtr<FdoIFeatureReader> retor;
	try
	{
		retor = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retor != NULL);
	count = 0;
	try
	{
		while (retor->ReadNext ())
		{
			count++;
			if(!retor->IsNull(L"SmID"))
			{
				SmID = retor->GetInt32 (L"SmID");
			}
			if(!retor->IsNull(L"SmUserID"))
			{
				UserID = retor->GetInt32 (L"SmUserID");
			}
			if(!retor->IsNull(L"Geometry"))
			{
				geometry = retor->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 3, count );
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
//test not null、not in
void SuperMapFilterTest::testUnaryLogicalOperator()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoISelect> Select;
	Select = (FdoISelect *)m_connection->CreateCommand(FdoCommandType_Select);
	Select->SetFeatureClassName(L"面");
	
	//test not NULL 
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"NOT TestDate NULL")));

	FdoPtr<FdoIFeatureReader> ret;
	try
	{
		ret = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", ret != NULL);
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
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 3, count );
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

	//test not IN
	Select->SetFilter(FdoPtr<FdoFilter>(FdoFilter::Parse(L"NOT SmID in (16,18,19,20)")));
	FdoPtr<FdoIFeatureReader> retnotin;
	try
	{
		retnotin = Select->Execute();
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
	CPPUNIT_ASSERT_MESSAGE("返回的要素集合为空!", retnotin != NULL);
	count = 0;
	try
	{
		while (retnotin->ReadNext ())
		{
			count++;
			if(!retnotin->IsNull(L"SmID"))
			{
				SmID = retnotin->GetInt32 (L"SmID");
			}
			if(!retnotin->IsNull(L"SmUserID"))
			{
				UserID = retnotin->GetInt32 (L"SmUserID");
			}
			if(!retnotin->IsNull(L"Geometry"))
			{
				geometry = retnotin->GetGeometry (L"Geometry");
			}
			CPPUNIT_ASSERT_MESSAGE ("几何对象类型不正确", FdoGeometryType_Polygon == *(int*)geometry->GetData());
		}
		CPPUNIT_ASSERT_MESSAGE ("未查出点数据集中的要素", 0 != count);
		CPPUNIT_ASSERT_EQUAL( 6, count );
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
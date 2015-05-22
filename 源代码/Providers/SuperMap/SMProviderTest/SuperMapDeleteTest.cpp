#include "StdAfx.h"
#include "SuperMapDeleteTest.h"
#include "SMProviderSuite.h"
#include "FDOConnection.h"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(SuperMapDeleteTest, SPT::SMProvideSuiteName());

FdoPtr<FdoIConnection> SuperMapDeleteTest::m_connection = NULL;

SuperMapDeleteTest::SuperMapDeleteTest(void)
{

}

SuperMapDeleteTest::~SuperMapDeleteTest(void)
{

}

void SuperMapDeleteTest::setUp ()
{
	if(m_connection == NULL)
	{
		m_connection = GetFDOConnection();
	}
}
void SuperMapDeleteTest::tearDown ()
{
	if(NULL != m_connection)
	{
		m_connection->Close();
		m_connection = NULL;
	}
}

void SuperMapDeleteTest::delete_point()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"点");

		FdoString *strFilter = L"SmID = 13 and SmUserID = 0";
		Delete->SetFilter( strFilter );

		int nDelNum = 0;
		nDelNum = Delete->Execute();
		CPPUNIT_ASSERT_EQUAL( 1, nDelNum );
	}
}

void SuperMapDeleteTest::delete_line()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"线");

		FdoString *strFilter = L"SmID = 39 or SmUserID > 5";
		Delete->SetFilter( strFilter );

		int nDelNum = 0;
		nDelNum = Delete->Execute();
		CPPUNIT_ASSERT_EQUAL( 1, nDelNum );
	}

}

void SuperMapDeleteTest::delete_region()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"面");

		FdoString *strFilter = L"SmID = 27 and SmUserID = 0";
		Delete->SetFilter( strFilter );

		int nDelNum = 0;
		nDelNum = Delete->Execute();
		CPPUNIT_ASSERT_EQUAL( 1, nDelNum );
	}
}

void SuperMapDeleteTest::delete_cad()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"NEW_CAD");

		FdoString *strFilter = L"SmID = 17";
		Delete->SetFilter( strFilter );

		int nDelNum = 0;
		nDelNum = Delete->Execute();
		CPPUNIT_ASSERT_EQUAL( 1, nDelNum );
	}
}

void SuperMapDeleteTest::delete_text()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"文本");

		FdoString *strFilter = L"SmID = 1";
		Delete->SetFilter( strFilter );

		int nDelNum = 0;
		nDelNum = Delete->Execute();
		CPPUNIT_ASSERT_EQUAL( 1, nDelNum );
	}
}

void SuperMapDeleteTest::delete_no_featureclass()
{
	CPPUNIT_ASSERT_MESSAGE("FDO连接未打开!", m_connection != NULL);
	CPPUNIT_ASSERT_MESSAGE("FDO连接引用次数不为1!", m_connection->GetRefCount() == 1);

	FdoPtr<FdoIDelete> Delete;
	Delete = (FdoIDelete *)m_connection->CreateCommand(FdoCommandType_Delete);
	if(NULL != Delete)
	{
		Delete->SetFeatureClassName(L"");
		int nDelNum = 0;
		try
		{
			nDelNum = Delete->Execute();
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

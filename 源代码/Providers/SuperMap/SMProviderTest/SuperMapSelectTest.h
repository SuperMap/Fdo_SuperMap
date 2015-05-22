#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SuperMapSelectTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapSelectTest);

	CPPUNIT_TEST(select_point);
	CPPUNIT_TEST(select_line);
	CPPUNIT_TEST(select_region);
	CPPUNIT_TEST(select_cad);
	CPPUNIT_TEST(select_text);
	CPPUNIT_TEST(select_sdb_boolean);
	CPPUNIT_TEST(select_sdb_date);
	CPPUNIT_TEST(select_no_featureclass);
	
	CPPUNIT_TEST_SUITE_END();
public:
	SuperMapSelectTest(void);
	void setUp ();

public:
	~SuperMapSelectTest(void);
	void tearDown ();

protected:
	void select_point();
	void select_line();
	void select_region();
	void select_cad();
	void select_text();
	void select_sdb_boolean();
	void select_sdb_date();
	void select_no_featureclass();

private:
	int GetRecordCount(char *strDataset, char *strFilter);

private:
	static FdoPtr<FdoIConnection> m_connection;
};

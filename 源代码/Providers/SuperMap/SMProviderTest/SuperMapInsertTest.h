#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SuperMapInsertTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapInsertTest);
	
	CPPUNIT_TEST(insert_point);
	CPPUNIT_TEST(insert_line);
	CPPUNIT_TEST(insert_region);
	CPPUNIT_TEST(insert_cad);
	CPPUNIT_TEST(insert_text);
	CPPUNIT_TEST(insert_no_featureclass);
	
	CPPUNIT_TEST_SUITE_END();

public:
	SuperMapInsertTest(void);
	void setUp ();

public:
	~SuperMapInsertTest(void);
	void tearDown ();

protected:
	void insert_point();
	void insert_line();
	void insert_region();
	void insert_cad();
	void insert_text();
	void insert_no_featureclass();

private:
	static FdoPtr<FdoIConnection> m_connection;
};

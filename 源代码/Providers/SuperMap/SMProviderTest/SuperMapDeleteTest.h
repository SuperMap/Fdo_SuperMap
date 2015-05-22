#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SuperMapDeleteTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapDeleteTest);

	CPPUNIT_TEST(delete_point);
	CPPUNIT_TEST(delete_line);
	CPPUNIT_TEST(delete_region);
	CPPUNIT_TEST(delete_cad);
	CPPUNIT_TEST(delete_text);
	CPPUNIT_TEST(delete_no_featureclass);

	CPPUNIT_TEST_SUITE_END();
public:
	SuperMapDeleteTest(void);
	void setUp ();

public:
	~SuperMapDeleteTest(void);
	void tearDown ();

protected:
	void delete_point();
	void delete_line();
	void delete_region();
	void delete_cad();
	void delete_text();
	void delete_no_featureclass();

private:
	static FdoPtr<FdoIConnection> m_connection;
};

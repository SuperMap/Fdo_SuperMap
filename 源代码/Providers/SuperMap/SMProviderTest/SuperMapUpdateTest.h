#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;


class SuperMapUpdateTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapUpdateTest);

	CPPUNIT_TEST(update_point);
	CPPUNIT_TEST(update_line);
	CPPUNIT_TEST(update_region);
	CPPUNIT_TEST(update_cad);
	CPPUNIT_TEST(update_text);
	CPPUNIT_TEST(update_no_featureclass);
	
	CPPUNIT_TEST_SUITE_END();

public:
	SuperMapUpdateTest(void);
	void setUp ();

public:
	~SuperMapUpdateTest(void);
	void tearDown ();

protected:
	void update_point();
	void update_line();
	void update_region();
	void update_cad();
	void update_text();
	void update_no_featureclass();

private:
	static FdoPtr<FdoIConnection> m_connection;
};

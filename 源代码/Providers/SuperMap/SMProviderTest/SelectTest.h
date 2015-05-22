#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SelectTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SelectTest);

	CPPUNIT_TEST(select_point);
	CPPUNIT_TEST(select_point_no_featureclass);
	CPPUNIT_TEST(select_region);
	CPPUNIT_TEST(select_region_no_featureclass);

	CPPUNIT_TEST_SUITE_END();
public:
	SelectTest(void);
public:
	~SelectTest(void);
	void setUp ();
	void tearDown ();
protected:
	void select_region();
	void select_region_no_featureclass();
	void select_point();
	void select_point_no_featureclass();
private:
	static FdoPtr<FdoIConnection> m_connection;
};

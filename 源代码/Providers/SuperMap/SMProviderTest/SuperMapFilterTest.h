#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SuperMapFilterTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapFilterTest);

	CPPUNIT_TEST(testComparisonCondition);
	CPPUNIT_TEST(testInCondition);
	CPPUNIT_TEST(testNullCondition);
	CPPUNIT_TEST(testSpatialCondition);
	CPPUNIT_TEST(testBinaryLogicalOperator);
	CPPUNIT_TEST(testUnaryLogicalOperator);

	CPPUNIT_TEST_SUITE_END();

public:
	SuperMapFilterTest(void);
	void setUp ();

public:
	~SuperMapFilterTest(void);
	void tearDown ();

protected:
	void testComparisonCondition();
	void testInCondition();
	void testNullCondition();
	void testSpatialCondition();
	void testBinaryLogicalOperator();
	void testUnaryLogicalOperator();

private:
	static FdoPtr<FdoIConnection> m_connection;

};

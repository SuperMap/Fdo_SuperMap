#pragma once

#include "cppunit/extensions/HelperMacros.h"
class FdoIConnection;
template <class T> class FdoPtr;

class SuperMapRasterTest :public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(SuperMapRasterTest);

	CPPUNIT_TEST(select_raster_1bit);
	CPPUNIT_TEST(select_raster_4bit);
	CPPUNIT_TEST(select_raster_8bit);
	CPPUNIT_TEST(select_raster_16bit);
	CPPUNIT_TEST(select_raster_24bit);
	CPPUNIT_TEST(select_raster_32bit);
	
	CPPUNIT_TEST_SUITE_END();

public:
	SuperMapRasterTest(void);
	void setUp ();

public:
	~SuperMapRasterTest(void);
	void tearDown ();

protected:
	void select_raster_1bit();
	void select_raster_4bit();
	void select_raster_8bit();
	void select_raster_16bit();
	void select_raster_24bit();
	void select_raster_32bit();

private:
	static FdoPtr<FdoIConnection> m_connection;
};

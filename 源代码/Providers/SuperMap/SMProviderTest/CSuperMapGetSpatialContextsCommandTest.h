/** \file	 CSuperMapGetSpatialContextsCommandTest.h
*  \brief    负责对SuperMapGetSpatialContextsCommand及空间语义相关类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-19
*  \note :
*/

#ifndef __SUPERMAP_GET_SPATIAL_CONTEXTS_COMMAND_TEST_H__
#define __SUPERMAP_GET_SPATIAL_CONTEXTS_COMMAND_TEST_H__

#include "cppunit/extensions/HelperMacros.h"

class FdoIConnection;
template <class T> class FdoPtr;

class CSuperMapGetSpatialContextsCommandTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CSuperMapGetSpatialContextsCommandTest);
 
	CPPUNIT_TEST(testExecute1);
	CPPUNIT_TEST(testExecute2);
	CPPUNIT_TEST(testExecute3);
	
	CPPUNIT_TEST_SUITE_END();

	static FdoPtr<FdoIConnection> m_connection;

public:
	CSuperMapGetSpatialContextsCommandTest();
	~CSuperMapGetSpatialContextsCommandTest();
	void setUp();
	void tearDown();

public:
	void testExecute1();
	void testExecute2();
	void testExecute3();

protected:
	FdoIConnection* GetSuperMapConnection();

};

#endif //__SUPERMAP_GET_SPATIAL_CONTEXTS_COMMAND_TEST_H__
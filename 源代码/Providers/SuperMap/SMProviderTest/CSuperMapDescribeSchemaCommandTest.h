/** \file	 CSuperMapDescribeSchemaCommandTest.h
*  \brief    负责对SuperMapDescribeSchemaCommand类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#ifndef __SUPERMAP_DESCRIBE_SCHEMA_COMMAND_TEST_H__
#define __SUPERMAP_DESCRIBE_SCHEMA_COMMAND_TEST_H__

#include "cppunit/extensions/HelperMacros.h"

class FdoIConnection;
template <class T> class FdoPtr;

class CSuperMapDescribeSchemaCommandTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CSuperMapDescribeSchemaCommandTest);
 
	CPPUNIT_TEST(testExecute1);
	CPPUNIT_TEST(testExecute2);
	CPPUNIT_TEST(testExecute3);
	CPPUNIT_TEST(testExecute4);
	CPPUNIT_TEST(testExecute5);

	CPPUNIT_TEST_SUITE_END();

	static FdoPtr<FdoIConnection> m_connection;

public:
	CSuperMapDescribeSchemaCommandTest();
	~CSuperMapDescribeSchemaCommandTest();
	void setUp();
	void tearDown();

public:
	void testExecute1();
	void testExecute2();
	void testExecute3();
	void testExecute4();
	void testExecute5();

protected:
	FdoIConnection* GetSuperMapConnection();

};

#endif //__SUPERMAP_DESCRIBE_SCHEMA_COMMAND_TEST_H__
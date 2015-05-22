
/** \file	 CSuperMapConnectionTest.h
*  \brief    负责对SuperMapConnection类进行单元测试
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-17
*  \note :
*/

#ifndef __SUPERMAP_CONNECTION_TEST_H__
#define __SUPERMAP_CONNECTION_TEST_H__

#include "cppunit/extensions/HelperMacros.h"

class FdoIConnection;
template <class T> class FdoPtr;

class CSuperMapConnectionTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CSuperMapConnectionTest);
	//CPPUNIT_TEST(connect);
	//CPPUNIT_TEST(cnnect2);
	//CPPUNIT_TEST(connect3);
	//CPPUNIT_TEST(testSetConnectionString);
	//CPPUNIT_TEST(testOpen);

	//from 2007-12-17
	CPPUNIT_TEST(testConnect);
	CPPUNIT_TEST(testSetConnectionString);

	CPPUNIT_TEST_SUITE_END();

	static FdoPtr<FdoIConnection> m_connection;

public:
	CSuperMapConnectionTest();
	virtual ~CSuperMapConnectionTest();
	void setUp();
	void tearDown();

public:
	//测试连接的状态设置及打开操作是否正常
	//void connect();
	//测试连接的状态设置及关闭操作是否正常
	//void connect2();
	//测试通过连接类从物理数据源建立逻辑模式是否正确。
	//void connect3();

	// 重点函数测试
	//void testSetConnectionString();
	//void testOpen();

	//from 2007-12-17
	// 对连接类的基本功能进行测试
	void testConnect();

	/// <summary>Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
	/// connection is closed.</summary>
	/// <param name="value">Input the connection string</param> 
	/// <returns>Returns nothing</returns> 
	/// void SetConnectionString (FdoString* value);
    void testSetConnectionString();
	

protected:
	// 获取SuperMapProvider的连接
	FdoIConnection* GetSuperMapConnection(); 
	

};

#endif //__SUPERMAP_CONNECTION_TEST_H__

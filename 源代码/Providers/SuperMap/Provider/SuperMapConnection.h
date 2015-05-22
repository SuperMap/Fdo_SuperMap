
/** \file	 SuperMapConnection.h
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*  \note : modified by zhouxu 2007-10-23
*/


#ifndef __SUPERMAP_CONNECTION_H__
#define __SUPERMAP_CONNECTION_H__

#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <FdoCommonThreadMutex.h>
#include "UGC.h"

class SuperMapLpFeatureSchemaCollection;
class SuperMapSpatialContextCollection;
class SuperMapTransaction;

class SuperMapConnection : public FdoIConnection
{
public:

	SuperMapConnection (void);
	virtual ~SuperMapConnection(void);

	// FdoIDisposable interface

	// <summary>Dispose this object.</summary>
	// <returns>Returns nothing</returns> 
	void Dispose ();
		
	// FdoIConnection overrides

	/// <summary>Gets an FdoIConnectionCapabilities interface describing the capabilities
	/// of the connection.</summary>
	/// <returns>Returns the connection capabilities</returns> 
	FdoIConnectionCapabilities* GetConnectionCapabilities ();

	/// <summary>Gets an FdoISchemaCapabilities interface describing the provider's support for the feature schema.</summary>
	/// <returns>Returns schema capabilities</returns> 
	FdoISchemaCapabilities* GetSchemaCapabilities ();

	/// <summary>Gets an FdoICommandCapabilities interface describing the commands a provider supports.</summary>
	/// <returns>Returns the command capabilities</returns> 
	FdoICommandCapabilities* GetCommandCapabilities ();

	/// <summary>Gets an FdoIFilterCapabilities interface describing the provider's support for filters.</summary>
	/// <returns>Returns the filter capabilities</returns> 
	FdoIFilterCapabilities* GetFilterCapabilities ();

	/// <summary>Gets an FdoIExpressionCapabilities interface describing the provider's support for expressions.</summary>
	/// <returns>Returns the expression capabilities</returns> 
	FdoIExpressionCapabilities* GetExpressionCapabilities ();

	/// <summary>Gets an FdoIRasterCapabilities interface describing the provider's support for raster images.</summary>
	/// <returns>Returns the raster capabilities</returns> 
	FdoIRasterCapabilities* GetRasterCapabilities ();

	/// <summary>Gets an FdoITopologyCapabilities interface describing the provider's support for topology.</summary>
	/// <returns>Returns the topology capabilities</returns> 
	FdoITopologyCapabilities* GetTopologyCapabilities ();

	/// <summary>Gets an FdoIGeometryCapabilities interface describing the provider's support for geometry.</summary>
	/// <returns>Returns the geometry capabilities</returns> 
	virtual FdoIGeometryCapabilities* GetGeometryCapabilities();

	/// <summary>Gets the connection string used to open a DataStore.</summary>
	/// <returns>Returns the connection string</returns> 
	FdoString* GetConnectionString ();

	/// <summary>Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
	/// connection is closed.</summary>
	/// <param name="value">Input the connection string</param> 
	/// <returns>Returns nothing</returns> 
	void SetConnectionString (FdoString* value);

	/// <summary>Gets an FdoIConnectionInfo interface that can be used to interrogate and set connection properties.</summary>
	/// <returns>Returns the connection info</returns> 
	FdoIConnectionInfo* GetConnectionInfo ();

	/// <summary>Gets the current state of the connection.</summary>
	/// <returns>Returns the current state of the connection</returns> 
	FdoConnectionState GetConnectionState ();

	/// <summary>Gets the number of milliseconds to wait while trying to establish a
	/// connection before terminating the attempt and generating an error. If
	/// the provider does not support the timeout capability 0 will be returned</summary>
	/// <returns>Returns the time to wait (in milliseconds)</returns> 
	FdoInt32 GetConnectionTimeout ();

	/// <summary>Sets the number of milliseconds to wait while trying to establish a
	/// connection before terminating the attempt and generating an error. If
	/// the provider does not support the timeout capability then attempting to
	/// set a timeout will result in an exception</summary>
	/// <param name="value">Input the time to wait (in milliseconds)</param> 
	/// <returns>Returns nothing</returns> 
	void SetConnectionTimeout (FdoInt32 value);

	/// <summary>Opens a feature connection with the settings specified by the
	/// ConnectionString attribute of the provider-specific feature connection
	/// object.</summary>
	/// <returns>Returns nothing</returns> 
	FdoConnectionState Open ();

	/// <summary>Closes the connection to the DataStore</summary>
	/// <returns>Returns nothing</returns> 
	void Close ();

	/// <summary>Begins a transaction and returns an object that realizes
	/// FdoITransaction.</summary>
	/// <returns>Returns the transaction</returns> 
	FdoITransaction* BeginTransaction ();
	void EndTransaction ();

	/// <summary>Creates and returns the specified type of command object associated with
	/// the connection.</summary>
	/// <param name="commandType">Input the command type to be created</param> 
	/// <returns>Returns the command</returns> 
	FdoICommand* CreateCommand (FdoInt32 commandType);

	/// <summary>Factory function that creates an empty Schema Override set specific
	/// to this FDO Provider.</summary>
	/// <returns>Returns FdoPhysicalSchemaMapping</returns> 
	FdoPhysicalSchemaMapping* CreateSchemaMapping();

	/// <summary>Sets the XML configuration stream used to configure the Data Store. 
	/// SetConfiguration can only be called while the connection is closed.</summary>
	/// <param name="configStream">Input the XML configuration stream</param> 
	/// <returns>Returns nothing</returns> 
	void SetConfiguration(FdoIoStream* configStream);

	/// <summary>Forces the writes of any cached data to the targed datastore.</summary>
	/// <returns> Returns nothing </returns>
	/// 
	void Flush();

	////////////////////////////////////////////////////////////////////////
    // Non-published schema management APIs:
    ////////////////////////////////////////////////////////////////////////

	//! \biref		获取SuperMap数据源指针
	//! \return		返回UGDataSouce抽象基类指针
	//! \param		无
	UGC::UGDataSource* GetDataSource();

 	//! \biref		判断是否影像模式连接
	//! \return		返回bool型
	//! \param		无
	bool IsOnlyConnectImage();  

	//! \biref		获取模式数据源转换类指针
	//! \return		返回模式数据源转换集合类指针
	//! \param		无
	SuperMapLpFeatureSchemaCollection* GetLpSchemas();

	//! \biref		从数据源获取空间语义
	//! \return		返回空间语义列表集合（一般情况，一个物理数据源只对应一个空间语义信息）
	//! \param		无
	SuperMapSpatialContextCollection* GetSpatialContexts();

	//! \biref		创建空间语义
	//! \return		void型
	//! \param		name 空间语义名称
	//! \param		description 空间语义描述信息
	//! \param		coordinateSystem 坐标系名称
	//! \param		coordinateSystemWkt 空间语义的WKT串信息
	//! \param		extentType 空间语义范围类型
	//! \param		extent FdoByteArray指针类型的空间语义范围
	//! \param		xyTolerance XY方向上的误差容限
	//! \param		zTolerance 方向上的误差容限
	//! \param		bool型 是否是更新
	void CreateSpatialContext(
								FdoString* name,
								FdoString* description,
								FdoString* coordinateSystem,
								FdoString* coordinateSystemWkt,
								FdoSpatialContextExtentType extentType,
								FdoByteArray * extent,
								double xyTolerance,
								double zTolerance,
								bool   update
							);

	//! \brief		设置创建SDB标志
	//! \param		bCreate bool型
	void SetCreateSDB(bool bCreate = true){m_bCreate = bCreate;};
private:


protected:
	/**
	* The connection string containing details about how to connect to Shp.
	*/
	FdoStringP m_ConnectionString;

	/**
	* The connection state (closed, pending, open).
	*/
	FdoConnectionState m_ConnectionState;

	/**
	* Connection information object.
	*/
	FdoPtr<FdoIConnectionInfo> m_ConnectionInfo;

	/*
	* The current transaction.
	*/
	//SuperMapTransaction* m_pTransaction; // can't use FdoPtr<> because of circular reference
protected:
	/**
	* 管理连接打开的SuperMap数据源
	*/
	//UGC::UGDataSource* m_pDataSource;
	std::string m_strConnectionSession;
		
	/**
	* 存储SuperMap数据源到FDO逻辑模式的转换定义
	*/
	FdoPtr<SuperMapLpFeatureSchemaCollection> m_LpSchemas;

	/**
     *  存空间语义列表（通常只有一个成员）
     */
	FdoPtr<SuperMapSpatialContextCollection> m_SpatialContextColl;

	/**
     *  是否为创建SDB文件
     */
	bool m_bCreate;
};

#endif // __SUPERMAP_CONNECTION_H__

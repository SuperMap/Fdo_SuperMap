#ifndef _ICONNECTION_H_
#define _ICONNECTION_H_
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Commands/ICommand.h>
#include <Fdo/Commands/Schema/PhysicalSchemaMapping.h>
#include <Fdo/Connections/ConnectionException.h>
#include <Fdo/Connections/ConnectionState.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Connections/IConnectionInfo.h>
#include <Fdo/Connections/IConnectionPropertyDictionary.h>
#include <Fdo/Connections/ITransaction.h>
#include <Fdo/Connections/Capabilities/ArgumentDefinition.h>
#include <Fdo/Connections/Capabilities/FunctionDefinition.h>
#include <Fdo/Connections/Capabilities/ICommandCapabilities.h>
#include <Fdo/Connections/Capabilities/IConnectionCapabilities.h>
#include <Fdo/Connections/Capabilities/IExpressionCapabilities.h>
#include <Fdo/Connections/Capabilities/IFilterCapabilities.h>
#include <Fdo/Connections/Capabilities/ISchemaCapabilities.h>
#include <Fdo/Connections/Capabilities/ThreadCapability.h>
#include <Fdo/Connections/Capabilities/IRasterCapabilities.h>
#include <Fdo/Connections/Capabilities/ITopologyCapabilities.h>
#include <Fdo/Connections/Capabilities/IGeometryCapabilities.h>

class FdoICommand;

/// \brief
/// The FdoIConnection interface enables a feature provider to implement a
/// connection class, which represents a unique session with a data
/// store.
class FdoIConnection : public FdoIDisposable
{
public:
    /// \brief
    /// Gets an FdoIConnectionCapabilities interface describing the capabilities
    /// of the connection.
    /// 
    /// \return
    /// Returns the connection capabilities
    /// 
    FDO_API virtual FdoIConnectionCapabilities* GetConnectionCapabilities() = 0;

    /// \brief
    /// Gets an FdoISchemaCapabilities interface describing the provider's support for the feature schema.
    /// 
    /// \return
    /// Returns schema capabilities
    /// 
    FDO_API virtual FdoISchemaCapabilities* GetSchemaCapabilities() = 0;

    /// \brief
    /// Gets an FdoICommandCapabilities interface describing the commands a provider supports.
    /// 
    /// \return
    /// Returns the command capabilities
    /// 
    FDO_API virtual FdoICommandCapabilities* GetCommandCapabilities() = 0;

    /// \brief
    /// Gets an FdoIFilterCapabilities interface describing the provider's support for filters.
    /// 
    /// \return
    /// Returns the filter capabilities
    /// 
    FDO_API virtual FdoIFilterCapabilities* GetFilterCapabilities() = 0;

    /// \brief
    /// Gets an FdoIExpressionCapabilities interface describing the provider's support for expressions.
    /// 
    /// \return
    /// Returns the expression capabilities
    /// 
    FDO_API virtual FdoIExpressionCapabilities* GetExpressionCapabilities() = 0;

    /// \brief
    /// Gets an FdoIRasterCapabilities interface describing the provider's support for raster images.
    /// 
    /// \return
    /// Returns the raster capabilities
    /// 
    FDO_API virtual FdoIRasterCapabilities* GetRasterCapabilities() = 0;

    /// \brief
    /// Gets an FdoITopologyCapabilities interface describing the provider's support for topology.
    /// 
    /// \return
    /// Returns the topology capabilities
    /// 
    FDO_API virtual FdoITopologyCapabilities* GetTopologyCapabilities() = 0;

    /// \brief
    /// Gets an FdoIGeometryCapabilities interface describing the provider's support for geometry.
    /// 
    /// \return
    /// Returns the geometry capabilities
    /// 
    FDO_API virtual FdoIGeometryCapabilities* GetGeometryCapabilities() = 0;

    /// \brief
    /// Gets the connection string used to open a DataStore.
    /// 
    /// \return
    /// Returns the connection string
    /// 
    FDO_API virtual FdoString* GetConnectionString() = 0;

    /// \brief
    /// Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
    /// connection is closed.
    /// 
    /// \param value 
    /// Input the connection string
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetConnectionString(FdoString* value) = 0;

    /// \brief
    /// Gets an FdoIConnectionInfo interface that can be used to interrogate and set connection properties.
    /// 
    /// \return
    /// Returns the connection info
    /// 
    FDO_API virtual FdoIConnectionInfo* GetConnectionInfo() = 0;

    /// \brief
    /// Gets the current state of the connection.
    /// 
    /// \return
    /// Returns the current state of the connection
    /// 
    FDO_API virtual FdoConnectionState GetConnectionState() = 0;

    /// \brief
    /// Gets the number of milliseconds to wait while trying to establish a
    /// connection before terminating the attempt and generating an error. If
    /// the provider does not support the timeout capability 0 will be returned
    /// 
    /// \return
    /// Returns the time to wait (in milliseconds)
    /// 
    FDO_API virtual FdoInt32 GetConnectionTimeout() = 0;

    /// \brief
    /// Sets the number of milliseconds to wait while trying to establish a
    /// connection before terminating the attempt and generating an error. If
    /// the provider does not support the timeout capability then attempting to
    /// set a timeout will result in an exception
    /// 
    /// \param value 
    /// Input the time to wait (in milliseconds)
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetConnectionTimeout(FdoInt32 value) = 0;

    /// \brief
    /// Opens a feature connection with the settings specified by the
    /// ConnectionString attribute of the provider-specific feature connection
    /// object.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoConnectionState Open() = 0;

    /// \brief
    /// Closes the connection to the DataStore
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;

    /// \brief
    /// Begins a transaction and returns an object that realizes
    /// FdoITransaction.
    /// 
    /// \return
    /// Returns the transaction
    /// 
    FDO_API virtual FdoITransaction* BeginTransaction() = 0;

    /// \brief
    /// Creates and returns the specified type of command object associated with
    /// the connection.
    /// 
    /// \param commandType 
    /// Input the command type to be created
    /// 
    /// \return
    /// Returns the command
    /// 
    FDO_API virtual FdoICommand* CreateCommand(FdoInt32 commandType) = 0;

    /// \brief
    /// Factory function that creates an empty Schema Override set specific
    /// to this FDO Provider.
    /// 
    /// \return
    /// Returns FdoPhysicalSchemaMapping
    /// 
    FDO_API virtual FdoPhysicalSchemaMapping* CreateSchemaMapping() = 0;

    /// \brief
    /// Sets the XML configuration stream used to configure the Data Store. 
    /// SetConfiguration can only be called while the connection is closed.
    /// 
    /// \param configStream 
    /// Input the XML configuration stream
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetConfiguration(FdoIoStream* configStream) = 0;

    /// \brief
    /// Forces the writes of any cached data to the targed datastore.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Flush() = 0;
};
#endif



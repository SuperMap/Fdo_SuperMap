#ifndef _IDESCRIBESCHEMAMAPPING_H_
#define _IDESCRIBESCHEMAMAPPING_H_
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
#include <Fdo/Commands/Schema/PhysicalSchemaMappingCollection.h>
#include <Fdo/Connections/IConnection.h>

/// \brief
/// The FdoIDescribeSchemaMapping interface defines the DescribeSchemaMapping command, which
/// describes the logical to physical schema mappings for feature schemas 
/// available from the connection. The DescribeSchemaMapping
/// command can describe the mappings for a single schema or all schemas available from
/// the connection. The Execute operation returns an FdoPhysicalSchemaMappingCollection
/// object.
class FdoIDescribeSchemaMapping : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the schema for which to describe
    /// schema mappings.
    /// 
    /// \return
    /// Returns the schema name
    /// 
    FDO_API virtual FdoString* GetSchemaName() = 0;

    /// \brief
    /// Sets the name of the schema to describe. This function is optional; if not
    /// specified, execution of the command will describe the mappings for
    /// all schemas.
    /// 
    /// \param value 
    /// Input the schema name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetSchemaName(FdoString* value) = 0;

    /// \brief
    /// Gets the current "include default mappings" setting.
    /// 
    /// \return
    /// Returns True if Execute() will include default mappings.
    /// 
    FDO_API virtual FdoBoolean GetIncludeDefaults() = 0;

    /// \brief
    /// Sets the "include default mappings" setting.
    /// 
    /// \param includeDefaults 
    /// Input True: Execute() will return
    /// all mappings for the feature schema(s).
    /// False: Execute() will not include default logical to physical
    /// mappings, only those mappings that have been overridden will 
    /// be returned.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetIncludeDefaults( FdoBoolean includeDefaults ) = 0;

    /// \brief
    /// Executes the DescribeSchemaMapping command and returns a 
    /// FdoPhysicalSchemaMappingCollection. If the specified schema name does not exist,
    /// the Execute method throws an exception.
    /// 
    /// \return
    /// Returns the schema mapping collection for the requested feature schemas.
    /// 
    FDO_API virtual FdoPhysicalSchemaMappingCollection* Execute() = 0;
};
#endif



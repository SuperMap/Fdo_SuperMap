#ifndef _IDESCRIBESCHEMA_H_
#define _IDESCRIBESCHEMA_H_
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
#include <Fdo/Schema/FeatureSchemaCollection.h>
#include <Fdo/Connections/IConnection.h>

/// \brief
/// The FdoIDescribeSchema interface defines the DescribeSchema command, which
/// describes the feature schemas available from the connection. The DescribeSchema
/// command can describe a single schema or all schemas available from
/// the connection. The Execute operation returns an FdoFeatureSchemaCollection
/// object.
class FdoIDescribeSchema : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the schema to describe. This function is optional;
    /// if not specified, execution of the command will describe all schemas.
    /// 
    /// \return
    /// Returns the schema name
    /// 
    FDO_API virtual FdoString* GetSchemaName() = 0;

    /// \brief
    /// Sets the name of the schema to describe. This function is optional; if not
    /// specified execution of the command will describe all schemas.
    /// 
    /// \param value 
    /// Input the schema name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetSchemaName(FdoString* value) = 0;

    /// \brief
    /// Executes the DescribeSchema command and returns a 
    /// FdoFeatureSchemaCollection. If a schema name is given that has 
    /// references to another schema, the dependent schemas will 
    /// be returned as well. If the specified schema name does not exist,
    /// the Execute method throws an exception.
    /// 
    /// \return
    /// Returns the schema collection representing the schema created.
    /// The element states for all elements will be set to FdoSchemaElementState_Unchanged.
    /// Each provider-specific implementation of Execute() can ensure 
    /// that this is the case by 
    /// calling FdoFeatureSchema::AcceptChanges() for each feature schema
    /// in the returned collection.
    /// 
    FDO_API virtual FdoFeatureSchemaCollection* Execute() = 0;
};
#endif



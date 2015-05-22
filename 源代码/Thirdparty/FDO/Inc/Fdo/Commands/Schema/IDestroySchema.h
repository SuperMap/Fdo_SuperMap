#ifndef _IDESTROYSCHEMA_H_
#define _IDESTROYSCHEMA_H_
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

/// \brief
/// The FdoIDestroySchema interface defines the DestroySchema command, which
/// destroys a schema definition, including all class definitions, relationship
/// definitions, and instance data within it. If elements in other schemas refer
/// to the schema to be destroyed command, execution will fail. Input to the
/// delete schema command is the name of the schema to be destroyed.
class FdoIDestroySchema : public FdoICommand
{
  public:
    /// \brief
    /// Gets the name of the schema to destroy as a string.
    /// 
    /// \return
    /// Returns the name of the schema to destroy
    /// 
    FDO_API virtual FdoString* GetSchemaName() = 0;

    /// \brief
    /// Sets the name of the schema to destroy as a string.
    /// 
    /// \param value 
    /// Input the name of the schema to destroy
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetSchemaName(FdoString* value) = 0;

    /// \brief
    /// Executes the destroy schema command, which removes the schema, class
    /// definitions, relation definitions, and all instance data from the DataStore.
    /// If elements in other schemas refer to the schema to be destroyed
    /// an exception is thrown.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



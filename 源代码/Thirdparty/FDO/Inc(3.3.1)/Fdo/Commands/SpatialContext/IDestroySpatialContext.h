#ifndef _IDESTROYSPATIALCONTEXT_H_
#define _IDESTROYSPATIALCONTEXT_H_
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
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIDestroySpatialContext interface defines the DestroySpatialContext
/// command, which destroys an existing spatial context. Input to the command is
/// the name of the context to destroy. Destroying a spatial context destroys
/// all data stored in that context.
class FdoIDestroySpatialContext : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the context to destroy as a string.
    /// 
    /// \return
    /// Returns the name of the spatial context to be deleted
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the context to destroy as a string.
    /// 
    /// \param value 
    /// Input the name of the spatial context to be deleted
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    /// Executes the DestroySpatialContext command, removing all data stored
    /// in that context. An exception is thrown if the spatial context does not exist.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



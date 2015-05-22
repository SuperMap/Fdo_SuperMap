#ifndef _IGETSPATIALCONTEXT_H_
#define _IGETSPATIALCONTEXT_H_
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
#include <Fdo/Commands/SpatialContext/ISpatialContextReader.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIGetSpatialContexts interface defines the GetSpatialContexts command,
/// which enumerates the existing spatial contexts.
class FdoIGetSpatialContexts : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    ///  Gets a Boolean flag that indicates if the GetSpatialContexts command
    /// will return only the active spatial context or all spatial contexts. The
    /// default value of this flag is false, return all spatial contexts.
    /// 
    /// \return
    /// Returns Boolean value
    /// 
    FDO_API virtual const bool GetActiveOnly() = 0;

    /// \brief
    ///  Sets a Boolean flag that indicates if the GetSpatialContexts command
    /// will return only the active spatial context or all spatial contexts. The
    /// default value of this flag is false, return all spatial contexts.
    /// 
    /// \param value 
    /// Input the Boolean flag
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetActiveOnly(const bool value) = 0;

    /// \brief
    /// Executes the GetSpatialContexts command returning an FdoISpatialContextReader.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoISpatialContextReader* Execute() = 0;
};
#endif



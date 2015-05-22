#ifndef _ICREATELONGTRANSACTION_H_
#define _ICREATELONGTRANSACTION_H_
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
/// The FdoICreateLongTransaction interface defines the CreateLongTransaction
/// command which creates a long transaction that is based upon the currently
/// active long transaction. If no long transaction is active, then the long
/// transaction is based upon the root data. Input to the create long
/// transaction command includes a name and description for the new long
/// transaction.
class FdoICreateLongTransaction : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction to create as a string.
    /// 
    /// \return
    /// Returns the name of the long transaction
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the long transaction to create as a string.
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    /// Gets the description of the long transaction to create as a string.
    /// 
    /// \return
    /// Returns the description of the long transaction
    /// 
    FDO_API virtual FdoString* GetDescription() = 0;

    /// \brief
    /// Sets the description of the long transaction to create as a string.
    /// 
    /// \param value 
    /// Input the description of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetDescription(FdoString* value) = 0;

    /// \brief
    /// Executes the create long transaction command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



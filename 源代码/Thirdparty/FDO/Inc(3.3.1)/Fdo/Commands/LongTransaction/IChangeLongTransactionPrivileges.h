#ifndef _ICHANGELONGTRANSACTIONPRIVILEGES_H_
#define _ICHANGELONGTRANSACTIONPRIVILEGES_H_
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
#include <Fdo/Commands/LongTransaction/LongTransactionPrivilegeOperations.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIChangeLongTransactionPrivileges interface defines the
/// ChangeLongTransactionPrivileges command, which grants or revokes long
/// transaction privileges for the named user. The ability to change the 
/// privileges might be restricted by the datastore security if the long 
/// transaction doesn’t belong to the user executing the command.
class FdoIChangeLongTransactionPrivileges : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction for which privileges should be
    /// changed.
    /// 
    /// \return
    /// Returns the name of the long transaction
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction for which privileges should be
    /// changed.
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Gets the name of the user for which to grant or revoke privileges.
    /// 
    /// \return
    /// Returns the user name
    /// 
    FDO_API virtual FdoString* GetUserName() = 0;
    
    /// \brief
    /// Sets the name of the user for which to grant or revoke privileges.
    /// 
    /// \param value 
    /// Input the user name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetUserName(FdoString* value) = 0;

    /// \brief
    /// Gets the privilege flags to grant or revoke.The returned value may be
    /// any combination of the values from the FdoLongTransactionPrivileges
    /// enumeration combined via a bit-wise or operation.
    /// 
    /// \return
    /// Returns the privileges as a bit masked value based on FdoLongTransactionPrivileges enumeration
    /// 
    FDO_API virtual FdoInt32 GetPrivileges() = 0;

    /// \brief
    /// Sets the privilege flags to grant or revoke. The privileges value may be
    /// any combination of the values from the FdoLongTransactionPrivileges
    /// enumeration combined via a bit-wise or operation.
    /// 
    /// \param value 
    /// Input the privileges as a bit masked value based on FdoLongTransactionPrivileges enumeration
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetPrivileges(FdoInt32 value) = 0;

    /// \brief
    /// Gets the operation to perform, grant, or revoke.
    /// 
    /// \return
    /// Returns the operation to perform
    /// 
    FDO_API virtual FdoLongTransactionPrivilegeOperations GetOperation() = 0;

    /// \brief
    /// Sets the operation to perform, grant, or revoke.
    /// 
    /// \param value 
    /// Input the operation to perform
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetOperation(FdoLongTransactionPrivilegeOperations value) = 0;

    /// \brief
    /// Executes the ChangeLongTransactionPrivilege command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



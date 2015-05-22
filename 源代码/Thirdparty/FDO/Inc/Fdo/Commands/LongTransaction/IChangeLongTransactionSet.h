#ifndef _ICHANGELONGTRANSACTIONSET_H_
#define _ICHANGELONGTRANSACTIONSET_H_
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
#include <Fdo/Commands/LongTransaction/LongTransactionSetOperations.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIChangeLongTransactionSet interface defines the ChangeLongTransactionSet
/// command, which allows the user to add a transaction to, remove a transaction
/// from, or clear the long transaction selection set. Users can add or remove
/// long transactions to the selection set for which they have access
/// privileges. Any attempt to add a long transaction for which the user does
/// not have the access privilege will result in a failure of the command.
class FdoIChangeLongTransactionSet : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction to add or remove from the
    /// selection set. 
    /// 
    /// \return
    /// Returns the name of the long transaction
    /// 
    /// \note
	/// This function is not required for the Clear operation.
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction to add or remove from the
    /// selection set. 
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    /// \note
	/// This function is not required for the Clear operation.
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Gets the operation to perform, add, remove, or clear.
    /// 
    /// \return
    /// Returns the operation to perform
    /// 
    FDO_API virtual FdoLongTransactionSetOperations GetOperation() = 0;

    /// \brief
    /// Sets the operation to perform, add, remove, or clear.
    /// 
    /// \param value 
    /// Input the operation to perform
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetOperation(FdoLongTransactionSetOperations value) = 0;

    /// \brief
    /// Executes the ChangeLongTransactionSet command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



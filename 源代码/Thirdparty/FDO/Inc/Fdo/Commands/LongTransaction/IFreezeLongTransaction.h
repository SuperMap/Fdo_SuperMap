#ifndef _IFREEZELONGTRANSACTION_H_
#define _IFREEZELONGTRANSACTION_H_
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
#include <Fdo/Commands/LongTransaction/LongTransactionFreezeOperations.h>

/// \brief
/// The FdoIFreezeLongTransaction interface defines the FreezeLongTransaction
/// command, which freezes or thaws a long transaction. When a long transaction
/// is frozen the user who froze it gains exclusive access to it. Other users can
/// read it, but not apply any updates.
/// Input to the FreezeLongTransaction command is the long transaction name and
/// the operation to perform. The Execute method performs the specified
/// operation on the identified long transaction if the user has access
/// privileges for the indicated long transaction.
class FdoIFreezeLongTransaction : public FdoICommand
{
  public:
    /// \brief
    /// Gets the name of the long transaction to freeze or unfreeze as a string.
    /// 
    /// \return
    /// Returns the name of the long transaction
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the long transaction to freeze or unfreeze as a string.
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    ///  Gets the operation to perform (Freeze or Thaw) on the long transaction.
    /// 
    /// \return
    /// Returns the operation to perform
    /// 
    FDO_API virtual FdoLongTransactionFreezeOperations GetOperation() = 0;

    /// \brief
    /// Sets the operation to perform (Freeze or Thaw) on the long transaction.
    /// 
    /// \param value 
    /// Input the operation to perform
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetOperation(FdoLongTransactionFreezeOperations value) = 0;

    /// \brief
    /// Executes the command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



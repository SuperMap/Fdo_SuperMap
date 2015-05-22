#ifndef _IROLLBACKLONGTRANSACTIONCHECKPOINT_H_
#define _IROLLBACKLONGTRANSACTIONCHECKPOINT_H_
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
/// The FdoIRollbackLongTransactionCheckpoint interface defines the
/// RollbackLongTransactionCheckpoint command, which allows the user to roll back
/// changes to a named checkpoint for the given long transaction. The user
/// requires the access privilege on the long transaction for which the user tries
/// to perform the operation.
class FdoIRollbackLongTransactionCheckpoint : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction for which a checkpoint should
    /// be rolled back.
    /// 
    /// \return
    /// Returns the list of long transaction names.
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction for which a checkpoint should
    /// be rolled back.
    /// 
    /// \param value 
    /// Input the long transaction name.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Gets the name of the checkpoint to which the rollback operation
    /// should be executed.
    /// 
    /// \return
    /// Returns the name of the checkpoint.
    /// 
    FDO_API virtual FdoString* GetCheckpointName() = 0;

    /// \brief
    /// Sets the name of the checkpoint to which the rollback operation
    /// should be executed.
    /// 
    /// \param value 
    /// Input the name of the checkpoint.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetCheckpointName(FdoString* value) = 0;

    /// \brief
    /// Executes the RollbackLongTransactionCheckpoint command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



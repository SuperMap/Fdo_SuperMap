#ifndef _IACTIVATELONGTRANSACTIONCHECKPOINT_H_
#define _IACTIVATELONGTRANSACTIONCHECKPOINT_H_
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
/// The FdoIActivateLongTransactionCheckpoint interface defines the
/// IActivateLongTransactionCheckpoint command, which allows the user to
/// activate the named checkpoint for the given long transaction. As a result, 
/// the long transaction that owns the checkpoint will be activated as well if
/// it is not already the active long transaction. The user requires the access
/// privilege on the long transaction for which the attempt is made to activate a
/// checkpoint.
class FdoIActivateLongTransactionCheckpoint : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the checkpoint to be activated for the named long
    /// transaction. If the property's value is empty the system will
    /// activate the most recent checkpoint of the long transaction.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoString* GetCheckpointName() = 0;

    /// \brief
    /// Sets the name of the checkpoint to be activated for the named long
    /// transaction. If the property's value is empty the system will
    /// activate the most recent checkpoint of the long transaction.
    /// 
    /// \param value 
    /// Input the name of the checkpoint
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetCheckpointName(FdoString* value) = 0;

    /// \brief
    /// Executes the ActivateLongTransactionCheckpoint command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



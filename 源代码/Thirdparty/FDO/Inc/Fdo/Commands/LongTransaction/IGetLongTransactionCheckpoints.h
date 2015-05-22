#ifndef _IGETLONGTRANSACTIONCHECKPOINT_H_
#define _IGETLONGTRANSACTIONCHECKPOINT_H_
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
#include <Fdo/Commands/LongTransaction/ILongTransactionCheckpointReader.h>
#include <Fdo/Commands/LongTransaction/LongTransactionConstants.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIGetLongTransactionCheckpoints interface defines the
/// GetLongTransactionCheckpoints command, which allows the user to enumerate
/// the checkpoints for a given long transaction. To execute the operation, the
/// user must have access privilege to the long transaction.
class FdoIGetLongTransactionCheckpoints : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction for which to get the checkpoints.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction for which to get the checkpoints.
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Executes the get long transaction checkpoints command, returning a
    /// reference to an FdoILongTransactionCheckpointReader.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoILongTransactionCheckpointReader* Execute() = 0;
};
#endif



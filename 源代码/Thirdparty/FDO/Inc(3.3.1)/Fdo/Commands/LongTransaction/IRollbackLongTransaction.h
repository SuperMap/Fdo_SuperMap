#ifndef _IROLLBACKLONGTRANSACTION_H_
#define _IROLLBACKLONGTRANSACTION_H_
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
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Commands/Locking/ILockConflictReader.h>

/// \brief
/// The FdoIRollbackLongTransaction interface defines the RollbackLongTransaction
/// command, which allows a user to execute rollback operations on a long
/// transaction. Two different rollback operations are distinguished: full and partial.
///
/// <ol>
/// <li>A full rollback operation is executed on all data within a long transaction and all its descendents. The data is removed from the database and all versions involved in the process deleted.
/// <li>A partial rollback operation is executed on a subset of the data within a long transaction (which could be all data). The specified data in this long transaction and all its descendents are removed from the database. The versions involved in the process are not removed. The subset of the data to be rolled back is defined by a class name and a set of filter criteria.
/// </ol>
/// To perform a rollback operation, the user requires the access and
/// rollback privileges for the long transaction to be rolled back (in the case
/// of a full rollback, the user also requires the remove privilege for the
/// long transaction) and the access privilege for all the descendent
/// versions.
class FdoIRollbackLongTransaction : public FdoIFeatureCommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction to roll back as a string.
    /// 
    /// \return
    /// Returns the name of the long transaction.
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the long transaction to roll back as a string.
    /// 
    /// \param value 
    /// Input the name of the long transaction.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    /// Gets a reference to the lock conflict reader.
    /// 
    /// \return
    /// Returns a reference to the lock conflict reader
    /// 
    FDO_API virtual FdoILockConflictReader* GetLockConflictReader() = 0;

    /// \brief
    /// Executes the RollbackLongTransaction command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



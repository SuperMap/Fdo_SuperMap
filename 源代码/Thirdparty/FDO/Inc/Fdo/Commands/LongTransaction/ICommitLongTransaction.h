#ifndef _ICOMMITLONGTRANSACTION_H_
#define _ICOMMITLONGTRANSACTION_H_
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
#include <Fdo/Commands/LongTransaction/ILTConflictDirectiveEnumerator.h>
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Commands/Locking/ILockConflictReader.h>

/// \brief
/// The FdoICommitLongTransaction interface defines the CommitLongTransaction
/// command, which allows a user to execute commit operations on a long
/// transaction. Two different commit operations are distinguished: full and partial.
///
/// <b>Full.</b> A full commit operation is executed on all data within a long transaction. The data is committed to the parent long transaction and the long transaction itself is removed.
///
/// <b>Partial.</b> A partial commit operation is executed on a subset of the data within a long transaction (this could be all data). The data is committed to the parent long transaction. However, the long transaction, itself, is not removed. The subset of the data to be committed is defined by a class name and a set of filter criteria.
///
/// To perform a commit operation the user requires the access and commit
/// privileges for the long transaction to be committed (in case of a
/// full commit the user also requires the remove privilege for the long
/// transaction) and the access privilege for the parent long transaction.
/// In addition, a full commit can be performed on a leaf long transaction
/// only. A long transaction is a leaf long transaction if it does not
/// have descendent versions.
class FdoICommitLongTransaction : public FdoIFeatureCommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction to commit as a string.
    /// 
    /// \return
    /// Returns the name of the long transaction
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the long transaction to commit as a string.
    /// 
    /// \param value 
    /// Input the name of the long transaction
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

    /// Executes the commit long transaction command and returns an
    /// FdoILongTransactionConflictDirectiveEnumerator.
    /// If the returned enumerator's count is 0 then
    /// no conflicts were detected and the command was executed successfully.
    /// Otherwise conflicts were detected and the user must specify how to
    /// resolve them using the enumerator and call Execute again.
    FDO_API virtual FdoILongTransactionConflictDirectiveEnumerator* Execute() = 0;
};
#endif



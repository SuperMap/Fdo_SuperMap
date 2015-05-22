#ifndef _IACQUIRELOCK_H_
#define _IACQUIRELOCK_H_
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
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/Locking/LockType.h>
#include <Fdo/Commands/Locking/LockStrategy.h>
#include <Fdo/Commands/Locking/ILockConflictReader.h>

/// \brief
/// The FdoIAcquireLock interface locks feature instances of a given class 
/// that match the specified criteria. Input to the acquire lock command
/// includes the name of the class, the lock type, the lock strategy, and
/// filter criteria by which to identify the instances to be locked. The
/// filter may be specified either as text or as an expression tree (most 
/// likely produced by a query builder). The lock type value is one of 
/// <p> - FdoLockType_Shared
/// <p> - FdoLockType_Exclusive
/// <p> - FdoLockType_Transaction
/// <p> - FdoLockType_LongTransactionExclusive
/// <p> - FdoLockType_AllLongTransactionExclusive
/// \remarks
/// If the lock strategy has a value of all and at least one of the feature
/// instances specified in the filter is locked by someone else, the command
/// returns an FdoILockConflictReader list which contains all of the feature
/// instances specified in the filter.
/// <p>If the lock strategy has a value of partial, the command returns an
/// FdoILockConflictReader list which contains all of the feature instances
/// specified in the filter that are already locked by someone else.
/// The command returns an empty FdoILockConflictReader list if all of the
/// feature instances specified in the filter were successfully locked.
class FdoIAcquireLock : public FdoIFeatureCommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the FdoLockType value.
    /// 
    /// \return
    /// Returns the lock type.
    /// 
    FDO_API virtual FdoLockType GetLockType() = 0;

    /// \brief
    /// Sets the FdoLockType value.
    /// 
    /// \param value 
    /// Input the lock type
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLockType(FdoLockType value) = 0;

    /// \brief
    /// Gets the FdoLockStrategy value.
    /// 
    /// \return
    /// Returns the strategy value (all or partial).
    /// 
    FDO_API virtual FdoLockStrategy GetLockStrategy() = 0;

    /// \brief
    /// Sets the FdoLockStrategy value (all or partial).
    /// 
    /// \param value 
    /// Input the lock strategy used for locking objects
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLockStrategy(FdoLockStrategy value) = 0;

    /// \brief
    /// Executes the AcquireLock command, returning an FdoILockConflictReader.
    /// 
    /// \return
    /// Returns a list of feature instances which could not be locked.
    /// The list could be empty indicating that all of the feature instances
    /// specified in the filter have been locked, or it could contain the list
    /// of feature instances that could not be locked because they are already
    /// locked by someone or because the locking strategy is all and at least
    /// one of the feature instances specified in the filter is already locked
    /// by someone else.
    /// 
    FDO_API virtual FdoILockConflictReader* Execute() = 0;
};
#endif



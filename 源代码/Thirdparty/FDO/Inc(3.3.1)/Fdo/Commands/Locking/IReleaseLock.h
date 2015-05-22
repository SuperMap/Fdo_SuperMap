#ifndef _IRELEASELOCK_H_
#define _IRELEASELOCK_H_
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

/// \brief
/// The FdoIReleaseLock interface defines the ReleaseLock command, which releases
/// locks from feature instances of a given class that match the specified
/// criteria. Input to the release lock command includes the name of the class
/// and filter criteria by which to identify the instances to be unlocked. The
/// filter may be specified either as text or as an expression tree (most likely
/// produced by a query builder). The ability to successfully execute the command 
/// might be restricted by the datastore security if the lock doesn’t belong to the 
/// user executing the command.
class FdoIReleaseLock : public FdoIFeatureCommand
{
public:
    /// \brief
    /// Gets the name of the user who owns the lock to release.
    /// 
    /// \return
    /// Returns name of the lock owner. If the name was not set, it returns the name of the caller.
    /// 
    FDO_API virtual FdoString* GetLockOwner() = 0;

    /// \brief
    /// Sets the name of the user who owns the lock to release.
    /// 
    /// \param value 
    /// Input the name of the user.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLockOwner(FdoString* value) = 0;

    /// \brief
    /// Executes the release lock command, returning an FdoILockConflictReader.
    /// 
    /// \return
    /// Returns a list of feature instances whose lock is owned by someone else.
    /// 
    FDO_API virtual FdoILockConflictReader* Execute() = 0;
};
#endif



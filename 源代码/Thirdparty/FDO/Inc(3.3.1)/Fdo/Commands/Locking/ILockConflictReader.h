#ifndef _ILOCKCONFLICTREADER_H_
#define _ILOCKCONFLICTREADER_H_
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
#include <Fdo/Commands/Locking/ConflictType.h>
#include <Fdo/Commands/PropertyValueCollection.h>

/// \brief
/// The FdoILockConflictReader interface provides forward only, read-only
/// functionality for identifying features that have a lock conflict.
/// Features with a lock conflict are those that the caller is attempting to modify 
/// that are already locked by someone else. 
/// \remarks
/// A reference to an FdoILockConflictReader is returned from the
/// FdoIAcquireLock, FdoISelect, FdoIReleaseLock, FdoIUpdate, and FdoIDelete commands. The
/// initial position of the FdoILockConflictReader is prior to the first item,
/// thus you must call ReadNext to begin accessing any data.
class FdoILockConflictReader : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the class name of the feature currently being read.
    /// 
    /// \remarks
    /// The value of the class name will be null in the event that the class
    /// name could not be resolved. This can happen 
    /// if the table has no class id field and multiple classes have been
    /// written to the table.
    /// 
    /// \return
    /// Returns the class name.
    /// 
    FDO_API virtual FdoString* GetFeatureClassName() = 0;

    /// \brief
    /// Returns an FdoPropertyValueCollection containing the property values
    /// that uniquely identify the feature currently being read.
    /// 
    /// \return
    /// Returns the property collection identifying the feature.
    /// 
    FDO_API virtual FdoPropertyValueCollection* GetIdentity() = 0;

    /// \brief
    /// Gets the name of the owner who holds a lock on the feature 
    /// currently being read.
    /// 
    /// \return
    /// Returns the name of the owner
    /// 
    FDO_API virtual FdoString* GetLockOwner() = 0;

    /// \brief
    /// Gets the name of the long transaction in which the feature 
    /// currently being read is locked.
    /// 
    /// \return
    /// Returns the name of the long transaction in which the feature
    /// currently being read is locked.
    /// 
    FDO_API virtual FdoString* GetLongTransaction() = 0;

    /// \brief
    /// Gets the conflict type for the conflict currently being read.
    /// 
    /// \return
    /// Returns the conflict type for the conflict currently being read.
    /// 
    FDO_API virtual FdoConflictType GetConflictType() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the 
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoILockConflictReader object, freeing any resources it may
    /// be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;
};
#endif



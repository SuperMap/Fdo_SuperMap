#ifndef _IDELETE_H_
#define _IDELETE_H_
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
#include <Fdo/Commands/Locking/ILockConflictReader.h>

/// \brief
/// The FdoIDelete interface defines the Delete command, which deletes instances of
/// a given class that match the specified criteria. Input to the delete command
/// includes the name of the class, and filter criteria by which to identify the
/// instances to be deleted. The filter may be specified either as text or as an
/// expression tree (most likely produced by a query builder). The delete
/// command can delete instances at global scope or instances/values nested
/// within an object collection property. Instances at global scope are referred
/// to simply by the class name. Instances at a nested scope (i.e. instances
/// within a object collection property) are referred to by the containing class
/// name, followed by a '.', followed by the object collection property name.
class FdoIDelete : public FdoIFeatureCommand
{
    friend class FdoIConnection; 

public:
    /// \brief
    /// Executes the delete command and returns the number of instances
    /// deleted
    /// 
    /// \return
    /// Returns the number of instances deleted.
    /// 
    FDO_API virtual FdoInt32 Execute() = 0;

    /// \brief
    ///  Deleting objects might result in lock conflicts if objects
    /// to be deleted are not exclusively locked for the user attempting to
    /// delete the object. A lock conflict report is generated.
    /// The function GetLockConflicts returns a lock conflict reader that provides
    /// access to the list of lock conflicts that occurred during the execution
    /// of the delete operation.
    /// 
    /// \return
    /// Returns a lock conflict reader.
    /// 
    FDO_API virtual FdoILockConflictReader* GetLockConflicts() = 0;

};
#endif



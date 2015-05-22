#ifndef _IGETLOCKEDOBJECTS_H_
#define _IGETLOCKEDOBJECTS_H_
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
#include <Fdo/Commands/Locking/ILockedObjectReader.h>

/// \brief
/// The FdoIGetLockedObjects interface defines the GetLockedObjects command, which
/// gets a list of all objects that are currently locked by a particular user.
class FdoIGetLockedObjects : public FdoICommand
{
  public:
    /// \brief
    /// Gets the name of the user whose locked objects you want to list.
    /// 
    /// \return
    /// Returns the name of the user
    /// 
    FDO_API virtual FdoString* GetLockOwner() = 0;

    /// \brief
    /// Sets the name of the user whose locked objects you want to list.
    /// 
    /// \param value 
    /// Input the name of the user
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLockOwner(FdoString* value) = 0;

    /// \brief
    /// Executes the GetLockedObjects command, returning an FdoILockedObjectReader.
    /// 
    /// \return
    /// Returns a list of all of the objects currently locked by a particular user.i The list might be empty if the user does not have anything locked.
    /// 
    FDO_API virtual FdoILockedObjectReader* Execute() = 0;
};
#endif



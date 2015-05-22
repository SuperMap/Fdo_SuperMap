/*
 * 
* Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
* 
 */

#include "stdafx.h"

[!output PREFIX]ReleaseLockCommand::[!output PREFIX]ReleaseLockCommand (FdoIConnection *connection) :
    [!output PREFIX]FeatureCommand<FdoIReleaseLock> (connection),
    mOwner ()
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]ReleaseLockCommand::[!output PREFIX]ReleaseLockCommand (const [!output PREFIX]ReleaseLockCommand &right) { }
[!output PREFIX]ReleaseLockCommand::~[!output PREFIX]ReleaseLockCommand (void)
{
}

//
// FdoIReleaseLock overrides
//

/// <summary>Gets the name of the user who owns the lock to release. If this function
/// returns null or an empty string the lock being released is assumed to
/// belong to the connected user. Users with appropriate administrative
/// privileges can release locks owned by other users. The SetLockOwner
/// method allows an administrative user to set that name.</summary>
/// <returns>Returns name of the user</returns> 
FdoString* [!output PREFIX]ReleaseLockCommand::GetLockOwner ()
{
    return (mOwner);
}

/// <summary>Sets the name of the user who owns the lock to release. If set to null
/// or an empty string the lock being released is assumed to belong to the
/// connected user. Users with appropriate administrative privileges can
/// release locks owned by other users. The SetLockOwner method allows an
/// administrative user to set that name.</summary>
/// <param name="value">Input the name of the user.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ReleaseLockCommand::SetLockOwner (FdoString* value)
{
    if (NULL == value)
        value = L"";
    mOwner = value;
}

/// <summary>Executes the release lock command, returning an FdoILockConflictReader.</summary>
/// <returns>Returns an FdoILockConflictReader</returns> 
FdoILockConflictReader* [!output PREFIX]ReleaseLockCommand::Execute ()
{
    FdoPtr<[!output PREFIX]LockConflictReader> ret;
    ret = new [!output PREFIX]LockConflictReader (mFdoConnection, L"", L"");
    return (FDO_SAFE_ADDREF (ret.p));
}


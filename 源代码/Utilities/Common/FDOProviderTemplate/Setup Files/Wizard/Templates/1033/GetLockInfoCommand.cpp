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

[!output PREFIX]GetLockInfoCommand::[!output PREFIX]GetLockInfoCommand (FdoIConnection *connection) :
    [!output PREFIX]FeatureCommand<FdoIGetLockInfo> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]GetLockInfoCommand::[!output PREFIX]GetLockInfoCommand (const [!output PREFIX]GetLockInfoCommand &right) { }
[!output PREFIX]GetLockInfoCommand::~[!output PREFIX]GetLockInfoCommand (void)
{
}

//
// FdoIGetLockInfo overrides
//

/// <summary>Executes the GetLockInfo command, returning an FdoILockInfoReader.</summary>
/// <returns>Returns the lock info reader.</returns> 
FdoILockedObjectReader* [!output PREFIX]GetLockInfoCommand::Execute ()
{
    FdoPtr<[!output PREFIX]LockedObjectReader> ret;
    ret = new [!output PREFIX]LockedObjectReader (mFdoConnection);
    return (FDO_SAFE_ADDREF (ret.p));
}


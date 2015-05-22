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

[!output PREFIX]AcquireLockCommand::[!output PREFIX]AcquireLockCommand (FdoIConnection *connection) :
    [!output PREFIX]FeatureCommand<FdoIAcquireLock> (connection),
    mType (FdoLockType_None),
    mStrategy (FdoLockStrategy_All)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]AcquireLockCommand::[!output PREFIX]AcquireLockCommand (const [!output PREFIX]AcquireLockCommand &right) { }
[!output PREFIX]AcquireLockCommand::~[!output PREFIX]AcquireLockCommand (void)
{
}

/// <summary>Gets the FdoLockType value.</summary>
/// <returns>Returns the desired lock type.</returns> 
FdoLockType [!output PREFIX]AcquireLockCommand::GetLockType ()
{
    return (mType);
}

/// <summary>Sets the FdoLockType value.</summary>
/// <param name="value">Input the lock type</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]AcquireLockCommand::SetLockType (FdoLockType value)
{
	#pragma message ("ToDo: handle lock types FdoLockType_None, FdoLockType_Exclusive, FdoLockType_LongTransactionExclusive")
    mType = value;
}

/// <summary>Gets the FdoLockStrategy value.</summary>
/// <returns>Returns the desired lock strategy.</returns> 
FdoLockStrategy [!output PREFIX]AcquireLockCommand::GetLockStrategy ()
{
    return (mStrategy);
}

/// <summary>Sets the FdoLockStrategy value.</summary>
/// <param name="value">Input the lock strategy used for locking objects</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]AcquireLockCommand::SetLockStrategy (FdoLockStrategy value)
{
	#pragma message ("ToDo: handle lock strategies FdoLockStrategy_All, FdoLockStrategy_Partial")
    mStrategy = value;
}

/// <summary>Executes the AcquireLock command, returning an FdoILockConflictReader.</summary>
/// <returns>Returns the list of conflicts.</returns> 
FdoILockConflictReader* [!output PREFIX]AcquireLockCommand::Execute ()
{
    FdoPtr<[!output PREFIX]LockConflictReader> ret;
    ret = new [!output PREFIX]LockConflictReader (mFdoConnection, L"", L"");
    return (FDO_SAFE_ADDREF (ret.p));
}


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
#include "[!output PREFIX]SelectCommand.h"
#include "[!output PREFIX]FeatureReader.h"

#include <malloc.h>

[!output PREFIX]SelectCommand::[!output PREFIX]SelectCommand ([!output PREFIX]Connection* connection) :
    FdoCommonFeatureCommand<FdoISelect, [!output PREFIX]Connection> (connection),
    mType (FdoLockType_None),
    mStrategy (FdoLockStrategy_All),
    mPropertiesToSelect (NULL)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]SelectCommand::[!output PREFIX]SelectCommand (const [!output PREFIX]SelectCommand &right) { }

[!output PREFIX]SelectCommand::~[!output PREFIX]SelectCommand (void)
{
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing.</returns> 
void [!output PREFIX]SelectCommand::Dispose ()
{
    delete this;
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
/// return with the result. If empty all properties of the specified class
/// are returned.</summary>
/// <returns>Returns the list of property names.</returns> 
FdoIdentifierCollection* [!output PREFIX]SelectCommand::GetPropertyNames ()
{
    if (mPropertiesToSelect == NULL)
        mPropertiesToSelect = FdoIdentifierCollection::Create();

    return (FDO_SAFE_ADDREF(mPropertiesToSelect.p));
}

/// <summary>Gets the FdoLockType value (see "Locking Commands").</summary>
/// <returns>Returns the lock type.</returns> 
FdoLockType [!output PREFIX]SelectCommand::GetLockType ()
{
    return (mType);
}

/// <summary>Sets the FdoLockType value (see "Locking Commands").</summary>
/// <param name="value">Input the lock type.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]SelectCommand::SetLockType (FdoLockType value)
{
#pragma message ("ToDo: handle lock types FdoLockType_None, FdoLockType_Exclusive, FdoLockType_LongTransactionExclusive")
    mType = value;
}

/// <summary>Gets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <returns>Returns the lock strategy.</returns> 
FdoLockStrategy [!output PREFIX]SelectCommand::GetLockStrategy ()
{
    return (mStrategy);
}

/// <summary>Sets the FdoLockStrategy value (see "Locking Commands").</summary>
/// <param name="value">Input the lock strategy.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]SelectCommand::SetLockStrategy (FdoLockStrategy value)
{
#pragma message ("ToDo: handle lock strategies FdoLockStrategy_All, FdoLockStrategy_Partial")
    mStrategy = value;
}

/// <summary>Executes the select command and returns a reference to an FdoIFeatureReader.</summary>
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* [!output PREFIX]SelectCommand::Execute ()
{
    FdoPtr<[!output PREFIX]FeatureReader> ret;

    ret = new [!output PREFIX]FeatureReader ();

    return (FDO_SAFE_ADDREF (ret.p));
}

/// <summary>Executes the select command and returns a reference to an
/// IFeatureReader.</summary> 
/// <returns>Returns the feature reader.</returns> 
FdoIFeatureReader* [!output PREFIX]SelectCommand::ExecuteWithLock ()
{
    FdoPtr<[!output PREFIX]FeatureReader> ret;

    ret = new [!output PREFIX]FeatureReader ();

    return (FDO_SAFE_ADDREF (ret.p));
}

/// <summary> When executing the operation ExecuteWithLock lock 
/// conflicts may occur. Those lock conflicts are reported. The 
/// function GetLockConflicts returns a lock conflict reader 
/// providing access to the list of lock conflicts that occurred 
/// during the execution of the operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* [!output PREFIX]SelectCommand::GetLockConflicts ()
{
[!if LOCKING]
    return (new [!output PREFIX]LockConflictReader ());
[!else]
    throw FdoException::Create (NlsMsgGet ([!output UPPER_PREFIX]_LOCKING_NOT_SUPPORTED, "Locking not supported."));
[!endif]
}


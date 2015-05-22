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

[!output PREFIX]RollbackLongTransactionCommand::[!output PREFIX]RollbackLongTransactionCommand (FdoIConnection *connection) :
    [!output PREFIX]FeatureCommand<FdoIRollbackLongTransaction> (connection),
    mName ()
{
}

[!output PREFIX]RollbackLongTransactionCommand::~[!output PREFIX]RollbackLongTransactionCommand (void)
{
}

/// <summary>Gets the name of the long transaction to commit as a string.</summary>
/// <returns>Returns the name of the long transaction</returns> 
FdoString* [!output PREFIX]RollbackLongTransactionCommand::GetName ()
{
    return (mName);
}

/// <summary>Sets the name of the long transaction to create as a string.</summary>
/// <param name="value">Input the name of the long transaction</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]RollbackLongTransactionCommand::SetName (FdoString* value)
{
    mName = value;
}

void [!output PREFIX]RollbackLongTransactionCommand::Execute ()
{
	#pragma message ("ToDo: Execute")
}

/// <summary>Gets a reference to the lock conflict reader.</summary>
/// <returns>Returns a reference to the lock conflict reader</returns> 
FdoILockConflictReader* [!output PREFIX]RollbackLongTransactionCommand::GetLockConflictReader()
{
[!if LOCKING]
    return (new [!output PREFIX]LockConflictReader ());
[!else]
    throw FdoException::Create (NlsMsgGet ([!output UPPER_PREFIX]_LOCKING_NOT_SUPPORTED, "Locking not supported."));
[!endif]
}


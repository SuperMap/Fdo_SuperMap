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

[!output PREFIX]CommitLongTransactionCommand::[!output PREFIX]CommitLongTransactionCommand (FdoIConnection *connection) :
    [!output PREFIX]FeatureCommand<FdoICommitLongTransaction> (connection),
    mName ()
{
}

[!output PREFIX]CommitLongTransactionCommand::~[!output PREFIX]CommitLongTransactionCommand (void)
{
    // ToDo: invalidate the conflict enumerator
}

/// <summary>Gets the name of the long transaction to commit as a string.</summary>
/// <returns>Returns the name of the long transaction</returns> 
FdoString* [!output PREFIX]CommitLongTransactionCommand::GetName ()
{
    return (mName);
}

/// <summary>Sets the name of the long transaction to create as a string.</summary>
/// <param name="value">Input the name of the long transaction</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]CommitLongTransactionCommand::SetName (FdoString* value)
{
    mName = value;
}

// Executes the commit long transaction command and returns an
// FdoILongTransactionConflictDirectiveEnumerator.
// If the returned enumerator's count is 0 then
// no conflicts were detected and the command was executed successfully.
// Otherwise conflicts were detected and the user must specify how to
// resolve them using the enumerator and call Execute again.
FdoILongTransactionConflictDirectiveEnumerator* [!output PREFIX]CommitLongTransactionCommand::Execute ()
{
	#pragma message ("ToDo: Execute")
    return NULL;
}

/// <summary>Gets a reference to the lock conflict reader.</summary>
/// <returns>Returns a reference to the lock conflict reader</returns> 
FdoILockConflictReader* [!output PREFIX]CommitLongTransactionCommand::GetLockConflictReader()
{
	// return new [!output PREFIX]LockConflictReader(mFdoConnection, L"", L"");
	return NULL;
}


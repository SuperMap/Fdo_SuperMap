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

[!output PREFIX]DeleteCommand::[!output PREFIX]DeleteCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIDelete, [!output PREFIX]Connection> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]DeleteCommand::[!output PREFIX]DeleteCommand (const [!output PREFIX]DeleteCommand &right) { }

[!output PREFIX]DeleteCommand::~[!output PREFIX]DeleteCommand (void)
{
}

/// <summary>Executes the delete command and returns the number of instances
/// deleted</summary>
/// <returns>Returns the number of instances deleted.</returns> 
FdoInt32 [!output PREFIX]DeleteCommand::Execute ()
{
#pragma message ("ToDo: delete")
    return (0);
}

/// <summary> Deleting objects might result in lock conflicts if objects
/// to be deleted are not exclusively locked for the user attempting to
/// delete the object. A lock conflict report is generated.
/// The function GetLockConflicts returns a lock conflict reader that provides
/// access to the list of lock conflicts that occurred during the execution
/// of the delete operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* [!output PREFIX]DeleteCommand::GetLockConflicts ()
{
[!if LOCKING]
    return (new [!output PREFIX]LockConflictReader (mConnection, L"", L""));
[!else]
	return NULL;
[!endif]
}


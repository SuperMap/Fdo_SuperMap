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

[!output PREFIX]UpdateCommand::[!output PREFIX]UpdateCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIUpdate, [!output PREFIX]Connection> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]UpdateCommand::[!output PREFIX]UpdateCommand (const [!output PREFIX]UpdateCommand &right) { }

[!output PREFIX]UpdateCommand::~[!output PREFIX]UpdateCommand (void)
{
}

//
// FdoIUpdate interface
//

/// <summary>Executes the update command and returns the number of modified 
/// instances.</summary>
/// <returns>Returns nothing</returns> 
FdoInt32 [!output PREFIX]UpdateCommand::Execute ()
{
#pragma message ("ToDo: update")
    return (0);
}


/// <summary> Updating objects might result in lock conflicts if objects
/// to be updated are not exclusively locked for the user attempting to
/// update the object. If objects to be updated are not exclusively locked for the 
/// user attempting to update the object, a lock conflict report is generated.
/// The function GetLockConflicts returns a lock conflict reader providing
/// access to the list of lock conflicts that occurred during the execution
/// of the update operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* [!output PREFIX]UpdateCommand::GetLockConflicts ()
{
[!if LOCKING]
    return (new [!output PREFIX]LockConflictReader (mConnection, L"", L""));
[!else]
	return NULL;
[!endif]
}


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

[!output PREFIX]GetLockedObjectsCommand::[!output PREFIX]GetLockedObjectsCommand (FdoIConnection *connection) :
    [!output PREFIX]Command<FdoIGetLockedObjects> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]GetLockedObjectsCommand::[!output PREFIX]GetLockedObjectsCommand (const [!output PREFIX]GetLockedObjectsCommand &right) { }
[!output PREFIX]GetLockedObjectsCommand::~[!output PREFIX]GetLockedObjectsCommand (void)
{
}

//
// FdoIGetLockInfo overrides
//

///<summary>Gets the name of the user for which to get a list of locked objects.</summary>
/// <returns>Returns the name of the user</returns> 
FdoString* [!output PREFIX]GetLockedObjectsCommand::GetLockOwner ()
{
    return (mLockOwner);
}

///<summary>Sets the name of the user for which to get a list of locked objects.</summary>
/// <param name="value">Input the name of the user</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]GetLockedObjectsCommand::SetLockOwner (FdoString* value)
{
    mLockOwner = value;
}

///<summary>Executes the GetLockedObjects command, returning an FdoILockedObjectReader.</summary>
/// <returns>Returns FdoILockedObjectReade.r</returns> 
FdoILockedObjectReader* [!output PREFIX]GetLockedObjectsCommand::Execute ()
{
    return new [!output PREFIX]LockedObjectReader (mConnection);
}


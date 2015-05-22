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

[!output PREFIX]ActivateLongTransactionCommand::[!output PREFIX]ActivateLongTransactionCommand (FdoIConnection *connection) :
    [!output PREFIX]Command<FdoIActivateLongTransaction> (connection),
    mName ()
{
}

[!output PREFIX]ActivateLongTransactionCommand::~[!output PREFIX]ActivateLongTransactionCommand (void)
{
}

/// <summary>Gets the name of the long transaction to activate as a string.</summary>
/// <returns>Returns the name of the long transaction</returns>
FdoString* [!output PREFIX]ActivateLongTransactionCommand::GetName ()
{
    return (mName);
}

/// <summary>Sets the name of the long transaction to activate as a string.</summary>
/// <param name="value">Input the name of the long transaction</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ActivateLongTransactionCommand::SetName (FdoString* value)
{
    mName = value;
}

/// <summary>Executes the activate long transaction command. An exception is
/// thrown if the long transaction does not exist or the user does not
/// have access privileges to the long transaction.</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ActivateLongTransactionCommand::Execute ()
{
	#pragma message ("ToDo: Execute")
}


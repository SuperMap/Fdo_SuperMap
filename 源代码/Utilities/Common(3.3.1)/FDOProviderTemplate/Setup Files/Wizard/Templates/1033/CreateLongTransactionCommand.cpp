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

[!output PREFIX]CreateLongTransactionCommand::[!output PREFIX]CreateLongTransactionCommand (FdoIConnection *connection) :
    [!output PREFIX]Command<FdoICreateLongTransaction> (connection),
    mName (),
    mDescription ()
{
}

[!output PREFIX]CreateLongTransactionCommand::~[!output PREFIX]CreateLongTransactionCommand (void)
{
}

/// <summary>Gets the name of the long transaction to create as a string.</summary>
/// <returns>Returns the name of the long transaction</returns> 
FdoString* [!output PREFIX]CreateLongTransactionCommand::GetName ()
{
    return (mName);
}

/// <summary>Sets the name of the long transaction to create as a string.</summary>
/// <param name="value">Input the name of the long transaction</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]CreateLongTransactionCommand::SetName (FdoString* value)
{
    mName = value;
}

/// <summary>Gets the description of the long transaction to create as a string.</summary>
/// <returns>Returns the description of the long transaction</returns> 
FdoString* [!output PREFIX]CreateLongTransactionCommand::GetDescription ()
{
    return (mDescription);
}

/// <summary>Sets the description of the long transaction to create as a string.</summary>
/// <param name="value">Input the description of the long transaction</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]CreateLongTransactionCommand::SetDescription (FdoString* value)
{
    mDescription = value;
}

/// <summary>Executes the create long transaction command.</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]CreateLongTransactionCommand::Execute ()
{
#pragma message ("ToDo: Execute")
}



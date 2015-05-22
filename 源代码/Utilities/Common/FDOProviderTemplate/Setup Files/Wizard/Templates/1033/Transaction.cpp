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

#include <malloc.h>
#include <string.h>

[!output PREFIX]Transaction::[!output PREFIX]Transaction ([!output PREFIX]Connection* connection) :
    mConnection (connection)
{
    FDO_SAFE_ADDREF (mConnection);
}

[!output PREFIX]Transaction::~[!output PREFIX]Transaction (void)
{
    FDO_SAFE_RELEASE (mConnection);
}

/// <summary> Gets the FdoIConnection object associated with the transaction.</summary>
/// <returns>Returns FdoIConnection object</returns>
FdoIConnection* [!output PREFIX]Transaction::GetConnection ()
{
    return (FDO_SAFE_ADDREF(mConnection));
}

/// <summary> Commits the transaction.</summary>
/// <returns>Returns nothing</returns>
void [!output PREFIX]Transaction::Commit ()
{
#pragma message ("ToDo: commit transaction")
}

/// <summary> Rolls back a transaction from a pending state.</summary>
/// <returns>Returns nothing</returns>
void [!output PREFIX]Transaction::Rollback ()
{
#pragma message ("ToDo: rollback transaction")
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void [!output PREFIX]Transaction::Dispose ()
{
    delete this;
}


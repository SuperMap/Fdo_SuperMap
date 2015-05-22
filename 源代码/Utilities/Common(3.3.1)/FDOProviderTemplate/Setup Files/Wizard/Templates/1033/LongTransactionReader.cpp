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

[!output PREFIX]LongTransactionReader::[!output PREFIX]LongTransactionReader ([!output PREFIX]Connection* connection) :
    mConnection (connection)
{
}

[!output PREFIX]LongTransactionReader::~[!output PREFIX]LongTransactionReader (void)
{
    Close ();
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]LongTransactionReader::[!output PREFIX]LongTransactionReader (const [!output PREFIX]LongTransactionReader &right) { }

void [!output PREFIX]LongTransactionReader::Dispose ()
{
    delete this;
}

/// <summary>Gets the name of the long transaction currently being read.</summary>
/// <returns>Returns the name of the long transaction.</returns> 
FdoString* [!output PREFIX]LongTransactionReader::GetName ()
{
    return (mName);
}

/// <summary>Gets the description of the long transaction currently being read.</summary>
/// <returns>Returns the description of the long transaction.</returns> 
FdoString* [!output PREFIX]LongTransactionReader::GetDescription ()
{
    return (mDescription);
}

/// <summary>Gets the owner of the long transaction currently being read.</summary>
/// <returns>Returns the owner name.</returns> 
FdoString* [!output PREFIX]LongTransactionReader::GetOwner ()
{
    return (mOwner);
}

/// <summary>Gets the creation date of the long transaction currently being read.</summary>
/// <returns>Returns the date when the long transaction was created.</returns> 
FdoDateTime [!output PREFIX]LongTransactionReader::GetCreationDate ()
{
    FdoDateTime ret;
    return (ret);
}

/// <summary>Returns true if the long transaction currently being read is the
/// active long transaction.</summary>
/// <returns>Returns true if the long transaction is active.</returns> 
bool [!output PREFIX]LongTransactionReader::IsActive ()
{
    return (false);
}

/// <summary>Returns true if the long transaction currently being read is locked.</summary>
/// <returns>Returns true if the long transaction is locked by anybody.</returns> 
bool [!output PREFIX]LongTransactionReader::IsFrozen ()
{
    return (false);
}

/// <summary>Advances the reader to the next item. The default position of the
/// reader is prior to the first item. Thus, you must call ReadNext
/// to begin accessing any data.</summary>
/// <returns>Returns true if there is a next item.</returns> 
bool [!output PREFIX]LongTransactionReader::ReadNext ()
{
    return false;
}

/// <summary>Closes the FdoILongTransactionReader object, freeing any resources it may
/// be holding.</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]LongTransactionReader::Close ()
{
}

/// <summary>Provides access to the direct descendent long transactions 
/// for the long transaction being currently read. The caller can use the
/// returned reader to get to the next level of descendents if required.
/// The returned reader is empty if there are no descendents for the long
/// transction.</summary>
/// <returns>Returns a long transaction reader with the direct descendents
/// for the long transaction currently being read.</returns> 
FdoILongTransactionReader* [!output PREFIX]LongTransactionReader::GetChildren ()
{
    return (new [!output PREFIX]LongTransactionReader (mConnection));
}

/// <summary>Provides access to the direct ascendant long transactions for
/// the long transaction being currently read. The caller can use the 
/// returned reader to get to the next level of ascendants if required.
/// The returned reader is empty if there are no ascendants for the long
/// transaction</summary>
/// <returns>Returns a long transaction reader with the direct ascendants 
/// for the long transaction currently being read.</returns> 
FdoILongTransactionReader* [!output PREFIX]LongTransactionReader::GetParents ()
{
    return (new [!output PREFIX]LongTransactionReader (mConnection));
}


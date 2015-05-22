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

[!output PREFIX]LockedObjectReader::[!output PREFIX]LockedObjectReader ([!output PREFIX]Connection* connection) :
    mConnection (connection),
    mClassName (),
    mUser ()
{
    FDO_SAFE_ADDREF (mConnection.p);
}

[!output PREFIX]LockedObjectReader::~[!output PREFIX]LockedObjectReader (void)
{
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void [!output PREFIX]LockedObjectReader::Dispose ()
{
    delete this;
}

/// <summary>Gets the class name of the feature currently being read.</summary>
/// <returns>Returns the name of the class.</returns> 
FdoString* [!output PREFIX]LockedObjectReader::GetFeatureClassName ()
{
    return (mClassName);
}

/// <summary>Checks if we're the only one hanging onto the GetIdentity objects.</summary>
// <returns>Returns true if we should allocate another set of identity objects.</returns> 
bool [!output PREFIX]LockedObjectReader::Referenced ()
{
    FdoInt32 i;
    FdoInt32 j;
    bool ret;

    ret = true;

    if (mIdentity != NULL)
    {
        mIdentity.p->AddRef ();
        i = mIdentity.p->Release ();
        if (2 > i)
        {
            FdoPropertyValue* property = mIdentity->GetItem (0);
            FdoInt32Value* value = (FdoInt32Value*)property->GetValue ();
            j = value->Release ();
            i = property->Release ();
            if ((2 > i) && (2 > j))
                ret = false;
        }
    }

    return (ret);
}

/// <summary>Returns an FdoPropertyValueCollection containing the property values
/// that uniquely identify the feature currently being read.</summary>
/// <returns>Returns the property collection identifying the feature.</returns> 
FdoPropertyValueCollection* [!output PREFIX]LockedObjectReader::GetIdentity ()
{
#pragma message ("ToDo: identity of current lock conflict")
    if (Referenced ())
    {   // new objects required
        mIdentity = FdoPropertyValueCollection::Create ();
        FdoPtr<FdoInt32Value> value = FdoInt32Value::Create (0);
        FdoPtr<FdoPropertyValue> property = FdoPropertyValue::Create (L"FeatureId", value);
        mIdentity->Add (property);
    }
    else
    {  // the user isn't holding on to the id, so reuse it
       FdoPtr<FdoPropertyValue> property = mIdentity->GetItem (0);
       FdoPtr<FdoInt32Value> value = (FdoInt32Value*)property->GetValue ();
       value->SetInt32 (42); // set new Id value
    }

    return (FDO_SAFE_ADDREF (mIdentity.p));
}

/// <summary>Gets the name of user who holds the lock on the feature currently being
/// read.</summary>
/// <returns>Returns the lock owner.</returns> 
FdoString* [!output PREFIX]LockedObjectReader::GetLockOwner ()
{
    return (mUser);
}

/// <summary>Gets the name of the long transaction for the feature currently being read.</summary>
/// <returns>Returns the name of the long transaction.</returns> 
FdoString* [!output PREFIX]LockedObjectReader::GetLongTransaction ()
{
    return (L"");
}

/// <summary>Gets the type of the lock held on the feature currently being read.</summary>
/// <returns>Returns the lock type.</returns> 
const FdoLockType [!output PREFIX]LockedObjectReader::GetLockType ()
{
	return (FdoLockType_Exclusive);
}

/// <summary>Advances the reader to the next item. The default position of the 
/// reader is prior to the first item. Thus, you must call ReadNext
/// to begin accessing any data.</summary>
/// <returns>Returns true if there is a next item.</returns> 
bool [!output PREFIX]LockedObjectReader::ReadNext ()
{
    return false;
}

/// <summary>Closes the FdoILockConflictReader object, freeing any resources it may
/// be holding.</summary>
/// <returns>Returns nothing.</returns> 
void [!output PREFIX]LockedObjectReader::Close ()
{
}


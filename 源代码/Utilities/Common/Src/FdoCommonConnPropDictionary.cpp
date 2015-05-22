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

#include "FdoCommonConnPropDictionary.h"
#include "FdoCommonConnStringParser.h"

//TODO: rename this cpp file to not contain the keyword "Connection"
// since it is now usable for several kinds of FdoIPropertyDictionary
// subclasses.


// Syncronizes this dictionary to the given connection string;
// Call this method whenever the user updates the connection string directly
// (e.g. in FdoIConnection::SetConnectionString()):
void FdoCommonConnPropDictionary::UpdateFromConnectionString(FdoString *newConnectionString)
{
    FdoPtr<ConnectionProperty> property;

    // Initialize all properties to empty string:
    for (FdoInt32 i=0; i<mProperties->GetCount(); i++)
    {
        property = mProperties->GetItem(i);
        property->SetValue(L"");
    }

    // Populate the properties that are set in newConnectionString:
    if (NULL != newConnectionString)
    {
        FdoCommonConnStringParser parser (this, newConnectionString);
        for (FdoInt32 i=0; i<mProperties->GetCount(); i++)
        {
            property = mProperties->GetItem(i);
            if (parser.IsPropertyValueSet(property->GetName()))
            {
                FdoStringP val = parser.GetPropertyValueW(property->GetName());
                property->SetValue(val);
            }
        }
    }
}

// Define a new connection property;
// Dall this method once per connection property
// immediately after creating a new instance of FdoCommonPropDictionary:
void FdoCommonConnPropDictionary::AddProperty(ConnectionProperty *newConnProp)
{
    // let base class do its work:
    FdoCommonPropDictionary<FdoIConnectionPropertyDictionary>::AddProperty(newConnProp);

    // Populate the dictionary from what's currently in the connection string:
    const wchar_t* connection_string = mConnection->GetConnectionString ();
    UpdateFromConnectionString(connection_string);
}



void FdoCommonConnPropDictionary::SetProperty (FdoString* name, FdoString* value)
{
    // let base class do its work:
    FdoCommonPropDictionary<FdoIConnectionPropertyDictionary>::SetProperty(name, value);

    // compute the new connection string length
    FdoPtr<ConnectionProperty> pProperty;
    int count = mProperties->GetCount ();

    // generate the new connection string
    FdoStringP connection_string;
    for (int i = 0; i < count; i++)
    {
        pProperty = mProperties->GetItem(i);

        // skip over properties that aren't set:
        // NOTE: if a required property isn't set, FdoIConnection::Open() should throw appropriate exception
        if (!pProperty->GetIsPropertySet ())
            continue;

        // verify we have a valid token
        const wchar_t* tname  = pProperty->GetName ();
        const wchar_t* tvalue = pProperty->GetValue ();
        if (tname == NULL || tvalue == NULL || wcslen (tname) == 0)
            continue;

        connection_string += tname;                              // name
        connection_string += CONNECTIONPROPERTY_SEPARATOR;       // =
		if (tvalue != NULL && (pProperty->GetIsPropertyQuoted() || wcsrchr(tvalue, L';') != NULL))
		{
			connection_string += L"\"";                              // "
			connection_string += tvalue;                             // value
			connection_string += L"\"";                              // "
		}
		else
			connection_string += tvalue;                             // value
        connection_string += CONNECTIONPROPERTY_DELIMITER;           // ;
    }

    // update it on the connection
    mConnection->SetConnectionString (connection_string);
}

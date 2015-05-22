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

[!output PREFIX]InsertCommand::[!output PREFIX]InsertCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIInsert, [!output PREFIX]Connection> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]InsertCommand::[!output PREFIX]InsertCommand (const [!output PREFIX]InsertCommand &right) { }

[!output PREFIX]InsertCommand::~[!output PREFIX]InsertCommand (void)
{
}


/// <summary>Gets the FdoBatchParameterValueCollection that can be used for optimized
/// batch inserts of multiple features with a single insert command. Batch
/// inserts can be performed by using Parameters for each of the property
/// values, then adding collections of parameter values to the
/// FdoBatchParameterValueCollection. Each FdoParameterValueCollection in the
/// FdoBatchParameterValueCollection should contain one FdoParameterValue for each
/// of the parameters specified for property values.</summary>
/// <returns>Returns FdoBatchParameterValueCollection</returns>
FdoBatchParameterValueCollection* [!output PREFIX]InsertCommand::GetBatchParameterValues ()
{
    if (mBatchParameters == NULL)
        mBatchParameters = FdoBatchParameterValueCollection::Create();

    return (FDO_SAFE_ADDREF(mBatchParameters.p));
}

/// <summary>Executes the insert command and returns a reference to an
/// FdoIFeatureReader. Some feature providers can generate automatic identity
/// values for features. This will happen automatically as the features are
/// inserted. The returned FdoIFeatureReader allows the client to obtain the
/// automatic identity property value(s) of newly inserted object(s). The
/// returned feature reader at a minimum will read the unique identity
/// properties of the objects just inserted. Multiple objects will be
/// returned through the reader in the case of a batch insert.</summary>
/// <returns>Returns an FdoIFeatureReader</returns> 
FdoIFeatureReader* [!output PREFIX]InsertCommand::Execute ()
{
#pragma message ("ToDo: insert")
    return (new [!output PREFIX]FeatureReader ());
}


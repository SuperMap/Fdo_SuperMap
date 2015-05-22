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

[!output PREFIX]CommandCapabilities::[!output PREFIX]CommandCapabilities ()
{
}

[!output PREFIX]CommandCapabilities::~[!output PREFIX]CommandCapabilities ()
{
}

void [!output PREFIX]CommandCapabilities::Dispose()
{
    delete this;
}

/// <summary>Gets an array of the FdoCommandType values supported by the feature provider.</summary>
/// <param name="size">Output the number of commands</param> 
/// <returns>Returns the list of commands</returns> 
FdoInt32* [!output PREFIX]CommandCapabilities::GetCommands (FdoInt32& size)
{
    static const FdoCommandType commands[] =
    {
        FdoCommandType_Select,
        FdoCommandType_SelectAggregates,
[!if READ_WRITE]
        FdoCommandType_Insert,
        FdoCommandType_Delete,
        FdoCommandType_Update,
[!endif]
        FdoCommandType_DescribeSchema,
[!if META_DATA]
        FdoCommandType_ApplySchema,
        FdoCommandType_DestroySchema,
[!endif]
[!if SQL]
        FdoCommandType_SQLCommand,
[!endif]
[!if LOCKING]
        FdoCommandType_AcquireLock,
        FdoCommandType_GetLockInfo,
        FdoCommandType_GetLockedObjects,
        FdoCommandType_GetLockOwners,
        FdoCommandType_ReleaseLock,
[!endif]
[!if LONG_TRANSACTIONS]
        FdoCommandType_ActivateLongTransaction,
        FdoCommandType_DeactivateLongTransaction,
        FdoCommandType_CommitLongTransaction,
        FdoCommandType_CreateLongTransaction,
        FdoCommandType_GetLongTransactions,
//      FdoCommandType_FreezeLongTransaction,
        FdoCommandType_RollbackLongTransaction,
//      FdoCommandType_ActivateLongTransactionCheckpoint,
//      FdoCommandType_CreateLongTransactionCheckpoint,
//      FdoCommandType_GetLongTransactionCheckpoints,
//      FdoCommandType_RollbackLongTransactionCheckpoint,
//      FdoCommandType_ChangeLongTransactionPrivileges,
//      FdoCommandType_GetLongTransactionPrivileges,
//      FdoCommandType_ChangeLongTransactionSet,
//      FdoCommandType_GetLongTransactionsInSet,
[!endif]
[!if ACTIVATE_SPATIAL_CONTEXT]
        FdoCommandType_ActivateSpatialContext,
[!endif]
[!if CREATE_SPATIAL_CONTEXT]
        FdoCommandType_CreateSpatialContext,
[!endif]
[!if DESTROY_SPATIAL_CONTEXT]
        FdoCommandType_DestroySpatialContext,
[!endif]
[!if GET_SPATIAL_CONTEXT]
        FdoCommandType_GetSpatialContexts,
[!endif]
    };

    size = sizeof (commands) / sizeof (FdoCommandType);

    return ((FdoInt32*)commands);
}

/// <summary>Determines if commands support parameterization.</summary>
/// <returns>Returns true if commands support parameterization</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsParameters ()
{
#pragma message ("ToDo: supports parameters")
    return (false);
}

/// <summary>Determines if the feature provider supports command execution timeout.</summary>
/// <returns>Returns true if the feature provider supports timeout.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsTimeout ()
{
#pragma message ("ToDo: supports timeout")
    return (false);
}


/// <summary>Determines if the feature provider can use expressions for properties with Select and SelectAggregate commands.</summary>
/// <returns>Returns true if the feature provider supports select expressions.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsSelectExpressions()
{
#pragma message ("ToDo: supports select expressions")
    return (false);
}

/// <summary>Determines if simple functions can be used in Select and SelectAggregates command. 
/// Aggregate functions can only be used in the SelectAggregates command. Capability for using SelectAggregates is found in 
/// CommandCapabilities.</summary>
/// <returns>Returns true if the feature provider supports select simple functions.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsSelectFunctions()
{
#pragma message ("ToDo: supports select functions")
    return (false);
}

/// <summary>Determines if Distinct can be used with SelectAggregates. This can be true only 
/// if the SelectAggregates command is supported by the provider.</summary>
/// <returns>Returns true if the feature provider supports select distinct.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsSelectDistinct()
{
#pragma message ("ToDo: supports select distinct")
    return (false);
}

/// <summary>Determines  if ordering is available in the Select and SelectAggregates command.</summary>
/// <returns>Returns true if the feature provider supports select ordering.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsSelectOrdering()
{
#pragma message ("ToDo: supports select ordering")
    return (false);
}

/// <summary>Determines if a grouping criteria is available in the SelectAggregates command. 
/// This can be true only if the SelectAggregates command is supported by the provider. Note that aggregate 
/// functions can be supported without also supporting grouping criteria (but not vice versa).</summary>
/// <returns>Returns true if the feature provider supports select grouping.</returns> 
bool [!output PREFIX]CommandCapabilities::SupportsSelectGrouping()
{
#pragma message ("ToDo: supports select grouping")
    return (false);
}


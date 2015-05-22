#ifndef _COMMANDTYPE_H_
#define _COMMANDTYPE_H_
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef _WIN32
#pragma once
#endif

/// \ingroup (enums)
/// \brief
/// The FdoCommandType enumeration defines the list of abstract commands a feature
/// provider can support.
enum FdoCommandType {
    /// Represents the Select Command.
    FdoCommandType_Select,

    /// Represents the Insert Command.
    FdoCommandType_Insert,

    /// Represents the Delete Command.
    FdoCommandType_Delete,

    /// Represents the Update Command.
    FdoCommandType_Update,

    /// Represents the DescribeSchema Command.
    FdoCommandType_DescribeSchema,

    /// Represents the DescribeSchemaMapping Command.
    FdoCommandType_DescribeSchemaMapping,

    /// Represents the ApplySchema command.
    FdoCommandType_ApplySchema,

    /// Represents the DestroySchema command.
    FdoCommandType_DestroySchema,

    /// Represents the ActivateSpatialContext command.
    FdoCommandType_ActivateSpatialContext,

    /// Represents the CreateSpatialContext command.
    FdoCommandType_CreateSpatialContext,

    /// Represents the DestroySpatialContext command.
    FdoCommandType_DestroySpatialContext,

    /// Represents the GetSpatialContexts command.
    FdoCommandType_GetSpatialContexts,

    /// Represents the CreateMeasureUnit command.
    FdoCommandType_CreateMeasureUnit,

    /// Represents the DestroyMeasureUnit command.
    FdoCommandType_DestroyMeasureUnit,

    /// Represents the GetMeasureUnits command.
    FdoCommandType_GetMeasureUnits,

    /// Represents the SQLCommand command.
    FdoCommandType_SQLCommand,

    /// Represents the AcquireLock command.
    FdoCommandType_AcquireLock,

    /// Represents the GetLockInfo command.
    FdoCommandType_GetLockInfo,

    /// Represents the GetLockedObjects command.
    FdoCommandType_GetLockedObjects,

    /// Represents the GetLockOwners command.
    FdoCommandType_GetLockOwners,

    /// Represents the ReleaseLock command.
    FdoCommandType_ReleaseLock,

    /// Represents the ActivateLongTransaction command.
    FdoCommandType_ActivateLongTransaction,

    /// Represents the DeactivateLongTransaction command.
    FdoCommandType_DeactivateLongTransaction,

    /// Represents the CommitLongTransaction command.
    FdoCommandType_CommitLongTransaction,

    /// Represents the CreateLongTransaction command.
    FdoCommandType_CreateLongTransaction,

    /// Represents the GetLongTransactions command.
    FdoCommandType_GetLongTransactions,

    /// Represents the FreezeLongTransaction command.
    FdoCommandType_FreezeLongTransaction,

    /// Represents the RollbackLongTransaction command.
    FdoCommandType_RollbackLongTransaction,

    /// Represents the ActivateLongTransactionCheckpoint command.
    FdoCommandType_ActivateLongTransactionCheckpoint,

    /// Represents the CreateLongTransactionCheckpoint command.
    FdoCommandType_CreateLongTransactionCheckpoint,

    /// Represents the GetLongTransactionCheckpoints command.
    FdoCommandType_GetLongTransactionCheckpoints,

    /// Represents the RollbackLongTransactionCheckpoint command.
    FdoCommandType_RollbackLongTransactionCheckpoint,

    /// Represents the ChangeLongTransactionPrivileges command.
    FdoCommandType_ChangeLongTransactionPrivileges,

    /// Represents the GetLongTransactionPrivileges command.
    FdoCommandType_GetLongTransactionPrivileges,

    /// Represents the ChangeLongTransactionSet command.
    FdoCommandType_ChangeLongTransactionSet,

    /// Represents the GetLongTransactionsInSet command.
    FdoCommandType_GetLongTransactionsInSet,

    /// Represents the NetworkShortestPath command.
    FdoCommandType_NetworkShortestPath,

    /// Represents the NetworkAllPaths command.
    FdoCommandType_NetworkAllPaths,

    /// Represents the NetworkReachableNodes command.
    FdoCommandType_NetworkReachableNodes,

    /// Represents the NetworkReachingNodes command.
    FdoCommandType_NetworkReachingNodes,

    /// Represents the NetworkNearestNeighbors command.
    FdoCommandType_NetworkNearestNeighbors,

    /// Represents the NetworkWithinCost command.
    FdoCommandType_NetworkWithinCost,

    /// Represents the NetworkTSP command.
    FdoCommandType_NetworkTSP,

    /// Represents the ActivateTopologyArea command.
    FdoCommandType_ActivateTopologyArea,

    /// Represents the DeactivateTopologyArea command.
    FdoCommandType_DeactivateTopologyArea,

    /// Represents the ActivateTopologyInCommandResult command.
    FdoCommandType_ActivateTopologyInCommandResult,

    /// Represents the DeactivateTopologyInCommandResults command.
    FdoCommandType_DeactivateTopologyInCommandResults,

    /// Represents the SelectAggregates command.
    FdoCommandType_SelectAggregates,

    /// Represents the CreateDataStore command.
    FdoCommandType_CreateDataStore,

    /// Represents the DestroyDataStore command.
    FdoCommandType_DestroyDataStore,

    /// Represents the ListDatastores command
	FdoCommandType_ListDataStores,

    /// Represents the index of the first provider specific command.
    FdoCommandType_FirstProviderCommand

};


#endif



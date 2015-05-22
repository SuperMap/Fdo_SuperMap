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
#define [!output UPPER_PREFIX]_MESSAGE_DEFINE
#include <../Message/inc/[!output PREFIX]Message.h>

#include <malloc.h>
#include <string.h>

// external access to connection for client services
extern "C" FDO[!output UPPER_PREFIX]_API FdoIConnection* CreateConnection ()
{
   return (new [!output PREFIX]Connection ());
}

[!output PREFIX]Connection::[!output PREFIX]Connection (void) :
    mConnectionString ((wchar_t*)NULL)
{
#pragma message ("ToDo: initialize the connection object")
}

[!output PREFIX]Connection::~[!output PREFIX]Connection (void)
{
#pragma message ("ToDo: rollback transactions, unlock transient locks, etc.")
}

// <summary>Dispose this object.</summary>
// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::Dispose ()
{
    delete this;
}

/// <summary>Gets an FdoIConnectionCapabilities interface describing the capabilities
/// of the connection.</summary>
/// <returns>Returns the connection capabilities</returns> 
FdoIConnectionCapabilities* [!output PREFIX]Connection::GetConnectionCapabilities ()
{
    return (new [!output PREFIX]ConnectionCapabilities ());
}

/// <summary>Gets an FdoISchemaCapabilities interface describing the provider's support for the feature schema.</summary>
/// <returns>Returns schema capabilities</returns> 
FdoISchemaCapabilities* [!output PREFIX]Connection::GetSchemaCapabilities ()
{
    return (new [!output PREFIX]SchemaCapabilities ());
}

/// <summary>Gets an FdoICommandCapabilities interface describing the commands a provider supports.</summary>
/// <returns>Returns the command capabilities</returns> 
FdoICommandCapabilities* [!output PREFIX]Connection::GetCommandCapabilities ()
{
    return (new [!output PREFIX]CommandCapabilities ());
}

/// <summary>Gets an FdoIFilterCapabilities interface describing the provider's support for filters.</summary>
/// <returns>Returns the filter capabilities</returns> 
FdoIFilterCapabilities* [!output PREFIX]Connection::GetFilterCapabilities ()
{
    return (new [!output PREFIX]FilterCapabilities ());
}

/// <summary>Gets an FdoIExpressionCapabilities interface describing the provider's support for expressions.</summary>
/// <returns>Returns the expression capabilities</returns> 
FdoIExpressionCapabilities* [!output PREFIX]Connection::GetExpressionCapabilities ()
{
    return (new [!output PREFIX]ExpressionCapabilities ());
}

/// <summary>Gets an FdoIRasterCapabilities interface describing the provider's support for raster images.</summary>
/// <returns>Returns the raster capabilities</returns> 
FdoIRasterCapabilities* [!output PREFIX]Connection::GetRasterCapabilities (void)
{
    return (new [!output PREFIX]RasterCapabilities ());
}

/// <summary>Gets an FdoITopologyCapabilities interface describing the provider's support for topology.</summary>
/// <returns>Returns the topology capabilities</returns> 
FdoITopologyCapabilities* [!output PREFIX]Connection::GetTopologyCapabilities ()
{
    return (new [!output PREFIX]TopologyCapabilities ());
}


/// Gets an FdoIGeometryCapabilities interface describing the provider's support for geometry
FdoIGeometryCapabilities* [!output PREFIX]Connection::GetGeometryCapabilities()
{
    return (new [!output PREFIX]GeometryCapabilities());
}

/// <summary>Gets the connection string used to open a DataStore.</summary>
/// <returns>Returns the connection string</returns> 
FdoString* [!output PREFIX]Connection::GetConnectionString ()
{
    return (mConnectionString);
}

/// <summary>Sets the connection string used to open a DataStore. SetConnectionString can only be set while the
/// connection is closed.</summary>
/// <param name="value">Input the connection string</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::SetConnectionString (FdoString* value)
{
    if ((GetConnectionState() == FdoConnectionState_Closed) || (GetConnectionState() == FdoConnectionState_Pending))
    {
        // Update the connection string:
        mConnectionString = value;

        // Update the connection property dictionary:
        FdoPtr<[!output PREFIX]ConnectionInfo> info = dynamic_cast<[!output PREFIX]ConnectionInfo*>(GetConnectionInfo ());
        FdoPtr<FdoCommonConnPropDictionary> dictionary = dynamic_cast<FdoCommonConnPropDictionary*>(info->GetConnectionProperties ());
        dictionary->UpdateFromConnectionString (mConnectionString);
    }
    else
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_103_CONNECTION_ALREADY_OPEN)));
}

/// <summary>Gets an FdoIConnectionInfo interface that can be used to interrogate and set connection properties.</summary>
/// <returns>Returns the connection info</returns> 
FdoIConnectionInfo* [!output PREFIX]Connection::GetConnectionInfo ()
{
    if (mConnectionInfo == NULL)
        mConnectionInfo = new [!output PREFIX]ConnectionInfo (this);
    return FDO_SAFE_ADDREF(mConnectionInfo.p);
}

/// <summary>Gets the current state of the connection.</summary>
/// <returns>Returns the current state of the connection</returns> 
FdoConnectionState [!output PREFIX]Connection::GetConnectionState ()
{
#pragma message ("ToDo: connection state (FdoConnectionState_Closed, FdoConnectionState_Pending, FdoConnectionState_Open)")
    return (FdoConnectionState_Closed);
}

/// <summary>Gets the number of milliseconds to wait while trying to establish a
/// connection before terminating the attempt and generating an error. If
/// the provider does not support the timeout capability 0 will be returned</summary>
/// <returns>Returns the time to wait (in milliseconds)</returns> 
FdoInt32 [!output PREFIX]Connection::GetConnectionTimeout ()
{
    return (0);
}

/// <summary>Sets the number of milliseconds to wait while trying to establish a
/// connection before terminating the attempt and generating an error. If
/// the provider does not support the timeout capability then attempting to
/// set a timeout will result in an exception</summary>
/// <param name="value">Input the time to wait (in milliseconds)</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::SetConnectionTimeout (FdoInt32 value)
{
    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_67_CONNECTION_TIMEOUT_NOT_SUPPORTED)));
}

/// <summary>Opens a feature connection with the settings specified by the
/// ConnectionString attribute of the provider-specific feature connection
/// object.</summary>
/// <returns>Returns nothing</returns> 
FdoConnectionState [!output PREFIX]Connection::Open ()
{
    return (GetConnectionState ());
}

/// <summary>Closes the connection to the DataStore</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::Close ()
{
}

/// <summary>Begins a transaction and returns an object that realizes
/// FdoITransaction.</summary>
/// <returns>Returns the transaction</returns> 
FdoITransaction* [!output PREFIX]Connection::BeginTransaction ()
{
[!if TRANSACTIONS]
    return (new [!output PREFIX]Transaction (this));
[!else]
    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_101_TRANSACTIONS_NOT_SUPPORTED)));
[!endif]
}

/// <summary>Creates and returns the specified type of command object associated with
/// the connection.</summary>
/// <param name="commandType">Input the command type to be created</param> 
/// <returns>Returns the command</returns> 
FdoICommand* [!output PREFIX]Connection::CreateCommand (FdoInt32 commandType)
{
    FdoPtr<FdoICommand> ret;

    switch (commandType)
    {
        case FdoCommandType_Select:
            ret = new [!output PREFIX]SelectCommand (this);
            break;
        case FdoCommandType_SelectAggregates:
            ret = new [!output PREFIX]SelectAggregatesCommand (this);
            break;
[!if READ_WRITE]
        case FdoCommandType_Insert:
            ret = new [!output PREFIX]InsertCommand (this);
            break;
        case FdoCommandType_Delete:
            ret = new [!output PREFIX]DeleteCommand (this);
            break;
        case FdoCommandType_Update:
            ret = new [!output PREFIX]UpdateCommand (this);
            break;
[!endif]
        case FdoCommandType_DescribeSchema:
            ret = new [!output PREFIX]DescribeSchemaCommand (this);
            break;
[!if META_DATA]
        case FdoCommandType_ApplySchema:
            ret = new [!output PREFIX]ApplySchemaCommand (this);
            break;
        case FdoCommandType_DestroySchema:
            ret = new [!output PREFIX]DestroySchemaCommand (this);
            break;
[!endif]
[!if SQL]
        case FdoCommandType_SQLCommand:
            ret = new [!output PREFIX]SQLCommand (this);
            break;
[!endif]
[!if LOCKING]
        case FdoCommandType_AcquireLock:
            ret = new [!output PREFIX]AcquireLockCommand (this);
            break;
        case FdoCommandType_GetLockInfo:
            ret = new [!output PREFIX]GetLockInfoCommand (this);
            break;
        case FdoCommandType_GetLockedObjects:
            ret = new [!output PREFIX]GetLockedObjectsCommand (this);
            break;
        case FdoCommandType_GetLockOwners:
            ret = new [!output PREFIX]GetLockOwnersCommand (this);
            break;
        case FdoCommandType_ReleaseLock:
            ret = new [!output PREFIX]ReleaseLockCommand (this);
            break;
[!endif]
[!if LONG_TRANSACTIONS]
        case FdoCommandType_ActivateLongTransaction:
            ret = new [!output PREFIX]ActivateLongTransactionCommand (this);
            break;
        case FdoCommandType_DeactivateLongTransaction:
            ret = new [!output PREFIX]DeactivateLongTransactionCommand (this);
            break;
        case FdoCommandType_CommitLongTransaction:
            ret = new [!output PREFIX]CommitLongTransactionCommand (this);
            break;
        case FdoCommandType_CreateLongTransaction:
            ret = new [!output PREFIX]CreateLongTransactionCommand (this);
            break;
        case FdoCommandType_GetLongTransactions:
            ret = new [!output PREFIX]GetLongTransactionsCommand (this);
            break;
        case FdoCommandType_RollbackLongTransaction:
            ret = new [!output PREFIX]RollbackLongTransactionCommand (this);
            break;
[!endif]
[!if ACTIVATE_SPATIAL_CONTEXT]
        case FdoCommandType_ActivateSpatialContext:
            ret = new [!output PREFIX]ActivateSpatialContext (this);
            break;
[!endif]
[!if CREATE_SPATIAL_CONTEXT]
        case FdoCommandType_CreateSpatialContext:
            ret = new [!output PREFIX]CreateSpatialContext (this);
            break;
[!endif]
[!if DESTROY_SPATIAL_CONTEXT]
        case FdoCommandType_DestroySpatialContext:
            ret = new [!output PREFIX]DestroySpatialContext (this);
            break;
[!endif]
[!if GET_SPATIAL_CONTEXT]
        case FdoCommandType_GetSpatialContexts:
            ret = new [!output PREFIX]GetSpatialContexts (this);
            break;
[!endif]
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_102_COMMAND_NOT_SUPPORTED, "The command '%1$ls' is not supported.", (FdoString*)(FdoCommonMiscUtil::FdoCommandTypeToString ((FdoCommandType)commandType))));
    }

    return (FDO_SAFE_ADDREF (ret.p));
}


/// <summary>Factory function that creates an empty Schema Override set specific
/// to this FDO Provider.</summary>
/// <returns>Returns FdoPhysicalSchemaMapping</returns> 
FdoPhysicalSchemaMapping* [!output PREFIX]Connection::CreateSchemaMapping()
{
#pragma message ("ToDo: schema mapping")
    return (NULL);
}


/// <summary>Sets the XML configuration stream used to configure the Data Store. 
/// SetConfiguration can only be called while the connection is closed.</summary>
/// <param name="configStream">Input the XML configuration stream</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::SetConfiguration(FdoIoStream* configStream)
{
    throw FdoException::Create(NlsMsgGet([!output UPPER_PREFIX]_CONNECTION_CONFIGURATION_FILE_NOT_SUPPORTED, "[!output PREFIX] Provider does not support configuration files."));
}

/// <summary>
/// Forces the writes of any cached data to the targed datastore.</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]Connection::Flush()
{
}


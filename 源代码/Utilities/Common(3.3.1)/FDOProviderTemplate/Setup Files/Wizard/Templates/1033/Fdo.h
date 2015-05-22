/*
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
 */

#ifndef FDO[!output UPPER_PREFIX]_H
#define FDO[!output UPPER_PREFIX]_H

// common C++ headers:
#include <malloc.h>
#include <limits>
#include <float.h>

// common STL headers:
#include <vector>

// OS-specific headers:
#ifndef _WIN32
#include <wctype.h>  // for wchar related functions
#endif

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the [!output UPPER_PREFIX]_EXPORTS
// symbol defined.  The [!output UPPER_PREFIX]_EXPORTS symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// [!output UPPER_PREFIX]_EXPORTS functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef _WIN32
#include <crtdbg.h>  // for _crtSetDbgFlag() and _CrtCheckMemory() and _ASSERTE
#pragma once

#ifdef [!output UPPER_PREFIX]_EXPORTS
	#define FDO[!output UPPER_PREFIX]_API __declspec(dllexport)
#else // [!output UPPER_PREFIX]_EXPORTS
	#define FDO[!output UPPER_PREFIX]_API __declspec(dllimport)
#endif // [!output UPPER_PREFIX]_EXPORTS

#else // _WIN32

#define FDO[!output UPPER_PREFIX]_API

#endif // _WIN32

// Base FDO headers
#include <Fdo.h>

// FDO Common headers
#include <FdoCommonCommand.h>
#include <FdoCommonFeatureCommand.h>
#include <FdoCommonConnPropDictionary.h>
#include <FdoCommonMiscUtil.h>

#include <[!output PREFIX]Provider.h>
#include <../Message/inc/[!output PREFIX]Message.h>
#include <[!output PREFIX]ConnectionCapabilities.h>
#include <[!output PREFIX]CommandCapabilities.h>
#include <[!output PREFIX]ExpressionCapabilities.h>
#include <[!output PREFIX]FilterCapabilities.h>
#include <[!output PREFIX]SchemaCapabilities.h>
#include <[!output PREFIX]RasterCapabilities.h>
#include <[!output PREFIX]TopologyCapabilities.h>
#include <[!output PREFIX]GeometryCapabilities.h>
#include <[!output PREFIX]Connection.h>
#include <[!output PREFIX]ConnectionInfo.h>
#include <[!output PREFIX]DescribeSchemaCommand.h>
#include <[!output PREFIX]Reader.h>
#include <[!output PREFIX]FeatureReader.h>
#include <[!output PREFIX]SelectCommand.h>
#include <[!output PREFIX]DataReader.h>
#include <[!output PREFIX]SelectAggregatesCommand.h>
#include <[!output PREFIX]Command.h>
#include <[!output PREFIX]FeatureCommand.h>
#include <[!output PREFIX]ApplySchemaCommand.h>
#include <[!output PREFIX]DestroySchemaCommand.h>
[!if SQL]
#include <[!output PREFIX]SQLDataReader.h>
#include <[!output PREFIX]SQLCommand.h>
[!endif]
[!if TRANSACTIONS]
#include <[!output PREFIX]Transaction.h>
[!endif]
[!if READ_WRITE]
#include <[!output PREFIX]InsertCommand.h>
#include <[!output PREFIX]UpdateCommand.h>
#include <[!output PREFIX]DeleteCommand.h>
[!endif]
[!if LOCKING]
#include <[!output PREFIX]LockConflictReader.h>
#include <[!output PREFIX]LockOwnersReader.h>
#include <[!output PREFIX]ReleaseLockCommand.h>
#include <[!output PREFIX]AcquireLockCommand.h>
#include <[!output PREFIX]GetLockInfoCommand.h>
#include <[!output PREFIX]LockedObjectReader.h>
#include <[!output PREFIX]GetLockOwnersCommand.h>
#include <[!output PREFIX]GetLockedObjectsCommand.h>
[!endif]
[!if ACTIVATE_SPATIAL_CONTEXT]
#include <[!output PREFIX]ActivateSpatialContext.h>
[!endif]
[!if GET_SPATIAL_CONTEXT]
#include <[!output PREFIX]GetSpatialContexts.h>
#include <[!output PREFIX]SpatialContextReader.h>
[!endif]
[!if CREATE_SPATIAL_CONTEXT]
#include <[!output PREFIX]CreateSpatialContext.h>
[!endif]
[!if DESTROY_SPATIAL_CONTEXT]
#include <[!output PREFIX]DestroySpatialContext.h>
[!endif]
[!if LONG_TRANSACTIONS]
#include <[!output PREFIX]LongTransactionReader.h>
#include <[!output PREFIX]ActivateLongTransactionCommand.h>
#include <[!output PREFIX]DeactivateLongTransactionCommand.h>
#include <[!output PREFIX]CommitLongTransactionCommand.h>
#include <[!output PREFIX]CreateLongTransactionCommand.h>
#include <[!output PREFIX]GetLongTransactionsCommand.h>
#include <[!output PREFIX]RollbackLongTransactionCommand.h>
[!endif]

#endif // FDO[!output UPPER_PREFIX]_H


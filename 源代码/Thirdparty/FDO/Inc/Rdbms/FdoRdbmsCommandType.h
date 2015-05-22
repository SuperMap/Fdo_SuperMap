#ifndef _FDORDBMSCOMMANDTYPE_H_
#define _FDORDBMSCOMMANDTYPE_H_
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

/// <library>
/// FdoRdbms.lib
/// </library>

#ifdef _WIN32
#pragma once
#endif

#include "Fdo/Commands/CommandType.h"


// If you want to know where we got this number it's one
// of the perfect square triangular numbers ...
// We picked this number so our custom commands wouldn't clash with other
// custom provider commands.
#define FDO_RBMDS_FIRST_PROVIDER_COMMAND 41616


/// <summary>The FdoRdbmsCommandType enumeration defines the list of Rdbms commands.</summary>
/// <param name="FdoRdbmsCommandType_CreateSpatialIndex">Represents the CreateSpatialIndex command.</param>
/// <param name="FdoRdbmsCommandType_DestroySpatialIndex">Represents the DestroySpatialIndex command.</param>
/// <param name="FdoRdbmsCommandType_GetSpatialIndexes">Represents the GetSpatialIndices command.</param>

enum FdoRdbmsCommandType{

    // Represents the CreateSpatialIndex command.
    FdoRdbmsCommandType_CreateSpatialIndex =  FdoCommandType_FirstProviderCommand + FDO_RBMDS_FIRST_PROVIDER_COMMAND,

    // Represents the DestroySpatialIndex command.
    FdoRdbmsCommandType_DestroySpatialIndex,

    // Represents the GetSpatialIndices command.
    FdoRdbmsCommandType_GetSpatialIndexes
};


#endif


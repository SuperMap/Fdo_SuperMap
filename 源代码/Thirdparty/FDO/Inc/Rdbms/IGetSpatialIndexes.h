#ifndef _IGETSPATIALINDEXES_H_
#define _IGETSPATIALINDEXES_H_
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

#include "FdoStd.h"
#include "Fdo/Commands/ICommand.h"
#include "Rdbms/ISpatialIndexReader.h"

/// <summary>The IGetSpatialIndexes interface defines the GetSpatialIndexes command,
/// which enumerates the existing spatial indexes.</summary>
class FdoIGetSpatialIndexes : public FdoICommand
{
public:
    ///<summary> Gets a Boolean flag that indicates if the GetSpatialIndexes command
    /// will return only the spatial indexes of the active spatial contexts or all spatial indexes.
    /// The default value of this flag is false, return all spatial indexes. </summary>
    /// <returns>Returns the value of the Boolean flag </returns>
    FDO_API virtual const bool GetActiveOnly() = 0;

    /// <summary> Gets a Boolean flag that indicates if the GetSpatialIndexes command
    /// will return only the spatial indexes of the active spatial contexts or all spatial indexes. </summary>
    /// <param name="value">Input the Boolean flag</param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetActiveOnly(const bool value) = 0;

    /// <summary>Executes the GetSpatialIndexes command returning an ISpatialIndexReader.</summary>
    /// <returns>Returns ISpatialIndexReader</returns>
    FDO_API virtual FdoISpatialIndexReader* Execute() = 0;
};
#endif


#ifndef _ISPATIALINDEXREADER_H_
#define _ISPATIALINDEXREADER_H_
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

#include "Fdo.h"
#include "Rdbms/SpatialIndexDimensionType.h"
#include "Rdbms/SpatialIndexType.h"


/// <summary>The ISpatialIndexReader interface provides forward only, readonly
/// functionality for enumerating spatial indexes.  A reference to an
/// ISpatialIndexReader is returned from the GetSpatialIndexes command.
/// The initial position of the ISpatialIndexReader is prior to the
/// first item. Therefore you must call ReadNext to begin accessing any data.</summary>
class FdoISpatialIndexReader : public FdoIDisposable
{
public:
    /// <summary>Gets the name of the spatial index currently being read.</summary>
    /// <returns>Returns the name of the spatial context.</returns>
    FDO_API virtual const wchar_t* GetName() = 0;

    /// <summary>Gets the name of the current spatial context as a String.</summary>
    /// <returns>Returns the description of the spatial context </returns>
    FDO_API virtual const wchar_t* GetSpatialContextName() = 0;

    /// <summary>Gets the type of the current spatial Index, either Quad-Tree or R-Tree.</summary>
    /// <returns>Returns the spatial index type</returns>
    FDO_API virtual SpatialIndexType GetSpatialIndexType() = 0;

    /// <summary>Gets the number of dimensions of the current spatial Index.</summary>
    /// <returns>Returns the extent type</returns>
    FDO_API virtual SpatialIndexDimensionType GetNumDimensions() = 0;

    /// <summary>Advances the reader to the next item. The default position of the reader
    /// is prior to the first item. Therefore you must call ReadNext to begin
    /// accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns>
    FDO_API virtual bool ReadNext() = 0;

    /// <summary>Closes the ISpatialIndexReader object freeing any resources it may
    /// be holding.</summary>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void Dispose() = 0;
};
#endif


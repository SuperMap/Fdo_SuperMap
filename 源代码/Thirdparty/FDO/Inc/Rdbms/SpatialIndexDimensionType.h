#ifndef _SPATIALINDEXDIMENSIONTYPE_H_
#define _SPATIALINDEXDIMENSIONTYPE_H_
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

/// <summary>The SpatialIndexDimensionType enumeration defines the spatial data number of dimensions
/// used by spatial indexing.</summary>
/// <param name="SpatialIndexDimension_Default">The number of dimensions used by the spatial index is defaulted.</param>
/// <param name="SpatialIndexDimension_2D">The number of dimensions used by the spatial index is 2.</param>
/// <param name="SpatialIndexDimension_3D">The number of dimensions used by the spatial index is 3.</param>

enum SpatialIndexDimensionType
{
    // The number of dimensions used by the spatial index is defaulted
    SpatialIndexDimension_Default,

    // The number of dimensions used by the spatial index is 2
    SpatialIndexDimension_2D,

    // The number of dimensions used by the spatial index is 3
    SpatialIndexDimension_3D
};

#endif


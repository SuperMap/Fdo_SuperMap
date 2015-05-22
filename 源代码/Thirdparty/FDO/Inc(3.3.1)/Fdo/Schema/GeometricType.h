#ifndef _GEOMETRICTYPE_H_
#define _GEOMETRICTYPE_H_

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
/// The FdoGeometricType enumeration categorizes all of the geometry types
/// supported by FDO based on their geometric dimensionality.
enum FdoGeometricType
{
    /// Represents 0-dimensional geometric primitives, such as Points.
    FdoGeometricType_Point = 0x01,

    /// Represents 1 dimensional geometric primitives, such as Curves and Lines.
    FdoGeometricType_Curve = 0x02,

    /// Represents 2 dimensional geometric primitives, such as Polygons.
    FdoGeometricType_Surface = 0x04,

    /// Represents 3 dimensional geometric primitives, such as Cubes.
    FdoGeometricType_Solid = 0x08
};

#define FdoGeometricType_All    FdoGeometricType_Point|FdoGeometricType_Curve|FdoGeometricType_Surface|FdoGeometricType_Solid

#endif



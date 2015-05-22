#ifndef _PROPERTYTYPE_H_
#define _PROPERTYTYPE_H_

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
/// The FdoPropertyType enumeration lists the possible types that a Property can be.
enum FdoPropertyType
{
    /// Represents a Data Property type.
    FdoPropertyType_DataProperty,

    /// Represents an Object Property type.
    FdoPropertyType_ObjectProperty,

    /// Represents a Geometric Property type.
    FdoPropertyType_GeometricProperty,

    /// Represents an Association Property type.
    FdoPropertyType_AssociationProperty,

    /// Represents a Raster (image) Property type.
    FdoPropertyType_RasterProperty
};
#endif



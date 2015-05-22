#ifndef _RASTERDATATYPE_H_
#define _RASTERDATATYPE_H_

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

#include <FdoStd.h>

/// \ingroup (enums)
/// \brief
/// The FdoRasterDataType enumeration specifies the type of data stored in the Raster Image.
enum FdoRasterDataType
{
    /// Data is organized in an unknown or provider specific manner.
    FdoRasterDataType_Unknown,

    /// Data is organized as Unsigned Integers.
    FdoRasterDataType_UnsignedInteger,

    /// Data is organized as Signed Integers.
    FdoRasterDataType_Integer,

    /// Data is organized as Floats.
    FdoRasterDataType_Float,

    /// Data is organized as Doubles.
    FdoRasterDataType_Double
};

#endif // _RASTERDATATYPE_H_



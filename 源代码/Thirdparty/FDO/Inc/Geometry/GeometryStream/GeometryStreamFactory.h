#ifndef _GEOMETRYSTREAMFACTORY_H_
#define _GEOMETRYSTREAMFACTORY_H_

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

#include <FdoCommon.h>
#include <Geometry/GeometryStream/GeometryStreamReader.h>
#include <Geometry/GeometryStream/GeometryStreamWriter.h>

/// \brief
/// The FdoGeometryStreamFactory class is a factory (abstract) for classes dealing with serialized geometric data.
/// The data source is defined by the implementation.
/// This is a helper type and does not inherit from FdoIGeometry.
class FdoGeometryStreamFactory /* Abstract */ : public FdoIDisposable
{
public:

    /// \brief
    /// Gets a stream reader object for serialized Geometry.
    /// 
    /// \param byteArray 
    /// Input array of Geometry data in FGF format.
    /// 
    /// \return
    /// Returns the reader
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamReader* CreateGeometryStreamReader(
        FdoByteArray * byteArray) = 0;

    /// \brief
    /// Gets a stream reader object for serialized Geometry.
    /// 
    /// \param data 
    /// Input array data
    /// \param count 
    /// Input number of bytes in the array
    /// The caller must guarantee the validity of the array for the lifetime
    /// of the associated geometry stream.
    /// 
    /// \return
    /// Returns the reader
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamReader* CreateGeometryStreamReader(
        const FdoByte * data,
        FdoInt32 count) = 0;

    /// \brief
    /// Gets a stream writer object for serialized Geometry in FGF format.
    /// 
    /// \return
    /// Returns the writer
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamWriter* CreateGeometryStreamWriter() = 0;

protected:
    /// Constructor and destructor

    /// \brief
    /// Constructs a default instance of a FdoGeometryStreamFactory.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoGeometryStreamFactory() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoGeometryStreamFactory() {};
};
#endif



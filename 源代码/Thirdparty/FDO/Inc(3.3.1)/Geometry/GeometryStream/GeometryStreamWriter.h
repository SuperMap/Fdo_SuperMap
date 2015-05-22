#ifndef _GEOMETRYSTREAMWRITER_H_
#define _GEOMETRYSTREAMWRITER_H_

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
#include <Geometry/IDirectPosition.h>
#include <Geometry/GeometryStream/GeometryStreamReader.h>
#include <Geometry/ILinearRing.h>

class FdoGeometryStreamFactory; // forward declare

/// \brief
/// The FdoGeometryStreamWriter class is a writer for geometric data (abstract). The destination for the data is defined by the implementation.
/// FdoGeometryStreamWriter is a helper type and does not inherit from FdoIGeometry.
class FdoGeometryStreamWriter /* Abstract */ : public FdoIDisposable
{
public:

    /// \brief
    /// Gets a reader of data on this object's stream.
    /// 
    /// \return
    /// Returns a Geometry stream reader
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamReader* GetReader() = 0;

    /// \brief
    /// Writes one number as a "double" into the stream.
    /// 
    /// \param value 
    /// Input Data value to write into the stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void WriteDouble(
        double value) = 0;

    /// \brief
    /// Writes one number as a "FdoInt32" into the stream.
    /// 
    /// \param value 
    /// Input Data value to write into the stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void WriteInt(
        FdoInt32 value) = 0;

    /// \brief
    /// Writes one byte into the stream.
    /// 
    /// \param value 
    /// Input Data value to write into the stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void WriteByte(
        FdoByte value) = 0;

    /// \brief
    /// Writes a geometric position into the stream.  The position's dimension is 
    /// taken from the position, itself.
    /// 
    /// \param value 
    /// Input Data value to write into the stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void WriteDirectPosition(
        FdoIDirectPosition * value) = 0;

    /// \brief
    /// Gets a factory object that can create more streams of the same implementation type as this object.
    /// 
    /// \return
    /// Returns A Geometry stream factory
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamFactory * GetFactory() = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoGeometryStreamWriter() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoGeometryStreamWriter() {};
};
#endif



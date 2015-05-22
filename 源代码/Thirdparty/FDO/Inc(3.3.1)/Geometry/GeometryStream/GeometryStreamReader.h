#ifndef _GEOMETRYSTREAMREADER_H_
#define _GEOMETRYSTREAMREADER_H_

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
#include <Common/Dimensionality.h>
#include <Geometry/IDirectPosition.h>
#include <Geometry/ILinearRing.h>

class FdoGeometryStreamFactory; // forward declare

/// \brief
/// The FdoGeometryStreamReader class is a reader for serialized geometric data (abstract). The data source is defined by the implementation.
/// FdoGeometryStreamReader is a helper type and does not inherit from FdoIGeometry.
class FdoGeometryStreamReader /* Abstract */ : public FdoIDisposable
{
public:

    /// \brief
    /// Gets an array representing the entire serialized Geometry.
    /// 
    /// \return
    /// Returns the byte array
    /// 
    FDO_GEOM_API virtual FdoByteArray * GetData() = 0;

    /// \brief
    /// Sets the array used by the reader.
    /// 
    /// \param data 
    /// Input array object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SetData(
        FdoByteArray * data) = 0;

    /// \brief
    /// Sets the array used by the reader.
    /// 
    /// \param data 
    /// Input array data
    /// \param count 
    /// Input number of bytes in the array
    /// The caller must guarantee the validity of the array for the lifetime
    /// of the associated geometry stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SetData(
        const FdoByte * data,
        FdoInt32 count) = 0;

    /// \brief
    /// Gets the amount of data in the array returned by GetData(), in bytes.
    /// 
    /// \return
    /// Returns the number of bytes of Geometry data
    /// 
    FDO_GEOM_API virtual FdoInt32 GetLength() = 0;


    /// \brief
    /// Advances the current position by skipping past bytes.
    /// 
    /// \param count 
    /// Input number of bytes to skip
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SkipBytes(
        FdoInt32 count) = 0;


    /// \brief
    /// Advances the current position by skipping past integers.
    /// 
    /// \param count 
    /// Input number of integers to skip
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SkipInts(
        FdoInt32 count) = 0;


    /// \brief
    /// Advances the current position by skipping past doubles.
    /// 
    /// \param count 
    /// Input number of doubles to skip
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SkipDoubles(
        FdoInt32 count) = 0;


    /// \brief
    /// Advances the current position by skipping past geometric
    /// positions with the given dimension.
    /// 
    /// \param dimension 
    /// Input dimensionality of the positions (see FdoDimensionality)
    /// \param count 
    /// Input number of positions to skip
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void SkipDirectPositions(
        FdoInt32 dimension,
        FdoInt32 count) = 0;

    /// \brief
    /// Resets the current position to the beginning of the stream.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void Reset() = 0;

    /// \brief
    /// Reads one number as a "double" from current position in the stream.
    /// 
    /// \return
    /// Returns The next number in the stream
    /// 
    FDO_GEOM_API virtual double ReadDouble() = 0;

    /// \brief
    /// Reads one number as a "FdoInt32" from the stream.
    /// 
    /// \return
    /// Returns The next number in the stream
    /// 
    FDO_GEOM_API virtual FdoInt32 ReadInt() = 0;

    /// \brief
    /// Reads one byte from the stream.
    /// 
    /// \return
    /// Returns The next byte in the stream
    /// 
    FDO_GEOM_API virtual FdoByte ReadByte() = 0;

    /// \brief
    /// Reads a geometric position with the given dimensionality from the stream.
    /// 
    /// \return
    /// Returns The numbers in the stream as a FdoIDirectPosition
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition * ReadDirectPosition(FdoInt32 dimension) = 0;

    /// \brief
    /// Reads a geometric position with the given dimensionality from the stream, 
    /// by value of its ordinates (for performance).
    /// 
    /// \param dimensionality 
    /// Input Dimensionality of ordinates in this position.
    /// \param x 
    /// Output X ordinate value.
    /// \param y 
    /// Output Y ordinate value.
    /// \param z 
    /// Output Z ordinate value.
    /// \param m 
    /// Output M ordinate value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void ReadDirectPositionByMembers(FdoInt32 dimensionality, double *x, double *y, double *z, double *m) = 0;

    /// \brief
    /// Gets a factory object that can create more streams of the same implementation type as this object.
    /// 
    /// \return
    /// Returns A Geometry stream factory
    /// 
    FDO_GEOM_API virtual FdoGeometryStreamFactory * GetFactory() = 0;

protected:

    /// \brief
    /// Constructs a default instance of a FdoGeometryStreamReader.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoGeometryStreamReader() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoGeometryStreamReader() {};
};
#endif



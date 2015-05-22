#ifndef _IGEOMETRY_H_
#define _IGEOMETRY_H_

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
#include <Geometry/IEnvelope.h>
#include <Common/Dimensionality.h>
#include <Common/GeometryType.h>
#include <Common/Collection.h>

/// \brief
/// The FdoIGeometry class defines the properties and methods common to all geometric
/// types.  FdoIGeometry is an abstract type.
class FdoIGeometry : public FdoIDisposable
{
public:

    /// \brief
    /// Gets the envelope for the Geometry.
    /// 
    /// \return
    /// Returns the envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* GetEnvelope() const = 0;

    /// \brief
    /// Gets the dimensionality of ordinates in this object.
    /// 
    /// \remarks
    ///  Values are from the FdoDimensionality enumeration.
    /// A return type of "FdoInt32" is used instead of the enumeration, catering to typical use with bit masking.
    /// 
    /// \return
    /// Returns the ordinate dimensionality
    /// 
    FDO_GEOM_API virtual FdoInt32 GetDimensionality() const = 0;

    /// \brief
    /// Gets the type of the most-derived interface 
    /// in the Geometry package for this object
    /// 
    /// \remarks
    ///  The derived type indicates to what class the object may safely be cast.
    /// 
    /// \return
    /// Returns the derived type
    /// 
    FDO_GEOM_API virtual FdoGeometryType GetDerivedType() const = 0;

    /// \brief
    /// Gets the text string representation of this Geometry.
    /// 
    /// \remarks
    /// This object retains ownership of the string.
    /// The caller should NOT attempt to free it.
    /// The text string may be retained in memory by the object indefinitely.
    /// Calling this method on a large number of Geometries that are retained
    /// in memory may cause a noticable increase in memory consumption.
    /// 
    /// \return
    /// Returns the text string
    /// 
    FDO_GEOM_API virtual FdoString* GetText() = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIGeometry() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIGeometry() {};
};


/// \brief
///  Collection of CurvePolygon objects.
class FdoGeometryCollection : public FdoCollection<FdoIGeometry, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoGeometryCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoGeometryCollection* Create()
    {
        FdoGeometryCollection* value = new FdoGeometryCollection();
        if (NULL == value)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));

        return value;
    }

protected:
    void Dispose()
    {
        delete this;
    }
};
#endif



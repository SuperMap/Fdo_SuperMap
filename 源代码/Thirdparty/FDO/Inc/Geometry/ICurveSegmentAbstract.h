#ifndef _ICURVESEGMENTABSTRACT_H_
#define _ICURVESEGMENTABSTRACT_H_

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
#include <Common/Collection.h>
#include <Geometry/IDirectPosition.h>
#include <Geometry/IEnvelope.h>
#include <Common/GeometryType.h>
#include <Common/Dimensionality.h>

/// \brief
/// The FdoICurveSegmentAbstract class is an abstract geometric Curve Segment object.  
/// This class is used strictly as a component of curves 
/// and, thus, does not inherit from IGeometry.
class FdoICurveSegmentAbstract : public FdoIDisposable
{
public:

    /// \brief
    /// Gets the envelope for the curve segment.
    /// 
    /// \return
    /// Returns the envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* GetEnvelope() const = 0;

    /// \brief
    /// Gets the starting position of this curve segment.
    /// 
    /// \return
    /// Returns the starting position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetStartPosition() const = 0;

    /// \brief
    /// Gets the ending position of this curve segment.
    /// 
    /// \return
    /// Returns the ending position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetEndPosition() const = 0;

    /// \brief
    /// Gets the closure state for the curve segment.
    /// 
    /// \remarks
    /// The meaning behind this method is not guaranteed
    /// to be uniform between derived types or between implementations
    /// of this package.
    /// It may represent a computed value, an explicit attribute, or be true by definition.
    /// As a computed value, the result is typically from simply testing the starting and 
    /// ending positions for exact equality.  This is only reliable in floating
    /// point arithmetic if these data have identical origins.
    /// As an explicit attribute, it would be persisted with the Geometry and 
    /// typically denoted by a parameter in the relevant factory method.  
    /// Some Geometry types are closed by definition.
    /// 
    /// \return
    /// Returns 'true' if the curve is closed, and false otherwise
    /// 
    FDO_GEOM_API virtual bool GetIsClosed() const = 0;

    /// \brief
    /// Gets the type of the most-derived interface 
    /// in the Geometry package for this object
    /// 
    /// \return
    /// Returns the derived type
    /// 
    FDO_GEOM_API virtual FdoGeometryComponentType GetDerivedType() const = 0;

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

protected:

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoICurveSegmentAbstract() {};

};


/// \brief
///  The FdoCurveSegmentCollection class is a collection of CurveSegment objects.
class FdoCurveSegmentCollection : public FdoCollection<FdoICurveSegmentAbstract, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoCurveSegmentCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoCurveSegmentCollection* Create()
    {
        FdoCurveSegmentCollection* value = new FdoCurveSegmentCollection();
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



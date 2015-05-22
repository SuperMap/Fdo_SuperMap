#ifndef _IENVELOPE_H_
#define _IENVELOPE_H_

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

/// \brief
/// The FdoIEnvelope class is a three-dimensional, axis-aligned box.  This is a
/// helper type for Geometries, and does not itself inherit from
/// IGeometry.
/// This type is typically used to record the "extents" of a shape, also
/// known in 2 dimensions as an MBR ("Minimum Bounding Rectangle").
/// The box may be initially empty, meaning that no dimensions have an
/// assigned value.
/// each individual extent may be unassigned, in which case using its
/// accessor will return numeric_limits<double>::quiet_NaN().
class FdoIEnvelope : public FdoIDisposable
{
public:

    /// \brief
    /// Gets the minimum X coordinate value.
    /// 
    /// \remarks
    /// This is the smallest X ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the X coordinate for the point in the rear, lower-left
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the miniumum X ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMinX() const = 0;

    /// \brief
    /// Gets the minimum Y coordinate value.
    /// 
    /// \remarks
    /// This is the smallest Y ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the Y coordinate for the point in the rear, lower-left
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the miniumum Y ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMinY() const = 0;

    /// \brief
    /// Gets the minimum Z coordinate value.
    /// 
    /// \remarks
    /// This is the smallest Z ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the Z coordinate for the point in the rear, lower-left
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the miniumum Z ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMinZ() const = 0;

    /// \brief
    /// Gets the maximum X coordinate value.
    /// 
    /// \remarks
    /// This is the largest X ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the X coordinate for the point in the front, upper-right
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the maxiumum X ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMaxX() const = 0;

    /// \brief
    /// Gets the maximum Y coordinate value.
    /// 
    /// \remarks
    /// This is the largest Y ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the Y coordinate for the point in the front, upper-right
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the maxiumum Y ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMaxY() const = 0;

    /// \brief
    /// Gets the maximum Z coordinate value.
    /// 
    /// \remarks
    /// This is the largest Z ordinate value for the envelope, regardless
    /// of the sense of the axes.  In a conventional right-handed system,
    /// this would be the Z coordinate for the point in the front, upper-right
    /// corner of the envelope.
    /// 
    /// \return
    /// Returns the maxiumum Z ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API virtual double GetMaxZ() const = 0;

    /// \brief
    /// Gets the ordinates as an array.
    /// 
    /// \remarks
    /// The caller must not free the returned array.
    /// The ordinates are in the order XYZXYZ, with only those present 
    /// according to the dimensionality.
    /// 
    /// \return
    /// Returns the ordinates
    /// 
    FDO_GEOM_API virtual const double * GetOrdinates() = 0;

    /// \brief
    /// Indicates whether the envelope's extents are set.
    /// 
    /// \return
    /// Returns 'true' if none of the X, Y and Z extents have been set; 'false' otherwise
    /// 
    FDO_GEOM_API virtual bool GetIsEmpty() const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIEnvelope() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIEnvelope() {};

};
#endif



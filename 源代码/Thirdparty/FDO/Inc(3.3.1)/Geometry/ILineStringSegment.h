#ifndef _ILINESTRINGSEGMENT_H_
#define _ILINESTRINGSEGMENT_H_

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

#include <Geometry/ICurveSegmentAbstract.h>
#include <Geometry/IDirectPosition.h>

/// \brief
/// The FdoILineStringSegment class is a LineString curve segment type.  
/// The shape of FdoILineStringSegment is the set of positions defined by the contained collection, 
/// plus linear interpolation between consecutive points.
/// This is a helper type for Geometries in the Geometry package.
/// \note
/// It does not derive from IGeometry.
class FdoILineStringSegment : public FdoICurveSegmentAbstract
{
public:

    /// \brief
    /// Gets the number of positions in this object.
    /// 
    /// \return
    /// Returns the number of positions
    /// 
    FDO_GEOM_API virtual FdoInt32 GetCount() const = 0;

    /// \brief
    /// Gets the position at the specified (zero-based) index.
    /// 
    /// \return
    /// Returns the position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetItem(
        FdoInt32 index) const = 0;

    /// \brief
    /// Gets a collection of all of the positions in this object.
    /// 
    /// \return
    /// Returns the positions
    /// 
    FDO_GEOM_API virtual FdoDirectPositionCollection* GetPositions() = 0;

    /// \brief
    /// Gets the ordinates as an array.
    /// 
    /// \remarks
    /// The caller must not free the returned array.
    /// The ordinates are in the order XYZMXYZM..., with only those present 
    /// according to the dimensionality.
    /// 
    /// \return
    /// Returns the ordinates
    /// 
    FDO_GEOM_API virtual const double * GetOrdinates() = 0;
    
protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoILineStringSegment() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoILineStringSegment() {};

};
#endif



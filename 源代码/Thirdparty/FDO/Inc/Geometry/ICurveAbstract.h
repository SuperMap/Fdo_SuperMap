#ifndef _ICURVEABSTRACT_H_
#define _ICURVEABSTRACT_H_

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

#include <Geometry/IGeometry.h>
#include <Geometry/IDirectPosition.h>

/// \brief
/// The FdoICurveAbstract class is a curve Geometry type (abstract). FdoICurveAbstract is the most general curve type.  
class FdoICurveAbstract : public FdoIGeometry
{
public:
    /// \brief
    /// Gets the starting position of this Curve.
    /// 
    /// \remarks
    ///  This is the start of the entire curve.  In cases where a derived type
    /// is composed of multiple contiguous parts, this position is the start of the
    /// first of those parts.
    /// 
    /// \return
    /// Returns the starting position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetStartPosition() const = 0;

    /// \brief
    /// Gets the ending position of this Curve.
    /// 
    /// \remarks
    ///  This is the end of the entire curve.  In cases where a derived type
    /// is composed of multiple contiguous parts, this position is the end of the
    /// last of those parts.
    /// 
    /// \return
    /// Returns the ending position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetEndPosition() const = 0;

    /// \brief
    /// Gets the closure state for the curve.
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
};
#endif



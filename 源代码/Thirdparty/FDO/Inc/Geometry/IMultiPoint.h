#ifndef _IMULTIPOINT_H_
#define _IMULTIPOINT_H_

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

#include <Geometry/IGeometricAggregateAbstract.h>
#include <Geometry/IPoint.h>

/// \brief
/// The FdoIMultiPoint class is a multi-point aggregate Geometry type.
class FdoIMultiPoint : public FdoIGeometricAggregateAbstract
{
public:

    /// \brief
    /// Gets a point at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of points.
    /// 
    /// \return
    /// Returns a point
    /// 
    FDO_GEOM_API virtual FdoIPoint* GetItem(
        FdoInt32 index) const = 0;

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
    FDO_GEOM_API FdoIMultiPoint() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIMultiPoint() {};
};
#endif



#ifndef _IMULTICURVEPOLYGON_H_
#define _IMULTICURVEPOLYGON_H_

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
#include <Geometry/ICurvePolygon.h>

/// \brief
/// The FdoIMultiCurvePolygon class is a multi-CurvePolygon aggregate Geometry type.
class FdoIMultiCurvePolygon : public FdoIGeometricAggregateAbstract
{
public:

    /// \brief
    /// Gets a CurvePolygon at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of polygons.
    /// 
    /// \return
    /// Returns a CurvePolygon
    /// 
    FDO_GEOM_API virtual FdoICurvePolygon* GetItem(
        FdoInt32 index) const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIMultiCurvePolygon() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIMultiCurvePolygon() {};

};
#endif



#ifndef _IMULTIPOLYGON_H_
#define _IMULTIPOLYGON_H_

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
#include <Geometry/IPolygon.h>

/// \brief
/// The FdoIMultiPolygon class is a multi-polygon aggregate Geometry type.
class FdoIMultiPolygon : public FdoIGeometricAggregateAbstract
{
public:

    /// \brief
    /// Gets a polygon at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of polygons.
    /// 
    /// \return
    /// Returns a polygon
    /// 
    FDO_GEOM_API virtual FdoIPolygon* GetItem(
        FdoInt32 index) const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIMultiPolygon() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIMultiPolygon() {};

};
#endif



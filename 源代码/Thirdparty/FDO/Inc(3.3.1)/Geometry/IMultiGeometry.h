#ifndef _IMULTIGEOMETRY_H_
#define _IMULTIGEOMETRY_H_

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
#include <Geometry/IGeometry.h>

/// \brief
/// The FdoIMultiGeometry class is a heterogeneous MultiGeometry type.
/// One MultiGeometry containing another MultiGeometry
/// is not supported.
class FdoIMultiGeometry : public FdoIGeometricAggregateAbstract
{
public:

    /// \brief
    /// Gets a Geometry at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of geometries.
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry* GetItem(
        FdoInt32 index) const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIMultiGeometry() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIMultiGeometry() {};

};
#endif



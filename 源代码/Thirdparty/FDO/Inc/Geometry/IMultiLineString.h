#ifndef _IMULTILINESTRING_H_
#define _IMULTILINESTRING_H_

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
#include <Geometry/ILineString.h>

/// \brief
/// The FdoIMultiLineString class is a multi-LineString collection geometry type.
/// The curves contained here do not have to
/// be contiguous, nor spatially interact in any other way.
class FdoIMultiLineString : public FdoIGeometricAggregateAbstract
{
public:

    /// \brief
    /// Gets a LineString at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of line strings.
    /// 
    /// \return
    /// Returns a CurveString
    /// 
    FDO_GEOM_API virtual FdoILineString* GetItem(
        FdoInt32 index) const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIMultiLineString() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIMultiLineString() {};
};
#endif



#ifndef _SPATIALOPERATIONS_H_
#define _SPATIALOPERATIONS_H_
// 

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

/// \ingroup (enums)
/// \brief
/// The FdoSpatialOperations enumeration lists the spatial conditions available.
enum FdoSpatialOperations
{
    /// Test to see if the geometric property value spatially contains the
    /// literal geometric value.
    FdoSpatialOperations_Contains,

    /// Test to see if the geometric property value spatially crosses the given
    /// geometry.
    FdoSpatialOperations_Crosses,

    /// Test to see if the geometric property value is spatially
    /// disjoint from the given geometry.
    FdoSpatialOperations_Disjoint,

    /// Test to see if the geometric property value is spatially equal to the
    /// given geometry.
    FdoSpatialOperations_Equals,

    /// Test to see if the geometric property value spatially intersects the
    /// given geometry.
    FdoSpatialOperations_Intersects,

    /// Test to see if the geometric property value spatially overlaps the given
    /// geometry.
    FdoSpatialOperations_Overlaps,

    /// Test to see if the geometric property value spatially touches the given
    /// geometry.
    FdoSpatialOperations_Touches,

    /// Test to see if the geometric property value is spatially within the
    /// given geometry.
    FdoSpatialOperations_Within,

    /// Test to see if the geometric property value is covered by the interior
    /// and boundary of the given geometry.
    FdoSpatialOperations_CoveredBy,

    /// Test to see if the geometric property value is inside the interior
    /// of the given geometry, not touching the boundary.
    FdoSpatialOperations_Inside,

    /// Test to see if the envelope of the referenced geometric property value spatially intersects the
    /// given geometry.
    FdoSpatialOperations_EnvelopeIntersects

};


#endif



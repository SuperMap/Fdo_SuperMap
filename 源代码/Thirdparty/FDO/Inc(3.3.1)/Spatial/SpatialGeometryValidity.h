#ifndef _FDOSPATIALGEOMETRYVALIDITY_H_
#define _FDOSPATIALGEOMETRYVALIDITY_H_
/*
* Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifdef _WIN32
#pragma once
#endif

/// \ingroup (enums)
/// \brief
///  FdoSpatialGeometryValidity is an enumeration to denote the validity of a Geometry
/// during a test of type and dimensionality..
enum FdoSpatialGeometryValidity
{
    /// Indicates no specific validity; used for unknown or default states.
    FdoSpatialGeometryValidity_None = 0,

    /// Geometry passes a test.
    FdoSpatialGeometryValidity_Valid = 1,

    /// Geometry fails a test.
    FdoSpatialGeometryValidity_Invalid = 2,

    /// Geometry fails a test, but could be approximated 
    /// using allowed types.
    FdoSpatialGeometryValidity_InvalidButCanBeApproximated = 3,

    /// Geometry fails a test due to having an disallowed dimensionality.
    FdoSpatialGeometryValidity_InvalidDueToDimensionality = 4
};

#endif



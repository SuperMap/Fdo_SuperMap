#ifndef _GEOMETRYTYPE_H_
#define _GEOMETRYTYPE_H_

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

#ifdef __cplusplus
/// \ingroup (enums)
    /// \brief
    ///  FdoGeometryType is an enumeration to denote the type of a Geometry.
    /// 
    /// \remarks
    ///  This enumeration applies to types that derive from FdoIGeometry.
    enum FdoGeometryType
#else
    typedef enum
#endif
{
    /// Indicates no specific type; used for "unknown", "don't care" or an incompletely constructed Geometry object.
    FdoGeometryType_None = 0,

    /// Point type (FdoIPoint).
    FdoGeometryType_Point = 1,

    /// LineString type (FdoILineString).
    FdoGeometryType_LineString = 2,

    /// Polygon type (FdoIPolygon).
    FdoGeometryType_Polygon = 3,

    /// MultiPoint type (FdoIMultiPoint).
    FdoGeometryType_MultiPoint = 4,

    /// MultiLineString type (FdoIMultiLineString).
    FdoGeometryType_MultiLineString = 5,

    /// MultiPolygon type (FdoIMultiPolygon).
    FdoGeometryType_MultiPolygon = 6,

    /// MultiGeometry type (FdoIMultiGeometry).
    FdoGeometryType_MultiGeometry = 7,

    /// CurveString type (FdoICurveString).
    FdoGeometryType_CurveString = 10,

    /// CurvePolygon type (FdoICurvePolygon).
    FdoGeometryType_CurvePolygon = 11,

    /// MultiCurveString type (FdoIMultiCurveString).
    FdoGeometryType_MultiCurveString = 12,
    
    /// MultiCurvePolygon type (FdoIMultiCurvePolygon).
    FdoGeometryType_MultiCurvePolygon = 13

#ifdef __cplusplus
};
#else
} FdoGeometryType;
#endif


#ifdef __cplusplus
	/// \ingroup (enums)
    /// \brief
    ///  Enumeration for components of Geometry.
    /// 
    /// \remarks
    ///  This enumeration applies to certain helper types that are used to compose other types which derive from FdoIGeometry.
    enum FdoGeometryComponentType
#else
    typedef enum
#endif
{
    /// LinearRing type (FdoILinearRing).
    FdoGeometryComponentType_LinearRing = 129,

    /// CircularArcSegment type (FdoICircularArcSegment).
    FdoGeometryComponentType_CircularArcSegment = 130,

    /// LineStringSegment type (FdoILineStringSegment).
    FdoGeometryComponentType_LineStringSegment = 131,

    /// Ring type (FdoIRing).
    FdoGeometryComponentType_Ring = 132

#ifdef __cplusplus
};
#else
} FdoGeometryComponentType;
#endif
#endif



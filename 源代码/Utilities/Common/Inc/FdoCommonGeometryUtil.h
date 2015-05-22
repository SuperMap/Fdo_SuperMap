#ifndef FDOCOMMONGEOMETRYUTIL_H
#define FDOCOMMONGEOMETRYUTIL_H
// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifdef _WIN32
#pragma once
#endif


// ----------------------------------------------------------------------------
//                             Constant Definitions
// ----------------------------------------------------------------------------

#define All_GEOMETRY_POINT  \
        (FdoCommonGeometryTypeHexCode_Point | FdoCommonGeometryTypeHexCode_MultiPoint)

#define ALL_GEOMETRY_CURVE  \
        (FdoCommonGeometryTypeHexCode_LineString  | FdoCommonGeometryTypeHexCode_MultiLineString  | \
         FdoCommonGeometryTypeHexCode_CurveString | FdoCommonGeometryTypeHexCode_MultiCurveString   )

#define ALL_GEOMETRY_SURFACE  \
        (FdoCommonGeometryTypeHexCode_Polygon      | FdoCommonGeometryTypeHexCode_MultiPolygon      | \
         FdoCommonGeometryTypeHexCode_CurvePolygon | FdoCommonGeometryTypeHexCode_MultiCurvePolygon   )

#define ALL_GEOMETRY_POINT_CURVE          (All_GEOMETRY_POINT | ALL_GEOMETRY_CURVE)
#define ALL_GEOMETRY_POINT_SURFACE        (All_GEOMETRY_POINT |ALL_GEOMETRY_SURFACE)
#define ALL_GEOMETRY_CURVE_SURFACE        (ALL_GEOMETRY_CURVE |ALL_GEOMETRY_SURFACE)
#define ALL_GEOMETRY_POINT_CURVE_SURFACE  (All_GEOMETRY_POINT |ALL_GEOMETRY_CURVE |ALL_GEOMETRY_SURFACE)


// ----------------------------------------------------------------------------
//                               Class Definitions
// ----------------------------------------------------------------------------

class FdoCommonGeometryUtil {

public:

    /// The function returns the hex-code that represents the selection of all
    /// geometry types.

    static FdoInt32 GetAllGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// curve/line based geometry types.

    static FdoInt32 GetCurveGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// curve/line and polygon based geometry types.

    static FdoInt32 GetCurveSurfaceGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// point based geometry types.

    static FdoInt32 GetPointGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// point and curve/line based geometry types.

    static FdoInt32 GetPointCurveGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// point and polygon based geometry types.

    static FdoInt32 GetPointSurfaceGeometryTypesCode ();

    /// The function returns the hex-code that represents the selection of all
    /// polygon based geometry types.

    static FdoInt32 GetSurfaceGeometryTypesCode ();

    /// The functions map a geometry type to its unique hex-code that can be
    /// used in a bit-wise operation.

    static FdoInt32 MapGeometryTypeToHexCode (FdoGeometryType gType);
    static FdoInt32 MapGeometryTypeToHexCode (int             pos);

    /// The function maps a geometry type hex code to the corresponding FDO geometry
    /// type.

    static FdoGeometryType MapHexCodeToGeometryType (FdoInt32 gTypeHexCode);

    // Converts a GeometricType to GeometryTypes bitmap of hexcodes.

	static FdoInt32 GetGeometryTypes(FdoInt32 value);

    // Converts GeometryTypes from hexcode to array format.
    // Caller is responsible for ensuring that the gTypes array has enough entries to 
    // hold all geometryTypes defined in the hexcode.

    static void GeometryTypesToArray( FdoInt32 hexType, FdoGeometryType* gTypes, FdoInt32& typeCount );

    // Get special hexcode for when no geometryTypes are defined.

    static FdoInt32 GetNoneGeometryTypesCode ();

    // Get count of GeometryTypes from hex value including NONE

    static FdoInt32 GetCountGeometryTypesFromHex (FdoInt32 hexType);

private:

    /// The following enumeration defines hex-codes that map to FDO Geometry Types.

    enum FdoCommonGeometryTypeHexCode {

        FdoCommonGeometryTypeHexCode_None              = 0x00020,
        FdoCommonGeometryTypeHexCode_Point             = 0x00040,
        FdoCommonGeometryTypeHexCode_LineString        = 0x00080,
        FdoCommonGeometryTypeHexCode_Polygon           = 0x00100,
        FdoCommonGeometryTypeHexCode_MultiPoint        = 0x00200,
        FdoCommonGeometryTypeHexCode_MultiLineString   = 0x00400,
        FdoCommonGeometryTypeHexCode_MultiPolygon      = 0x00800,
        FdoCommonGeometryTypeHexCode_MultiGeometry     = 0x01000,
        FdoCommonGeometryTypeHexCode_CurveString       = 0x02000,
        FdoCommonGeometryTypeHexCode_CurvePolygon      = 0x04000,
        FdoCommonGeometryTypeHexCode_MultiCurveString  = 0x08000,
        FdoCommonGeometryTypeHexCode_MultiCurvePolygon = 0x10000,

    };  //  enum FdoCommonGeometryTypeHexCode

	static FdoInt32 GetGeometricType(int pos);

};  //  class FdoCommonGeometryUtil

#endif


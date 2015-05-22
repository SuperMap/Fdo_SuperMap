// 
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
//  

#include "stdafx.h"
#include <FdoCommonGeometryUtil.h>


// ----------------------------------------------------------------------------
//                               Public Functions
// ----------------------------------------------------------------------------

FdoInt32 FdoCommonGeometryUtil::GetAllGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_POINT_CURVE_SURFACE;

}  //  GetAllGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetCurveGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | curve/line based geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_CURVE;

}  //  GetCurveGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetCurveSurfaceGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | curve/line and polygon based geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_CURVE_SURFACE;

}  //  GetCurveSurfaceGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetPointGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | point based geometry types.
// +---------------------------------------------------------------------------

{

    return All_GEOMETRY_POINT;

}  //  GetPointGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetPointCurveGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | point and curve/line based geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_POINT_CURVE;

}  //  GetPointCurveGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetPointSurfaceGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | point and polygon based geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_POINT_SURFACE;

}  //  GetPointSurfaceGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::GetSurfaceGeometryTypesCode ()

// +---------------------------------------------------------------------------
// | The function returns the hex-code that represents the selection of all
// | polygon based geometry types.
// +---------------------------------------------------------------------------

{

    return ALL_GEOMETRY_SURFACE;

}  //  GetSurfaceGeometryTypesCode ()

FdoInt32 FdoCommonGeometryUtil::MapGeometryTypeToHexCode (
                                                        FdoGeometryType gType)

// +---------------------------------------------------------------------------
// | The functions map a geometry type to its unique hex-code that can be used
// | in a bit-wise operation.
// +---------------------------------------------------------------------------

{

    switch (gType) {

      case FdoGeometryType_None:
        return FdoCommonGeometryTypeHexCode_None;
        break;

      case FdoGeometryType_Point:
        return FdoCommonGeometryTypeHexCode_Point;
        break;

      case FdoGeometryType_LineString:
        return FdoCommonGeometryTypeHexCode_LineString;
        break;

      case FdoGeometryType_Polygon:
        return FdoCommonGeometryTypeHexCode_Polygon;
        break;

      case FdoGeometryType_MultiPoint:
        return FdoCommonGeometryTypeHexCode_MultiPoint;
        break;

      case FdoGeometryType_MultiLineString:
        return FdoCommonGeometryTypeHexCode_MultiLineString;
        break;

      case FdoGeometryType_MultiPolygon:
        return FdoCommonGeometryTypeHexCode_MultiPolygon;
        break;

      case FdoGeometryType_MultiGeometry:
        return FdoCommonGeometryTypeHexCode_MultiGeometry;
        break;

      case FdoGeometryType_CurveString:
        return FdoCommonGeometryTypeHexCode_CurveString;
        break;

      case FdoGeometryType_CurvePolygon:
        return FdoCommonGeometryTypeHexCode_CurvePolygon;
        break;

      case FdoGeometryType_MultiCurveString:
        return FdoCommonGeometryTypeHexCode_MultiCurveString;
        break;

      case FdoGeometryType_MultiCurvePolygon:
        return FdoCommonGeometryTypeHexCode_MultiCurvePolygon;
        break;

      default:
        throw FdoException::Create(
                              FdoException::NLSGetMessage(
                                  FDO_NLSID(FDO_128_GEOMETRY_MAPPING_ERROR)));
        break;

    }  //  switch ...

}  //  MapGeometryTypeToHexCode ()

FdoInt32 FdoCommonGeometryUtil::MapGeometryTypeToHexCode (int pos)

// +---------------------------------------------------------------------------
// | The functions map a geometry type to its unique hex-code that can be used
// | in a bit-wise operation.
// +---------------------------------------------------------------------------

{

    switch (pos) {

      case  0:
        return FdoCommonGeometryTypeHexCode_None;
        break;

      case  1:
        return FdoCommonGeometryTypeHexCode_Point;
        break;

      case  2:
        return FdoCommonGeometryTypeHexCode_LineString;
        break;

      case  3:
        return FdoCommonGeometryTypeHexCode_Polygon;
        break;

      case  4:
        return FdoCommonGeometryTypeHexCode_MultiPoint;
        break;

      case  5:
        return FdoCommonGeometryTypeHexCode_MultiLineString;
        break;

      case  6:
        return FdoCommonGeometryTypeHexCode_MultiPolygon;
        break;

      case  7:
        return FdoCommonGeometryTypeHexCode_MultiGeometry;
        break;

      case  8:
        return FdoCommonGeometryTypeHexCode_CurveString;
        break;

      case  9:
        return FdoCommonGeometryTypeHexCode_CurvePolygon;
        break;

      case 10:
        return FdoCommonGeometryTypeHexCode_MultiCurveString;
        break;

      case 11:
        return FdoCommonGeometryTypeHexCode_MultiCurvePolygon;
        break;

      default:
        throw FdoException::Create(
                              FdoException::NLSGetMessage(
                                  FDO_NLSID(FDO_128_GEOMETRY_MAPPING_ERROR)));
        break;

    }  //  switch ...

}  //  MapGeometryTypeToHexCode ()

FdoGeometryType FdoCommonGeometryUtil::MapHexCodeToGeometryType (
                                                        FdoInt32 gTypeHexCode)

// +---------------------------------------------------------------------------
// | The function maps a geometry type hex-code to the corresponding FDO
// | geometry type.
// +---------------------------------------------------------------------------

{

    switch (gTypeHexCode) {

      case FdoCommonGeometryTypeHexCode_None:
        return FdoGeometryType_None;
        break;

      case FdoCommonGeometryTypeHexCode_Point:
        return FdoGeometryType_Point;
        break;

      case FdoCommonGeometryTypeHexCode_LineString:
        return FdoGeometryType_LineString;
        break;

      case FdoCommonGeometryTypeHexCode_Polygon:
        return FdoGeometryType_Polygon;
        break;

      case FdoCommonGeometryTypeHexCode_MultiPoint:
        return FdoGeometryType_MultiPoint;
        break;

      case FdoCommonGeometryTypeHexCode_MultiLineString:
        return FdoGeometryType_MultiLineString;
        break;

      case FdoCommonGeometryTypeHexCode_MultiPolygon:
        return FdoGeometryType_MultiPolygon;
        break;

      case FdoCommonGeometryTypeHexCode_MultiGeometry:
        return FdoGeometryType_MultiGeometry;
        break;

      case FdoCommonGeometryTypeHexCode_CurveString:
        return FdoGeometryType_CurveString;
        break;

      case FdoCommonGeometryTypeHexCode_CurvePolygon:
        return FdoGeometryType_CurvePolygon;
        break;

      case FdoCommonGeometryTypeHexCode_MultiCurveString:
        return FdoGeometryType_MultiCurveString;
        break;

      case FdoCommonGeometryTypeHexCode_MultiCurvePolygon:
        return FdoGeometryType_MultiCurvePolygon;
        break;

      default:
        throw FdoException::Create(
                              FdoException::NLSGetMessage(
                                   FDO_NLSID(FDO_128_GEOMETRY_MAPPING_ERROR)));
        break;

    }  //  switch ...

}  //  MapHexCodeToGeometryType ()

FdoInt32 FdoCommonGeometryUtil::GetGeometryTypes(FdoInt32 value)
{
    FdoInt32 currGeometricType;

    // The following sets the corresponding geometry types.

    FdoInt32 geometryTypes = 0x00000;

    for (int i = 0; i < MAX_GEOMETRIC_TYPE_SIZE; i++)
    {
        currGeometricType = GetGeometricType(i);
        if (currGeometricType != -1)
        {
            if ((value & currGeometricType) > 0)
            {
                switch (currGeometricType)
                {
                    case FdoGeometricType_Point:
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_Point);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_MultiPoint);
                        break;
                    case FdoGeometricType_Curve:
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_LineString);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_MultiLineString);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_CurveString);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_MultiCurveString);
                        break;
                    case FdoGeometricType_Surface:
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_Polygon);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_MultiPolygon);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_CurvePolygon);
                        geometryTypes = geometryTypes | MapGeometryTypeToHexCode(FdoGeometryType_MultiCurvePolygon);
                        break;
                }
            }
        }
    }

	return geometryTypes;
}

void FdoCommonGeometryUtil::GeometryTypesToArray( FdoInt32 hexType, FdoGeometryType* gTypes, FdoInt32& typeCount )
{
    FdoInt32 currTypeHexCode;

    // Based on the current geometry type value fill the corresponding vector with the
    // selected geometry types.
    typeCount = 0;
    for (int i = 0; i < MAX_GEOMETRY_TYPE_SIZE; i++)
    {
        currTypeHexCode = MapGeometryTypeToHexCode(i);
        if ((hexType & currTypeHexCode) > 0)
            gTypes[typeCount++] = MapHexCodeToGeometryType(currTypeHexCode);
    }
}

FdoInt32 FdoCommonGeometryUtil::GetGeometricType(int pos)
{
    switch (pos) 
    {
        case 0:  return FdoGeometricType_Point;   break;
        case 1:  return FdoGeometricType_Curve;   break;
        case 2:  return FdoGeometricType_Surface; break;
        case 3:  return FdoGeometricType_Solid;   break;
        default: return -1;                       break;
    }
}

FdoInt32 FdoCommonGeometryUtil::GetNoneGeometryTypesCode()
{
	return FdoCommonGeometryTypeHexCode_None;
}

FdoInt32 FdoCommonGeometryUtil::GetCountGeometryTypesFromHex (FdoInt32 hexType)
{
    FdoInt32 typeCount = 0;
    for (int i = 0; i < MAX_GEOMETRY_TYPE_SIZE; i++)
    {
        if ((hexType & MapGeometryTypeToHexCode(i)) != 0)
            typeCount++;
    }
    return typeCount;
}

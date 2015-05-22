/*
 * 
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
* 
 */

#include "stdafx.h"

[!output PREFIX]GeometryCapabilities::[!output PREFIX]GeometryCapabilities ()
{
}

[!output PREFIX]GeometryCapabilities::~[!output PREFIX]GeometryCapabilities ()
{
}

void [!output PREFIX]GeometryCapabilities::Dispose()
{
    delete this;
}

/// <summary>Return the list of supported geometry types. For example, if a client wanted to know if a provider supported
/// multi-polygons, it would call GetGeometryTypes and check if the MultiPolygon type was listed.</summary>
/// <param name="length">Output the number of geometry types.</param> 
/// <returns>Returns the list of geometry types</returns> 
FdoGeometryType* [!output PREFIX]GeometryCapabilities::GetGeometryTypes (FdoInt32& length)
{
    static const FdoGeometryType geomTypes[] =
    {
        FdoGeometryType_Point,
//        FdoGeometryType_LineString,
//        FdoGeometryType_Polygon,
//        FdoGeometryType_MultiPoint,
//        FdoGeometryType_MultiLineString,
//        FdoGeometryType_MultiPolygon
    };
    length = ELEMENTS(geomTypes);
    return ((FdoGeometryType *)geomTypes);
}

/// <summary>Return the list of supported component types. For example, if a client wanted to know if circular arcs were supported 
/// by a provider, it would call GetGeometryComponentTypes and check for CircularArcSegment in the returned list.</summary>
/// <param name="length">Output the number of component types.</param> 
/// <returns>Returns the list of component types</returns> 
FdoGeometryComponentType* [!output PREFIX]GeometryCapabilities::GetGeometryComponentTypes (FdoInt32& length)
{
    static const FdoGeometryComponentType geomComponentTypes[] =
    {
//        FdoGeometryComponentType_LinearRing,
        FdoGeometryComponentType_LineStringSegment
    };
    length = ELEMENTS(geomComponentTypes);
    return ((FdoGeometryComponentType *)geomComponentTypes);
}

/// <summary>Returns the supported dimensionalities which are based on the bit masks defined in the FdoDimensionality enum. 
/// The Z and M bits indicate if the provider supports 3d or Measure dimensions in geometry data. The XY bit should be set too.</summary>
/// <returns>Returns the dimensionalities</returns> 
FdoInt32 [!output PREFIX]GeometryCapabilities::GetDimensionalities ()
{
    return (FdoDimensionality_XY /*| FdoDimensionality_Z | FdoDimensionality_M */); 
}


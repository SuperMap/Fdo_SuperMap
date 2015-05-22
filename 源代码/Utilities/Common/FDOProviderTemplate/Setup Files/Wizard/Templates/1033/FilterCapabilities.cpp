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

[!output PREFIX]FilterCapabilities::[!output PREFIX]FilterCapabilities ()
{
}

[!output PREFIX]FilterCapabilities::~[!output PREFIX]FilterCapabilities ()
{
}

void [!output PREFIX]FilterCapabilities::Dispose ()
{
    delete this;
}

/// <summary>Returns an array of FdoConditionType objects the feature provider supports.</summary>
/// <param name="length">Output the number of condition types</param> 
/// <returns>Returns the list of condition types</returns> 
FdoConditionType* [!output PREFIX]FilterCapabilities::GetConditionTypes (FdoInt32& length)
{
#pragma message ("ToDo: filter capabilities FdoConditionType_Comparison, FdoConditionType_Like, FdoConditionType_In, FdoConditionType_Null, FdoConditionType_Spatial, FdoConditionType_Distance")
    static FdoConditionType types[] =
    {
      FdoConditionType_Comparison,
      //FdoConditionType_Like,
      //FdoConditionType_In,
      //FdoConditionType_Null,
      //FdoConditionType_Spatial,
      //FdoConditionType_Distance
    };

    length = sizeof (types) / sizeof (FdoConditionType);

    return (types);
}

/// <summary>Returns an array of FdoSpatialOperation objects the feature provider supports.</summary>
/// <param name="length">Output the number of spatial operations</param> 
/// <returns>Returns the list of spartial operations</returns> 
FdoSpatialOperations* [!output PREFIX]FilterCapabilities::GetSpatialOperations (FdoInt32& length)
{
#pragma message ("ToDo: spatial operations FdoSpatialOperations_Contains, FdoSpatialOperations_Crosses, FdoSpatialOperations_Disjoint, FdoSpatialOperations_Equals, FdoSpatialOperations_Intersects, FdoSpatialOperations_Overlaps, FdoSpatialOperations_Touches, FdoSpatialOperations_Within, FdoSpatialOperations_CoveredBy, FdoSpatialOperations_EnvelopeIntersects")
    static FdoSpatialOperations operations[] =
    {
      FdoSpatialOperations_Contains,
      //FdoSpatialOperations_Crosses,
      //FdoSpatialOperations_Disjoint,
      //FdoSpatialOperations_Equals,
      //FdoSpatialOperations_Intersects,
      //FdoSpatialOperations_Overlaps,
      //FdoSpatialOperations_Touches,
      //FdoSpatialOperations_Within,
      //FdoSpatialOperations_CoveredBy,
      //FdoSpatialOperations_EnvelopeIntersects
    };

    length = sizeof (operations) / sizeof (FdoSpatialOperations);

    return (operations);
}

/// <summary>Returns an array of FdoDistanceOperation objects the feature provider supports.</summary>
/// <param name="length">Output the number of distance operations</param> 
/// <returns>Returns the list of distance operations</returns> 
FdoDistanceOperations* [!output PREFIX]FilterCapabilities::GetDistanceOperations (FdoInt32& length)
{
#pragma message ("ToDo: distance operations FdoDistanceOperations_Beyond, FdoDistanceOperations_Within")
    static FdoDistanceOperations operations[] =
    {
//      FdoDistanceOperations_Beyond,
      FdoDistanceOperations_Within
    };

    length = sizeof (operations) / sizeof (FdoDistanceOperations);

    return (operations);
}

/// <summary>Determines if the feature provider supports geodesic distance measurement. Returns false if the feature provider supports only linear distance measurement.</summary>
/// <returns>Returns true if the feature provider supports geodesic distance measurement</returns> 
bool [!output PREFIX]FilterCapabilities::SupportsGeodesicDistance ()
{
    return (false);  //TODO: verify this
}

/// <summary>Determines if spatial and distance operations can be applied between two 
/// geometric properties. Returns false if spatial and distance operations can be applied only between 
/// a geometric property and a literal geometry.</summary>
/// <returns>Returns true if spatial and distance operations can be applied</returns> 
bool [!output PREFIX]FilterCapabilities::SupportsNonLiteralGeometricOperations ()
{
    return (false);  //ok
}


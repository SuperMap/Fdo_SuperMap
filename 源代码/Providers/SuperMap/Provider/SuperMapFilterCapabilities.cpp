
/** \file	 SuperMapFilterCapabilities.cpp
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#include <SuperMap.h>

SuperMapFilterCapabilities::SuperMapFilterCapabilities ()
{
}

SuperMapFilterCapabilities::~SuperMapFilterCapabilities ()
{
}

void SuperMapFilterCapabilities::Dispose ()
{
    delete this;
}

/// <summary>Returns an array of FdoConditionType objects the feature provider supports.</summary>
/// <param name="length">Output the number of condition types</param> 
/// <returns>Returns the list of condition types</returns> 
FdoConditionType* SuperMapFilterCapabilities::GetConditionTypes (FdoInt32& length)
{
	//TODO:: 根据UGC的具体功能再做仔细的定义
    static FdoConditionType types[] =
    {
      FdoConditionType_Comparison,
      FdoConditionType_Like,
      FdoConditionType_In,
      FdoConditionType_Null,
      FdoConditionType_Spatial,
    };

    length = sizeof (types) / sizeof (FdoConditionType);

    return (types);
}

/// <summary>Returns an array of FdoSpatialOperation objects the feature provider supports.</summary>
/// <param name="length">Output the number of spatial operations</param> 
/// <returns>Returns the list of spartial operations</returns> 
FdoSpatialOperations* SuperMapFilterCapabilities::GetSpatialOperations (FdoInt32& length)
{
    static FdoSpatialOperations operations[] =
    {
		FdoSpatialOperations_Contains,
		FdoSpatialOperations_Crosses,
		FdoSpatialOperations_Disjoint,
		FdoSpatialOperations_Equals,
		FdoSpatialOperations_Intersects,
		FdoSpatialOperations_Overlaps,
		FdoSpatialOperations_Touches,
		FdoSpatialOperations_Within,
		// TODO::再做研究 目前还和UGC对应不上
		/*FdoSpatialOperations_CoveredBy,*/
		FdoSpatialOperations_Inside,
		FdoSpatialOperations_EnvelopeIntersects
    };

    length = sizeof (operations) / sizeof (FdoSpatialOperations);

    return (operations);
}

/// <summary>Returns an array of FdoDistanceOperation objects the feature provider supports.</summary>
/// <param name="length">Output the number of distance operations</param> 
/// <returns>Returns the list of distance operations</returns> 
FdoDistanceOperations* SuperMapFilterCapabilities::GetDistanceOperations (FdoInt32& length)
{
    length = 0;

    return (NULL);
}

/// <summary>Determines if the feature provider supports geodesic distance measurement. Returns false if the feature provider supports only linear distance measurement.</summary>
/// <returns>Returns true if the feature provider supports geodesic distance measurement</returns> 
bool SuperMapFilterCapabilities::SupportsGeodesicDistance ()
{
    return (false);
}

/// <summary>Determines if spatial and distance operations can be applied between two 
/// geometric properties. Returns false if spatial and distance operations can be applied only between 
/// a geometric property and a literal geometry.</summary>
/// <returns>Returns true if spatial and distance operations can be applied</returns> 
bool SuperMapFilterCapabilities::SupportsNonLiteralGeometricOperations ()
{
    return (false);
}


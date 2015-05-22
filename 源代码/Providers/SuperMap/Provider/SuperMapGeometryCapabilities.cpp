/** \file	 SuperMapGeometryCapabilities.cpp
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#include "SuperMap.h"

SuperMapGeometryCapabilities::SuperMapGeometryCapabilities ()
{
}

SuperMapGeometryCapabilities::~SuperMapGeometryCapabilities ()
{
}

void SuperMapGeometryCapabilities::Dispose()
{
    delete this;
}

/// <summary>Return the list of supported geometry types. For example, if a client wanted to know if a provider supported
/// multi-polygons, it would call GetGeometryTypes and check if the MultiPolygon type was listed.</summary>
/// <param name="length">Output the number of geometry types.</param> 
/// <returns>Returns the list of geometry types</returns> 
FdoGeometryType* SuperMapGeometryCapabilities::GetGeometryTypes (FdoInt32& length)
{
	TRACE(_T("调用 SuperMapGeometryCapabilities::GetGeometryTypes()... \n"));
    static const FdoGeometryType geomTypes[] =
    {
	
        FdoGeometryType_Point,
        FdoGeometryType_LineString,
        FdoGeometryType_Polygon,
        FdoGeometryType_MultiPoint,			
        FdoGeometryType_MultiLineString,	// 支持多点、多线
		FdoGeometryType_MultiPolygon,

		FdoGeometryType_MultiGeometry

		/*shp
		FdoGeometryType_Point,
        FdoGeometryType_LineString,
        FdoGeometryType_Polygon,
        FdoGeometryType_MultiPoint,
        FdoGeometryType_MultiLineString,
		*/
	};

    length = ELEMENTS(geomTypes);
    return ((FdoGeometryType *)geomTypes);
}

/// <summary>Return the list of supported component types. For example, if a client wanted to know if circular arcs were supported 
/// by a provider, it would call GetGeometryComponentTypes and check for CircularArcSegment in the returned list.</summary>
/// <param name="length">Output the number of component types.</param> 
/// <returns>Returns the list of component types</returns> 
FdoGeometryComponentType* SuperMapGeometryCapabilities::GetGeometryComponentTypes (FdoInt32& length)
{
	TRACE(_T("调用 SuperMapGeometryCapabilities::GetGeometryComponentTypes()... \n"));
    static const FdoGeometryComponentType geomComponentTypes[] =
    {
		//TODO::待实现后再打开 
	//	FdoGeometryComponentType_CircularArcSegment,           
	// 	FdoGeometryComponentType_Ring,          
        FdoGeometryComponentType_LinearRing,
        FdoGeometryComponentType_LineStringSegment	// 支持组合几何数据 //added by zhouxu 2008-1-14
    };
    length = ELEMENTS(geomComponentTypes);
    return ((FdoGeometryComponentType *)geomComponentTypes);
	/*shp
	FdoGeometryComponentType_LinearRing,
	FdoGeometryComponentType_LineStringSegment,
	*/
}

/// <summary>Returns the supported dimensionalities which are based on the bit masks defined in the FdoDimensionality enum. 
/// The Z and M bits indicate if the provider supports 3d or Measure dimensions in geometry data. The XY bit should be set too.</summary>
/// <returns>Returns the dimensionalities</returns> 
FdoInt32 SuperMapGeometryCapabilities::GetDimensionalities ()
{
	TRACE(_T("调用 SuperMapGeometryCapabilities::GetDimensionalities()... \n"));
    return (FdoDimensionality_XY);//目前仅支持二维 | FdoDimensionality_Z | FdoDimensionality_M);	//支持三维
}


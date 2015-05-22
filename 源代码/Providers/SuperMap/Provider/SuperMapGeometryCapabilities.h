/** \file	 SuperMapGeometryCapabilities.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#ifndef __SUPERMAP_GEOMETRYCAPABILITIES_H__
#define __SUPERMAP_GEOMETRYCAPABILITIES_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapGeometryCapabilities : public FdoIGeometryCapabilities
{
public:
    SuperMapGeometryCapabilities ();

protected:
    virtual ~SuperMapGeometryCapabilities ();

protected:
    virtual void Dispose ();

public:
    /// <summary>Return the list of supported geometry types. For example, if a client wanted to know if a provider supported
    /// multi-polygons, it would call GetGeometryTypes and check if the MultiPolygon type was listed.</summary>
    /// <param name="length">Output the number of geometry types.</param> 
    /// <returns>Returns the list of geometry types</returns> 
    virtual FdoGeometryType* GetGeometryTypes (FdoInt32& length);

    /// <summary>Return the list of supported component types. For example, if a client wanted to know if circular arcs were supported 
    /// by a provider, it would call GetGeometryComponentTypes and check for CircularArcSegment in the returned list.</summary>
    /// <param name="length">Output the number of component types.</param> 
    /// <returns>Returns the list of component types</returns> 
    virtual FdoGeometryComponentType* GetGeometryComponentTypes (FdoInt32& length);

    /// <summary>Returns the supported dimensionalities which are based on the bit masks defined in the FdoDimensionality enum. 
    /// The Z and M bits indicate if the provider supports 3d or Measure dimensions in geometry data. The XY bit should be set too.</summary>
    /// <returns>Returns the dimensionalities</returns> 
    virtual FdoInt32 GetDimensionalities ();
};

#endif // __SUPERMAP_GEOMETRYCAPABILITIES_H__


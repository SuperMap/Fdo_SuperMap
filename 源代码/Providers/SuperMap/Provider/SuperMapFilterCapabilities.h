
/** \file	 SuperMapFilterCapabilities.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifndef __SUPERMAP_FILTERCAPABILITIES_H__
#define __SUPERMAP_FILTERCAPABILITIES_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapFilterCapabilities : public FdoIFilterCapabilities
{
public:
    SuperMapFilterCapabilities ();

protected:
    virtual ~SuperMapFilterCapabilities ();

protected:
    virtual void Dispose();

public:
    /// <summary>Returns an array of FdoConditionType objects the feature provider supports.</summary>
    /// <param name="length">Output the number of condition types</param> 
    /// <returns>Returns the list of condition types</returns> 
    virtual FdoConditionType* GetConditionTypes (FdoInt32& length);

    /// <summary>Returns an array of FdoSpatialOperation objects the feature provider supports.</summary>
    /// <param name="length">Output the number of spatial operations</param> 
    /// <returns>Returns the list of spartial operations</returns> 
    virtual FdoSpatialOperations* GetSpatialOperations (FdoInt32& length);

    /// <summary>Returns an array of FdoDistanceOperation objects the feature provider supports.</summary>
    /// <param name="length">Output the number of distance operations</param> 
    /// <returns>Returns the list of distance operations</returns> 
    virtual FdoDistanceOperations* GetDistanceOperations (FdoInt32& length);

    /// <summary>Determines if the feature provider supports geodesic distance measurement. Returns false if the feature provider supports only linear distance measurement.</summary>
    /// <returns>Returns true if the feature provider supports geodesic distance measurement</returns> 
    virtual bool SupportsGeodesicDistance ();

    /// <summary>Determines if spatial and distance operations can be applied between two 
    /// geometric properties. Returns false if spatial and distance operations can be applied only between 
    /// a geometric property and a literal geometry.</summary>
    /// <returns>Returns true if spatial and distance operations can be applied</returns> 
    virtual bool SupportsNonLiteralGeometricOperations ();
};

#endif // __SUPERMAP_FILTERCAPABILITIES_H__


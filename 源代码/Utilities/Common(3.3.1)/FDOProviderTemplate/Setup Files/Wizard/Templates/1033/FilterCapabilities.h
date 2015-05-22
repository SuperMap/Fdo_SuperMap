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

#ifndef [!output UPPER_PREFIX]FILTERCAPABILITIES_H
#define [!output UPPER_PREFIX]FILTERCAPABILITIES_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]FilterCapabilities : public FdoIFilterCapabilities
{
public:
    [!output PREFIX]FilterCapabilities ();

protected:
    virtual ~[!output PREFIX]FilterCapabilities ();

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

#endif // [!output UPPER_PREFIX]FILTERCAPABILITIES_H


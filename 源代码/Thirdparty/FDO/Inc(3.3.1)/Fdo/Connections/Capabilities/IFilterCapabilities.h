#ifndef _IFILTERCAPABILITIES_H_
#define _IFILTERCAPABILITIES_H_
// 

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

#include <FdoStd.h>
#include <Fdo/Filter/ConditionType.h>
#include <Fdo/Filter/DistanceOperations.h>
#include <Fdo/Filter/SpatialOperations.h>

/// \brief
/// The FdoIFilterCapabilities interface declares the feature provider's level of support for FdoFilter classes.
class FdoIFilterCapabilities : public FdoIDisposable
{
public:
    /// \brief
    /// Returns an array of FdoConditionType objects the feature provider supports.
    /// 
    /// \param length 
    /// Output the number of condition types
    /// 
    /// \return
    /// Returns the list of condition types
    /// 
    FDO_API virtual FdoConditionType* GetConditionTypes(FdoInt32& length) = 0;

    /// \brief
    /// Returns an array of FdoSpatialOperation objects the feature provider supports.
    /// 
    /// \param length 
    /// Output the number of spatial operations
    /// 
    /// \return
    /// Returns the list of spartial operations
    /// 
    FDO_API virtual FdoSpatialOperations* GetSpatialOperations(FdoInt32& length) = 0;

    /// \brief
    /// Returns an array of FdoDistanceOperation objects the feature provider supports.
    /// 
    /// \param length 
    /// Output the number of distance operations
    /// 
    /// \return
    /// Returns the list of distance operations
    /// 
    FDO_API virtual FdoDistanceOperations* GetDistanceOperations(FdoInt32& length) = 0;

    /// \brief
    /// Determines if the feature provider supports geodesic distance measurement. Returns false if the feature provider supports only linear distance measurement.
    /// 
    /// \return
    /// Returns true if the feature provider supports geodesic distance measurement
    /// 
    FDO_API virtual bool SupportsGeodesicDistance() = 0;

    /// \brief
    /// Determines if spatial and distance operations can be applied between two 
    /// geometric properties. Returns false if spatial and distance operations can be applied only between 
    /// a geometric property and a literal geometry.
    /// 
    /// \return
    /// Returns true if spatial and distance operations can be applied
    /// 
    FDO_API virtual bool SupportsNonLiteralGeometricOperations() = 0;
};
#endif



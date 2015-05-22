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

#ifndef FDOSPATIALGEOMETRYCONVERTER_H
#define FDOSPATIALGEOMETRYCONVERTER_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

// This class shows how to use the Geometry API to analyse a geometry in detail.
// This example copies a geometry while applying a trivial transformation
// (swapping X and Y ordinates) to each ordinate.  It can also convert between
// dimensionalities.
class FdoSpatialGeometryConverter
{
public:
    FDO_SPATIAL_API FdoSpatialGeometryConverter() {};
    FDO_SPATIAL_API virtual ~FdoSpatialGeometryConverter() {};

public:
    FDO_SPATIAL_API FdoIGeometry * ConvertOrdinates(
        FdoIGeometry * geometry,
        bool applyTargetDimensionality=false,
        FdoInt32 targetDimensionality = 0,
        double padValueZ = 0.0,
        double padValueM = 0.0);

    FDO_SPATIAL_API virtual void ConvertPosition(
        double &x,
        double &y) = 0;

    FDO_SPATIAL_API virtual void ConvertPosition(
        double &x,
        double &y,
        double &z) = 0;

protected:

    void ConvertOrdinates(
        FdoInt32 inputDim,
        FdoInt32 numPositions,
        const double * inputOrds,
        double padValueZ,
        double padValueM,
        FdoInt32 outputDim,
        double * outputOrds);

    FdoILinearRing * ConvertOrdinates(
        FdoILinearRing * ring,
        FdoInt32 outputDim,
        double padValueZ,
        double padValueM);

    FdoCurveSegmentCollection * ConvertOrdinates(
        FdoCurveSegmentCollection * csc,
        FdoInt32 outputDim,
        double padValueZ,
        double padValueM);

    FdoICurveSegmentAbstract * ConvertOrdinates(
        FdoICurveSegmentAbstract * cs,
        FdoInt32 outputDim,
        double padValueZ,
        double padValueM);

    double * AllocateOrdinates(FdoInt32 numOrdinates);

    FdoInt32 DimensionalityToNumOrdinates(FdoInt32 dimensionality);
};

#endif

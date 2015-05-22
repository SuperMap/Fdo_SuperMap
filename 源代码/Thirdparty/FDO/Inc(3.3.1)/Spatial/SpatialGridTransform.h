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
#ifndef FdoSpatialGridTransform___H
#define FdoSpatialGridTransform___H	1

#include <FdoCommon.h>


/// \brief
/// Class to handle transformations of ordinates between double precision
/// and integers.  The integer format models a fine grid.
class FdoSpatialGridTransform : public FdoDisposable
{
public:

    /// \brief
    /// Factory method for GridTransformer.
    /// 
    /// \remarks
    /// This models a 2D coordinate system on a grid, using 64-bit integers as ordinates.
    /// Each unit of integer is equivalent to one unit of resolution in floating point
    /// numbers.  The unit of resolution is taken to be twice the given tolerance.
    /// 
    /// \param extents 
    /// Input Extents of floating-point XY plane.
    /// \param tolerance 
    /// Tolerance of ordinate values.
    /// 
    /// \return
    /// Returns An instance of this class.
    /// 
    FDO_SPATIAL_API static FdoSpatialGridTransform * Create(
        FdoIEnvelope * extents,
        double tolerance);

    /// \brief
    /// Transform floating-point ordinates to integer ordinates on the grid.
    /// 
    /// \param x 
    /// Input Floating-point X ordinate.
    /// \param y 
    /// Input Floating-point Y ordinate.
    /// \param xGrid 
    /// Output Integer X ordinate.
    /// \param yGrid 
    /// Output Integer Y ordinate.
    /// 
    /// \return
    /// Returns Nothing.
    /// 
    FDO_SPATIAL_API void TransformToGrid(
        double x,
        double y,
        FdoInt64 * xGrid,
        FdoInt64 * yGrid);

    /// \brief
    /// Transform integer ordinates on the grid to floating-point ordinates.
    /// 
    /// \param x 
    /// Input Floating-point X ordinate.
    /// \param y 
    /// Input Floating-point Y ordinate.
    /// \param x 
    /// Output Integer X ordinate.
    /// \param y 
    /// Output Integer Y ordinate.
    /// 
    /// \return
    /// Returns Nothing.
    /// 
    FDO_SPATIAL_API void TransformFromGrid(
        FdoInt64 xGrid,
        FdoInt64 yGrid,
        double * x,
        double * y);

protected:

    /// Floating-point cordinate system parameters
    double m_minX;
    double m_minY;
    double m_maxX;
    double m_maxY;
    double m_resolution;

    /// Transformation parameters
    double m_offsetX;
    double m_offsetY;
    double m_scale;
    double m_scaleInverse;

    void CalculateParameters();

    /// Constructors and Destructor
    FdoSpatialGridTransform();
    FdoSpatialGridTransform(
        FdoIEnvelope * extents,
        double tolerance);
    virtual ~FdoSpatialGridTransform();
};

/// \ingroup (typedefs)
/// \brief
/// FdoSpatialGridTransformP is a FdoPtr on FdoSpatialGridTransform, provided for convenience.
typedef FdoPtr<FdoSpatialGridTransform> FdoSpatialGridTransformP;

#endif // FdoSpatialGridTransform___H



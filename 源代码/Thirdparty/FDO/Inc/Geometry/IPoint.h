#ifndef _IPOINT_H_
#define _IPOINT_H_

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

#include <Geometry/IGeometry.h>
#include <Geometry/IDirectPosition.h>
#include <Common/Collection.h>

/// \brief
/// The FdoIPoint class is a point Geometry type.
class FdoIPoint : public FdoIGeometry
{
public:

    /// \brief
    /// Gets the position of this point Geometry.
    /// 
    /// \return
    /// Returns the position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetPosition() const = 0;

    /// \brief
    /// Gets the position of this point Geometry, by values of its member data.
    /// This is in aid of higher performance for any implementation that
    /// does not internally use FdoIDirectPosition objects for storage, or for
    /// an application seeking to avoid overhead of accessor methods.
    /// 
    /// \param x 
    /// Output X ordinate value.
    /// \param y 
    /// Output Y ordinate value.
    /// \param z 
    /// Output Z ordinate value.
    /// \param m 
    /// Output M ordinate value.
    /// \param dimensionality 
    /// Output Dimensionality of ordinates in this position.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual void GetPositionByMembers(
        double *x,
        double *y,
        double *z,
        double *m,
        FdoInt32 *dimensionality) const = 0;

    /// \brief
    /// Gets the ordinates as an array.
    /// 
    /// \remarks
    /// The caller must not free the returned array.
    /// The ordinates are in the order XYZMXYZM..., with only those present 
    /// according to the dimensionality.
    /// 
    /// \return
    /// Returns the ordinates
    /// 
    FDO_GEOM_API virtual const double * GetOrdinates() = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIPoint() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIPoint() {};
};


/// \brief
///  The FdoPointCollection class is a collection of CurvePolygon objects.
class FdoPointCollection : public FdoCollection<FdoIPoint, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoPointCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoPointCollection* Create()
    {
        FdoPointCollection* value = new FdoPointCollection();
        if (NULL == value)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));

        return value;
    }

protected:
    void Dispose()
    {
        delete this;
    }
};
#endif



#ifndef _ILINEARRING_H_
#define _ILINEARRING_H_

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


#include <Geometry/IRingAbstract.h>
#include <Geometry/IDirectPosition.h>
#include <Common/Collection.h>

/// \brief
/// The FdoILinearRing class is a linear ring helper type.
/// The shape of FdoILinearRing is the set of positions defined by the contained collection, 
/// plus linear interpolation between consecutive points.
class FdoILinearRing : public FdoIRingAbstract
{
public:

    /// \brief
    /// Gets the number of positions in this object.
    /// 
    /// \return
    /// Returns the number of positions
    /// 
    FDO_GEOM_API virtual FdoInt32 GetCount() const = 0;

    /// \brief
    /// Gets the position at the specified (zero-based) index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of positions.
    /// 
    /// \return
    /// Returns the position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* GetItem(
        FdoInt32 index) const = 0;

    /// \brief
    /// Gets the position at the specified (zero-based) index, by values of its member data.
    /// This is in aid of higher performance for any implementation that
    /// does not internally use FdoIDirectPosition objects for storage, or for
    /// an application seeking to avoid overhead of accessor methods.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of positions.
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
    FDO_GEOM_API virtual void GetItemByMembers(
        FdoInt32 index,
        double *x,
        double *y,
        double *z,
        double *m,
        FdoInt32 *dimensionality) const = 0;

    /// \brief
    /// Gets a collection of all of the positions in this object.
    /// 
    /// \return
    /// Returns the positions
    /// 
    FDO_GEOM_API virtual FdoDirectPositionCollection* GetPositions() = 0;

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
    FDO_GEOM_API FdoILinearRing() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoILinearRing() {};
};

/// \brief
///  The FdoLinearRingCollection class is a collection of CurvePolygon objects.
class FdoLinearRingCollection : public FdoCollection<FdoILinearRing, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoLinearRingCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoLinearRingCollection* Create()
    {
        FdoLinearRingCollection* value = new FdoLinearRingCollection();
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



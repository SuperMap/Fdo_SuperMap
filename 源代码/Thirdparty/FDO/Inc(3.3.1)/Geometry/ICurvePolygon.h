#ifndef _ICURVEPOLYGON_H_
#define _ICURVEPOLYGON_H_

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

#include <Geometry/ISurfaceAbstract.h>
#include <Geometry/IRing.h>
#include <Common/Collection.h>

/// \brief
/// The FdoICurvePolygon class is a CurvePolygon geometry type.  
/// This type is defined by one exterior boundary and zero or more 
/// interior boundaries.
/// Each of the boundaries must be a closed, simple Ring.
class FdoICurvePolygon : public FdoISurfaceAbstract
{
public:

    /// \brief
    /// Gets the ring defining the outer boundary.
    /// 
    /// \return
    /// Returns the exterior ring
    /// 
    FDO_GEOM_API virtual FdoIRing* GetExteriorRing() const = 0;

    /// \brief
    /// Gets the number of interior rings.
    /// 
    /// \return
    /// Returns the number of interior rings
    /// 
    FDO_GEOM_API virtual FdoInt32 GetInteriorRingCount() const = 0;

    /// \brief
    /// Gets the interior ring at the specified (zero-based) index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of interior rings.
    /// 
    /// \return
    /// Returns the interior ring
    /// 
    FDO_GEOM_API virtual FdoIRing* GetInteriorRing(
        FdoInt32 index) const = 0;

protected:
    
    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoICurvePolygon() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoICurvePolygon() {};
};


/// \brief
///  The FdoCurvePolygonCollection class is a collection of CurvePolygon objects.
class FdoCurvePolygonCollection : public FdoCollection<FdoICurvePolygon, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoCurvePolygonCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoCurvePolygonCollection* Create()
    {
        FdoCurvePolygonCollection* value = new FdoCurvePolygonCollection();
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



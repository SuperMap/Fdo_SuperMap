#ifndef _ICURVESTRING_H_
#define _ICURVESTRING_H_

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

#include <Geometry/ICurveAbstract.h>
#include <Geometry/ICurveSegmentAbstract.h>
#include <Common/Collection.h>

/// \brief
/// The FdoICurveString class is a CurveString Geometry type. FdoICurveString is the most general non-abstract curve type.  
/// It is defined by an ordered collection of contiguous curve segments.
class FdoICurveString : public FdoICurveAbstract
{
public:

    /// \brief
    /// Gets the number of curve segments in this curve.  
    /// 
    /// \return
    /// Returns the number of curve segments
    /// 
    FDO_GEOM_API virtual FdoInt32 GetCount() const = 0;

    /// \brief
    /// Gets the curve segment at the given zero-based index.
    /// 
    /// \param index 
    /// Input Zero-based index in the object's list of curve segments.
    /// 
    /// \return
    /// Returns the requested curve segment
    /// 
    FDO_GEOM_API virtual FdoICurveSegmentAbstract* GetItem(
        FdoInt32 index) const = 0;

    /// \brief
    /// Gets all the curve segments.
    /// 
    /// \return
    /// Returns a collection of all the curve segments
    /// 
    FDO_GEOM_API virtual FdoCurveSegmentCollection * GetCurveSegments() const = 0;

protected:


    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoICurveString() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoICurveString() {};

};


/// \brief
///  The FdoCurveStringCollection class is a collection of CurvePolygon objects.
class FdoCurveStringCollection : public FdoCollection<FdoICurveString, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoCurveStringCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoCurveStringCollection* Create()
    {
        FdoCurveStringCollection* value = new FdoCurveStringCollection();
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



#ifndef _IDIRECTPOSITION_H_
#define _IDIRECTPOSITION_H_

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

#include <FdoCommon.h>
#include <Common/Collection.h>
#include <Common/Dimensionality.h>

/// \brief
/// The FdoIDirectPosition class is a direct position object.  
/// FdoIDirectPosition is a simple coordinate position in any allowed dimension.  
/// The actual object may have several implementations, depending on
/// the dimension and other factors.
/// This is a lightweight helper type for Geometries in the Geometry package.
/// \note
/// It does not derive from IGeometry.
class FdoIDirectPosition : public FdoIDisposable
{
public:


    /// \brief
    /// Gets the X ordinate.
    /// 
    /// \return
    /// Returns the X ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API virtual double GetX() const = 0;
    
    /// \brief
    /// Gets the Y ordinate.
    /// 
    /// \return
    /// Returns the Y ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API virtual double GetY() const = 0;
    
    /// \brief
    /// Gets the Z ordinate.
    /// 
    /// \return
    /// Returns the Z ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API virtual double GetZ() const = 0;

    /// \brief
    /// Gets the M ordinate.
    /// 
    /// \return
    /// Returns the M ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API virtual double GetM() const = 0;

    /// \brief
    /// Gets the ordinates as an array.
    /// 
    /// \remarks
    /// The caller must not free the returned array.
    /// The ordinates are in the order XYZM, with only those present 
    /// according to the dimensionality.
    /// 
    /// \return
    /// Returns the ordinates
    /// 
    FDO_GEOM_API virtual const double * GetOrdinates() = 0;

    /// \brief
    /// Gets the dimensionality of ordinates in this position.
    /// 
    /// \remarks
    ///  Values are from the FdoDimensionality enumeration.
    /// A return type of "FdoInt32" is used instead of the enumeration, catering to typical use with bit masking.
    /// 
    /// \return
    /// Returns the ordinate dimensionality
    /// 
    FDO_GEOM_API virtual FdoInt32 GetDimensionality() const = 0;

protected:

    /// \brief
    /// Constructs a default instance.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoIDirectPosition() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIDirectPosition() {};
};


/// \brief
///  The FdoDirectPositionCollection class is a collection of DirectPosition objects.
class FdoDirectPositionCollection : public FdoCollection<FdoIDirectPosition, FdoException>
{
public:
    /// \brief
    ///  Creates an instance of FdoDirectPositionCollection with no contained elements.
    /// 
    /// \return
    /// Returns an empty collection
    /// 
    static FdoDirectPositionCollection* Create()
    {
        FdoDirectPositionCollection* value = new FdoDirectPositionCollection();
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



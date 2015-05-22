#ifndef _IRINGABSTRACT_H_
#define _IRINGABSTRACT_H_

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
#include <Geometry/IEnvelope.h>
#include <Common/Dimensionality.h>

/// \brief
/// The FdoIRingAbstract class is a ring Geometry helper type (abstract). FdoIRingAbstract is the most general ring type.
/// It is similar to CurveAbstract, but is always closed.
class FdoIRingAbstract : public FdoIDisposable
{
public:

    /// \brief
    /// Gets the envelope for the object.
    /// 
    /// \return
    /// Returns the envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* GetEnvelope() const = 0;

    /// \brief
    /// Gets the dimensionality of ordinates in this object.
    /// 
    /// \remarks
    ///  Values are from the FdoDimensionality enum.
    /// A return type of "FdoInt32" is used instead of the enum, catering to typical use with bit masking.
    /// 
    /// \return
    /// Returns the ordinate dimensionality
    /// 
    FDO_GEOM_API virtual FdoInt32 GetDimensionality() const = 0;

protected:

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoIRingAbstract() {};
};
#endif



#ifndef _INTBINVALUE_H_
#define _INTBINVALUE_H_
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
#include <Fdo/Expression/DataValue.h>
#include <Fdo/Schema/DataType.h>
#include <Fdo/Expression/Int64Value.h>

/// \brief
/// The FdoIntBinValue class derives from FdoInt64Value and represents a binary value.
class FdoIntBinValue : public FdoInt64Value
{
/// \cond DOXYGEN-IGNORE
    friend class FdoByteValue;
    friend class FdoInt16Value;
    friend class FdoInt32Value;
protected:
    /// \brief
    /// Constructs a default instance of an FdoIntBinValue with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoIntBinValue();

    /// \brief
    /// Constructs a default instance of an FdoIntBinValue using the specified arguments.
    /// \param value 
    /// Input a 32 bit binary integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoIntBinValue(FdoInt64 value);

    /// \brief
    /// Default destructor for FdoIntBinValue.
    virtual ~FdoIntBinValue();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoIntBinValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoIntBinValue
    /// 
    static FdoIntBinValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoIntBinValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a 32 bit binary integer
    /// 
    /// \return
    /// Returns the created FdoIntBinValue
    /// 
    static FdoIntBinValue* Create(FdoInt64 value);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FdoString* ToString();

    /// 
    FdoIntBinValue* Create(
        FdoDataValue* src, 
        FdoBoolean truncate = false, 
        FdoBoolean nullIfIncompatible = false
    );

/// \endcond
};
#endif

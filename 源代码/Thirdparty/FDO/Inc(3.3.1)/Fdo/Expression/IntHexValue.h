#ifndef _INTHEXVALUE_H_
#define _INTHEXVALUE_H_
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
/// The FdoIntHexValue class derives from FdoInt64Value and represents a hex value.
class FdoIntHexValue : public FdoInt64Value
{
/// \cond DOXYGEN-IGNORE
    friend class FdoByteValue;
    friend class FdoInt16Value;
    friend class FdoInt32Value;
protected:
    /// \brief
    /// Constructs a default instance of an FdoIntHexValue with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoIntHexValue();

    /// \brief
    /// Constructs a default instance of an FdoIntHexValue using the specified arguments.
    /// \param value 
    /// Input a 32 bit hex integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoIntHexValue(FdoInt64 value);

    /// \brief
    /// Default destructor for FdoIntHexValue.
    virtual ~FdoIntHexValue();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoIntHexValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoIntHexValue
    /// 
    static FdoIntHexValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoIntHexValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a 32 bit hex integer
    /// 
    /// \return
    /// Returns the created FdoIntHexValue
    /// 
    static FdoIntHexValue* Create(FdoInt64 value);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FdoString* ToString();

    /// 
    FdoIntHexValue* Create(
        FdoDataValue* src, 
        FdoBoolean truncate = false, 
        FdoBoolean nullIfIncompatible = false
    );

/// \endcond
};
#endif

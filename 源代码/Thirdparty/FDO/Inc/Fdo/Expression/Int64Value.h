#ifndef _INT64VALUE_H_
#define _INT64VALUE_H_
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

/// \brief
/// The FdoInt64Value class derives from FdoDataValue and represents a 64-bit signed integer value.
class FdoInt64Value : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoInt64Value with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoInt64Value();

    /// \brief
    /// Constructs a default instance of an FdoInt64Value using the specified arguments.
    /// \param value 
    /// Input a 64 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoInt64Value(FdoInt64 value);

    /// \brief
    /// Default destructor for FdoInt64Value.
    virtual ~FdoInt64Value();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoInt64Value with a value of null.
    /// 
    /// \return
    /// Returns the created FdoInt64Value
    /// 
    FDO_API static FdoInt64Value* Create();

    /// \brief
    /// Constructs a default instance of an FdoInt64Value using the specified arguments.
    /// 
    /// \param value 
    /// Input a 64 bit integer
    /// 
    /// \return
    /// Returns the created FdoInt64Value
    /// 
    FDO_API static FdoInt64Value* Create(FdoInt64 value);

    /// \brief
    /// Gets the data type of the FdoInt64Value.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoInt64Value.
    /// 
    /// \return
    /// Returns a 64 bit integer
    /// 
    FDO_API FdoInt64 GetInt64();

    /// \brief
    /// Sets the FdoInt64Value.
    /// 
    /// \param value 
    /// Input a 64 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetInt64(FdoInt64 value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoInt64Value to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input an FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// A cast operator to get the integer value.
    /// 
    /// \return
    /// Returns a 64 bit integer
    /// 
    FDO_API operator FdoInt64()
    {
        return m_data;
    }

protected:
    FdoInt64    m_data;
};
#endif



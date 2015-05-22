#ifndef _INT16VALUE_H_
#define _INT16VALUE_H_
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
/// The FdoInt16Value class derives from FdoDataValue and represents a 16-bit signed integer value.
class FdoInt16Value : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
    friend class FdoByteValue;
protected:
    /// \brief
    /// Constructs a default instance of an FdoInt16Value with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoInt16Value();

    /// \brief
    /// Constructs a default instance of an FdoInt16Value using the specified arguaments.
    /// \param value 
    /// Input a 16 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoInt16Value(FdoInt16 value);

    /// \brief
    /// Default destructor for FdoInt16Value.
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoInt16Value();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoInt16Value with a value of null.
    /// 
    /// \return
    /// Returns the created FdoInt16Value
    /// 
    FDO_API static FdoInt16Value* Create();

    /// \brief
    /// Constructs a default instance of an FdoInt16Value using the specified arguments.
    /// 
    /// \param value 
    /// Input a 16 bit integer
    /// 
    /// \return
    /// Returns the created FdoInt16Value
    /// 
    FDO_API static FdoInt16Value* Create(FdoInt16 value);

    /// \brief
    /// Gets the data type of the FdoInt16Value.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoInt16Value.
    /// 
    /// \return
    /// Returns a 16 bit integer
    /// 
    FDO_API FdoInt16 GetInt16();

    /// \brief
    /// Sets the FdoInt16Value.
    /// 
    /// \param value 
    /// Input a 16 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetInt16(FdoInt16 value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoInt16Value to the appropriate
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
    /// Returns a 16 bit integer
    /// 
    FDO_API operator FdoInt16()
    {
        return m_data;
    }

/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs an instance of an FdoInt16Value from another FdoDataValue.
    /// 
    /// \param src 
    /// Input the other FdoDataValue. Must be of one of the following types:
    ///     FdoDataType_Byte
    ///     FdoDataType_Int16
    /// \param truncate 
    /// Input in the future, will determine what to do if source value does not fit in the int16
    /// number range:
    ///     true - truncate the value to fit.
    ///     false - throw an exception
    /// \param nullIfIncompatible 
    /// Input in the future, will determine what to do if source value type is not compatible with the 
    /// FDO int16 type:
    ///     true - return NULL.
    ///     false - throw an exception
    /// 
    /// \return
    /// Returns an FdoInt16Value
    /// 
    static FdoInt16Value* Create(
        FdoDataValue* src, 
        FdoBoolean truncate = false, 
        FdoBoolean nullIfIncompatible = false
    );

    // See FdoDataValue::DoCompare()
    virtual FdoCompareType DoCompare( FdoDataValue* other );

    FdoInt16    m_data;
/// \endcond
};
#endif



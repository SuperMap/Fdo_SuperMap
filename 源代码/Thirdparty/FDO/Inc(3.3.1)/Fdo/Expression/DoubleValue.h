#ifndef _DOUBLEVALUE_H_
#define _DOUBLEVALUE_H_
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
/// The FdoDoubleValue class derives from FdoDataValue and represents a double-precision floating point number.
class FdoDoubleValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
    friend class FdoByteValue;
    friend class FdoInt16Value;
    friend class FdoInt32Value;
    friend class FdoInt64Value;
    friend class FdoSingleValue;
protected:
    /// \brief
    /// Constructs a default instance of an FdoDoubleValue with a
    /// value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDoubleValue();

    /// \brief
    /// Constructs a default instance of an FdoDoubleValue using the
    /// specified arguments.
    /// 
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDoubleValue(double value);

    /// \brief
    /// Default destructor for FdoDoubleValue.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoDoubleValue();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoDoubleValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoDoubleValue
    /// 
    FDO_API static FdoDoubleValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoDoubleValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns the created FdoDoubleValue
    /// 
    FDO_API static FdoDoubleValue* Create(double value);

    /// \brief
    /// Gets the data type of the FdoDoubleValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the double value.
    /// 
    /// \return
    /// Returns a double
    /// 
    FDO_API double GetDouble();

    /// \brief
    /// Sets the double value as a double precision floating point number.
    /// 
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDouble(double value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoDoubleValue to the appropriate
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
    /// A cast operator to get the double value.
    /// 
    /// \return
    /// Returns a double
    /// 
    FDO_API operator double()
    {
        return m_data;
    }

/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs an instance of an FdoDoubleValue from another FdoDataValue.
    /// 
    /// \param src 
    /// Input the other FdoDataValue. Must be of one of the following types:
    ///     FdoDataType_Byte
    ///     FdoDataType_Decimal
    ///     FdoDataType_Double
    ///     FdoDataType_Int16
    ///     FdoDataType_Int32
    ///     FdoDataType_Int64
    ///     FdoDataType_Single
    /// \param truncate 
    /// Input in the future, will determine what to do if source value does not fit in the double 
    /// number range:
    ///     true - truncate the value to fit.
    ///     false - throw an exception
    /// \param nullIfIncompatible 
    /// Input in the future, will determine what to do if source value type is not compatible with the 
    /// FDO double type:
    ///     true - return NULL.
    ///     false - throw an exception
    /// 
    /// \return
    /// Returns an FdoDoubleValue
    /// 
    static FdoDoubleValue* Create(
        FdoDataValue* src, 
        FdoBoolean truncate = false, 
        FdoBoolean nullIfIncompatible = false
    );

    // See FdoDataValue::DoCompare()
    virtual FdoCompareType DoCompare( FdoDataValue* other );

    double  m_data;
/// \endcond
};
#endif



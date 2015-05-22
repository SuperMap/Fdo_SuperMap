#ifndef _DECIMALVALUE_H_
#define _DECIMALVALUE_H_
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
/// The FdoDecimalValue class derives from FdoDataValue and represents a decimal value.
class FdoDecimalValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoDecimalValue with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoDecimalValue();

    /// \brief
    /// Constructs a default instance of an FdoDecimalValue using the specified arguments.
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDecimalValue(double value);

    /// \brief
    /// Default destructor for FdoDecimalValue.
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoDecimalValue();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoDecimalValue with a value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoDecimalValue* Create();

    /// \brief
    /// Constructs an instance of an FdoDecimalValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoDecimalValue* Create(double value);

    /// \brief
    /// Gets the data type of the FdoDecimalValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the decimal value.
    /// 
    /// \return
    /// Returns a double
    /// 
    FDO_API double GetDecimal();

    /// \brief
    /// Sets the decimal value.
    /// 
    /// \param value 
    /// Input a double
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDecimal(double value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoDecimalValue to the appropriate
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
    /// A cast operator to get the decimal value.
    /// 
    /// \return
    /// Returns a double
    /// 
    FDO_API operator double()
    {
        return m_data;
    }

protected:
/// \cond DOXYGEN-IGNORE
    double  m_data;
};
/// \endcond
#endif



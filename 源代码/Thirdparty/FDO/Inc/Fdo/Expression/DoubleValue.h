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

protected:
/// \cond DOXYGEN-IGNORE
    double  m_data;
};
/// \endcond
#endif



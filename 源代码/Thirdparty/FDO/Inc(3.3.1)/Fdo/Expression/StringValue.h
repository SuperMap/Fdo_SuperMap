#ifndef _STRINGVALUE_H_
#define _STRINGVALUE_H_
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
/// The FdoStringValue class derives from FdoDataValue and represents a literal string.
class FdoStringValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoStringValue with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoStringValue();

    /// \brief
    /// Constructs a default instance of an FdoStringValue using the specified arguments.
    /// \return
    /// Returns nothing
    /// 
    FdoStringValue(FdoString* value);

    /// \brief
    /// Default destructor for FdoStringValue.
    virtual ~FdoStringValue();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoStringValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoStringValue
    /// 
    FDO_API static FdoStringValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoStringValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a character string
    /// 
    /// \return
    /// Returns the created FdoStringValue
    /// 
    FDO_API static FdoStringValue* Create(FdoString* value);

    /// \brief
    /// Gets the data type of the FdoStringValue.
    /// 
    /// \return
    /// Returns FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoStringValue as a string.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FDO_API FdoString* GetString();

    /// \brief
    /// Sets the FdoStringValue as a string.
    /// 
    /// \param value 
    /// Input a character string
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetString(FdoString* value);

    /// \brief
    /// Sets the FdoStringValue to a null value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetNull();

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoStringValue to the appropriate
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
    /// A cast operator to get the string.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FDO_API operator wchar_t*()
    {
        return m_data;
    }

protected:
    // See FdoDataValue::DoCompare()
    virtual FdoCompareType DoCompare( FdoDataValue* other );

    wchar_t*    m_data;
    size_t      m_allocatedSize;
};
#endif



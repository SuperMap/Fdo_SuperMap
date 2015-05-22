#ifndef _DATATIMEVALUE_H_
#define _DATATIMEVALUE_H_
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
/// The FdoDateTimeValue class derives from FdoDataValue and represents a date or time.
class FdoDateTimeValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoDateTimeValue with a
    /// value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDateTimeValue();

    /// \brief
    /// Constructs a default instance of an FdoDateTimeValue using the specified
    /// arguments.
    /// 
    /// \param value 
    /// Input a FdoDateTime
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDateTimeValue(FdoDateTime value);

    /// \brief
    /// Default destructor for FdoDateTimeValue.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoDateTimeValue();

    virtual void Dispose();
    /// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoDateTimeValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoDateTimeValue
    /// 
    FDO_API static FdoDateTimeValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoDateTimeValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a FdoDateTime
    /// 
    /// \return
    /// Returns the created FdoDateTimeValue
    /// 
    FDO_API static FdoDateTimeValue* Create(FdoDateTime value);

    /// \brief
    /// Gets the data type of the FdoDateTimeValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the date time value.
    /// 
    /// \return
    /// Returns a FdoDateTime
    /// 
    FDO_API FdoDateTime GetDateTime();

    /// \brief
    /// Sets the date time value.
    /// 
    /// \param value 
    /// Input a FdoDateTime
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDateTime(FdoDateTime value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoDateTimeValue to the appropriate
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
    /// A cast operator to get the date time value.
    /// 
    /// \return
    /// Returns a FdoDateTime
    /// 
    FDO_API operator FdoDateTime()
    {
        return m_data;
    }

/// \cond DOXYGEN-IGNORE
protected:
    // See FdoDataValue::DoCompare()
    virtual FdoCompareType DoCompare( FdoDataValue* other );

    FdoDateTime m_data;
/// \endcond
};
#endif



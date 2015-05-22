#ifndef _BOOLEANVALUE_H_
#define _BOOLEANVALUE_H_
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

/// \brief
/// The FdoBooleanValue class derives from FdoDataValue and represents a Boolean
/// value.
class FdoBooleanValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoBooleanValue with a
    /// value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoBooleanValue();

    /// \brief
    /// Constructs a default instance of an FdoBooleanValue using the specified
    /// arguments.
    /// 
    /// \param value 
    /// Input a Boolean value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoBooleanValue(bool value);

    /// \brief
    /// Default destructor for FdoBooleanValue.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoBooleanValue();

    virtual void Dispose();

/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoBooleanValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoBooleanValue
    /// 
    FDO_API static FdoBooleanValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoBooleanValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a Boolean value
    /// 
    /// \return
    /// Returns the created FdoBooleanValue
    /// 
    FDO_API static FdoBooleanValue* Create(bool value);

    /// \brief
    /// Gets the data type of the FdoBooleanValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoBooleanValue.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API bool GetBoolean();

    /// \brief
    /// Sets the Boolean value.
    /// 
    /// \param value 
    /// Input a Boolean value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetBoolean(bool value);

    /// \brief
    ///  Overrides FdoExpression.Process to pass the FdoBooleanValue to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input the FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a character string.
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// A cast operator to get the Boolean value.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API operator bool()
    {
        return m_data;
    }

protected:
    bool        m_data;
};
#endif



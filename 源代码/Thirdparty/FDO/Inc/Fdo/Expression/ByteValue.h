#ifndef _BYTEVALUE_H_
#define _BYTEVALUE_H_
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
/// The FdoByteValue class derives from FdoDataValue and represents a literal
/// byte value.
class FdoByteValue : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoByteValue with a value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoByteValue();

    /// \brief
    /// Constructs a default instance of an FdoByteValue using the specified arguments.
    /// \param value 
    /// Input a byte
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoByteValue(FdoByte value);

    /// \brief
    /// Default destructor for FdoByteValue.
    virtual ~FdoByteValue();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoByteValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoByteValue
    /// 
    FDO_API static FdoByteValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoByteValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte
    /// 
    /// \return
    /// Returns the created FdoByteValue
    /// 
    FDO_API static FdoByteValue* Create(FdoByte value);

    /// \brief
    /// Gets the data type of the FdoByteValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoByteValue.
    /// 
    /// \return
    /// Returns a byte
    /// 
    FDO_API FdoByte GetByte();

    /// \brief
    /// Sets the byte value.
    /// 
    /// \param value 
    /// Input a byte
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetByte(FdoByte value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoByteValue to the appropriate
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
    /// Returns a text string
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// A cast operator to get the byte value.
    /// 
    /// \return
    /// Returns a byte
    /// 
    FDO_API operator FdoByte()
    {
        return m_data;
    }

protected:
/// \cond DOXYGEN-IGNORE
    FdoByte m_data;
};
/// \endcond
#endif



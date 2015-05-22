#ifndef _DATAVALUE_H_
#define _DATAVALUE_H_
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
#include <Fdo/Expression/LiteralValue.h>
#include <Fdo/Schema/DataType.h>

/// \brief
/// The FdoDataValue class derives from FdoLiteralValue and represents a literal
/// value such as a string or a number.
class FdoDataValue : public FdoLiteralValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    ///  Constructs a default instance of an FdoDataValue with data type string and a
    /// value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoDataValue();
/// \endcond

public:
    /// \brief
    /// Constructs an instance of a null FdoDataValue using the specified arguments.
    /// 
    /// \param dataType 
    /// Input data type
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoDataValue* Create(FdoDataType dataType);

    /// \brief
    /// Constructs an instance of an FdoBooleanValue using the specified argument.
    /// 
    /// \param value 
    /// Input a Boolean value
    /// 
    /// \return
    /// Returns an FdoBooleanValue
    /// 
    FDO_API static FdoDataValue* Create(bool value);

    /// \brief
    /// Constructs an instance of an FdoByteValue using the specified argument.
    /// 
    /// \param value 
    /// Input a byte
    /// 
    /// \return
    /// Returns an FdoByteValue
    /// 
    FDO_API static FdoDataValue* Create(FdoByte value);

    /// \brief
    /// Constructs an instance of an FdoDateTimeValue using the specified argument.
    /// 
    /// \param value 
    /// Input a FdoDateTime
    /// 
    /// \return
    /// Returns an FdoDateTimeValue
    /// 
    FDO_API static FdoDataValue* Create(FdoDateTime value);

    /// \brief
    /// Constructs an instance of an FdoDecimalValue or FdoDoubleValue using 
    /// the specified arguments.
    /// 
    /// \param value 
    /// Input a double
    /// \param dataType 
    /// Input a data type
    /// 
    /// \return
    /// Returns an FdoDecimalValue or FdoDoubleValue
    /// 
    FDO_API static FdoDataValue* Create(double value, FdoDataType dataType);

    /// \brief
    /// Constructs an instance of an FdoInt16Value using the specified argument.
    /// 
    /// \param value 
    /// Input a 16 bit integer
    /// 
    /// \return
    /// Returns an FdoInt16Value
    /// 
    FDO_API static FdoDataValue* Create(FdoInt16 value);

    /// \brief
    /// Constructs an instance of an FdoInt32Value using the specified argument.
    /// 
    /// \param value 
    /// Input a 32 bit integer
    /// 
    /// \return
    /// Returns an FdoInt32Value
    /// 
    FDO_API static FdoDataValue* Create(FdoInt32 value);

    /// \brief
    /// Constructs an instance of an FdoInt64Value using the specified argument.
    /// 
    /// \param value 
    /// Input a 64 bit integer
    /// 
    /// \return
    /// Returns an FdoInt64Value
    /// 
    FDO_API static FdoDataValue* Create(FdoInt64 value);

    /// \brief
    /// Constructs an instance of an FdoSingleValue using the specified argument.
    /// 
    /// \param value 
    /// Input a single precision floating point value
    /// 
    /// \return
    /// Returns an FdoSingleValue
    /// 
    FDO_API static FdoDataValue* Create(float value);

    /// \brief
    /// Constructs an instance of an FdoStringValue using the specified argument.
    /// 
    /// \param value 
    /// Input a character string
    /// 
    /// \return
    /// Returns an FdoStringValue
    /// 
    FDO_API static FdoDataValue* Create(FdoString* value);

    /// \brief
    /// Constructs an instance of an FdoBLOBValue or FdoCLOBValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte array
    /// \param length 
    /// Input the length of the byte array
    /// \param dataType 
    /// Input the type of value to create
    /// 
    /// \return
    /// Returns an FdoBLOBValue or an FdoCLOBValue
    /// 
    FDO_API static FdoDataValue* Create(FdoByte* value, FdoInt32 length, FdoDataType dataType);

    /// \brief
    /// Constructs an instance of an FdoBLOBValue or FdoCLOBValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte array
    /// \param dataType 
    /// Input the type of value to create
    /// 
    /// \return
    /// Returns an FdoBLOBValue or an FdoCLOBValue
    /// 
    FDO_API static FdoDataValue* Create(FdoByteArray* value, FdoDataType dataType);

    /// \brief
    /// Gets the data type of the FdoDataValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API virtual FdoDataType GetDataType() = 0;

    /// \brief
    /// Returns true if the FdoDataValue represents a null value.
    /// 
    /// \return
    /// Returns true if the FdoDataValue represents a null value
    /// 
    FDO_API virtual bool IsNull();

    /// \brief
    /// Sets the FdoDataValue to a null value of the specified type.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetNull();

	static FdoDataValue* Create(FdoString* value, FdoDataType dataType);

    // Get the value as an XML format string.
    FdoString* GetXmlValue();

/// \cond DOXYGEN-IGNORE
protected:
    bool        m_isNull;
    FdoStringP  m_XmlValue; // Manages GetXmlValue return string when datatype is datetime.
/// \endcond
	 
};

/// \ingroup (typedefs)
/// \brief
/// FdoDataValueP is a FdoPtr on FdoDataValue, provided for convenience.
typedef FdoPtr<FdoDataValue> FdoDataValueP;

#endif



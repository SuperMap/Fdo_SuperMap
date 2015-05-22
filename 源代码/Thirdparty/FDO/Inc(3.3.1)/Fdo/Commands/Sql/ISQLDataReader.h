#ifndef _ISQLDATAREADER_H_
#define _ISQLDATAREADER_H_

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

/// \brief
/// The FdoISQLDataReader interface provides a forward-only, read-only
/// iterator for reading relational table data. A reference to an
/// FdoISQLDataReader is returned from the SQLCommands ExecuteReader method.
/// The initial position of the FdoISQLDataReader interface is prior to the first item.
/// Thus, you must call ReadNext to begin accessing any data.
class FdoISQLDataReader: public FdoIDisposable
{
public:
    /// \brief
    /// Gets the number of columns in the result set.
    /// 
    /// \return
    /// Returns the number of columns.
    /// 
    FDO_API virtual FdoInt32 GetColumnCount() = 0;

    /// \brief
    /// Gets the name of the column at the given ordinal position.
    /// 
    /// \param index 
    /// Input the position of the column.
    /// 
    /// \return
    /// Returns the column name
    /// 
    FDO_API virtual FdoString* GetColumnName(FdoInt32 index) = 0;

    /// \brief
    /// Gets the data type of the column with the specified name.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the type of the column.
    /// 
    FDO_API virtual FdoDataType GetColumnType(FdoString* columnName) = 0;

    /// \brief
    /// Gets the FDO property type of the column with the specified name. This is used
    ///  to indicate if a given column is a geometric property or a data property. If the column is
    ///  a FdoPropertyType_DataProperty, then GetColumnType can be used to find the data type of the column.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the FDO property type of the column.
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType(FdoString* columnName) = 0;

    /// \brief
    /// Gets the Boolean value of the specified column. No conversion is
    /// performed, thus the column must be FdoDataType_Boolean or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the Boolean value
    /// 
    FDO_API virtual bool GetBoolean(FdoString* columnName) = 0;

    /// \brief
    /// Gets the byte value of the specified column. No conversion is
    /// performed, thus the column must be FdoDataType_Byte or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the byte value.
    /// 
    FDO_API virtual FdoByte GetByte(FdoString* columnName) = 0;

    /// \brief
    /// Gets the date time value of the specified column. No conversion
    /// is performed, thus the column must be FdoDataType_DateTime or
    /// an exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the date and time value.
    /// 
    FDO_API virtual FdoDateTime GetDateTime(FdoString* columnName) = 0;

    /// \brief
    /// Gets the double-precision floating point value of the specified column.
    /// No conversion is performed, thus the column must be of type
    /// Double or an exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the double value.
    /// 
    FDO_API virtual double GetDouble(FdoString* columnName) = 0;

    /// \brief
    /// Gets the signed 16-bit integer value of the specified column. No conversion is
    /// performed, thus the column must be FdoDataType_Int16 or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the FdoInt16 value.
    /// 
    FDO_API virtual FdoInt16 GetInt16(FdoString* columnName) = 0;

    /// \brief
    /// Gets the signed 32-bit integer value of the specified column. No conversion is
    /// performed, thus the column must be FdoDataType_Int32 or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the FdoInt32 value.
    /// 
    FDO_API virtual FdoInt32 GetInt32(FdoString* columnName) = 0;

    /// \brief
    /// Gets the signed 64-bit integer value of the specified column. No conversion
    /// is performed, thus the column must be FdoDataType_Int64 or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the FdoInt64 value.
    /// 
    FDO_API virtual FdoInt64 GetInt64(FdoString* columnName) = 0;

    /// \brief
    /// Gets the single-precision floating point value of the specified column.
    /// No conversion is performed, thus the column must be FdoDataType_Single
    /// or an exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the single value
    /// 
    FDO_API virtual float GetSingle(FdoString* columnName) = 0;

    /// \brief
    /// Gets the string value of the specified column. No conversion is
    /// performed, thus the column must be FdoDataType_String or an
    /// exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the string value.
    /// 
    FDO_API virtual FdoString* GetString(FdoString* columnName) = 0;

    /// \brief
    /// Gets a LOBValue reference. The LOB is fully read in and data available.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB or
    /// FdoDataType_CLOB etc. (a LOB type)
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the reference to LOBValue
    /// 
    FDO_API virtual FdoLOBValue* GetLOB(FdoString* propertyName) = 0;

    /// \brief
    /// Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
    /// FdoCLOBStreamReader etc. to allow reading in blocks of data.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB 
    /// or FdoDataType_CLOB etc. (a LOB type)
    /// Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns a reference to a LOB stream reader
    /// 
    FDO_API virtual FdoIStreamReader* GetLOBStreamReader(const wchar_t* propertyName ) = 0;

    /// \brief
    /// Returns true if the value of the specified column is null.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns true if the value is null.
    /// 
    FDO_API virtual bool IsNull(FdoString* columnName) = 0;

    /// \brief
    /// Gets the geometry value of the specified column as a byte array
    /// in FGF format. No conversion is performed, thus the column
    /// must be of Geometric type or an exception is thrown.
    /// 
    /// \param columnName 
    /// Input the column name.
    /// 
    /// \return
    /// Returns the FGF byte array value.
    /// 
    FDO_API virtual FdoByteArray* GetGeometry(FdoString* columnName) = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoISQLDataReader object, freeing any resources it may be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;
};
#endif



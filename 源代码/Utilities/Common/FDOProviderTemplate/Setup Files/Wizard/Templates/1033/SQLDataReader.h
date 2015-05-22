#ifndef [!output PREFIX]SQLREADER_H
#define [!output PREFIX]SQLREADER_H     1
/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the GNU Lesser
 * General Public License as published by the Free Software Foundation.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

// The ISQLDataReader interface provides a forward only, readonly
// iterator for reading relational table data.  A reference to an
// ISQLDataReader is returned from the SQLCommands ExecuteReader method.
// The initial position of the ISQLDataReader is prior to the first item.
// Therefore you must call ReadNext to begin accessing any data.
class [!output PREFIX]SQLDataReader: public FdoISQLDataReader
{
    friend class [!output PREFIX]SQLCommand;

private:
      [!output PREFIX]SQLDataReader( FdoIConnection *connection /*, [!output PREFIX]QueryResult *query */);
      [!output PREFIX]SQLDataReader(const [!output PREFIX]SQLDataReader &right);
      [!output PREFIX]SQLDataReader & operator=(const [!output PREFIX]SQLDataReader &right);

protected:
    virtual ~[!output PREFIX]SQLDataReader();
    virtual void Dispose() { delete this; }

  public:

    // Gets the number of columns in the result set.
    FdoInt32 GetColumnCount();

    // Gets the name of the column at the given ordinal position.
    virtual const wchar_t* GetColumnName(FdoInt32 index);

    // Gets the data type of the column with the specified name.
    virtual FdoDataType GetColumnType(const wchar_t* columnName);

    /// <summary>Gets the FDO property type of the column with the specified name. This is used
    //  to indicate if a given column is a geometric property or a data property. If the column is
    //  a FdoPropertyType_Data, then GetColumnType can be used to find the data type of the column.</summary>
    /// <param name="propertyName">Input the column name.</param>
    /// <returns>Returns the FDO property type of the column.</returns>
    virtual FdoPropertyType GetPropertyType(FdoString* columnName);

    // Gets the Boolean value of the specified column. No conversion is
    // performed, therefore the column must be of type Boolean or an
    // exception is thrown.
    virtual bool GetBoolean(const wchar_t* columnName);

    // Gets the Byte value of the specified column. No conversion is
    // performed, therefore the column must be of type Byte or an
    // exception is thrown.
    virtual FdoByte GetByte(const wchar_t* columnName);

    // Gets the DateTime value of the specified column. No conversion
    // is performed, therefore the column must be of type DateTime or
    // an exception is thrown.
    virtual FdoDateTime GetDateTime(const wchar_t* columnName);

    // Gets the Double floating point value of the specified column.
    // No conversion is performed, therefore the column must be of type
    // Double or an exception is thrown.
    virtual double GetDouble(const wchar_t* columnName);

    // Gets the Int16 value of the specified column. No conversion is
    // performed, therefore the column must be of type Int16 or an
    // exception is thrown.
    virtual FdoInt16 GetInt16(const wchar_t* columnName);

    // Gets the Int32 value of the specified column. No conversion is
    // performed, therefore the column must be of type Int32 or an
    // exception is thrown.
    virtual FdoInt32 GetInt32(const wchar_t* columnName);

    // Gets the Int64 value of the specified column. No conversion
    // is performed, therefore the column must be of type Int64 or an
    // exception is thrown.
    virtual FdoInt64 GetInt64(const wchar_t* columnName);

    // Gets the Single floating point value of the specified column.
    // No conversion is performed, therefore the column must be of type
    // Single or an exception is thrown.
    virtual float GetSingle(const wchar_t* columnName);

    // Gets the String value of the specified column. No conversion is
    // performed, therefore the column must be of type String or an
    // exception is thrown.
    virtual const wchar_t* GetString(const wchar_t* columnName);

    // Gets the LOB value of the specified column as a LOBValue.
    // No conversion is performed, therefore the column must be of
    // type LOB (BLOB/CLOB etc) or an exception is thrown.
    virtual FdoLOBValue* GetLOB(const wchar_t* columnName );

    // Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
    // FdoCLOBStreamReader etc. to allow reading in blocks of data.
    // Because no conversion is performed, the property must be FdoDataType_BLOB
    // or FdoDataType_CLOB etc. (a LOB type)
    // Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
    virtual FdoIStreamReader* GetLOBStreamReader(const wchar_t* columnName );

    // Returns true if the value of the specified column is null.
    virtual bool IsNull(const wchar_t* columnName);

    // Gets the Geometry value of the specified column as a byte array
    // in FGF format. No conversion is performed, therefore the column
    // must be of Geometric type or an exception is thrown.
    virtual FdoByteArray* GetGeometry(const wchar_t* columnName);

    // Advances the reader to the next item. The default position of the
    // reader is prior to the first item. Therefore you must call ReadNext
    // to begin accessing any data.
    virtual bool ReadNext();

    // Closes the ISQLDataReader object freeing any resources it may be holding.
    virtual void Close();

private:
        [!output PREFIX]Connection		*mFdoConnection;
};

#endif // [!output PREFIX]SQLREADER_H

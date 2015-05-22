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
 */

#ifndef [!output UPPER_PREFIX]READER_H
#define [!output UPPER_PREFIX]READER_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

template <class FDO_READER> class [!output PREFIX]Reader :
    public FDO_READER
{

public:
    [!output PREFIX]Reader ()
    {
    }

    virtual ~[!output PREFIX]Reader (void)
    {
    }

    virtual void Dispose ()
    {
        delete this;
    }

    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]Reader & operator= (const [!output PREFIX]Reader &right);

    //
    // FdoIFeatureReader interface
    //

    /// <summary>Gets the Boolean value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Boolean or an 
    /// exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the Boolean value.</returns> 
    virtual bool GetBoolean (const FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Boolean)));
    }

    /// <summary>Gets the byte value of the specified property. No conversion is 
    /// performed, thus the property must be FdoDataType_Byte or an 
    /// exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the byte value.</returns> 
    virtual FdoByte GetByte (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Byte)));
    }

    /// <summary> Gets the date and time value of the specified property. No conversion is 
    /// performed, thus the property must be FdoDataType_DateTime or an 
    /// exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the date and time value.</returns> 
    virtual FdoDateTime GetDateTime (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_DateTime)));
    }

    /// <summary>Gets the double-precision floating point value of the specified property. No
    /// conversion is performed, thus the property must be FdoDataType_Double
    /// or an exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the double floating point value</returns> 
    virtual double GetDouble (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Double)));
    }

    /// <summary>Gets the 16-bit integer value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Int16 or an exception
    /// is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the FdoInt16 value.</returns> 
    virtual FdoInt16 GetInt16 (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Int16)));
    }

    /// <summary>Gets the 32-bit integer value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Int32 or an exception
    /// is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the FdoInt32 value</returns> 
    virtual FdoInt32 GetInt32 (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Int32)));
    }

    /// <summary>Gets the 64-bit integer value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Int64 or an exception
    /// is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the FdoInt64 value.</returns> 
    virtual FdoInt64 GetInt64 (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Int64)));
    }

    /// <summary>Gets the Single floating point value of the specified property. No
    /// conversion is performed, thus the property must be FdoDataType_Single
    /// or an exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the single value</returns> 
    virtual float GetSingle (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_Single)));
    }

    /// <summary>Gets the string value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_String or an exception
    /// is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the string value</returns> 
    virtual FdoString* GetString (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_71_DATA_TYPE_NOT_SUPPORTED, "The data type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType_String)));
    }


    /// <summary>Gets a LOBValue reference. The LOB is fully read in and data available.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB or
    /// FdoDataType_CLOB etc. (a LOB type)
    /// <param name="propertyName">Input the property name.</param> 
    /// <returns>Returns the reference to LOBValue</returns> 
    virtual FdoLOBValue* GetLOB(FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_72_LOB_DATA_TYPE_NOT_SUPPORTED)));
    }

    /// <summary>Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
    /// FdoCLOBStreamReader etc. to allow reading in blocks of data.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB 
    /// or FdoDataType_CLOB etc. (a LOB type)
    /// Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
    /// <param name="propertyName">Input the property name.</param> 
    /// <returns>Returns a reference to a LOB stream reader</returns> 
    virtual FdoIStreamReader* GetLOBStreamReader(FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_72_LOB_DATA_TYPE_NOT_SUPPORTED)));
    }

    /// <summary>Returns true if the value of the specified property is null.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns true if the value is null.</returns> 
    virtual bool IsNull (FdoString* identifier)
    {
        return (true);
    }

    /// <summary>Gets the geometry value of the specified property as a byte array in 
    /// FGF format. Because no conversion is performed, the property must be
    /// of Geometric type; otherwise, an exception is thrown.</summary>
    /// <param name="identifier">Input the property name.</param> 
    /// <returns>Returns the byte array in FGF format.</returns> 
    virtual FdoByteArray* GetGeometry (FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_70_PROPERTY_TYPE_NOT_SUPPORTED, "The property type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoPropertyTypeToString (FdoPropertyType_GeometricProperty)));
    }

    /// <summary>Gets the geometry value of the specified property as a byte array in 
    /// FGF format. Because no conversion is performed, the property must be
    /// of Geometric type; otherwise, an exception is thrown. 
    /// This method is a language-specific performance optimization that returns a
    /// pointer to the array data, rather than to an object that encapsulates
    /// the array.  The array's memory area is only guaranteed to be valid
    /// until a call to ReadNext() or Close(), or the disposal of this reader
    /// object.</summary>
    /// <param name="propertyName">Input the property name.</param> 
    /// <param name="count">Output the number of bytes in the array.</param> 
    /// <returns>Returns a pointer to the byte array in FGF format.</returns> 
    virtual const FdoByte * GetGeometry(FdoString* propertyName, FdoInt32 * count)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_70_PROPERTY_TYPE_NOT_SUPPORTED, "The property type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoPropertyTypeToString (FdoPropertyType_GeometricProperty)));
    }

    /// <summary>Gets the raster object of the specified property.
    /// Because no conversion is performed, the property must be
    /// of Raster type; otherwise, an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param> 
    /// <returns>Returns the raster object.</returns> 
    virtual FdoIRaster* GetRaster(FdoString* identifier)
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_70_PROPERTY_TYPE_NOT_SUPPORTED, "The property type '%1$ls' is not supported by this provider.", FdoCommonMiscUtil::FdoPropertyTypeToString (FdoPropertyType_RasterProperty)));
    }

    /// <summary>Advances the reader to the next item and returns true if there is
    /// another object to read or false if reading is complete. The default
    /// position of the reader is prior to the first item. Thus you must
    /// call ReadNext to begin accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns> 
    virtual bool ReadNext ()
    {
        return (false);
    }

    /// <summary>Closes the Reader object, freeing any resources it may be holding.</summary>
    /// <returns>Returns nothing</returns> 
    virtual void Close ()
    {
    }

protected:
};

#endif // [!output UPPER_PREFIX]READER_H


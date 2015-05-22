/** \file	 SuperMapDataReader.h
*  \author	 Âí¿¡
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-12-10
*/

#ifndef __SUPERMAP_DATAREADER_H__
#define __SUPERMAP_DATAREADER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

#define   EXECUTE_METHOD( method ) {\
    return m_FeatureReader->method; \
    }

class SuperMapDataReader : public FdoIDataReader
{
public:
      SuperMapDataReader( SuperMapFeatureReader  *reader );
	  ~SuperMapDataReader(void);

      virtual void Dispose() 
	  { 
		  delete this; 
	  }
public:
    /// <summary>Gets the number of propertys in the result set.</summary>
    /// <returns>Returns the number of propertys.</returns>
    virtual FdoInt32 GetPropertyCount()
    {
        EXECUTE_METHOD(GetPropertyCount());
    }

    /// <summary>Gets the name of the property at the given ordinal position.</summary>
    /// <param name="index">Input the position of the property.</param>
    /// <returns>Returns the property name</returns>
    virtual FdoString* GetPropertyName(FdoInt32 index)
    {
        EXECUTE_METHOD(GetPropertyName( index ));
    }

    /// <summary>Gets the data type of the property with the specified name.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the type of the property.</returns>
    virtual FdoDataType GetDataType(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetDataType(propertyName));
    }

    /// <summary>Gets the FDO property type of a given property. This is used
    //  to indicate if a given property is a geometric property or a data property. If the property is
    //  a FdoPropertyType_Data, then GetDataType can be used to to find the data type of the property.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the FDO property type.</returns>
    virtual FdoPropertyType GetPropertyType(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetPropertyType(propertyName));
    }

    /// <summary>Gets the Boolean value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Boolean or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the Boolean value</returns>
    virtual bool GetBoolean(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetBoolean(propertyName));
    }

    /// <summary>Gets the byte value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Byte or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the byte value.</returns>
    virtual FdoByte GetByte(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetByte(propertyName));
    }

    /// <summary>Gets the date time value of the specified property. No conversion
    /// is performed, thus the property must be FdoDataType_DateTime or
    /// an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the date and time value.</returns>
    virtual FdoDateTime GetDateTime(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetDateTime(propertyName));
    }

    /// <summary>Gets the double-precision floating point value of the specified property.
    /// No conversion is performed, thus the property must be of type
    /// Double or an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the double value.</returns>
    virtual double GetDouble(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetDouble(propertyName));
    }

    /// <summary>Gets the signed 16-bit integer value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Int16 or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the FdoInt16 value.</returns>
    virtual FdoInt16 GetInt16(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetInt16(propertyName));
    }

    /// <summary>Gets the signed 32-bit integer value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_Int32 or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the FdoInt32 value.</returns>
    virtual FdoInt32 GetInt32(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetInt32(propertyName));
    }

    /// <summary>Gets the signed 64-bit integer value of the specified property. No conversion
    /// is performed, thus the property must be FdoDataType_Int64 or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the FdoInt64 value.</returns>
    virtual FdoInt64 GetInt64(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetInt64(propertyName));
    }

    /// <summary>Gets the single-precision floating point value of the specified property.
    /// No conversion is performed, thus the property must be FdoDataType_Single
    /// or an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the single value</returns>
    virtual float GetSingle(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetSingle(propertyName));
    }

    /// <summary>Gets the string value of the specified property. No conversion is
    /// performed, thus the property must be FdoDataType_String or an
    /// exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the string value.</returns>
    virtual FdoString* GetString(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetString(propertyName));
    }

    /// <summary>Gets a LOBValue reference. The LOB is fully read in and data available.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB or
    /// FdoDataType_CLOB etc. (a LOB type)
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the reference to LOBValue</returns>
    virtual FdoLOBValue* GetLOB(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetLOB(propertyName));
    }

    /// <summary>Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
    /// FdoCLOBStreamReader etc. to allow reading in blocks of data.
    /// Because no conversion is performed, the property must be FdoDataType_BLOB
    /// or FdoDataType_CLOB etc. (a LOB type)
    /// Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns a reference to a LOB stream reader</returns>
    virtual FdoIStreamReader* GetLOBStreamReader(const wchar_t* propertyName )
    {
        EXECUTE_METHOD(GetLOBStreamReader(propertyName));
    }

    /// <summary>Returns true if the value of the specified property is null.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns true if the value is null.</returns>
    virtual bool IsNull(FdoString* propertyName)
    {
        EXECUTE_METHOD(IsNull(propertyName));
    }

    /// <summary>Gets the geometry value of the specified property as a byte array
    /// in FGF format. No conversion is performed, thus the property
    /// must be of Geometric type or an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the FGF byte array value.</returns>
    virtual FdoByteArray* GetGeometry(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetGeometry(propertyName));
    }

    /// <summary>Gets the raster object of the specified property.
    /// Because no conversion is performed, the property must be
    /// of Raster type; otherwise, an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param>
    /// <returns>Returns the raster object.</returns>
    virtual FdoIRaster* GetRaster(FdoString* propertyName)
    {
        EXECUTE_METHOD(GetRaster(propertyName));
    }

    /// <summary>Advances the reader to the next item. The default position of the
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns>
    virtual bool ReadNext()
    {
        EXECUTE_METHOD(ReadNext());
    }

    /// <summary>Closes the FdoIDataReader object, freeing any resources it may be holding.</summary>
    /// <returns>Returns nothing</returns>
    virtual void Close()
    {
        if( NULL != m_FeatureReader )
		{
            m_FeatureReader->Close();
		}
    }

private:

    FdoPtr<SuperMapFeatureReader> m_FeatureReader;
};

#endif // __SUPERMAP_DATAREADER_H__
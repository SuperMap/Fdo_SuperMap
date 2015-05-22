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

#ifndef FDOCOMMONREADER___H
#define FDOCOMMONREADER___H	1

#ifdef _WIN32
#pragma once
#endif

#pragma message ("TODO: FdoCommonReader support for LOBs, raster and association properties")


// The FdoCommonReader class implements some of the common reader functionality found in all providers.
// In particular, it implements a "one row cache" mechanism that caches all values in a row, to prevent
// re-fetching the same values from the datastore on each call.
//
// This class can be used to implement any of the following FDO readers,
// by setting the BASECLASS template argument to one of the following FDO readers:
//    FdoIFeatureReader:  "items" correspond to properties (computed or not)
//    FdoIDataReader:     "items" correspond to properties (computed or not)
//    FdoISQLDataReader:  "items" correspond to columns
template <typename BASECLASS>
class FdoCommonReader : public BASECLASS
{
protected:
    /// common API methods between FdoIFeatureReader, FdoIDataReader, FdoISQLDataReader;
    /// These typically do not need to be overridden, unless
    /// a type is unsupported and thus an exception needs to be thrown:
    virtual bool                GetBoolean( const wchar_t *itemName );
    virtual FdoByte             GetByte( const wchar_t *itemName );
    virtual double              GetDouble(const wchar_t* itemName);
    virtual short               GetInt16( const wchar_t *itemName );
    virtual int                 GetInt32( const wchar_t *itemName );
    virtual FdoInt64            GetInt64( const wchar_t *itemName );
    virtual float               GetSingle( const wchar_t *itemName );
    virtual const wchar_t*      GetString( FdoString* itemName );
    virtual FdoDateTime         GetDateTime(FdoString* itemName );
    virtual FdoLOBValue*        GetLOB(FdoString* itemName);
    virtual FdoIStreamReader *  GetLOBStreamReader(FdoString* itemName);
    virtual FdoByteArray*       GetGeometry(FdoString* itemName);
    virtual const FdoByte*      GetGeometry(FdoString* itemName, FdoInt32 *);
    virtual FdoIRaster*         GetRaster(FdoString* itemName);
    virtual bool                IsNull(FdoString* itemName);

    // API methods for FdoIDataReader;
    // These do not need to be overriden since they rely on the GetItem*() methods which must be overridden:
    virtual FdoInt32 GetPropertyCount();
    virtual FdoString* GetPropertyName(FdoInt32 index);
    virtual FdoDataType GetDataType(FdoString* propertyName);
    virtual FdoPropertyType GetPropertyType(FdoString* propertyName);

    /// Retrieve information about metadata;
    /// An item is either a plain or computed property (in the case of FdoIFeatureReader and FdoIDataReader)
    /// or a column (in the case of FdoISqlDataReader).
    /// These methods need to be overridden by each subclass:
    virtual FdoInt32        GetItemCount(void) = 0;
    virtual FdoString*      GetItemName(FdoInt32 i) = 0;            // throw exception if index is invalid
    virtual FdoInt32        GetItemIndex(FdoString* itemName) = 0;  // throw exception if name is invalid
    virtual FdoPropertyType GetItemType(FdoInt32 i) = 0;            // throw exception if index is invalid
    virtual FdoDataType     GetItemDataType(FdoInt32 i) = 0;        // throw exception if index is invalid

    /// Retrieve data values; these are guaranteed to only be called once per row of data.
    /// These methods need to be overridden by each subclass, except for types not supported:
    virtual void GetBooleanForCache( FdoIdentifier *itemName, bool *bValue, bool *bIsNull);
    virtual void GetByteForCache( FdoIdentifier *itemName, FdoByte *byteValue, bool *bIsNull);
    virtual void GetDateTimeForCache(FdoIdentifier *itemName, FdoDateTime *dateTimeValue, bool *bIsNull );
    virtual void GetDoubleForCache(FdoIdentifier *itemName, double *doubleValue, bool *bIsNull );
    virtual void GetDecimalForCache(FdoIdentifier *itemName, double *decimalValue, bool *bIsNull );
    virtual void GetInt16ForCache( FdoIdentifier *itemName, FdoInt16 *int16Value, bool *bIsNull );
    virtual void GetInt32ForCache( FdoIdentifier *itemName, FdoInt32 *int32Value, bool *bIsNull );
    virtual void GetInt64ForCache( FdoIdentifier *itemName, FdoInt64 *int64Value, bool *bIsNull );
    virtual void GetSingleForCache( FdoIdentifier *itemName, float *singlevalue,   bool *bIsNull );
    virtual void GetStringForCache( FdoIdentifier *itemName, FdoStringP *stringValue, bool *bIsNull );
    virtual void GetGeometryForCache(FdoIdentifier *itemName, FdoByteArray **byteArray, bool *bIsNull);


    /// Retrieve information about the row of items:
    /// These methods need to be overridden by each subclass:
    virtual bool ReaderHasData(void) = 0;  // return false IFF before first row or after last row

    /// Populate the one-row-cache;
    /// typically does not need to be overriden;
    /// Subclass must call PopulatePropertyValueCache from ReadNext when a new row of data is available:
    void PopulatePropertyValueCache();

private:
    /// Create/verify the one-row-cache;
    /// internal methods, cannot be overriden:
    void CreatePropertyValueCache();
    FdoPropertyValue* GetPropertValue(FdoString *itemName, FdoPropertyType propType, FdoDataType dataType);
    void CheckItemName(FdoString *itemName);

private:
    /// One-row-cache member variables:
    FdoPtr<FdoPropertyValueCollection>  mPropertyValueCache; // Values of all properties in current row.
};


template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::CreatePropertyValueCache()
{
    if (mPropertyValueCache == NULL)
    {
        mPropertyValueCache = FdoPropertyValueCollection::Create();
        VALIDATE_ALLOCATION(mPropertyValueCache);
        FdoPtr<FdoPropertyValue> newPropValue;
        FdoPtr<FdoValueExpression> newValueExpr;
        FdoPropertiesP properties;

    /// Iterate all items (properties or columns):
        FdoInt32 count = GetItemCount();
        for (int i=0; i<count; i++)
        {
    /// Get FDO property name and type:
            FdoString * itemName = GetItemName(i);
            FdoPropertyType propertyType = GetItemType(i);

    /// Create one ValueExpression according to the property type (and data type, if applicable):
            switch (propertyType)
            {
            case FdoPropertyType_DataProperty:
                {
                    FdoDataType dataPropType = GetItemDataType(i);

                    switch (dataPropType)
                    {
                    case FdoDataType_Boolean:  newValueExpr = FdoBooleanValue::Create();  break;
                    case FdoDataType_Byte:     newValueExpr = FdoByteValue::Create();     break;
                    case FdoDataType_DateTime: newValueExpr = FdoDateTimeValue::Create(); break;
                    case FdoDataType_Decimal:  newValueExpr = FdoDecimalValue::Create();  break;
                    case FdoDataType_Double:   newValueExpr = FdoDoubleValue::Create();   break;
                    case FdoDataType_Int16:    newValueExpr = FdoInt16Value::Create();    break;
                    case FdoDataType_Int32:    newValueExpr = FdoInt32Value::Create();    break;
                    case FdoDataType_Int64:    newValueExpr = FdoInt64Value::Create();    break;
                    case FdoDataType_Single:   newValueExpr = FdoSingleValue::Create();   break;
                    case FdoDataType_String:   newValueExpr = FdoStringValue::Create();   break;
                    default:
                        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED),
                            FdoCommonMiscUtil::FdoDataTypeToString(dataPropType)));
                    };
                    break;
                }
            break;

            case FdoPropertyType_GeometricProperty:
                newValueExpr = FdoGeometryValue::Create();
            break;

            case FdoPropertyType_ObjectProperty:
                ; // do nothing, we don't cache object properties
            break;

            case FdoPropertyType_RasterProperty:
                ; // TODO
            break;

            case FdoPropertyType_AssociationProperty:
                ; // TODO
            break;

            default:
                throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
            }
            VALIDATE_POINTER(newValueExpr);

            newPropValue = FdoPropertyValue::Create(itemName, newValueExpr);
            VALIDATE_POINTER(newPropValue);

            mPropertyValueCache->Add(newPropValue);
        }
    }
}


template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::PopulatePropertyValueCache()
{
    CreatePropertyValueCache();

    FdoInt32 count = mPropertyValueCache->GetCount();

    for (int i = 0;  i < count;  i++)
    {
        FdoPtr<FdoPropertyValue> propValue = mPropertyValueCache->GetItem(i);
        VALIDATE_POINTER(propValue);
        FdoPtr<FdoIdentifier> id = propValue->GetName();
        VALIDATE_POINTER(id);
        FdoString * name = id->GetName();
        FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
        VALIDATE_POINTER(valueExpr);

    /// Get FDO property type:
        FdoPropertyType propertyType = GetItemType(i);

    /// Populate this FDO ValueExpression:
        bool bIsNull = false;
        switch (propertyType)
        {
        case FdoPropertyType_DataProperty:
            {
                FdoDataType dataPropType = GetItemDataType(i);
                switch (dataPropType)
                {
                case FdoDataType_Boolean:
                {
                    bool boolValue = false;
                    GetBooleanForCache(id, &boolValue, &bIsNull);

                    FdoBooleanValue * typedValue = static_cast<FdoBooleanValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetBoolean(boolValue);
                }
                break;

                case FdoDataType_Byte:
                {
                    FdoByte byteValue;
                    GetByteForCache(id, &byteValue, &bIsNull);

                    FdoByteValue * typedValue = static_cast<FdoByteValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetByte(byteValue);
                }
                break;

                case FdoDataType_DateTime:
                {
                    FdoDateTime dateTimeValue;
                    GetDateTimeForCache(id, &dateTimeValue, &bIsNull);

                    FdoDateTimeValue * typedValue = static_cast<FdoDateTimeValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetDateTime(dateTimeValue);
                }
                break;

                case FdoDataType_Decimal:
                {
                    double decimalValue;
                    GetDecimalForCache(id, &decimalValue, &bIsNull);

                    FdoDecimalValue * typedValue = static_cast<FdoDecimalValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetDecimal(decimalValue);
                }
                break;

                case FdoDataType_Double:
                {
                    double doubleValue;
                    GetDoubleForCache(id, &doubleValue, &bIsNull);

                    FdoDoubleValue * typedValue = static_cast<FdoDoubleValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetDouble(doubleValue);
                }
                break;

                case FdoDataType_Int16:
                {
                    FdoInt16 int16Value;
                    GetInt16ForCache(id, &int16Value, &bIsNull);

                    FdoInt16Value * typedValue = static_cast<FdoInt16Value*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetInt16(int16Value);
                }
                break;

                case FdoDataType_Int32:
                {
                    FdoInt32 int32Value;
                    GetInt32ForCache(id, &int32Value, &bIsNull);

                    FdoInt32Value * typedValue = static_cast<FdoInt32Value*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetInt32(int32Value);
                }
                break;

                case FdoDataType_Int64:
                {
                    FdoInt64 int64Value;
                    GetInt64ForCache(id, &int64Value, &bIsNull);

                    FdoInt64Value * typedValue = static_cast<FdoInt64Value*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetInt64(int64Value);
                }
                break;

                case FdoDataType_Single:
                {
                    float singleValue;
                    GetSingleForCache(id, &singleValue, &bIsNull);

                    FdoSingleValue * typedValue = static_cast<FdoSingleValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetSingle(singleValue);
                }
                break;

                case FdoDataType_String:
                {
                    FdoStringP stringValue;
                    GetStringForCache(id, &stringValue, &bIsNull);

                    FdoStringValue * typedValue = static_cast<FdoStringValue*>(valueExpr.p);
                    VALIDATE_POINTER(typedValue);

                    if (bIsNull)
                        typedValue->SetNull();
                    else
                        typedValue->SetString(stringValue);   // This copies "stringValue", so "stringValue" will safely be freed.
                }
                break;

                default:
                    throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
                };
            }
        break;

        case FdoPropertyType_GeometricProperty:
        {
            FdoPtr<FdoByteArray> byteArrayValue;
            GetGeometryForCache(id, &(byteArrayValue.p), &bIsNull);

            FdoGeometryValue * typedValue = static_cast<FdoGeometryValue*>(valueExpr.p);
            VALIDATE_POINTER(typedValue);

            if (bIsNull || byteArrayValue == NULL)
                typedValue->SetNullValue();
            else
                typedValue->SetGeometry(byteArrayValue); // This does not copy "byteArray" (just AddRef's it).
        }
        break;

        case FdoPropertyType_ObjectProperty:
            ; // do nothing, we don't cache object properties
        break;

        case FdoPropertyType_RasterProperty:
            ; // TODO
        break;

        case FdoPropertyType_AssociationProperty:
            ; // TODO
        break;

        default:
            throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
        }
    }
}



template <typename BASECLASS>
bool FdoCommonReader<BASECLASS>::GetBoolean( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Boolean);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoBooleanValue * typedValue = (FdoBooleanValue *)(valueExpr.p);

    bool returnValue = typedValue->GetBoolean();

    return ( returnValue );
}

template <typename BASECLASS>
FdoByte FdoCommonReader<BASECLASS>::GetByte( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Byte);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoByteValue * typedValue = (FdoByteValue *)(valueExpr.p);

    FdoByte returnValue = typedValue->GetByte();

    return ( returnValue );
}

template <typename BASECLASS>
FdoDateTime FdoCommonReader<BASECLASS>::GetDateTime( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_DateTime);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoDateTimeValue * typedValue = (FdoDateTimeValue *)(valueExpr.p);

    FdoDateTime returnValue = typedValue->GetDateTime();

    return ( returnValue );
}

template <typename BASECLASS>
double FdoCommonReader<BASECLASS>::GetDouble( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Double);

    /// NOTE: we could be fetching either a Decimal or a Double here:
    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoDecimalValue * decimalValue = dynamic_cast<FdoDecimalValue*>(valueExpr.p);
    FdoDoubleValue  * doubleValue  = dynamic_cast<FdoDoubleValue*>(valueExpr.p);

    double returnValue = 0.0;
    if (NULL != decimalValue)
        returnValue = decimalValue->GetDecimal();
    else
        returnValue = doubleValue->GetDouble();

    return ( returnValue );
}

template <typename BASECLASS>
FdoInt16 FdoCommonReader<BASECLASS>::GetInt16( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Int16);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoInt16Value * typedValue = (FdoInt16Value *)(valueExpr.p);

    FdoInt16 returnValue = typedValue->GetInt16();

    return ( returnValue );
}

template <typename BASECLASS>
FdoInt32 FdoCommonReader<BASECLASS>::GetInt32( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Int32);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoInt32Value * typedValue = (FdoInt32Value *)(valueExpr.p);

    FdoInt32 returnValue = typedValue->GetInt32();

    return ( returnValue );
}

template <typename BASECLASS>
FdoInt64 FdoCommonReader<BASECLASS>::GetInt64( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Int64);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoInt64Value * typedValue = (FdoInt64Value *)(valueExpr.p);

    FdoInt64 returnValue = typedValue->GetInt64();

    return ( returnValue );
}

template <typename BASECLASS>
float FdoCommonReader<BASECLASS>::GetSingle( FdoString *itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_Single);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoSingleValue * typedValue = (FdoSingleValue *)(valueExpr.p);

    float returnValue = typedValue->GetSingle();

    return ( returnValue );
}

template <typename BASECLASS>
FdoString * FdoCommonReader<BASECLASS>::GetString( FdoString * itemName )
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_DataProperty, FdoDataType_String);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoStringValue * typedValue = (FdoStringValue *)(valueExpr.p);

    FdoString * returnValue = typedValue->GetString();

    return ( returnValue );
}

template <typename BASECLASS>
FdoByteArray * FdoCommonReader<BASECLASS>::GetGeometry(FdoString* itemName)
{
    FdoPtr<FdoPropertyValue> propValue = GetPropertValue(itemName, FdoPropertyType_GeometricProperty, (FdoDataType)-1);

    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);
    FdoGeometryValue * typedValue = (FdoGeometryValue *)(valueExpr.p);

    FdoByteArray * returnValue = typedValue->GetGeometry();

    return ( returnValue );
}


template <typename BASECLASS>
const FdoByte * FdoCommonReader<BASECLASS>::GetGeometry(FdoString * itemName, FdoInt32 * count)
{
    CheckItemName(itemName);

    FdoByte *               data = NULL;
    FdoPtr<FdoByteArray>    ba = this->GetGeometry(itemName);
    VALIDATE_POINTER(ba);

    data = ba->GetData();
    *count = ba->GetCount();

    return data;
}


template <typename BASECLASS>
FdoIRaster * FdoCommonReader<BASECLASS>::GetRaster(FdoString *itemName)
{
    CheckItemName(itemName);

    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
}


template <typename BASECLASS>
FdoLOBValue* FdoCommonReader<BASECLASS>::GetLOB(FdoString* itemName)
{
    CheckItemName(itemName);

    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
}


template <typename BASECLASS>
FdoIStreamReader * FdoCommonReader<BASECLASS>::GetLOBStreamReader(FdoString *itemName)
{
    CheckItemName(itemName);

    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_3_NOTIMPLEMENTED)));
}


template <typename BASECLASS>
bool FdoCommonReader<BASECLASS>::IsNull( FdoString *itemName )
{
    bool    value = false;

    CheckItemName(itemName);

    if( ! ReaderHasData() ) 
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_58_READERHASNODATA)));

    FdoPtr<FdoPropertyValue> propValue = mPropertyValueCache->GetItem(itemName);
    VALIDATE_POINTER(propValue);
    FdoPtr<FdoValueExpression> valueExpr = propValue->GetValue();
    VALIDATE_POINTER(valueExpr);

    FdoPropertyType propertyType = GetItemType(GetItemIndex(itemName));
    switch (propertyType)
    {
    case FdoPropertyType_DataProperty:
        value = ((FdoDataValue *)(valueExpr.p))->IsNull();
        break;
    case FdoPropertyType_GeometricProperty:
        value = ((FdoGeometryValue *)(valueExpr.p))->IsNull();
        break;
    case FdoPropertyType_ObjectProperty:
        ; // do nothing, we don't cache object properties
    break;
    case FdoPropertyType_RasterProperty:
        ; // TODO
    break;
    case FdoPropertyType_AssociationProperty:
        ; // TODO
    break;
    default:
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
    }

    return value;
}


template <typename BASECLASS>
FdoPropertyValue* FdoCommonReader<BASECLASS>::GetPropertValue(
    FdoString *itemName,
    FdoPropertyType propType,
    FdoDataType propDataType)
{
    CheckItemName(itemName);

    /// Verify that we are not past the last row of data or before the first row:
    if( ! ReaderHasData() ) 
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_58_READERHASNODATA)));

    FdoPtr<FdoPropertyValue> propValue = mPropertyValueCache->GetItem(itemName);
    VALIDATE_POINTER(propValue);

    /// Verify that this property is of the expected type:
    FdoInt32 itemIndex = GetItemIndex(itemName);
    FdoPropertyType propertyType = GetItemType(itemIndex);
    if (propertyType != propType)
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    /// If this is a data property, verify that it of the correct data type:
    if (propertyType == FdoPropertyType_DataProperty)
    {
    /// NOTE: we are OK if the user is fetching a Double but the property type is a Decimal (due to API limitations)
        FdoDataType actualPropDataType = GetItemDataType(itemIndex);
        if ( (propDataType != actualPropDataType) &&
             ((propDataType!=FdoDataType_Double) || ((propDataType==FdoDataType_Double) && (actualPropDataType!=FdoDataType_Decimal))) )
            throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    /// Verify that the given property value is not NULL:
    if (IsNull(itemName))
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_59_CANNOTFETCHNULLVALUE)));

    return FDO_SAFE_ADDREF(propValue.p);
}


template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::CheckItemName(FdoString *itemName)
{
    long lDummyIndex = GetItemIndex(itemName);  // should throw exeption if the name is invalid
}


template <typename BASECLASS>
FdoInt32 FdoCommonReader<BASECLASS>::GetPropertyCount()
{
    return GetItemCount();
}

template <typename BASECLASS>
FdoString* FdoCommonReader<BASECLASS>::GetPropertyName(FdoInt32 index)
{
    return GetItemName(index);
}

template <typename BASECLASS>
FdoDataType FdoCommonReader<BASECLASS>::GetDataType(FdoString* propertyName)
{
    return GetItemDataType(GetItemIndex(propertyName));
}

template <typename BASECLASS>
FdoPropertyType FdoCommonReader<BASECLASS>::GetPropertyType(FdoString* propertyName)
{
    return GetItemType(GetItemIndex(propertyName));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetBooleanForCache( FdoIdentifier *itemName, bool *bValue, bool *bIsNull)
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Boolean)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetByteForCache( FdoIdentifier *itemName, FdoByte *byteValue, bool *bIsNull)
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Byte)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetDateTimeForCache(FdoIdentifier *itemName, FdoDateTime *dateTimeValue, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_DateTime)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetDoubleForCache(FdoIdentifier *itemName, double *doubleValue, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Double)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetDecimalForCache(FdoIdentifier *itemName, double *decimalValue, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Decimal)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetInt16ForCache( FdoIdentifier *itemName, FdoInt16 *int16Value, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Int16)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetInt32ForCache( FdoIdentifier *itemName, FdoInt32 *int32Value, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Int32)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetInt64ForCache( FdoIdentifier *itemName, FdoInt64 *int64Value, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Int64)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetSingleForCache( FdoIdentifier *itemName, float *singlevalue,   bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Single)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetStringForCache( FdoIdentifier *itemName, FdoStringP *stringValue, bool *bIsNull )
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_String)));
}

template <typename BASECLASS>
void FdoCommonReader<BASECLASS>::GetGeometryForCache(FdoIdentifier *itemName, FdoByteArray **byteArray, bool *bIsNull)
{
    throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_70_PROPERTY_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoPropertyTypeToString(FdoPropertyType_GeometricProperty)));
}

#endif // FDOCOMMONREADER___H



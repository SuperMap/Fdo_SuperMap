// 
//  
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//  
#include "stdafx.h"
#include <FdoCommonBinaryWriter.h>
#include <FdoCommonStringUtil.h>
#include <FdoCommonMiscUtil.h>
#include <Common/StringP.h>

FdoCommonBinaryWriter::FdoCommonBinaryWriter(int initialLen)
{
    m_len = initialLen;

    _ASSERT(m_len > 0);

    m_data = new unsigned char[m_len];
    m_pos = 0;

    m_strCacheLen = 0;
    m_strCache = NULL;
}

FdoCommonBinaryWriter::~FdoCommonBinaryWriter()
{
    delete [] m_data;

    if (m_strCache)
        delete [] m_strCache;
}


void FdoCommonBinaryWriter::Reset()
{
    m_pos = 0;
}


unsigned char* FdoCommonBinaryWriter::GetData(bool bDetach)
{
    unsigned char* ret = m_data;
    if (bDetach)  // relinquish ownership of the data array to the caller; this is useful for improving performance
    {
        m_data = NULL;
        m_len = 0;
        m_pos = 0;
    }
    return ret;
}

int FdoCommonBinaryWriter::GetDataLen()
{
    return m_pos;
}

int FdoCommonBinaryWriter::GetPosition()
{
    return m_pos;
}

void FdoCommonBinaryWriter::WriteDouble(double d)
{
    CheckResize(sizeof(double));
    //TODO: endian
    *(double*)(m_data+m_pos) = d;
    m_pos += sizeof(double);
}


void FdoCommonBinaryWriter::WriteSingle(float f)
{
    CheckResize(sizeof(float));
    //TODO: endian
    *(float*)(m_data+m_pos) = f;
    m_pos += sizeof(float);
}

void FdoCommonBinaryWriter::WriteInt32(int i)
{
    CheckResize(sizeof(int));
    //TODO: endian
    *(int*)(m_data+m_pos) = i;
    m_pos += sizeof(int);
}

void FdoCommonBinaryWriter::WriteUInt32(unsigned i)
{
    CheckResize(sizeof(unsigned));
    //TODO: endian
    *(unsigned*)(m_data+m_pos) = i;
    m_pos += sizeof(unsigned);
}

void FdoCommonBinaryWriter::WriteInt16(short s)
{
    CheckResize(sizeof(short));
    //TODO: endian
    *(short*)(m_data+m_pos) = s;
    m_pos += sizeof(short);
}

void FdoCommonBinaryWriter::WriteUInt16(unsigned short us)
{
    CheckResize(sizeof(unsigned short));
    //TODO: endian
    *(unsigned short*)(m_data+m_pos) = us;
    m_pos += sizeof(unsigned short);
}

void FdoCommonBinaryWriter::WriteInt64(FdoInt64 ll)
{
    CheckResize(sizeof(FdoInt64));
    //TODO: endian
    *(FdoInt64*)(m_data+m_pos) = ll;
    m_pos += sizeof(FdoInt64);
}

void FdoCommonBinaryWriter::WriteByte(unsigned char b)
{
    CheckResize(sizeof(unsigned char));
    *(m_data+m_pos) = b;
    m_pos += sizeof(unsigned char);
}

void FdoCommonBinaryWriter::WriteChar(char c)
{
    CheckResize(sizeof(char));
    *(m_data+m_pos) = c;
    m_pos += sizeof(char);
}

void FdoCommonBinaryWriter::WriteString(const wchar_t* src)
{
    unsigned srcLen = 0;
    
    //handle empty string
    if (src == NULL || (srcLen = (unsigned)wcslen(src)) == 0 )
    {
        WriteInt32(0);
        return;
    }

    unsigned maxmbslen = srcLen * 4 + 1;

    if (m_strCacheLen < maxmbslen)
    {
        if (m_strCache)
            delete [] m_strCache;

        m_strCacheLen = maxmbslen;
        m_strCache = new char[maxmbslen];
    }

    int actualLen = FdoStringP::Utf8FromUnicode( src, srcLen, m_strCache, m_strCacheLen );

    _ASSERT(actualLen >= 0);
    actualLen += 1; //add 1 for null character

    CheckResize(actualLen + sizeof(unsigned));

    //write string length (number of bytes, not characters!!!)
    WriteUInt32(actualLen);
    
    //write actual string content to the output
    memcpy(m_data + m_pos, m_strCache, actualLen);
    m_pos += actualLen;

}


void FdoCommonBinaryWriter::WriteRawString(const wchar_t* src)
{
    int srcLen = 0;
    
    //handle null string
    if (src == NULL)
    {
        return;
    }

    //handle empty string -> write trailing 0
    //NOTE: NOT the same as NULL.
    if ((srcLen = (unsigned)wcslen(src)) == 0)
    {
        WriteByte(0);
        return;
    }

    unsigned maxmbslen = srcLen * 4 + 1;

    if (m_strCacheLen < maxmbslen)
    {
        if (m_strCache)
            delete [] m_strCache;

        m_strCacheLen = maxmbslen;
        m_strCache = new char[maxmbslen];
    }

    int actualLen = FdoStringP::Utf8FromUnicode( src, srcLen, m_strCache, m_strCacheLen );

    _ASSERT(actualLen >= 0);
	
    actualLen += 1; //add 1 for null character
    
    CheckResize(actualLen + sizeof(int));

    //RAW WRITE - do not write length, we know how to compute it from the
    //property offsets at the beginning of the data record
    /*
    //write string length (number of bytes, not characters!!!)
    WriteInt32(actualLen);
    */
    
    //write actual string content to the output
    memcpy(m_data + m_pos, m_strCache, actualLen);
    m_pos += actualLen;
}



//checks if the data write buffer has enough space and resizes it if needed
void FdoCommonBinaryWriter::CheckResize(unsigned len)
{
    if (m_pos + len < m_len)
        return;

    int newlen = 0;
    if (len > m_len)
        newlen = m_len + len;
    else 
        newlen = m_len*2;

    unsigned char* ndata = new unsigned char[newlen];
    memcpy(ndata, m_data, m_len);
    m_len = newlen;
    delete [] m_data;
    m_data = ndata;
}

//writes a byte array 
void FdoCommonBinaryWriter::WriteBytes(unsigned char* buf, int len)
{
    CheckResize(len);
    
    memcpy(m_data + m_pos, buf, len);
    m_pos += len;
}

//serializes a FdoDateTime
void FdoCommonBinaryWriter::WriteDateTime(FdoDateTime dt)
{
    WriteInt16(dt.year);
    WriteChar(dt.month);
    WriteChar(dt.day);
    WriteChar(dt.hour);
    WriteChar(dt.minute);
    WriteSingle(dt.seconds);
}





void FdoCommonBinaryWriter::WritePropertyValue(FdoPropertyDefinition* pd, FdoPropertyValue* pv)
{
    FdoDataPropertyDefinition* dpd = NULL;
    FdoPtr<FdoValueExpression> expression;

    if (pd->GetPropertyType() == FdoPropertyType_DataProperty)
        dpd = (FdoDataPropertyDefinition*)pd;

    if (NULL != pv)
        expression = pv->GetValue();

    if ((pv == NULL) || (expression == NULL))
    {
        //if the property value is NULL, do not write anything to the data record
        //the default value will be used if later the user asks for the value
        //of this property
        //TODO: should we write the default property value instead?
        return;
    }

    if (dpd)
    {
        switch (dpd->GetDataType())
        {
        case FdoDataType_Boolean :
                WriteByte(((FdoBooleanValue*)(expression.p))->GetBoolean() ? 1 : 0);
                break;

        case FdoDataType_Byte : 
                WriteByte(((FdoByteValue*)(expression.p))->GetByte());
                break;

        case FdoDataType_DateTime : 
                WriteDateTime(((FdoDateTimeValue*)(expression.p))->GetDateTime());
                break;

        case FdoDataType_Decimal :
                WriteDouble(((FdoDecimalValue*)(expression.p))->GetDecimal());
                break;

        case FdoDataType_Double :
                WriteDouble(((FdoDoubleValue*)(expression.p))->GetDouble());
                break;

        case FdoDataType_Int16 : 
                WriteInt16(((FdoInt16Value*)(expression.p))->GetInt16());
                break;

        case FdoDataType_Int32 : 
                WriteInt32(((FdoInt32Value*)(expression.p))->GetInt32());
                break;

        case FdoDataType_Int64 : 
                WriteInt64(((FdoInt64Value*)(expression.p))->GetInt64());
                break;

        case FdoDataType_Single : 
                WriteSingle(((FdoSingleValue*)(expression.p))->GetSingle());
                break;

        case FdoDataType_String : 
                WriteRawString(((FdoStringValue*)(expression.p))->GetString());
                break;

        default: 
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED),
                FdoCommonMiscUtil::FdoDataTypeToString(dpd->GetDataType())));
        }
    }
    else
    {
        //we have a geometric property
        FdoPtr<FdoByteArray> byteArray = ((FdoGeometryValue*)(expression.p))->GetGeometry();

        if (!byteArray)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_60_NULL_POINTER)));

        //Note we do not need to write the length of a byte array since we know it
        //by subtracting the offsets into property values in the data record
        WriteBytes(byteArray->GetData(), byteArray->GetCount());
    }
}


void FdoCommonBinaryWriter::WritePropertyValue(FdoPropertyDefinition* pd, FdoIReader* reader)
{
    VALIDATE_ARGUMENT(pd);

    FdoDataType dataType = (FdoDataType)0;
    if (pd->GetPropertyType() == FdoPropertyType_DataProperty)
        dataType = ((FdoDataPropertyDefinition*)pd)->GetDataType();

    FdoPtr<FdoPropertyValue> propValue = FdoCommonMiscUtil::GetPropertyValue(pd->GetName(), pd->GetPropertyType(), dataType, reader);

    WritePropertyValue(pd, propValue);
}



//serializes a collection of feature properties into a byte array
void FdoCommonBinaryWriter::WritePropertyValues(FdoClassDefinition* classDef, FdoCommonPropertyIndex* pi, FdoPropertyValueCollection* pvc)
{
    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> bpdc = classDef->GetBaseProperties();
    FdoPtr<FdoPropertyDefinitionCollection> pdc = classDef->GetProperties();

    //find number of properties we will store into the data record
    //we will use this number to save an offset into the data records for each property
    //at the beginning of the data record
    int numProps = bpdc->GetCount() + pdc->GetCount();

    //write feature class ID
    WriteUInt16((FCID_STORAGE)pi->GetFCID());

    //now generate the data value -- write all property values, except for the ones
    //we already wrote to the key -- we have to check if each one is in the ID prop
    //collection

    //reserve space for offsets into property values in data record
    for (int i=0; i<numProps; i++)
        WriteInt32(0);

    // serialize all properties:
    for (int i=0; i<numProps; i++)
    {
        FdoCommonPropertyStub* propStub = pi->GetPropInfo(i);

        // Find the related property definition:
        FdoPtr<FdoPropertyDefinition> pd;
        try
        {
            pd = bpdc->GetItem(propStub->m_name);
        }
        catch (FdoException *e)
        {
            e->Release();
            // If an exception thrown here, don't catch it since there's nothing more we can do:
            pd = pdc->GetItem(propStub->m_name);
        }


        //save offset of property data to the reserved position at the
        //beginning of the record
        //TODO: endian
        ((int*)(GetData() + sizeof(FCID_STORAGE)))[i] = GetPosition();

        // Serialize value:
        if (pvc)
        {
            try
            {
                FdoPtr<FdoPropertyValue> pv((FdoPropertyValue*)pvc->GetItem(pd->GetName()));
                WritePropertyValue(pd, pv);
            }
            catch(FdoException* e)
            {
                //if no property value was specified in the input collection
                //we will use default/NULL property value
                e->Release();
                WritePropertyValue(pd, (FdoPropertyValue*)NULL);
            }
        }
        else
        {
            WritePropertyValue(pd, (FdoPropertyValue*)NULL);
        }
    }
}


// Serialize the current row from the reader into the binary writer, filtered based on given identifiers:
void FdoCommonBinaryWriter::WritePropertyValues(FdoClassDefinition *classDef, FdoCommonPropertyIndex* pi, FdoIReader* reader)
{
    VALIDATE_ARGUMENT(reader);
    VALIDATE_ARGUMENT(pi);
    VALIDATE_ARGUMENT(classDef);

    // Get info on the class:
    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> bpdc = classDef->GetBaseProperties();
    FdoPtr<FdoPropertyDefinitionCollection> pdc = classDef->GetProperties();

    //find number of properties we will store into the data record
    //we will use this number to save an offset into the data records for each property
    //at the beginning of the data record
    int numProps = pi->GetNumProps();

    //write feature class ID
    WriteUInt16((FCID_STORAGE)pi->GetFCID());

    //now generate the data value -- write all property values, except for the ones
    //we already wrote to the key -- we have to check if each one is in the ID prop
    //collection

    //reserve space for offsets into property values in data record
    for (int i=0; i<numProps; i++)
        WriteInt32(0);

    // serialize all properties:
    for (int i=0; i<numProps; i++)
    {
        FdoCommonPropertyStub* propStub = pi->GetPropInfo(i);

        // Find the related property definition:
        FdoPtr<FdoPropertyDefinition> pd;
        try
        {
            pd = bpdc->GetItem(propStub->m_name);
        }
        catch (FdoException *e)
        {
            e->Release();
            // If an exception thrown here, don't catch it since there's nothing more we can do:
            pd = pdc->GetItem(propStub->m_name);
        }


        //save offset of property data to the reserved position at the
        //beginning of the record
        //TODO: endian
        ((int*)(GetData() + sizeof(FCID_STORAGE)))[i] = GetPosition();

        // Serialize value:
        WritePropertyValue(pd, reader);
    }
}


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
#include <FdoCommonBinaryReader.h>
#include <FdoCommonStringUtil.h>
#include <FdoCommonPropertyIndex.h>
#include <Common/StringP.h>

//use this to avoid entres equal to 0 in the 
//unicode string hash table -- because hash_map
//uses 0 as default empty values.
const int ADD_TO_OFFSET = 1;

FdoCommonBinaryReader::FdoCommonBinaryReader(unsigned char* data, int len)
{
    m_data = data;
    m_len = len;
    m_pos = 0;
    m_wcsCacheLen = 0;
    m_wcsCacheCurrent = 0;
    m_wcsCache = NULL;

}

FdoCommonBinaryReader::~FdoCommonBinaryReader()
{
    //if we used extra string buffers, clear them
    if (!m_stringCaches.empty())
    {
        for (std::list<wchar_t*>::iterator iter=m_stringCaches.begin(); 
            iter != m_stringCaches.end(); iter++)
            delete [] (*iter);
    }

    if (m_wcsCache)
        delete [] m_wcsCache;
}

void FdoCommonBinaryReader::Reset(unsigned char* data, int len)
{
    m_data = data;
    m_len = len;
    m_pos = 0;
    m_wcsCacheCurrent = 0;
    
    if (!(m_wcsCachedStrings).empty())
    {
        (m_wcsCachedStrings).clear();
    }

    //if we used extra string buffers, clear them
    //and only reuse the last one (pointed to by m_wcsCache)
    if (!m_stringCaches.empty())
    {
        for (std::list<wchar_t*>::iterator iter=m_stringCaches.begin(); 
            iter != m_stringCaches.end(); iter++)
            delete [] (*iter);

		m_stringCaches.clear();
    }
}

void FdoCommonBinaryReader::SetPosition(int offset)
{
    m_pos = offset;
}

int FdoCommonBinaryReader::GetPosition()
{
    return m_pos;
}

unsigned char* FdoCommonBinaryReader::GetDataAtCurrentPosition()
{
    return m_data + m_pos;
}

unsigned FdoCommonBinaryReader::GetDataLen()
{
    return m_len;
}

double FdoCommonBinaryReader::ReadDouble()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(double));

    //TODO: endian
    double ret = *(double*)(m_data + m_pos);
    m_pos += sizeof(double);
    return ret;
}

float FdoCommonBinaryReader::ReadSingle()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(float));

    //TODO: endian
    float ret = *(float*)(m_data + m_pos);
    m_pos += sizeof(float);
    return ret;
}

int FdoCommonBinaryReader::ReadInt32()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(int));

    //TODO: endian
    int ret = *(int*)(m_data + m_pos);
    m_pos += sizeof(int);
    return ret;
}

unsigned FdoCommonBinaryReader::ReadUInt32()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(int));

    //TODO: endian
    unsigned ret = *(unsigned*)(m_data + m_pos);
    m_pos += sizeof(unsigned);
    return ret;
}

short FdoCommonBinaryReader::ReadInt16()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(short));

    //TODO: endian
    short ret = *(short*)(m_data + m_pos);
    m_pos += sizeof(short);
    return ret;
}

unsigned short FdoCommonBinaryReader::ReadUInt16()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(unsigned short));

    //TODO: endian
    unsigned short ret = *(unsigned short*)(m_data + m_pos);
    m_pos += sizeof(unsigned short);
    return ret;
}

FdoInt64 FdoCommonBinaryReader::ReadInt64()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(FdoInt64));

    //TODO: endian
    FdoInt64 ret = *(FdoInt64*)(m_data + m_pos);
    m_pos += sizeof(FdoInt64);
    return ret;
}


unsigned char FdoCommonBinaryReader::ReadByte()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(unsigned char));

    //TODO: endian
    unsigned char ret = *(m_data + m_pos);
    m_pos += sizeof(unsigned char);
    return ret;
}

char FdoCommonBinaryReader::ReadChar()
{
    _ASSERT(m_pos <= m_len - (int)sizeof(char));

    //TODO: endian
    char ret = *(m_data + m_pos);
    m_pos += sizeof(char);
    return ret;
}

wchar_t* FdoCommonBinaryReader::ReadString()
{
    //read string length (number of bytes, not characters!!!)
    //this includes null terminator character
    unsigned mbstrlen = ReadUInt32();

    return ReadRawString(mbstrlen);
}


wchar_t* FdoCommonBinaryReader::ReadRawString(unsigned mbstrlen)
{    
    
    //check if we have read this string already (it will be cached)
    wchar_t* thestring = (m_wcsCachedStrings)[m_pos];
    if (thestring != NULL)
        return thestring;

    //make sure wchar_t cache size is big enough
    if (m_wcsCacheLen - m_wcsCacheCurrent < mbstrlen + 1)
    {
        //pick size -- minimum size is STRING_BUFFER_SIZE
        m_wcsCacheLen = max(STRING_CACHE_SIZE, m_wcsCacheCurrent + mbstrlen + 1);
        wchar_t* tmp = new wchar_t[m_wcsCacheLen];

        if (m_wcsCache)
        {
            //if we already had a buffer, keep track of it
            //in the list, but set the new current buffer 
            //to the newly allocated one
            m_stringCaches.push_back(m_wcsCache);
            m_wcsCache = tmp;
        }
        else
        {
            //otherwise just keep track of cache buffer pointer
            m_wcsCache = tmp;
        }
    }

    //handle empty string
    if (mbstrlen <= 1)
    {
        m_wcsCache[m_wcsCacheCurrent] = 0;
        (m_wcsCachedStrings)[m_pos] = m_wcsCache + m_wcsCacheCurrent;
        m_wcsCacheCurrent += 1;

        //skip past null character
        m_pos += mbstrlen;

        return m_wcsCache + m_wcsCacheCurrent - 1;
    }
        
    //Note: we pass in m_len as number of characters to read, but we know
    //the string must be null terminated, so the function will terminate before that
    int count = FdoStringP::Utf8ToUnicode((char*)(m_data + m_pos), mbstrlen, m_wcsCache + m_wcsCacheCurrent, mbstrlen);

    _ASSERT(count > 0 && (unsigned int)count < mbstrlen);

    //remember offset of current string
    unsigned offset = m_wcsCacheCurrent;
    (m_wcsCachedStrings)[m_pos] = m_wcsCache + offset;

    //increment position count to position after string
    //note that "count" is the number of unicode characters
    //read, not the number of bytes we need to increment.
    m_pos += mbstrlen; 

    //remember where to put next string that we read
    m_wcsCacheCurrent += (int)wcslen(m_wcsCache + m_wcsCacheCurrent) + 1;

    return m_wcsCache + offset;
}


//deserializes a FdoDateTime
FdoDateTime FdoCommonBinaryReader::ReadDateTime()
{
    FdoDateTime ret;

    ret.year = ReadInt16();
    ret.month = ReadChar();
    ret.day = ReadChar();
    ret.hour = ReadChar();
    ret.minute = ReadChar();
    ret.seconds = ReadSingle();

    return ret;
}



int FdoCommonBinaryReader::PositionReader(int recordIndex, FdoCommonPropertyIndex* pi)
{
    //make sure we have data
    if (GetDataLen() == 0)
        throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_69_PROPERTY_NOT_AVAILABLE)));

    //position where offset to property value is stored
    //remember: we have a 2 byte FCID at the beginning
    //and then offsets for each property
    SetPosition(sizeof(FCID_STORAGE) + recordIndex * sizeof(int));

    //get offset to property value and position there
    int offset = ReadInt32();

    //compute how many bytes the
    //property value spans -- we do this by subtracting the two offsets
    int endoffset = 0;

    if (recordIndex < pi->GetNumProps() - 1)
        endoffset = ReadInt32();
    else
        endoffset = GetDataLen();

    //skip to the beginning of the data value
    SetPosition(offset);

    //the length of the data
    //If it is 0, it means the property value is NULL or equal to
    //the default property value (if specified in the schema)
    int len = endoffset - offset;

    return len;
}


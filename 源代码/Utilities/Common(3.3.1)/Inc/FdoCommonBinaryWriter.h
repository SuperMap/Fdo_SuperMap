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
#ifndef FDOCOMMONBINARYWRITER_H
#define FDOCOMMONBINARYWRITER_H

#include <FdoCommonPropertyIndex.h>


class FdoCommonBinaryWriter : public FdoDisposable
{
public:
    FdoCommonBinaryWriter(void) {};   // 0-arg constructor to please FdoPtr::operator->
    FdoCommonBinaryWriter(int initialLen);

    void Reset();

    unsigned char* GetData(bool bDetach = false);
    int GetDataLen();
    int GetPosition();


    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    /// Basic writer methods:

    void WriteDouble(double d);
    void WriteSingle(float f);
    void WriteInt32(int i);
    void WriteUInt32(unsigned i);
    void WriteInt16(short s);
    void WriteUInt16(unsigned short us);
    void WriteInt64(FdoInt64 ll);
    void WriteByte(unsigned char b);
    void WriteChar(char c);
    void WriteString(const wchar_t* src); 
    void WriteRawString(const wchar_t* src);
    void WriteBytes(unsigned char* buf, int len);
    void WriteDateTime(FdoDateTime dt);
    //add more as needed...


    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    /// Complex writer methods:

    void WritePropertyValue(FdoPropertyDefinition* pd, FdoPropertyValue* pv);

    void WritePropertyValue(FdoPropertyDefinition* pd, FdoIReader* reader);

    void WritePropertyValues(FdoClassDefinition* classDef, FdoCommonPropertyIndex* pi, FdoPropertyValueCollection* pvc);

    /// Serialize the current row from the reader into the binary writer, filtered based on given FdoCommonPropertyIndex:
    void WritePropertyValues(FdoClassDefinition *classDef, FdoCommonPropertyIndex* pi, FdoIReader* reader);


protected:

    virtual ~FdoCommonBinaryWriter();

private:

    void CheckResize(unsigned len);

    unsigned char* m_data;
    unsigned m_len;
    unsigned m_pos;

    char* m_strCache;
    unsigned m_strCacheLen;
};


#endif // FDOCOMMONBINARYWRITER_H



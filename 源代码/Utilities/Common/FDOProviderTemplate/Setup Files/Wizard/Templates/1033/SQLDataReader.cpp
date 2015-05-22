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
#include "stdafx.h"

[!output PREFIX]SQLDataReader::[!output PREFIX]SQLDataReader( FdoIConnection *connection /*, [!output PREFIX]QueryResult *query */)
{
    mFdoConnection = dynamic_cast<[!output PREFIX]Connection*>(connection);
    if( mFdoConnection )
        mFdoConnection->AddRef();
}

[!output PREFIX]SQLDataReader::~[!output PREFIX]SQLDataReader()
{
    Close();
    if( mFdoConnection )
        mFdoConnection->Release();
}

FdoInt32 [!output PREFIX]SQLDataReader::GetColumnCount()
{
    return (0);
}

const wchar_t* [!output PREFIX]SQLDataReader::GetColumnName(FdoInt32 index)
{
    return (L"");
}

FdoDataType [!output PREFIX]SQLDataReader::GetColumnType( const wchar_t* columnName )
{
    return (FdoDataType_Int16);
}

FdoPropertyType [!output PREFIX]SQLDataReader::GetPropertyType(FdoString* columnName)
{
	return FdoPropertyType_DataProperty;
}

bool [!output PREFIX]SQLDataReader::GetBoolean(const wchar_t* columnName)
{
    return (false);
}


FdoByte [!output PREFIX]SQLDataReader::GetByte(const wchar_t* columnName)
{
    return ('\0');
}

FdoDateTime [!output PREFIX]SQLDataReader::GetDateTime(const wchar_t* columnName)
{
	FdoDateTime pDataTime;
    return (pDataTime);
}


double [!output PREFIX]SQLDataReader::GetDouble(const wchar_t* columnName)
{
    return (0.0);
}


FdoInt16 [!output PREFIX]SQLDataReader::GetInt16(const wchar_t* columnName)
{
    return (0);
}


FdoInt32 [!output PREFIX]SQLDataReader::GetInt32(const wchar_t* columnName)
{
    return (0);
}


FdoInt64 [!output PREFIX]SQLDataReader::GetInt64(const wchar_t* columnName)
{
    return (0);
}


float [!output PREFIX]SQLDataReader::GetSingle(const wchar_t* columnName)
{
    return (0.0);
}

const wchar_t* [!output PREFIX]SQLDataReader::GetString(const wchar_t* columnName)
{
    return (L"");
}


FdoIStreamReader* [!output PREFIX]SQLDataReader::GetLOBStreamReader(const wchar_t* columnName)
{
	return (NULL);
}

FdoLOBValue* [!output PREFIX]SQLDataReader::GetLOB(const wchar_t* columnName)
{
	return (NULL);
}

bool [!output PREFIX]SQLDataReader::IsNull(const wchar_t* columnName)
{
	return (true);
}

FdoByteArray* [!output PREFIX]SQLDataReader::GetGeometry(const wchar_t* propertyName)
{
	return (NULL);
}

bool [!output PREFIX]SQLDataReader::ReadNext()
{
	return (false);
}

void [!output PREFIX]SQLDataReader::Close()
{
}


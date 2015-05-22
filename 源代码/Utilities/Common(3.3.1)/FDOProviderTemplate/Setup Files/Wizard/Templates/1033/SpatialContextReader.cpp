/*
 * 
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
#include "[!output PREFIX]SpatialContextReader.h"


[!output PREFIX]SpatialContextReader::[!output PREFIX]SpatialContextReader()
{
#pragma message ("ToDo: implement spatial context reader")
}

[!output PREFIX]SpatialContextReader::~[!output PREFIX]SpatialContextReader(void)
{
}

FdoString* [!output PREFIX]SpatialContextReader::GetName()
{
    return (L"");
}

FdoString* [!output PREFIX]SpatialContextReader::GetDescription()
{
    return (L"");
}

FdoString* [!output PREFIX]SpatialContextReader::GetCoordinateSystem()
{
    return (L"");
}


FdoString* [!output PREFIX]SpatialContextReader::GetCoordinateSystemWkt()
{
    return (L"");
}

FdoSpatialContextExtentType [!output PREFIX]SpatialContextReader::GetExtentType()
{
    return (FdoSpatialContextExtentType_Static);
}

FdoByteArray* [!output PREFIX]SpatialContextReader::GetExtent()
{

    return (NULL);
}

const double [!output PREFIX]SpatialContextReader::GetXYTolerance()
{
    return (0.0);
}

const double [!output PREFIX]SpatialContextReader::GetZTolerance()
{
    return (0.0);
}

const bool [!output PREFIX]SpatialContextReader::IsActive()
{
    return (false);
}

bool [!output PREFIX]SpatialContextReader::ReadNext()
{
    return (false);
}

void [!output PREFIX]SpatialContextReader::Dispose()
{
    delete this;
}



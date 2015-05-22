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

#include <malloc.h>
#include <string.h>

[!output PREFIX]DataReader::[!output PREFIX]DataReader ()
{
}

[!output PREFIX]DataReader::~[!output PREFIX]DataReader (void)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]DataReader::[!output PREFIX]DataReader (const [!output PREFIX]DataReader &right) { }

void [!output PREFIX]DataReader::Dispose ()
{
    delete this;
}


/// <summary>Gets the number of propertys in the result set.</summary>
/// <returns>Returns the number of propertys.</returns> 
FdoInt32 [!output PREFIX]DataReader::GetPropertyCount ()
{
    return (0);
}

/// <summary>Gets the name of the property at the given ordinal position.</summary>
/// <param name="index">Input the position of the property.</param> 
/// <returns>Returns the property name</returns> 
FdoString* [!output PREFIX]DataReader::GetPropertyName (FdoInt32 index)
{
    return (L"");
}

/// <summary>Gets the data type of the property with the specified name.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the type of the property.</returns> 
FdoDataType [!output PREFIX]DataReader::GetDataType (FdoString* propertyName)
{
    return (FdoDataType_Int16);
}

/// <summary>Gets the FDO property type of a given property. This is used
//  to indicate if a given property is a geometric property or a data property. If the property is
//  a FdoPropertyType_DataProperty, then GetDataType can be used to to find the data type of the property.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the FDO property type.</returns> 
FdoPropertyType [!output PREFIX]DataReader::GetPropertyType (FdoString* propertyName)
{
    return (FdoPropertyType_DataProperty);
}

/// <summary>Advances the reader to the next item and returns true if there is
/// another object to read or false if reading is complete. The default
/// position of the reader is prior to the first item. Thus you must
/// call ReadNext to begin accessing any data.</summary>
/// <returns>Returns true if there is a next item.</returns> 
bool [!output PREFIX]DataReader::ReadNext ()
{
    return (false);
}




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

[!output PREFIX]FeatureReader::[!output PREFIX]FeatureReader ()
{
}

[!output PREFIX]FeatureReader::~[!output PREFIX]FeatureReader (void)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]FeatureReader::[!output PREFIX]FeatureReader (const [!output PREFIX]FeatureReader &right) { }

void [!output PREFIX]FeatureReader::Dispose ()
{
    delete this;
}

/// <summary>Gets the definition of the object currently being read. If the user
/// has requested only a subset of the class properties, the class 
/// definition reflects what the user has asked, rather than the full class 
/// definition.</summary>
/// <returns>Returns the class definition object.</returns> 
FdoClassDefinition* [!output PREFIX]FeatureReader::GetClassDefinition ()
{
#pragma message ("ToDo: [!output PREFIX]ClassDefinition")
//    FdoPtr<FdoIDescribeSchema> describe = (FdoIDescribeSchema*)mConnection->CreateCommand (FdoCommandType_DescribeSchema);
//    FdoPtr<FdoFeatureSchemaCollection> schemas = describe->Execute ();
//    FdoPtr<FdoFeatureSchema> schema = schemas->GetItem (0);
//    FdoPtr<FdoClassCollection> classes = schema->GetClasses ();
//    FdoPtr<FdoClassDefinition> definition = classes->GetItem (0);

//    return (FDO_SAFE_ADDREF (definition.p));
     return (NULL);
}

/// <summary>Gets a value indicating the depth of nesting for the current reader.
/// The depth value increases each time GetFeatureObject is called and a new 
/// reader is returned. The outermost reader has a depth of 0.</summary>
/// <returns>Returns the depth</returns> 
FdoInt32 [!output PREFIX]FeatureReader::GetDepth ()
{
    return (0);
}

/// <summary>Gets a reference to an FdoIFeatureReader to read the data contained in
/// the object or object collection property. If the property is not an
/// object property, an exception is thrown.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the nested feature reader</returns> 
FdoIFeatureReader* [!output PREFIX]FeatureReader::GetFeatureObject (FdoString* propertyName)
{
    throw FdoCommandException::Create(NlsMsgGet([!output UPPER_PREFIX]_OBJECT_PROPERTIES_NOT_SUPPORTED, "Object properties are not supported."));
}




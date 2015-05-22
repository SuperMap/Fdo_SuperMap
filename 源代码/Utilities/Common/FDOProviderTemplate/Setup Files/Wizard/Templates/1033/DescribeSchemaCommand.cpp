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
#include "[!output PREFIX]Provider.h"

#include <malloc.h>
#include <string.h>

[!output PREFIX]DescribeSchemaCommand::[!output PREFIX]DescribeSchemaCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIDescribeSchema, [!output PREFIX]Connection> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]DescribeSchemaCommand::[!output PREFIX]DescribeSchemaCommand (const [!output PREFIX]DescribeSchemaCommand &right) { }

[!output PREFIX]DescribeSchemaCommand::~[!output PREFIX]DescribeSchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//[!output PREFIX]DescribeSchemaCommand & operator= (const [!output PREFIX]DescribeSchemaCommand &right);

/// <summary>Gets the name of the schema to describe. This function is optional;
/// if not specified, execution of the command will describe all schemas.</summary>
/// <returns>Returns the schema name</returns> 
const wchar_t* [!output PREFIX]DescribeSchemaCommand::GetSchemaName ()
{
    return (mSchemaName);
}


/// <summary>Sets the name of the schema to describe. This function is optional; if not
/// specified, execution of the command will describe all schemas.</summary>
/// <param name="value">Input the schema name</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]DescribeSchemaCommand::SetSchemaName (const wchar_t* value)
{
    mSchemaName = value;
}

/// <summary>Executes the DescribeSchema command and returns a 
/// FdoFeatureSchemaCollection. If a schema name is given that has 
/// references to another schema, the dependent schemas will 
/// be returned as well. If the specified schema name does not exist,
/// the Execute method throws an exception.</summary>
/// <returns>Returns the schema collection representing the schema created.</returns> 
FdoFeatureSchemaCollection* [!output PREFIX]DescribeSchemaCommand::Execute ()
{
    FdoPtr<FdoFeatureSchemaCollection> ret;

    ret = FdoFeatureSchemaCollection::Create (NULL);

    return (FDO_SAFE_ADDREF(ret.p));
}


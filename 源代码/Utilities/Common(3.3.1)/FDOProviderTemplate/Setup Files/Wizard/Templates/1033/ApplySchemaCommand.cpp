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

[!output PREFIX]ApplySchemaCommand::[!output PREFIX]ApplySchemaCommand (FdoIConnection *connection) :
    [!output PREFIX]Command<FdoIApplySchema> (connection)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]ApplySchemaCommand::[!output PREFIX]ApplySchemaCommand (const [!output PREFIX]ApplySchemaCommand &right) { }

[!output PREFIX]ApplySchemaCommand::~[!output PREFIX]ApplySchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//[!output PREFIX]ApplySchemaCommand & operator= (const [!output PREFIX]ApplySchemaCommand &right);

///<summary>Gets the schema to create.</summary>
/// <returns>Returns the schema that would be created.</returns> 
FdoFeatureSchema* [!output PREFIX]ApplySchemaCommand::GetFeatureSchema ()
{
    return (FDO_SAFE_ADDREF (mSchema.p));
}

///<summary>Sets the schema to create.</summary>
/// <param name="value">Input the definition of the schema to create.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ApplySchemaCommand::SetFeatureSchema (FdoFeatureSchema* value)
{
	mSchema = FDO_SAFE_ADDREF (value);
}

/// <summary> Gets the FdoPhysicalSchemaMapping used to specify how the schema definition
/// gets mapped into physical storage.</summary>
/// <returns>Returns FdoPhysicalSchemaMapping</returns> 
FdoPhysicalSchemaMapping* [!output PREFIX]ApplySchemaCommand::GetPhysicalMapping ()
{
	#pragma message ("ToDo: GetPhysicalMapping")
    return NULL;
}

///<summary>Sets the FdoPhysicalSchemaMapping used to specify how the schema definition
///gets mapped into physical storage.</summary>
/// <param name="value">Input the FdoPhysicalSchemaMapping</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ApplySchemaCommand::SetPhysicalMapping (FdoPhysicalSchemaMapping* value)
{
	#pragma message ("ToDo: SetPhysicalMapping")
}



/// <summary> Indicates whether Execute() will ignore element states 
/// when applying the feature schema.</summary>
/// <returns>Returns true if elements states will be ignored, false otherwise. 
/// </returns> 
FdoBoolean [!output PREFIX]ApplySchemaCommand::GetIgnoreStates()
{
	#pragma message ("ToDo: GetIgnoreStates")
    return false;
}

///<summary>Changes the handling of element states by Execute().</summary>
/// <param name="ignoreStates">Input True: Execute() will ignore the 
/// element states on the Feature Schema elements. Instead, it 
/// will additively merge the Feature Schema into the current DataStore.
/// False: Execute() will use the element states to determine whether
/// each element is inserted, modified or deleted.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ApplySchemaCommand::SetIgnoreStates( FdoBoolean ignoreStates )
{
    #pragma message ("ToDo: SetIgnoreStates")
}

///<summary>Executes the ApplySchema command that creates metadata and physical
///storage for the schema. An exception is thrown if the schema already
///exists or if a schema already exists and the feature provider only
///supports a single schema. If schema changes include deletion of classes
///or the schema itself, then those classes (or the schema, if it is marked
///as deleted) must not contain any instance data. If they do, an exception
///will be thrown.</summary>
/// <returns>Returns nothing</returns> 
void [!output PREFIX]ApplySchemaCommand::Execute ()
{
#pragma message ("ToDo: Execute")
}



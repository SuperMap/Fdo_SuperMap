/** \file	 SuperMapDestroySchemaCommand.cpp
*  \author	 ÖÜÐñ
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-30
*/  

#include "SuperMap.h"

SuperMapDestroySchemaCommand::SuperMapDestroySchemaCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIDestroySchema, SuperMapConnection> (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapDestroySchemaCommand::SuperMapDestroySchemaCommand (const SuperMapDestroySchemaCommand &right) { }

SuperMapDestroySchemaCommand::~SuperMapDestroySchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//SuperMapDestroySchemaCommand & operator= (const SuperMapDestroySchemaCommand &right);

///<summary>Gets the name of the schema to destroy as a string.</summary>
/// <returns>Returns the name of the schema to destroy</returns> 
FdoString* SuperMapDestroySchemaCommand::GetSchemaName ()
{
    return (m_SchemaName);
}

///<summary>Sets the name of the schema to destroy as a string.</summary>
/// <param name="value">Input the name of the schema to destroy</param> 
/// <returns>Returns nothing</returns> 
void SuperMapDestroySchemaCommand::SetSchemaName (FdoString* value)
{
    m_SchemaName = value;
}

///<summary>Executes the destroy schema command, which removes the schema, class
///definitions, relation definitions, and all instance data from the DataStore.
///If elements in other schemas refer to the schema to be destroyed
///an exception is thrown.</summary>
/// <returns>Returns nothing</returns> 
void SuperMapDestroySchemaCommand::Execute ()
{
	TRACE(_T("µ÷ÓÃ SuperMapDestroySchemaCommand::Execute [%ls]¡£\n"), m_SchemaName);
    FdoPtr<FdoFeatureSchema> schema = FdoFeatureSchema::Create (m_SchemaName, L"");
    schema->Delete ();
    FdoPtr<FdoIApplySchema> apply = (FdoIApplySchema*)mConnection->CreateCommand (FdoCommandType_ApplySchema);
    apply->SetFeatureSchema (schema);
    apply->Execute ();
}
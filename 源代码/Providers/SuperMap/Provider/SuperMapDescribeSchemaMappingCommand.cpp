/** \file	 SuperMapDescribeSchemaMappingCommand.cpp
*  \author	 ÖÜ Ðñ
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-30
*/

#include "SuperMap.h"


SuperMapDescribeSchemaMappingCommand::SuperMapDescribeSchemaMappingCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIDescribeSchemaMapping, SuperMapConnection> (connection),
    mIncludeDefaults(true)
{
}

/** Do not implement the copy constructor. **/
//SuperMapDescribeSchemaMappingCommand::SuperMapDescribeSchemaMappingCommand (const SuperMapDescribeSchemaMappingCommand &right) { }

SuperMapDescribeSchemaMappingCommand::~SuperMapDescribeSchemaMappingCommand (void)
{
}

/** Do not implement the assignment operator. **/
//SuperMapDescribeSchemaMappingCommand & operator= (const SuperMapDescribeSchemaMappingCommand &right);


/// <summary>Gets the name of the schema for which to describe
/// schema mappings.</summary>
/// <returns>Returns the schema name</returns> 
FdoString* SuperMapDescribeSchemaMappingCommand::GetSchemaName()
{
    return (mSchemaName);
}

/// <summary>Sets the name of the schema to describe. This function is optional; if not
/// specified, execution of the command will describe the mappings for
/// all schemas.</summary>
/// <param name="value">Input the schema name</param> 
/// <returns>Returns nothing</returns> 
void SuperMapDescribeSchemaMappingCommand::SetSchemaName(FdoString* value)
{
    mSchemaName = value;
}

/// <summary>Gets the current "include default mappings" setting.</summary>
/// <returns>Returns True if Execute() will include default mappings.</returns> 
FdoBoolean SuperMapDescribeSchemaMappingCommand::GetIncludeDefaults()
{
    return mIncludeDefaults;
}

/// <summary>Sets the "include default mappings" setting.</summary>
/// <param name="includeDefaults">Input True: Execute() will return
/// all mappings for the feature schema(s).
/// False: Execute() will not include default logical to physical
/// mappings, only those mappings that have been overridden will 
/// be returned.</param> 
/// <returns>Returns nothing</returns> 
void SuperMapDescribeSchemaMappingCommand::SetIncludeDefaults( FdoBoolean includeDefaults )
{
    mIncludeDefaults = includeDefaults;
}

/// <summary>Executes the DescribeSchemaMapping command and returns a 
/// FdoPhysicalSchemaMappingCollection. If the specified schema name does not exist,
/// the Execute method throws an exception.</summary>
/// <returns>Returns the schema mapping collection for the requested feature schemas.</returns> 
FdoPhysicalSchemaMappingCollection* SuperMapDescribeSchemaMappingCommand::Execute()
{
	TRACE(_T("µ÷ÓÃ SuperMapDescribeSchemaMappingCommand::Execute [%ls]¡£\n"));
	
    FdoPtr<FdoPhysicalSchemaMappingCollection> schemaMappings = FdoPhysicalSchemaMappingCollection::Create();
	/*
    // Get the LogicalPhysical schema collection:
    FdoPtr<SuperMapConnection> shpConn = (SuperMapConnection*)GetConnection ();
    FdoPtr<ShpLpFeatureSchemaCollection> lpSchemas = shpConn->GetLpSchemas();
    VALIDATE_POINTER(lpSchemas);

    // Get all schema mappings requested by caller:
    for (FdoInt32 i=0; i<lpSchemas->GetCount(); i++)
    {
        FdoPtr<ShpLpFeatureSchema> lpSchema = lpSchemas->GetItem(i);

        if ((mSchemaName==NULL) || (0==wcslen(mSchemaName)) || (0==wcscmp(mSchemaName,lpSchema->GetName())))
        {
            FdoPtr<FdoShpOvPhysicalSchemaMapping> schemaMapping = lpSchema->GetSchemaMappings(mIncludeDefaults);
            if (schemaMapping != NULL)
                schemaMappings->Add(schemaMapping);
        }
    }
	*/

    return FDO_SAFE_ADDREF(schemaMappings.p);
}
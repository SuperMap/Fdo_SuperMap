/** \file	 SuperMapDescribeSchemaMappingCommand.h
*  \author	 ÖÜ Ðñ
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-30
*/

#ifndef __SUPERMAP_DESCRIBESCHEMAMAPPINGCOMMAND_H__
#define __SUPERMAP_DESCRIBESCHEMAMAPPINGCOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapDescribeSchemaMappingCommand :
    public FdoCommonCommand<FdoIDescribeSchemaMapping, SuperMapConnection>
{
    friend class SuperMapConnection;

    FdoStringP mSchemaName;
    bool mIncludeDefaults;

private:
    //
    // Prevent the use of the copy constructor by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDescribeSchemaMappingCommand (const SuperMapDescribeSchemaMappingCommand &right);

    // Constructs an instance of a DescribeSchema command using the given connection.
    SuperMapDescribeSchemaMappingCommand (FdoIConnection* connection);

protected:
    // Default destructor for DescribeSchema command.
    virtual ~SuperMapDescribeSchemaMappingCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDescribeSchemaMappingCommand & operator= (const SuperMapDescribeSchemaMappingCommand &right);

    /// <summary>Gets the name of the schema for which to describe
    /// schema mappings.</summary>
    /// <returns>Returns the schema name</returns> 
    virtual FdoString* GetSchemaName();

    /// <summary>Sets the name of the schema to describe. This function is optional; if not
    /// specified, execution of the command will describe the mappings for
    /// all schemas.</summary>
    /// <param name="value">Input the schema name</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetSchemaName(FdoString* value);

    /// <summary>Gets the current "include default mappings" setting.</summary>
    /// <returns>Returns True if Execute() will include default mappings.</returns> 
    virtual FdoBoolean GetIncludeDefaults();

    /// <summary>Sets the "include default mappings" setting.</summary>
    /// <param name="includeDefaults">Input True: Execute() will return
    /// all mappings for the feature schema(s).
    /// False: Execute() will not include default logical to physical
    /// mappings, only those mappings that have been overridden will 
    /// be returned.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetIncludeDefaults( FdoBoolean includeDefaults );

    /// <summary>Executes the DescribeSchemaMapping command and returns a 
    /// FdoPhysicalSchemaMappingCollection. If the specified schema name does not exist,
    /// the Execute method throws an exception.</summary>
    /// <returns>Returns the schema mapping collection for the requested feature schemas.</returns> 
    virtual FdoPhysicalSchemaMappingCollection* Execute();
};

#endif // __SUPERMAP_DESCRIBESCHEMAMAPPINGCOMMAND_H__
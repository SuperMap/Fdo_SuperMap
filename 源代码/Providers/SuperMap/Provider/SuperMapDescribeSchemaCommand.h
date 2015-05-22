
/** \file	 SuperMapDescribeSchemaCommand.h
*  \author	 ºÂÓñ½­
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*/

#ifndef __SUPERMAP_DESCRIBESCHEMACOMMAND_H__
#define __SUPERMAP_DESCRIBESCHEMACOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapDescribeSchemaCommand : public FdoCommonCommand<FdoIDescribeSchema, SuperMapConnection>
{
    friend class SuperMapConnection;
private:
    //
    // Prevent the use of the copy constructor by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDescribeSchemaCommand (const SuperMapDescribeSchemaCommand &right);

    // Constructs an instance of a DescribeSchema command using the given connection.
    SuperMapDescribeSchemaCommand (FdoIConnection* connection);

protected:
    // Default destructor for DescribeSchema command.
    virtual ~SuperMapDescribeSchemaCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDescribeSchemaCommand & operator= (const SuperMapDescribeSchemaCommand &right);

    /// <summary>Gets the name of the schema to describe. This function is optional;
    /// if not specified, execution of the command will describe all schemas.</summary>
    /// <returns>Returns the schema name</returns> 
    virtual const wchar_t* GetSchemaName ();

    /// <summary>Sets the name of the schema to describe. This function is optional; if not
    /// specified, execution of the command will describe all schemas.</summary>
    /// <param name="value">Input the schema name</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetSchemaName (const wchar_t* value);

    /// <summary>Executes the DescribeSchema command and returns a 
    /// FdoFeatureSchemaCollection. If a schema name is given that has 
    /// references to another schema, the dependent schemas will 
    /// be returned as well. If the specified schema name does not exist,
    /// the Execute method throws an exception.</summary>
    /// <returns>Returns the schema collection representing the schema created.</returns> 
    virtual FdoFeatureSchemaCollection* Execute ();

private:
    FdoStringP m_SchemaName;
};

#endif // __SUPERMAP_DESCRIBESCHEMACOMMAND_H__


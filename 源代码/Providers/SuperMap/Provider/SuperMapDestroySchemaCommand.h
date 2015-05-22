/** \file	 SuperMapDestroySchemaCommand.h
*  \author	 ÖÜÐñ
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-30
*/  

#ifndef __SUPERMAP_DESTROYSCHEMACOMMAND_H__
#define __SUPERMAP_DESTROYSCHEMACOMMAND_H__

#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapDestroySchemaCommand :
    public FdoCommonCommand<FdoIDestroySchema, SuperMapConnection>
{
    friend class SuperMapConnection;

    FdoStringP m_SchemaName;

private:
    //
    // Prevent the use of the copy constructor by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDestroySchemaCommand (const SuperMapDestroySchemaCommand &right);

    // Constructs an instance of a DescribeSchema command using the given connection.
    SuperMapDestroySchemaCommand (FdoIConnection* connection);

protected:
    // Default destructor for DescribeSchema command.
    virtual ~SuperMapDestroySchemaCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implementing it.
    // DO NOT IMPLEMENT
    SuperMapDestroySchemaCommand & operator= (const SuperMapDestroySchemaCommand &right);

    ///<summary>Gets the name of the schema to destroy as a string.</summary>
    /// <returns>Returns the name of the schema to destroy</returns> 
    virtual FdoString* GetSchemaName ();

    ///<summary>Sets the name of the schema to destroy as a string.</summary>
    /// <param name="value">Input the name of the schema to destroy</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetSchemaName (FdoString* value);

    ///<summary>Executes the destroy schema command, which removes the schema, class
    ///definitions, relation definitions, and all instance data from the DataStore.
    ///If elements in other schemas refer to the schema to be destroyed
    ///an exception is thrown.</summary>
    /// <returns>Returns nothing</returns> 
    virtual void Execute ();
};

#endif // SUPERMAPDESTROYSCHEMACOMMAND_H


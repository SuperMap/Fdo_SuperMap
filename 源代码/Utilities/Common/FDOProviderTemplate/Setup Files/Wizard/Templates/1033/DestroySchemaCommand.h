/*
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
 */

#ifndef [!output PREFIX]DESTROYSCHEMACOMMAND_H
#define [!output PREFIX]DESTROYSCHEMACOMMAND_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]DestroySchemaCommand :
    public [!output PREFIX]Command<FdoIDestroySchema>
{
    friend class [!output PREFIX]Connection;

protected:
    FdoStringP mSchemaName;

private:
    [!output PREFIX]DestroySchemaCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]DestroySchemaCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by definning it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]DestroySchemaCommand & operator= (const [!output PREFIX]DestroySchemaCommand &right);

    //
    // FdoIDestroySchema interface
    //

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

#endif // [!output PREFIX]DESTROYSCHEMACOMMAND_H


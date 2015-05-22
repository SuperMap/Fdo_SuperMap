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

#ifndef [!output PREFIX]SQLCOMMAND_H
#define [!output PREFIX]SQLCOMMAND_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]SQLCommand :
    public [!output PREFIX]Command<FdoISQLCommand>
{
    friend class [!output PREFIX]Connection;

protected:
    wchar_t* mSql;

private:
    [!output PREFIX]SQLCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]SQLCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by definning it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]SQLCommand & operator= (const [!output PREFIX]SQLCommand &right);

    /// <summary>Gets the SQL statement to be executed as a string.</summary>
    /// <returns>Returns the SQL statement.</returns> 
    virtual FdoString* GetSQLStatement ();

    /// <summary>Sets the SQL statement to be executed as a string.</summary>
    /// <param name="value">Input the SQL statement.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetSQLStatement (FdoString* value);

    /// <summary>Executes the SQL statement against the connection object and returns
    /// the number of rows affected.</summary>
    /// <returns>Returns the number of rows affected.</returns> 
    virtual FdoInt32 ExecuteNonQuery ();

    /// <summary>Executes the SQL statement against the connection object and returns
    /// an FdoISQLDataReader.</summary>
    /// <returns>Returns the data reader.</returns> 
    virtual FdoISQLDataReader* ExecuteReader ();
};

#endif // [!output PREFIX]SQLCOMMAND_H


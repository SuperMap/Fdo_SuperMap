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

[!output PREFIX]SQLCommand::[!output PREFIX]SQLCommand (FdoIConnection *connection) :
    [!output PREFIX]Command<FdoISQLCommand> (connection),
    mSql (NULL)
{
}

/** Do not implement the copy constructor. **/
//[!output PREFIX]SQLCommand::[!output PREFIX]SQLCommand (const [!output PREFIX]SQLCommand &right) { }

[!output PREFIX]SQLCommand::~[!output PREFIX]SQLCommand (void)
{
    if (NULL != mSql)
    {
        delete[] mSql;
        mSql = NULL;
    }
}

/// <summary>Gets the SQL statement to be executed as a string.</summary>
/// <returns>Returns the SQL statement.</returns> 
FdoString* [!output PREFIX]SQLCommand::GetSQLStatement ()
{
    return (mSql);
}

/// <summary>Sets the SQL statement to be executed as a string.</summary>
/// <param name="value">Input the SQL statement.</param> 
/// <returns>Returns nothing</returns> 
void [!output PREFIX]SQLCommand::SetSQLStatement (FdoString* value)
{
    if (NULL != mSql)
    {
        delete[] mSql;
        mSql = NULL;
    }

    if (NULL != value)
    {
        mSql = new wchar_t[wcslen (value) + 1];
        wcscpy (mSql, value);
    }
}

/// <summary>Executes the SQL statement against the connection object and returns
/// the number of rows affected.</summary>
/// <returns>Returns the number of rows affected.</returns> 
FdoInt32 [!output PREFIX]SQLCommand::ExecuteNonQuery ()
{
    return (0);
}

/// <summary>Executes the SQL statement against the connection object and returns
/// an FdoISQLDataReader.</summary>
/// <returns>Returns the data reader.</returns> 
FdoISQLDataReader* [!output PREFIX]SQLCommand::ExecuteReader ()
{
    return new [!output PREFIX]SQLDataReader(mConnection);
}


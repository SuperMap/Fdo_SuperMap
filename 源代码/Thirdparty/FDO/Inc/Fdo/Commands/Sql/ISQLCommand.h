#ifndef _ISQLCOMMAND_H_
#define _ISQLCOMMAND_H_
//

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Commands/ICommand.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/Sql/ISQLDataReader.h>

/// \brief
/// The FdoISQLCommand interface defines the SQL command, which supports the
/// execution of a SQL statement against an underlying RDBMS. Two execute
/// methods are provided to distinguish between statements that return table data
/// versus those that execute non query type operations.
class FdoISQLCommand : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the SQL statement to be executed as a string.
    /// 
    /// \return
    /// Returns the SQL statement.
    /// 
    FDO_API virtual FdoString* GetSQLStatement() = 0;

    /// \brief
    /// Sets the SQL statement to be executed as a string.
    /// 
    /// \param value 
    /// Input the SQL statement.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetSQLStatement(FdoString* value) = 0;

    /// \brief
    /// Executes the SQL statement against the connection object and returns
    /// the number of rows affected.
    /// 
    /// \return
    /// Returns the number of rows affected.
    /// 
    FDO_API virtual FdoInt32 ExecuteNonQuery() = 0;

    /// \brief
    /// Executes the SQL statement against the connection object and returns
    /// an FdoISQLDataReader.
    /// 
    /// \return
    /// Returns the data reader.
    /// 
    FDO_API virtual FdoISQLDataReader* ExecuteReader() = 0;
};
#endif



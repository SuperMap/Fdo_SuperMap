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

#ifndef [!output UPPERPREFIX]TRANSACTION_H
#define [!output UPPERPREFIX]TRANSACTION_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]Transaction : public FdoITransaction
{
    friend class [!output PREFIX]Connection;

protected:
    [!output PREFIX]Connection* mConnection;

    [!output PREFIX]Transaction ([!output PREFIX]Connection* connection);

public:
    virtual ~[!output PREFIX]Transaction(void);

    /// <summary> Gets the FdoIConnection object associated with the transaction.</summary>
    /// <returns>Returns FdoIConnection object</returns>
    FdoIConnection* GetConnection ();

    /// <summary> Commits the transaction.</summary>
    /// <returns>Returns nothing</returns>
    void Commit ();

    /// <summary> Rolls back a transaction from a pending state.</summary>
    /// <returns>Returns nothing</returns>
    void Rollback ();

    void Dispose ();
};

#endif // [!output UPPERPREFIX]TRANSACTION_H


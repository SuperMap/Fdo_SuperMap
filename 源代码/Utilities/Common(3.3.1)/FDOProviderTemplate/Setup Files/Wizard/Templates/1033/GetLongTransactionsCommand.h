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

#ifndef [!output PREFIX]GETLONGTRANSACTIONCOMMAND_H
#define [!output PREFIX]GETLONGTRANSACTIONCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]GetLongTransactionsCommand :
    public [!output PREFIX]Command<FdoIGetLongTransactions>
{
    // name of the long transaction
    FdoStringP mName;

public:
    [!output PREFIX]GetLongTransactionsCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]GetLongTransactionsCommand (void);

    /// <summary>Sets the name of the long transaction for which information
    /// should be retrieved. The function can also be used to nullify the
    /// property by using a NULL pointer as the function's parameter. If the
    /// the property is not set, the function returns information for all
    /// available long transactions.</summary>
    /// <returns>Returns nothing</returns>
    void SetName(FdoString* value);

    /// <summary>Gets the currently set name of the long transaction for which
    /// the long transaction information should be retrieved. If the property
    /// is not set, the function returns a NULL pointer.</summary>
    /// <returns>Returns a long transaction name.</returns>
    FdoString* GetName();

    /// <summary>Executes the GetLongTransactions command returning a reference to an
    /// FdoILongTransactionReader.</summary>
    /// <returns>Returns the long transaction reader</returns> 
    FdoILongTransactionReader* Execute ();
};

#endif // [!output PREFIX]GETLONGTRANSACTIONCOMMAND_H


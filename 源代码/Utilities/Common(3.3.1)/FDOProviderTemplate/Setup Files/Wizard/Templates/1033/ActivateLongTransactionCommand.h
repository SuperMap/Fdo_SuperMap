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

#ifndef [!output PREFIX]ACTIVATELONGTRANSACTIONCOMMAND_H
#define [!output PREFIX]ACTIVATELONGTRANSACTIONCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]ActivateLongTransactionCommand :
    public [!output PREFIX]Command<FdoIActivateLongTransaction>
{

protected:
    // name of the long transaction
    FdoStringP mName;

public:
    [!output PREFIX]ActivateLongTransactionCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]ActivateLongTransactionCommand (void);

    /// <summary>Gets the name of the long transaction to activate as a string.</summary>
    /// <returns>Returns the name of the long transaction</returns>
    FdoString* GetName ();

    /// <summary>Sets the name of the long transaction to activate as a string.</summary>
    /// <param name="value">Input the name of the long transaction</param> 
    /// <returns>Returns nothing</returns> 
    void SetName (FdoString* value);

    /// <summary>Executes the activate long transaction command. An exception is
    /// thrown if the long transaction does not exist or the user does not
    /// have access privileges to the long transaction.</summary>
    /// <returns>Returns nothing</returns> 
    void Execute ();
};

#endif // [!output PREFIX]ACTIVATELONGTRANSACTIONCOMMAND_H


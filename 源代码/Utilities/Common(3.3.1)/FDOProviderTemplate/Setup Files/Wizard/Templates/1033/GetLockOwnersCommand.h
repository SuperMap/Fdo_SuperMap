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

#ifndef [!output PREFIX]GETLOCKOWNERSCOMMAND_H
#define [!output PREFIX]GETLOCKOWNERSCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]GetLockOwnersCommand :
    public [!output PREFIX]Command<FdoIGetLockOwners>
{
    friend class [!output PREFIX]Connection;

private:

    [!output PREFIX]GetLockOwnersCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]GetLockOwnersCommand (void);

public:

    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]GetLockOwnersCommand & operator= (const [!output PREFIX]GetLockOwnersCommand &right);

    //
    // FdoIGetLockOwners overrides
    //

    /// <summary>Executes the GetLockOwners command, returning an FdoILockOwnersReader.</summary>
    /// <returns>Returns the lock info reader.</returns> 
    FdoILockOwnersReader* Execute ();
};

#endif // [!output PREFIX]GETLOCKOWNERSCOMMAND_H


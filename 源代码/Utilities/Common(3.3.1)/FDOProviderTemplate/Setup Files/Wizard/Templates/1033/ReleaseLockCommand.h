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

#ifndef [!output PREFIX]RELEASELOCKCOMMAND_H
#define [!output PREFIX]RELEASELOCKCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]ReleaseLockCommand :
    public [!output PREFIX]FeatureCommand<FdoIReleaseLock>
{
    friend class [!output PREFIX]Connection;

protected:
    FdoStringP mOwner; // choose who's locks, default to current user

  protected:

    [!output PREFIX]ReleaseLockCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]ReleaseLockCommand (void);

public:

    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]ReleaseLockCommand & operator= (const [!output PREFIX]ReleaseLockCommand &right);

    //
    // FdoIReleaseLock overrides
    //

    /// <summary>Gets the name of the user who owns the lock to release. If this function
    /// returns null or an empty string the lock being released is assumed to
    /// belong to the connected user. Users with appropriate administrative
    /// privileges can release locks owned by other users. The SetLockOwner
    /// method allows an administrative user to set that name.</summary>
    /// <returns>Returns name of the user</returns> 
    FdoString* GetLockOwner ();

    /// <summary>Sets the name of the user who owns the lock to release. If set to null
    /// or an empty string the lock being released is assumed to belong to the
    /// connected user. Users with appropriate administrative privileges can
    /// release locks owned by other users. The SetLockOwner method allows an
    /// administrative user to set that name.</summary>
    /// <param name="value">Input the name of the user.</param> 
    /// <returns>Returns nothing</returns> 
    void SetLockOwner (FdoString* value);

    /// <summary>Executes the release lock command, returning an FdoILockConflictReader.</summary>
    /// <returns>Returns an FdoILockConflictReader</returns> 
    FdoILockConflictReader* Execute ();
};

#endif // [!output PREFIX]RELEASELOCKCOMMAND_H


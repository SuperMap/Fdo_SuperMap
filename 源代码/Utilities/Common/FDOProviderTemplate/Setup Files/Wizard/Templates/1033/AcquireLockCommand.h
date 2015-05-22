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

#ifndef [!output PREFIX]ACQUIRELOCKCOMMAND_H
#define [!output PREFIX]ACQUIRELOCKCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]AcquireLockCommand :
    public [!output PREFIX]FeatureCommand<FdoIAcquireLock>
{
    friend class [!output PREFIX]Connection;

protected:

    FdoLockType mType; // lock type; only exclusive honoured
    FdoLockStrategy mStrategy; // full/partial locking

private:

    [!output PREFIX]AcquireLockCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]AcquireLockCommand (void);

public:

    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]AcquireLockCommand & operator= (const [!output PREFIX]AcquireLockCommand &right);

    /// <summary>Gets the FdoLockType value.</summary>
    /// <returns>Returns the desired lock type.</returns> 
    FdoLockType GetLockType ();

    /// <summary>Sets the FdoLockType value.</summary>
    /// <param name="value">Input the lock type</param> 
    /// <returns>Returns nothing</returns> 
    void SetLockType (FdoLockType value);

    /// <summary>Gets the FdoLockStrategy value.</summary>
    /// <returns>Returns the desired lock strategy.</returns> 
    FdoLockStrategy GetLockStrategy ();

    /// <summary>Sets the FdoLockStrategy value.</summary>
    /// <param name="value">Input the lock strategy used for locking objects</param> 
    /// <returns>Returns nothing</returns> 
    void SetLockStrategy (FdoLockStrategy value);

    /// <summary>Executes the AcquireLock command, returning an FdoILockConflictReader.</summary>
    /// <returns>Returns the list of conflicts.</returns> 
    FdoILockConflictReader* Execute ();
};

#endif // [!output PREFIX]ACQUIRELOCKCOMMAND_H


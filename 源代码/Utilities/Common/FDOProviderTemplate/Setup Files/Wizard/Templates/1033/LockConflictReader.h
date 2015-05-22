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

#ifndef [!output UPPER_PREFIX]LOCKCONFLICTREADER_H
#define [!output UPPER_PREFIX]LOCKCONFLICTREADER_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]LockConflictReader :
    public FdoILockConflictReader
{
    friend class [!output PREFIX]SelectCommand;
    friend class [!output PREFIX]UpdateCommand;
    friend class [!output PREFIX]DeleteCommand;
    friend class [!output PREFIX]FeatureReader;
[!if LOCKING]
    friend class [!output PREFIX]AcquireLockCommand;
    friend class [!output PREFIX]ReleaseLockCommand;
[!endif]
[!if LONG_TRANSACTIONS]
	friend class [!output PREFIX]RollbackLongTransactionCommand;
[!endif]

    FdoPtr<[!output PREFIX]Connection> mConnection;
    FdoStringP mClassName; // class name for locks in this conflict reader
    FdoStringP mOwner; // owner for current lock in this conflict reader
    FdoPtr<FdoPropertyValueCollection> mIdentity; // GetIdentity objects, reused if the refcount allows

protected:
    // 0-argument constructor to please FdoPtr::operator->() :
    [!output PREFIX]LockConflictReader() { [!output PREFIX]LockConflictReader(NULL, L"", L""); }

    [!output PREFIX]LockConflictReader ([!output PREFIX]Connection* connection, FdoString* cls, FdoString* owner);
    virtual ~[!output PREFIX]LockConflictReader (void);

    /// <summary>Checks if we're the only one hanging onto the GetIdentity objects.</summary>
    // <returns>Returns true if we should allocate another set of identity objects.</returns> 
    virtual bool Referenced ();

public:

    // FdoIDisposable interface

    // <summary>Dispose this object.</summary>
    // <returns>Returns nothing</returns> 
    void Dispose ();

    // FdoILockConflictReader overrides

    /// <summary>Gets the class name of the feature currently being read.</summary>
    /// <returns>Returns the class name.</returns> 
    FdoString* GetFeatureClassName ();

    /// <summary>Returns an FdoPropertyValueCollection containing the property values
    /// that uniquely identify feature currently being read.</summary>
    /// <returns>Returns the property collection identifying the feature.</returns> 
    FdoPropertyValueCollection* GetIdentity ();

    /// <summary>Gets the name of the owner that holds a lock on the feature 
    /// currently being read.</summary>
    /// <returns>Returns the name of the owner.</returns> 
    FdoString* GetLockOwner ();

    /// <summary>Gets the conflict type for the conflict currently being read.</summary>
    /// <returns>Returns the conflict type for the conflict currently being read.</returns> 
    FdoConflictType GetConflictType ();

    /// <summary>Gets the name of the long transaction in which the feature 
    /// currently being read is locked.</summary>
    /// <returns>Returns the name of the long transaction in which the feature
    /// currently being read is locked.</returns> 
    FdoString* GetLongTransaction ();

    /// <summary>Advances the reader to the next item. The default position of the 
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns> 
    bool ReadNext ();

    /// <summary>Closes the FdoILockConflictReader object, freeing any resources it may
    /// be holding.</summary>
    /// <returns>Returns nothing.</returns> 
    void Close ();
};

#endif // [!output UPPER_PREFIX]LOCKCONFLICTREADER_H


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

#ifndef [!output PREFIX]LOCKEDOBJECTREADER_H
#define [!output PREFIX]LOCKEDOBJECTREADER_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]LockedObjectReader :
    public FdoILockedObjectReader
{
    friend class [!output PREFIX]GetLockInfoCommand;
    friend class [!output PREFIX]GetLockedObjectsCommand;

    FdoPtr<[!output PREFIX]Connection> mConnection; // our connection object for accessing [!output PREFIX] API

    FdoStringP mClassName; // cached class name
    FdoStringP mUser; // cached user name

    // GetIdentity objects, reused if the refcount allows
    FdoPtr<FdoPropertyValueCollection> mIdentity;

protected:
	[!output PREFIX]LockedObjectReader() {};
    [!output PREFIX]LockedObjectReader ([!output PREFIX]Connection* connection);
    virtual ~[!output PREFIX]LockedObjectReader (void);

    /// <summary>Checks if we're the only one hanging onto the GetIdentity objects.</summary>
    // <returns>Returns true if we should allocate another set of identity objects.</returns> 
    virtual bool Referenced ();

public:

    // FdoIDisposable interface

    // <summary>Dispose this object.</summary>
    // <returns>Returns nothing</returns> 
    void Dispose ();

    // FdoILockedObjectReader interface

    /// <summary>Gets the class name of the feature currently being read.</summary>
    /// <returns>Returns the name of the class.</returns> 
    FdoString* GetFeatureClassName ();

    /// <summary>Returns an FdoPropertyValueCollection containing the property values
    /// that uniquely identify the feature currently being read.</summary>
    /// <returns>Returns the property collection identifying the feature.</returns> 
    FdoPropertyValueCollection* GetIdentity ();

    /// <summary>Gets the name of user who holds the lock on the feature currently being
    /// read.</summary>
    /// <returns>Returns the lock owner.</returns> 
    FdoString* GetLockOwner ();

    /// <summary>Gets the name of the long transaction for the feature currently
    /// being read.</summary>
    /// <returns>Returns the name of the long transaction.</returns> 
    FdoString* GetLongTransaction ();

    /// <summary>Gets the type of the lock held on the feature currently being read.</summary>
    /// <returns>Returns the lock type.</returns> 
    const FdoLockType GetLockType ();

    /// <summary>Advances the reader to the next item. The default position of the 
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns> 
    bool ReadNext ();

    /// <summary>Closes the FdoILockInfoReader object, freeing any resources it may
    /// be holding.</summary>
    /// <returns>Returns nothing.</returns> 
    void Close ();

};

#endif // [!output PREFIX]LOCKEDOBJECTREADER_H


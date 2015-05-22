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

#ifndef [!output UPPER_PREFIX]SELECTCOMMAND_H
#define [!output UPPER_PREFIX]SELECTCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]SelectCommand :
    public FdoCommonFeatureCommand<FdoISelect, [!output PREFIX]Connection>
{
    friend class [!output PREFIX]Connection;

protected:
    FdoLockType mType;
    FdoLockStrategy mStrategy;
    FdoPtr<FdoIdentifierCollection> mPropertiesToSelect;

protected:
    [!output PREFIX]SelectCommand ([!output PREFIX]Connection* connection);
    virtual ~[!output PREFIX]SelectCommand (void);

public:
    //
    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]SelectCommand & operator= (const [!output PREFIX]SelectCommand &right);

    void Dispose ();

    /// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
    /// return with the result. If empty all properties of the specified class
    /// are returned.</summary>
    /// <returns>Returns the list of property names.</returns> 
    virtual FdoIdentifierCollection* GetPropertyNames ();

    /// <summary>Gets the FdoLockType value (see "Locking Commands").</summary>
    /// <returns>Returns the lock type.</returns> 
    virtual FdoLockType GetLockType ();

    /// <summary>Sets the FdoLockType value (see "Locking Commands").</summary>
    /// <param name="value">Input the lock type.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetLockType (FdoLockType value);

    /// <summary>Gets the FdoLockStrategy value (see "Locking Commands").</summary>
    /// <returns>Returns the lock strategy.</returns> 
    virtual FdoLockStrategy GetLockStrategy ();

    /// <summary>Sets the FdoLockStrategy value (see "Locking Commands").</summary>
    /// <param name="value">Input the lock strategy.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetLockStrategy (FdoLockStrategy value);

    /// <summary>Executes the select command and returns a reference to an FdoIFeatureReader.</summary>
    /// <returns>Returns the feature reader.</returns> 
    virtual FdoIFeatureReader* Execute ();

    /// <summary>Executes the select command and returns a reference to an
    /// IFeatureReader.</summary> 
    /// <returns>Returns the feature reader.</returns> 
    virtual FdoIFeatureReader* ExecuteWithLock ();

    /// <summary> When executing the operation ExecuteWithLock lock 
    /// conflicts may occur. Those lock conflicts are reported. The 
    /// function GetLockConflicts returns a lock conflict reader 
    /// providing access to the list of lock conflicts that occurred 
    /// during the execution of the operation.</summary>
    /// <returns>Returns a lock conflict reader.</returns> 
    virtual FdoILockConflictReader* GetLockConflicts ();

    /// <summary>Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a order by criteria.</summary>
    /// <returns>Returns the list of group by property names.</returns> 
    virtual FdoIdentifierCollection* GetOrdering(){ return NULL; }

    /// <summary>Set the ordering option of the selection. This is only used if the ordering collection is not empty.</summary>
    /// <param name="option">Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
    /// FdoOrderingOption_Ascending is the default value.</param> 
    /// <returns>Returns nothing</returns> 
    virtual void SetOrderingOption( FdoOrderingOption  option ) {}

    /// <summary>Gets the ordering option.</summary>
    /// <returns>Returns the ordering option.</returns> 
    virtual FdoOrderingOption GetOrderingOption( ){ return (FdoOrderingOption)0; }
};

#endif // [!output UPPER_PREFIX]SELECTCOMMAND_H


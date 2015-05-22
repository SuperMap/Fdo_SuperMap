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

#ifndef [!output UPPER_PREFIX]CONNECTIONCAPABILITIES_H
#define [!output UPPER_PREFIX]CONNECTIONCAPABILITIES_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]ConnectionCapabilities : public FdoIConnectionCapabilities
{
public:
    [!output PREFIX]ConnectionCapabilities ();

protected:
    virtual ~[!output PREFIX]ConnectionCapabilities ();

protected:
    virtual void Dispose ();

public:

    /// <summary>Gets an FdoThreadCapability value that declares the feature provider's level of thread safety.</summary>
    /// <returns>Returns the connection thread capability.</returns> 
    FdoThreadCapability GetThreadCapability ();

    /// <summary>Gets the spatial context extent types supported by the feature provider.</summary>
    /// <param name="length">Output the number of spatial context types.</param> 
    /// <returns>Returns the list of spatial context extent types.</returns> 
    FdoSpatialContextExtentType* GetSpatialContextTypes (FdoInt32& length);

    /// <summary>Determines if the feature provider supports persistent locking.</summary>
    /// <returns>Returns true if the feature provider supports persistent locking.</returns> 
    bool SupportsLocking ();

    // Returns the list of lock types
    virtual FdoLockType* GetLockTypes(FdoInt32& size);

    /// <summary>Determines if the feature provider supports connection timeout.</summary>
    /// <returns>Returns true if the feature provider supports connection timeout.</returns> 
    bool SupportsTimeout ();

    /// <summary>Determines if the feature provider supports transactions.</summary>
    /// <returns>Returns true if the feature provider supports transactions.</returns> 
    bool SupportsTransactions ();

    /// <summary>Determines true if the feature provider supports long transactions.</summary>
    /// <remarks><span class="note">Note&nbsp;</span> Long Transaction commands are NOT supported 
    /// in this release.</remarks>
    /// <returns>Returns true if the feature provider supports long transactions.</returns> 
    bool SupportsLongTransactions ();

    /// <summary>Determines if the feature provider supports SQL commands.</summary>
    /// <returns>Returns true if the feature provider supports SQL commands.</returns> 
    bool SupportsSQL ();

    /// <summary>Determines if the feature provider supports XML configuration.</summary>
    /// <returns>Returns true if the feature provider supports the setting of a configuration.</returns> 
    bool SupportsConfiguration();

    /// <summary>Determines if the provider supports multiple spatial contexts.
    /// <returns>Returns true if the provider supports multiple spatial contexts.
    bool SupportsMultipleSpatialContexts();

    /// <summary>Determines if the provider supports specifying the coordinate system by name or ID without specifying the WKT
    /// when creating a new spatial context.</summary>
    /// <returns>Returns true if the provider supports specifying the coordinate system by name or ID without specifying the WKT
    /// when creating a new spatial context.</returns> 
    bool SupportsCSysWKTFromCSysName();

    /// \brief
    ///	Determines if write is supported by the provider or by the datastore depending on whether this request is at
    /// the provider or datastore level.
    ///
    /// \return
    ///	Returns true if write is supported by the provider or by the datastore depending on whether this request is at
    /// the provider or datastore level.
    virtual bool SupportsWrite();

    /// \brief
    /// Determines if the provider or datastore can support more than one user writing to a single datastore at
    /// one time.
    ///
    /// \return
    /// Returns true if the provider or datastore can support more than one user writing to a single datastore at
    /// one time.
    virtual bool SupportsMultiUserWrite();

    // \brief
    /// Determines if the provider can support the flush function. Flush is used to write any outstanding data
    /// to the datastore. This is mainly used by the file based providers to ensure that any cached data is writen to the file.
    ///
    /// \return
    /// Returns true if the provider or datastore can support the flush function.
    ///
    virtual bool SupportsFlush();
};

#endif // [!output UPPER_PREFIX]CONNECTIONCAPABILITIES_H


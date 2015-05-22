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

#ifndef [!output PREFIX]GETLOCKEDOBJECTSCOMMAND_H
#define [!output PREFIX]GETLOCKEDOBJECTSCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]GetLockedObjectsCommand :
    public [!output PREFIX]Command<FdoIGetLockedObjects>
{
    friend class [!output PREFIX]Connection;

protected:

    FdoStringP mLockOwner;

private:

    [!output PREFIX]GetLockedObjectsCommand (FdoIConnection *connection);
    virtual ~[!output PREFIX]GetLockedObjectsCommand (void);

public:

    // Prevent the use of the Assignment Operation by defining it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]GetLockedObjectsCommand & operator= (const [!output PREFIX]GetLockedObjectsCommand &right);

    //
    // FdoIGetLockedObjects overrides
    //

    ///<summary>Gets the name of the user for which to get a list of locked objects.</summary>
    /// <returns>Returns the name of the user</returns> 
    FdoString* GetLockOwner ();

    ///<summary>Sets the name of the user for which to get a list of locked objects.</summary>
    /// <param name="value">Input the name of the user</param> 
    /// <returns>Returns nothing</returns> 
    void SetLockOwner (FdoString* value);

    ///<summary>Executes the GetLockedObjects command, returning an FdoILockedObjectReader.</summary>
    /// <returns>Returns FdoILockedObjectReade.r</returns> 
    FdoILockedObjectReader* Execute ();
};

#endif // [!output PREFIX]GETLOCKEDOBJECTSCOMMAND_H


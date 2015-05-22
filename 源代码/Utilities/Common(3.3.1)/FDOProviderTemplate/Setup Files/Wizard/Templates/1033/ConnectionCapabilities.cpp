/*
 * 
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
* 
 */

#include "stdafx.h"

[!output PREFIX]ConnectionCapabilities::[!output PREFIX]ConnectionCapabilities ()
{
}

[!output PREFIX]ConnectionCapabilities::~[!output PREFIX]ConnectionCapabilities ()
{
}

void [!output PREFIX]ConnectionCapabilities::Dispose()
{
    delete this;
}

/// <summary>Gets an FdoThreadCapability value that declares the feature provider's level of thread safety.</summary>
/// <returns>Returns the connection thread capability.</returns> 
FdoThreadCapability [!output PREFIX]ConnectionCapabilities::GetThreadCapability ()
{
#pragma message ("ToDo: multi-threaded")
    return (FdoThreadCapability_SingleThreaded);
}

/// <summary>Gets the spatial context extent types supported by the feature provider.</summary>
/// <param name="length">Output the number of spatial context types.</param> 
/// <returns>Returns the list of spatial context extent types.</returns> 
FdoSpatialContextExtentType* [!output PREFIX]ConnectionCapabilities::GetSpatialContextTypes (FdoInt32& length)
{
#pragma message ("ToDo: spatial extent types (FdoSpatialContextExtentType_Static, FdoSpatialContextExtentType_Dynamic)")
    static FdoSpatialContextExtentType types[] =
    {
        FdoSpatialContextExtentType_Static
    };

    length = sizeof(types) / sizeof(FdoSpatialContextExtentType);

    return (types);
}

/// <summary>Determines if the feature provider supports persistent locking.</summary>
/// <returns>Returns true if the feature provider supports persistent locking.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsLocking ()
{
[!if LOCKING]
    return (true);
[!else]
    return (false);
[!endif]
}

FdoLockType* [!output PREFIX]ConnectionCapabilities::GetLockTypes(FdoInt32& size)
{
[!if LOCKING]
#pragma message ("ToDo: supported lock types")
    static FdoLockType [!output PREFIX]LockTypes[] = {FdoLockType_Exclusive};
    size = sizeof([!output PREFIX]LockTypes)/sizeof(FdoLockType);
    return ([!output PREFIX]LockTypes);
[!else]
    size = 0;
    return ((FdoLockType*)NULL);
[!endif]
}

/// <summary>Determines if the feature provider supports connection timeout.</summary>
/// <returns>Returns true if the feature provider supports connection timeout.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsTimeout ()
{
    return (false);
}

/// <summary>Determines if the feature provider supports transactions.</summary>
/// <returns>Returns true if the feature provider supports transactions.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsTransactions ()
{
[!if TRANSACTIONS]
    return (true);
[!else]
    return (false);
[!endif]
}

/// <summary>Determines true if the feature provider supports long transactions.</summary>
/// <returns>Returns true if the feature provider supports long transactions.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsLongTransactions ()
{
[!if LONG_TRANSACTIONS]
    return (true);
[!else]
    return (false);
[!endif]
}

/// <summary>Determines if the feature provider supports SQL commands.</summary>
/// <returns>Returns true if the feature provider supports SQL commands.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsSQL()
{
[!if SQL]
    return (true);
[!else]
    return (false);
[!endif]
}

/// <summary>Determines if the feature provider supports XML configuration.</summary>
/// <returns>Returns true if the feature provider supports the setting of a configuration.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsConfiguration()
{
[!if XMLCONFIG]
    return (true);
[!else]
    return (false);
[!endif]
}

/// <summary>Determines if the provider supports multiple spatial contexts.
/// <returns>Returns true if the provider supports multiple spatial contexts.
bool [!output PREFIX]ConnectionCapabilities::SupportsMultipleSpatialContexts()
{
    return (false);
}

/// <summary>Determines if the provider supports specifying the coordinate system by name or ID without specifying the WKT
/// when creating a new spatial context.</summary>
/// <returns>Returns true if the provider supports specifying the coordinate system by name or ID without specifying the WKT
/// when creating a new spatial context.</returns> 
bool [!output PREFIX]ConnectionCapabilities::SupportsCSysWKTFromCSysName()
{
    return (false);
}


bool [!output PREFIX]ConnectionCapabilities::SupportsWrite()
{
[!if READ_WRITE]
    return true;
[!else]
    return false;
[!endif]
}

bool [!output PREFIX]ConnectionCapabilities::SupportsMultiUserWrite()
{
#pragma message ("ToDo: Supports multi-user write")
    return false;
}


bool [!output PREFIX]ConnectionCapabilities::SupportsFlush() 
{
#pragma message ("ToDo: Supports Flush")
    return false;
}
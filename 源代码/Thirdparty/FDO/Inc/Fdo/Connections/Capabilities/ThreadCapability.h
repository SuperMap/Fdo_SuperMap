#ifndef _THREADCAPABILITY_H_
#define _THREADCAPABILITY_H_
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef _WIN32
#pragma once
#endif

/// \ingroup (enums)
/// \brief
/// The FdoThreadCapability enumeration defines the threading capabilities of a feature provider.
enum FdoThreadCapability
{
    /// The feature provider is not thread safe.
    FdoThreadCapability_SingleThreaded,

    /// The feature provider supports a single thread per connection. Multiple concurrent threads
    /// cannot access the same connection object and only one command can be executing per
    /// connection. Multiple connections can be active concurrently as long as each is
    /// executing on its own thread.
    FdoThreadCapability_PerConnectionThreaded,

    /// The feature provider supports a single thread per command. Multiple concurrent threads
    /// cannot access the same command object; however, multiple commands can be executing
    /// concurrently against a single connection.
    FdoThreadCapability_PerCommandThreaded,

    /// The feature provider is fully multi-threaded. Concurrent thread access is safe
    /// for all objects.
    FdoThreadCapability_MultiThreaded
};
#endif



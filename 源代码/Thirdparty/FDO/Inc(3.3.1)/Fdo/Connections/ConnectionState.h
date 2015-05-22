#ifndef _CONNECTIONSTATE_H_
#define _CONNECTIONSTATE_H_
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
/// The FdoConnectionState enumeration indicates the current state of the connection
enum FdoConnectionState
{
    /// The connection is busy executing one or more commands. Executing another
    /// command while the connection is busy will result in an exception.
    FdoConnectionState_Busy,

    /// The connection is closed.
    FdoConnectionState_Closed,

    /// The connection is open.
    FdoConnectionState_Open,

    /// The connection is pending. this is used to indicate that the application has 
    /// issued an Open request, but the open is not completed because the application
    /// needs to include additional connection property values.
    FdoConnectionState_Pending
};
#endif



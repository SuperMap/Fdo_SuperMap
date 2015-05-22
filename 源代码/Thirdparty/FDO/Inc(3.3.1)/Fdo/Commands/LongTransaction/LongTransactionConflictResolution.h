#ifndef _LONGTRANSACTIONCONFLICTRESOLUTION_H_
#define _LONGTRANSACTIONCONFLICTRESOLUTION_H_
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
/// The FdoLongTransactionConflictResolution enumeration defines the list of
/// available options for resolving conflict.
enum FdoLongTransactionConflictResolution
{
    /// Indicates that the conflict cannot be resolved.
    FdoLongTransactionConflictResolution_Unresolved,

    /// Keep the data as defined in the long transaction to be committed,
    /// overwriting the data in the long transaction's parent.
    FdoLongTransactionConflictResolution_Child,

    /// Keep the data as defined in the versions parent, discarding the data
    /// as defined in the long transaction to be committed.
    FdoLongTransactionConflictResolution_Parent
};
#endif



#ifndef _CONFLICTTYPE_H_
#define _CONFLICTTYPE_H_ 
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
/// The FdoConflictType enumeration defines conflict types required to
/// identify the lock type of a conflict reported with the lock conflict reader.

enum FdoConflictType
{

    /// Identifies a reported conflict
    /// in the lock conflict reader as a lock conflict. A conflict represents a
    /// lock conflict if an object the user requests to be locked is already locked
    /// by a different user.
    FdoConflictType_LockConflict,
    /// Identifies a reported conflict
    /// in the lock conflict reader as a version conflict. A conflict represents a
    /// version conflict if an object the user requests to be locked has already been
    /// versioned.
    FdoConflictType_VersionConflict,
    /// Indicates that an unsupported or
    /// unknown conflict type has been encountered.
    FdoConflictType_Unsupported

};
#endif



#ifndef _ILOCKOWNERSREADER_H_
#define _ILOCKOWNERSREADER_H_
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

#include <FdoStd.h>

/// \brief
/// The FdoILockOwnersReader interface provides forward-only, read-only functionality
/// for identifying users. A connected user has status of lock owner even if he has
/// no locks or has released his locks.
/// \remarks
/// A reference to an
/// FdoILockOwnersReader interface is returned from the GetLockOwners command. The initial
/// position of the FdoILockOwnersReader interface is prior to the first item. Thus, you
/// must call ReadNext to begin accessing any data.
class FdoILockOwnersReader : public FdoIDisposable
{

public:

    /// \brief
    /// Gets the name of a user.
    /// 
    /// \return
    /// Returns the name of a user
    /// 
    FDO_API virtual FdoString* GetLockOwner() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the 
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoILockOwnersReader object, freeing any resources it may be
    /// holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;

};
#endif



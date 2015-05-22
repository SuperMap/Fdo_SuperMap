#ifndef _ILONGTRANSACTIONPRIVILEGEREADER_H_
#define _ILONGTRANSACTIONPRIVILEGEREADER_H_
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
/// The FdoILongTransactionPrivilegeReader interface provides forward only,
/// read-only functionality for enumerating long transaction privileges.
/// A reference to an FdoILongTransactionPrivilegeReader is returned from
/// the GetLongTransactionPrivileges command. The initial position of
/// the FdoILongTransactionPrivilegeReader is prior to the first item.
/// Thus, you must call ReadNext to begin accessing any data.
class FdoILongTransactionPrivilegeReader : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the name of the user currently being read.
    /// 
    /// \return
    /// Returns the user name
    /// 
    FDO_API virtual FdoString* GetUserName() = 0;

    /// \brief
    /// Gets the privileges granted to the user currently being read. The
    /// returned value may be any combination of the values from the
    /// FdoLongTransactionPrivileges enumeration combined via a bit-wise or
    /// operation.
    /// 
    /// \return
    /// Returns the privileges as a bit masked value based on FdoLongTransactionPrivileges enumeration
    /// 
    FDO_API virtual FdoInt32 GetPrivileges() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the
    /// reader is prior to the first item. Therefore you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoILongTransactionPrivilegesReader object, freeing any
    /// resources it may be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;
};
#endif



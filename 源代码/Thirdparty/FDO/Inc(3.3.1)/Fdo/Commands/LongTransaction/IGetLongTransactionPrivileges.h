#ifndef _IGETLONGTRANSACTIONPRIVILEGES_H_
#define _IGETLONGTRANSACTIONPRIVILEGES_H_
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
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/LongTransaction/ILongTransactionPrivilegeReader.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIGetLongTransactionPrivileges interface defines the
/// GetLongTransactionPrivileges command, which allows the user to enumerate the
/// privileges of a long transaction established for each user. The ability to 
/// successfully execute the command might be restricted by the datastore security 
/// if the long transaction doesn’t belong to the user executing the command.
class FdoIGetLongTransactionPrivileges : public FdoICommand
{
    friend class FdoIConnection;

public: 
    /// \brief
    /// Gets the name of the long transaction for which privileges should be
    /// enumerated.
    /// 
    /// \return
    /// Returns the long transaction name
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction for which privileges should be
    /// enumerated.
    /// 
    /// \param value 
    /// Input the long transaction name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Executes the GetLongTransactionPrivileges command, returning a reference
    /// to an FdoILongTransactionPrivilegeReader.
    /// 
    /// \return
    /// Returns the long transaction privilege reader.
    /// 
    FDO_API virtual FdoILongTransactionPrivilegeReader* Execute() = 0;
};
#endif



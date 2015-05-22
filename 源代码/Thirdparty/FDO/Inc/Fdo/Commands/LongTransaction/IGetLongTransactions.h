#ifndef _IGETLONGTRANSACTIONS_H_
#define _IGETLONGTRANSACTIONS_H_
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
#include <Fdo/Commands/LongTransaction/ILongTransactionReader.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIGetLongTransactions interface defines the GetLongTransactions
/// command. It allows a user to retrieve long transaction information for all or
/// a specific long transaction. The command returns a FdoILongTransactionReader
/// object enumerating the identified long transactions.
class FdoIGetLongTransactions : public FdoICommand
{
    friend class FdoIConnection;

public:

    /// \brief
    /// Sets the name of the long transaction for which information
    /// should be retrieved. The function can also be used to nullify the
    /// property by using a NULL pointer as the function's parameter. If the
    /// the property is not set, the function returns information for all
    /// available long transactions.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    /// Gets the currently set name of the long transaction for which
    /// the long transaction information should be retrieved. If the property
    /// is not set, the function returns a NULL pointer.
    /// 
    /// \return
    /// Returns a long transaction name.
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Executes the GetLongTransactions command returning a reference to an
    /// FdoILongTransactionReader.
    /// 
    /// \return
    /// Returns a long transaction reader
    /// 
    FDO_API virtual FdoILongTransactionReader* Execute() = 0;

};
#endif



#ifndef _ITRANSACTION_H_
#define _ITRANSACTION_H_
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

class FdoIConnection;

/// \brief
///  The FdoITransaction interface represents a transaction to be performed in a DataStore, and is implemented
/// by feature providers that support transactions.
class FdoITransaction : public FdoIDisposable
{
public:
    /// \brief
    ///  Gets the FdoIConnection object associated with the transaction.
    /// 
    /// \return
    /// Returns FdoIConnection object
    /// 
    FDO_API virtual FdoIConnection* GetConnection() = 0;

    /// \brief
    ///  Commits the transaction.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Commit() = 0;

    /// \brief
    ///  Rolls back a transaction from a pending state.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Rollback() = 0;
};
#endif



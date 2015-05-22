#ifndef _ICOMMAND_H_
#define _ICOMMAND_H_
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
#include <Fdo/Connections/ITransaction.h>
#include <Fdo/Commands/ParameterValueCollection.h>

class FdoIConnection;
class FdoITransaction;

/// \brief
/// The FdoICommand interface defines behavior common to all commands in FDO. In
/// order to be executed, commands must have an association to a connection.
/// Commands can also be optionally associated with a transaction if the
/// connection supports transactions. The parameter values collection allows
/// values to be specified for commands that support expressions and/or filters.
class FdoICommand : public FdoIDisposable
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the FdoIConnection that this command will operate on.
    /// 
    /// \return
    /// Returns the connection object
    /// 
    FDO_API virtual FdoIConnection* GetConnection() = 0;

    /// \brief
    /// Gets the transaction in which the command executes.
    /// 
    /// \return
    /// Returns the transaction object
    /// 
    FDO_API virtual FdoITransaction* GetTransaction() = 0;

    /// \brief
    /// Sets the transaction in which the command executes.
    /// 
    /// \param value 
    /// Input the transaction object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetTransaction(FdoITransaction* value) = 0;

    /// \brief
    /// Gets the number of milliseconds to wait before terminating the attempt
    /// to execute a command and generating an error. If the provider does not
    /// support the timeout capability, 0 is returned.
    /// 
    /// \return
    /// Returns the time (in milliseconds)
    /// 
    FDO_API virtual FdoInt32 GetCommandTimeout() = 0;

    /// \brief
    /// Sets the number of milliseconds to wait before terminating the attempt
    /// to execute a command and generating an error. If the provider does not
    /// support the timeout capability, then attempting to set a timeout will
    /// result in an exception.
    /// 
    /// \param value 
    /// Input the time (in milliseconds)
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetCommandTimeout(FdoInt32 value) = 0;

    /// \brief
    /// Returns an FdoParameterValueCollection. If the command requires parameters, the 
    /// literal values to bind to each of those named parameters must be added to
    /// this collection.
    /// 
    /// \return
    /// Returns the list of parameters and their respective values
    /// 
    FDO_API virtual FdoParameterValueCollection* GetParameterValues() = 0;

    /// \brief
    /// Validates and optimizes the command for execution. Calling this method is
    /// optional, but recommended if bound to different sets of parameters and
    /// executed multiple times.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Prepare() = 0;

    /// \brief
    /// Attempts to cancel command execution. Cancel may be called on a separate
    /// thread after the commands Execute method has been called and before 
    /// Execute has returned. If successful, an exception is thrown from the
    /// Execute method. If there is nothing to cancel, nothing happens. If
    /// command execution is in process, and the attempt to cancel fails or is
    /// not supported, an exception is thrown.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Cancel() = 0;

};
#endif



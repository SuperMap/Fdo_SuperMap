/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef FDOCOMMONCOMMAND_H
#define FDOCOMMONCOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32


template <class FDO_COMMAND, class CONNECTION_CLASS> class FdoCommonCommand : public FDO_COMMAND
{
    /// friend class CONNECTION_CLASS;

protected:
    /// The connection this command was created from.
    FdoPtr<CONNECTION_CLASS> mConnection;

protected:

    /// Constructs an instance of a command for the given connection.    
    FdoCommonCommand (FdoIConnection* connection) :
        mConnection (static_cast<CONNECTION_CLASS*>(connection))
    {
        FDO_SAFE_ADDREF (mConnection.p);
    }

    /// Default destructor for a command.
    virtual ~FdoCommonCommand() 
    { 
    }

    virtual void Dispose()
    {
        delete this;
    }

public:
    /// Gets the connection this command will operate on.
    virtual FdoIConnection* GetConnection () 
    {
        return (FDO_SAFE_ADDREF(mConnection.p));
    }

    /// Sets the connection this command will operate on.
    virtual void SetConnection (FdoIConnection* value)
    {
        mConnection = (CONNECTION_CLASS *)FDO_SAFE_ADDREF(value);
    }

    /// Gets the wait time before terminating the attempt to execute a command
    /// and generating an error.
    virtual int GetCommandTimeout ()
    {
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_100_COMMAND_TIMEOUT_NOT_SUPPORTED)));
    }

    /// Sets the wait time before terminating the attempt to execute a command
    /// and generating an error.
    virtual void SetCommandTimeout (int value)
    {
        (void)value;  // prevent compiler from complaining about unreferenced arguments
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_100_COMMAND_TIMEOUT_NOT_SUPPORTED)));
    }

    /// Gets the transaction in which the command executes.
    virtual FdoITransaction* GetTransaction ();

    /// Sets the transaction in which the command executes.
    virtual void SetTransaction (FdoITransaction* value);
 
    /// Validates and optimizes the command for execution. Calling this method is
    /// optional, but recommended if the bound to different sets of parameters and
    /// executed multiple times.
    virtual void Prepare ();

    /// Attempts to cancel command execution. Cancel may be called on a separate
    /// thread after the commands Execute method has been called and before 
    /// Execute has returned. If successful an exception will be thrown from the
    /// Execute method. If there is nothing to cancel, nothing happens. However,
    /// if command execution is in process, and the attempt to cancel fails or is
    /// not supported, no exception is generated.
    virtual void Cancel ();

    /// Returns a ParameterValueCollection. If the command requires parameters, the 
    /// literal values to bind to each of those named parameters must be added to
    /// this collection. 
    virtual FdoParameterValueCollection* GetParameterValues ();
};

// Gets the transaction in which the command executes.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
FdoITransaction* FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>::GetTransaction ()
{
    return (NULL);
}

// Sets the transaction in which the command executes.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>::SetTransaction (FdoITransaction* value)
{
    (void)value;  // avoid compile-time warning about unreference argument
}

// Validates and optimizes the command for execution. Calling this method is
// optional, but recommended if the bound to different sets of parameters and
// executed multiple times.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>::Prepare ()
{
}

// Attempts to cancel command execution. Cancel may be called on a separate
// thread after the commands Execute method has been called and before 
// Execute has returned. If successful an exception will be thrown from the
// Execute method. If there is nothing to cancel, nothing happens. However,
// if command execution is in process, and the attempt to cancel fails or is
// not supported, no exception is generated.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>::Cancel ()
{
}

// Returns a ParameterValueCollection. If the command requires parameters, the 
// literal values to bind to each of those named parameters must be added to
// this collection. 
template <class FDO_COMMAND, class CONNECTION_CLASS> 
FdoParameterValueCollection* FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>::GetParameterValues()
{
    throw FdoCommandException::Create (FdoException::NLSGetMessage(FDO_68_COMMAND_PARAMETERS_NOT_SUPPORTED, "Command parameters are not supported."));
}


#endif // FDOCOMMONCOMMAND_H



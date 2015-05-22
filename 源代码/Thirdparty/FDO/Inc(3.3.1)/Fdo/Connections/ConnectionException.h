#ifndef _CONNECTIONEXCEPTION_H_
#define _CONNECTIONEXCEPTION_H_
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
/// The FdoConnectionException class is the exception type thrown from classes in the Connections package.
/// ConnectionException derives from a language level exception class that is environment-
/// specific.
class FdoConnectionException : public FdoException
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoConnectionException.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoConnectionException();

    /// \brief
    /// Constructs an instance of an FdoConnectionException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoConnectionException(FdoString* message);

    /// \brief
    /// Constructs an instance of an FdoConnectionException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoConnectionException(FdoString* message, FdoException* cause);

    /// \brief
    /// Default destructor for FdoConnectionException class.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual ~FdoConnectionException();

    FDO_API virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Returns a default instance of an FdoConnectionException.
    /// 
    /// \return
    /// Returns FdoConnectionException
    /// 
    FDO_API static FdoConnectionException* Create();

    /// \brief
    ///  Returns an instance of an FdoConnectionException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message.
    /// 
    /// \return
    /// Returns FdoConnectionException.
    /// 
    FDO_API static FdoConnectionException* Create(FdoString* message);

    /// \brief
    ///  Returns an instance of an FdoConnectionException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message.
    /// \param cause 
    /// Input the cause of the error.
    /// 
    /// \return
    /// Returns FdoConnectionException
    /// 
    FDO_API static FdoConnectionException* Create(FdoString* message, FdoException* cause);
};
#endif



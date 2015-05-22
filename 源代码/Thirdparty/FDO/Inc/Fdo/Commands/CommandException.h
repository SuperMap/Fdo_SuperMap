#ifndef _COMMANDEXCEPTION_
#define _COMMANDEXCEPTION_
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
/// The FdoCommandException class is the exception type thrown from classes in the Data package.
/// FdoCommandException derives from a language level exception class that is environment
/// specific.
class FdoCommandException : public FdoException
{
protected:
    /// \brief
    /// Constructs a default instance of an FdoCommandException.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoCommandException();

    /// \brief
    /// Constructs an instance of an FdoCommandException using the specified arguments.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoCommandException(FdoString* message);

    /// \brief
    /// Constructs an instance of an FdoCommandException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoCommandException(FdoString* message, FdoException* cause);

    /// \brief
    ///  Default destructor for CommandException.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual ~FdoCommandException();

    /// \brief
    ///  Dispose of this object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Dispose();

public:
    /// \brief
    ///  Returns a default instance of an FdoCommandException.
    /// 
    /// \return
    /// Returns FdoCommandException object
    /// 
    FDO_API static FdoCommandException* Create();

    /// \brief
    /// Returns an instance of an FdoCommandException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// 
    /// \return
    /// Returns FdoCommandException object
    /// 
    FDO_API static FdoCommandException* Create(FdoString* message);

    /// \brief
    ///  Returns an instance of an FdoCommandException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns FdoCommandException object
    /// 
    FDO_API static FdoCommandException* Create(FdoString* message, FdoException* cause);
};

/// \ingroup (typedefs)
/// \brief
/// FdoCommandExceptionP is a FdoPtr on FdoCommandException, provided for convenience.
typedef FdoPtr<FdoCommandException> FdoCommandExceptionP;

#endif



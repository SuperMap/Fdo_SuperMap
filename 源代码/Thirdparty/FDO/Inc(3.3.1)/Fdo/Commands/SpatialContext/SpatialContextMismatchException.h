#ifndef _SPATIALCONTEXTMISMATCHEXCEPTION_H_
#define _SPATIALCONTEXTMISMATCHEXCEPTION_H_
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
/// The FdoSpatialContextMismatchException class is the exception type thrown from classes 
/// editing the datastore. It derives from a language level exception class that is
/// environment-specific. This exception is thrown whenever a command operates on a geometry 
/// whose spatial context does not match the active spatial context.
/// The message should always mention which spatial contexts were mismatched.
class FdoSpatialContextMismatchException : public FdoException
{
protected:
    /// Constructs a default instance of an FdoSpatialContextMismatchException.
    FDO_API FdoSpatialContextMismatchException();

    /// Constructs an instance of an FdoSpatialContextMismatchException using the specified
    /// arguments.
    FDO_API FdoSpatialContextMismatchException(FdoString* message);

    /// Constructs an instance of an FdoSpatialContextMismatchException using the specified
    /// arguments.
    FDO_API FdoSpatialContextMismatchException(FdoString* message, FdoException* cause);

    FDO_API virtual ~FdoSpatialContextMismatchException();

    FDO_API virtual void Dispose();

public:
    /// \brief
    /// Constructs a default instance of an FdoSpatialContextMismatchException.
    /// 
    /// \return
    /// Returns FdoSpatialContextMismatchException
    /// 
    FDO_API static FdoSpatialContextMismatchException* Create();

    /// \brief
    /// Constructs an instance of an FdoSpatialContextMismatchException using the specified arguments.
    /// 
    /// \param message 
    /// Input message text
    /// 
    /// \return
    /// Returns FdoSpatialContextMismatchException
    /// 
    FDO_API static FdoSpatialContextMismatchException* Create(FdoString* message);

    /// \brief
    /// Constructs an instance of an FdoSpatialContextMismatchException using the specified arguments.
    /// 
    /// \param message 
    /// Input name text
    /// \param cause 
    /// Input cause of exception
    /// 
    /// \return
    /// Returns FdoSpatialContextMismatchException
    /// 
    FDO_API static FdoSpatialContextMismatchException* Create(FdoString* message, FdoException* cause);
};

/// \ingroup (typedefs)
/// \brief
/// FdoSpatialContextMismatchExceptionP is a FdoPtr on FdoSpatialContextMismatchException, provided for convenience.
typedef FdoPtr<FdoSpatialContextMismatchException> FdoSpatialContextMismatchExceptionP;

#endif



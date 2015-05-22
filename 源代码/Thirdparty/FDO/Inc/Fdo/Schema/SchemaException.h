#ifndef _SCHEMAEXCEPTION_H_
#define _SCHEMAEXCEPTION_H_

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
/// The FdoSchemaException class is the exception type thrown from classes in the Schema
/// package. It derives from a language level exception class that is
/// environment-specific.
class FdoSchemaException : public FdoException
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoSchemaException.
    FdoSchemaException();

    /// Constructs an instance of an FdoSchemaException using the specified
    /// arguments.
    FdoSchemaException(FdoString* message);

    /// Constructs an instance of an FdoSchemaException using the specified
    /// arguments.
    FdoSchemaException(FdoString* message, FdoException* cause);

    virtual ~FdoSchemaException();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoSchemaException.
    /// 
    /// \return
    /// Returns FdoSchemaException
    /// 
    FDO_API static FdoSchemaException* Create();

    /// \brief
    /// Constructs an instance of an FdoSchemaException using the specified arguments.
    /// 
    /// \param message 
    /// Input message text
    /// 
    /// \return
    /// Returns FdoSchemaException
    /// 
    FDO_API static FdoSchemaException* Create(FdoString* message);

    /// \brief
    /// Constructs an instance of an FdoSchemaException using the specified arguments.
    /// 
    /// \param name 
    /// Input name text
    /// \param cause 
    /// Input cause of exception
    /// 
    /// \return
    /// Returns FdoSchemaException
    /// 
    FDO_API static FdoSchemaException* Create(FdoString* name, FdoException* cause);
};

/// \ingroup (typedefs)
/// \brief
/// FdoSchemaExceptionP is a FdoPtr on FdoSchemaException, provided for convenience.
typedef FdoPtr<FdoSchemaException> FdoSchemaExceptionP;

#endif



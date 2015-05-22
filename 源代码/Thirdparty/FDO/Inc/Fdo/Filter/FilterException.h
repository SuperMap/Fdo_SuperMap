#ifndef _FILTEREXCEPTION_H_
#define _FILTEREXCEPTION_H_
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
/// The FdoFilterException class is the exception type thrown from classes in the Filter
/// package. It derives from a language level exception class that is
/// environment-specific.
class FdoFilterException : public FdoException
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoFilterException.
    FdoFilterException();

    /// Constructs an instance of an FdoFilterException using the specified
    /// arguments.
    FdoFilterException(FdoString* message);

    /// Constructs an instance of an FdoFilterException using the specified
    /// arguments.
    FdoFilterException(FdoString* message, FdoException* cause);

    virtual ~FdoFilterException();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoFilterException.
    /// 
    /// \return
    /// Returns FdoFilterException
    /// 
    FDO_API static FdoFilterException* Create();

    /// \brief
    /// Constructs an instance of an FdoFilterException using the specified arguments.
    /// 
    /// \param message 
    /// Input message text
    /// 
    /// \return
    /// Returns FdoFilterException
    /// 
    FDO_API static FdoFilterException* Create(FdoString* message);

    /// \brief
    /// Constructs an instance of an FdoFilterException using the specified arguments.
    /// 
    /// \param message 
    /// Input message text
    /// \param cause 
    /// Input cause of exception
    /// 
    /// \return
    /// Returns FdoFilterException
    /// 
    FDO_API static FdoFilterException* Create(FdoString* message, FdoException* cause);
};
#endif



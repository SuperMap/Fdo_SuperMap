#ifndef FDO_XML_EXCEPTION_H_
#define FDO_XML_EXCEPTION_H_
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

#include <FdoCommon.h>

/// \brief
/// FdoXmlException is a root class for exception type thrown from the
/// FDO XML package
class FdoXmlException : public FdoException
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    ///  Constructs a default instance of an FdoXmlException.
    /// 
    FdoXmlException();

    /// \brief
    ///  Constructs an instance of an FdoXmlException using the specified
    /// arguments.
    /// 
    FdoXmlException(FdoString* message);

    /// \brief
    ///  Constructs an instance of an FdoXmlException using the specified
    /// arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoXmlException(FdoString* message, FdoException* cause);

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Returns a default instance of an FdoXmlException.
    /// 
    /// \return
    /// Returns FdoXmlException object
    /// 
    FDO_API_COMMON static FdoXmlException* Create();

    /// \brief
    /// Returns an instance of an FdoXmlException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// 
    /// \return
    /// Returns the Exception object
    /// 
    FDO_API_COMMON static FdoXmlException* Create(FdoString* message);

    /// \brief
    /// Returns an instance of an FdoXmlException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns FdoXmlException object
    /// 
    FDO_API_COMMON static FdoXmlException* Create(FdoString* message, FdoException* cause);

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlExceptionP is a FdoPtr on FdoXmlException, provided for convenience.
typedef FdoPtr<FdoXmlException> FdoXmlExceptionP;

#endif



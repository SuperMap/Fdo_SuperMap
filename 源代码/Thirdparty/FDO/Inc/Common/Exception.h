#ifndef _FDO_EXCEPTION_H_
#define _FDO_EXCEPTION_H_
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

#include <FdoMessage.h>
#include <stdarg.h>

#ifdef  _DEBUG
#define FDO_NLSID(x)  x, #x, __FILE__, __LINE__
#else
#define FDO_NLSID(x)  x, #x
#endif

template <class T> class FdoPtr;

/// \brief
/// FdoException is a root class for the exception type thrown from classes. It derives from a language 
/// level exception class that is environment specific.
class FdoException : public FdoIDisposable
{
protected:
    /// Constructs a default instance of a FdoException.
    FDO_API_COMMON FdoException();

    /// Constructs an instance of a FdoException using the specified arguments.
    FDO_API_COMMON FdoException(FdoString* message);

    /// Constructs an instance of a FdoException using the specified arguments.
    FDO_API_COMMON FdoException(FdoString* message, FdoException* cause);

    /// Default destructor for FdoException class.
    FDO_API_COMMON virtual ~FdoException();

/// \cond DOXYGEN-IGNORE
    virtual void Dispose();
/// \endcond

public:
    /// \brief
    ///  Returns a default instance of a FdoException.
    /// 
    /// \return
    /// Returns the FdoException object
    /// 
    FDO_API_COMMON static FdoException* Create();

    /// \brief
    /// Returns an instance of a FdoException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// 
    /// \return
    /// Returns the FdoException object
    /// 
    FDO_API_COMMON static FdoException* Create(FdoString* message);

    /// \brief
    ///  Returns an instance of a FdoException using the specified arguments.
    /// 
    /// \param message 
    /// Input the error message
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns the FdoException object
    /// 
    FDO_API_COMMON static FdoException* Create(FdoString* message, FdoException* cause);

    /// \brief
    /// Gets the message associated with this exception. If no message is
    /// associated with this exception but it has a cause, then this method
    /// returns the message specified for the cause exception. If no message and
    /// no cause are associated with this exception then a null reference is
    /// returned.
    /// 
    /// \return
    /// Returns the error message
    /// 
    FDO_API_COMMON virtual FdoString* GetExceptionMessage();

    /// \brief
    /// Gets a reference to the exception that caused this exception.
    /// 
    /// \return
    /// Returns the cause of the error
    /// 
    FDO_API_COMMON virtual FdoException* GetCause();

    /// \brief
    /// Gets a reference to the exception that is the root cause of this
    /// exception.
    /// 
    /// \return
    /// Returns the root cause for the error
    /// 
    FDO_API_COMMON virtual FdoException* GetRootCause();

    /// \brief
    /// Sets the cause exception
    /// 
    /// \param cause 
    /// Input the cause of the error
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API_COMMON virtual void SetCause( FdoException* cause );

    /// \brief
    /// Gets the message associated with this exception. If no message is
    /// associated with this exception but it has a cause, then this method
    /// returns the message specified for the cause exception. If no message and
    /// no cause are associated with this exception then a null reference is
    /// returned.
    /// 
    /// \return
    /// Returns the error message
    /// 
    FDO_API_COMMON virtual FdoString* ToString();

    /// \brief
    /// Gets the exception message. For internal use by template classes in getting a localized message.
    /// 
    /// \remarks
    /// In addition to the listed parameters, a flexible number of additional variables, as required, 
    /// can be used as input to format the exception message.
    /// 
    /// \param msgNum 
    /// Input the error message number
    /// \param defMsg 
    /// Input a text error message to use if the message number is not found
    /// \param file 
    /// Input file name where exception occurred
    /// \param line 
    /// Input the line number where exception occurred
    /// 
    /// \return
    /// Returns the localized message text
    /// 
    FDO_API_COMMON static FdoString* NLSGetMessage(FdoInt32 msgNum, char* defMsg, char* file, int line, ...);

    /// \brief
    /// Gets the exception message. For internal use by FdoException class in getting a localized message.
    /// 
    /// \param msgNum 
    /// Input the error message number
    /// \param defMsg 
    /// Input a text error message to use if the message number is not found
    /// \param file 
    /// Input file name where exception occurred
    /// \param line 
    /// Input the line number where exception occurred
    /// \param catalog 
    /// Input the NLS message catalog name.
    /// \param arguments 
    /// Input the variable argument parameters from previous call.
    /// 
    /// \return
    /// Returns the localized message text
    /// 
    FDO_API_COMMON static FdoString* NLSGetMessage(FdoInt32 msgNum, char* defMsg, char* file, int line, char* catalog, va_list arguments);

    /// \brief
    /// Gets the exception message. For internal use by template classes in getting a localized message.
    /// 
    /// \remarks
    /// In addition to the listed parameters, a flexible number of additional variables, as required, 
    /// can be used as input to format the exception message.
    /// 
    /// \param msgNum 
    /// Input the error message number
    /// \param defMsg 
    /// Input a text error message to use if the message number is not found
    /// 
    /// \return
    /// Returns the localized message text
    /// 
    FDO_API_COMMON static FdoString* NLSGetMessage(FdoInt32 msgNum, char* defMsg, ...);

    /// \brief
    /// Gets the exception message. For internal use by FdoException class in getting a localized message.
    /// 
    /// \param msgNum 
    /// Input the error message number
    /// \param defMsg 
    /// Input a text error message to use if the message number is not found
    /// \param catalog 
    /// Input the NLS message catalog name.
    /// \param arguments 
    /// Input the variable argument parameters from previous call.
    /// 
    /// \return
    /// Returns the localized message text
    /// 
    FDO_API_COMMON static FdoString* NLSGetMessage(FdoInt32 msgNum, char* defMsg, char* catalog, va_list arguments);

/// \cond DOXYGEN-IGNORE
protected:
    wchar_t*        m_message;
    FdoException*   m_cause;


/// \endcond

};

/// \ingroup (typedefs)
/// \brief
/// FdoExceptionP is a FdoPtr on FdoException, provided for convenience.
typedef FdoPtr<FdoException> FdoExceptionP;

#endif



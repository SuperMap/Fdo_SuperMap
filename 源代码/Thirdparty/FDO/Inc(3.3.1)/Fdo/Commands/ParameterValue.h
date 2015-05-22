#ifndef _PARAMETERVALUE_H_
#define _PARAMETERVALUE_H_
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
#include <Fdo/Expression/LiteralValue.h>
#include <Fdo/Expression/StringValue.h>

/// \brief
/// The FdoParameterValue class specifies a value for a particular parameter.
/// Instances of this class are used to specify a value to bind to a parameter
/// when a command is executed.
class FdoParameterValue : public FdoIDisposable
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a ParameterValue.
    FdoParameterValue();

    /// Constructs an instance of a ParameterValue using the specified arguments.
    FdoParameterValue(FdoString* name);

    /// Constructs an instance of a ParameterValue using the specified arguments.
    FdoParameterValue(FdoString* name, FdoLiteralValue* value);

    virtual ~FdoParameterValue();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoParameterValue.
    /// 
    /// \return
    /// Returns FdoParameterValue
    /// 
    FDO_API static FdoParameterValue* Create();

    /// \brief
    /// Constructs an instance of an FdoParameterValue using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoParameterValue
    /// 
    FDO_API static FdoParameterValue* Create(FdoString* name);

    /// \brief
    /// Constructs an instance of an FdoParameterValue using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param value 
    /// Input literal value
    /// 
    /// \return
    /// Returns FdoParameterValue
    /// 
    FDO_API static FdoParameterValue* Create(FdoString* name, FdoLiteralValue* value);

    /// \brief
    /// Gets the parameter name the value should bind to as a string.
    /// 
    /// \return
    /// Returns parameter name
    /// 
    FDO_API FdoString* GetName();

    /// \brief
    /// Sets the parameter name the value should bind to as a string.
    /// 
    /// \param value 
    /// Input parameter name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoString* value);

    /// \brief
    /// Gets the value to bind to the parameter as an FdoLiteralValue.
    /// 
    /// \return
    /// Returns literal value
    /// 
    FDO_API FdoLiteralValue* GetValue();

    /// \brief
    /// Sets the value to bind to the parameter as an FdoLiteralValue.
    /// 
    /// \param value 
    /// Input literal value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetValue(FdoLiteralValue* value);

    /// \brief
    /// Sets the value to bind to the parameter as a string.
    /// 
    /// \param value 
    /// Input string
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetValue(FdoString* value);

protected:
/// \cond DOXYGEN-IGNORE
    wchar_t*            m_name;
    FdoLiteralValue*    m_value;
/// \endcond
};
#endif



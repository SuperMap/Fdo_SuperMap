#ifndef _PROPERTYVALUE_H_
#define _PROPERTYVALUE_H_
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
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Expression/ValueExpression.h>
#include <Fdo/Commands/CommandException.h>
#include <Common/IStreamReader.h>

/// \brief
/// The FdoPropertyValue class represents a property name/value pair. Instances of
/// this class are used to specify or hold onto a reference to a property name
/// and the properties value.
class FdoPropertyValue : public FdoIDisposable
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoPropertyValue.
    FdoPropertyValue();

    /// Constructs an instance of an FdoPropertyValue using the specified arguments.
    FdoPropertyValue(FdoIdentifier* name, FdoValueExpression* value = NULL);

    /// Constructs an instance of an FdoPropertyValue using the specified arguments.
    FdoPropertyValue(FdoString* name, FdoValueExpression* value = NULL);

    virtual ~FdoPropertyValue();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoPropertyValue.
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API static FdoPropertyValue* Create();

    /// \brief
    /// Constructs an instance of an FdoPropertyValue using the specified arguments.
    /// 
    /// \param name 
    /// Input property name as identifier
    /// \param value 
    /// Input value of property
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API static FdoPropertyValue* Create(FdoIdentifier* name, FdoValueExpression* value);

    /// \brief
    /// Constructs an instance of an FdoPropertyValue using the specified arguments.
    /// 
    /// \param name 
    /// Input property name as a string
    /// \param value 
    /// Input value of property
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API static FdoPropertyValue* Create(FdoString* name, FdoValueExpression* value);

    /// \brief
    /// Gets the property name as an identifier.
    /// 
    /// \return
    /// Returns identifier
    /// 
    FDO_API FdoIdentifier* GetName();

    /// \brief
    /// Sets the property name as an identifier.
    /// 
    /// \param value 
    /// Input identifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoIdentifier* value);

    /// \brief
    /// Sets the property name as a string.
    /// 
    /// \param value 
    /// Input string
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoString* value);

    /// \brief
    /// Gets the value of the property as an FdoValueExpression.
    /// 
    /// \return
    /// Returns FdoValueExpression
    /// 
    FDO_API FdoValueExpression* GetValue();

    /// \brief
    /// Sets the value of the property as an FdoValueExpression.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetValue(FdoValueExpression* value);

    /// \brief
    /// Sets the value of the property as a string. The string content 
    /// will be parsed to produce the required FdoValueExpression.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetValue(FdoString* value);

    /// \brief
    /// Provides a Reader on a external data source to allow reading 
    /// in blocks of data.
    /// 
    /// \param stream 
    /// Input reference to a stream reader
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void  SetStreamReader(FdoIStreamReader *stream); 

    /// \brief
    /// Gets the value of the property as an Stream Reader.
    /// 
    /// \return
    /// Returns FdoIStreamReader
    /// 
    FDO_API FdoIStreamReader* GetStreamReader();

private:
    FdoValueExpression      *m_Value;
    FdoIdentifier           *m_Name;
    FdoIStreamReader        *m_StreamReader;
};
#endif



#ifndef _IDENTIFIER_H_
#define _IDENTIFIER_H_
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
#include <Fdo/Expression/Expression.h>

/// \brief
/// The FdoIdentifier class derives from FdoExpression and represents an 
/// identifier, such as a class name or property name. Identifiers can be just a name 
/// or they can be scoped to a particular context. For example, consider a Person class 
/// that has a DataProperty called "Name" and a ClassProperty called "Address". 
/// The Address class has DataProperties "Street", "City", and "Zip Code". When manipulating 
/// instances of a Person, the "Name" property can be referred to by the property name "Name". 
/// The "City" property is scoped inside the "Address" property, hence must be referred to by the 
/// property name "Address.City".
class FdoIdentifier : public FdoExpression
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an identifier.
    FdoIdentifier();

    /// Constructs an instance of an identifier using the specified arguments.
    FdoIdentifier(FdoString* text);

    /// Default destructor for identifier.
    virtual ~FdoIdentifier();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an identifier.
    /// 
    /// \return
    /// Returns the FdoIdentifier
    /// 
    FDO_API static FdoIdentifier* Create();

    /// \brief
    /// Constructs an instance of an identifier using the specified arguments.
    /// 
    /// \param text 
    /// Input identifier text
    /// 
    /// \return
    /// Returns the FdoIdentifier
    /// 
    FDO_API static FdoIdentifier* Create(FdoString* text);

    /// \brief
    /// Gets the full text of the identifier.
    /// 
    /// \return
    /// Returns the identifier text
    /// 
    FDO_API FdoString* GetText();

    /// \brief
    /// Sets the full text of the identifier.
    /// 
    /// \param value 
    /// Input identifier text
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetText(FdoString* value);

    /// \brief
    /// Gets just the name of the identifier, with any scope stripped off.
    /// 
    /// \return
    /// Returns the name of the identifier
    /// 
    FDO_API FdoString* GetName();

    /// \brief
    /// Gets the scope of the identifier as an array of strings.
    /// 
    /// \param length 
    /// Output number of strings
    /// 
    /// \return
    /// Returns scope as array of strings
    /// 
    FDO_API FdoString** GetScope(FdoInt32& length);

    /// \brief
    /// Gets the schema name part of the identifier.
    /// 
    /// \return
    /// Returns the schema name or an empty string if the schema is not part of the identifier
    /// 
    FDO_API FdoString* GetSchemaName();

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoIdentifier to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input expression processor interface
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    FDO_API virtual FdoString* ToString();

private:
    wchar_t*    m_text;
    wchar_t*    m_name;
    wchar_t**   m_scope;
    wchar_t*    m_schemaName;
    FdoInt32    m_scopelen;
    bool        generateScope;
    bool        generateName;
    bool        generateSchemaName;
};
#endif



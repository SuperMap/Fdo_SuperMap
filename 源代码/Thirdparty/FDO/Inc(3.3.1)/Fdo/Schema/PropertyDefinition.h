#ifndef _PROPERTYDEFINITION_H_
#define _PROPERTYDEFINITION_H_

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
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/SchemaElement.h>

/// \brief
/// FdoPropertyDefinition is an abstract class that derives from FdoSchemaElement.
/// FdoPropertyDefinition is the base class of FdoDataPropertyDefinition, 
/// FdoGeometricPropertyDefinition, and FdoObjectPropertyDefinition.
class FdoPropertyDefinition : public FdoSchemaElement
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a PropertyDefinition.
    FdoPropertyDefinition();

    /// Constructs an instance of a PropertyDefinition using the specified
    /// arguments.
    FdoPropertyDefinition(FdoString* name, FdoString* description, bool system = false);

    virtual ~FdoPropertyDefinition();
/// \endcond

public:
    /// \brief
    /// Abstract operation that must be implemented by derived classes to return the concrete property type.
    /// 
    /// \return
    /// Returns the property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType() = 0;

    /// \brief
    /// Gets the fully qualified name of this property
    /// 
    /// \return
    /// Returns {schema_name}:{class_name}.{property_name}
    /// 
    FDO_API virtual FdoStringP GetQualifiedName();

    /// \brief
    /// Returns a Boolean value that indicates if this is a system generated property.
    /// 
    /// \return
    /// Returns true if this property is system generated, false otherwise.
    /// 
    /// System properties are not written out to the XML schema file, which remains provider-portable.
    FDO_API virtual bool GetIsSystem();

    /// \brief
    /// Sets whether this is a system property.
    /// This function must only be called by an FDO Provider. Typically, it would be 
    /// called by the DescribeSchema command implementation.
    /// 
    /// \param value 
    /// Input true if this is a system property.
    /// 
    FDO_API virtual void SetIsSystem( bool value );

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML and Schema Merge support

    /// Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);
    virtual void InitFromXml(FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );

protected:
    bool    m_system;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoPropertyP is a FdoPtr on FdoPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoPropertyDefinition> FdoPropertyP;

#endif



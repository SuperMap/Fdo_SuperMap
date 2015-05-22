#ifndef _OBJECTPROPERTYDEFINITION_H_
#define _OBJECTPROPERTYDEFINITION_H_

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
#include <Fdo/Schema/PropertyDefinition.h>
#include <Fdo/Schema/ObjectType.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/OrderType.h>
#include <Fdo/Schema/DataPropertyDefinition.h>

/// \brief
/// The FdoObjectPropertyDefinition class derives from FdoPropertyDefinition and represents
/// containment of an object or a collection of objects within another class.
/// The class of the contained object must already be defined in the feature
/// schema and cannot be abstract.
class FdoObjectPropertyDefinition : public FdoPropertyDefinition
{
protected:
    /// Constructs a default instance of an FdoObjectPropertyDefinition. 
    FDO_API FdoObjectPropertyDefinition();

    /// Constructs an instance of an FdoObjectPropertyDefinition using the specified
    /// arguments.
    FDO_API FdoObjectPropertyDefinition(FdoString* name, FdoString* description, bool system = false);

/// \cond DOXYGEN-IGNORE
    virtual ~FdoObjectPropertyDefinition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoObjectPropertyDefinition.
    /// 
    /// \return
    /// Returns FdoObjectPropertyDefinition
    /// 
    FDO_API static FdoObjectPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoObjectPropertyDefinition using the specified
    /// arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// \param system 
    /// Input true if this is a system generated property, otherwise false.
    /// \note
	/// A client would never set system to true, only a provider.
    /// 
    /// \return
    /// Returns FdoObjectPropertyDefinition
    /// 
    FDO_API static FdoObjectPropertyDefinition* Create(FdoString* name, FdoString* description, bool system = false);

    /// \brief
    /// Gets the concrete property type.
    /// 
    /// \return
    /// Returns the concrete property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType();

    /// \brief
    /// Gets a reference to the FdoClassDefinition that defines the type of this
    /// property.
    /// 
    /// \return
    /// Returns class definition
    /// 
    FDO_API FdoClassDefinition* GetClass();

    /// \brief
    /// Sets a reference to the FdoClassDefinition that defines the type of this
    /// property.
    /// 
    /// \param value 
    /// Input class definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetClass(FdoClassDefinition* value);

    /// \brief
    /// Gets a reference to an FdoDataPropertyDefinition to use for uniquely identifying
    /// instances of the contained class within a single parent object instance.
    /// This value is only used for the FdoObjectType_Collection and FdoObjectType_OrderedCollection object
    /// property types. The FdoDataPropertyDefinition must belong to the FdoClassDefinition that
    /// defines the type of this property.
    /// 
    /// \return
    /// Returns data property definition
    /// 
    FDO_API FdoDataPropertyDefinition* GetIdentityProperty();

    /// \brief
    /// Sets a reference to an FdoDataPropertyDefinition to use for uniquely identifying
    /// instances of the contained class within a single parent object instance.
    /// This value is only used for the FdoObjectType_Collection and FdoObjectType_OrderedCollection object
    /// property types. The FdoDataPropertyDefinition must belong to the FdoClassDefinition that
    /// defines the type of this property.
    /// 
    /// \param value 
    /// Input data property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetIdentityProperty(FdoDataPropertyDefinition* value);

    /// \brief
    /// Gets the type of this object property (value, collection, or ordered 
    /// collection).
    /// 
    /// \return
    /// Returns the type of this object property
    /// 
    FDO_API FdoObjectType GetObjectType();

    /// \brief
    /// Sets the type of this object property (value, collection, or ordered 
    /// collection).
    /// 
    /// \param value 
    /// Input the type of this object property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetObjectType(FdoObjectType value);

    /// \brief
    /// Gets the order type of this object property (ascending or descending). 
    /// This property is only applicable if the property type is set to 
    /// FdoObjectType_OrderedCollection.
    /// 
    /// \return
    /// Returns the order type
    /// 
    FDO_API FdoOrderType GetOrderType();

    /// \brief
    /// Sets the order type of this object property (ascending or descending). 
    /// This property is only applicable if the property type is set to 
    /// FdoObjectType_OrderedCollection.
    /// 
    /// \param value 
    /// Input the order type
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOrderType(FdoOrderType value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the object property class or any 
    // identity property are marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );

private:
    FdoClassDefinition*         m_class;
    FdoObjectType               m_objectType;
    FdoOrderType                m_orderType;
    FdoDataPropertyDefinition*  m_identityProperty;

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoClassDefinition*         m_classCHANGED;
    FdoObjectType               m_objectTypeCHANGED;
    FdoOrderType                m_orderTypeCHANGED;
    FdoDataPropertyDefinition*  m_identityPropertyCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoObjectPropertyP is a FdoPtr on FdoObjectPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoObjectPropertyDefinition> FdoObjectPropertyP;


#endif



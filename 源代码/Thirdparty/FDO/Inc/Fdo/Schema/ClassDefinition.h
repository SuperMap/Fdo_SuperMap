#ifndef _CLASSDEFINITION_H_
#define _CLASSDEFINITION_H_

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
#include <Fdo/Schema/ClassCapabilities.h>
#include <Fdo/Schema/ClassType.h>
#include <Fdo/Schema/DataPropertyDefinitionCollection.h>
#include <Fdo/Schema/PropertyDefinitionCollection.h>
#include <Fdo/Schema/ReadOnlyPropertyDefinitionCollection.h>
#include <Fdo/Schema/ReadOnlyDataPropertyDefinitionCollection.h>
#include <Fdo/Schema/UniqueConstraintCollection.h>

class FdoReadOnlyPropertyDefinitionCollection;
class FdoReadOnlyDataPropertyDefinitionCollection;
class FdoIDisposableCollection;
class FdoUniqueConstraintCollection;

/// \brief
/// FdoClassDefinition is an abstract class that derives from FdoSchemaElement.
/// FdoClassDefinition is a base class for all concrete class types (e.g., FdoClass,
/// FdoFeatureClass) in the Schema package.
class FdoClassDefinition : public FdoSchemaElement
{
    template <class OBJ> friend class FdoSchemaCollection;
    friend class FdoRelationEnd;
    friend class FdoRelation;
    friend class FdoObjectPropertyDefinition;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a ClassDefinition.
    FdoClassDefinition();

    /// Constructs an instance of a ClassDefinition using the specified
    /// arguments.
    FdoClassDefinition(FdoString* name, FdoString* description);

    virtual ~FdoClassDefinition();
/// \endcond

public:
    /// \brief
    /// This is an abstract operation that must be implemented by derived classes to return
    /// the concrete class type.
    /// 
    /// \return
    /// Returns FdoClassType
    /// 
    FDO_API virtual FdoClassType GetClassType();

    /// \brief
    /// Gets the base FdoClassDefinition this class is derived from.
    /// 
    /// \return
    /// Returns the base FdoClassDefinition
    /// 
    FDO_API FdoClassDefinition* GetBaseClass();

    /// \brief
    /// Sets the base FdoClassDefinition this class is derived from.
    /// 
    /// \param value 
    /// Input FdoClassDefinition this class is derived from
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetBaseClass(FdoClassDefinition* value);

    /// \brief
    /// Gets the abstraction state of the FdoClassDefinition. Classes marked as abstract
    /// cannot be created via FDO commands and cannot be used as properties of
    /// another class.
    /// 
    /// \return
    /// Returns if the FdoClassDefinition is abstract
    /// 
    FDO_API bool GetIsAbstract();

    /// \brief
    /// Sets the abstraction state of the FdoClassDefinition. Classes marked as abstract
    /// cannot be created via FDO commands and cannot be used as properties of
    /// another class.
    /// 
    /// \param value 
    /// Input the abstraction state
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetIsAbstract(bool value);

    /// \brief
    /// Sets the base properties of this class.  All elements of the 
    /// input collection must also be properties of the class.
    /// 
    /// \param value 
    /// Input collection of FdoPropertyDefinition values
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetBaseProperties(FdoPropertyDefinitionCollection* value);

    /// \brief
    /// Returns an FdoReadOnlyPropertyDefinitionCollection containing the properties
    /// defined by base classes or by the concrete class type, itself. This
    /// collection is only populated when the FdoClassDefinition is returned by the
    /// DescribeSchema command.
    /// 
    /// \return
    /// Returns FdoReadOnlyPropertyDefinitionCollection
    /// 
    FDO_API FdoReadOnlyPropertyDefinitionCollection* GetBaseProperties();

    /// \brief
    /// Returns an FdoDataPropertyDefinitionCollection containing references to the
    /// data properties that can be used to uniquely identify instances of the
    /// class. The contained properties must already be defined in either the
    /// properties or baseProperties collection. If GetBaseClass() returns non
    /// null then this collection must be empty.
    /// 
    /// \return
    /// Returns DataPropertyDefinitionCollection
    /// 
    FDO_API FdoDataPropertyDefinitionCollection* GetIdentityProperties();

    /// \brief
    /// Returns an FdoReadOnlyDataPropertyDefinitionCollection containing the identity
    /// properties for the base class.
    /// 
    /// \return
    /// Returns ReadOnlyDataPropertyDefinitionCollection
    /// 
    FDO_API FdoReadOnlyDataPropertyDefinitionCollection* GetBaseIdentityProperties();

    /// \brief
    /// Returns an FdoPropertyCollection containing the FdoDataProperties,
    /// FdoClassProperties, and FdoGeometricProperties defined for this class.
    /// 
    /// \return
    /// Returns FdoPropertyDefinitionCollection
    /// 
    FDO_API FdoPropertyDefinitionCollection* GetProperties();

    /// \brief
    /// Gets the fully qualified name of this class
    /// 
    /// \return
    /// Returns {schema_name}:{class_name}
    /// 
    FDO_API virtual FdoStringP GetQualifiedName();

    /// \brief
    /// Gets the computed state of the FdoClassDefinition. Computed classes cannot be made persistent or added to 
    /// FDO schema. The computed classes are used as a transient classes that can be returned by a feature or data reader. 
    /// They describe the result of a select expression, select function and select distinct.
    /// 
    /// \return
    /// Returns if the FdoClassDefinition is a computed class
    /// 
    FDO_API bool GetIsComputed();

    /// \brief
    /// Sets the computed state of the FdoClassDefinition. This is an internal method that 
    /// can only be called by providers. Application should not use this method.
    /// 
    /// \param value 
    /// Input the computed state
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetIsComputed(bool value);

    /// \brief
    /// Gets the class-specific capabilities for this class.
    /// 
    /// \return
    /// Returns the capabilities. The Class Capabilities are connection
    /// datastore dependent so they are only defined when this object was 
    /// created by a DescribeSchema command. The returned capabilities are the
    /// ones for this command's connection.
    /// Returns NULL if this object was not created by a DescribeSchema command.
    /// 
    FDO_API FdoClassCapabilities* GetCapabilities();

    /// \brief
    /// Sets the class-specific capabilities for this class.
    /// This function must only be called by an FDO Provider. It would be 
    /// typically called by the DescribeSchema command implementation.
    /// 
    /// \param capabilities 
    /// Input the class capabilities.
    /// 
    FDO_API void SetCapabilities(FdoClassCapabilities* capabilities);

    /// \brief
    /// Gets a FdoUniqueConstraintCollection containing all unique constraints applied to properties of this class.
    /// The contained properties must already be defined in either the
    /// properties or baseProperties collections.
    /// 
    /// \return
    /// A FdoUniqueConstraintCollection containing all unique constraints defined for properties of this class.
    /// 
    FDO_API FdoUniqueConstraintCollection* GetUniqueConstraints();

/// \cond DOXYGEN-IGNORE

    // Public non-API functions for XML and Schema Merge support

    // Update a class definition from the given definition.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the base class or any identity properties
    // are marked for delete.
    // Also checks references for each class property.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize the class from its XML attributes
    virtual void InitFromXml(const FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);
    virtual void InitFromXml(FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Handle sub-elements such as properties
    /// Element start
    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    /// Element end
    virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );

    /// Serialize this class to XML.
  	virtual void _writeXml( FdoSchemaXmlContext* pContext );

    /// Serialize the base properties ( properties from base classes )
    /// These functions are only called for classes that are represented in XML
    /// by a complexType restriction.

    /// Wrap base properties in <BaseProperties> element
    void writeXmlBaseProperties( FdoSchemaXmlContext* pContext );
    /// Just write base properties, don't wrap them.
    void _writeXmlBaseProperties( FdoSchemaXmlContext* pContext );

private:
    bool                                        m_isAbstract;
    FdoClassDefinition*                         m_baseClass;
    FdoReadOnlyPropertyDefinitionCollection*    m_baseProperties;
    FdoDataPropertyDefinitionCollection*        m_identityProperties;
    FdoPropertyDefinitionCollection*            m_properties;
	FdoUniqueConstraintCollection*				m_uniqueConstraints;

    FdoStringsP                                 m_idPropNames;
	FdoStringsP                                 m_consPropNames; 

    bool                                        m_bProperties;

    /// This is a special property that is used by non-persisted classes only.
    bool                                        m_isComputed; 

    FdoClassCapabilitiesP                       m_capabilities;

    FdoStringsP                                 m_propNameScopes;
    FdoBoolean                                  m_bFirstAssocSubProp;

    /// Initialize the private members of this class (avoid duplication in multiple constructors):
    void Init();

protected:
    /// Notification method called whenever a property of this element is removed
    virtual void PropertyRemoved(const FdoPropertyDefinition* property);

    /// Is this a property of this element?
    virtual bool IsProperty(const FdoPropertyDefinition* property);

    /// Does this class have a base class?
    virtual bool IsSubClass();

    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    bool                                        m_isAbstractCHANGED;
    FdoClassDefinition*                         m_baseClassCHANGED;
    FdoReadOnlyPropertyDefinitionCollection*    m_basePropertiesCHANGED;
	FdoUniqueConstraintCollection*				m_uniqueConstraintsCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoClassDefinitionP is a FdoPtr on FdoClassDefinition, provided for convenience.
typedef FdoPtr<FdoClassDefinition> FdoClassDefinitionP;

#endif



#ifndef _ASSOCIATIONPROPERTYDEFINITION_H_
#define _ASSOCIATIONPROPERTYDEFINITION_H_

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
#include <Fdo/Schema/DeleteRule.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/DataPropertyDefinitionCollection.h>

/// \brief
/// The FdoAssociationPropertyDefinition class derives from FdoPropertyDefinition and represents
/// the association between two classes.
/// The class of the associated class must already be defined in the feature
/// schema and cannot be abstract.
class FdoAssociationPropertyDefinition : public FdoPropertyDefinition
{
protected:
    /// Constructs a default instance of an FdoAssociationPropertyDefinition. 
    FDO_API FdoAssociationPropertyDefinition();

    /// Constructs an instance of an FdoAssociationPropertyDefinition using the specified
    /// arguments.
    FDO_API FdoAssociationPropertyDefinition(FdoString* name, FdoString* description, bool system = false);
/// \cond DOXYGEN-IGNORE
    virtual ~FdoAssociationPropertyDefinition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoAssociationPropertyDefinition.
    /// 
    /// \return
    /// Returns FdoAssociationPropertyDefinition
    /// 
    FDO_API static FdoAssociationPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoAssociationPropertyDefinition using the specified
    /// arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// \param system 
    /// Input true if this is a system generated property, false otherwise.
    /// \note
	/// A client would never set system to true, only a provider.
    /// 
    /// \return
    /// Returns FdoAssociationPropertyDefinition
    /// 
    FDO_API static FdoAssociationPropertyDefinition* Create(FdoString* name, FdoString* description, bool system = false);

    /// \brief
    /// Gets the concrete property type.
    /// 
    /// \return
    /// Returns the concrete property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType();

    /// \brief
    /// Gets a reference to the associated class.
    /// 
    /// \return
    /// Returns class definition
    /// 
    FDO_API FdoClassDefinition* GetAssociatedClass();

    /// \brief
    /// Sets a reference to the associated class.
    /// 
    /// \param value 
    /// Input class definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetAssociatedClass(FdoClassDefinition* value);

    /// \brief
    /// Gets a reference to an FdoDataPropertyDefinitionCollection which is a collection of 
    /// properties of the current class that are used as key for this association. Initially, this 
    /// collection is empty. The user can optionally add any number of properties.  If the collection 
    /// is left empty, the identity properties of the associated class are added to the current class. 
    /// The number, order and types should match the property of the ReverseIdentityProperties collection. 
    /// All properties in the collection should already exist in the containing class. 
    /// This is needed in case the current class already has properties (foreign keys) that are used 
    /// to reference the associated feature.
    /// 
    /// \return
    /// Returns data property definition
    /// 
    FDO_API FdoDataPropertyDefinitionCollection* GetIdentityProperties();

    /// \brief
    /// Gets a reference to an FdoDataPropertyDefinitionCollection used to return a collection 
    /// of properties of the associated class that are used as key for this association. 
    /// The number, order and types should match the IdentityProperties. If the reverse identity 
    /// collection is empty, then the associated class identity properties will be used. 
    /// The properties of the collection should already exist on the associated class.
    /// 
    /// \return
    /// Returns data property definition
    /// 
    FDO_API FdoDataPropertyDefinitionCollection* GetReverseIdentityProperties();

    /// \brief
    /// Gets the reverse name of this property. See description of SetReverseName.
    /// 
    /// \return
    /// Returns the reverse name
    /// 
    FDO_API FdoString* GetReverseName();

    /// \brief
    /// This method is used to set the name of this association as seen by the associated 
    /// class. This is an optional parameter that can be provided if the navigation back from the 
    /// associated class is needed. This property will appear as read-only property on the associated 
    /// class. For example let's assume that we have an Accident class that associated to a Road class 
    /// by an association called Road? If we wanted to find all the accidents associated to a given 
    /// road, we will need to provide a reverse property name of the road association property. 
    /// In this case an appropriate value for such a name would be accident. The filter that can be 
    /// used to find all the accidents would look like: accident not null.
    /// 
    /// \param name 
    /// Input reverse name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetReverseName(FdoString* name);

    /// \brief
    /// Gets the delete rule.
    /// 
    /// \return
    /// Returns the delete rule
    /// 
    FDO_API FdoDeleteRule GetDeleteRule();

    /// \brief
    /// Sets the delete rule.
    /// 
    /// \param value 
    /// Input the delete rule
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDeleteRule(FdoDeleteRule value);

    /// \brief
    /// Gets the lock cascade option. true to cascade the lock otherwise the lock is not cascaded
    /// 
    /// \return
    /// Returns the lock cascade option
    /// 
    FDO_API bool GetLockCascade();

    /// \brief
    /// Sets the lock cascade option.
    /// 
    /// \param value 
    /// Input the lock cascade option.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLockCascade(bool value);

    /// \brief
    /// This method is used to verify if this association property is a read-only association 
    /// property. A read-only association property is created internally when the reverse name of an 
    /// association property is specified. The read-only association property is added automatically 
    /// to the associated class and can be used to navigate from the associated class to the 
    /// associating class
    /// 
    /// \return
    /// Returns true if the association property is read-only. otherwise false.
    /// 
    FDO_API bool GetIsReadOnly();

    /// \brief
    /// This method is used to set the read-only status of the association property. 
    /// This method should only be called by FDO providers to set to read-only the association 
    /// property added internally to the associated class that represent the reverse association 
    /// property.
    /// 
    /// \param value 
    /// Input the read-only flag
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDO_API  void SetIsReadOnly(bool value);

    /// \brief
    /// This method is used to return the association multiplicity from the owner class 
    /// side. See SetMultiplicity method for description of the possible values.
    /// 
    /// \return
    /// Returns a FdoString that represent the multiplicity.
    /// 
    FDO_API FdoString* GetMultiplicity();

    /// \brief
    /// This method is used to set the association multiplicity from the property owner class side. 
    /// The only possible values are 1 or m. If the multiplicity is set to 1, then only one instance
    /// of the owning class can be associated to a given instance of the associated class. If the 
    /// multiplicity is set to m, then many instances of the owning class can be associated to the 
    /// same instance of the associated class.
    /// 
    /// \param value 
    /// The multiplicity from the property owner class side. Valid values are:  1 or m.
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDO_API  void SetMultiplicity(FdoString* value);

    /// \brief
    /// This method is used to return the association multiplicity from the associated class 
    /// side. See SetReverseMultiplicity method for description of the possible values.
    /// 
    /// \return
    /// Returns a FdoString that represent the reverse multiplicity.
    /// 
    FDO_API FdoString* GetReverseMultiplicity();

    /// \brief
    /// This method is used to set the association multiplicity from the associated class side.
    /// The only possible values are 0 or 1. If the multiplicity is set to 0, then it is not mandatory 
    /// to initialize the association property when a new object is created. If the multiplicity is 
    /// set to 1, then the association property must be initialized when a new object is created.
    /// 
    /// \param value 
    /// The multiplicity from the associated class side. Valid values are:  0 or 1.
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDO_API  void SetReverseMultiplicity(FdoString* value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the associated class or any 
    // association identity properties are marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

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

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );

    virtual void SetParent(FdoSchemaElement* value);

private:
    void CheckIdentityReferences( FdoSchemaMergeContext* pContext, FdoDataPropertyDefinitionCollection* idProps, long messageId );
    
    wchar_t*                                m_reverseName;
    FdoClassDefinition*                     m_associatedClass;
    FdoDeleteRule                           m_deleteRule;
    bool                                    m_lockCascade;
    bool                                    m_isReadOnly;
    wchar_t*                                m_multiplicity;
    wchar_t*                                m_reverseMultiplicity;
    FdoDataPropertyDefinitionCollection*    m_identityProperties;
    FdoDataPropertyDefinitionCollection*    m_identityReverseProperties;

    FdoStringsP                             m_idPropNames;
    FdoStringsP                             m_idRvrsPropNames;
    FdoDataPropertyDefinition*              m_dataPropertyHandler;
    bool                                    m_Default;

private:
    FdoString* DeleteRuleToString(FdoDeleteRule rule);
    FdoDeleteRule StringToDeleteRule(FdoString *string);

    /// Used to add a read-only association property to the associated class.
    void ModifyAssociatedClass();

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoClassDefinition*                     m_associatedClassCHANGED;
    FdoDeleteRule                           m_deleteRuleCHANGED;
    bool                                    m_lockCascadeCHANGED;
    bool                                    m_isReadOnlyCHANGED;
    wchar_t*                                m_multiplicityCHANGED;
    wchar_t*                                m_reverseMultiplicityCHANGED;
    wchar_t*                                m_reverseNameCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoAssociationPropertyP is a FdoPtr on FdoAssociationPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoAssociationPropertyDefinition> FdoAssociationPropertyP;

#endif



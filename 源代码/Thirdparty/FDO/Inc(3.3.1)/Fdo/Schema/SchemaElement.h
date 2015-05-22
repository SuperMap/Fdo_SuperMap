#ifndef _SCHEMAELEMENT_H_
#define _SCHEMAELEMENT_H_

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
#include <Fdo/Schema/SchemaAttributeDictionary.h>
#include <Fdo/Schema/SchemaElementState.h>

class FdoFeatureSchema;
class FdoPropertyDefinition;
class FdoSchemaMergeContext;
class FdoSchemaXmlContext;
class FdoSchemaXmlError;

template <class OBJ> class FdoSchemaCollection;

/// \brief
/// FdoSchemaElement is an abstract class that acts as a base class for all classes
/// in the Schema package.
class FdoSchemaElement : 
    public FdoIDisposable,
    public virtual FdoXmlSaxHandler
{
    friend class FdoFeatureSchema;
    template <class OBJ> friend class FdoSchemaCollection;
    friend class FdoSchemaAttributeDictionary;
    friend class FdoPropertyDefinitionCollection;
    friend class FdoDataPropertyDefinitionCollection;
    friend class FdoNetworkNodeFeatureClass;
    friend class FdoNetworkFeatureClass;
    friend class FdoNetworkLinkFeatureClass;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoSchemaElement.
    FdoSchemaElement();

    /// Constructs an instance of an FdoSchemaElement using the specified arguments.
    FdoSchemaElement(FdoString* name, FdoString* description);

    virtual ~FdoSchemaElement();

    /// Write this element to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );
/// \endcond

public:
    /// \brief
    /// Gets the parent of this FdoSchemaElement or null if this object has not
    /// been added to a parent object.
    /// 
    /// \return
    /// Returns FdoSchemaElement of parent
    /// 
    FDO_API virtual FdoSchemaElement* GetParent();

    /// \brief
    /// Gets the FdoFeatureSchema this object is a part of. Returns null if this
    /// object has not been added to a feature schema.
    /// 
    /// \return
    /// Returns FdoFeatureSchema this object is a part of
    /// 
    FDO_API virtual FdoFeatureSchema* GetFeatureSchema();

    /// \brief
    /// Returns the current state of the schema element.
    /// 
    /// \return
    /// Returns the current state of the schema element
    /// 
    FDO_API FdoSchemaElementState GetElementState();

    /// \brief
    /// Gets an FdoSchemaAttributeDictionary that contains the attributes 
    /// associated with this FdoSchemaElement.
    /// 
    /// \return
    /// Returns an FdoSchemaAttributeDictionary
    /// 
    FDO_API FdoSchemaAttributeDictionary* GetAttributes();

    /// \brief
    /// Gets the name of the schema object.
    /// 
    /// \return
    /// Returns the name of the schema object
    /// 
    FDO_API virtual FdoString* GetName();

    /// \brief
    /// Gets the fully qualified name of this schema element
    /// 
    /// \return
    /// Default implementation simply returns the element name
    /// 
    FDO_API virtual FdoStringP GetQualifiedName();

    /// \brief
    /// Sets the name of the schema object.
    /// 
    /// \param value 
    /// Input the name of the schema object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value);

    /// \brief
    /// Indicates that this object allows its name
    /// to change. This function is defined so that this class can 
    /// be a FdoNamedCollection element.
    /// 
    /// \return
    /// Returns true
    /// 
    FDO_API virtual FdoBoolean CanSetName()
    {
        return true;
    }


    /// \brief
    /// Gets the description of the schema object.
    /// 
    /// \return
    /// Returns the description of the schema object
    /// 
    FDO_API virtual FdoString* GetDescription();

    /// \brief
    /// Sets the description of the schema object.
    /// 
    /// \param value 
    /// Input the description of the schema object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetDescription(FdoString* value);

    /// \brief
    /// Marks the schema element for deletion by setting the element state to
    /// FdoSchemaElementState_Deleted. If the schema elements current state is
    /// FdoSchemaElementState_Added then the element is physically removed. If
    /// the current state is FdoSchemaElementState_Detached this method does
    /// nothing.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Delete();

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Modification support

    // Update a schema element from the given element.
    virtual void Set( FdoSchemaElement* pElement, FdoSchemaMergeContext* pContext );

    // Checks referenced elements and adds errors if any are deleted. 
    // Does nothing.
    // Sub-classes must override this function if specific references need to be checked.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Handle the start of a sub-element
    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    /// Handle the end of a sub-element
    virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );

protected:
    /// Sets the parent of this SchemaObject. Can only be called from within the
    /// Schema package.
    virtual void SetParent(FdoSchemaElement* value);

    /// Sets the current state of the schema element. This is a package private
    /// method that can only be called from within the Schema package.
    void SetElementState(FdoSchemaElementState value);

    /// Notification method called whenever a property of this element is removed
    virtual void PropertyRemoved(const FdoPropertyDefinition* property);

    /// Is this a property of this element?
    virtual bool IsProperty(const FdoPropertyDefinition* property);

    /// Does this element have a base class?
    virtual bool IsSubClass();

    /// Throws an exception if the given name is not a valid 
    /// schema element name.
    void VldName( FdoString* name );

private:
    FdoSchemaElement*               m_parent;

    /// The name of the schema object. This name is used to reference the schema
    /// object within the scope of the containing schema object.
    wchar_t*                        m_name;

    /// Optional description of the schema object.
    wchar_t*                        m_description;

    FdoSchemaAttributeDictionary*   m_attributes;

    FdoSchemaElementState           m_state;


protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    unsigned int                    m_changeInfoState;
    FdoSchemaElement*               m_parentCHANGED;
    wchar_t*                        m_nameCHANGED;
    wchar_t*                        m_descriptionCHANGED;

    /// States stored in the m_changeInfoState bitfield flag
    static const unsigned int   CHANGEINFO_PRESENT      = 0x00000001;
    static const unsigned int   CHANGEINFO_PROCESSING   = 0x00000002;
    static const unsigned int   CHANGEINFO_PROCESSED    = 0x00000004;

    /// SAX Handler for reading simple sub-element contents
    FdoXmlCharDataHandlerP        m_XmlContentHandler;

    /// SAX Handler for reading error sub-elements
    /// Errors are generated by the XSL transformation that 
    /// converts the Feature Schema XML from external to internal
    /// format before it is read.
    FdoPtr<FdoSchemaXmlError>     m_XmlErrorHandler;
/// \endcond

};
/// \ingroup (typedefs)
/// \brief
/// FdoSchemaElementP is a FdoPtr on FdoSchemaElement, provided for convenience.
typedef FdoPtr<FdoSchemaElement> FdoSchemaElementP;

#endif



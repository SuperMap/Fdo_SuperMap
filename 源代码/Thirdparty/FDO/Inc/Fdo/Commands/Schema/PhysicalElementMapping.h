#ifndef FDO_PHYSICALELEMENTMAPPING_H
#define FDO_PHYSICALELEMENTMAPPING_H
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
#include <Fdo/Xml/Context.h>
#include <Fdo/Commands/CommandException.h>

class FdoPhysicalSchemaMapping;
class FdoXmlFlags;

/// \brief
/// FdoPhysicalElementMapping is an abstract class that acts as a base class for all 
/// Physical Schema Mapping Override classes. FDO also provides a number of sub-classes
/// for particular types of Provider-specific override classes:
/// \remarks
/// <ul>
/// <li>FdoPhysicalClassMapping: All classes corresponding to Feature Classes
/// must be based on FdoPhysicalClassMapping.
/// <li>FdoPhysicalPropertyMapping: Must be the base for all classes corresponding to 
/// Properties.
/// <li>FdoPhysicalSchemaMapping: Must be the base for all types of schema override sets.
/// </ul>
/// Other types of schema override classes can be based directly on FdoPhysicalElementMapping.
class FdoPhysicalElementMapping : 
    public FdoIDisposable,
    public virtual FdoXmlSaxHandler
{
    template <class OBJ> friend class FdoPhysicalElementMappingCollection;

public:
    /// \brief
    /// Gets the parent of this FdoPhysicalElementMapping or null if this object has not
    /// been added to a parent object.
    /// 
    /// \return
    /// Returns FdoPhysicalElementMapping of parent
    /// 
    FDO_API virtual FdoPhysicalElementMapping* GetParent();

    /// \brief
    /// Gets the FdoPhysicalSchemaMapping that this element is a part of. Returns null if this
    /// object has not been added to a feature schema.
    /// 
    /// \return
    /// Returns FdoPhysicalSchemaMapping this object is a part of
    /// 
    FDO_API virtual FdoPhysicalSchemaMapping* GetSchemaMapping();

    /// \brief
    /// Gets the name of this element.
    /// 
    /// \return
    /// Returns the name of this element.
    /// 
    FDO_API virtual FdoString* GetName();

    /// \brief
    /// Gets the fully qualified name of this element
    /// 
    /// \return
    /// default implementation simply returns the element name
    /// 
    FDO_API virtual FdoStringP GetQualifiedName();

    /// \brief
    /// Sets the name of this element.
    /// 
    /// \param value 
    /// Input the name of this element.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value);

/// \cond DOXYGEN-IGNORE
    //Indicates that this object allows its name
    //to change. This function is defined so that this class can 
    //be a FdoNamedCollection element.
    FDO_API virtual FdoBoolean CanSetName()
    {
        return true;
    }
/// \endcond

    /// Functions for XML support

    /// \brief
    /// Initializes this Physical Element Mapping from its XML attributes. Called when
    /// the element is deserialized from XML. Can be extended to handle 
    /// particular XML attributes for derived classes.
    /// 
    /// \param pContext 
    /// Input context contain information about the current deserialization operation
    /// \param attrs 
    /// Input the XML attributes.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// \brief
    /// Writes this Physical Mapping Element to XML. Called when
    /// the element is serialized to XML. Can be extended to handle 
    /// particular XML attributes and sub-elements for derived classes.
    /// 
    /// \param xmlWriter 
    /// Input write the element to this XML writer
    /// \param flags 
    /// Input flags that control the writing of the element.
    /// 
    /// \return
    /// Returns nothing
    /// 
   	FDO_API virtual void _writeXml(
    	FdoXmlWriter* xmlWriter, 
    	const FdoXmlFlags* flags
	);

/// \cond DOXYGEN-IGNORE

    /// Various error reporting functions that are not yet part of the supported
    /// FDO API.
    /// All of them return a FdoXmlSkipElementHandler, which can be used to skip
    /// over the element in error.

    FDO_API FdoXmlSaxHandler* SubElementError(
        FdoXmlSaxContext* pContext, 
        FdoString* parentElement,
        FdoString* subElement
    );

    FDO_API FdoXmlSaxHandler* MultiSubElementError(
        FdoXmlSaxContext* pContext, 
        FdoString* parentElement,
        FdoString* subElement
    );

    FDO_API FdoXmlSaxHandler* ChoiceSubElementError(
        FdoXmlSaxContext* pContext, 
        FdoString* parentElement,
        FdoStringsP subElements
    );

    FDO_API FdoXmlSaxHandler* DuplicateSubElementError(
        FdoXmlSaxContext* pContext, 
        FdoString* parentElement,
        FdoString* subElement,
        FdoString* subElementName
    );
/// \endcond


protected:
    /// \brief
    /// Constructs a default instance of an FdoPhysicalElementMapping.
    /// 
    FDO_API FdoPhysicalElementMapping();

    /// \brief
    /// Constructs an instance of an FdoPhysicalElementMapping using the specified arguments.
    /// 
    /// \param name 
    /// Input the element name
    /// 
    FDO_API FdoPhysicalElementMapping(FdoString* name /*, FdoString* description = L"" */);

    /// \brief
    /// FdoPhysicalElementMapping destructor.
    /// 
    FDO_API virtual ~FdoPhysicalElementMapping();

    /// \brief
    /// Sets the parent of this Physical Element Mapping.
    /// 
    /// \param value 
    /// Input the parent
    /// 
    FDO_API void SetParent(FdoPhysicalElementMapping* value);

/// \cond DOXYGEN-IGNORE

    /// retrieves a FdoXmlSkipElementHandler for skipping an entire XML element
    FDO_API FdoXmlSaxHandler* GetSkipper();

    /// Get the second token from the provider name for this 
    /// elements schema mapping set.
    FdoStringP GetProviderLocalName();

    /// SAX Handler for reading simple sub-element contents
    FdoXmlCharDataHandlerP        m_XmlContentHandler;

    /// SAX Handler for skipping elements
    FdoXmlSkipElementHandlerP     m_XmlSkipper;
/// \endcond

private:
    /// m_parent is a non-refcounted reference, to avoid circular references that prevent
    /// elements from being freed.
    FdoPhysicalElementMapping*              m_parent;

    /// The name of this element
    FdoStringP                              m_name;

    /// Optional description of this element.
    FdoStringP                              m_description;
};

/// \ingroup (typedefs)
/// \brief
/// FdoPhysicalElementMappingP is a FdoPtr on FdoPhysicalElementMapping, provided for convenience.
typedef FdoPtr<FdoPhysicalElementMapping> FdoPhysicalElementMappingP;

#endif



#ifndef FDO_XMLSCHEMAMAPPING_H_
#define FDO_XMLSCHEMAMAPPING_H_

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
#include <Fdo/Xml/Serializable.h>
#include <Fdo/Commands/Schema/PhysicalSchemaMapping.h>
#include <Fdo/Xml/ClassMappingCollection.h>

/// \brief
/// FdoXmlSchemaMapping specifies overrides for translating a feature schema between 
/// FDO and GML.
class FdoXmlSchemaMapping :
	public FdoPhysicalSchemaMapping
{
 
public:
    /// \brief
    /// Creates an XML Schema Mapping Set.
    /// 
    /// \return
    /// FdoXmlSchemaMapping
    /// 
    FDO_API static FdoXmlSchemaMapping* Create( FdoString* name );

    /// \brief
    /// Gets the provider name.
    /// 
    /// \return
    /// Returns "OSGeo.GML.1.0". 
	/// \note
	/// This is the name given to this
    /// particular type of Schema Override set and is not the name of an actual FDO provider.
    /// 
    ///  
	FDO_API virtual FdoString* GetProvider();

    /// \brief
    /// Sets the target namespace URI for the GML version of this schema.
    /// When the Feature Schema for these overrides is written to GML, its targetNamespace
    /// is set to this value.
    /// 
    /// \param url 
    /// Input the target namespace.
    /// 
    FDO_API void SetTargetNamespace( FdoString* url );

    /// \brief
    /// Gets the target namespace URI for the GML version of this schema.
    /// 
    /// \return
    /// Returns the target namespace.
    /// 
	FDO_API FdoString* GetTargetNamespace();

    /// \brief
    /// Gets the mappings between GML global elements and their types as Fdo Classes. These
    /// mappings are used in two circumstances:
    /// <ul>
    /// 	<li> when features are read from a GML Document, these mappings determine the Feature
    ///     class of each feature, based on its element name. If the element name is not 
    ///     in these mappings then the class name defaults to the element name.
    /// 	<li> when the Feature Schema for these overrides is written to GML, a global element
    ///     is created from each item in element mappings collection. 
    /// </ul>
    /// 
    /// \return
    /// Returns FdoXmlElementMappingCollection*
    /// 
	FDO_API FdoXmlElementMappingCollection* GetElementMappings();

    /// \brief
    /// Gets the mappings for FDO Classes.
    /// 
    /// \return
    /// Returns FdoXmlClassMappingCollection*
    /// 
	FDO_API FdoXmlClassMappingCollection* GetClassMappings();

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlSchemaMapping() {}

    FdoXmlSchemaMapping( FdoString* name );

    virtual ~FdoXmlSchemaMapping();

    virtual void Dispose();

    /// Functions for XML support

    /// \brief
    /// Initializes this Xml Schema Mapping from its XML attributes. Called when
    /// the element is deserialized from XML. 
    /// 
    /// \param pContext 
    /// Input context contain information about the current deserialization operation
    /// \param attrs 
    /// Input the XML attributes.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// \brief
    /// Writes this XML Schema Mapping to XML. Called when
    /// the element is serialized to XML. 
    /// 
    /// \param xmlWriter 
    /// Input write the element to this XML writer
    /// \param flags 
    /// Input flags that control the writing of the element.
    /// 
    /// \return
    /// Returns nothing
    /// 
   	virtual void _writeXml(
    	FdoXmlWriter* xmlWriter, 
    	const FdoXmlFlags* flags
	);
/// \endcond

private:
    FdoStringP mTargetNamespace;
    FdoXmlElementMappingsP mElementMappings;
    FdoXmlClassMappingsP mClassMappings;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSchemaMappingP is a FdoPtr on FdoXmlSchemaMapping, provided for convenience.
typedef FdoPtr<FdoXmlSchemaMapping> FdoXmlSchemaMappingP;

#endif



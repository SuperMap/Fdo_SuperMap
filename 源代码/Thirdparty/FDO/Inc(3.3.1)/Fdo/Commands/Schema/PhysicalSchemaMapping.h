#ifndef FDO_PHYSICALSCHEMAMAPPING_H_
#define FDO_PHYSICALSCHEMAMAPPING_H_
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
#include <Fdo/Xml/Serializable.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>

/// \brief
/// FdoPhysicalSchemaMapping is an  abstract class that is the base class of
/// all Schema Override sets. Each instance contains the overrides for a 
/// particular Feature Schema and FDO Provider.
/// Each FDO Provider, that allows Schema Overrides, must create a sub-class of this 
/// class. This sub-class must implement the overrides that are specific to the 
/// provider. The Provider can also add support, for serializing to an XML document, 
/// by overriding the functions inherited from  FdoXmlSerializable.
class FdoPhysicalSchemaMapping :
	public FdoPhysicalElementMapping,
	public FdoXmlSerializable
{
    friend class FdoPhysicalSchemaMappingCollection;
 
public:
    /// \brief
    /// Gets the name of the applicable FDO provider.
    /// 
    /// \return
    /// Returns the name of FDO provider to which this Schema Override set 
    /// applies. The provider name must conform to the format:
    /// "[Company].[Provider].[Version]".
    /// 
	FDO_API virtual FdoString* GetProvider() = 0;

protected:
    /// \brief
    /// Initializes this Schema Override set from its XML attributes. Called when
    /// the set is deserialized from XML. This function decodes any
    /// encoded schema names (See _writeXml). Can be extended to handle 
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
    /// Writes this Schema Override set to XML. Called when
    /// this set is serialized to XML. This function converts (encodes) 
    /// schema names to be valid XML element names. Can be extended to handle provider-specific
    /// attributes and sub-elements.
    /// 
    /// \param xmlWriter 
    /// Input write the Schema Override set to this XML writer
    /// \param flags 
    /// Input flags that control the writing of the Schema Override set.
    /// 
    /// \return
    /// Returns nothing
    /// 
 	FDO_API virtual void _writeXml(
    	FdoXmlWriter* xmlWriter, 
    	const FdoXmlFlags* flags
	);

};

/// \ingroup (typedefs)
/// \brief
/// FdoIPhysicalSchemaMappingP is a FdoPtr on FdoIPhysicalSchemaMapping, provided for convenience.
typedef FdoPtr<FdoPhysicalSchemaMapping> FdoPhysicalSchemaMappingP;

#endif



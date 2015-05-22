#ifndef FDO_PHYSICALPROPERTYMAPPING_H
#define FDO_PHYSICALPROPERTYMAPPING_H
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
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>

class FdoPhysicalSchemaMapping;
class FdoXmlFlags;

/// \brief
/// FdoPhysicalPropertyMapping is an abstract class that acts as a base class for all 
/// Physical Schema Mapping property overrides.
class FdoPhysicalPropertyMapping : 
    public FdoPhysicalElementMapping
{
public:
    /// \brief
    /// Initializes this Physical Property Mapping from its XML attributes. Called when
    /// this element is deserialized from XML. This function decodes any
    /// encoded property names (See _writeXml). Can be extended to handle 
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
    /// Writes this Physical Property Mapping to XML. Called when
    /// this element is serialized to XML. This function converts (encodes) 
    /// property names to be valid XML element names. Can be extended to handle 
    /// particular XML attributes and sub-elements for derived classes.
    /// \note
	/// Schema Override elements that do not require name encoding
    /// should be based on FdoPhysicalElementMapping instead of this class.
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


protected:
    /// \brief
    /// Constructs a default instance of a property mapping.
    /// 
    FDO_API FdoPhysicalPropertyMapping(); 

    /// \brief
    /// Constructs a named instance of a property mapping.
    /// 
    /// \param name 
    /// Input the class name
    /// 
    FDO_API FdoPhysicalPropertyMapping( FdoString* name );

    /// \brief
    /// property mapping destructor.
    /// 
    FDO_API virtual ~FdoPhysicalPropertyMapping();

};

/// \ingroup (typedefs)
/// \brief
/// FdoPhysicalPropertyMappingP is a FdoPtr on FdoPhysicalPropertyMapping, provided for convenience.
typedef FdoPtr<FdoPhysicalPropertyMapping> FdoPhysicalPropertyMappingP;

#endif



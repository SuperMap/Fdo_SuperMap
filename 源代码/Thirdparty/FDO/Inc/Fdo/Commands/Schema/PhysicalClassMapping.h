#ifndef FDO_PHYSICALCLASSMAPPING_H
#define FDO_PHYSICALCLASSMAPPING_H
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
/// FdoPhysicalClassMapping is an abstract class that acts as a base class for all 
/// Physical Schema Mapping class overrides.
class FdoPhysicalClassMapping : 
    public FdoPhysicalElementMapping
{
public:
    /// \brief
    /// Initializes this class from its XML attributes. Called when
    /// the class is deserialized from XML. This function decodes any
    /// encoded class names (See _writeXml) and strips off the "Type" suffix if present.
    /// Can be extended to handle 
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
    /// Writes this class to XML. Called when
    /// the class is serialized to XML. This function converts (encodes) 
    /// class names to be valid XML element names and appends the "Type"
    /// suffix to the name. Can be extended to handle 
    /// particular XML attributes for derived classes.
    /// \note
	/// Schema Override elements that do not require name encoding
    /// should be based on FdoPhysicalElementMapping instead of this class.
    /// 
    /// \param xmlWriter 
    /// Input write the class to this XML writer
    /// \param flags 
    /// Input flags that control the writing of the class.
    /// 
    /// \return
    /// Returns nothing
    /// 
    /// Write this element to XML.
   	FDO_API virtual void _writeXml(
    	FdoXmlWriter* xmlWriter, 
    	const FdoXmlFlags* flags
	);

protected:
    /// \brief
    /// Constructs a default instance of a class mapping.
    /// 
    FDO_API FdoPhysicalClassMapping(); 

    /// \brief
    /// Constructs a named instance of a class mapping.
    /// 
    /// \param name 
    /// Input the class name
    /// 
    FDO_API FdoPhysicalClassMapping( FdoString* name );

    /// \brief
    /// Class mapping destructor.
    /// 
    FDO_API virtual ~FdoPhysicalClassMapping();

};

/// \ingroup (typedefs)
/// \brief
/// FdoPhysicalClassMappingP is a FdoPtr on FdoPhysicalClassMapping, provided for convenience.
typedef FdoPtr<FdoPhysicalClassMapping> FdoPhysicalClassMappingP;

#endif



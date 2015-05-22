#ifndef FDO_XMLCLASSMAPPING_H
#define FDO_XMLCLASSMAPPING_H

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
#include <Fdo/Commands/Schema/PhysicalClassMapping.h>
#include <Fdo/Xml/ElementMappingCollection.h>

/// \brief
/// FdoXmlClassMapping describes GML to FDO mappings for a particular FDO class
/// Only mappings that cannot be represented in FDO are described.
class FdoXmlClassMapping : public FdoPhysicalClassMapping
{
public:
    /// \brief
    /// Constructs an object describing the GML-FDO mappings for an FDO class.
    /// 
    /// \param name 
    /// Input class name
    /// \param GmlName 
    /// Input corresponding type name in GML version of the
    /// class's schema.
    /// \param wkBaseName 
    /// Input name of the most specialized well-known type. This is 
    /// set when the type represents geometries and indicates what kind of geometries the type
    /// represents. wkBaseName must be L"" or one of the constants defined in 
    /// commonGml212Gml212.h.
	 /// \param wkSchemaName
	 /// Well-known schema name.
    /// 
    /// \return
    /// Returns FdoXmlClassMapping
    /// 
    FDO_API static FdoXmlClassMapping* Create(
        FdoString* name, 
        FdoString* gmlName,
        FdoString* wkBaseName,
        FdoString* wkSchemaName = L""
    );

    /// \brief
    /// Gets the name of the class's corresponding GML complexType.
    /// 
    /// \return
    /// Returns FdoString.
    /// 
    FDO_API FdoString* GetGmlName();

    /// \brief
    /// Gets the most specialized well-known base type
    /// 
    /// \return
    /// Returns FdoString.
    /// 
    FDO_API FdoString* GetWkBaseName();

    /// \brief
    /// Gets the schema containing most specialized well-known base type
    /// 
    /// \return
    /// Returns FdoString.
    /// 
    FDO_API FdoString* GetWkSchemaName();

    /// \brief
    /// Gets the mappings between GML elements for this class's properties and their
    /// Fdo Classes. 
    /// 
    /// \return
    /// Returns FdoXmlElementMappingCollection*
    /// 
	FDO_API FdoXmlElementMappingCollection* GetElementMappings();

/// \cond DOXYGEN-IGNORE

    /// \brief
    /// Writes this XML Class Mapping to XML. Called when
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

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlClassMapping() {}

    FdoXmlClassMapping(
        FdoString* name, 
        FdoString* gmlName,
        FdoString* wkBaseName,
        FdoString* wkSchemaName
    );

    virtual ~FdoXmlClassMapping();

    virtual void Dispose();

    /// Functions for XML support

    /// \brief
    /// Initializes this Xml Class Mapping from its XML attributes. Called when
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

/// \endcond

private:
    FdoStringP mGmlName;
    FdoStringP mWkBaseName;
    FdoStringP mWkSchemaName;
    FdoXmlElementMappingsP mElementMappings;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlClassMappingP is a FdoPtr on FdoXmlClassMapping, provided for convenience.
typedef FdoPtr<FdoXmlClassMapping> FdoXmlClassMappingP;

#endif



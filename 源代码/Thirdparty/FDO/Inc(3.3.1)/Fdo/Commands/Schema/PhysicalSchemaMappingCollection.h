#ifndef FDO_PHYSICALSCHEMAMAPPINGCOLLECTION_H
#define FDO_PHYSICALSCHEMAMAPPINGCOLLECTION_H
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
#include <Fdo/Xml/Deserializable.h>
#include <Fdo/Xml/Serializable.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Schema/SchemaException.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>
#include <Fdo/Commands/Schema/PhysicalSchemaMapping.h>

class FdoVector;

/// \brief
/// FdoPhysicalSchemaMappingCollection defines a collection of Schema Override
/// sets. This is a generic collection which can contain override sets for different 
/// FDO Providers.
class FdoPhysicalSchemaMappingCollection : 
    public FdoCollection<FdoPhysicalSchemaMapping, FdoCommandException>,
    public FdoXmlDeserializable,
    public FdoXmlSerializable
{
public:
    /// \brief
    /// Constructs an instance of an FdoPhysicalSchemaMappingCollection .
    /// 
    /// \return
    /// Returns FdoPhysicalSchemaMappingCollection
    /// 
    FDO_API static FdoPhysicalSchemaMappingCollection* Create();

    /// \brief
    /// Gets the Schema Override set in the collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param item 
    /// Input item
    /// 
    /// \return
    /// Returns the Schema Override set at the specified index
    /// 
   	FDO_API FdoPhysicalSchemaMapping* GetItem( FdoInt32 item );

    /// \brief
    /// Gets the Schema Override set for the specified 
    /// FDO provider and Feature Schema.
    /// 
    /// \param providerName 
    /// Input FDO Provider name of the form "[Company].[Provider].[Version]".
    /// \param schemaName 
    /// Input Feature Schema name.
    /// 
    /// \return
    /// the Schema Override set for the given FDO Provider and Feature 
    /// Schema, where the  [company] and [provider] parts of the set’s providerName 
    /// and the given providerName match exactly. The set with the highest 
    /// [version], that is less than or equal to the [version] of the given provider, 
    /// is returned.  NULL is return if a set was not found.
    /// 
	FDO_API FdoPhysicalSchemaMapping * GetItem( 
		FdoString* providerName, 
		FdoString* schemaName
	);

    /// \brief
    /// Gets the Schema Override set for the specified Feature Schema and the
    /// FDO provider for the specified connection. This function allows an application 
    /// to retrieve the Schema Overrides for an active provider without knowing the 
    /// provider name.
    /// 
    /// \param connection 
    /// Input the FDO connection.
    /// \param schemaName 
    /// Input Feature Schema name.
    /// 
    /// \return
    /// Returns the Schema Override set for the given Feature Schema and 
    /// the FDO Provider for the given connection. NULL is return if the set was not 
    /// found.
    /// 
	FDO_API FdoPhysicalSchemaMapping * GetItem( 
		FdoIConnection* connection, 
		FdoString* schemaName
	);

/// \cond DOXYGEN-IGNORE
//
    /// FdoXmlDeserializable overrides for deserializing a Schema Override set collection 
    /// from XML. These are not exposed via the FDO API.

    FDO_API virtual void XmlEndDocument(FdoXmlSaxContext* context);

    FDO_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    FDO_API virtual FdoXmlSaxContext* GetSaxContext();

protected:
    FDO_API FdoPhysicalSchemaMappingCollection();

    FDO_API virtual ~FdoPhysicalSchemaMappingCollection()
    {
    }

    FDO_API virtual void Dispose()
    {
        delete this;
    }

    /// FdoXmlSerializable override that serializes a Feature Schema collection to XML.
  	FDO_API virtual void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );
/// \endcond

private:
    FdoPtr<FdoXmlSkipElementHandler> m_XmlSkipper;
};

/// \ingroup (typedefs)
/// \brief
/// FdoSchemaMappingsP is a FdoPtr on FdoPhysicalSchemaMappingCollection, provided for convenience.
typedef FdoPtr<FdoPhysicalSchemaMappingCollection> FdoSchemaMappingsP;

#endif



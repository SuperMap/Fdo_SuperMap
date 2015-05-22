#ifndef _FEATURESCHEMA_H_
#define _FEATURESCHEMA_H_

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
#include <Fdo/Schema/SchemaElement.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/SchemaCollection.h>
#include <Fdo/Schema/ClassCollection.h>
#include <Fdo/Xml/Serializable.h>

class FdoRelationCollection;
class FdoRelation;

/// \brief
/// The FdoFeatureSchema class derives from FdoSchemaElement.
/// A feature schema contains all of the classes and relationships
/// that make up a particular data model. The FdoFeatureSchema class can be used to
/// either create a new schema or to browse the schema end of a
/// connection. In the later case, the FdoFeatureSchema instance is created by the
/// DescribeSchema command. In this case the schema objects have additional properties,
/// such as coordinate system definitions that can be useful to the
/// application when placed in context with the schema objects.
class FdoFeatureSchema : 
    public FdoSchemaElement,
    public FdoXmlSerializable
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default empty instance of an FdoFeatureSchema.
    FdoFeatureSchema();

    /// Constructs an instance of an FdoFeatureSchema using the specified arguments.
    FdoFeatureSchema(FdoString* name, FdoString* description);

    virtual ~FdoFeatureSchema();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default empty instance of an FdoFeatureSchema.
    /// 
    /// \return
    /// Returns FdoFeatureSchema
    /// 
    FDO_API static FdoFeatureSchema* Create();

    /// \brief
    /// Constructs an instance of an FdoFeatureSchema using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoFeatureSchema
    /// 
    FDO_API static FdoFeatureSchema* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Returns an FdoClassCollection that contains all of the classes defined in
    /// the feature schema.
    /// 
    /// \return
    /// Returns an FdoClassCollection
    /// 
    FDO_API FdoClassCollection* GetClasses();

    /// \brief
    /// Returns an FdoRelationCollection that contains all of the relations defined
    /// in the feature schema.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API FdoRelationCollection* GetRelations();

    /// \brief
    /// Accepts all of the changes that have been made to the feature schema.
    /// All child elements with a schema element state set to
    /// FdoSchemaElementState_Deleted are physically removed from the schema. All
    /// other child elements have their schema element state values set to
    /// FdoSchemaElementState_Unchanged.
    /// This method would usually be only called from an FDO Provider (IApplySchema
    /// implementation). It would not normally called by an FDO Client.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void AcceptChanges();

    /// \brief
    /// Rejects all of the changes that have been made to the feature schema.
    /// All child elements with a schema element state set to
    /// FdoSchemaElementState_Added are physically removed from the schema. All other 
    /// child elements are restored to their original states and have their schema 
    /// element state values set to FdoSchemaElementState_Unchanged.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void RejectChanges();

    /// \brief
    /// Gets the stylesheet for converting a Feature Schema collection from 
    /// internal to external XML format. The internal format is very similar to 
    /// the Feature Schema class hierarchy. The external format is OGC GML.
    /// 
    /// \return
    /// Returns the stylesheet
    /// 
    FDO_API virtual FdoXmlReader* GetFromInternalStylesheet();

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML serialization and Schema Merge

    /// Merge the given schema into this schema. An additive merge
    /// is performed. 
    void Set( FdoFeatureSchema* pSchema, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given context if any class references elements
    // marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Allows FeatureSchemaCollection to get the stylesheet.
    static FdoXmlReader* _getFromInternalStylesheet();

    /// FdoXmlDeserializabe callback override to handle start of sub-elements 
    //when deserializing from XML.
    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    /// FdoXmlSerializabe callback override to serialize this feature schema
    /// to XML.
  	virtual void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );
  	virtual void _writeXml( FdoSchemaXmlContext* pContext );
/// \endcond

private:
    FdoClassCollection*         m_classes;
};

/// \ingroup (typedefs)
/// \brief
/// FdoFeatureSchemaP is a FdoPtr on FdoFeatureSchema, provided for convenience.
typedef FdoPtr<FdoFeatureSchema> FdoFeatureSchemaP;

#endif



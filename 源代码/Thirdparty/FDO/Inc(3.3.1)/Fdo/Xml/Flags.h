#ifndef FDO_XML_FLAGS_H
#define FDO_XML_FLAGS_H

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

#include <FdoStd.h>

class FdoPhysicalSchemaMappingCollection;

/// \brief
/// FdoXmlFlags defines various options for serializing and deserializing
/// FDO element to and from XML Documents.
class FdoXmlFlags : public FdoIDisposable
{
public:
    /// \brief
    /// The FdoXmlFlags::ErrorLevel determines how strict the error reporting 
    /// is when a Feature Schema is read from an XML Document. For each errorLevel a 
    /// certain level of round-trip fidelity is guaranteed if the read succeeds.
    /// \param ErrorLevel_VeryLow 
    /// the read succeeds even if no level of 
    /// round-trip fidelity is maintained. If the Feature Schema is read successfully 
    /// from document A and then written to document B, any instance document that
    /// conforms to the document A schema may or may not conform to the document B 
    /// schema. A document that does not conform to the A schema may or may not 
    /// conform to the B schema. This errorLevel is useful for reading schemas from 
    /// external sources into FDO when it doesn’t matter how much the schemas are 
    /// altered during the read.
    /// 
	enum ErrorLevel {
    		/// The read fails with an exception when the Feature Schema cannot be read without alteration.
		/// If the Feature Schema is read successfully from document A and then written to document B, 
    		/// documents A and B are guaranteed to be identical.
		/// This errorLevel should be used when no alterations to the Feature Schema can be tolerated
		ErrorLevel_High,
    		/// Fails if the Feature Schema cannot be read 
    		/// without changing the domain of its conforming instance documents.
		/// If the Feature Schema is read successfully from document A
		/// and then written to document B,
    		/// any instance document that conforms to the document A schema 
    		/// will also conform to the document B schema.
		/// Any instance document that does not conform to A does not conform to B.
		/// However, documents A and B will not necessarily be identical.
		ErrorLevel_Normal,
    		/// Similar to ErrorLevel_Normal except that the 
    		/// instance document domain is allowed to grow.
		/// If the Feature Schema is read 
    		/// successfully from document A and then written to document B,
		/// any instance document that conforms to the document A schema will also conform to the document B schema.
		/// However a document that does not conform to the A schema 
    		/// may or may not conform to the B schema.
		ErrorLevel_Low,
    		/// The read succeeds even if no level of round-trip fidelity is maintained.
		/// If the Feature Schema is read successfully from document A and then written to document B,
		/// any instance document thatconforms to the document A schema
		/// may or may not conform to the document B schema.
    		/// A document that does not conform to the A schema may or may not conform to the B schema.
		/// This errorLevel is useful for reading schemas from external sources into FDO
		/// when it doesn’t matter how much the schemas are altered during the read.
		ErrorLevel_VeryLow
	};

    /// \brief
    /// Constructs an FdoXmlFlags object.
    /// 
    /// \param url 
    /// Input When writing  Feature Schemas, this specifies the 
    /// prefix for the target namespace for any schemas that are written. The XML 
    /// format for Feature Schemas is OGC GML, so a targetNamespace for the 
    /// xs:schema element is required. This namespace will be http://[url]/[schema_name].
    /// \param errorLevel 
    /// Input The error level for reading feature schemas.
    /// \param nameAdjust 
    /// Input true: apply name adjustment to all elements. 
    /// false: apply name adjustment only to elements with fdo:nameAdjust="true"
    /// 
    /// \return
    /// Returns FdoXmlFlags
    /// 
    FDO_API static FdoXmlFlags* Create( 
        FdoString* url = L"fdo.osgeo.org/schemas/feature",
		ErrorLevel errorLevel = ErrorLevel_Normal,
        FdoBoolean nameAdjust = true
	);

    /// \brief
    /// Sets the target namespace prefix, see FdoXmlFlags::Create().
    /// 
    /// \param url 
    /// Input the target namespace prefix.
    /// 
    FDO_API void SetUrl( FdoString* url );

    /// \brief
    /// Gets the target namespace prefix, see FdoXmlFlags::Create().
    /// 
    /// \return
    /// Returns the target namespace prefix.
    /// 
	FDO_API FdoString* GetUrl() const;

    /// \brief
    /// Sets the error level, see FdoXmlFlags::Create().
    /// 
    /// \param errorLevel 
    /// Input the error level.
    /// 
	FDO_API void SetErrorLevel( ErrorLevel errorLevel );

    /// \brief
    /// Gets the current error level, see FdoXmlFlags::Create().
    /// 
    /// \return
    /// Returns the error level.
    /// 
	FDO_API ErrorLevel GetErrorLevel() const;

    /// \brief
    /// Sets the name adjustment flag, see FdoXmlFlags::Create().
    /// 
    /// \param nameAdjust 
    /// Input the name adjustment flag.
    /// 
  	FDO_API void SetNameAdjust( FdoBoolean nameAdjust );

    /// \brief
    /// Gets the name adjustment flag, see FdoXmlFlags::Create().
    /// 
    /// \return
    /// Returns the name adjustment flag.
    /// 
	FDO_API FdoBoolean GetNameAdjust() const;

    /// \brief
    /// Sets the Schema Name as Prefix flag. This flag controls how
    /// an FDO Feature Schema name is generated when the schema is read
    /// from GML.
    /// 
    /// \param schemaNameAsPrefix 
    /// Input when true, the Feature Schema 
    /// name is set to the prefix from the xmlns namespace declaration for 
    /// the schema's targetNamespace. The target namespace prefix flag on this 
    /// object is ignored
    /// in this case. If no suitable namespace declaration can be found,
    /// the Feature Schema name is set as if this flag were false.
    /// Schemas cannot be round-tripped when this flag is true. Therefore, it
    /// may only be set to true when the current ErrorLevel is VeryLow.
    /// Caution must be observed when using this flag. Unpredictable results
    /// can occur if a GML Schema uses different prefixes for its 
    /// targetNamespace in different parts of the schema.
    /// 
  	FDO_API void SetSchemaNameAsPrefix( FdoBoolean schemaNameAsPrefix );

    /// \brief
    /// Gets the Schema Name as Prefix flag.
    /// 
    /// \return
    /// Returns the Schema Name as Prefix flag.
    /// 
	FDO_API FdoBoolean GetSchemaNameAsPrefix() const;

    /// \brief
    /// Sets the Use GML ID flag.
    /// 
    /// \param schemaNameAsPrefix 
    /// Input when true, the feature id ( fid in GML 2, gml:id in GML 3)
    /// becomes the identity property of all feature classes.
    /// 
  	FDO_API void SetUseGmlId( FdoBoolean schemaNameAsPrefix );

    /// \brief
    /// Gets the Use GML ID flag.
    /// 
    /// \return
    /// Returns the Use GML ID flag.
    /// 
	FDO_API FdoBoolean GetUseGmlId() const;

    /// \brief
    /// Sets the Schema Mapping Overrides for translating schemas 
    /// between GML and FDO. 
    /// 
    /// \param mappings 
    /// Input the Schema Mapping Overrides. This collection
    /// can contain an FdoXmlSchemaMapping element for each Feature Schema that
    /// may be written or read. When a Feature Schema is read or written to or 
    /// from GML, this collection is checked for an FdoXmlSchemaMapping item named 
    /// the same as the feature schema. If present, the hints in this item 
    /// affect how the feature schema is read or written. The Schema Mapping 
    /// Overrides also control how features are read since they 
    /// can override the default correspondences between feature class names 
    /// and their GML element names.
    /// 
  	FDO_API void SetSchemaMappings( FdoPhysicalSchemaMappingCollection* mappings );

    /// \brief
    /// Gets the current Schema Mapping Overrides.
    /// 
    /// \return
    /// Returns FdoXmlSchemaMappingCollection*.
    /// 
	FDO_API FdoPhysicalSchemaMappingCollection* GetSchemaMappings() const;

protected:
    /// default constructor to keep linux from complaining
    FdoXmlFlags() {}
	FDO_API FdoXmlFlags( FdoString* url, ErrorLevel errorLevel, FdoBoolean nameAdjust );
    FDO_API virtual ~FdoXmlFlags();

/// \cond DOXYGEN-IGNORE
    //Deletes myself
    FDO_API virtual void Dispose();
/// \endcond

private:
    ErrorLevel mErrorLevel;
    FdoStringP mUrl;
    FdoBoolean mNameAdjust;
    FdoBoolean mSchemaNameAsPrefix;
    FdoBoolean mUseGmlId;
    FdoPhysicalSchemaMappingCollection* mSchemaMappings;

/// \cond DOXYGEN-IGNORE
private:
    FdoBoolean mElementDefaultNullability;
public:
    void SetElementDefaultNullability( FdoBoolean pValue )
    {
        mElementDefaultNullability = pValue;
    }

    FdoBoolean GetElementDefaultNullability() const
    {
        return mElementDefaultNullability;
    }
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFlagsP is a FdoPtr on FdoXmlFlags, provided for convenience.
typedef FdoPtr<FdoXmlFlags> FdoXmlFlagsP;

#endif



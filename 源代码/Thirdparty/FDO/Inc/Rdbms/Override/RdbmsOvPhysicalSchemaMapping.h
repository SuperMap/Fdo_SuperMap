#ifndef FDO_RDBMSOVPHYSICALSCHEMAMAPPING_H
#define FDO_RDBMSOVPHYSICALSCHEMAMAPPING_H
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

#include <Fdo/Commands/Schema/PhysicalSchemaMapping.h>
#include <Utilities/SchemaMgr/Overrides/TableMappingType.h>
#include <Utilities/SchemaMgr/Overrides/GeometricColumnType.h>
#include <Utilities/SchemaMgr/Overrides/GeometricContentType.h>
#include <Rdbms/Override/RdbmsOv.h>
#include <Rdbms/Override/RdbmsOvClassCollection.h>
#include <Rdbms/Override/RdbmsOvSchemaAutoGeneration.h>

/// <library>
/// FdoRdbms.lib
/// </library>

///<summary>Abstract base class for RDBMS type provider schema 
///override sets.</summary>
class FdoRdbmsOvPhysicalSchemaMapping : public FdoPhysicalSchemaMapping
{

public:
    ///<summary>Gets the collection of class overrides for this schema 
    ///override set.</summary>
    /// <returns>Returns FdoRdbmsOvReadOnlyClassCollection</returns>
    FDORDBMS_OV_API FdoRdbmsOvReadOnlyClassCollection* GetClasses();

    ///<summary>Gets the table mapping</summary>
    ///<returns>Returns the table mapping</returns>
    FDORDBMS_OV_API FdoSmOvTableMappingType GetTableMapping();

    ///<summary>Sets the table mapping</summary>
    /// <param name="mappingType">Input the mapping type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetTableMapping(FdoSmOvTableMappingType mappingType);

    ///<summary>Gets the default geometric column type for newly-created geometric properties</summary>
    ///<returns>Returns the default geometric column type</returns>
    FDORDBMS_OV_API FdoSmOvGeometricColumnType GetGeometricColumnType();

    ///<summary>Sets default geometric column type for newly-created geometric properties</summary>
    /// <param name="columnType">Input the default geometric column type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetGeometricColumnType(FdoSmOvGeometricColumnType columnType);

    ///<summary>Gets the default geometric content type for newly-created geometric properties</summary>
    ///<returns>Returns the default geometric content type</returns>
    FDORDBMS_OV_API FdoSmOvGeometricContentType GetGeometricContentType();

    ///<summary>Sets default geometric content type for newly-created geometric properties</summary>
    /// <param name="contentType">Input the default geometric content type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetGeometricContentType(FdoSmOvGeometricContentType contentType);

    ///<summary>Gets the settings for AutoGenerating classes for this feature
    ///schema from the physical schema of the connected datastore.
    ///</summary>
    ///<returns>Returns FdoRdbmsOvSchemaAutoGeneration</returns>
    FDORDBMS_OV_API FdoRdbmsOvSchemaAutoGeneration* GetAutoGeneration();

    ///<summary>Sets class autogeneration settings.</summary>
    /// <param name="autoGeneration">
    /// Input the autogeneration settings. If NULL then no schema autogeneration
    /// takes place.
    /// </param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetAutoGeneration(FdoRdbmsOvSchemaAutoGeneration* autoGeneration);

//DOM-IGNORE-BEGIN

    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);
    
    FDORDBMS_OV_API FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );
//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPhysicalSchemaMapping();
    FDORDBMS_OV_API FdoRdbmsOvPhysicalSchemaMapping(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPhysicalSchemaMapping();

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    // Serialize this property to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);
   
    // Write any provider-specific parts that become XML attributes.
    FDORDBMS_OV_API virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Write any provider-specific parts that become XML elements.
    FDORDBMS_OV_API virtual void _writeXmlElements(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Get a writable version of the class override collection.
    FDORDBMS_OV_API FdoRdbmsOvClassCollection* GetRdbmsClasses();

    // Create a class override. Each provider that supports class overrides
    // must override this function.
    FDORDBMS_OV_API virtual FdoRdbmsOvClassDefinition* CreateClass( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* atts
    )
    {
        // TODO: exception
        return NULL;
    }

    // Add a class override to this schema override set. Each provider that 
    // supports class overrides must override this function.
    FDORDBMS_OV_API virtual void AddClass( 
        FdoRdbmsOvClassDefinition* pClass
    )
    {
        // TODO: exception
    }

private:
    FdoSmOvTableMappingType    mMappingType;
    FdoSmOvGeometricColumnType  mDefaultGeometricColumnType;
    FdoSmOvGeometricContentType mDefaultGeometricContentType;
    FdoRdbmsOvClassesP mClasses;
    FdoRdbmsOvSchemaAutoGenerationP mAutoGeneration;
};

///<summary>FdoRdbmsOvSchemaMappingP is a FdoPtr on FdoRdbmsOvPhysicalSchemaMapping, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvPhysicalSchemaMapping> FdoRdbmsOvSchemaMappingP;

#endif


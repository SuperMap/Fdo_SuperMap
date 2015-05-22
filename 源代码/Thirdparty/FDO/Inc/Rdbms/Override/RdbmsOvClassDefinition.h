#ifndef FDO_RDBMSOVCLASSDEFINITION_H
#define FDO_RDBMSOVCLASSDEFINITION_H

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

/// <library>
/// FdoRdbms.lib
/// </library>

#include <Fdo/Commands/Schema/PhysicalClassMapping.h>
#include <Utilities/SchemaMgr/Overrides/TableMappingType.h>
#include <Rdbms/Override/RdbmsOv.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinitionCollection.h>
#include <Rdbms/Override/RdbmsOvDataPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvGeometricPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvObjectPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvTable.h>

///<summary>Abstract class defining physical schema overrides for a class definition.</summary>
class FdoRdbmsOvClassDefinition: public FdoPhysicalClassMapping
{

public:
    ///<summary>Gets the collection of property overrides for this class
    ///override.</summary>
    /// <returns>Returns FdoRdbmsOvReadOnlyPropertyDefinitionCollection</returns>
    FDORDBMS_OV_API FdoRdbmsOvReadOnlyPropertyDefinitionCollection* GetProperties();

    ///<summary>Gets the table overrides for this class override</summary>
    /// <returns>Returns FdoRdbmsOvTable</returns>
    FDORDBMS_OV_API FdoRdbmsOvTable* GetTable();

    ///<summary>Gets the table mapping</summary>
    ///<returns>Returns FdoSmOvTableMappingType</returns>
    FDORDBMS_OV_API FdoSmOvTableMappingType GetTableMapping();

    ///<summary>Sets the table mapping</summary>
    /// <param name="mappingType">Input the mapping type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetTableMapping(FdoSmOvTableMappingType mappingType);

//DOM-IGNORE-BEGIN
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);
     
    // XML Serialization functions.

    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    // Serialize the XML attributes of this class:
    FDORDBMS_OV_API virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

    FDORDBMS_OV_API virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname
    );

//DOM-IGNORE-END

protected:
    //<summary>Constructs a default instance of an FdoRdbmsOvClassDefinition.</summary>
    FDORDBMS_OV_API FdoRdbmsOvClassDefinition();

    //<summary>Constructs an instance of an FdoRdbmsOvClassDefinition using the specified arguments.</summary>
    // <param name="name">Input the element name</param> 
    FDORDBMS_OV_API FdoRdbmsOvClassDefinition(FdoString *name);

    FDORDBMS_OV_API virtual ~FdoRdbmsOvClassDefinition();

    //<summary>Gets the property overrides in writable form.</summary>
    // <returns>Returns FdoRdbmsOvPropertyDefinitionCollection</returns>
    FDORDBMS_OV_API FdoRdbmsOvPropertyDefinitionCollection* GetRdbmsProperties();

    //<summary>Sets the table override<summary>
    // <param name="table">Input table override</param>
    FDORDBMS_OV_API void SetTable(FdoRdbmsOvTable* table);

    //<summary>Sets the table override from XML attributes</summary>
    // <param name="context">Input context contain information about the current deserialization operation</param> 
    // <param name="attrs">Input the XML attributes.</param> 
    FDORDBMS_OV_API virtual void SetTable(
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* atts
    )
    {
        //TODO: exception
    }

    //<summary>
    //Creates a data property override for this class override.
    //Must be overridden by all providers that support
    //data property overrides.
    //</summary>
    // <param name="context">Input context contain information about the current deserialization operation</param> 
    // <param name="propAttrs">Input the XML attributes for the property override.</param> 
    // <param name="colAttrs">Input the XML attributes for the property's column override.</param> 
    // <returns>Returns FdoRdbmsOvDataPropertyDefinition</returns>
    FDORDBMS_OV_API virtual FdoRdbmsOvDataPropertyDefinition* CreateDataProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoXmlAttributeCollection* colAtts
    )
    {
        //TODO: exception
        return NULL;
    }

    //<summary>
    //Creates a geometric property override for this class override.
    //Must be overridden by all providers that support
    //geometric property overrides.
    //</summary>
    // <param name="context">Input context contain information about the current deserialization operation</param> 
    // <param name="propAttrs">Input the XML attributes for the property override.</param> 
    // <param name="colAttrs">Input the XML attributes for the property's column override.</param> 
    // <returns>Returns FdoRdbmsOvDataPropertyDefinition</returns>
    FDORDBMS_OV_API virtual FdoRdbmsOvGeometricPropertyDefinition* CreateGeometricProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoXmlAttributeCollection* colAtts
    )
    {
        //TODO: exception
        return NULL;
    }

    //<summary>
    //Creates a object property override for this class override.
    //Must be overridden by all providers that support
    //object property overrides.
    //</summary>
    // <param name="context">Input context contain information about the current deserialization operation</param> 
    // <param name="propAttrs">Input the XML attributes for the property override.</param> 
    // <param name="mappingAttrs">Input the XML attributes for the 
    // object property table mapping override.</param> 
    // <returns>Returns FdoRdbmsOvDataPropertyDefinition</returns>
    FDORDBMS_OV_API virtual FdoRdbmsOvObjectPropertyDefinition* CreateObjectProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoString* mappingType,
        FdoXmlAttributeCollection* mappingAtts
    )
    {
        //TODO: exception
        return NULL;
    }

    //<summary> 
    //Checks if the given property is already in this class overrides's
    //property list. If it is then an error is logged and a SAX handler
    //for skipping the rest of the property's XML elements is returned.
    ///summary>
    // <param name="context">Input context contain information about the current deserialization operation</param> 
    // <param name="pProp">Input the property to check</param> 
    // <returns>Returns FdoXmlSaxHandler</returns>
    FDORDBMS_OV_API FdoXmlSaxHandler* CheckDuplicateProperty( 
        FdoXmlSaxContext* context,
        FdoRdbmsOvPropertyDefinition* pProp 
    );

    //<summary>
    //Adds a property to this class definition.
    //<summary>
    FDORDBMS_OV_API virtual void AddProperty(
        FdoRdbmsOvPropertyDefinition* pProp 
    ) = 0;

//DOM-IGNORE-BEGIN
    // Initializes this class override.
    void Init();
//DOM-IGNORE-END

private:
    FdoSmOvTableMappingType mMappingType;
    FdoRdbmsOvPropertiesP mProperties;
    FdoRdbmsOvTableP                         mTable;

    FdoXmlAttributesP                        mCurrAtts;
    FdoRdbmsOvPropertyDefinition*            mCurrProp;
    FdoRdbmsOvDataPropertyP                  mCurrDataProp;
    FdoRdbmsOvGeometricPropertyP             mCurrGeomProp;
    FdoRdbmsOvObjectPropertyP                mCurrObjProp;

    // Lists the allowable sub-elements for class definition's XML element
    FdoStringsP                        mElementSubElements;
    // List of Object Property Mapping element.
    FdoStringsP                        mOpSubElements;
};

///<summary>FdoRdbmsOvClassP is a FdoPtr on FdoRdbmsOvClassDefinition, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvClassDefinition> FdoRdbmsOvClassP;

#endif



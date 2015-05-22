#ifndef FDO_RDBMSOVOBJECTPROPERTYDEFINITION_H
#define FDO_RDBMSOVOBJECTPROPERTYDEFINITION_H
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

#include <Rdbms/Override/RdbmsOv.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvPropertyMappingClass.h>
#include <Rdbms/Override/RdbmsOvPropertyMappingConcrete.h>
#include <Rdbms/Override/RdbmsOvPropertyMappingSingle.h>

///<summary>Abstract class defining physical schema overrides for an object property
///definition.</summary>
class FdoRdbmsOvObjectPropertyDefinition : virtual public FdoRdbmsOvPropertyDefinition
{
public:
    ///<summary>Gets the object property mapping definition</summary>
    /// <returns>Returns FdoRdbmsOvPropertyMappingDefinition</returns>
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingDefinition* GetMappingDefinition();

//DOM-IGNORE-BEGIN

    // XML Serialization functions, not part of API.

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(
        FdoXmlSaxContext* pContext, 
        FdoXmlAttributeCollection* attrs,
        FdoString* mappingType,
        FdoXmlAttributeCollection* mappingAttrs
    );

    // Create and optionally attach a Single table property mapping.
    FDORDBMS_OV_API virtual FdoRdbmsOvPropertyMappingSingle* CreateSingleMapping(
        bool attach // if true then make the new mapping the property mapping for 
                    // this object property. Replaces any previous mapping 
    )
    {
        return NULL;
        //TODO: exception
    }

    // Create and optionally attach a Class table property mapping.
    FDORDBMS_OV_API virtual FdoRdbmsOvPropertyMappingClass* CreateClassMapping(
        bool attach // if true then make the new mapping the property mapping for 
                    // this object property. Replaces any previous mapping 
    )
    {
        return NULL;
        //TODO: exception
    }

    // Create and optionally attach a Concrete table property mapping.
    FDORDBMS_OV_API virtual FdoRdbmsOvPropertyMappingConcrete* CreateConcreteMapping(
        bool attach // if true then make the new mapping the property mapping for 
                    // this object property. Replaces any previous mapping 
    )
    {
        return NULL;
        //TODO: exception
    }

//DOM-IGNORE-END


protected:
    FDORDBMS_OV_API FdoRdbmsOvObjectPropertyDefinition();
    FDORDBMS_OV_API FdoRdbmsOvObjectPropertyDefinition(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvObjectPropertyDefinition();

    // Sets the object property mapping
    FDORDBMS_OV_API void SetMappingDefinition(FdoRdbmsOvPropertyMappingDefinition* propertyMappingDefinition);

    // Serialize provider-specific parts of this override to XML.
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
    FdoRdbmsOvPropertyMappingP mPropertyMappingDefinition;
};

///<summary>FdoRdbmsOvObjectPropertyP is a FdoPtr on FdoRdbmsOvObjectPropertyDefinition, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvObjectPropertyDefinition> FdoRdbmsOvObjectPropertyP;

#endif


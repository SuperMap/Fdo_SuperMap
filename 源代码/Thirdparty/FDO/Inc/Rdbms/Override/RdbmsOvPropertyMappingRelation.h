#ifndef FDO_RDBMSOVPROPERTYMAPPINGRELATION_H
#define FDO_RDBMSOVPROPERTYMAPPINGRELATION_H
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
#include <Rdbms/Override/RdbmsOvPropertyMappingDefinition.h>

class FdoRdbmsOvClassDefinition;

///<summary>
///Abstract class defining the physical schema overrides for relation type 
///object property table mappings.
///</summary>
class FdoRdbmsOvPropertyMappingRelation : public virtual FdoRdbmsOvPropertyMappingDefinition
{

public:

    ///<summary>Gets the internal class</summary>
    /// <returns>Returns the internal class</returns>
    FDORDBMS_OV_API FdoRdbmsOvClassDefinition* GetInternalClass();

//DOM-IGNORE-BEGIN

    // Serialize this property to XML. Not part of the API.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Creates and optionally attaches an internal class override object.
    FDORDBMS_OV_API virtual FdoRdbmsOvClassDefinition* CreateInternalClass(
        bool attach // if true then make the new class the internal class for 
                    // this property mapping. Replaces any previous internal class 
    )
    {
        // TODO: throw exception.
        return NULL;
    }
//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingRelation();
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyMappingRelation();

    ///<summary>Sets the internal class</summary>
    /// <returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetInternalClass(FdoRdbmsOvClassDefinition* classDefinition);

    // Handle start of sub-elements when deserializing from XML.
    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

    // Handle end of sub-elements when deserializing from XML.
    FDORDBMS_OV_API virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname
    );


private:
    FdoPtr<FdoRdbmsOvClassDefinition> mClassDefinition;
};

///<summary>
///FdoRdbmsOvPropertyMappingRelationP is a FdoPtr on 
///FdoRdbmsOvPropertyMappingRelation, provided for convenience.
///</summary>
typedef FdoPtr<FdoRdbmsOvPropertyMappingRelation> FdoRdbmsOvPropertyMappingRelationP;

#endif


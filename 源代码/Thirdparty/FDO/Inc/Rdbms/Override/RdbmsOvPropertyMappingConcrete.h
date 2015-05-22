#ifndef FDO_RDBMSOVPROPERTYMAPPINGRCONCRETE_H
#define FDO_RDBMSOVPROPERTYMAPPINGRCONCRETE_H
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
#include <Rdbms/Override/RdbmsOvPropertyMappingRelation.h>

///<summary>
///Abstract class defining the physical schema overrides for the Concrete 
///type object property mapping. Under the Concrete mapping type, each object 
///property is kept in its own table.
///</summary>
class FdoRdbmsOvPropertyMappingConcrete : public virtual FdoRdbmsOvPropertyMappingRelation
{

public:
//DOM-IGNORE-BEGIN

    // XML Serialization functions, not part of the API.

    // Serialize this property to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingConcrete();
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyMappingConcrete();

    // Handle sub-elements when deserializing from XML.
    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

private:
};

///<summary>
///FdoRdbmsOvPropertyMappingConcreteP is a FdoPtr on 
///FdoRdbmsOvPropertyMappingConcrete, provided for convenience.
///</summary>
typedef FdoPtr<FdoRdbmsOvPropertyMappingConcrete> FdoRdbmsOvPropertyMappingConcreteP;

#endif



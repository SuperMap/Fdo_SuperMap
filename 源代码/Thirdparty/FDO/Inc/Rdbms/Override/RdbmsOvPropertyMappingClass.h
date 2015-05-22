#ifndef FDO_RDBMSOVPROPERTYMAPPINGRCLASS_H
#define FDO_RDBMSOVPROPERTYMAPPINGRCLASS_H
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

//DOM-IGNORE-BEGIN

///<summary>Abstract class defining the physical schema overrides for the Class
///type object property mapping.</summary>
class FdoRdbmsOvPropertyMappingClass : public virtual FdoRdbmsOvPropertyMappingRelation
{
public:
    // Serialize this property to XML. Not part of the API.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingClass();
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyMappingClass();

    // Handle sub-elements when deserializing from XML.
    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

};

///<summary>FdoRdbmsOvPropertyMappingClassP is a FdoPtr on FdoRdbmsOvPropertyMappingClass, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvPropertyMappingClass> FdoRdbmsOvPropertyMappingClassP;

//DOM-IGNORE-END

#endif


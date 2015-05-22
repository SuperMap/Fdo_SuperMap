#ifndef FDO_RDBMSOVPROPERTYMAPPINGDEFINITION_H
#define FDO_RDBMSOVPROPERTYMAPPINGDEFINITION_H
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

#include <FdoCommon.h>
#include <Fdo/Xml/Flags.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Rdbms/Override/RdbmsOv.h>

///<summary>
///Abstract class defining the physical schema overrides for object 
///property table mappings.
///</summary>
class FdoRdbmsOvPropertyMappingDefinition : public FdoPhysicalElementMapping
{
public:

//DOM-IGNORE-BEGIN

    // The following functions are for internal use and are not part of the API.

    // Sets the parent of this object.
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    // Serialize this property to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingDefinition();
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyMappingDefinition();
};

///<summary>
///FdoRdbmsOvPropertyMappingP is a FdoPtr on FdoRdbmsOvPropertyMappingDefinition,
///provided for convenience.
///</summary>
typedef FdoPtr<FdoRdbmsOvPropertyMappingDefinition> FdoRdbmsOvPropertyMappingP;

#endif


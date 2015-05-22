#ifndef FDO_RDBMSOVPROPERTYDEFINITION_H
#define FDO_RDBMSOVPROPERTYDEFINITION_H
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

#include <Fdo/Commands/Schema/PhysicalPropertyMapping.h>
#include <Rdbms/Override/RdbmsOv.h>

///<summary>Abstract class defining physical schema overrides for a property
///definition.</summary>
class FdoRdbmsOvPropertyDefinition : public FdoPhysicalPropertyMapping
{
public:
//DOM-IGNORE-BEGIN
    // Serialize this property to XML. Not part of the API.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Makes SetParent function public
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);

//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyDefinition();
    FDORDBMS_OV_API FdoRdbmsOvPropertyDefinition(FdoString *name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyDefinition();

    // Serialize this property to XML. 
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);
};

///<summary>FdoRdbmsOvPropertyP is a FdoPtr on FdoRdbmsOvPropertyDefinition, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvPropertyDefinition> FdoRdbmsOvPropertyP;

#endif


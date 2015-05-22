#ifndef FDO_RDBMSOVGEOMETRICCOLUMN_H
#define FDO_RDBMSOVGEOMETRICCOLUMN_H
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

#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Rdbms/Override/RdbmsOv.h>

///<summary>Abstract base class for defining physical schema overrides for a 
///geometric column.
///</summary>
class FdoRdbmsOvGeometricColumn : public FdoPhysicalElementMapping
{
public:
//DOM-IGNORE-BEGIN

    // Sets the parent of this object. Not part of the API.
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);

    // Serialize this property to XML. Not part of the API.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvGeometricColumn();
    FDORDBMS_OV_API FdoRdbmsOvGeometricColumn(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvGeometricColumn();

    // Serialize provider-specific parts of this override to XML
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );


};

///<summary>FdoRdbmsOvGeometricColumnP is a FdoPtr on FdoRdbmsOvGeometricColumn, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvGeometricColumn> FdoRdbmsOvGeometricColumnP;

#endif


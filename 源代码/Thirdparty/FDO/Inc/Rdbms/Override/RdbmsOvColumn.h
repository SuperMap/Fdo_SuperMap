#ifndef FDO_RDBMSOVCOLUMN_H
#define FDO_RDBMSOVCOLUMN_H
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

#include <Fdo.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Rdbms/Override/RdbmsOv.h>

///<summary>Abstract class defining physical schema overrides for a column.</summary>
class FdoRdbmsOvColumn : public FdoPhysicalElementMapping
{
public:

//DOM-IGNORE-BEGIN
    // Sets the parent of this object. Not part of the API.
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);

    // Serialize this override to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

protected:
    FDORDBMS_OV_API FdoRdbmsOvColumn();
    FDORDBMS_OV_API FdoRdbmsOvColumn(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvColumn();


    // Serialize provider-specific parts of this override to XML.
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );
//DOM-IGNORE-END

private:
};

///<summary>FdoRdbmsOvColumnP is a FdoPtr on FdoRdbmsOvColumn, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvColumn> FdoRdbmsOvColumnP;



#endif


#ifndef FDO_RDBMSOVTABLE_H
#define FDO_RDBMSOVTABLE_H
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
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Rdbms/Override/RdbmsOv.h>

///<summary>Abstract class defining physical schema overrides for a table.</summary>
class FdoRdbmsOvTable : public FdoPhysicalElementMapping
{
public:
    ///<summary>Gets the primary key nane</summary>
    ///<returns>Returns the primary key name</returns>
    FDORDBMS_OV_API FdoString *GetPKeyName();

    ///<summary>Sets the primary key name</summary>
    /// <param name="pKeyName">Input the primary key name</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetPKeyName(FdoString *pKeyName);

//DOM-IGNORE-BEGIN
    // Makes SetParent function public.
    FDORDBMS_OV_API void SetParent(FdoPhysicalElementMapping* value);

    // Serialize this property to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);
//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvTable();
    FDORDBMS_OV_API FdoRdbmsOvTable(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvTable();

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

    // Write provider-specific parts to XML.
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
    FdoStringP mPKeyName;

};

///<summary>FdoRdbmsOvTableP is a FdoPtr on FdoRdbmsOvTable, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvTable> FdoRdbmsOvTableP;

#endif


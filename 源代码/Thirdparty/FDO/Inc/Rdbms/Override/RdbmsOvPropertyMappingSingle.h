#ifndef FDO_RDBMSOVPROPERTYMAPPINGSINGLE_H
#define FDO_RDBMSOVPROPERTYMAPPINGSINGLE_H
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
#include <Rdbms/Override/RdbmsOv.h>
#include <Rdbms/Override/RdbmsOvPropertyMappingDefinition.h>


///<summary>
///Abstract class defining the physical schema overrides for the Single 
///type object property mapping. Under the Single mapping type, the object 
///property is kept in the same table as its containing class.
///</summary>
class FdoRdbmsOvPropertyMappingSingle : public virtual FdoRdbmsOvPropertyMappingDefinition
{
public:
    ///<summary>
    ///Gets the prefix which is prepended to the name of each column
    ///</summary>
    /// <returns>Returns the prefix</returns>
    FDORDBMS_OV_API FdoString* GetPrefix();

    ///<summary>Sets the prefix</summary>
    /// <returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetPrefix(FdoString* prefix);

//DOM-IGNORE-BEGIN

    // XML Serialization functions, not part of the API.

    // Serialize this property to XML.
    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    // Initialize this element from its XML attributes
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

//DOM-IGNORE-END

protected:
    FDORDBMS_OV_API FdoRdbmsOvPropertyMappingSingle();
    FDORDBMS_OV_API virtual ~FdoRdbmsOvPropertyMappingSingle();

    // Handle sub-elements when deserializing from XML.
    FDORDBMS_OV_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context,
        FdoString* uri,
        FdoString* name,
        FdoString* qname,
        FdoXmlAttributeCollection* atts
    );

private:
    FdoStringP  mPrefix;
};

///<summary>
///FdoRdbmsOvPropertyMappingSingleP is a FdoPtr on 
///FdoRdbmsOvPropertyMappingSingle, provided for convenience.
///</summary>
typedef FdoPtr<FdoRdbmsOvPropertyMappingSingle> FdoRdbmsOvPropertyMappingSingleP;

#endif


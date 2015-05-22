
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

#ifndef _FDOTOPOFEATUREPROPERTYDEFINITION_H_
#define _FDOTOPOFEATUREPROPERTYDEFINITION_H_

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Schema/PropertyDefinition.h>

/// \brief
/// FdoTopoFeaturePropertyDefinition derives from FdoPropertyDefinition and its
/// values can be used to relate topological primitives to one or more
/// application domain features. One can use the short form "TopoFeature" to
/// refer to these properties. The semantics of this property are similar to
/// Object properties. One uses FdoIFeatureReader::GetObject() to retrieve
/// values.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
/// \remarks
/// FdoTopoFeaturePropertyDefinition and FdoTopoGeometryPropertyDefinition are
/// the matching roles of many:many relationships between topological primitives
/// and application domain features. FDO Association properties are not used for
/// these roles because topological relationships are not between fixed classes.
/// The relationships are populated only from the TopoGeometry role, so
/// TopoFeature properties need never be subject to an insertion or update
/// operation. 
class FdoTopoFeaturePropertyDefinition : public FdoPropertyDefinition
{
public:

    /// \brief
    /// Constructs an instance of an FdoTopoFeaturePropertyDefinition using the
    /// specified arguments.
    /// 
    FDO_API static FdoTopoFeaturePropertyDefinition * Create(
        FdoString * name, 
        FdoString * description,
        bool        system = false
    );

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML support

    /// Initialize the class from its XML attributes
    virtual void InitFromXml(FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);
    virtual void InitFromXml(FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Handle sub-elements such as properties
    /// Element start
    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    /// Element end
    virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );

    /// Serialize this class to XML.
  	virtual void _writeXml( FdoSchemaXmlContext* pContext );

protected:
    /// \brief
    /// Dispose this object.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Dispose ();
 
    /// Hide default constructor to ensure that it cannot be used.
    FdoTopoFeaturePropertyDefinition() {};
    virtual ~FdoTopoFeaturePropertyDefinition() {};

    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
/// \endcond
};



#endif /* _FDOTOPOFEATUREPROPERTYDEFINITION_H_ */



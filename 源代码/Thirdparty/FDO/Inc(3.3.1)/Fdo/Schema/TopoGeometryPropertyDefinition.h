#ifndef _FDOTOPOGEOMETRYPROPERTYDEFINITION_H_
#define _FDOTOPOGEOMETRYPROPERTYDEFINITION_H_

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

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Schema/GeometricPropertyDefinition.h>

/// \brief
/// FdoTopoGeometryPropertyDefinition derives from
/// FdoGeometricPropertyDefinition, but it has behavior of both geometry and
/// fixed association. It can be used to relate an application-domain feature
/// class (other than a topological primitive class) to a topology. One can use
/// the short form TopoGeometry to refer to these properties.  Values of this
/// property can be used:
/// <ul>
/// <li> as spatial geometries; use FdoIFeatureReader::GetGeometry().
/// <li> to gain access to relationships to underlying features, including
/// topology primitives, similar to Association Properties; e.g. use
/// FdoIFeatureReader::GetObject() to retrieve, and associated feature
/// identifiers to insert/update.
/// </ul>
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoTopoGeometryPropertyDefinition : public FdoGeometricPropertyDefinition
{
public:
    FdoTopoGeometryPropertyDefinition(
        FdoString * name, 
        FdoString * description, 
        FdoString * topologyName,
        bool        system = false
    );

    /// Get the name of the topology to which this property belongs.
    FdoString * GetTopologyName();

    /// Set the name of the topology to which this property belongs. The
    /// referenced topology must exist.
    void SetTopologyName(
        FdoString * topologyName
    );

    /// Gets the topo geometry property definition on which the current topo
    /// geometry property depends. If the current property is not in a topology
    /// hierarchy, then null is returned.
    FdoTopoGeometryPropertyDefinition * GetDependsOnTopoGeometry();

    /// Set the top geometry property on which the current topo geometry
    /// property depends. This is set only if the current topo geometry property
    /// is in a topology hierarchy. Set it to null (the default) to indicate
    /// that the current property is not in a topology hierarchy.
    void SetDependsOnTopoGeometry(
        FdoTopoGeometryPropertyDefinition * dependsOnTopoGeometry
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
    /// The name of the related topology.
    FdoString * topologyName;

    FdoTopoGeometryPropertyDefinition * dependsOnTopoGeometry;

    /// \brief
    /// Dispose this object.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Dispose ();
 
    /// Hide default constructor to ensure that it cannot be used.
    FdoTopoGeometryPropertyDefinition() {};
    virtual ~FdoTopoGeometryPropertyDefinition();

    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
/// \endcond
};



#endif /* _FDOTOPOGEOMETRYPROPERTYDEFINITION_H_ */



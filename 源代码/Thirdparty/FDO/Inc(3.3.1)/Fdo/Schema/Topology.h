#ifndef _FDOTOPOLOGY_H_
#define _FDOTOPOLOGY_H_

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
#include <Fdo/Schema/ClassDefinition.h>

/// \brief
/// This class is used to represent a topology.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoTopology : public FdoClassDefinition
{
    public:
    /// Constructor
    FdoTopology(
    /// The topology name.
        FdoString * name, 
    /// The topology description.
        FdoString * description, 
    /// The name of the spatial context from which to aquire spatial
    /// parameters for the topology.
        FdoString * spatialContext
    );

    /// Get the name of the node primitive feature class for this topology.
    FdoString * GetNodeClassName();

    /// Get the name of the edge primitive feature class for this topology.
    FdoString * GetEdgeClassName();

    /// Get the name of the face primitive feature class for this topology.
    FdoString * GetFaceClassName();

    /// Get the name of the spatial context for this topology.
    FdoString * GetSpatialContextName();

    /// Set the name of the spatial context for this topology. The spatial
    /// context must already exist.
    void SetSpatialContextName(
        FdoString * spatialContextName
    );

    private:
    /// The system-generated name of the feature class for node primitives in
    /// this topology.
    FdoString * nodeClassName;

    /// The system-generated name of the feature class for edge primitives in
    /// this topology.
    FdoString * edgeClassName;

    /// The system-generated name of the feature class for face primitives in
    /// this topology.
    FdoString * faceClassName;

    /// The name of the spatial context in which the topology’s spatial data is
    /// defined.  The spatial context is used to acquire extents, coordinate
    /// system and internal tolerances.  It is also used as the common reference
    /// for spatial queries that span more than one topological feature class.
    FdoString * spatialContextName;

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
 
/// \cond DOXYGEN-IGNORE

    /// Hide default constructor to ensure that it cannot be used.
    FdoTopology() {};
    virtual ~FdoTopology();

    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
 /// \endcond
};



#endif /* _FDOTOPOLOGY_H_ */



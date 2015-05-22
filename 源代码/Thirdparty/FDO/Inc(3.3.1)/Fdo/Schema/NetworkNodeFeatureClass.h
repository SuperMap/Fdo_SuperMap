#ifndef _NETWORKNODEFEATURECLASS_H_
#define _NETWORKNODEFEATURECLASS_H_

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
#include <Fdo/Schema/NetworkFeatureClass.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// FdoNetworkNodeFeature derives from FdoNetworkFeature and can be used to represent a 
/// logical node feature.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoNetworkNodeFeatureClass : public FdoNetworkFeatureClass
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNetworkNodeFeatureClass.
    FdoNetworkNodeFeatureClass();

    /// Constructs an instance of an FdoNetworkNodeFeatureClass using the specified arguments.
    FdoNetworkNodeFeatureClass(FdoString* name, FdoString* description);

    virtual ~FdoNetworkNodeFeatureClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoNetworkNodeFeatureClass.
    /// 
    /// \return
    /// Returns FdoNetworkNodeFeatureClass
    /// 
    FDO_API static FdoNetworkNodeFeatureClass* Create();

    /// \brief
    /// Constructs an instance of an FdoNetworkNodeFeatureClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoNetworkNodeFeatureClass
    /// 
    FDO_API static FdoNetworkNodeFeatureClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

    /// \brief
    /// Gets a reference to the layer property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetLayerProperty();

    /// \brief
    /// Sets a reference to the layer property. The associated class of the layer
    /// association property must be an FdoNetworkLayer.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLayerProperty(FdoAssociationPropertyDefinition* value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the layer property
    // is marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

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


    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );


private:
    FdoAssociationPropertyDefinition    *m_layer;

    FdoAssociationPropertyDefinition    *m_layerHandler;
    bool                                m_bStartLayer;
protected:
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoAssociationPropertyDefinition    *m_layerCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoNetworkNodeFeatureClassP is a FdoPtr on FdoNetworkNodeFeatureClass, provided for convenience.
typedef FdoPtr<FdoNetworkNodeFeatureClass> FdoNetworkNodeFeatureClassP;

#endif



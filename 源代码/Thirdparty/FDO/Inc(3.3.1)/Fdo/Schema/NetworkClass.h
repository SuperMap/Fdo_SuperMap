#ifndef _NETWORKCLASS_H_
#define _NETWORKCLASS_H_

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
#include <Fdo/Schema/NetworkLayerClass.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/AssociationPropertyDefinition.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// FdoNetworkClass derives from FdoClassDefinition and can be used to represent a 
/// linear network. The FdoNetworkClass type has 2 pre-defined base properties. The first is a bool 
/// type called "Directed". And the second is a FdoObjectPropertyDefinition of an ordered collection called "Layers".
/// The "Directed" property is used to indicate if the network is directed or undirected. 
/// The network is directed if the Directed property is set to true. Otherwise, it is undirected. The Layers property
/// is used to contain the ordered list of layers. The class of the layers object property must be of type FdoNetworkLayer.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoNetworkClass : public FdoClassDefinition
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNetworkClass.
    FdoNetworkClass();

    /// Constructs an instance of an FdoNetworkClass using the specified arguments.
    FdoNetworkClass(FdoString* name, FdoString* description);

    virtual ~FdoNetworkClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoNetworkClass.
    /// 
    /// \return
    /// Returns FdoNetworkClass
    /// 
    FDO_API static FdoNetworkClass* Create();

    /// \brief
    /// Constructs an instance of an FdoNetworkClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoNetworkClass
    /// 
    FDO_API static FdoNetworkClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

    /// \brief
    /// Gets a reference to the layer class.
    /// 
    /// \return
    /// Returns a network layer class definition
    /// 
    FDO_API FdoNetworkLayerClass* GetLayerClass();

    /// \brief
    /// Sets a reference to the layer class. The layer class is used to define the system
    /// layers ordered collection object  property.
    /// 
    /// \param value 
    /// Input an network layer class
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLayerClass(FdoNetworkLayerClass* value);

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML and Schema Merge support

    /// Update this property from the given property.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the network layer class
    // is marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );

private:
    FdoNetworkLayerClass            *m_layerClass;

protected:
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoNetworkLayerClass            *m_layerClassCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoNetworkClassP is a FdoPtr on FdoNetworkClass, provided for convenience.
typedef FdoPtr<FdoNetworkClass> FdoNetworkClassP;

#endif



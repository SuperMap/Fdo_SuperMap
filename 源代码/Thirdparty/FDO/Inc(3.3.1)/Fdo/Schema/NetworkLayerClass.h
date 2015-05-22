#ifndef _NETWORKLAYERCLASS_H_
#define _NETWORKLAYERCLASS_H_

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
#include <Fdo/Schema/ClassType.h>

/// \brief
/// FdoNetworkLayerClass derives from FdoClassDefinition and can be used to represent a 
/// network layer.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoNetworkLayerClass : public FdoClassDefinition
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNetworkLayerClass.
    FdoNetworkLayerClass();

    /// Constructs an instance of an FdoNetworkLayerClass using the specified arguments.
    FdoNetworkLayerClass(FdoString* name, FdoString* description);

    virtual ~FdoNetworkLayerClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoNetworkLayerClass.
    /// 
    /// \return
    /// Returns FdoNetworkLayerClass
    /// 
    FDO_API static FdoNetworkLayerClass* Create();

    /// \brief
    /// Constructs an instance of an FdoNetworkLayerClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoNetworkLayerClass
    /// 
    FDO_API static FdoNetworkLayerClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML and Schema Merge support

    /// Update this property from the given property.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );


protected:
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoNetworkLayerClassP is a FdoPtr on FdoNetworkLayerClass, provided for convenience.
typedef FdoPtr<FdoNetworkLayerClass> FdoNetworkLayerClassP;

#endif



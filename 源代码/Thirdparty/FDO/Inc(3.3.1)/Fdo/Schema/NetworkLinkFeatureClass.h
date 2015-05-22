#ifndef _NETWORKLINKFEATURECLASS_H_
#define _NETWORKLINKFEATURECLASS_H_

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
#include <Fdo/Schema/GeometricPropertyDefinition.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// FdoNetworkLinkFeature derives from FdoNetworkFeature 
/// and can be used to represent a logical link feature.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoNetworkLinkFeatureClass : public FdoNetworkFeatureClass
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNetworkLinkFeatureClass.
    FdoNetworkLinkFeatureClass();

    /// Constructs an instance of an FdoNetworkLinkFeatureClass using the specified arguments.
    FdoNetworkLinkFeatureClass(FdoString* name, FdoString* description);

    virtual ~FdoNetworkLinkFeatureClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoNetworkLinkFeatureClass.
    /// 
    /// \return
    /// Returns FdoNetworkLinkFeatureClass
    /// 
    FDO_API static FdoNetworkLinkFeatureClass* Create();

    /// \brief
    /// Constructs an instance of an FdoNetworkLinkFeatureClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoNetworkLinkFeatureClass
    /// 
    FDO_API static FdoNetworkLinkFeatureClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

    /// \brief
    /// Gets a reference to the start node property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetStartNodeProperty();

    /// \brief
    /// Sets a reference to the start node property.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetStartNodeProperty(FdoAssociationPropertyDefinition* value);

    /// \brief
    /// Gets a reference to the end node property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetEndNodeProperty();

    /// \brief
    /// Sets a reference to the end node property.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetEndNodeProperty(FdoAssociationPropertyDefinition* value);
    
/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the start or end node properties 
    // are marked for delete.
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
    FdoAssociationPropertyDefinition    *m_startNodeFeature;
    FdoAssociationPropertyDefinition    *m_endNodeFeature;

    bool                                m_bStartNode;
    bool                                m_bEndNode;
    FdoAssociationPropertyDefinition    *m_startNodeFeatureHandler;
    FdoAssociationPropertyDefinition    *m_endNodeFeatureHandler;

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoAssociationPropertyDefinition    *m_startNodeFeatureCHANGED;
    FdoAssociationPropertyDefinition    *m_endNodeFeatureCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoNetworkLinkFeatureClassP is a FdoPtr on FdoNetworkLinkFeatureClass, provided for convenience.
typedef FdoPtr<FdoNetworkLinkFeatureClass> FdoNetworkLinkFeatureClassP;

#endif



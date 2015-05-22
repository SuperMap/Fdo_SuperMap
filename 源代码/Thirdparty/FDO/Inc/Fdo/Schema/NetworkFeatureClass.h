#ifndef _NETWORKFEATURECLASS_H_
#define _NETWORKFEATURECLASS_H_

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
#include <Fdo/Schema/FeatureClass.h>
#include <Fdo/Schema/AssociationPropertyDefinition.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// FdoNetworkFeature is an abstract class that derives from FdoFeatureClass and is a base 
/// for the FdoNetworkNodeFeature and FdoNetworkLinkFeature.
/// \note
/// This Help topic is provided for informational use only. There is
/// no interface or support provided. Autodesk reserves the right to change
/// the software related to the content herein.
class FdoNetworkFeatureClass : public FdoFeatureClass
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNetworkFeatureClass.
    /// To make a class of this type, you need to either create a FdoNetworkNodeFeatureClass
    /// or FdoNetworkLinkFeatureClass.
    FdoNetworkFeatureClass();

    /// Constructs an instance of an FdoNetworkNodeFeatureClass using the specified arguments.
    FdoNetworkFeatureClass(FdoString* name, FdoString* description);

    virtual ~FdoNetworkFeatureClass();
/// \endcond

public:

    /// \brief
    /// Gets a reference to the cost property.
    /// 
    /// \return
    /// Returns a property definition
    /// 
    FDO_API FdoDataPropertyDefinition* GetCostProperty();

    /// \brief
    /// Sets a reference to the cost property.
    /// 
    /// \param value 
    /// Input a property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetCostProperty(FdoDataPropertyDefinition* value);

    /// \brief
    /// Gets a reference to the network property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetNetworkProperty();

    /// \brief
    /// Sets a reference to the network property.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetNetworkProperty(FdoAssociationPropertyDefinition* value);

    /// \brief
    /// Gets a reference to the referenced feature property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetReferencedFeatureProperty();

    /// \brief
    /// Sets a reference to the referenced feature property.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetReferencedFeatureProperty(FdoAssociationPropertyDefinition* value);

    /// \brief
    /// Gets a reference to the parent network feature property.
    /// 
    /// \return
    /// Returns an association property definition
    /// 
    FDO_API FdoAssociationPropertyDefinition* GetParentNetworkFeatureProperty();

    /// \brief
    /// Sets a reference to the parent network feature property.
    /// 
    /// \param value 
    /// Input an association property definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetParentNetworkFeatureProperty(FdoAssociationPropertyDefinition* value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoClassDefinition* pProperty, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if any of the  cost, referenced feature, network 
    // or parent network properties are marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
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


    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );


private:
    FdoDataPropertyDefinition           *m_costProperty;
    FdoAssociationPropertyDefinition    *m_network;
    FdoAssociationPropertyDefinition    *m_referencedFeature;
    FdoAssociationPropertyDefinition    *m_parentNetworkFeature;

    bool                                m_bNetwork;
    bool                                m_bReferenceFeature;
    bool                                m_bParentNetwork;

    FdoAssociationPropertyDefinition    *m_networkHandler;
    FdoAssociationPropertyDefinition    *m_referencedFeatureHandler;
    FdoAssociationPropertyDefinition    *m_parentNetworkFeatureHandler;


protected:
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoDataPropertyDefinition           *m_costPropertyCHANGED;
    FdoAssociationPropertyDefinition    *m_networkCHANGED;
    FdoAssociationPropertyDefinition    *m_referencedFeatureCHANGED;
    FdoAssociationPropertyDefinition    *m_parentNetworkFeatureCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoNetworkFeatureClassP is a FdoPtr on FdoNetworkFeatureClass, provided for convenience.
typedef FdoPtr<FdoNetworkFeatureClass> FdoNetworkFeatureClassP;

#endif



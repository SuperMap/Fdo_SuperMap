#ifndef _FEATURECLASS_H_
#define _FEATURECLASS_H_

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
#include <Fdo/Schema/GeometricPropertyDefinition.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// The FdoFeatureClass class can be used to represent spatial or non-spatial features.
/// Spatial features must have at lease one geometric property. The FdoFeatureClass
/// type has one pre-defined base property "Bounds". The "Bounds" read-only
/// property can be used to get the geometric boundary of the spatial feature.
/// The value of this property will be null if the feature is not a spatial
/// feature.
class FdoFeatureClass : public FdoClassDefinition
{
    template <class OBJ> friend class FdoSchemaCollection;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoFeatureClass.
    FdoFeatureClass();

    /// Constructs an instance of an FdoFeatureClass using the specified arguments.
    FdoFeatureClass(FdoString* name, FdoString* description);

    virtual ~FdoFeatureClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoFeatureClass.
    /// 
    /// \return
    /// Returns FdoFeatureClass
    /// 
    FDO_API static FdoFeatureClass* Create();

    /// \brief
    /// Constructs an instance of an FdoFeatureClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoFeatureClass
    /// 
    FDO_API static FdoFeatureClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

    /// \brief
    /// Gets the geometric property that defines the geometry for this spatial 
    /// feature class.
    /// 
    /// \return
    /// Returns the geometric property
    /// 
    FDO_API FdoGeometricPropertyDefinition* GetGeometryProperty();

    /// \brief
    /// Sets the geometric property that defines the geometry for this spatial 
    /// feature class. The specified FdoGeometricPropertyDefinition must be a member 
    /// of either the FdoClassDefinition.GetBaseProperties or FdoClassDefinition.GetProperties 
    /// collection.
    /// 
    /// \param value 
    /// Input the geometric property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetGeometryProperty(FdoGeometricPropertyDefinition* value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this feature class from the given feature class.
    virtual void Set( FdoClassDefinition* pClass, FdoSchemaMergeContext* pContext );

    // Checks referenced elements. 
    // Adds errors to the given merge context if the GeometryProperty
    // is marked for delete.
    virtual void CheckReferences( FdoSchemaMergeContext* pContext );

    /// Initialize the feature class from its XML attributes
    virtual void InitFromXml(FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this feature class to XML.
  	virtual void _writeXml( FdoSchemaXmlContext* pContext );
    virtual void _writeBaseXml( FdoSchemaXmlContext* pContext );

private:
    FdoGeometricPropertyDefinition* m_geometry;

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    FdoGeometricPropertyDefinition* m_geometryCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoFeatureClassP is a FdoPtr on FdoFeatureClass, provided for convenience.
typedef FdoPtr<FdoFeatureClass> FdoFeatureClassP;

#endif



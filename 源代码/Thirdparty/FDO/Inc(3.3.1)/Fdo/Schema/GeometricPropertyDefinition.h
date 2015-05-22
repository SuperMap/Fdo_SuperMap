#ifndef _GEOMETRICPROPERTYDEFINITION_H_
#define _GEOMETRICPROPERTYDEFINITION_H_

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
#include <Fdo/Schema/PropertyDefinition.h>
#include <Common/GeometryType.h>
#include <Fdo/Schema/PropertyType.h>

#define MAX_GEOMETRY_TYPE_SIZE    12
#define MAX_GEOMETRIC_TYPE_SIZE    4

/// \brief
/// FdoGeometricPropertyDefinition derives from FdoPropertyDefinition and represents a
/// geometric value. Geometric properties can take on any of the geometric types
/// listed in the FdoGeometricType enumeration. 
/// \note
/// Geometric properties do
/// not actually store the coordinate system or measure units, this is to enable
/// the use of the same schema in different geometric locals. FdoGeometricType
/// informs the client application what types of geometric primitives it can
/// expect when reading a particular geometric property (and what types they can
/// store in the property on insert/update). The client application can
/// interpret the actual geometry values as it wants, e.g., displaying and
/// manipulating the vertices of a Polyline as a group of independent points.
class FdoGeometricPropertyDefinition : public FdoPropertyDefinition
{
    friend class FdoFeatureClass;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoGeometricPropertyDefinition.
    FdoGeometricPropertyDefinition();

    /// Constructs an instance of an FdoGeometricPropertyDefinition using the
    /// specified arguments.
    FdoGeometricPropertyDefinition(FdoString* name, FdoString* description, bool system = false);

    virtual ~FdoGeometricPropertyDefinition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoGeometricPropertyDefinition.
    /// 
    /// \return
    /// Returns FdoGeometricPropertyDefinition
    /// 
    FDO_API static FdoGeometricPropertyDefinition *Create();

    /// \brief
    /// Constructs an instance of an FdoGeometricPropertyDefinition using the
    /// specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// \param system 
    /// Input true if this is a system generated property, false otherwise.
    /// \note
	/// A client would never set system to true, only a provider.
    /// 
    /// \return
    /// Returns FdoGeometricPropertyDefinition
    /// 
    FDO_API static FdoGeometricPropertyDefinition *Create(FdoString *name, FdoString *description, bool system = false);

    /// \brief
    /// Gets the concrete property type.
    /// 
    /// \return
    /// Returns the concrete property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType();

    /// \brief
    /// Gets the FdoGeometricTypes that can be stored in this geometric property.
    /// The returned value may be any combination of the values from the
    /// FdoGeometricType enumeration combined via a bit-wise or operation.
    /// 
    /// \return
    /// Returns the FdoGeometricTypes that can be stored in this geometric property
    /// 
    FDO_API FdoInt32 GetGeometryTypes();

    /// \brief
    /// Sets the FdoGeometricTypes that can be stored in this geometric property.
    /// The value may be any combination of the values from the FdoGeometricType
    /// enumeration combined via a bit-wise or operation.
    /// 
    /// \param value 
    /// Input the FdoGeometricTypes that can be stored in this geometric property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetGeometryTypes(FdoInt32 value);

    /// \brief
    /// Returns a Boolean value that indicates if this geometric property is
    /// read-only.
    /// 
    /// \return
    /// Returns a Boolean value that specifies whether this geometric property is
    /// read-only
    /// 
    FDO_API bool GetReadOnly();

    /// \brief
    /// Sets a Boolean value that specifies whether this geometric property is
    /// read-only.
    /// 
    /// \param value 
    /// Input a Boolean value that specifies whether this geometric property is
    /// read-only
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetReadOnly(bool value);

    /// \brief
    /// Gets a Boolean value that indicates if the geometry of this property
    /// include elevation values.
    /// 
    /// \return
    /// Returns a Boolean value that determines if the geometry of this property
    /// includes elevation values
    /// 
    FDO_API bool GetHasElevation();

    /// \brief
    /// Sets a Boolean value that determines if the geometry of this property
    /// includes elevation values.
    /// 
    /// \param value 
    /// Input a Boolean value that determines if the geometry of this property
    /// includes elevation values
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetHasElevation(bool value);

    /// \brief
    /// Gets a Boolean value that indicates if the geometry of this property
    /// includes measurement values that can be used for dynamic segmentation.
    /// 
    /// \return
    /// Returns a Boolean value that indicates if the geometry of this property
    /// includes measurement values
    /// 
    FDO_API bool GetHasMeasure();

    /// \brief
    /// Sets a Boolean value that determines if the geometry of this property
    /// includes measurement values that can be used for dynamic segmentation.
    /// 
    /// \param value 
    /// Input a Boolean value that determines if the geometry of this property
    /// includes measurement values
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetHasMeasure(bool value);

    /// \brief
    /// Sets/add a Spatial Context association to this geometric property.
    /// 
    /// \param value 
    /// Input the Spatial Context name to be added/set. 
    /// Defaults to the active Spatial Context.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetSpatialContextAssociation(FdoString *value);

    /// \brief
    /// Gets the Spatial Context name associated to this geometric property.
    /// 
    /// \return
    /// Returns a String value representing the Spatial Context name.
    /// If NULL then the geometric property is associated with all the Spatial Contexts
    /// in the datastore (supports multiple geometric representations via this property).
    /// 
    FDO_API FdoString *GetSpatialContextAssociation();

    /// \brief
    /// Gets the specific geometry types that can be stored in this geometric
    /// property. The returned value is a list of geometry types that are
    /// supported, with length being the number of types returned.
    /// 
    /// \param length 
    /// The parameter is used to return the number of geometry types being
    /// returned by the function.
    /// 
    /// \return
    /// Returns a list of geometry types that are supported.
    /// 
    FDO_API FdoGeometryType *GetSpecificGeometryTypes(FdoInt32 &length);

    /// \brief
    /// Sets the specific set of geometry types that can be stored in this
    /// geometric property. The provided value is a list of geometry types
    /// that are supported. Usually, one specific type is supported, but
    /// there can be more than one. 
    /// 
    /// \param types
    /// The specific set of geometry types that can be stored in this
    /// geometric property.
    ///
    /// \param length 
    /// Indicates the number of geometry types being stored in the provided
    /// set of geometry types.
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDO_API void SetSpecificGeometryTypes(FdoGeometryType *types, FdoInt32 length);

/// \cond DOXYGEN-IGNORE
    // Public non-API function for geometry type support (this is to pass along the
    // hex-code (bitfield) value of the supported geometry types rather than the
    // complete array.
    FDO_API FdoInt32 GetSpecificGeometryTypes();

    // Public non-API functions for XML and Schema Mergesupport

    // Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// read the geometric types from XML sub-elements.
    /// Element start
    virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* context, 
                                              FdoString* uri, 
                                              FdoString* name, 
                                              FdoString* qname, 
                                              FdoXmlAttributeCollection* atts);
    /// Element end
    virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);

    /// Serialize this property to XML.
    virtual void _writeXml(FdoSchemaXmlContext* pContext);

    /// Returns true if none of this property's setters have been called.
    bool GetAllDefaults();

private:
    FdoInt32        m_geometryTypes;
    FdoInt32        m_geometricTypes;
    bool            m_readOnly;
    bool            m_hasElevation;
    bool            m_hasMeasure;
    FdoStringP      m_associatedSCName;
    bool            m_allDefaults;
    FdoGeometryType m_types[MAX_GEOMETRY_TYPE_SIZE];
    FdoInt32        m_typesSize;
    bool            m_cacheGeometryTypes;

    /// Temporary holding place for geometric types while being
    /// deserialized from XML.
    FdoInt32        m_XmlGeometricTypes;
    FdoInt32        m_XmlGeometryTypesCount;
    FdoGeometryType m_XmlGeometryTypes[MAX_GEOMETRY_TYPE_SIZE];

    /// Function to initialize the internal geometry type collection.
    void InitGeometryTypes();

    /// Function to retrieve the current geometric type.
    FdoInt32 GetGeometricType(int pos);

    /// Function to map a geometry type to a unique number that can be used
    /// in a bit-wise operation.
    FdoInt32 MapGeometryTypeToHexCode (FdoGeometryType gType);
    FdoInt32 MapGeometryTypeToHexCode (int             pos);

    /// Function to map a geometry type hex code to the corresponding FDO geometry type.
    FdoGeometryType MapHexCodeToGeometryType (FdoInt32 gTypeHexCode);

    /// Function to cache the geometry types currently available.
    void CacheGeometryTypes();

    /// Function to initialize all member variables.
    void SetToZero();

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _RejectChanges();
    virtual void    _AcceptChanges();
    FdoInt32        m_geometryTypesCHANGED;
    FdoInt32        m_geometricTypesCHANGED;
    bool            m_readOnlyCHANGED;
    bool            m_hasElevationCHANGED;
    bool            m_hasMeasureCHANGED;
	FdoStringP      m_associatedSCNameCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoGeometricPropertyP is a FdoPtr on FdoGeometricPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoGeometricPropertyDefinition> FdoGeometricPropertyP;

#endif



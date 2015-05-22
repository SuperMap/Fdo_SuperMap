#ifndef _RASTERPROPERTYDEFINITION_H_
#define _RASTERPROPERTYDEFINITION_H_

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
#include <Fdo/Schema/DataPropertyDefinition.h>
#include <Fdo/Schema/DataType.h>
#include <Fdo/Raster/RasterDataModel.h>

/// \brief
/// The FdoRasterPropertyDefinition has the information needed to
/// create or completely describe a raster property. This class encapsulates
/// the information necessary to insert a 'new' raster, in the absence of
/// any other information, for the properties defined using this schema
/// element.
class FdoRasterPropertyDefinition : public FdoPropertyDefinition
{
    typedef FdoPropertyDefinition superclass;

    friend class FdoFeatureClass;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoRasterPropertyDefinition.
    FdoRasterPropertyDefinition ();

    /// Constructs an instance of an FdoRasterPropertyDefinition using the
    /// specified arguments.
    FdoRasterPropertyDefinition (FdoString* name, FdoString* description, bool system = false);

    /// Destructor.
    virtual ~FdoRasterPropertyDefinition ();

    //
    /// FdoIDisposable interface
    //

    /// \brief
    /// Dispose this object.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Dispose ();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoRasterPropertyDefinition.
    /// 
    /// \return
    /// Returns FdoRasterPropertyDefinition
    /// 
    FDO_API static FdoRasterPropertyDefinition* Create ();

    /// \brief
    /// Constructs an instance of an FdoRasterPropertyDefinition using the
    /// specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// \param system 
    /// Input true if this is a system generated property, false otherwise.
    /// <\note
	/// A client would never set system to true, only a provider.
    /// 
    /// \return
    /// Returns FdoRasterPropertyDefinition
    /// 
    FDO_API static FdoRasterPropertyDefinition* Create (FdoString* name, FdoString* description, bool system = false);

    //
    /// FdoPropertyDefinition interface
    //

    /// \brief
    /// Gets the concrete property type.
    /// 
    /// \return
    /// Returns the concrete property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType ();

    //
    /// Attributes.
    //

    /// \brief
    /// Returns a Boolean value that indicates if this property is read-only.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API virtual bool GetReadOnly ();

    /// \brief
    /// Sets a Boolean value that indicates if this property is read-only.
    /// 
    /// \param value 
    /// Input a Boolean value that indicates if this property is read-only
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetReadOnly (bool value);

    /// \brief
    /// Returns a Boolean value that indicates if this property's value can be
    /// null.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API virtual bool GetNullable();

    /// \brief
    /// Sets a Boolean value that indicates if this property's value can be
    /// null.
    /// 
    /// \param value 
    /// Input a Boolean value that indicates if this property's value can be
    /// null
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetNullable(bool value);

    /// \brief
    /// Gets the default data model used by this raster property.
    /// 
    /// \return
    /// Returns the current default data model.
    /// 
    FDO_API virtual FdoRasterDataModel* GetDefaultDataModel ();

    /// \brief
    /// Sets the default data model used by this raster property.
    /// Allowed values are only those data models that are acceptable to the
    /// SupportsDataModel capability.
    /// 
    /// \param datamodel 
    /// The datamodel to be used for newly created
    /// rasters, or the default datamodel to be used when returning raster data.
    /// 
    FDO_API virtual void SetDefaultDataModel (FdoRasterDataModel* datamodel);

    /// \brief
    /// Gets the default size of image file in the horizontal
    /// direction in pixels (number of columns).
    /// 
    /// \return
    /// Returns the current default horizontal image size in pixels
    /// (number of columns).
    /// 
    FDO_API virtual FdoInt32 GetDefaultImageXSize ();

    /// \brief
    /// Sets the default size of an image file in the horizontal
    /// direction in pixels (number of columns).
    /// 
    /// \param size 
    /// The desired default horizontal image size in pixels
    /// (number of columns).
    /// 
    FDO_API virtual void SetDefaultImageXSize (FdoInt32 size);

    /// \brief
    /// Gets the default size of an image file in the vertical
    /// direction in pixels (number of rows).
    /// 
    /// \return
    /// Returns the current default vertical image size in pixels
    /// (number of rows).
    /// 
    FDO_API virtual FdoInt32 GetDefaultImageYSize ();

    /// \brief
    /// Sets the default size of an image file in the vertical
    /// direction in pixels (number of rows).
    /// 
    /// \param size 
    /// The desired default vertical image size in pixels
    /// (number of rows).
    /// 
    FDO_API virtual void SetDefaultImageYSize (FdoInt32 size);

    //
    /// Spatial Context Support.
    //

    /// \brief
    /// Sets a Spatial Context association for this raster property.
    /// 
    /// \param spatialContextName 
    /// Input the Spatial Context name to be set. 
    /// Defaults to the active Spatial Context.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetSpatialContextAssociation(FdoString *spatialContextName);

    /// \brief
    /// Gets the Spatial Context name associated to this raster property.
    /// 
    /// \return
    /// Returns a String value representing the Spatial Context name.
    /// 
    FDO_API FdoString * GetSpatialContextAssociation();


/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML and Schema Merge support

    /// Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize this property to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );


private:
    bool            m_readOnly;
    bool            m_nullable;
    FdoRasterDataModel* m_model;
    FdoInt32        m_sizeX;
    FdoInt32        m_sizeY;
    FdoStringP      m_spatialContextAssociation;

private:
    FdoStringP DataModelTypeToString(FdoRasterDataModelType type);
    FdoStringP DataOrganizationToString(FdoRasterDataOrganization organization);
    FdoStringP DataTypeToString(FdoRasterDataType organization);

    FdoRasterDataModelType StringToDataModelType(FdoString *string);
    FdoRasterDataOrganization StringToDataOrganization(FdoString *string);
    FdoRasterDataType StringToDataType(FdoString *string);

protected:

    //
    /// FdoSchemaElement interface.
    //
    virtual void    _StartChanges();
    virtual void    _RejectChanges();
    virtual void    _AcceptChanges();

    bool            m_readOnlyCHANGED;
    bool            m_nullableCHANGED;
    FdoRasterDataModel* m_modelCHANGED;
    FdoInt32        m_sizeXCHANGED;
    FdoInt32        m_sizeYCHANGED;
    FdoStringP      m_scAssociationCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoRasterPropertyP is a FdoPtr on FdoRasterPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoRasterPropertyDefinition> FdoRasterPropertyP;

#endif // _RASTERPROPERTYDEFINITION_H_



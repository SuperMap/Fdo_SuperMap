#ifndef _DATAPROPERTYDEFINITION_H_
#define _DATAPROPERTYDEFINITION_H_

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
#include <Fdo/Schema/ObjectType.h>
#include <Fdo/Schema/DataType.h>
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/PropertyValueConstraint.h>

/// \brief
/// The FdoDataPropertyDefinition class derives from FdoPropertyDefinition and represents simple
/// values or collections of simple values. FdoDataPropertyDefinitions can take on
/// any of the data types listed in the FdoDataType enumeration.
class FdoDataPropertyDefinition : public FdoPropertyDefinition
{
    template <class OBJ> friend class FdoSchemaCollection;
    friend class FdoObjectPropertyDefinition;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoDataPropertyDefinition.
    FdoDataPropertyDefinition();

    /// Constructs an instance of an FdoDataPropertyDefinition using the specified arguments
    FdoDataPropertyDefinition(FdoString* name, FdoString* description, bool system = false);

    /// Common initialization code called by all constructors:
    void Init();

    virtual ~FdoDataPropertyDefinition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoDataPropertyDefinition.
    /// 
    /// \return
    /// Returns FdoDataPropertyDefinition
    /// 
    FDO_API static FdoDataPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoDataPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// \param system 
    /// Input true if this is a system generated property, otherwise falseds.
    /// 
    /// \return
    /// Returns FdoDataPropertyDefinition
    /// 
    FDO_API static FdoDataPropertyDefinition* Create(FdoString* name, FdoString* description, bool system = false);

    /// \brief
    /// Gets the concrete property type.
    /// 
    /// \return
    /// Returns the concrete property type
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType();

    /// \brief
    /// Gets the FdoDataType of this property.
    /// 
    /// \return
    /// Returns FdoDataType of this property
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Sets the FdoDataType of this property.
    /// 
    /// \param dataType 
    /// Input the FdoDataType of this property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDataType(FdoDataType dataType);

    /// \brief
    /// Returns a Boolean value that indicates if this property is read-only.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API bool GetReadOnly();

    /// \brief
    /// Sets a Boolean value that indicates if this property is read-only.
    /// 
    /// \param value 
    /// Input a Boolean value that indicates if this property is read-only
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetReadOnly(bool value);

    /// \brief
    /// Gets the length of a String, BLOB, or CLOB data property. This value
    /// does not apply to any other FdoDataType.
    /// 
    /// \return
    /// Returns the length of a String, BLOB, or CLOB data property
    /// 
    FDO_API FdoInt32 GetLength();

    /// \brief
    /// Sets the length of a String, BLOB, or CLOB data property. This value is
    /// ignored for all other FdoDataType values.
    /// 
    /// \param value 
    /// Input the length of a String, BLOB, or CLOB data property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLength(FdoInt32 value);

    /// \brief
    /// Gets the precision (total number of digits) of a decimal data property.
    /// This value does not apply to any other FdoDataType.
    /// 
    /// \return
    /// Returns the precision
    /// 
    FDO_API FdoInt32 GetPrecision();

    /// \brief
    /// Sets the precision (total number of digits) of a decimal data property.
    /// This value is ignored for all other FdoDataType values.
    /// 
    /// \param value 
    /// Input the precision
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetPrecision(FdoInt32 value);

    /// \brief
    /// Gets the scale (number of digits to the right of the decimal point) of a
    /// decimal data property. This value does not apply to any other FdoDataType.
    /// 
    /// \return
    /// Returns the scale
    /// 
    FDO_API FdoInt32 GetScale();

    /// \brief
    /// Sets the scale (number of digits to the right of the decimal point) of a
    /// decimal data property. This value is ignored for all other FdoDataType values.
    /// 
    /// \param value 
    /// Input the scale
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetScale(FdoInt32 value);

    /// \brief
    /// Returns a Boolean value that indicates if this property's value can be
    /// null.
    /// 
    /// \return
    /// Returns a Boolean value
    /// 
    FDO_API bool GetNullable();

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
    FDO_API void SetNullable(bool value);

    /// \brief
    /// Gets the default value for this property. The default value is used when
    /// an instance of the containing class is created without specifying a value
    /// for this property.
    /// 
    /// \return
    /// Returns the default value
    /// 
    FDO_API FdoString* GetDefaultValue();

    /// \brief
    /// Sets the default value for this property. The default value is used when
    /// an instance of the containing class is created without specifying a value
    /// for this property.
    /// 
    /// \param value 
    /// Input the default value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDefaultValue(FdoString* value);

    /// \brief
    /// Sets a Boolean value that indicates if this is an autogenerated property.
    /// 
    /// \param value 
    /// Input a Boolean value that indicates if this property should
    /// be automatically generated by the provider. If true, then the provider will auto-generate
    /// unique id values for objects of the class containing this property.
    /// The provider will set the attribute properties to read-only.
    /// If the provider does not support auto-generation or if the data types of the
    /// property is not supported for unique id generation by the provider, then the provider will
    /// throw an AutoGenerationException. If false, then the provider will not autogenerate values.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetIsAutoGenerated(bool value);
 
    /// \brief
    /// Returns a Boolean value that indicates if this is an autogenerated property.
    /// 
    /// \return
    /// Returns a Boolean value.
    /// 
    FDO_API bool GetIsAutoGenerated();

    /// \brief
    /// Returns the value constraint of this data property.
    /// 
    /// \return
    /// Returns the FdoPropertyValueConstraint or NULL if not set.
    /// 
    FDO_API FdoPropertyValueConstraint* GetValueConstraint();

    /// \brief
    /// Sets the value constraint of this data property.
    /// 
    /// \param value 
    /// Set the value constraint of this data property.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetValueConstraint( FdoPropertyValueConstraint* value );

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this property from the given property.
    virtual void Set( FdoPropertyDefinition* pProperty, FdoSchemaMergeContext* pContext );

    /// Initialize this property from its XML attributes
    virtual void InitFromXml(FdoString* propertyTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);
    
    /// read the geometric types from XML sub-elements.
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
    FdoDataType m_dataType;
    bool        m_readOnly;
    FdoInt32    m_length;
    FdoInt32    m_precision;
    FdoInt32    m_scale;
    bool        m_nullable;
    wchar_t*    m_defaultValue;
    bool        m_autogenerated;
	FdoPropertyValueConstraint *m_propertyValueConstraint;

protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _RejectChanges();
    virtual void    _AcceptChanges();
    FdoDataType m_dataTypeCHANGED;
    bool        m_readOnlyCHANGED;
    FdoInt32    m_lengthCHANGED;
    FdoInt32    m_precisionCHANGED;
    FdoInt32    m_scaleCHANGED;
    bool        m_nullableCHANGED;
    wchar_t*    m_defaultValueCHANGED;
    bool        m_autogeneratedCHANGED;
	FdoPropertyValueConstraint *m_propertyValueConstraintCHANGED;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoDataPropertyP is a FdoPtr on FdoDataPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoDataPropertyDefinition> FdoDataPropertyP;

#endif



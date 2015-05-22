/*
 * 
* Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
* 
 */

#include "stdafx.h"

[!output PREFIX]SchemaCapabilities::[!output PREFIX]SchemaCapabilities()
{
}

[!output PREFIX]SchemaCapabilities::~[!output PREFIX]SchemaCapabilities()
{
}

void [!output PREFIX]SchemaCapabilities::Dispose()
{
    delete this;
}

/// <summary>Returns an array of the FdoClassType objects the feature provider supports.</summary>
/// <param name="length">Output the number of class types.</param> 
/// <returns>Returns the list of class types.</returns> 
FdoClassType* [!output PREFIX]SchemaCapabilities::GetClassTypes(FdoInt32& length)
{
    static FdoClassType classes[] =
    {
        FdoClassType_Class,
        FdoClassType_FeatureClass
    };

    length = sizeof (classes) / sizeof (FdoClassType);

    return (classes);
}

/// <summary>Returns an array of the FdoDataType objects the feature provider supports.</summary>
/// <param name="length">Output the number of data types.</param> 
/// <returns>Returns the list of data types</returns> 
FdoDataType* [!output PREFIX]SchemaCapabilities::GetDataTypes(FdoInt32& length)
{
#pragma message ("ToDo: schema capabilities data types")
    static FdoDataType types[] =
    {
        //FdoDataType_DateTime,
        //FdoDataType_Double,
        FdoDataType_Int16,
        //FdoDataType_Int32,
        //FdoDataType_Single,
        //FdoDataType_String,
        //FdoDataType_BLOB,
        //FdoDataType_Boolean,
        //FdoDataType_Decimal,
        //FdoDataType_Byte,
        //FdoDataType_Int64,
        //FdoDataType_CLOB,
    };

    length = sizeof (types) / sizeof (FdoDataType);

    return (types);
}


/// <summary>Determines if the feature provider supports inheritance.</summary>
/// <returns>Returns true if the feature provider supports inheritance</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsInheritance()
{
    return (false);
}


/// <summary>Determines if the provider supports multiple schemas. Returns false if the provider supports only a single schema.</summary>
/// <returns>Returns true if the provider supports multiple schemas.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsMultipleSchemas()
{
    return (true);
}


/// <summary>Determines if the provider supports object properties. Returns false if the provider supports only data and geometric properties.</summary>
/// <returns>Returns true if the provider supports object properties.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsObjectProperties()
{
    return (false);
}


/// <summary>Determines if the provider supports Schema Mapping Overrides 
/// (overrides to the default rules for mapping Feature Schemas to provider-specific
/// physical schemas)</summary>
/// <returns>Returns true if the provider supports Schema Overrides</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsSchemaOverrides()
{
    return false;
}


/// <summary>Determines if the provider supports association property.</summary>
/// <returns>Returns true if the provider support the association property.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsAssociationProperties(void)
{
    return false;
}

/// <summary>Determines if the provider supports the network model.</summary>
/// <returns>Returns true if the provider supports the network model.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsNetworkModel(void)
{
    return false;
}

/// <summary>Determines if the provider can auto-generate unique ID values for a class.</summary>
/// <returns>Returns true if the provider supports id autogeneration.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsAutoIdGeneration()
{
    return true;
}

/// <summary>Determines if the provider can auto-generate unique ID values that are unique for the entire datastore, rather than just for a particular class.</summary>
/// <returns>Returns true if the provider supports id autogeneration unique across an datastore.</returns> 
bool [!output PREFIX]SchemaCapabilities::SupportsDataStoreScopeUniqueIdGeneration()
{
    return false;
}

/// <summary>Returns an array of the FdoDataType objects the feature provider supports for auto-generation.</summary>
/// <param name="length">Output the number of data types.</param> 
/// <returns>Returns the list of data types</returns> 
FdoDataType* [!output PREFIX]SchemaCapabilities::GetSupportedAutoGeneratedTypes(FdoInt32& length)
{
    static FdoDataType autogen_types[] =
    {
        FdoDataType_Int32,
    };

    length = sizeof (autogen_types) / sizeof (FdoDataType);

    return (autogen_types);
}

bool [!output PREFIX]SchemaCapabilities::SupportsSchemaModification()
{
    return false;
}

/// <summary>Determines if the provider supports inclusive value range constraints.</summary>
/// <returns>Returns true if the provider supports inclusive value range constraints.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsInclusiveValueRangeConstraints()
{
    return false;
}

/// <summary>Determines if the provider supports exclusive value range constraints.</summary>
/// <returns>Returns true if the provider supports exclusive value range constraints.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsExclusiveValueRangeConstraints()
{
    return false;
}

/// <summary>Determines if the provider supports value constraints list.</summary>
/// <returns>Returns true if the provider supports value constraints list.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsValueConstraintsList()
{
    return false;
}

/// <summary>Determines if the provider supports nullable value constraint.</summary>
/// <returns>Returns true if the provider supports nullable value constraint.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsNullValueConstraints()
{
    return false;
}

/// <summary>Determines if the provider supports unique value constraint.</summary>
/// <returns>Returns true if the provider supports unique value constraint.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsUniqueValueConstraints()
{
    return false;
}

/// <summary>Determines if the provider supports composite unique value constraint.</summary>
/// <returns>Returns true if the provider supports composite unique value constraint.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsCompositeUniqueValueConstraints()
{
    return false;
}

/// <summary>Determines if the provider supports multiple identity properties per class.</summary>
/// <returns>Returns true if the provider supports multiple identity properties per class.</returns>
bool [!output PREFIX]SchemaCapabilities::SupportsCompositeId()
{
    return false;
}


FdoInt32 [!output PREFIX]SchemaCapabilities::GetNameSizeLimit (FdoSchemaElementNameType nameType)
{
#pragma message ("ToDo: name size limits")
    switch (nameType)
    {
        case FdoSchemaElementNameType_Datastore:   return -1;  // -1 means unlimited
        case FdoSchemaElementNameType_Schema:      return -1;  // -1 means unlimited
        case FdoSchemaElementNameType_Class:       return -1;  // -1 means unlimited
        case FdoSchemaElementNameType_Property:    return -1;  // -1 means unlimited
        case FdoSchemaElementNameType_Description: return -1;  // -1 means unlimited
    }
    return -1;
}

FdoString* [!output PREFIX]SchemaCapabilities::GetReservedCharactersForName()
{
#pragma message ("ToDo: reserved characters for names")
    return L".:";
}

FdoInt64 [!output PREFIX]SchemaCapabilities::GetMaximumDataValueLength (FdoDataType dataType)
{
#pragma message ("ToDo: maximum data value lenghts")
    switch (dataType)
    {
        case FdoDataType_String:   return (FdoInt64)-1;  // -1 means unlimited
        case FdoDataType_BLOB:     return (FdoInt64)-1;  // -1 means unlimited
        case FdoDataType_CLOB:     return (FdoInt64)-1;  // -1 means unlimited
        case FdoDataType_Decimal:  return (FdoInt64)(GetMaximumDecimalScale() + GetMaximumDecimalPrecision());
        case FdoDataType_Boolean:  return (FdoInt64)sizeof(FdoBoolean);
        case FdoDataType_Byte:     return (FdoInt64)sizeof(FdoByte);
        case FdoDataType_DateTime: return (FdoInt64)sizeof(FdoDateTime);
        case FdoDataType_Double:   return (FdoInt64)sizeof(FdoDouble);
        case FdoDataType_Int16:    return (FdoInt64)sizeof(FdoInt16);
        case FdoDataType_Int32:    return (FdoInt64)sizeof(FdoInt32);
        case FdoDataType_Int64:    return (FdoInt64)sizeof(FdoInt64);
        case FdoDataType_Single:   return (FdoInt64)sizeof(FdoFloat);
    }
    return (FdoInt64)-1;  // -1 means unlimited
}

FdoInt32 [!output PREFIX]SchemaCapabilities::GetMaximumDecimalPrecision()
{
#pragma message ("ToDo: maximum decimal precision")
    return -1;  // -1 means unlimited
}

FdoInt32 [!output PREFIX]SchemaCapabilities::GetMaximumDecimalScale()
{
#pragma message ("ToDo: maximum decimal scale")
    return -1;  // -1 means unlimited
}

FdoDataType* [!output PREFIX]SchemaCapabilities::GetSupportedIdentityPropertyTypes(FdoInt32& length)
{
#pragma message ("ToDo: supported identity property types")
    length = 1;
    FdoDataType supportedIdentityTypes[1];
    supportedIdentityTypes[0] = FdoDataType_Int32;
    return supportedIdentityTypes;
}

bool [!output PREFIX]SchemaCapabilities::SupportsDefaultValue()
{
#pragma message ("ToDo: supports default values")
    return false;
}

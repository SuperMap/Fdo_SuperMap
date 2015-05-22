
/** \file	 SuperMapSchemaCapabilities.cpp
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#include <SuperMap.h>

SuperMapSchemaCapabilities::SuperMapSchemaCapabilities()
{
}

SuperMapSchemaCapabilities::~SuperMapSchemaCapabilities()
{
}

void SuperMapSchemaCapabilities::Dispose()
{
    delete this;
}

/// <summary>Returns an array of the FdoClassType objects the feature provider supports.</summary>
/// <param name="length">Output the number of class types.</param> 
/// <returns>Returns the list of class types.</returns> 
FdoClassType* SuperMapSchemaCapabilities::GetClassTypes(FdoInt32& length)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetClassTypes()... \n"));
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
FdoDataType* SuperMapSchemaCapabilities::GetDataTypes(FdoInt32& length)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetDataTypes()... \n"));
    static FdoDataType types[] =
    {
		FdoDataType_Boolean,
		FdoDataType_Byte,
		FdoDataType_Int16,
		FdoDataType_Int32,
		FdoDataType_Single,
		FdoDataType_Double,
		FdoDataType_DateTime,
		FdoDataType_Decimal,
		FdoDataType_BLOB,
		FdoDataType_String
    };

    length = sizeof (types) / sizeof (FdoDataType);

    return (types);
}


/// <summary>Determines if the feature provider supports inheritance.</summary>
/// <returns>Returns true if the feature provider supports inheritance</returns> 
bool SuperMapSchemaCapabilities::SupportsInheritance()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsInheritance()... \n"));
    return (false);
}


/// <summary>Determines if the provider supports multiple schemas. Returns false if the provider supports only a single schema.</summary>
/// <returns>Returns true if the provider supports multiple schemas.</returns> 
bool SuperMapSchemaCapabilities::SupportsMultipleSchemas()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsMultipleSchemas()... \n"));
    return (true);
}


/// <summary>Determines if the provider supports object properties. Returns false if the provider supports only data and geometric properties.</summary>
/// <returns>Returns true if the provider supports object properties.</returns> 
bool SuperMapSchemaCapabilities::SupportsObjectProperties()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsObjectProperties()... \n"));
    return (false);
}


/// <summary>Determines if the provider supports Schema Mapping Overrides 
/// (overrides to the default rules for mapping Feature Schemas to provider-specific
/// physical schemas)</summary>
/// <returns>Returns true if the provider supports Schema Overrides</returns> 
bool SuperMapSchemaCapabilities::SupportsSchemaOverrides()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsSchemaOverrides()... \n"));
    return false;  // APPLYSHEMA NOT IN R1, SO OVERRIDES NOT IN R1
}


/// <summary>Determines if the provider supports association property.</summary>
/// <returns>Returns true if the provider support the association property.</returns> 
bool SuperMapSchemaCapabilities::SupportsAssociationProperties(void)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsAssociationProperties()... \n"));
    return false;
}

/// <summary>Determines if the provider supports the network model.</summary>
/// <returns>Returns true if the provider supports the network model.</returns> 
bool SuperMapSchemaCapabilities::SupportsNetworkModel(void)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsNetworkModel()... \n"));
    return false;
}

/// <summary>Determines if the provider can auto-generate unique ID values for a class.</summary>
/// <returns>Returns true if the provider supports id autogeneration.</returns> 
bool SuperMapSchemaCapabilities::SupportsAutoIdGeneration()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsAutoIdGeneration()... \n"));
    return true;
}

/// <summary>Determines if the provider can auto-generate unique ID values that are unique for the entire datastore, rather than just for a particular class.</summary>
/// <returns>Returns true if the provider supports id autogeneration unique across an datastore.</returns> 
bool SuperMapSchemaCapabilities::SupportsDataStoreScopeUniqueIdGeneration()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsDataStoreScopeUniqueIdGeneration()... \n"));
    return false;
}

/// <summary>Returns an array of the FdoDataType objects the feature provider supports for auto-generation.</summary>
/// <param name="length">Output the number of data types.</param> 
/// <returns>Returns the list of data types</returns> 
FdoDataType* SuperMapSchemaCapabilities::GetSupportedAutoGeneratedTypes(FdoInt32& length)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetSupportedAutoGeneratedTypes()... \n"));
    static FdoDataType autogen_types[] =
    {
		//TODO::可能还要再加几个类型
        FdoDataType_Int32,
    };

    length = sizeof (autogen_types) / sizeof (FdoDataType);

    return (autogen_types);
}

bool SuperMapSchemaCapabilities::SupportsSchemaModification()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsSchemaModification()... \n"));
    //return false;
	return true;  // by zhouxu 2008-9-2
}

/// <summary>Determines if the provider supports inclusive value range constraints.</summary>
/// <returns>Returns true if the provider supports inclusive value range constraints.</returns> 
bool SuperMapSchemaCapabilities::SupportsInclusiveValueRangeConstraints()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsInclusiveValueRangeConstraints()... \n"));
    return false;
}

/// <summary>Determines if the provider supports exclusive value range constraints.</summary>
/// <returns>Returns true if the provider supports exclusive value range constraints.</returns>
bool SuperMapSchemaCapabilities::SupportsExclusiveValueRangeConstraints()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsExclusiveValueRangeConstraints()... \n"));
    return false;
}
/// <summary>Determines if the provider supports value constraints list.</summary>
/// <returns>Returns true if the provider supports value constraints list.</returns>
bool SuperMapSchemaCapabilities::SupportsValueConstraintsList()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsValueConstraintsList()... \n"));
    return false;
}

/// <summary>Determines if the provider supports nullable value constraint.</summary>
/// <returns>Returns true if the provider supports nullable value constraint.</returns>
bool SuperMapSchemaCapabilities::SupportsNullValueConstraints()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsNullValueConstraints()... \n"));
    return true;
}

/// <summary>Determines if the provider supports unique value constraint.</summary>
/// <returns>Returns true if the provider supports unique value constraint.</returns>
bool SuperMapSchemaCapabilities::SupportsUniqueValueConstraints()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsUniqueValueConstraints()... \n"));
    return true;
}

/// <summary>Determines if the provider supports composite unique value constraint.</summary>
/// <returns>Returns true if the provider supports composite unique value constraint.</returns>
bool SuperMapSchemaCapabilities::SupportsCompositeUniqueValueConstraints()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsCompositeUniqueValueConstraints()... \n"));
    return true;
}

/// <summary>Determines if the provider supports multiple identity properties per class.</summary>
/// <returns>Returns true if the provider supports multiple identity properties per class.</returns>
bool SuperMapSchemaCapabilities::SupportsCompositeId()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsCompositeId()... \n"));
    return false;
}

FdoInt32 SuperMapSchemaCapabilities::GetNameSizeLimit (FdoSchemaElementNameType nameType)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetNameSizeLimit()... \n"));
    switch (nameType)
    {
		//TODO::再做进一步测试工作，判断SIZE是否够用
        case FdoSchemaElementNameType_Datastore:   return 123;  // sql server's limit, which is higher than oracle's limit of 30
        case FdoSchemaElementNameType_Schema:      return 10;
        case FdoSchemaElementNameType_Class:       return 10;
        case FdoSchemaElementNameType_Property:    return 10;
        case FdoSchemaElementNameType_Description: return 0;
    }
    return -1;
}

FdoString* SuperMapSchemaCapabilities::GetReservedCharactersForName()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetReservedCharactersForName()... \n"));
    return L".:";
}

FdoInt64 SuperMapSchemaCapabilities::GetMaximumDataValueLength (FdoDataType dataType)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetMaximumDataValueLength()... \n"));
    switch (dataType)
    {
        case FdoDataType_String:   return (FdoInt64)4294967296LL; // SuperMap's limit itself
        case FdoDataType_BLOB:     return (FdoInt64)4294967296LL; // Oracle's limit, which is higher than SQL Server's limit
        case FdoDataType_CLOB:     return (FdoInt64)4294967296LL; // Oracle's limit, which is higher than SQL Server's limit
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
    return (FdoInt64)-1;
}

FdoInt32 SuperMapSchemaCapabilities::GetMaximumDecimalPrecision()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetMaximumDecimalPrecision()... \n"));
    return 38; // oracle's limit, since it's higher than sql server's limit
}

FdoInt32 SuperMapSchemaCapabilities::GetMaximumDecimalScale()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetMaximumDecimalScale()... \n"));
    return 127; // oracle's limit, since it's higher than sql server's limit
}

FdoDataType* SuperMapSchemaCapabilities::GetSupportedIdentityPropertyTypes(FdoInt32& length)
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::GetSupportedIdentityPropertyTypes()... \n"));
    /*static FdoDataType types[] =
    {
        FdoDataType_DateTime,
        FdoDataType_Double,
        FdoDataType_Int16,
        FdoDataType_Int32,
        FdoDataType_Single,
        FdoDataType_String,
        FdoDataType_BLOB
    };

    length = sizeof (types) / sizeof (FdoDataType);

    return types;*/

	//TODO::再做一下测试
	// modified by zhouxu 2007-12-6
	// 标识属性字段只支持FdoDataType_Int32
	length = 1;
	static FdoDataType supportedIdentityTypes[1];
	supportedIdentityTypes[0] = FdoDataType_Int32;
	return supportedIdentityTypes;
}

bool SuperMapSchemaCapabilities::SupportsDefaultValue()
{
	TRACE(_T("调用 SuperMapSchemaCapabilities::SupportsDefaultValue()... \n"));
    return false;  // this could be true if we supported ApplySchema
}

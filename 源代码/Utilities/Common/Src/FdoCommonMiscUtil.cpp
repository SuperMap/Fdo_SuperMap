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
#include "FdoCommonMiscUtil.h"
#include "FdoCommonSchemaUtil.h"
#include "FdoCommonOSUtil.h"
#include "FdoCommonStringUtil.h"


FdoString* FdoCommonMiscUtil::FdoDataTypeToString (FdoDataType logicalPropertyType)
{
    wchar_t* logicalTypeString;

    switch (logicalPropertyType)
    {
        case FdoDataType_Boolean:
            logicalTypeString = L"FdoDataType_Boolean";
            break;
        case FdoDataType_Byte:
            logicalTypeString = L"FdoDataType_Byte";
            break;
        case FdoDataType_DateTime:
            logicalTypeString = L"FdoDataType_DateTime";
            break;
        case FdoDataType_Decimal:
            logicalTypeString = L"FdoDataType_Decimal";
            break;
        case FdoDataType_Double:
            logicalTypeString = L"FdoDataType_Double";
            break;
        case FdoDataType_Int16:
            logicalTypeString = L"FdoDataType_Int16";
            break;
        case FdoDataType_Int32:
            logicalTypeString = L"FdoDataType_Int32";
            break;
        case FdoDataType_Int64:
            logicalTypeString = L"FdoDataType_Int64";
            break;
        case FdoDataType_Single:
            logicalTypeString = L"FdoDataType_Single";
            break;
        case FdoDataType_String:
            logicalTypeString = L"FdoDataType_String";
            break;
        case FdoDataType_BLOB:
            logicalTypeString = L"FdoDataType_BLOB";
            break;
        case FdoDataType_CLOB:
            logicalTypeString = L"FdoDataType_CLOB";
            break;
        default:
            logicalTypeString = L"Unknown FdoDataType";
            break;
    }

    return (logicalTypeString);
}



FdoString* FdoCommonMiscUtil::FdoPropertyTypeToString (FdoPropertyType logicalPropertyType)
{
    wchar_t* logicalTypeString;

    switch (logicalPropertyType)
    {
        case FdoPropertyType_DataProperty:
            logicalTypeString = L"FdoPropertyType_DataProperty";
            break;
        case FdoPropertyType_ObjectProperty:
            logicalTypeString = L"FdoPropertyType_ObjectProperty";
            break;
        case FdoPropertyType_GeometricProperty:
            logicalTypeString = L"FdoPropertyType_GeometricProperty";
            break;
        case FdoPropertyType_AssociationProperty:
            logicalTypeString = L"FdoPropertyType_AssociationProperty";
            break;
        case FdoPropertyType_RasterProperty:
            logicalTypeString = L"FdoPropertyType_RasterProperty";
            break;
        default:
            logicalTypeString = L"Unknown FdoPropertyType";
            break;
    }

    return (logicalTypeString);
}



FdoString* FdoCommonMiscUtil::FdoClassTypeToString (FdoClassType logicalClassType)
{
    wchar_t* logicalTypeString;

    switch (logicalClassType)
    {
        case FdoClassType_Class:
            logicalTypeString = L"FdoClassType_Class";
            break;
        case FdoClassType_FeatureClass:
            logicalTypeString = L"FdoClassType_FeatureClass";
            break;
        case FdoClassType_NetworkClass:
            logicalTypeString = L"FdoClassType_NetworkClass";
            break;
        case FdoClassType_NetworkLayerClass:
            logicalTypeString = L"FdoClassType_NetworkLayerClass";
            break;
        case FdoClassType_NetworkNodeClass:
            logicalTypeString = L"FdoClassType_NetworkNodeClass";
            break;
        case FdoClassType_NetworkLinkClass:
            logicalTypeString = L"FdoClassType_NetworkLinkClass";
            break;
        default:
            logicalTypeString = L"Unknown FdoClassType";
            break;
    }

    return (logicalTypeString);
};

FdoStringP FdoCommonMiscUtil::FdoCommandTypeToString (FdoInt32 command)
{
    FdoStringP ret;

    switch (command)
    {
        case FdoCommandType_Select:
            ret = L"FdoCommandType_Select";
            break;
        case FdoCommandType_Insert:
            ret = L"FdoCommandType_Insert";
            break;
        case FdoCommandType_Delete:
            ret = L"FdoCommandType_Delete";
            break;
        case FdoCommandType_Update:
            ret = L"FdoCommandType_Update";
            break;
        case FdoCommandType_DescribeSchema:
            ret = L"FdoCommandType_DescribeSchema";
            break;
        case FdoCommandType_DescribeSchemaMapping:
            ret = L"FdoCommandType_DescribeSchemaMapping";
            break;
        case FdoCommandType_ApplySchema:
            ret = L"FdoCommandType_ApplySchema";
            break;
        case FdoCommandType_DestroySchema:
            ret = L"FdoCommandType_DestroySchema";
            break;
        case FdoCommandType_ActivateSpatialContext:
            ret = L"FdoCommandType_ActivateSpatialContext";
            break;
        case FdoCommandType_CreateSpatialContext:
            ret = L"FdoCommandType_CreateSpatialContext";
            break;
        case FdoCommandType_DestroySpatialContext:
            ret = L"FdoCommandType_DestroySpatialContext";
            break;
        case FdoCommandType_GetSpatialContexts:
            ret = L"FdoCommandType_GetSpatialContexts";
            break;
        case FdoCommandType_CreateMeasureUnit:
            ret = L"FdoCommandType_CreateMeasureUnit";
            break;
        case FdoCommandType_DestroyMeasureUnit:
            ret = L"FdoCommandType_DestroyMeasureUnit";
            break;
        case FdoCommandType_GetMeasureUnits:
            ret = L"FdoCommandType_GetMeasureUnits";
            break;
        case FdoCommandType_SQLCommand:
            ret = L"FdoCommandType_SQLCommand";
            break;
        case FdoCommandType_AcquireLock:
            ret = L"FdoCommandType_AcquireLock";
            break;
        case FdoCommandType_GetLockInfo:
            ret = L"FdoCommandType_GetLockInfo";
            break;
        case FdoCommandType_GetLockedObjects:
            ret = L"FdoCommandType_GetLockedObjects";
            break;
        case FdoCommandType_GetLockOwners:
            ret = L"FdoCommandType_GetLockOwners";
            break;
        case FdoCommandType_ReleaseLock:
            ret = L"FdoCommandType_ReleaseLock";
            break;
        case FdoCommandType_ActivateLongTransaction:
            ret = L"FdoCommandType_ActivateLongTransaction";
            break;
        case FdoCommandType_DeactivateLongTransaction:
            ret = L"FdoCommandType_DeactivateLongTransaction";
            break;
        case FdoCommandType_CommitLongTransaction:
            ret = L"FdoCommandType_CommitLongTransaction";
            break;
        case FdoCommandType_CreateLongTransaction:
            ret = L"FdoCommandType_CreateLongTransaction";
            break;
        case FdoCommandType_GetLongTransactions:
            ret = L"FdoCommandType_GetLongTransactions";
            break;
        case FdoCommandType_FreezeLongTransaction:
            ret = L"FdoCommandType_FreezeLongTransaction";
            break;
        case FdoCommandType_RollbackLongTransaction:
            ret = L"FdoCommandType_RollbackLongTransaction";
            break;
        case FdoCommandType_ActivateLongTransactionCheckpoint:
            ret = L"FdoCommandType_ActivateLongTransactionCheckpoint";
            break;
        case FdoCommandType_CreateLongTransactionCheckpoint:
            ret = L"FdoCommandType_CreateLongTransactionCheckpoint";
            break;
        case FdoCommandType_GetLongTransactionCheckpoints:
            ret = L"FdoCommandType_GetLongTransactionCheckpoints";
            break;
        case FdoCommandType_RollbackLongTransactionCheckpoint:
            ret = L"FdoCommandType_RollbackLongTransactionCheckpoint";
            break;
        case FdoCommandType_ChangeLongTransactionPrivileges:
            ret = L"FdoCommandType_ChangeLongTransactionPrivileges";
            break;
        case FdoCommandType_GetLongTransactionPrivileges:
            ret = L"FdoCommandType_GetLongTransactionPrivileges";
            break;
        case FdoCommandType_ChangeLongTransactionSet:
            ret = L"FdoCommandType_ChangeLongTransactionSet";
            break;
        case FdoCommandType_GetLongTransactionsInSet:
            ret = L"FdoCommandType_GetLongTransactionsInSet";
            break;
        case FdoCommandType_NetworkShortestPath:
            ret = L"FdoCommandType_NetworkShortestPath";
            break;
        case FdoCommandType_NetworkAllPaths:
            ret = L"FdoCommandType_NetworkAllPaths";
            break;
        case FdoCommandType_NetworkReachableNodes:
            ret = L"FdoCommandType_NetworkReachableNodes";
            break;
        case FdoCommandType_NetworkReachingNodes:
            ret = L"FdoCommandType_NetworkReachingNodes";
            break;
        case FdoCommandType_NetworkNearestNeighbors:
            ret = L"FdoCommandType_NetworkNearestNeighbors";
            break;
        case FdoCommandType_NetworkWithinCost:
            ret = L"FdoCommandType_NetworkWithinCost";
            break;
        case FdoCommandType_NetworkTSP:
            ret = L"FdoCommandType_NetworkTSP";
            break;
        case FdoCommandType_ActivateTopologyArea:
            ret = L"FdoCommandType_ActivateTopologyArea";
            break;
        case FdoCommandType_DeactivateTopologyArea:
            ret = L"FdoCommandType_DeactivateTopologyArea";
            break;
        case FdoCommandType_ActivateTopologyInCommandResult:
            ret = L"FdoCommandType_ActivateTopologyInCommandResult";
            break;
        case FdoCommandType_DeactivateTopologyInCommandResults:
            ret = L"FdoCommandType_DeactivateTopologyInCommandResults";
            break;
        case FdoCommandType_SelectAggregates:
            ret = L"FdoCommandType_SelectAggregates";
            break;
        case FdoCommandType_CreateDataStore:
            ret = L"FdoCommandType_CreateDataStore";
            break;
        case FdoCommandType_DestroyDataStore:
            ret = L"FdoCommandType_DestroyDataStore";
            break;
        case FdoCommandType_ListDataStores:
            ret = L"FdoCommandType_ListDataStores";
            break;
        default:
            {
                wchar_t buffer[9];

                FdoCommonOSUtil::swprintf (buffer, ELEMENTS(buffer), L"#%d", command);
                ret = buffer;
            }
            break;
    }

    return (ret);
}

FdoStringP FdoCommonMiscUtil::FdoSpatialOperationsToString (FdoSpatialOperations op)
{
    FdoStringP ret;

    switch (op)
    {
        case FdoSpatialOperations_Contains:
            ret = L"FdoSpatialOperations_Contains";
            break;
        case FdoSpatialOperations_Crosses:
            ret = L"FdoSpatialOperations_Crosses";
            break;
        case FdoSpatialOperations_Disjoint:
            ret = L"FdoSpatialOperations_Disjoint";
            break;
        case FdoSpatialOperations_Equals:
            ret = L"FdoSpatialOperations_Equals";
            break;
        case FdoSpatialOperations_Intersects:
            ret = L"FdoSpatialOperations_Intersects";
            break;
        case FdoSpatialOperations_Overlaps:
            ret = L"FdoSpatialOperations_Overlaps";
            break;
        case FdoSpatialOperations_Touches:
            ret = L"FdoSpatialOperations_Touches";
            break;
        case FdoSpatialOperations_Within:
            ret = L"FdoSpatialOperations_Within";
            break;
        case FdoSpatialOperations_CoveredBy:
            ret = L"FdoSpatialOperations_CoveredBy";
            break;
        case FdoSpatialOperations_Inside:
            ret = L"FdoSpatialOperations_Inside";
            break;
        case FdoSpatialOperations_EnvelopeIntersects:
            ret = L"FdoSpatialOperations_EnvelopeIntersects";
            break;
        default:
            {
                wchar_t buffer[9];
                FdoCommonOSUtil::swprintf (buffer, ELEMENTS(buffer), L"#%d", op);
                ret = buffer;
            }
            break;
    }
    return (ret);
}


FdoStringP FdoCommonMiscUtil::FdoGeometryTypeToString (FdoGeometryType geomType)
{
    FdoStringP ret;

    switch (geomType)
    {
        case FdoGeometryType_None:
            ret = L"FdoGeometryType_None";
        break;

        case FdoGeometryType_Point:
            ret = L"FdoGeometryType_Point";
        break;

        case FdoGeometryType_LineString:
            ret = L"FdoGeometryType_LineString";
        break;

        case FdoGeometryType_Polygon:
            ret = L"FdoGeometryType_Polygon";
        break;

        case FdoGeometryType_MultiPoint:
            ret = L"FdoGeometryType_MultiPoint";
        break;

        case FdoGeometryType_MultiLineString:
            ret = L"FdoGeometryType_MultiLineString";
        break;

        case FdoGeometryType_MultiPolygon:
            ret = L"FdoGeometryType_MultiPolygon";
        break;

        case FdoGeometryType_MultiGeometry:
            ret = L"FdoGeometryType_MultiGeometry";
        break;

        case FdoGeometryType_CurveString:
            ret = L"FdoGeometryType_CurveString";
        break;

        case FdoGeometryType_CurvePolygon:
            ret = L"FdoGeometryType_CurvePolygon";
        break;

        case FdoGeometryType_MultiCurveString:
            ret = L"FdoGeometryType_MultiCurveString";
        break;
    
        case FdoGeometryType_MultiCurvePolygon:
            ret = L"FdoGeometryType_MultiCurvePolygon";
        break;

        default:
        {
            wchar_t buffer[9];
            FdoCommonOSUtil::swprintf (buffer, ELEMENTS(buffer), L"#%d", geomType);
            ret = buffer;
        }
        break;
    }

    return ret;
}


// Returns: -1 if d1 < d2,  0 if d1==d2,  1 of d1>d2.
//    Note that if d1 and d2 are different date/time types, they are sorted as follows: datetime < date < time.
int FdoCommonMiscUtil::CompareDateTimes(FdoDateTime d1, FdoDateTime d2)
{
    if (d1.IsDateTime() && d2.IsDate())
        return -1;
    else if (d1.IsDateTime() && d2.IsTime())
        return -1;
    else if (d1.IsDate() && d2.IsTime())
        return -1;
    else if (d1.IsDate() && d2.IsDateTime())
        return 1;
    else if (d1.IsTime() && d2.IsDate())
        return 1;
    else if (d1.IsTime() && d2.IsDateTime())
        return 1;
    else  // both FdoDateTime are the same date/time type
    {
        // Compare date component (if any):
        if (d1.IsDateTime() || d1.IsDate())
        {
            if (d1.year != d2.year)
                return (d1.year < d2.year) ? -1 : 1;
            else if (d1.month != d2.month)
                return  (d1.month < d2.month)  ? -1 : 1;
            else if (d1.day != d2.day)
                return (d1.day < d2.day)  ? -1 : 1;
        }

        // Compare time component (if any):
        if (d1.IsDateTime() || d1.IsTime())
        {
            if (d1.hour != d2.hour)
                return (d1.hour < d2.hour)  ? -1 : 1;
            else if (d1.minute != d2.minute)
                return (d1.minute < d2.minute)  ? -1 : 1;
            else if (d1.seconds != d2.seconds)
                return (d1.seconds < d2.seconds)  ? -1 : 1;
        }
    }

    return 0;  // d1==d2 if we get here
}


int FdoCommonMiscUtil::CompareDataValues(FdoDataValue *d1, FdoDataValue *d2)
{
    if ((d1 == NULL) || (d2 == NULL))
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_60_NULL_POINTER)));

	if (IsLessThan(d1, d2))
        return -1;
    else if (IsEqualTo(d1,d2))
        return 0;
    else
        return 1;
}


FdoPropertyValue* FdoCommonMiscUtil::GetPropertyValue(FdoString *propName, FdoPropertyType propType, FdoDataType dataType, FdoIReader* reader)
{
    VALIDATE_ARGUMENT(propName);
    VALIDATE_ARGUMENT(reader);

    FdoPtr<FdoPropertyValue> propValue = FdoPropertyValue::Create(propName, NULL);
    FdoPtr<FdoValueExpression> valueExpr;
    // valueExpr is initialized to NULL implicitly by FdoPtr<>, so if reader->IsNull() is true, propValue's value will be set to NULL.

    if (!reader->IsNull(propName))
    {
        if (FdoPropertyType_DataProperty == propType)
        {
            switch (dataType)
            {
            case FdoDataType_Boolean :
                if (reader->IsNull(propName))
                    valueExpr = FdoBooleanValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoBooleanValue::Create(reader->GetBoolean(propName));
            break;

            case FdoDataType_Byte :
                if (reader->IsNull(propName))
                    valueExpr = FdoByteValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoByteValue::Create(reader->GetByte(propName));
            break;

            case FdoDataType_DateTime :
                if (reader->IsNull(propName))
                    valueExpr = FdoDateTimeValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoDateTimeValue::Create(reader->GetDateTime(propName));
            break;

            case FdoDataType_Decimal :
                if (reader->IsNull(propName))
                    valueExpr = FdoDecimalValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoDecimalValue::Create(reader->GetDouble(propName));
            break;

            case FdoDataType_Single :
                if (reader->IsNull(propName))
                    valueExpr = FdoSingleValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoSingleValue::Create(reader->GetSingle(propName));
            break;

            case FdoDataType_Double :
                if (reader->IsNull(propName))
                    valueExpr = FdoDoubleValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoDoubleValue::Create(reader->GetDouble(propName));
            break;

            case FdoDataType_Int16 : 
                if (reader->IsNull(propName))
                    valueExpr = FdoInt16Value::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoInt16Value::Create(reader->GetInt16(propName));
            break;

            case FdoDataType_Int32 : 
                if (reader->IsNull(propName))
                    valueExpr = FdoInt32Value::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoInt32Value::Create(reader->GetInt32(propName));
            break;

            case FdoDataType_Int64 : 
                if (reader->IsNull(propName))
                    valueExpr = FdoInt64Value::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoInt64Value::Create(reader->GetInt64(propName));
            break;

            case FdoDataType_String : 
                if (reader->IsNull(propName))
                    valueExpr = FdoStringValue::Create();  // defaults to IsNull()==true
                else
                    valueExpr = FdoStringValue::Create(reader->GetString(propName));
            break;

            default: 
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED),
                    FdoCommonMiscUtil::FdoDataTypeToString(dataType)));
            }
        }
        else if (FdoPropertyType_GeometricProperty == propType)
        {
                if (reader->IsNull(propName))
                    valueExpr = FdoGeometryValue::Create();  // defaults to IsNull()==true
                else
                {
                    FdoPtr<FdoByteArray> byteArray = reader->GetGeometry(propName);
                    valueExpr = FdoGeometryValue::Create(byteArray);
                }
        }
        else
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_70_PROPERTY_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoPropertyTypeToString(propType)));
    }

    propValue->SetValue(valueExpr);

    return FDO_SAFE_ADDREF(propValue.p);
}



/// <summary> Returns the requested item in the given property value collection, or NULL if not found.</summary>
FdoPropertyValue* FdoCommonMiscUtil::GetItemNoThrow(FdoPropertyValueCollection *coll, FdoString* name)
{
    FdoPtr<FdoPropertyValue> propValue;
    bool bFound=false;
    for (FdoInt32 i=0; (i<coll->GetCount()) && !bFound; i++)
    {
        propValue = coll->GetItem(i);
        FdoPtr<FdoIdentifier> propertyId = propValue->GetName();
        bFound = (0==wcscmp(propertyId->GetName(), name));
    }

    if (bFound)
        return FDO_SAFE_ADDREF(propValue.p);
    else
        return NULL;
}



/// <summary> Handles read-only properties and default values in the given PropertyValue collection.</summary>
void FdoCommonMiscUtil::HandleReadOnlyAndDefaultValues(FdoClassDefinition *classDef, FdoPropertyValueCollection *propValues, bool bMakeNullsExplicit)
{
    FdoPtr<FdoPropertyDefinitionCollection> propertyDefs = classDef->GetProperties();

    for (FdoInt32 i=0; i<propertyDefs->GetCount(); i++)
    {
        FdoPtr<FdoPropertyDefinition> propertyDef = propertyDefs->GetItem(i);
        bool bIsSet = false;
        bool bHasDefaultValue = false;
        bool bIsIdentityProperty = false;
        bool bIsReadOnly = false;

        // Get the corresponding property value, if any:
        FdoPtr<FdoPropertyValue> propValue;
        propValue = GetItemNoThrow(propValues, propertyDef->GetName());
        bIsSet = (propValue!=NULL) && FdoPtr<FdoValueExpression>(propValue->GetValue())!=NULL;

        // Determine whether this property is read only:
        if (propertyDef->GetPropertyType() == FdoPropertyType_DataProperty)
        {
            FdoDataPropertyDefinition* dataPropertyDef = static_cast<FdoDataPropertyDefinition*>(propertyDef.p);
            bIsReadOnly = dataPropertyDef->GetReadOnly();
        }

        // Handle this property:
        if (propertyDef->GetPropertyType() == FdoPropertyType_DataProperty)
        {
            FdoDataPropertyDefinition* dataPropertyDef = static_cast<FdoDataPropertyDefinition*>(propertyDef.p);
            bIsIdentityProperty = FdoCommonSchemaUtil::IsIdentityProperty(classDef, dataPropertyDef->GetName());

            FdoString *defaultValue = dataPropertyDef->GetDefaultValue();
            bHasDefaultValue = (defaultValue != NULL) && (wcslen(defaultValue) > 0);


            if (bIsReadOnly)
            {
                if (bIsSet)
                    throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_97_CANNOT_SET_READONLY_PROPERTY, "Property '%1$ls' cannot be set because it is read-only.", propertyDef->GetName()));
                if (!bHasDefaultValue && !bIsIdentityProperty)
                    throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_98_MISSING_DEFAULT_VALUE, "Read-only property '%1$ls' requires a default value.", propertyDef->GetName()));
                if (bHasDefaultValue && bIsIdentityProperty)
                    throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_99_CANNOT_DEFAULT_READONLY_PROPERTY, "Read-only identity property '%1$ls' cannot have a default value.", propertyDef->GetName()));
            }

            if (!bIsSet && bHasDefaultValue)
            {
                if (propValue != NULL)
                    propValue->SetValue(defaultValue);
                else
                {
                    propValue = FdoPropertyValue::Create();
                    propValue->SetName(dataPropertyDef->GetName());
                    propValue->SetValue(defaultValue);
                    propValues->Add(propValue);
                }
            }
        }

        // Convert implicit NULLs into explicit NULLs if requested:
        if (bMakeNullsExplicit && !bIsReadOnly && !bIsSet && (propValue==NULL))
        {
            propValue = FdoPropertyValue::Create();
            propValue->SetName(propertyDef->GetName());
            propValue->SetValue((FdoValueExpression*)NULL);
            propValues->Add(propValue);
        }
    }

    // Validate that all given property values have valid property names:
    for (FdoInt32 i=0; i<propValues->GetCount(); i++)
    {
        FdoPtr<FdoPropertyValue> propVal = propValues->GetItem(i);
        FdoPtr<FdoIdentifier> propValId = propVal->GetName();
        // NOTE: we can skip checking the base properties since this provider currently doesn't support inheritance
        FdoPtr<FdoPropertyDefinition> propertyDef = propertyDefs->FindItem(propValId->GetName());
        if (propertyDef == NULL)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_74_PROPERTY_NAME_NOT_FOUND, "The property '%1$ls' was not found.", propValId->GetName()));
    }
}


void FdoCommonMiscUtil::ThrowPropertyConstraintException(FdoDataPropertyDefinition* dataProperty, FdoDataValue* dataValue)
{
    FdoPtr<FdoPropertyValueConstraint> valueConstraint = dataProperty->GetValueConstraint();
    switch (valueConstraint->GetConstraintType())
    {
        case FdoPropertyValueConstraintType_Range:
        {
            FdoPropertyValueConstraintRange* rangeConstraint = static_cast<FdoPropertyValueConstraintRange*>(valueConstraint.p);
            FdoPtr<FdoDataValue> minValue = rangeConstraint->GetMinValue();
            bool minNotNull = ( minValue && !(minValue->IsNull()) );
            FdoPtr<FdoDataValue> maxValue = rangeConstraint->GetMaxValue();
            bool maxNotNull = ( maxValue && !(maxValue->IsNull()) );
            FdoStringP rangeString = FdoStringP::Format(L"%ls %ls N %ls %ls",
                minNotNull ? minValue->ToString() : L"",
                minNotNull ? (rangeConstraint->GetMinInclusive() ? L"<=" : L"<") : L"",
                maxNotNull ? (rangeConstraint->GetMaxInclusive() ? L"<=" : L"<") : L"",
                maxNotNull ? maxValue->ToString() : L"" );
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_111_PROPERTY_RANGE_CONSTRAINT_VIOLATED), dataProperty->GetName(), (FdoString*)rangeString, dataValue->ToString()));
        }
        break;

        case FdoPropertyValueConstraintType_List:
        {
            FdoPropertyValueConstraintList* listConstraint = static_cast<FdoPropertyValueConstraintList*>(valueConstraint.p);
            FdoStringsP listStringCollection = FdoStringCollection::Create();
            FdoPtr<FdoDataValueCollection> listValues = listConstraint->GetConstraintList();
            for (int i=0; i<listValues->GetCount(); i++)
                listStringCollection->Add(FdoPtr<FdoDataValue>(listValues->GetItem(i))->ToString());
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_112_PROPERTY_LIST_CONSTRAINT_VIOLATED), dataProperty->GetName(), (FdoString*)listStringCollection->ToString(), dataValue->ToString()));
        }
        break;

        default:
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_113_PROPERTY_UNKNOWN_CONSTRAINT_VIOLATED), dataProperty->GetName(), dataValue->ToString()));
        break;
    }
}


bool FdoCommonMiscUtil::ContainsGeomType(FdoGeometryType* geomTypes, FdoInt32 geomTypeCount, FdoGeometryType geomType)
{
    bool bFound = false;
    for (int i=0; i<geomTypeCount && !bFound; i++)
        bFound = (geomTypes[i] == geomType);
    return bFound;
}


FdoFunctionDefinition* FdoCommonMiscUtil::CreateFunctionDefinition(
    FdoString* functionName, FdoString* functionDesc, bool isAggregate, int numSignatures, ...)
{
    va_list  varargs;
    va_start(varargs, numSignatures);

    FdoPtr<FdoSignatureDefinitionCollection> signatures = FdoSignatureDefinitionCollection::Create();

    for (int s=0; s<numSignatures; s++)
    {
        FdoPtr<FdoArgumentDefinitionCollection> args = FdoArgumentDefinitionCollection::Create();

        FdoPropertyType returnPropertyType = (FdoPropertyType)va_arg(varargs, int /*FdoPropertyType*/ );
        FdoDataType returnDataType = (FdoDataType)va_arg(varargs, int /*FdoDataType*/);
        int numInputArgs = va_arg(varargs, int);

        for (int i=0; i<numInputArgs; i++)
        {
	    FdoPropertyType argPropertyType = (FdoPropertyType)va_arg(varargs, int /*FdoPropertyType*/);
            FdoDataType argDataType = (FdoDataType)va_arg(varargs, int /*FdoDataType*/);
            FdoString *argName;
            FdoString *argDesc;

            if (argPropertyType == FdoPropertyType_GeometricProperty)
            {
                argName = L"geomValue";
                argDesc = FdoException::NLSGetMessage(FUNCTION_GEOM_ARG, "Argument that represents a geometry");
            }
            else if (argPropertyType == FdoPropertyType_AssociationProperty)
            {
                argName = L"associationValue";
                argDesc = FdoException::NLSGetMessage(FUNCTION_ASSOCIATION_ARG, "Argument that represents an association");
            }
            else if (argPropertyType == FdoPropertyType_ObjectProperty)
            {
                argName = L"objectValue";
                argDesc = FdoException::NLSGetMessage(FUNCTION_OBJECT_ARG, "Argument that represents an object");
            }
            else if (argPropertyType == FdoPropertyType_RasterProperty)
            {
                argName = L"rasterValue";
                argDesc = FdoException::NLSGetMessage(FUNCTION_RASTER_ARG, "Argument that represents a raster");
            }
            else if (argPropertyType == FdoPropertyType_DataProperty)
            {
                switch (argDataType)
                {
                case FdoDataType_Boolean:
                    argName = L"boolValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_BOOL_ARG, "Argument that represents a boolean");
                break;

                case FdoDataType_Byte:
                    argName = L"byteValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_BYTE_ARG, "Argument that represents a byte");
                break;

                case FdoDataType_DateTime:
                    argName = L"datetimeValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_DT_ARG, "Argument that represents a date/time");
                break;

                case FdoDataType_Decimal:
                    argName = L"decimalValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_DEC_ARG, "Argument that represents a decimal value");
                break;

                case FdoDataType_Double:
                    argName = L"doubleValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_DBL_ARG, "Argument that represents a double");
                break;

                case FdoDataType_Int16:
                    argName = L"int16Value";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_INT16_ARG, "Argument that represents a 16-bit integer");
                break;

                case FdoDataType_Int32:
                    argName = L"int32Value";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_INT32_ARG, "Argument that represents a 32-bit integer");
                break;

                case FdoDataType_Int64:
                    argName = L"int64Value";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_INT64_ARG, "Argument that represents a 64-bit integer");
                break;

                case FdoDataType_Single:
                    argName = L"singleValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_SINGLE_ARG, "Argument that represents a single");
                break;

                case FdoDataType_String:
                    argName = L"stringValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_STR_ARG, "Argument that represents a string");
                break;

                case FdoDataType_BLOB:
                    argName = L"blobValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_BLOB_ARG, "Argument that represents a blob");
                break;

                case FdoDataType_CLOB:
                    argName = L"clobValue";
                    argDesc = FdoException::NLSGetMessage(FUNCTION_CLOB_ARG, "Argument that represents a clob");
                break;

                default:
                    throw FdoException::Create(FdoException::NLSGetMessage(FDO_130_DATA_TYPE_NOT_SUPPORTED_BY_OPERATION, "The data type '%1$ls' is not supported by this operation.", FdoCommonMiscUtil::FdoDataTypeToString(argDataType)));
                }
            }
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_129_PROPERTY_TYPE_NOT_SUPPORTED_BY_OPERATION, "The property type '%1$ls' is not supported by this operation.", FdoCommonMiscUtil::FdoPropertyTypeToString(argPropertyType)));

            FdoPtr<FdoArgumentDefinition> arg = FdoArgumentDefinition::Create(argName, argDesc, argPropertyType, argDataType);
            args->Add(arg);
        }

        FdoPtr<FdoSignatureDefinition> signatureDef = FdoSignatureDefinition::Create(returnPropertyType, returnDataType, args);
        signatures->Add(signatureDef);
    }

    va_end(varargs);

    return FdoFunctionDefinition::Create(functionName, functionDesc, isAggregate, signatures);
}


bool FdoCommonMiscUtil::IsEqualTo (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    bool ret;

    // Handle NULL values:
    if (argLeft->IsNull() && argRight->IsNull())  // 2 out of 2 are NULL
        ret = true;
    else if ((argLeft->IsNull() && !argRight->IsNull()) || (!argLeft->IsNull() && argRight->IsNull()))  // 1 out of 2 are NULL
        ret = false;
    else switch (argLeft->GetDataType ())  // 0 out of 2 are NULL
    {
        case FdoDataType_Boolean:
            if (FdoDataType_Boolean != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
                ret = ((FdoBooleanValue*)argLeft)->GetBoolean () == ((FdoBooleanValue*)argRight)->GetBoolean ();
            break;
        case FdoDataType_Byte:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoByteValue*)argLeft)->GetByte () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            if (FdoDataType_DateTime != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
            {
                FdoDateTime t1;
                FdoDateTime t2;

                t1 = ((FdoDateTimeValue*)argLeft)->GetDateTime ();
                t2 = ((FdoDateTimeValue*)argRight)->GetDateTime ();
                ret = ((t1.year == t2.year) &&
                       (t1.month == t2.month) &&
                       (t1.day == t2.day) &&
                       (t1.hour == t2.hour) &&
                       (t1.minute == t2.minute) &&
                       (t1.seconds == t2.seconds));
            }
            break;
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Double:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int16:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int32:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int64:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Single:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () == ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
            if (FdoDataType_String != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
                ret = 0 == wcscmp (((FdoStringValue*)argLeft)->GetString (), ((FdoStringValue*)argRight)->GetString ());
            break;
        case FdoDataType_BLOB:
            if (FdoDataType_BLOB != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
            {
                FdoByteArray* b1;
                FdoByteArray* b2;
                FdoInt32 count1;
                FdoInt32 count2;

                b1 = ((FdoBLOBValue*)argLeft)->GetData ();
                b2 = ((FdoBLOBValue*)argRight)->GetData ();
                count1 = b1->GetCount ();
                count2 = b2->GetCount ();
                ret = count1 == count2;
                for (int i = 0; ret && (i < count1); i++)
                    if ((*b1)[i] != (*b2)[i])
                        ret = false;
            }
            break;
        case FdoDataType_CLOB:
            if (FdoDataType_CLOB != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
            {
                FdoByteArray* b1;
                FdoByteArray* b2;
                FdoInt32 count1;
                FdoInt32 count2;

                b1 = ((FdoCLOBValue*)argLeft)->GetData ();
                b2 = ((FdoCLOBValue*)argRight)->GetData ();
                count1 = b1->GetCount ();
                count2 = b2->GetCount ();
                ret = count1 == count2;
                for (int i = 0; ret && (i < count1); i++)
                    if ((*b1)[i] != (*b2)[i])
                        ret = false;
            }
            break;
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    return (ret);
}

bool FdoCommonMiscUtil::IsLessThan (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    bool ret;

    switch (argLeft->GetDataType ())
    {
        case FdoDataType_Boolean:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            break;
        case FdoDataType_Byte:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoByteValue*)argLeft)->GetByte () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            if (FdoDataType_DateTime != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
            {
                FdoDateTime t1;
                FdoDateTime t2;

                t1 = ((FdoDateTimeValue*)argLeft)->GetDateTime ();
                t2 = ((FdoDateTimeValue*)argRight)->GetDateTime ();
                ret = ((t1.year < t2.year) ||
                      ((t1.year == t2.year) && (t1.month < t2.month)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day < t2.day)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour < t2.hour)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour == t2.hour) && (t1.minute < t2.minute)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour == t2.hour) && (t1.minute == t2.minute) && (t1.seconds < t2.seconds)));
            }
            break;
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Double:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int16:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int32:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int64:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Single:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () < ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
            if (FdoDataType_String != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
                ret = 0 > wcscmp (((FdoStringValue*)argLeft)->GetString (), ((FdoStringValue*)argRight)->GetString ());
            break;
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    return (ret);
}

bool FdoCommonMiscUtil::IsGreaterThan (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    bool ret;

    switch (argLeft->GetDataType ())
    {
        case FdoDataType_Boolean:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            break;
        case FdoDataType_Byte:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoByteValue*)argLeft)->GetByte () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            if (FdoDataType_DateTime != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
            {
                FdoDateTime t1;
                FdoDateTime t2;

                t1 = ((FdoDateTimeValue*)argLeft)->GetDateTime ();
                t2 = ((FdoDateTimeValue*)argRight)->GetDateTime ();
                ret = ((t1.year > t2.year) ||
                      ((t1.year == t2.year) && (t1.month > t2.month)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day > t2.day)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour > t2.hour)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour == t2.hour) && (t1.minute > t2.minute)) ||
                      ((t1.year == t2.year) && (t1.month == t2.month) && (t1.day == t2.day) && (t1.hour == t2.hour) && (t1.minute == t2.minute) && (t1.seconds > t2.seconds)));
            }
            break;
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDecimalValue*)argLeft)->GetDecimal () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Double:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoDoubleValue*)argLeft)->GetDouble () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int16:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt16Value*)argLeft)->GetInt16 () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int32:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt32Value*)argLeft)->GetInt32 () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Int64:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoInt64Value*)argLeft)->GetInt64 () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_Single:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoByteValue*)argRight)->GetByte ();
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoDecimalValue*)argRight)->GetDecimal ();
                    break;
                case FdoDataType_Double:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoDoubleValue*)argRight)->GetDouble ();
                    break;
                case FdoDataType_Int16:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoInt16Value*)argRight)->GetInt16 ();
                    break;
                case FdoDataType_Int32:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoInt32Value*)argRight)->GetInt32 ();
                    break;
                case FdoDataType_Int64:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoInt64Value*)argRight)->GetInt64 ();
                    break;
                case FdoDataType_Single:
                    ret = ((FdoSingleValue*)argLeft)->GetSingle () > ((FdoSingleValue*)argRight)->GetSingle ();
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
            if (FdoDataType_String != argRight->GetDataType ())
                throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            else
                ret = 0 < wcscmp (((FdoStringValue*)argLeft)->GetString (), ((FdoStringValue*)argRight)->GetString ());
            break;
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    return (ret);
}


void FdoCommonMiscUtil::GetExpressionType(FdoFunctionDefinitionCollection *functionDefinitions, FdoClassDefinition* originalClassDef, FdoExpression *expr, FdoPropertyType &retPropType, FdoDataType &retDataType)
{
    VALIDATE_ARGUMENT(functionDefinitions);
    VALIDATE_ARGUMENT(originalClassDef);
    VALIDATE_ARGUMENT(expr);

    FdoPtr<FdoPropertyDefinitionCollection> properties = originalClassDef->GetProperties();
    FdoPtr<FdoReadOnlyPropertyDefinitionCollection> baseProperties = originalClassDef->GetBaseProperties();


    // Initialize return value to default:
    retPropType = FdoPropertyType_DataProperty;
    retDataType = FdoDataType_Int32;

    // Determine the proper return value:

    FdoUnaryExpression* unaryExpr = dynamic_cast<FdoUnaryExpression*>(expr);
    if (NULL != unaryExpr)
        GetExpressionType(functionDefinitions, originalClassDef, FdoPtr<FdoExpression>(unaryExpr->GetExpression()), retPropType, retDataType);

    FdoBinaryExpression* binaryExpr = dynamic_cast<FdoBinaryExpression*>(expr);
    if (NULL != binaryExpr)
    {
        FdoPropertyType leftPropType, rightPropType;
        FdoDataType leftDataType, rightDataType;
        GetExpressionType(functionDefinitions, originalClassDef, FdoPtr<FdoExpression>(binaryExpr->GetLeftExpression()), leftPropType, leftDataType);
        GetExpressionType(functionDefinitions, originalClassDef, FdoPtr<FdoExpression>(binaryExpr->GetRightExpression()), rightPropType, rightDataType);
        if ((leftPropType != FdoPropertyType_DataProperty) || (rightPropType != FdoPropertyType_DataProperty))
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));

        if (leftDataType==FdoDataType_Double)
        {
            if ((rightDataType==FdoDataType_Single) || (rightDataType==FdoDataType_Double) || (rightDataType==FdoDataType_Byte) || (rightDataType==FdoDataType_Decimal)
                 || (rightDataType==FdoDataType_Int16) || (rightDataType==FdoDataType_Int32) || (rightDataType==FdoDataType_Int64))
                retDataType = FdoDataType_Double;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Single)
        {
            if ((rightDataType==FdoDataType_Single) || (rightDataType==FdoDataType_Byte) 
                 || (rightDataType==FdoDataType_Int16) || (rightDataType==FdoDataType_Int32) || (rightDataType==FdoDataType_Int64))
                retDataType = FdoDataType_Single;
            else if (rightDataType==FdoDataType_Decimal)
                retDataType = FdoDataType_Decimal;
            else if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Decimal)
        {
            if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else if ((rightDataType==FdoDataType_Byte) || (rightDataType==FdoDataType_Decimal) || (rightDataType==FdoDataType_Single)
                 || (rightDataType==FdoDataType_Int16) || (rightDataType==FdoDataType_Int32) || (rightDataType==FdoDataType_Int64))
                retDataType = FdoDataType_Decimal;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Int64)
        {
            if (rightDataType==FdoDataType_Single)
                retDataType = FdoDataType_Single;
            else if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else if (rightDataType==FdoDataType_Decimal)
                retDataType = FdoDataType_Decimal;
            else if ((rightDataType==FdoDataType_Byte) || (rightDataType==FdoDataType_Int16) || (rightDataType==FdoDataType_Int32) || (rightDataType==FdoDataType_Int64))
                retDataType = FdoDataType_Int64;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Int32)
        {
            if (rightDataType==FdoDataType_Single)
                retDataType = FdoDataType_Single;
            else if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else if (rightDataType==FdoDataType_Decimal)
                retDataType = FdoDataType_Decimal;
            else if (rightDataType==FdoDataType_Int64)
                retDataType = FdoDataType_Int64;
            else if ((rightDataType==FdoDataType_Byte) || (rightDataType==FdoDataType_Int16) || (rightDataType==FdoDataType_Int32))
                retDataType = FdoDataType_Int32;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Int16)
        {
            if (rightDataType==FdoDataType_Single)
                retDataType = FdoDataType_Single;
            else if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else if (rightDataType==FdoDataType_Decimal)
                retDataType = FdoDataType_Decimal;
            else if (rightDataType==FdoDataType_Int64)
                retDataType = FdoDataType_Int64;
            else if (rightDataType==FdoDataType_Int32)
                retDataType = FdoDataType_Int32;
            else if ((rightDataType==FdoDataType_Byte) || (rightDataType==FdoDataType_Int16))
                retDataType = FdoDataType_Int16;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (leftDataType==FdoDataType_Byte)
        {
            if (rightDataType==FdoDataType_Single)
                retDataType = FdoDataType_Single;
            else if (rightDataType==FdoDataType_Double)
                retDataType = FdoDataType_Double;
            else if (rightDataType==FdoDataType_Decimal)
                retDataType = FdoDataType_Decimal;
            else if (rightDataType==FdoDataType_Int64)
                retDataType = FdoDataType_Int64;
            else if (rightDataType==FdoDataType_Int32)
                retDataType = FdoDataType_Int32;
            else if (rightDataType==FdoDataType_Int16)
                retDataType = FdoDataType_Int16;
            else if (rightDataType==FdoDataType_Byte)
                retDataType = FdoDataType_Byte;
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
    }

    FdoComputedIdentifier* computedId = dynamic_cast<FdoComputedIdentifier*>(expr);
    if (NULL != computedId)
        GetExpressionType(functionDefinitions, originalClassDef, FdoPtr<FdoExpression>(computedId->GetExpression()), retPropType, retDataType);
    else
    {
        FdoIdentifier* noncomputedId = dynamic_cast<FdoIdentifier*>(expr);
        if (NULL != noncomputedId)
        {
            FdoPtr<FdoPropertyDefinition> propDef = properties->FindItem(noncomputedId->GetName());
            FdoDataPropertyDefinition* dataPropDef = dynamic_cast<FdoDataPropertyDefinition*>(propDef.p);
            FdoPtr<FdoPropertyDefinition> basePropDef;
            try
            {
                basePropDef = baseProperties->GetItem(noncomputedId->GetName());
            }
            catch (FdoException *e)
            {
                e->Release();
            }
            FdoDataPropertyDefinition* baseDataPropDef = dynamic_cast<FdoDataPropertyDefinition*>(basePropDef.p);

            if (propDef != NULL)
            {
                retPropType = propDef->GetPropertyType();
                if (dataPropDef != NULL)
                    retDataType = dataPropDef->GetDataType();
            }
            else if (basePropDef != NULL)
            {
                retPropType = basePropDef->GetPropertyType();
                if (baseDataPropDef != NULL)
                    retDataType = baseDataPropDef->GetDataType();
            }
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_74_PROPERTY_NAME_NOT_FOUND), noncomputedId->GetName()));
        }
    }

    FdoBooleanValue* boolValue = dynamic_cast<FdoBooleanValue*>(expr);
    if (boolValue != NULL)
        retDataType = FdoDataType_Boolean;

    FdoByteValue* byteValue = dynamic_cast<FdoByteValue*>(expr);
    if (byteValue != NULL)
        retDataType = FdoDataType_Byte;

    FdoInt16Value* int16Value = dynamic_cast<FdoInt16Value*>(expr);
    if (int16Value != NULL)
        retDataType = FdoDataType_Int16;

    FdoInt32Value* int32Value = dynamic_cast<FdoInt32Value*>(expr);
    if (int32Value != NULL)
        retDataType = FdoDataType_Int32;

    FdoInt64Value* int64Value = dynamic_cast<FdoInt64Value*>(expr);
    if (int64Value != NULL)
        retDataType = FdoDataType_Int64;

    FdoSingleValue* singleValue = dynamic_cast<FdoSingleValue*>(expr);
    if (singleValue != NULL)
        retDataType = FdoDataType_Single;

    FdoDoubleValue* doubleValue = dynamic_cast<FdoDoubleValue*>(expr);
    if (doubleValue != NULL)
        retDataType = FdoDataType_Double;

    FdoDecimalValue* decimalValue = dynamic_cast<FdoDecimalValue*>(expr);
    if (decimalValue != NULL)
        retDataType = FdoDataType_Decimal;

    FdoDateTimeValue* datetimeValue = dynamic_cast<FdoDateTimeValue*>(expr);
    if (datetimeValue != NULL)
        retDataType = FdoDataType_DateTime;

    FdoStringValue* stringValue = dynamic_cast<FdoStringValue*>(expr);
    if (stringValue != NULL)
        retDataType = FdoDataType_String;

    FdoBLOBValue* blobValue = dynamic_cast<FdoBLOBValue*>(expr);
    if (blobValue != NULL)
        retDataType = FdoDataType_BLOB;

    FdoCLOBValue* CLOBValue = dynamic_cast<FdoCLOBValue*>(expr);
    if (CLOBValue != NULL)
        retDataType = FdoDataType_CLOB;

    FdoGeometryValue* geomValue = dynamic_cast<FdoGeometryValue*>(expr);
    if (geomValue != NULL)
    {
        retPropType = FdoPropertyType_GeometricProperty;
    }


    FdoFunction* function = dynamic_cast<FdoFunction*>(expr);
    if (NULL != function)
    {
        // Discover each argument 's property type and data type:
        FdoPtr<FdoExpressionCollection> args = function->GetArguments();
        FdoInt32 numArgs = args->GetCount();
        FdoPropertyType* argPropType = (FdoPropertyType*)alloca(sizeof(FdoPropertyType) * numArgs);
        FdoDataType*     argDataType = (FdoDataType*)    alloca(sizeof(FdoDataType)     * numArgs);
        for (int i=0; i<numArgs; i++)
        {
            FdoPtr<FdoExpression> arg = args->GetItem(i);
            GetExpressionType(functionDefinitions, originalClassDef, arg, argPropType[i], argDataType[i]);
        }

        // Match them up to the correct function signature:
        FdoPtr<FdoFunctionDefinition> funcDef = functionDefinitions->GetItem(function->GetName());
        FdoPtr<FdoReadOnlySignatureDefinitionCollection> sigDefs = funcDef->GetSignatures();
        bool bFound = false;
        for (int s=0; s<sigDefs->GetCount() && !bFound; s++)
        {
            FdoPtr<FdoSignatureDefinition> sigDef = sigDefs->GetItem(s);
            FdoPtr<FdoReadOnlyArgumentDefinitionCollection> sigArgs = sigDef->GetArguments();
            if (sigArgs->GetCount() != numArgs)
                continue;

            bFound = true;
            for (int a=0; a<numArgs && bFound; a++)
            {
                FdoPtr<FdoArgumentDefinition> sigArg = sigArgs->GetItem(a);

                bFound = (argPropType[a] == sigArg->GetPropertyType());
                if (bFound && (argPropType[a] == FdoPropertyType_DataProperty))
                    bFound = (argDataType[a] == sigArg->GetDataType());
            }

            if (bFound)
            {
                retPropType = sigDef->GetReturnPropertyType();
                retDataType = sigDef->GetReturnType();
            }
        }

        // If no matching signature was found, throw an exception:
        if (!bFound)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_183_INVALID_FUNCTION_ARG, "One or more arguments for function '%1$ls' did not match the expected argument types.", function->GetName()));
    }
}

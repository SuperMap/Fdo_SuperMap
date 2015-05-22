// 
//  
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//  
#include <stdafx.h>
#include <FdoCommonQueryAggregator.h>
#include <FdoCommonMiscUtil.h>
#include <float.h>
#include <limits>



FdoCommonQueryAggregator::FdoCommonQueryAggregator(FdoIConnection *conn, FdoClassDefinition* originalClassDef, FdoIdentifierCollection* selectedIds, FdoIFeatureReader* reader, FdoArray<FdoFunction*>* aggrFunctions)
:   FdoCommonFilterExecutor(reader, NULL)
{
    m_connection = FDO_SAFE_ADDREF(conn);
    m_aggrFunctions = FDO_SAFE_ADDREF(aggrFunctions);
    m_originalClassDef = FDO_SAFE_ADDREF(originalClassDef);
    m_selectedIds = FDO_SAFE_ADDREF(selectedIds);
}

FdoCommonQueryAggregator::~FdoCommonQueryAggregator()
{
}

void FdoCommonQueryAggregator::Dispose()
{
    delete this;
}

FdoPropertyValueCollection* FdoCommonQueryAggregator::RunQuery()
{
    //This code assumes that the identifier passed in to the Aggregator is an
    //aggregate function.  The argument to that function can be
    //any simple expression (i.e. not containing aggregates).

    // Initialize aggregate stats:
    for (FdoInt32 i=0; i<m_aggrFunctions->GetCount(); i++)
    {
        AggregateStats aggrStats;
        aggrStats.isNull = true;
        m_aggrStats.push_back(aggrStats);
    }

    // Evaluate all of the aggregate functions:
    m_EvaluatingAggregates = true;
    while (m_reader->ReadNext())
    {
        for (FdoInt32 i=0; i<m_aggrFunctions->GetCount(); i++)
        {
            m_aggrStatsIndex = i;
            FdoFunction* func = (*m_aggrFunctions)[i];
            func->Process(this);
        }
    }

    // Evaluate the remaining expressions:
    m_EvaluatingAggregates = false;
    FdoPtr<FdoPropertyValueCollection> retPropertyValues = FdoPropertyValueCollection::Create();
    for (FdoInt32 i=0; i<m_selectedIds->GetCount(); i++)
    {
        FdoPtr<FdoIdentifier> selectedId = m_selectedIds->GetItem(i);

        FdoPtr<FdoPropertyValue> pv = FdoPropertyValue::Create();
        pv->SetName(selectedId->GetName());
        FdoPtr<FdoLiteralValue> dv;

        selectedId->Process(this);

        switch (this->GetResultPropertyType())
        {
            case FdoPropertyType_DataProperty:
            {
                switch (this->GetResultDataType())
                {
                    case FdoDataType_Int32:
                    {
                        bool bIsNull;
                        FdoInt32 int32 = GetInt32Result(bIsNull);
                        if (bIsNull)
                            dv = FdoInt32Value::Create();  // defaults to NULL
                        else
                            dv = FdoInt32Value::Create(int32);
                    }
                    break;
                    case FdoDataType_Int64:   
                    {
                        bool bIsNull;
                        FdoInt64 int64 = GetInt64Result(bIsNull);
                        if (bIsNull)
                            dv = FdoInt64Value::Create();  // defaults to NULL
                        else
                            dv = FdoInt64Value::Create(int64);  
                    }
                    break;
                    case FdoDataType_Boolean: 
                    {
                        bool bIsNull;
                        bool boolean = GetBooleanResult(bIsNull);
                        if (bIsNull)
                            dv = FdoBooleanValue::Create();  // defaults to NULL
                        else
                            dv = FdoBooleanValue::Create(boolean);
                    }
                    break;
                    case FdoDataType_DateTime:
                    {
                        bool bIsNull;
                        FdoDateTime datetime = GetDateTimeResult(bIsNull);
                        if (bIsNull)
                            dv = FdoDateTimeValue::Create();  // defaults to NULL
                        else
                            dv = FdoDateTimeValue::Create(datetime);
                    }
                    break;
                    case FdoDataType_Double:  
                    {
                        bool bIsNull;
                        double dvalue = GetDoubleResult(bIsNull);
                        if (bIsNull)
                            dv = FdoDoubleValue::Create();  // defaults to NULL
                        else
                            dv = FdoDoubleValue::Create(dvalue);
                    }
                    break;
                    case FdoDataType_String:  
                    {
                        bool bIsNull;
                        FdoString* string = GetStringResult(bIsNull);
                        if (bIsNull)
                            dv = FdoStringValue::Create();  // defaults to NULL
                        else
                            dv = FdoStringValue::Create(string);
                    }
                    break;
                    default:
                        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(this->GetResultDataType())));
                }
            }
            break;

            case FdoPropertyType_GeometricProperty:
            {
                bool bIsNull;
                FdoPtr<FdoGeometryValue> geom = GetGeometricResult(bIsNull);
                if (bIsNull)
                    dv = FdoGeometryValue::Create();  // defaults to NULL
                else
                    dv = FDO_SAFE_ADDREF(geom.p);

            }
            break;

            default:
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_70_PROPERTY_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoPropertyTypeToString(this->GetResultPropertyType())));
        }

        pv->SetValue(dv);
        retPropertyValues->Add(pv);
    }

    return FDO_SAFE_ADDREF(retPropertyValues.p);
}



//--------------------------------------------------------------------
// FdoIExpressionProcessor
//--------------------------------------------------------------------

void FdoCommonQueryAggregator::ProcessFunction(FdoFunction& expr)
{
    //check for aggregate functions... only type we support in this class
    if ( IsAggregateFunction(expr.GetName()) )
    {
        if (!m_EvaluatingAggregates)
        {
            for (FdoInt32 i=0; i<m_aggrFunctions->GetCount(); i++)
            {
                FdoFunction* aggrFunc = (*m_aggrFunctions)[i]; 
                if (aggrFunc == &expr)
                {
                    FdoLiteralValue* dv = NULL;
                    AggregateStats &aggrStats = m_aggrStats.at(i);

                    FdoPropertyType propType;
                    FdoDataType dataType;
                    GetExpressionType(m_connection, m_originalClassDef, aggrFunc, propType, dataType);

                    switch (propType)
                    {
                    case FdoPropertyType_DataProperty:
                        switch (dataType)
                        {
                        case FdoDataType_Int64:
                            if (aggrStats.isNull)
                                dv = FdoInt64Value::Create();  // defaults to NULL
                            else
                                dv = FdoInt64Value::Create(aggrStats.int64Val);
                        break;

                        case FdoDataType_Double:
                            if (aggrStats.isNull)
                                dv = FdoDoubleValue::Create();  // defaults to NULL
                            else
                                dv = FdoDoubleValue::Create(aggrStats.doubleVal);
                        break;

                        case FdoDataType_String:
                            if (aggrStats.isNull)
                                dv = FdoStringValue::Create();  // defaults to NULL
                            else
                                dv = FdoStringValue::Create(aggrStats.stringVal);
                        break;

                        case FdoDataType_DateTime:
                            if (aggrStats.isNull)
                                dv = FdoDateTimeValue::Create();  // defaults to NULL
                            else
                                dv = FdoDateTimeValue::Create(aggrStats.dateTimeVal);
                        break;

                        default:
                            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
                        }
                    break;

                    case FdoPropertyType_GeometricProperty:
                        if (aggrStats.isNull)
                            dv = FdoGeometryValue::Create();  // defaults to NULL
                        else
                        {
                            FdoPtr<FdoFgfGeometryFactory> gf = FdoFgfGeometryFactory::GetInstance();
                            FdoPtr<FdoByteArray> geomBytes = gf->GetFgf(aggrStats.geomVal);
                            dv = FdoGeometryValue::Create(geomBytes);
                        }
                    break;

                    default:
                        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
                    }

                    m_retvals.push_back(dv);

                    break;
                }
            }
        }
        else
        {
            FdoPtr<FdoExpressionCollection> args = expr.GetArguments();
            
            if (args->GetCount() != 1)
                throw FdoExpressionException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_75_INVALID_NUM_ARGUMENTS), expr.GetName(), 1, args->GetCount()));

            FdoPtr<FdoExpression> arg = args->GetItem(0);

            //eval argument
            arg->Process(this);

            // If it is a number, get the result (cast to double); in the case of COUNT(),
            // this could be any type (e.g. geometry) so don't complain if not numeric:
            double d = 0.0;
            FdoString* strResult = NULL;
            FdoDateTime dateTimeResult;
            bool bValueIsNull = false;
            FdoDataType resultDataType;
            if (GetResultPropertyType() == FdoPropertyType_DataProperty)
            {
                resultDataType = GetResultDataType();
                if (resultDataType == FdoDataType_Double)
                    d = GetDoubleResult(bValueIsNull);
                else if (resultDataType == FdoDataType_Single)
                    d = (double)GetSingleResult(bValueIsNull);
                else if (resultDataType == FdoDataType_Decimal)
                    d = (double)GetDecimalResult(bValueIsNull);
                else if (resultDataType == FdoDataType_Byte)
                    d = (double)GetByteResult(bValueIsNull);
                else if (resultDataType == FdoDataType_Int16)
                    d = (double)GetInt16Result(bValueIsNull);
                else if (resultDataType == FdoDataType_Int32)
                    d = (double)GetInt32Result(bValueIsNull);
                else if (resultDataType == FdoDataType_Int64)
                    d = (double)GetInt64Result(bValueIsNull);
                else if (resultDataType == FdoDataType_String)
                    strResult = GetStringResult(bValueIsNull);
                else if (resultDataType == FdoDataType_DateTime)
                    dateTimeResult = GetDateTimeResult(bValueIsNull);
            }

            // Handle the aggregate function logic:
            AggregateStats &aggrStats = m_aggrStats.at(m_aggrStatsIndex);
            if (0==wcscmp(expr.GetName(), FDO_FUNCTION_MIN))
            {
                if (!bValueIsNull)
                {
                    if (resultDataType==FdoDataType_String)
                    {
                        if (aggrStats.isNull || (0>wcscmp(strResult, aggrStats.stringVal)))
                        {
                            aggrStats.stringVal = strResult;
                            aggrStats.isNull = false;
                        }
                    }
                    else if (resultDataType==FdoDataType_DateTime)
                    {
                        if (aggrStats.isNull || (0>FdoCommonMiscUtil::CompareDateTimes(dateTimeResult, aggrStats.dateTimeVal)))
                        {
                            aggrStats.dateTimeVal = dateTimeResult;
                            aggrStats.isNull = false;
                        }
                    }
                    else  // datatype is decimal, double, single, int16, int32, etc
                    {
                        if (aggrStats.isNull || (d < aggrStats.doubleVal))
                        {
                            aggrStats.doubleVal = d;
                            aggrStats.isNull = false;
                        }
                    }
                }
            }
            else if (0==wcscmp(expr.GetName(), FDO_FUNCTION_AVG))
            {
                if (!bValueIsNull)
                {
                    if (aggrStats.isNull)
                        aggrStats.int64Val = 1;
                    else
                        aggrStats.int64Val += 1;

                    if (aggrStats.isNull)
                        aggrStats.doubleValAccumulator = d;
                    else
                        aggrStats.doubleValAccumulator += d;

                    aggrStats.doubleVal = aggrStats.doubleValAccumulator / aggrStats.int64Val;
                    aggrStats.isNull = false;
                }
            }
            else if (0==wcscmp(expr.GetName(), FDO_FUNCTION_MAX))
            {
                if (!bValueIsNull)
                {
                    if (resultDataType==FdoDataType_String)
                    {
                        if (aggrStats.isNull || (0<wcscmp(strResult, aggrStats.stringVal)))
                        {
                            aggrStats.stringVal = strResult;
                            aggrStats.isNull = false;
                        }
                    }
                    else if (resultDataType==FdoDataType_DateTime)
                    {
                        if (aggrStats.isNull || (0<FdoCommonMiscUtil::CompareDateTimes(dateTimeResult, aggrStats.dateTimeVal)))
                        {
                            aggrStats.dateTimeVal = dateTimeResult;
                            aggrStats.isNull = false;
                        }
                    }
                    else  // datatype is decimal, double, single, int16, int32, etc
                    {
                        if (aggrStats.isNull || (d > aggrStats.doubleVal))
                        {
                            aggrStats.doubleVal = d;
                            aggrStats.isNull = false;
                        }
                    }
                }
            }
            else if (0==wcscmp(expr.GetName(), FDO_FUNCTION_SUM))
            {
                if (!bValueIsNull)
                {
                    if (aggrStats.isNull)
                        aggrStats.doubleVal = d;
                    else
                        aggrStats.doubleVal += d;
                    aggrStats.isNull = false;
                }
            }
            else if (0==wcscmp(expr.GetName(), FDO_FUNCTION_COUNT))
            {
                // NOTE: here we don't care if the value is null or not (bValueIsNull), each counts as one row
                if (aggrStats.isNull)
                    aggrStats.int64Val = 1;
                else
                    aggrStats.int64Val += 1;
                aggrStats.isNull = false;
            }
            else if (0==wcscmp(expr.GetName(), FDO_FUNCTION_SPATIALEXTENTS))
            {
                FdoPtr<FdoGeometryValue> geomValue = GetGeometricResult(bValueIsNull);
                if (!bValueIsNull)
                {
                    FdoPtr<FdoFgfGeometryFactory> gf = FdoFgfGeometryFactory::GetInstance();
                    FdoPtr<FdoIGeometry> geom = gf->CreateGeometryFromFgf(FdoPtr<FdoByteArray>(geomValue->GetGeometry()));
                    FdoPtr<FdoIEnvelope> envelope = geom->GetEnvelope();

                    double ordinates[15];
                    int i=0;

                    if (aggrStats.isNull)
                    {
                        ordinates[i] = envelope->GetMinX();  i++;
                        ordinates[i] = envelope->GetMinY();  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = envelope->GetMinZ();  i++;
                        }

                        ordinates[i] = envelope->GetMaxX();  i++;
                        ordinates[i] = envelope->GetMinY();  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = envelope->GetMaxZ();  i++;
                        }

                        ordinates[i] = envelope->GetMaxX();  i++;
                        ordinates[i] = envelope->GetMaxY();  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = envelope->GetMaxZ();  i++;
                        }

                        ordinates[i] = envelope->GetMinX();  i++;
                        ordinates[i] = envelope->GetMaxY();  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = envelope->GetMinZ();  i++;
                        }

                        ordinates[i] = envelope->GetMinX();  i++;
                        ordinates[i] = envelope->GetMinY();  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = envelope->GetMinZ();  i++;
                        }
                    }
                    else
                    {
            	        FdoIPolygon* aggrExtents = static_cast<FdoIPolygon*>(aggrStats.geomVal.p);
                        FdoPtr<FdoILinearRing> linearRing = aggrExtents->GetExteriorRing();
                        const double* aggrOrdinates = linearRing->GetOrdinates();

                        ordinates[i] = FdoCommonMin(envelope->GetMinX(), aggrOrdinates[i]);  i++;
                        ordinates[i] = FdoCommonMin(envelope->GetMinY(), aggrOrdinates[i]);  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = FdoCommonMin(envelope->GetMinZ(), aggrOrdinates[i]);  i++;
                        }

                        ordinates[i] = FdoCommonMin(envelope->GetMaxX(), aggrOrdinates[i]);  i++;
                        ordinates[i] = FdoCommonMin(envelope->GetMinY(), aggrOrdinates[i]);  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = FdoCommonMax(envelope->GetMaxZ(), aggrOrdinates[i]);  i++;
                        }

                        ordinates[i] = FdoCommonMax(envelope->GetMaxX(), aggrOrdinates[i]);  i++;
                        ordinates[i] = FdoCommonMax(envelope->GetMaxY(), aggrOrdinates[i]);  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = FdoCommonMax(envelope->GetMaxZ(), aggrOrdinates[i]);  i++;
                        }

                        ordinates[i] = FdoCommonMax(envelope->GetMinX(), aggrOrdinates[i]);  i++;
                        ordinates[i] = FdoCommonMax(envelope->GetMaxY(), aggrOrdinates[i]);  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = FdoCommonMin(envelope->GetMinZ(), aggrOrdinates[i]);  i++;
                        }

                        ordinates[i] = FdoCommonMin(envelope->GetMinX(), aggrOrdinates[i]);  i++;
                        ordinates[i] = FdoCommonMin(envelope->GetMinY(), aggrOrdinates[i]);  i++;
                        if (geom->GetDimensionality() & FdoDimensionality_Z)
                        {
                            ordinates[i] = FdoCommonMin(envelope->GetMinZ(), aggrOrdinates[i]);  i++;
                        }
                    }

                    FdoPtr<FdoILinearRing> linearRing = gf->CreateLinearRing(geom->GetDimensionality() & ~FdoDimensionality_M, i, ordinates);
            	    FdoPtr<FdoIPolygon> extents = gf->CreatePolygon(linearRing, NULL);

                    aggrStats.isNull = false;
                    aggrStats.geomVal = FDO_SAFE_ADDREF(extents.p);
                }
            }
            else
                throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
        }
    }
    else
        return FdoCommonFilterExecutor::ProcessFunction(expr);
}


bool FdoCommonQueryAggregator::IsAggregateFunction(FdoString* name)
{
    return (wcscmp(name, FDO_FUNCTION_MIN) == 0)
        || (wcscmp(name, FDO_FUNCTION_AVG) == 0)
        || (wcscmp(name, FDO_FUNCTION_MAX) == 0)
        || (wcscmp(name, FDO_FUNCTION_SUM) == 0)
        || (wcscmp(name, FDO_FUNCTION_COUNT) == 0)
        || (wcscmp(name, FDO_FUNCTION_SPATIALEXTENTS) == 0);
}



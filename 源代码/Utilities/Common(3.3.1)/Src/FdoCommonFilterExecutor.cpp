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

#include <stdafx.h>
#include <FdoCommonFilterExecutor.h>
#include <FdoCommonOSUtil.h>
#include <FdoCommonMiscUtil.h>

#include <Spatial/SpatialStd.h>
#include <Spatial/SpatialUtility.h>

#include <wctype.h>
#include <malloc.h>
#include <math.h>
#include <limits.h>

FdoCommonFilterExecutor::FdoCommonFilterExecutor (FdoIReader* reader, FdoIdentifierCollection* compIdents)
{
    m_reader = reader;  // NOTE: weak reference
    m_compIdents = FDO_SAFE_ADDREF(compIdents);
}

FdoCommonFilterExecutor::~FdoCommonFilterExecutor ()
{
    for (retval_stack::iterator iter = m_retvals.begin (); iter != m_retvals.end (); iter++)
        delete *iter;
    for (std::vector<FdoBooleanValue*>::iterator i = mBooleanPool.begin (); i != mBooleanPool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoByteValue*>::iterator i = mBytePool.begin (); i != mBytePool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoDateTimeValue*>::iterator i = mDateTimePool.begin (); i != mDateTimePool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoDecimalValue*>::iterator i = mDecimalPool.begin (); i != mDecimalPool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoDoubleValue*>::iterator i = mDoublePool.begin (); i != mDoublePool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoInt16Value*>::iterator i = mInt16Pool.begin (); i != mInt16Pool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoInt32Value*>::iterator i = mInt32Pool.begin (); i != mInt32Pool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoInt64Value*>::iterator i = mInt64Pool.begin (); i != mInt64Pool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoSingleValue*>::iterator i = mSinglePool.begin (); i != mSinglePool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoStringValue*>::iterator i = mStringPool.begin (); i != mStringPool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoBLOBValue*>::iterator i = mBLOBPool.begin (); i != mBLOBPool.end (); i++)
        (*i)->Release ();
    for (std::vector<FdoCLOBValue*>::iterator i = mCLOBPool.begin (); i != mCLOBPool.end (); i++)
        (*i)->Release ();
}

FdoCommonFilterExecutor* FdoCommonFilterExecutor::Create (FdoIReader* featureReader, FdoIdentifierCollection* compIdents)
{
    return new FdoCommonFilterExecutor (featureReader, compIdents);
}


void FdoCommonFilterExecutor::Dispose ()
{
    delete this;
}


FdoPropertyDefinition* FdoCommonFilterExecutor::GetPropInfo (FdoString* name)
{
    FdoPtr<FdoClassDefinition> definition;
    FdoPtr<FdoPropertyDefinitionCollection> properties;
    FdoPropertyDefinition* ret;

    definition = ((FdoIFeatureReader*)m_reader)->GetClassDefinition ();
    properties = definition->GetProperties ();
    ret = properties->FindItem (name);

    return (ret);
}

void FdoCommonFilterExecutor::Reset ()
{
    for (retval_stack::iterator iter = m_retvals.begin (); iter != m_retvals.end (); iter++)
        RelinquishDataValue (*iter);

    m_retvals.clear ();
}

//returns the data type of the result
//of the expression/filter evaluation.
//For filters it is always boolean
FdoDataType FdoCommonFilterExecutor::GetResultDataType ()
{
    if (GetResultPropertyType() != FdoPropertyType_DataProperty)
        throw FdoException::Create(FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    return (static_cast<FdoDataValue*>(m_retvals.back ())->GetDataType ());
}

FdoPropertyType FdoCommonFilterExecutor::GetResultPropertyType ()
{
    if ( dynamic_cast<FdoDataValue*>(m_retvals.back ()) != NULL )
        return FdoPropertyType_DataProperty;
    else if ( dynamic_cast<FdoGeometryValue*>(m_retvals.back ()) != NULL )
        return FdoPropertyType_GeometricProperty;
    else
        throw FdoException::Create(FdoException::NLSGetMessage (FDO_NLSID (FDO_57_UNEXPECTEDERROR)));
}

bool FdoCommonFilterExecutor::IsResultNull ()
{
    FdoPropertyType propType = GetResultPropertyType();
    if (propType == FdoPropertyType_DataProperty)
        return ((FdoDataValue*)m_retvals.back())->IsNull();
    else if (propType == FdoPropertyType_GeometricProperty)
        return ((FdoGeometryValue*)m_retvals.back())->IsNull();
    else
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
}


bool FdoCommonFilterExecutor::GetBooleanResult (bool &bIsNull)
{
    bool ret = false;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Boolean != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoBooleanValue*)dv)->GetBoolean ();

    RelinquishDataValue (dv);
    
    return (ret);
}


double FdoCommonFilterExecutor::GetDoubleResult (bool &bIsNull)
{
    double ret = 0.0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Double != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoDoubleValue*)dv)->GetDouble ();

    RelinquishDataValue (dv);
    
    return (ret);
}

float FdoCommonFilterExecutor::GetSingleResult (bool &bIsNull)
{
    float ret = 0.0f;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Single != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoSingleValue*)dv)->GetSingle ();

    RelinquishDataValue (dv);
    
    return (ret);
}

double FdoCommonFilterExecutor::GetDecimalResult (bool &bIsNull)
{
    double ret = 0.0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Decimal != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoDecimalValue*)dv)->GetDecimal ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoByte FdoCommonFilterExecutor::GetByteResult (bool &bIsNull)
{
    FdoByte ret = 0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Byte != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoByteValue*)dv)->GetByte ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoInt16 FdoCommonFilterExecutor::GetInt16Result (bool &bIsNull)
{
    FdoInt16 ret = 0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Int16 != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoInt16Value*)dv)->GetInt16 ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoInt32 FdoCommonFilterExecutor::GetInt32Result (bool &bIsNull)
{
    FdoInt32 ret = 0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Int32 != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoInt32Value*)dv)->GetInt32 ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoInt64 FdoCommonFilterExecutor::GetInt64Result (bool &bIsNull)
{
    FdoInt64 ret = 0;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_Int64 != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoInt64Value*)dv)->GetInt64 ();

    RelinquishDataValue (dv);
    
    return (ret);
}

const wchar_t* FdoCommonFilterExecutor::GetStringResult (bool &bIsNull)
{
    const wchar_t* ret = NULL;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_String != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoStringValue*)dv)->GetString ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoDateTime FdoCommonFilterExecutor::GetDateTimeResult (bool &bIsNull)
{
    FdoDateTime ret;

    if (FdoPropertyType_DataProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoDataValue* dv = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (FdoDataType_DateTime != dv->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    bIsNull = dv->IsNull();
    if (!bIsNull)
        ret = ((FdoDateTimeValue*)dv)->GetDateTime ();

    RelinquishDataValue (dv);
    
    return (ret);
}

FdoGeometryValue* FdoCommonFilterExecutor::GetGeometricResult (bool &bIsNull)
{
    FdoGeometryValue* ret = NULL;

    if (FdoPropertyType_GeometricProperty != GetResultPropertyType())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    FdoGeometryValue* gv = (FdoGeometryValue*)m_retvals.back ();
    m_retvals.pop_back ();

    bIsNull = gv->IsNull();
    ret = gv;

    //We dont (yet) cache geometry values:
    //RelinquishDataValue (dv);
    
    return (ret);
}

FdoBooleanValue* FdoCommonFilterExecutor::ObtainBooleanValue (bool bIsNull, bool value)
{
    FdoBooleanValue* ret;

    if (0 == mBooleanPool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoBooleanValue::Create();  // defaults to NULL
        else
            ret = FdoBooleanValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mBooleanPool.back ();
        mBooleanPool.pop_back ();
        if (bIsNull)
            ret->SetNull();
        else
            ret->SetBoolean (value);
    }

    return (ret);
}

FdoByteValue* FdoCommonFilterExecutor::ObtainByteValue (bool bIsNull, FdoByte value)
{
    FdoByteValue* ret;

    if (0 == mBytePool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoByteValue::Create (); // defaults to NULL
        else
            ret = FdoByteValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mBytePool.back ();
        mBytePool.pop_back ();
        if (bIsNull)
            ret->SetNull();
        else
            ret->SetByte (value);
    }

    return (ret);
}

FdoDateTimeValue* FdoCommonFilterExecutor::ObtainDateTimeValue (bool bIsNull, FdoDateTime value)
{
    FdoDateTimeValue* ret;

    if (0 == mDateTimePool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoDateTimeValue::Create ();  // defaults to NULL
        else
            ret = FdoDateTimeValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mDateTimePool.back ();
        mDateTimePool.pop_back ();
        if (bIsNull)
            ret->SetNull();
        else
            ret->SetDateTime (value);
    }

    return (ret);
}

FdoDecimalValue* FdoCommonFilterExecutor::ObtainDecimalValue (bool bIsNull, double value)
{
    FdoDecimalValue* ret;

    if (0 == mDecimalPool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoDecimalValue::Create ();  // defaults to NULL
        else
            ret = FdoDecimalValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mDecimalPool.back ();
        mDecimalPool.pop_back ();
        if (bIsNull)
            ret->SetNull();
        else
            ret->SetDecimal (value);
    }

    return (ret);
}

FdoDoubleValue* FdoCommonFilterExecutor::ObtainDoubleValue (bool bIsNull, double value)
{
    FdoDoubleValue* ret;

    if (0 == mDoublePool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoDoubleValue::Create ();  // defaults to NULL
        else
            ret = FdoDoubleValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mDoublePool.back ();
        mDoublePool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetDouble (value);
    }

    return (ret);
}

FdoInt16Value* FdoCommonFilterExecutor::ObtainInt16Value (bool bIsNull, FdoInt16 value)
{
    FdoInt16Value* ret;

    if (0 == mInt16Pool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoInt16Value::Create ();  // defaults to NULL
        else
            ret = FdoInt16Value::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mInt16Pool.back ();
        mInt16Pool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetInt16 (value);
    }

    return (ret);
}

FdoInt32Value* FdoCommonFilterExecutor::ObtainInt32Value (bool bIsNull, FdoInt32 value)
{
    FdoInt32Value* ret;

    if (0 == mInt32Pool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoInt32Value::Create ();  // defaults to NULL
        else
            ret = FdoInt32Value::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mInt32Pool.back ();
        mInt32Pool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetInt32 (value);
    }

    return (ret);
}

FdoInt64Value* FdoCommonFilterExecutor::ObtainInt64Value (bool bIsNull, FdoInt64 value)
{
    FdoInt64Value* ret;

    if (0 == mInt64Pool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoInt64Value::Create ();  // defaults to NULL
        else
            ret = FdoInt64Value::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mInt64Pool.back ();
        mInt64Pool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetInt64 (value);
    }

    return (ret);
}

FdoSingleValue* FdoCommonFilterExecutor::ObtainSingleValue (bool bIsNull, float value)
{
    FdoSingleValue* ret;

    if (0 == mSinglePool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoSingleValue::Create ();  // defaults to NULL
        else
            ret = FdoSingleValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mSinglePool.back ();
        mSinglePool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetSingle (value);
    }

    return (ret);
}

FdoStringValue* FdoCommonFilterExecutor::ObtainStringValue (bool bIsNull, FdoString* value)
{
    FdoStringValue* ret;

    if (0 == mStringPool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoStringValue::Create ();  // defaults to NULL
        else
            ret = FdoStringValue::Create (value);
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mStringPool.back ();
        mStringPool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetString (value);
    }

    return (ret);
}

FdoBLOBValue* FdoCommonFilterExecutor::ObtainBLOBValue (bool bIsNull, FdoByteArray* value)
{
    FdoBLOBValue* ret;

    if (0 == mBLOBPool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoBLOBValue::Create ();  // defaults to NULL;
        else
            ret = FdoBLOBValue::Create (value);  //TODO: there is probable a memory leak here
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mBLOBPool.back ();
        mBLOBPool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetData (value);
    }

    return (ret);
}

FdoCLOBValue* FdoCommonFilterExecutor::ObtainCLOBValue (bool bIsNull, FdoByteArray* value)
{
    FdoCLOBValue* ret;

    if (0 == mCLOBPool.size ())
    {
        // if the pool is empty, create new
        if (bIsNull)
            ret = FdoCLOBValue::Create ();  // defaults to NULL
        else
            ret = FdoCLOBValue::Create (value);  //TODO: there is probable a memory leak here
    }
    else
    {  // otherwise get an object from the pool and initialize it
        ret = mCLOBPool.back ();
        mCLOBPool.pop_back ();
        if (bIsNull)
            ret->SetNull ();
        else
            ret->SetData (value);
    }

    return (ret);
}

FdoGeometryValue* FdoCommonFilterExecutor::ObtainGeometryValue (bool bIsNull, FdoByteArray* value)
{
    FdoGeometryValue* ret;

    // No geometry pooling (yet)
    if (bIsNull)
        ret = FdoGeometryValue::Create ();
    else
        ret = FdoGeometryValue::Create (value);

    return ret;
}

void FdoCommonFilterExecutor::RelinquishDataValue (FdoLiteralValue* data)
{
    if (dynamic_cast<FdoDataValue*>(data) != NULL)
    {
        switch (((FdoDataValue*)data)->GetDataType ())
        {
            case FdoDataType_Boolean:
                mBooleanPool.push_back ((FdoBooleanValue*)data);
                break;
            case FdoDataType_Byte:
                mBytePool.push_back ((FdoByteValue*)data);
                break;
            case FdoDataType_DateTime:
                mDateTimePool.push_back ((FdoDateTimeValue*)data);
                break;
            case FdoDataType_Decimal:
                mDecimalPool.push_back ((FdoDecimalValue*)data);
                break;
            case FdoDataType_Double:
                mDoublePool.push_back ((FdoDoubleValue*)data);
                break;
            case FdoDataType_Int16:
                mInt16Pool.push_back ((FdoInt16Value*)data);
                break;
            case FdoDataType_Int32:
                mInt32Pool.push_back ((FdoInt32Value*)data);
                break;
            case FdoDataType_Int64:
                mInt64Pool.push_back ((FdoInt64Value*)data);
                break;
            case FdoDataType_Single:
                mSinglePool.push_back ((FdoSingleValue*)data);
                break;
            case FdoDataType_String:
                mStringPool.push_back ((FdoStringValue*)data);
                break;
            case FdoDataType_BLOB:
                mBLOBPool.push_back ((FdoBLOBValue*)data);
                break;
            case FdoDataType_CLOB:
                mCLOBPool.push_back ((FdoCLOBValue*)data);
                break;
            default:
                data->Release ();
        }
    }
    else if (dynamic_cast<FdoGeometryValue*>(data) != NULL)
    {
        // nothing to do since we dont pool geometry values (yet)
    }
    else
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_57_UNEXPECTEDERROR)));
}

void FdoCommonFilterExecutor::ProcessBinaryLogicalOperator (FdoBinaryLogicalOperator& filter)
{
    FdoPtr<FdoFilter> left = filter.GetLeftOperand ();
    FdoPtr<FdoFilter> right = filter.GetRightOperand ();

    //evaluate left hand side
    left->Process (this);
    bool bIsNull;
    bool argLeft = GetBooleanResult (bIsNull);
    if (bIsNull)
    {
        m_retvals.push_back (ObtainBooleanValue (true, false));
        return;
    }

    // optimize binary logic by looking at the value of the left operand and see
    // if we have to evaluate the right one also
    if (argLeft && filter.GetOperation () == FdoBinaryLogicalOperations_Or)
    {
        m_retvals.push_back (ObtainBooleanValue (false, true));
        return;
    }
    else if (!argLeft && filter.GetOperation () == FdoBinaryLogicalOperations_And)
    {
        m_retvals.push_back (ObtainBooleanValue (false, false));
        return;
    }
    
    // evaluate right hand side
    right->Process (this);
    bool argRight = GetBooleanResult (bIsNull);
    if (bIsNull)
        m_retvals.push_back (ObtainBooleanValue (true, false));
    else switch (filter.GetOperation ())
    {
        case FdoBinaryLogicalOperations_And: 
            m_retvals.push_back (ObtainBooleanValue (false, argLeft && argRight)); 
            break;
        case FdoBinaryLogicalOperations_Or : 
            m_retvals.push_back (ObtainBooleanValue (false, argLeft || argRight));
            break;
        default: 
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_82_UNSUPPORTED_LOGICAL_OPERATION)));
            break;
    }
}

void FdoCommonFilterExecutor::ProcessUnaryLogicalOperator (FdoUnaryLogicalOperator& filter)
{
    FdoPtr<FdoFilter> right = filter.GetOperand ();

    // evaluate right hand side
    right->Process (this);

    // get Process() results from return value stack
    bool bIsNull;
    bool argRight = GetBooleanResult (bIsNull);

    switch (filter.GetOperation ())
    {
        case FdoUnaryLogicalOperations_Not: 
            m_retvals.push_back (ObtainBooleanValue (bIsNull, bIsNull ? false : !argRight)); 
            break;
        default: 
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_82_UNSUPPORTED_LOGICAL_OPERATION)));break;
    }
}

void FdoCommonFilterExecutor::ProcessComparisonCondition (FdoComparisonCondition& filter)
{
    FdoPtr<FdoExpression> left = filter.GetLeftExpression ();
    FdoPtr<FdoExpression> right = filter.GetRightExpression ();

    right->Process (this);
    left->Process (this);
    
    //get Process() results from return value stack
    FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();
    FdoDataValue* argRight = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    if (argLeft->IsNull() || argRight->IsNull())
        m_retvals.push_back (ObtainBooleanValue (true, false));
    else switch (filter.GetOperation ())
    {
        case FdoComparisonOperations_EqualTo : 
            m_retvals.push_back (ObtainBooleanValue (false, IsEqualTo (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_NotEqualTo : 
            m_retvals.push_back (ObtainBooleanValue (false, !IsEqualTo (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_GreaterThan : 
            m_retvals.push_back (ObtainBooleanValue (false, IsGreaterThan (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_GreaterThanOrEqualTo : 
            m_retvals.push_back (ObtainBooleanValue (false, !IsLessThan (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_LessThan : 
            m_retvals.push_back (ObtainBooleanValue (false, IsLessThan (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_LessThanOrEqualTo : 
            m_retvals.push_back (ObtainBooleanValue (false, !IsGreaterThan (argLeft, argRight))); 
            break;
        case FdoComparisonOperations_Like :
            m_retvals.push_back (ObtainBooleanValue (false, Like (argLeft, argRight)));
            break;    
        default:
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_83_UNSUPPORTED_COMPARISON_OPERATION)));
    }

    RelinquishDataValue (argRight);
    RelinquishDataValue (argLeft);
}

void FdoCommonFilterExecutor::ProcessInCondition (FdoInCondition& filter)
{
    //first get the value of the property we are checking
    FdoPtr<FdoIdentifier> prop = filter.GetPropertyName ();
    ProcessIdentifier (*(prop.p));

    //get the property value off the stack
    FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    FdoPtr<FdoValueExpressionCollection> vals = filter.GetValues ();

    bool result = false;

    //see if the value collection contains the property value
    FdoInt32 count = vals->GetCount ();
    for (int i = 0; !result && (i < count); i++)
    {
        FdoPtr<FdoValueExpression> expr = vals->GetItem (i);
        expr->Process (this);

        FdoDataValue* argRight = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

        if (IsEqualTo (argLeft, argRight))
            result = true;

        RelinquishDataValue (argRight);

        if (result)
            break;
    }

    //if prop val is not IN the val collection, push false on the stack
    m_retvals.push_back (ObtainBooleanValue (false, result));

    RelinquishDataValue (argLeft);
}

void FdoCommonFilterExecutor::ProcessNullCondition (FdoNullCondition& filter)
{
    //first get the value of the property we are checking
    FdoPtr<FdoIdentifier> prop = filter.GetPropertyName ();
    
    bool isNull = m_reader->IsNull (prop->GetName ());

    m_retvals.push_back (ObtainBooleanValue (false, isNull));
}

void FdoCommonFilterExecutor::ProcessSpatialCondition (FdoSpatialCondition& filter)
{
    FdoPtr<FdoByteArray> fgf = m_reader->GetGeometry (
        FdoPtr<FdoIdentifier>(filter.GetPropertyName ())->GetName ());

    //no geometry? trivially false.
    if (fgf->GetCount () == 0)
        m_retvals.push_back (ObtainBooleanValue (false, false));

    FdoPtr<FdoExpression> exprRight = filter.GetGeometry ();
    FdoGeometryValue* gvRight = dynamic_cast<FdoGeometryValue*>(exprRight.p);
    
    if (!gvRight)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_84_SPATIAL_CONDITION_NOT_LITERAL_GEOMETRY)));

    FdoPtr<FdoByteArray> baRight = gvRight->GetGeometry ();

    FdoPtr<FdoFgfGeometryFactory> gf = FdoFgfGeometryFactory::GetInstance ();
    FdoPtr<FdoIGeometry> geomRight = gf->CreateGeometryFromFgf (baRight);
    FdoPtr<FdoIGeometry> geomLeft = gf->CreateGeometryFromFgf (fgf);

    //call on the geometry utility to evaluate the spatial operation
    bool ret = FdoSpatialUtility::Evaluate (geomLeft, filter.GetOperation (), geomRight);
    
    m_retvals.push_back (ObtainBooleanValue (false, ret));            
}

void FdoCommonFilterExecutor::ProcessDistanceCondition (FdoDistanceCondition& filter)
{
    //TODO:
    printf ("distance condition on %ls\n", filter.GetPropertyName ());
    throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_85_DISTANCE_SPATIAL_CONDITION_NOT_SUPPORTED)));
}


void FdoCommonFilterExecutor::ProcessBinaryExpression (FdoBinaryExpression& expr)
{
    FdoPtr<FdoExpression> left = expr.GetLeftExpression ();
    FdoPtr<FdoExpression> right = expr.GetRightExpression ();

    right->Process (this);
    left->Process (this);

    //get Process() results from return value stack
    FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();
    FdoDataValue* argRight = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    switch (expr.GetOperation ())
    {
        case FdoBinaryOperations_Add: 
            m_retvals.push_back (Add (argLeft, argRight));
            break;
        case FdoBinaryOperations_Multiply: 
            m_retvals.push_back (Multiply (argLeft, argRight));
            break;
        case FdoBinaryOperations_Subtract: 
            m_retvals.push_back (Subtract (argLeft, argRight));
            break;
        case FdoBinaryOperations_Divide: 
            m_retvals.push_back (Divide (argLeft, argRight));
            break;
        default: 
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_86_UNSUPPORTED_BINARY_OPERATION)));
    }

    RelinquishDataValue (argLeft);
    RelinquishDataValue (argRight);
}

void FdoCommonFilterExecutor::ProcessUnaryExpression (FdoUnaryExpression& expr)
{
    FdoPtr<FdoExpression> right = expr.GetExpression ();

    right->Process (this);

    FdoDataValue* argRight = (FdoDataValue*)m_retvals.back ();
    m_retvals.pop_back ();

    switch (expr.GetOperation ())
    {
        case FdoUnaryOperations_Negate:
            m_retvals.push_back (Negate (argRight));
            break;
        default:
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_87_UNSUPPORTED_UNARY_OPERATION)));
    }

    RelinquishDataValue (argRight);
}

void FdoCommonFilterExecutor::ProcessFunction (FdoFunction& expr)
{
    FdoString* name = expr.GetName ();

    if (wcscmp (name, FDO_FUNCTION_CONCAT) == 0)
    {
        FdoPtr<FdoExpressionCollection> args = expr.GetArguments ();

        if (args->GetCount () != 2)
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_75_INVALID_NUM_ARGUMENTS), expr.GetName(), 2, args->GetCount()));

        FdoPtr<FdoExpression> left = args->GetItem (0);
        left->Process (this);

        FdoPtr<FdoExpression> right = args->GetItem (1);
        right->Process (this);

        FdoDataValue* argRight = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

        FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

        if (FdoDataType_String != argLeft->GetDataType ())
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_88_INVALID_FUNCTION_ARG_TYPE), 1, name, FdoCommonMiscUtil::FdoDataTypeToString(argLeft->GetDataType()), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_String)));
        if (FdoDataType_String != argRight->GetDataType ())
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_88_INVALID_FUNCTION_ARG_TYPE), 2, name, FdoCommonMiscUtil::FdoDataTypeToString(argRight->GetDataType()), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_String)));

        if (argLeft->IsNull() && argRight->IsNull())
            m_retvals.push_back (ObtainStringValue (true, NULL));
        else if (argLeft->IsNull())
            m_retvals.push_back (ObtainStringValue (false, ((FdoStringValue*)argRight)->GetString ()));
        else if (argRight->IsNull())
            m_retvals.push_back (ObtainStringValue (false, ((FdoStringValue*)argLeft)->GetString ()));
        else
        {
            FdoString* prefix = ((FdoStringValue*)argLeft)->GetString ();
            FdoString* suffix = ((FdoStringValue*)argRight)->GetString ();
            size_t len = wcslen (prefix) + wcslen (suffix) + 1;
            wchar_t* res = (wchar_t*)alloca (sizeof (wchar_t) * len);
            wcscpy (res, prefix);
            wcscat (res, suffix);
            m_retvals.push_back (ObtainStringValue (false, res));
        }

        RelinquishDataValue (argLeft);
        RelinquishDataValue (argRight);
    }
    else if (wcscmp (name, FDO_FUNCTION_CEIL) == 0 || wcscmp (name, FDO_FUNCTION_FLOOR) == 0)
    {
        FdoPtr<FdoExpressionCollection> args = expr.GetArguments ();

        if (args->GetCount () != 1)
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_75_INVALID_NUM_ARGUMENTS), expr.GetName(), 1, args->GetCount()));

        FdoPtr<FdoExpression> left = args->GetItem (0);
        left->Process (this);

        FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

		ProcessFunctionCeilFloor( name, argLeft );

        RelinquishDataValue (argLeft);
    }
    else if (wcscmp (name, FDO_FUNCTION_LOWER) == 0)
    {
        FdoPtr<FdoExpressionCollection> args = expr.GetArguments ();

        if (args->GetCount () != 1)
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_75_INVALID_NUM_ARGUMENTS), expr.GetName(), 1, args->GetCount()));

        FdoPtr<FdoExpression> left = args->GetItem (0);
        left->Process (this);

        FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

        if (FdoDataType_String != argLeft->GetDataType ())
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_88_INVALID_FUNCTION_ARG_TYPE), 1, name, FdoCommonMiscUtil::FdoDataTypeToString(argLeft->GetDataType()), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_String)));

        if (argLeft->IsNull())
            m_retvals.push_back (ObtainStringValue (true, NULL));
        else
        {
            FdoString* arg = ((FdoStringValue*)argLeft)->GetString ();
            size_t len = wcslen (arg) + 1;
            wchar_t* res = (wchar_t*)alloca (sizeof (wchar_t) * len);
            wcscpy (res, arg);
            for (size_t i = 0; i < len; i++)
                res[i] = towlower (res[i]);
            m_retvals.push_back (ObtainStringValue (false, res));
        }

        RelinquishDataValue (argLeft);
    }
    else if (wcscmp (name, FDO_FUNCTION_UPPER) == 0)
    {
        FdoPtr<FdoExpressionCollection> args = expr.GetArguments ();

        if (args->GetCount () != 1)
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_75_INVALID_NUM_ARGUMENTS), expr.GetName(), 1, args->GetCount()));

        FdoPtr<FdoExpression> left = args->GetItem (0);
        left->Process (this);

        FdoDataValue* argLeft = (FdoDataValue*)m_retvals.back ();
        m_retvals.pop_back ();

        if (FdoDataType_String != argLeft->GetDataType ())
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_88_INVALID_FUNCTION_ARG_TYPE), 1, name, FdoCommonMiscUtil::FdoDataTypeToString(argLeft->GetDataType()), FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_String)));

        if (argLeft->IsNull())
            m_retvals.push_back (ObtainStringValue (true, NULL));
        else
        {
            FdoString* arg = ((FdoStringValue*)argLeft)->GetString ();
            size_t len = wcslen (arg) + 1;
            wchar_t* res = (wchar_t*)alloca (sizeof (wchar_t) * len);
            wcscpy (res, arg);
            for (size_t i = 0; i < len; i++)
                res[i] = towupper (res[i]);
            m_retvals.push_back (ObtainStringValue (false, res));
        }

        RelinquishDataValue (argLeft);
    }
    else
    {
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_89_UNSUPPORTED_FUNCTION), name));
    }
}

void FdoCommonFilterExecutor::ProcessFunctionCeilFloor( FdoString *name, FdoDataValue* argLeft )
{
    FdoDataType		type = argLeft->GetDataType ();

    if ((FdoDataType_Double != type) && (FdoDataType_Single != type) && (FdoDataType_Decimal != type) &&
	    (FdoDataType_Int32 != type) && (FdoDataType_Int16 != type) )
	{
		FdoStringP	allowedTypes =	FdoStringP(FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Double))  + L" / " +
									FdoStringP(FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Single))  + L" / " +
									FdoStringP(FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Decimal)) + L" / " +
									FdoStringP(FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Int32))   + L" / " +
									FdoStringP(FdoCommonMiscUtil::FdoDataTypeToString(FdoDataType_Int16));

		throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_88_INVALID_FUNCTION_ARG_TYPE), 1, name, 
																FdoCommonMiscUtil::FdoDataTypeToString(type), 
	  														    (FdoString *)allowedTypes));
	}
	else
	{
		if (argLeft->IsNull())
            m_retvals.push_back (ObtainDoubleValue (true, 0));
        else
        {
            double d = 0.0;

            if (FdoDataType_Double == type || FdoDataType_Decimal == type)
                d = ((FdoDoubleValue*)argLeft)->GetDouble ();
            else if ( FdoDataType_Single == type ) 
                d = ((FdoSingleValue*)argLeft)->GetSingle ();
			else if ( FdoDataType_Int32 == type ) 
				d = ((FdoInt32Value*)argLeft)->GetInt32();
			else if ( FdoDataType_Int16 == type ) 
				d = ((FdoInt16Value*)argLeft)->GetInt16();

			d = ( wcscmp (name, FDO_FUNCTION_CEIL) == 0) ? ceil (d) : floor (d);

            m_retvals.push_back (ObtainDoubleValue (false, d));
        }
	}
}

void FdoCommonFilterExecutor::ProcessIdentifier (FdoIdentifier& expr)
{
    ProcessIdentifier (expr.GetName ());
}

void FdoCommonFilterExecutor::ProcessComputedIdentifier (FdoComputedIdentifier& expr)
{
    //Computed identifiers:
    //Just evaluate the expression that the computed identifier represents.

    FdoPtr<FdoExpression> theexpr = expr.GetExpression ();
    theexpr->Process (this);
}


void FdoCommonFilterExecutor::ProcessIdentifier (FdoString* name)
{
    FdoPtr<FdoPropertyDefinition> definition = GetPropInfo (name);

    if (definition != NULL)
    {
        if (FdoPropertyType_DataProperty == definition->GetPropertyType ())
        {
            FdoDataType type = ((FdoDataPropertyDefinition*)definition.p)->GetDataType ();
            bool bIsNull = (m_reader->IsNull(name));
            switch (type)
            {
            case FdoDataType_Boolean : 
                m_retvals.push_back (ObtainBooleanValue (bIsNull, bIsNull ? false : m_reader->GetBoolean (name))); 
                break;
            case FdoDataType_Byte : 
                m_retvals.push_back (ObtainByteValue (bIsNull, bIsNull ? 0 : m_reader->GetByte (name))); 
                break;
            case FdoDataType_DateTime : 
                m_retvals.push_back (ObtainDateTimeValue (bIsNull, bIsNull ? FdoDateTime() : m_reader->GetDateTime (name))); 
                break;
            case FdoDataType_Decimal : 
                m_retvals.push_back (ObtainDecimalValue (bIsNull, bIsNull ? 0.0 : m_reader->GetDouble (name))); 
                break;
            case FdoDataType_Double : 
                m_retvals.push_back (ObtainDoubleValue (bIsNull, bIsNull ? 0.0 : m_reader->GetDouble (name))); 
                break;
            case FdoDataType_Int16 : 
                m_retvals.push_back (ObtainInt16Value (bIsNull, bIsNull ? 0 : m_reader->GetInt16 (name))); 
                break;
            case FdoDataType_Int32 : 
                m_retvals.push_back (ObtainInt32Value (bIsNull, bIsNull ? 0 : m_reader->GetInt32 (name))); 
                break;
            case FdoDataType_Int64 : 
                m_retvals.push_back (ObtainInt64Value (bIsNull, bIsNull ? 0 : m_reader->GetInt64 (name))); 
                break;
            case FdoDataType_Single : 
                m_retvals.push_back (ObtainSingleValue (bIsNull, bIsNull ? 0.0f : m_reader->GetSingle (name))); 
                break;
            case FdoDataType_String : 
                m_retvals.push_back (ObtainStringValue (bIsNull, bIsNull ? NULL : m_reader->GetString (name))); 
                break;
            case FdoDataType_BLOB : 
                m_retvals.push_back (ObtainBLOBValue (bIsNull, bIsNull ? NULL : m_reader->GetLOB (name)->GetData ())); 
                break;
            case FdoDataType_CLOB : 
                m_retvals.push_back (ObtainCLOBValue (bIsNull, bIsNull ? NULL : m_reader->GetLOB (name)->GetData ())); 
                break;
            default:
                throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_71_DATA_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoDataTypeToString(type)));
            }
        }
        else if (FdoPropertyType_GeometricProperty == definition->GetPropertyType ())
        {
            bool bIsNull = (m_reader->IsNull(name));
            FdoPtr<FdoByteArray> geomBytes = m_reader->GetGeometry(name);
            m_retvals.push_back (ObtainGeometryValue (bIsNull, bIsNull ? NULL : geomBytes.p )); 
        }
        else
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_70_PROPERTY_TYPE_NOT_SUPPORTED), FdoCommonMiscUtil::FdoPropertyTypeToString(definition->GetPropertyType())));
    }
    else
    {
        //if user tried to use a computed identifier in an expression
        //we need some special handling
        FdoPtr<FdoComputedIdentifier> cid;
        if (m_compIdents) {
            cid = dynamic_cast<FdoComputedIdentifier*>(m_compIdents->GetItem (name));
        }
        
        if (cid==NULL)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_81_IDENTIFIER_NOT_FOUND), name));
        
        cid->Process (this);
    }
}

void FdoCommonFilterExecutor::ProcessParameter (FdoParameter& expr)
{
    printf ("parameter %ls", expr.GetName ());
    throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_68_COMMAND_PARAMETERS_NOT_SUPPORTED)));
}

void FdoCommonFilterExecutor::ProcessBooleanValue (FdoBooleanValue& expr)
{
    m_retvals.push_back (ObtainBooleanValue (expr.IsNull(), expr.IsNull() ? false : expr.GetBoolean ()));
}

void FdoCommonFilterExecutor::ProcessByteValue (FdoByteValue& expr)
{
    m_retvals.push_back (ObtainByteValue (expr.IsNull(), expr.IsNull() ? 0 : expr.GetByte ()));
}

void FdoCommonFilterExecutor::ProcessDateTimeValue (FdoDateTimeValue& expr)
{
    m_retvals.push_back (ObtainDateTimeValue (expr.IsNull(), expr.IsNull() ? FdoDateTime() : expr.GetDateTime ()));
}

void FdoCommonFilterExecutor::ProcessDecimalValue (FdoDecimalValue& expr)
{
    m_retvals.push_back (ObtainDecimalValue (expr.IsNull(), expr.IsNull() ? 0.0 : expr.GetDecimal ()));
}

void FdoCommonFilterExecutor::ProcessDoubleValue (FdoDoubleValue& expr)
{
    m_retvals.push_back (ObtainDoubleValue (expr.IsNull(), expr.IsNull() ? 0.0 : expr.GetDouble ()));
}

void FdoCommonFilterExecutor::ProcessInt16Value (FdoInt16Value& expr)
{
    m_retvals.push_back (ObtainInt16Value (expr.IsNull(), expr.IsNull() ? 0 : expr.GetInt16 ()));
}

void FdoCommonFilterExecutor::ProcessInt32Value (FdoInt32Value& expr)
{
    m_retvals.push_back (ObtainInt32Value (expr.IsNull(), expr.IsNull() ? 0 : expr.GetInt32 ()));
}

void FdoCommonFilterExecutor::ProcessInt64Value (FdoInt64Value& expr)
{
    m_retvals.push_back (ObtainInt64Value (expr.IsNull(), expr.IsNull() ? 0 : expr.GetInt64 ()));
}

void FdoCommonFilterExecutor::ProcessSingleValue (FdoSingleValue& expr)
{
    m_retvals.push_back (ObtainSingleValue (expr.IsNull(), expr.IsNull() ? 0.0f : expr.GetSingle ()));
}

void FdoCommonFilterExecutor::ProcessStringValue (FdoStringValue& expr)
{
    m_retvals.push_back (ObtainStringValue (expr.IsNull(), expr.IsNull() ? NULL : expr.GetString ()));
}

void FdoCommonFilterExecutor::ProcessBLOBValue (FdoBLOBValue& expr)
{
    m_retvals.push_back (ObtainBLOBValue (expr.IsNull(), expr.IsNull() ? NULL : expr.GetData ()));
}

void FdoCommonFilterExecutor::ProcessCLOBValue (FdoCLOBValue& expr)
{
    m_retvals.push_back (ObtainCLOBValue (expr.IsNull(), expr.IsNull() ? NULL : expr.GetData ()));
}

void FdoCommonFilterExecutor::ProcessGeometryValue (FdoGeometryValue& expr)
{
    FdoPtr<FdoByteArray> geomBytes = expr.GetGeometry();
    m_retvals.push_back (ObtainGeometryValue (expr.IsNull(), expr.IsNull() ? NULL : geomBytes.p ));
}


//Matches strings according to the rules of the LIKE condition
// Wildcard characters supported in the pattern are:
//
// %    Any string of zero or more characters
// _    Any single character
// []   Any single character within the specified range ([a-f]) or set 
// ([abcdef]).
// [^]  Any single character not within the specified range ([^a-f]) or 
// set ([^abcdef]).
bool FdoCommonFilterExecutor::MatchesHere (const wchar_t* pattern, const wchar_t* src)
{
    bool bMatches = false;

    if (*pattern == L'\0')
    {
        if (wcslen (src))
        {
            bMatches = false;
        }
        else
        {
            bMatches = true;
        }
    }
    else if (*pattern == L'%')
    {
        bMatches = MatchPercent (pattern+1, src);
    }
    else if (*pattern == L'[')
    {
        bMatches = MatchBracket (pattern+1, src);
    }
    else if (*src != L'\0' && ((*pattern == L'_') ||  FdoCommonOSUtil::wcsnicmp (pattern, src, 1) == 0))
    {
        bMatches = MatchesHere (pattern+1, src+1);
    }

    return bMatches;
}

// %    Any string of zero or more characters
bool FdoCommonFilterExecutor::MatchPercent (const  wchar_t* pattern, const wchar_t* src)
{
    bool bMatches = false;
    
    while (!bMatches)
    {
        if (MatchesHere (pattern, src))
        {
            bMatches = true;
            break;
        }
        else if (*src == L'\0')
        {
            break;
        }
        src++;
    }

    return bMatches;
}

// []   Any single character within the specified range ([a-f]) or set 
// ([abcdef]).
// [^]  Any single character not within the specified range ([^a-f]) or 
// set ([^abcdef]).
bool FdoCommonFilterExecutor::MatchBracket (const wchar_t* pattern, const wchar_t* src)
{
    bool bMatches = false;
    bool reverse = false;

    //invalid case, unclosed bracket
    if (*pattern == L'\0')
        bMatches = false;

    if (*pattern == L'^')
    {
        reverse = true;
        pattern++;
    }

    //case of [] -- not a useful case
    if (*pattern == L']')
    {
        if (*src == L'\0')
            bMatches = true;

        if (reverse)
            bMatches = MatchesHere (pattern+1, src+1);

        bMatches = false;
    }

    wchar_t start = *pattern++;

    //case of [a-b] or [^a-b]
    if (*pattern == L'-')
    {
        //go past - character and get range end character and go past range end character
        pattern++;
        wchar_t end = *pattern++;

        if ((*src >= start && *src <= end) ^ reverse)
        {
            bMatches = MatchesHere (pattern+1, src+1);
        }
        else
            bMatches = false;
    }

    //case of [abcdef] ot [^abcdef]
    std::vector<wchar_t> set;
    set.push_back (start);

    do 
    {
        set.push_back (*pattern++);
    }
    while (*pattern != L']');

    wchar_t srcchar = *src;
    bool isthere = false;

    //look for current character in the set
    for (unsigned i=0; i<set.size (); i++)
    {
        wchar_t current = set[i];
        if (FdoCommonOSUtil::wcsnicmp (&current, &srcchar, 1) == 0)
        {
            isthere = true;
            break;
        }
    }

    if (isthere ^ reverse)
        bMatches = MatchesHere (pattern+1, src+1);
    else
        bMatches = false;


    return bMatches;
}


bool FdoCommonFilterExecutor::Like (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    if (FdoDataType_String != argLeft->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    if (FdoDataType_String != argRight->GetDataType ())
        throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));

    return (MatchesHere (((FdoStringValue*)argRight)->GetString (), ((FdoStringValue*)argLeft)->GetString ()));
}

bool FdoCommonFilterExecutor::IsEqualTo (FdoDataValue* argLeft, FdoDataValue* argRight)
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

bool FdoCommonFilterExecutor::IsLessThan (FdoDataValue* argLeft, FdoDataValue* argRight)
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

bool FdoCommonFilterExecutor::IsGreaterThan (FdoDataValue* argLeft, FdoDataValue* argRight)
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

FdoDataValue* FdoCommonFilterExecutor::Add (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    FdoDataValue* ret;

    bool bRetNull = (argLeft->IsNull() || argRight->IsNull());

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
                    ret = ObtainByteValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () + ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () + ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () + ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () + ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () + ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () + ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () + ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    return (ret);
}

FdoDataValue* FdoCommonFilterExecutor::Subtract (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    FdoDataValue* ret;

    bool bRetNull = (argLeft->IsNull() || argRight->IsNull());

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
                    ret = ObtainByteValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () - ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () - ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () - ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () - ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () - ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () - ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () - ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    // Handle NULL values  (use a coding shortcut):
    if (argLeft->IsNull() || argRight->IsNull())
        ret->SetNull();

    return (ret);
}

FdoDataValue* FdoCommonFilterExecutor::Multiply (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    FdoDataValue* ret;

    bool bRetNull = (argLeft->IsNull() || argRight->IsNull());

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
                    ret = ObtainByteValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () * ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () * ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () * ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () * ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () * ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () * ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () * ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    // Handle NULL values  (use a coding shortcut):
    if (argLeft->IsNull() || argRight->IsNull())
        ret->SetNull();

    return (ret);
}

FdoDataValue* FdoCommonFilterExecutor::Divide (FdoDataValue* argLeft, FdoDataValue* argRight)
{
    FdoDataValue* ret;

    bool bRetNull = (argLeft->IsNull() || argRight->IsNull());

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
                    ret = ObtainByteValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoByteValue*)argLeft)->GetByte () / ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_DateTime:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
        case FdoDataType_Decimal:
            switch (argRight->GetDataType ())
            {
                case FdoDataType_Boolean:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Byte:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoDecimalValue*)argLeft)->GetDecimal () / ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoDoubleValue*)argLeft)->GetDouble () / ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt16Value*)argLeft)->GetInt16 () / ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt32Value*)argLeft)->GetInt32 () / ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoInt64Value*)argLeft)->GetInt64 () / ((FdoSingleValue*)argRight)->GetSingle ());
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
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoByteValue*)argRight)->GetByte ());
                    break;
                case FdoDataType_DateTime:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
                case FdoDataType_Decimal:
                    ret = ObtainDecimalValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoDecimalValue*)argRight)->GetDecimal ());
                    break;
                case FdoDataType_Double:
                    ret = ObtainDoubleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoDoubleValue*)argRight)->GetDouble ());
                    break;
                case FdoDataType_Int16:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoInt16Value*)argRight)->GetInt16 ());
                    break;
                case FdoDataType_Int32:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoInt32Value*)argRight)->GetInt32 ());
                    break;
                case FdoDataType_Int64:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoInt64Value*)argRight)->GetInt64 ());
                    break;
                case FdoDataType_Single:
                    ret = ObtainSingleValue (bRetNull, bRetNull ? 0 : ((FdoSingleValue*)argLeft)->GetSingle () / ((FdoSingleValue*)argRight)->GetSingle ());
                    break;
                case FdoDataType_String:
                case FdoDataType_BLOB:
                case FdoDataType_CLOB:
                default:
                    throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            }
            break;
        case FdoDataType_String:
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    // Handle NULL values  (use a coding shortcut):
    if (argLeft->IsNull() || argRight->IsNull())
        ret->SetNull();

    return (ret);
}

FdoDataValue* FdoCommonFilterExecutor::Negate (FdoDataValue* argLeft)
{
    FdoDataValue* ret;

    bool bRetNull = argLeft->IsNull();

    switch (argLeft->GetDataType ())
    {
        case FdoDataType_Boolean:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
            break;
        case FdoDataType_Byte:
            ret = ObtainByteValue (bRetNull, bRetNull ? 0 : -((FdoByteValue*)argLeft)->GetByte ());
            break;
        case FdoDataType_DateTime:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
        case FdoDataType_Decimal:
            ret = ObtainDecimalValue (bRetNull, bRetNull ? 0.0 : -((FdoDecimalValue*)argLeft)->GetDecimal ());
            break;
        case FdoDataType_Double:
            ret = ObtainDoubleValue (bRetNull, bRetNull ? 0.0 : -((FdoDoubleValue*)argLeft)->GetDouble ());
            break;
        case FdoDataType_Int16:
            ret = ObtainInt16Value (bRetNull, bRetNull ? 0 : -((FdoInt16Value*)argLeft)->GetInt16 ());
            break;
        case FdoDataType_Int32:
            ret = ObtainInt32Value (bRetNull, bRetNull ? 0 : -((FdoInt32Value*)argLeft)->GetInt32 ());
            break;
        case FdoDataType_Int64:
            ret = ObtainInt64Value (bRetNull, bRetNull ? 0 : -((FdoInt64Value*)argLeft)->GetInt64 ());
            break;
        case FdoDataType_Single:
            ret = ObtainSingleValue (bRetNull, bRetNull ? 0.0f : -((FdoSingleValue*)argLeft)->GetSingle ());
            break;
        case FdoDataType_String:
        case FdoDataType_BLOB:
        case FdoDataType_CLOB:
        default:
            throw FdoException::Create (FdoException::NLSGetMessage (FDO_NLSID (FDO_62_PROPERTYVALUEFETCHTYPEMISMATCH)));
    }

    return (ret);
}


void FdoCommonFilterExecutor::GetExpressionType(FdoIConnection* conn, FdoClassDefinition* originalClassDef, FdoExpression *expr, FdoPropertyType &retPropType, FdoDataType &retDataType)
{
    VALIDATE_ARGUMENT(conn);
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
        GetExpressionType(conn, originalClassDef, FdoPtr<FdoExpression>(unaryExpr->GetExpression()), retPropType, retDataType);

    FdoBinaryExpression* binaryExpr = dynamic_cast<FdoBinaryExpression*>(expr);
    if (NULL != binaryExpr)
    {
        FdoPropertyType leftPropType, rightPropType;
        FdoDataType leftDataType, rightDataType;
        GetExpressionType(conn, originalClassDef, FdoPtr<FdoExpression>(binaryExpr->GetLeftExpression()), leftPropType, leftDataType);
        GetExpressionType(conn, originalClassDef, FdoPtr<FdoExpression>(binaryExpr->GetRightExpression()), rightPropType, rightDataType);
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
        GetExpressionType(conn, originalClassDef, FdoPtr<FdoExpression>(computedId->GetExpression()), retPropType, retDataType);
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
            GetExpressionType(conn, originalClassDef, arg, argPropType[i], argDataType[i]);
        }

        // Match them up to the correct function signature:
        FdoPtr<FdoIExpressionCapabilities> exprCapabilities = conn->GetExpressionCapabilities();
        FdoPtr<FdoFunctionDefinitionCollection> functionDefinitions = exprCapabilities->GetFunctions();
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

void FdoCommonFilterExecutor::ValidateFilter( FdoClassDefinition *cls, FdoFilter *filter, 
											  FdoIdentifierCollection *selIds,
											  FdoIFilterCapabilities *filterCapabilities )
{
    class FdoCommonFilterValidator : public virtual FdoIExpressionProcessor, public virtual FdoIFilterProcessor
    {
    private:
        FdoClassDefinition* m_class;
		FdoIdentifierCollection *m_selectedIds;
		FdoIFilterCapabilities	*m_filterCapabilities;

    protected:

        void HandleExpr( FdoExpression *exp )
        {
            exp->Process( this );
        }
        void HandleFilter( FdoFilter *filter )
        {
            filter->Process( this );
        }
    public:

        FdoCommonFilterValidator( FdoClassDefinition *cls, FdoIdentifierCollection *selIds, FdoIFilterCapabilities *filterCapabilities )
        {
            m_class = cls;
			m_selectedIds = selIds;
			m_filterCapabilities = filterCapabilities;
        }

        virtual void Dispose() { delete this; }

         /// <summary>Increase the reference count.</summary>
        /// <returns>Returns the new reference count (value for debugging use only).</returns>
        FdoInt32 AddRef()
        {
            // NOTE: due to multiple inheritance, there is an ambiguity in which AddRef() method to call.
            //  Calling BOTH AddRef() methods leads to instances of this class being prematurely released.
            return FdoIFilterProcessor::AddRef();
        }

        /// <summary>Decrease the reference count.</summary>
        /// <returns>Returns the new reference count (value for debugging use only).</returns>
        FdoInt32 Release ()
        {
            // NOTE: due to multiple inheritance, there is an ambiguity in which Release() method to call.
            //  Calling BOTH Release() methods leads to instances of this class being prematurely released.
            return FdoIFilterProcessor::Release();
        }

        virtual void ProcessBinaryExpression(FdoBinaryExpression& expr)
        {
            HandleExpr( FdoPtr<FdoExpression>(expr.GetLeftExpression()) );
            HandleExpr( FdoPtr<FdoExpression>(expr.GetRightExpression()) );
        }

// Supress warnings C4100: 'expr' : unreferenced formal parameter
#pragma warning( disable : 4100 )
        virtual void ProcessBooleanValue(FdoBooleanValue& expr) {  }
        virtual void ProcessByteValue(FdoByteValue& expr){   }
        virtual void ProcessDateTimeValue(FdoDateTimeValue& expr){   }
        virtual void ProcessDoubleValue(FdoDoubleValue& expr){   }
        virtual void ProcessDecimalValue(FdoDecimalValue& expr){   }
        virtual void ProcessInt16Value(FdoInt16Value& expr){  }
        virtual void ProcessInt32Value(FdoInt32Value& expr){  }
        virtual void ProcessInt64Value(FdoInt64Value& expr){  }
        virtual void ProcessSingleValue(FdoSingleValue& expr){  }
        virtual void ProcessStringValue(FdoStringValue& expr){  }
        virtual void ProcessBLOBValue(FdoBLOBValue& expr){   }
        virtual void ProcessCLOBValue(FdoCLOBValue& expr){  }
        virtual void ProcessFunction(FdoFunction& expr)
        {
            FdoPtr<FdoExpressionCollection>col = expr.GetArguments();
            for(int i=0; i<col->GetCount(); i++)
                HandleExpr( FdoPtr<FdoExpression>(col->GetItem( i ) ) );
        }
        virtual void ProcessGeometryValue(FdoGeometryValue& expr){  }
        virtual void ProcessParameter(FdoParameter& expr){  }
        virtual void ProcessUnaryExpression(FdoUnaryExpression& expr)
        {
            HandleExpr( FdoPtr<FdoExpression>(expr.GetExpression()) );
        }
        virtual void ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& filter)
        {
            HandleFilter( FdoPtr<FdoFilter>(filter.GetLeftOperand()) );
            HandleFilter( FdoPtr<FdoFilter>(filter.GetRightOperand()) );
        }
        virtual void ProcessComparisonCondition(FdoComparisonCondition& filter)
        {
            HandleExpr( FdoPtr<FdoExpression>(filter.GetLeftExpression()) );
            HandleExpr( FdoPtr<FdoExpression>(filter.GetRightExpression()) );
        }
        virtual void ProcessDistanceCondition(FdoDistanceCondition& filter){  }

        virtual void ProcessInCondition(FdoInCondition& filter)
        {
            ProcessIdentifier( *(FdoPtr<FdoIdentifier>(filter.GetPropertyName())) );
        }
        virtual void ProcessNullCondition(FdoNullCondition& filter)
        {
            ProcessIdentifier( *(FdoPtr<FdoIdentifier>(filter.GetPropertyName())) );
        }
        virtual void ProcessSpatialCondition(FdoSpatialCondition& filter)
		{  
			FdoSpatialOperations	op = filter.GetOperation();
			bool					found = false;
			int						numSpatialOps;

			FdoSpatialOperations	*supportedSpatialOps = m_filterCapabilities->GetSpatialOperations( numSpatialOps );

			for ( int i =0; i < numSpatialOps && !found; i++ )
			{
				found = ( op == supportedSpatialOps[i] );
			}
			if ( !found )
				throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_105_UNSUPPORTED_SPATIAL_OPERATION)));
		}

        virtual void ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& filter)
        {
            HandleFilter( FdoPtr<FdoFilter>(filter.GetOperand()) );
        }

        virtual void ProcessIdentifier(FdoIdentifier& expr)
        {
			// Return in case ids validation not required.
			if ( m_class == NULL )
				return;

             // This is used to validate the property names referenced in the filter.
            FdoPtr<FdoPropertyDefinitionCollection> props = m_class->GetProperties();
            FdoPtr<FdoReadOnlyPropertyDefinitionCollection> baseProps = m_class->GetBaseProperties();
            FdoPtr<FdoPropertyDefinition> prop;

            int length;
            // If any of the identifiers is a decorated name of the form <obj proper>.<property>, then this is
            // an association or object proeperty; assume it exist for now.
            if( expr.GetScope( length ) && length > 0 )
                return;

			// Check properties
            prop = props->FindItem( expr.GetName() );
			bool	found = ( prop != NULL );

            if( !found )
			{
				// Check base properties
				try
				{
					prop = baseProps->GetItem( expr.GetName() );
					found = true;
				}
				catch(FdoException *exp )
				{
					exp->Release();
				}

				// Check computed identifiers
				if( !found && m_selectedIds )
				{
					FdoPtr<FdoIdentifier>	id = m_selectedIds->FindItem( expr.GetName() );
					found = ( id != NULL );
				}
			}

			if ( !found )
				throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_81_IDENTIFIER_NOT_FOUND), expr.GetName()));
        }

        virtual void ProcessComputedIdentifier(FdoComputedIdentifier& expr)
        {
            HandleExpr( FdoPtr<FdoExpression>(expr.GetExpression()) );
        }
    };

    FdoCommonFilterValidator  validator(cls, selIds, filterCapabilities);
    filter->Process( &validator ); 
}

FdoFilter* FdoCommonFilterExecutor::OptimizeFilter( FdoFilter *filter )
{
	// This is mostly a place holder for potential filter optimization

	// For now we just reduce a simple case with potentiel significant performance improvement
	// This is the case where a filter has 2 and'ed spatial conditions that can be reduced to a 
	// single spatial condition.
 class FdoCommonFilterOptimizer :  public virtual FdoIFilterProcessor
    {
    private:
        FdoPtr<FdoFilter>	 m_newFilter;
		bool				 m_isOptimized;
		FdoPtr<FdoIGeometry> m_geomRight;
		FdoPtr<FdoIGeometry> m_geomLeft;

    protected:
        void HandleFilter( FdoFilter *filter )
        {
            filter->Process( this );
        }
    public:

		FdoCommonFilterOptimizer( ): m_isOptimized(false)
        {
        }

		bool IsOptimized() { return m_isOptimized; }

		FdoFilter* OptimizedFilter() { return FDO_SAFE_ADDREF(m_newFilter.p); }

        virtual void Dispose() { delete this; }
       
        virtual void ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& filter)
        {
			if( filter.GetOperation() != FdoBinaryLogicalOperations_And )
			{
				m_isOptimized = false;
				return;
			}
            HandleFilter( FdoPtr<FdoFilter>(filter.GetLeftOperand()) );
            HandleFilter( FdoPtr<FdoFilter>(filter.GetRightOperand()) );
        }
        virtual void ProcessComparisonCondition(FdoComparisonCondition& filter)
        {
            m_isOptimized = false;
			return;
        }
        virtual void ProcessDistanceCondition(FdoDistanceCondition& filter)
		{  
			m_isOptimized = false;
			return;
		}

        virtual void ProcessInCondition(FdoInCondition& filter)
        {
			m_isOptimized = false;
			return;
        }
        virtual void ProcessNullCondition(FdoNullCondition& filter)
        {
            m_isOptimized = false;
			return;
        }
        virtual void ProcessSpatialCondition(FdoSpatialCondition& filter)
		{  
			bool isleft = ( m_geomLeft == NULL );
			
			FdoPtr<FdoExpression> exprRight = filter.GetGeometry ();
			FdoGeometryValue* gv = dynamic_cast<FdoGeometryValue*>(exprRight.p);
			if (!gv)
			{
				m_isOptimized = false;
				return;
			}

			if( filter.GetOperation() == FdoSpatialOperations_Disjoint )
			{
				m_isOptimized = false;
				return;
			}

			FdoPtr<FdoByteArray> ba = gv->GetGeometry ();
			FdoPtr<FdoFgfGeometryFactory> gf = FdoFgfGeometryFactory::GetInstance ();
			if( isleft )
			{
				m_geomLeft = gf->CreateGeometryFromFgf (ba);
				m_newFilter = FDO_SAFE_ADDREF(&filter);
			}
			else
			{
				m_geomRight = gf->CreateGeometryFromFgf (ba);

			
				bool ret = FdoSpatialUtility::Evaluate (m_geomLeft, FdoSpatialOperations_Inside, m_geomRight);
				if( ret )
				{
					m_isOptimized = true;
					return;
				}
				ret = FdoSpatialUtility::Evaluate (m_geomRight, FdoSpatialOperations_Inside, m_geomLeft );
				if( ret )
				{
					m_isOptimized = true;
					m_newFilter = FDO_SAFE_ADDREF(&filter);
					return;
				}
				ret = FdoSpatialUtility::Evaluate (m_geomRight, FdoSpatialOperations_Disjoint, m_geomLeft );
				if( ret )
				{
					// If the condition do not overlap, then replace it with a filter that returns 0 features.
#ifdef _WIN32
					double small_dbl  =(double)(-9223372036854775807i64 - 1);
#else
					double small_dbl  =(double)(-9223372036854775807LL - 1);
#endif
					m_isOptimized = true;
					FdoPtr<FdoFgfGeometryFactory> gf = FdoFgfGeometryFactory::GetInstance();

					double coords[] = { small_dbl, small_dbl, 
										small_dbl, small_dbl, 
										small_dbl, small_dbl, 
										small_dbl, small_dbl, 
										small_dbl, small_dbl }; 

					FdoPtr<FdoILinearRing> outer = gf->CreateLinearRing(0, 10, coords);

					FdoPtr<FdoIPolygon> poly = gf->CreatePolygon(outer, NULL);

					FdoPtr<FdoByteArray> polyfgf = gf->GetFgf(poly);
					FdoPtr<FdoGeometryValue> gv = FdoGeometryValue::Create(polyfgf);
					m_newFilter = FdoSpatialCondition::Create(FdoPtr<FdoIdentifier>(filter.GetPropertyName())->GetName(), FdoSpatialOperations_EnvelopeIntersects, gv);
					return;
				}

				// Otherwise we make sure that the condition with the FdoSpatialOperations_EnvelopeIntersects is the left condition
				if( filter.GetOperation() == FdoSpatialOperations_EnvelopeIntersects )
				{
					// Let's re-arrage the filter to favor evaluating the envelope intersect first.
					m_newFilter = FdoFilter::Combine( &filter  , FdoBinaryLogicalOperations_And,  m_newFilter );
					m_isOptimized = true;
					return;
				}
			}
		}

        virtual void ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& filter)
        {
            m_isOptimized = false;
			return;
        }
    };

    FdoCommonFilterOptimizer  optimizer;
    filter->Process( &optimizer ); 

	return optimizer.IsOptimized()?optimizer.OptimizedFilter():FDO_SAFE_ADDREF(filter);
}

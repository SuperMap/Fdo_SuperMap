/*
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
 */

#ifndef _FDOCOMMONEXPRESSIONEXECUTOR_H_
#define _FDOCOMMONEXPRESSIONEXECUTOR_H_

#ifdef _WIN32
#pragma once
#endif

#include "FdoCommonOSUtil.h"

/// \brief
/// validate extended usage of functions
class FdoCommonExpressionExecutor : public FdoDisposable
{
protected:
	FdoCommonExpressionExecutor() {};
    FdoCommonExpressionExecutor(FdoFeatureSchemaCollection* schColl, FdoIdentifier* className)
    {
        m_UnknownTypeFound = false;
        FdoInt32 cnt = 0;
        FdoStringP Name;
        FdoString** ptrNames = className->GetScope(cnt);
        if (cnt == 0)
            Name = className->GetName();
        else
            Name = *ptrNames;

        FdoStringP schName = className->GetSchemaName();
        if (schName.GetLength())
        {
            FdoPtr<FdoFeatureSchema> schema = schColl->GetItem(schName);
            m_classes = schema->GetClasses();
            m_actClass = m_classes->FindItem(Name);
        }
        else
        {
            for(int i = 0; i < schColl->GetCount(); i++)
            {
                FdoPtr<FdoFeatureSchema> schema = schColl->GetItem(i);
                m_classes = schema->GetClasses();
                m_actClass = m_classes->FindItem(Name);
                if (m_actClass == NULL)
                    m_classes = NULL;
                else
                    break;
            }
        }
    }

    FdoDataType GetObjectType(FdoStringP objectName, FdoClassDefinition* classDef)
    {
        if (classDef != NULL)
        {
            FdoPtr<FdoPropertyDefinitionCollection> defColl = classDef->GetProperties();
            if(!objectName.Contains(L"."))
            {
                FdoPtr<FdoPropertyDefinition> propDef = defColl->FindItem(objectName);
                if (propDef == NULL)
                {
                    FdoPtr<FdoClassDefinition> baseClassDef = classDef->GetBaseClass();
                    while(baseClassDef != NULL)
                    {
                        defColl = baseClassDef->GetProperties();
                        propDef = defColl->FindItem(objectName);
                        if (propDef != NULL)
                            break;
                        baseClassDef = baseClassDef->GetBaseClass();
                    }
                }
                if (propDef != NULL && propDef->GetPropertyType() == FdoPropertyType_DataProperty)
                    return ((FdoDataPropertyDefinition*)propDef.p)->GetDataType();
            }
            else
            {
                FdoStringP propName = objectName.Left(L".");
                objectName = objectName.Right(L".");
                FdoPtr<FdoPropertyDefinition> propDef = defColl->FindItem(propName);
                if (propDef == NULL)
                {
                    FdoPtr<FdoClassDefinition> baseClassDef = classDef->GetBaseClass();
                    while(baseClassDef != NULL)
                    {
                        defColl = baseClassDef->GetProperties();
                        propDef = defColl->FindItem(propName);
                        if (propDef != NULL)
                            break;
                        baseClassDef = baseClassDef->GetBaseClass();
                    }
                }
                if (propDef != NULL)
                {
                    if(propDef->GetPropertyType() == FdoPropertyType_ObjectProperty)
                    {
                        FdoPtr<FdoClassDefinition> classObjDef = ((FdoObjectPropertyDefinition*)propDef.p)->GetClass();
                        return GetObjectType(objectName, classObjDef);
                    }
                    else if(propDef->GetPropertyType() == FdoPropertyType_AssociationProperty)
                    {
                        FdoPtr<FdoClassDefinition> classObjDef = ((FdoAssociationPropertyDefinition*)propDef.p)->GetAssociatedClass();
                        return GetObjectType(objectName, classObjDef);
                    }
                }
            }
        }
        m_UnknownTypeFound = true;
        return (FdoDataType)(FdoDataType_Boolean-1);
    }
public:
    static FdoCommonExpressionExecutor* Create(FdoFeatureSchemaCollection* schColl, FdoIdentifier* className)
    {
        return new FdoCommonExpressionExecutor(schColl, className);
    }

    void ValidateIdentifiers(FdoIdentifierCollection* idCol, FdoIExpressionCapabilities* expCap)
    {
        try
        {
            FdoPtr<FdoFunctionDefinitionCollection> functions = expCap->GetFunctions();
            for (int i = 0; i < idCol->GetCount(); i++)
            {
                FdoPtr<FdoIdentifier> idf = idCol->GetItem(i);
                if (dynamic_cast<FdoComputedIdentifier*>(idf.p) != NULL)
                {
                    FdoPtr<FdoExpression> expr = ((FdoComputedIdentifier*)idf.p)->GetExpression();
                    ValidateExpresion(expr, functions);
                }
            }
        }
        catch(FdoException* e)
        {
            if(m_UnknownTypeFound)
                e->Release();
            else
                throw e;
        }
    }
private:
    FdoDataType ValidateExpresion(FdoExpression* expr, FdoFunctionDefinitionCollection* functions)
    {
        if (dynamic_cast<FdoIdentifier*>(expr) != NULL){
            return GetObjectType(((FdoIdentifier*)expr)->GetName(), m_actClass);
        }
        else if (dynamic_cast<FdoFunction*>(expr) != NULL)
        {
            FdoFunction* fct = (FdoFunction*)expr;
            FdoString* fctName = fct->GetName();
            FdoPtr<FdoExpressionCollection> argsExp = fct->GetArguments();
            FdoPtr<FdoFunctionDefinition> function;

            for(int i = 0; i < functions->GetCount(); i++)
            {
                function = functions->GetItem(i);
                if (FdoCommonOSUtil::wcsicmp(function->GetName(), fctName) != 0)
                    function = NULL;
                else
                    break;
            }
            if (function == NULL) // unknown function do the best...
            {
                m_UnknownTypeFound = true;
                return (FdoDataType)(FdoDataType_Boolean-1);
            }
            // No argument provided, return the type
            if (argsExp == NULL || !argsExp->GetCount())
                return function->GetReturnType();

            FdoPtr<FdoReadOnlySignatureDefinitionCollection> pSigs = function->GetSignatures();

            for(int i = 0; i < pSigs->GetCount(); i++)
            {
                FdoPtr<FdoSignatureDefinition> pSig = pSigs->GetItem(i);
                FdoPtr<FdoReadOnlyArgumentDefinitionCollection> args = pSig->GetArguments();
                if (argsExp->GetCount() != args->GetCount())
                    continue;
                bool argsFound = true;
                for(int y = 0; y < args->GetCount(); y++)
                {
                    FdoDataType dataTypeArg;
                    FdoPtr<FdoArgumentDefinition> arg = args->GetItem(y);
                    FdoPtr<FdoExpression> exp = argsExp->GetItem(y);
                    dataTypeArg = ValidateExpresion(exp, functions);
                    if (dataTypeArg == (FdoDataType)(FdoDataType_Boolean-1))
                        dataTypeArg = arg->GetDataType();
                    if (dataTypeArg != arg->GetDataType())
                    {
                        argsFound = false;
                        break;
                    }
                }
                if (argsFound)
                    return pSig->GetReturnType();
            }
            throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_80_INVALID_EXPRESSION)));
        }
        else if (dynamic_cast<FdoUnaryExpression*>(expr) != NULL)
        {
            // just validate the expression from inside
            FdoPtr<FdoExpression> exp1 = ((FdoUnaryExpression*)expr)->GetExpression();
            ValidateExpresion(exp1, functions);
            return FdoDataType_Boolean;
        }
        else if (dynamic_cast<FdoBinaryExpression*>(expr) != NULL)
        {
            // just validate the expression from inside
            FdoPtr<FdoExpression> exp1 = ((FdoBinaryExpression*)expr)->GetLeftExpression();
            FdoDataType left = ValidateExpresion(exp1, functions);
            FdoPtr<FdoExpression> exp2 = ((FdoBinaryExpression*)expr)->GetRightExpression();
            FdoDataType right = ValidateExpresion(exp2, functions);
            if (left == FdoDataType_String || right == FdoDataType_String)
                return FdoDataType_String;
            if (left == FdoDataType_DateTime || right == FdoDataType_DateTime)
                return FdoDataType_DateTime;
            if (left == FdoDataType_Double || right == FdoDataType_Double)
                return FdoDataType_Double;
            if (left == FdoDataType_Decimal || right == FdoDataType_Decimal)
                return FdoDataType_Decimal;
            if (left == FdoDataType_Single || right == FdoDataType_Single)
                return FdoDataType_Double;
            if (left == FdoDataType_Int64 || right == FdoDataType_Int64)
                return FdoDataType_Int64;
            if (left == FdoDataType_Int32 || right == FdoDataType_Int32)
                return FdoDataType_Int32;
            if (left == FdoDataType_Int16 || right == FdoDataType_Int16)
                return FdoDataType_Int16;
            if (left == FdoDataType_Byte || right == FdoDataType_Byte)
                return FdoDataType_Byte;
            if (left == FdoDataType_Boolean || right == FdoDataType_Boolean)
                return FdoDataType_Boolean;
            // unknown type
            m_UnknownTypeFound = true;
            return (FdoDataType)(FdoDataType_Boolean-1);
        }
        else if (dynamic_cast<FdoStringValue*>(expr) != NULL)
            return FdoDataType_String;
        else if (dynamic_cast<FdoDateTime*>(expr) != NULL)
            return FdoDataType_DateTime;
        else if (dynamic_cast<FdoInt16Value*>(expr) != NULL)
            return FdoDataType_Int16;
        else if (dynamic_cast<FdoInt32Value*>(expr) != NULL)
            return FdoDataType_Int32;
        else if (dynamic_cast<FdoInt64Value*>(expr) != NULL)
            return FdoDataType_Int64;
        else if (dynamic_cast<FdoDoubleValue*>(expr) != NULL)
            return FdoDataType_Double;
        else if (dynamic_cast<FdoDecimalValue*>(expr) != NULL)
            return FdoDataType_Decimal;
        else if (dynamic_cast<FdoSingleValue*>(expr) != NULL)
            return FdoDataType_Single;
        else if (dynamic_cast<FdoByteValue*>(expr) != NULL)
            return FdoDataType_Byte;
        else if (dynamic_cast<FdoBooleanValue*>(expr) != NULL)
            return FdoDataType_Boolean;
        else // unknown type
        {
            m_UnknownTypeFound = true;
            return (FdoDataType)(FdoDataType_Boolean-1);
        }
    }
private:
    FdoPtr<FdoClassCollection> m_classes;
    FdoPtr<FdoClassDefinition> m_actClass;
    FdoBoolean m_UnknownTypeFound;
};

#endif //_FDOCOMMONEXPRESSIONEXECUTOR_H_

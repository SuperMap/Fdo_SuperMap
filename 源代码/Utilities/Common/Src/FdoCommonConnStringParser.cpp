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
#include "FdoCommonConnStringParser.h"
#include "FdoCommonOSUtil.h"
#include "FdoCommonStringUtil.h"
#include "FdoCommonConnPropDictionary.h"

#include <malloc.h>
#include <string.h>


void FdoCommonConnStringParser::SetPropertyValue (FdoCommonConnPropDictionary* propDictionary, const wchar_t* keyword, const wchar_t* value, bool isQuoted)
{
    bool bAddValue = true;
    FdoInt32 propCount=0;
    FdoString** propNames = NULL;
    if (propDictionary)
    {
        bAddValue = false;
        propNames = propDictionary->GetPropertyNames(propCount);
        for (FdoInt32 i = 0; i < propCount; i++)
        {
            if (0 == FdoCommonOSUtil::wcsnicmp (propNames[i], keyword, wcslen (keyword)))
            {
                bAddValue = true;
                break;
            }
        }
    }
    if (bAddValue)
    {
        char* mbValue;
        wide_to_multibyte(mbValue, value);
        FdoStringP pkeyword = ((FdoStringP)keyword).Lower();
        m_valueMap[(const wchar_t*)pkeyword] = ParsStringMapElem(value, mbValue);
        if (isQuoted && NULL != propDictionary)
        {
            FdoPtr<ConnectionProperty> pProp = propDictionary->FindProperty (keyword);
            pProp->SetIsPropertyQuoted (isQuoted);
        }
    }
}

bool FdoCommonConnStringParser::HasInvalidProperties(FdoCommonConnPropDictionary* propDictionary)
{
    bool bRetVal = false;
    FdoInt32 propCount = 0;
    FdoString** propNames = NULL;
    FdoInt32 internalPropCount = (FdoInt32)m_valueMap.size();
    if (propDictionary)
    {
        propNames = propDictionary->GetPropertyNames(propCount);
        for (FdoInt32 i = 0; i < propCount; i++)
        {
            if (IsPropertyValueSet(propNames[i]))
                internalPropCount--;
        }
        bRetVal = (internalPropCount != 0);
    }
    return bRetVal;
}

const wchar_t* FdoCommonConnStringParser::GetFirstInvalidPropertyName(FdoCommonConnPropDictionary* propDictionary)
{
    FdoInt32 propCount = 0;
    FdoString** propNames = NULL;
    if (!propDictionary || !m_valueMap.size())
        return NULL;
    propNames = propDictionary->GetPropertyNames(propCount);

    for (ParsStringMapIter it = m_valueMap.begin(); it != m_valueMap.end(); it++)
    {
        FdoStringP pName = it->first.c_str();
        bool foundProp = false;
        for (FdoInt32 i = 0; i < propCount; i++)
        {
            if (0 == FdoCommonOSUtil::wcsnicmp (propNames[i], pName, pName.GetLength()))
            {
                foundProp = true;
                break;
            }
        }
        if (!foundProp)
            return it->first.c_str();
    }
    return NULL;
}

FdoCommonConnStringParser::FdoCommonConnStringParser (FdoCommonConnPropDictionary* propDictionary, const wchar_t* connection_string) :
    m_connStringValid(false)
{
    if(!connection_string)
        return;
    
    std::wstring LastKey;
    bool isError = false;
    short State = 0;
    int pPoz = 0, pPozPN = 0, pPozPV = 0, pPozEnd = 0;
    do
    {
        switch(State)
        {
            case 0: //looking for start property name
                if (*(connection_string+pPoz) == L'=')
                    isError = true;
                else if (*(connection_string+pPoz) != L' ' && *(connection_string+pPoz) != L';')
                {
                    pPozPN = pPoz;
                    pPozEnd = pPoz+1;
                    State = 1;
                }
            break;
            case 1: //get property name
                if (*(connection_string+pPoz) == L'=')
                {
                    LastKey = std::wstring(connection_string+pPozPN, pPozEnd-pPozPN);
                    SetPropertyValue(propDictionary, LastKey.c_str(), L"");
                    if (*(connection_string+pPoz+1) == L'\"')
                    {
                        pPoz++;
                        State = 3;
                    }
                    else if (*(connection_string+pPoz+1) == L' ')
                    {
                        pPoz++;
                        State = 4;
                    }
                    else
                    {
                        pPozEnd = pPoz+1;
                        State = 2;
                    }
                    pPozPV = pPoz+1;
                }
                else if(*(connection_string+pPoz) == L';' || *(connection_string+pPoz) == L'\0')
                    isError = true;
                else if(*(connection_string+pPoz) != L' ')
                {
                    pPozEnd = pPoz+1;
                }
            break;
            case 2:  //get property value in case value is not surrounded by "
                if(*(connection_string+pPoz) == L'\"')
                    isError = true;
                else if(*(connection_string+pPoz) == L';' || *(connection_string+pPoz) == L'\0')
                {
                    SetPropertyValue(propDictionary, LastKey.c_str(), std::wstring(connection_string+pPozPV, pPozEnd-pPozPV).c_str());
                    State = 0;
                }
                else if(*(connection_string+pPoz) != L' ')
                    pPozEnd = pPoz+1;
            break;
            case 3:  //get property value in case value is surrounded by "
                if(*(connection_string+pPoz) == L'\"')
                {
                    SetPropertyValue(propDictionary, LastKey.c_str(), std::wstring(connection_string+pPozPV, pPoz-pPozPV).c_str(), true);
                    State = 0;
                }
                else if(*(connection_string+pPoz+1) == L'\0')
                    isError = true;
            break;
            case 4:  //handle space before "
                if (*(connection_string+pPoz) == L'\"')
                {
                    pPoz++;
                    State = 3;
                }
                else if(*(connection_string+pPoz) == L';')
                {
                    State = 0;
                }
                else if(*(connection_string+pPoz) != L' ')
                {
                    pPozEnd = pPoz;
                    State = 2;
                }
                pPozPV = pPoz;
            break;
        }
        pPoz++;
    }while(*(connection_string+pPoz-1) != L'\0' && !isError);
    m_connStringValid = !isError;
}

const char* FdoCommonConnStringParser::GetPropertyValue(FdoString* propertyName)
{
    FdoStringP pPropertyName = ((FdoStringP)propertyName).Lower();
    ParsStringMapIter it = m_valueMap.find((FdoString*)pPropertyName);
    return (it == m_valueMap.end()) ? NULL : it->second.second.c_str();
}

const wchar_t* FdoCommonConnStringParser::GetPropertyValueW(FdoString* propertyName)
{
    FdoStringP pPropertyName = ((FdoStringP)propertyName).Lower();
    ParsStringMapIter it = m_valueMap.find((FdoString*)pPropertyName);
    return (it == m_valueMap.end()) ? NULL : it->second.first.c_str();
}

bool FdoCommonConnStringParser::IsPropertyValueSet(FdoString* propertyName)
{
    FdoStringP pPropertyName = ((FdoStringP)propertyName).Lower();
    ParsStringMapIter it = m_valueMap.find((FdoString*)pPropertyName);
    return (it != m_valueMap.end());
}


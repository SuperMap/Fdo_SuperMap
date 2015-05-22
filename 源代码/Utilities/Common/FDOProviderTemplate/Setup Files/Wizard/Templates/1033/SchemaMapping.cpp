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
#include "[!output PREFIX]Provider.h"


[!output PREFIX]SchemaMapping::[!output PREFIX]SchemaMapping(void)
{
    m_ClassMappings = [!output PREFIX]ClassMappingCollection::Create(this);
}

[!output PREFIX]SchemaMapping::~[!output PREFIX]SchemaMapping(void)
{
}

FdoString* [!output PREFIX]SchemaMapping::GetProvider()
{
    return [!output PREFIX]ProviderName;
}


[!output PREFIX]ClassMappingCollection* [!output PREFIX]SchemaMapping::GetClasses()
{
    return FDO_SAFE_ADDREF(m_ClassMappings.p);
}


void [!output PREFIX]SchemaMapping::InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs)
{
    //TODO
}

FdoXmlSaxHandler* [!output PREFIX]SchemaMapping::XmlStartElement(
    FdoXmlSaxContext* context, 
    FdoString* uri, 
    FdoString* name, 
    FdoString* qname, 
    FdoXmlAttributeCollection* atts
)
{
    //TODO
    return(NULL);
}

FdoBoolean [!output PREFIX]SchemaMapping::XmlEndElement(
    FdoXmlSaxContext* context, 
    FdoString* uri, 
    FdoString* name, 
    FdoString* qname
)
{
    //TODO
    return(false);
}


void [!output PREFIX]SchemaMapping::_writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags )
{
    //TODO
}



[!output PREFIX]SchemaMapping* [!output PREFIX]SchemaMapping::Create(void)
{
    return new [!output PREFIX]SchemaMapping();
}


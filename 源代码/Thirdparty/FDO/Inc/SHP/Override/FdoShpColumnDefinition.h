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
#ifndef FDOSHPCOLUMNDEFINITION_H
#define FDOSHPCOLUMNDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoShpOvColumnDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    FDOSHP_API static FdoShpOvColumnDefinition* Create();

public:
    FDOSHP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOSHP_API virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* context,FdoString* uri, FdoString* name, FdoString* qname, FdoXmlAttributeCollection* atts);
    FDOSHP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOSHP_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

protected:
    FdoShpOvColumnDefinition(void);
    virtual ~FdoShpOvColumnDefinition(void);
    virtual void Dispose(void);
};

/// \ingroup (typedefs)
/// \brief
/// FdoShpOvColumnDefinitionP is an FdoPtr on FdoShpOvColumnDefinition
/// provided for convenience.
typedef FdoPtr<FdoShpOvColumnDefinition> FdoShpOvColumnDefinitionP;

#endif // FDOSHPCOLUMNDEFINITION_H



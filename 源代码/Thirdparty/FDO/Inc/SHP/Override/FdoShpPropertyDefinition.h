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
#ifndef FDOSHPPROPERTYDEFINITION_H
#define FDOSHPPROPERTYDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <SHP/Override/FdoShpColumnDefinition.h>

class FdoShpOvPropertyDefinition : public FdoPhysicalPropertyMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    FDOSHP_API static FdoShpOvPropertyDefinition* Create();

public:
    FDOSHP_API FdoShpOvColumnDefinition* GetColumn() const;
    FDOSHP_API void SetColumn(FdoShpOvColumnDefinition * definition);

    FDOSHP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOSHP_API virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* context,FdoString* uri, FdoString* name, FdoString* qname, FdoXmlAttributeCollection* atts);
    FDOSHP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOSHP_API virtual void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
    FdoShpOvPropertyDefinition(void);
    virtual ~FdoShpOvPropertyDefinition(void);
    virtual void Dispose(void);

private:
    FdoShpOvColumnDefinitionP m_ColumnDefinition;
};

/// \ingroup (typedefs)
/// \brief
/// FdoShpOvPropertyDefinition is an FdoPtr on FdoShpOvPropertyDefinition
/// provided for convenience.
typedef FdoPtr<FdoShpOvPropertyDefinition> FdoShpOvPropertyDefinitionP;

#endif // FDOSHPPROPERTYDEFINITION_H



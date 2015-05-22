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
#ifndef FDOSHPPHYSICALSCHEMAMAPPING_H
#define FDOSHPPHYSICALSCHEMAMAPPING_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <SHP/Override/FdoShpClassCollection.h>

class FdoShpOvPhysicalSchemaMapping : public FdoPhysicalSchemaMapping
{
    typedef FdoPhysicalSchemaMapping BaseType;

public:
    FDOSHP_API static FdoShpOvPhysicalSchemaMapping* Create();

    FDOSHP_API virtual FdoString* GetProvider();
    FDOSHP_API FdoShpOvClassCollection* GetClasses() const; 

    FDOSHP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOSHP_API virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* context,FdoString* uri, FdoString* name, FdoString* qname, FdoXmlAttributeCollection* atts);
    FDOSHP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOSHP_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Helper method to find a class mapping that maps to a given shapefile:
    FDOSHP_API FdoShpOvClassDefinition* FindByShapefile(FdoString *shapefilePath);

    /// Helper method to find a class mapping that maps to a given classname:
    FDOSHP_API FdoShpOvClassDefinition* FindByClassName(FdoString *class_name);

protected:
    FdoShpOvPhysicalSchemaMapping(void);
    virtual ~FdoShpOvPhysicalSchemaMapping(void);
    virtual void Dispose(void);

private:
    FdoShpOvClassCollectionP m_Classes;
};

/// \ingroup (typedefs)
/// \brief
/// FdoShpOvPhysicalSchemaMappingP is an FdoPtr on FdoShpOvPhysicalSchemaMapping
/// provided for convenience.
typedef FdoPtr<FdoShpOvPhysicalSchemaMapping> FdoShpOvPhysicalSchemaMappingP;

#endif // FDOSHPPHYSICALSCHEMAMAPPING_H



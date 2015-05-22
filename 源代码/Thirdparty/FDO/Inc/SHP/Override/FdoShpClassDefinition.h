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
#ifndef FDOSHPCLASSDEFINITION_H
#define FDOSHPCLASSDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <SHP/Override/FdoShpPropertyDefinitionCollection.h>

class FdoShpOvClassDefinition : public FdoPhysicalClassMapping
{
	typedef FdoPhysicalClassMapping BaseType;

public:
    FDOSHP_API static FdoShpOvClassDefinition* Create();

public:
    FDOSHP_API FdoShpOvPropertyDefinitionCollection* GetProperties() const;
    
    FDOSHP_API FdoString* GetShapeFile() const;
    FDOSHP_API void SetShapeFile(FdoString * location);
	bool IsPathUpdated(){ return m_pathUpdated; }
	void SetPathUpdated(bool lPathUpdated = true){ m_pathUpdated = lPathUpdated; }

    FDOSHP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOSHP_API virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* context,FdoString* uri, FdoString* name, FdoString* qname, FdoXmlAttributeCollection* atts);
    FDOSHP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOSHP_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Helper method to find a property mapping by its column name:
    FDOSHP_API FdoShpOvPropertyDefinition* FindByColumnName(FdoString* columnName);

protected:
    FdoShpOvClassDefinition(void);
    virtual ~FdoShpOvClassDefinition(void);
    virtual void Dispose(void);

private:
	bool m_pathUpdated;
    FdoStringP m_ShapeFileLocation;
    FdoShpOvPropertyDefinitionCollectionP m_Properties;
};

/// \ingroup (typedefs)
/// \brief
/// FdoShpOvClassDefinitionP is an FdoPtr on FdoShpOvClassDefinition
/// provided for convenience.
typedef FdoPtr<FdoShpOvClassDefinition> FdoShpOvClassDefinitionP;

#endif // FDOSHPCLASSDEFINITION_H



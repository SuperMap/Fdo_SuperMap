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
 *
 */
#ifndef FdoWmsOvPhysicalSchemaMapping_H
#define FdoWmsOvPhysicalSchemaMapping_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>
#include <WMS/Override/FdoWmsOvClassCollection.h>

/// \brief
/// FdoWmsOvPhysicalSchemaMapping is the concrete class that  
/// defines the Schema Overrides for a WMS Provider logical schema. 
class FdoWmsOvPhysicalSchemaMapping : public FdoPhysicalSchemaMapping
{
    typedef FdoPhysicalSchemaMapping BaseType;

public:
    /// \brief
    /// Constructs a new physical schema mapping.
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvPhysicalSchemaMapping instance.
    /// 
	FDOWMS_API static FdoWmsOvPhysicalSchemaMapping* Create();

    /// \brief
    /// Gets the name of the applicable FDO provider.
    /// 
    /// \return
    /// Returns the name of FDO provider to which this Schema Override set 
    /// applies. The provider name conforms to the format:
    /// "{Company}.{Provider}.{Version}".
    /// 
    FDOWMS_API virtual FdoString* GetProvider();

    /// \brief
    /// Gets the collection of Class Definition.
    /// 
    /// \return
    /// Returns the collection of Class Definition.
    /// 
    FDOWMS_API FdoWmsOvClassCollection* GetClasses();  

/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of supported API.
	FDOWMS_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOWMS_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    FDOWMS_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);

protected:
	FDOWMS_API FdoWmsOvPhysicalSchemaMapping(void);
	FDOWMS_API virtual ~FdoWmsOvPhysicalSchemaMapping(void);
    FDOWMS_API virtual void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );
	void Dispose(void);

private:
	FdoPtr<FdoWmsOvClassCollection> m_ClassMappings;

/// \endcond

};

/// \brief
///  FdoWmsOvPhysicalSchemaMappingP is a FdoPtr on FdoWmsOvPhysicalSchemaMapping, provided for convenience. 
typedef FdoPtr<FdoWmsOvPhysicalSchemaMapping> FdoWmsOvPhysicalSchemaMappingP;

#endif // FdoWmsOvPhysicalSchemaMapping_H



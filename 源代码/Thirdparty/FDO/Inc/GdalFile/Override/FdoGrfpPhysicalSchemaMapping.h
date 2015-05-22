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
/// <library>GRFPOverrides.lib</library>

#ifndef FDOGRFPPHYSICALSCHEMAMAPPING_H
#define FDOGRFPPHYSICALSCHEMAMAPPING_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpClassCollection;

/// <summary> 
/// The instance of class FdoGrfpPhysicalSchemaMapping is the root object of 
/// all instances of overrides classes. It holds a list of Class Definitions. 
/// </summary>
class FdoGrfpPhysicalSchemaMapping : public FdoPhysicalSchemaMapping
{
    typedef FdoPhysicalSchemaMapping BaseType;

public:
    /// <summary>Constructs a new physical schema mapping.</summary>
    /// <returns>Returns the newly created FdoGrfpPhysicalSchemaMapping instance.</returns> 
	FDOGRFP_API static FdoGrfpPhysicalSchemaMapping* Create();

    /// <summary>Gets the name of the applicable FDO provider.</summary>
    /// <returns>Returns the name of FDO provider to which this Schema Override set 
    /// applies. The provider name conforms to the format:
    /// "{Company}.{Provider}.{Version}".</returns> 
    FDOGRFP_API virtual FdoString* GetProvider();

    /// <summary>Gets the collection of Class Definition.</summary>
    /// <returns>Returns the collection of Class Definition.</returns> 
    FDOGRFP_API FdoGrfpClassCollection* GetClasses();  

//DOM-IGNORE-BEGIN

	// XML Serialization functions, not part of supported API.
	FDOGRFP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOGRFP_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    FDOGRFP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);

protected:
	FDOGRFP_API FdoGrfpPhysicalSchemaMapping(void);
	FDOGRFP_API virtual ~FdoGrfpPhysicalSchemaMapping(void);
    FDOGRFP_API virtual void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );
	void Dispose(void);

private:
	FdoPtr<FdoGrfpClassCollection> m_ClassMappings;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpPhysicalSchemaMappingP is a FdoPtr on FdoGrfpPhysicalSchemaMapping, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpPhysicalSchemaMapping> FdoGrfpPhysicalSchemaMappingP;

#endif

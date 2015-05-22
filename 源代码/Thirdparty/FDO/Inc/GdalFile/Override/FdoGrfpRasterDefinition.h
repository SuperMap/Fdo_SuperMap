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

#ifndef FDOGRFPRASTERDEFINITION_H
#define FDOGRFPRASTERDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterLocationCollection;

/// <summary> 
/// The FdoGrfpRasterDefinition class contains a collection of raster locations.
/// </summary>
class FdoGrfpRasterDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;
	friend class FdoGrfpClassDefinition;

public:
    /// <summary>Constructs a new Raster Definition.</summary>
    /// <returns>Returns the newly created FdoGrfpRasterDefinition instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterDefinition* Create();

    /// <summary>Gets the collection of raster locations.</summary>
    /// <returns>Returns the collection of raster locations.</returns> 
	FDOGRFP_API FdoGrfpRasterLocationCollection* GetLocations();

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
    FDOGRFP_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOGRFP_API FdoGrfpRasterDefinition(void);
	FDOGRFP_API virtual ~FdoGrfpRasterDefinition(void);
	void Dispose(void);

private:
	FdoPtr<FdoGrfpRasterLocationCollection> m_rasterLocations;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterDefinitionP is a FdoPtr on FdoGrfpRasterDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterDefinition> FdoGrfpRasterDefinitionP;

#endif

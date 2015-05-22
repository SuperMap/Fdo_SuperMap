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

#ifndef FDOGRFPRASTERFEATUREDEFINITION_H
#define FDOGRFPRASTERFEATUREDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterExtents;
class FdoGrfpRasterLocation;
class FdoGrfpRasterBandCollection;
class FdoGrfpRasterBandDefinition;

/// <summary> 
/// The FdoGrfpRasterFeatureDefinition class contains a collection of raster Features.
/// </summary>
class FdoGrfpRasterFeatureDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    /// <summary>Constructs a new Raster Feature Definition.</summary>
    /// <returns>Returns the newly created FdoGrfpRasterFeatureDefinition instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterFeatureDefinition* Create();

    /// <summary>Gets the collection of raster band definitions.</summary>
    /// <returns>Returns the collection of raster bans.</returns> 
	FDOGRFP_API FdoGrfpRasterBandCollection* GetBands();

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
	FDOGRFP_API FdoGrfpRasterFeatureDefinition(void);
	FDOGRFP_API virtual ~FdoGrfpRasterFeatureDefinition(void);
	void Dispose(void);

private:
	FdoPtr<FdoGrfpRasterBandCollection> m_rasterBands;
	FdoStringP                         m_name;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterFeatureDefinitionP is a FdoPtr on FdoGrfpRasterFeatureDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterFeatureDefinition> FdoGrfpRasterFeatureDefinitionP;

/// <summary> 
/// The FdoGrfpRasterFeatureCollection class holds a list of Raster Feature Definition.
/// </summary>
class FdoGrfpRasterFeatureCollection : public FdoPhysicalElementMappingCollection<FdoGrfpRasterFeatureDefinition>
{
public:
    /// <summary>Constructs a new empty collection of Raster Feature Definition.</summary>
    /// <param name="parent">Input parent object</param> 
    /// <returns>Returns the newly created FdoGrfpRasterFeatureCollection instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterFeatureCollection* Create(FdoGrfpRasterLocation *parent);

//DOM-IGNORE-BEGIN

protected:
	FdoGrfpRasterFeatureCollection();
    FDOGRFP_API FdoGrfpRasterFeatureCollection(FdoGrfpRasterLocation *parent);
    FDOGRFP_API virtual ~FdoGrfpRasterFeatureCollection(void);
	void Dispose();

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterFeaturesP is a FdoPtr on FdoGrfpRasterFeatureCollection, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterFeatureCollection> FdoGrfpRasterFeaturesP;

#endif


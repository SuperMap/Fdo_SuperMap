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

#ifndef FDOGRFPRASTERLOCATION_H
#define FDOGRFPRASTERLOCATION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterFeatureCollection;
class FdoGrfpRasterDefinition;

/// <summary> 
/// The FdoGrfpRasterLocation class defines a location that contains a collection of raster feature definitions. 
/// </summary>
class FdoGrfpRasterLocation : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    /// <summary> Constructs a new empty Raster Location. </summary>
    /// <returns> Returns the newly created FdoGrfpRasterLocation instance. </returns> 
	FDOGRFP_API static FdoGrfpRasterLocation* Create();

    /// <summary> Gets the collection of the raster feature definition contained in the location. </summary>
    /// <returns> Returns the collection of the raster feature definition contained in the location. </returns> 
	FDOGRFP_API FdoGrfpRasterFeatureCollection* GetFeatureCatalogue();

    /// <summary> Sets the collection of the raster feature definition. </summary>
    /// <param name="catalogue"> Input the collection of the raster feature definition</param>
	/// <returns>Returns nothing</returns> 
	FDOGRFP_API void SetFeatureCatalogue(FdoGrfpRasterFeatureCollection* catalogue);

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
	FDOGRFP_API FdoGrfpRasterLocation(void);
	FDOGRFP_API virtual ~FdoGrfpRasterLocation(void);
	void Dispose(void);

private:
	FdoPtr<FdoGrfpRasterFeatureCollection> m_featureCatalogue;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterLocationP is a FdoPtr on FdoGrfpRasterLocation, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterLocation> FdoGrfpRasterLocationP;

/// <summary> 
/// The FdoGrfpRasterLocationCollection class contains a collection of Raster Locations.
/// </summary>
class FdoGrfpRasterLocationCollection : public FdoPhysicalElementMappingCollection<FdoGrfpRasterLocation>
{
public:
    /// <summary> Constructs a new empty collection of Raster Location. </summary>
    /// <param name="parent">Input parent object</param> 
    /// <returns> Returns the newly created FdoGrfpRasterLocationCollection instance. </returns> 
	FDOGRFP_API static FdoGrfpRasterLocationCollection* Create(FdoGrfpRasterDefinition *parent);

//DOM-IGNORE-BEGIN

protected:
	FdoGrfpRasterLocationCollection();
    FDOGRFP_API FdoGrfpRasterLocationCollection(FdoGrfpRasterDefinition *parent);
    FDOGRFP_API virtual ~FdoGrfpRasterLocationCollection(void);
	void Dispose();

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterLocationsP is a FdoPtr on FdoGrfpRasterLocationCollection, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterLocationCollection> FdoGrfpRasterLocationsP;

#endif

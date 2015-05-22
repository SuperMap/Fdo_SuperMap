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

#ifndef FDOGRFPRASTERBANDDEFINITION_H
#define FDOGRFPRASTERBANDDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterExtents;
class FdoGrfpRasterFeatureDefinition;
class FdoGrfpRasterImageDefinition;

/// <summary> 
/// The FdoGrfpRasterBandDefinition class defines a raster band which contains a name 
/// and the extents of the raster band.
/// </summary>
class FdoGrfpRasterBandDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    /// <summary>Constructs a new Raster Band Definition.</summary>
    /// <returns>Returns the newly created FdoGrfpRasterBandDefinition instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterBandDefinition* Create();

	/// <summary>Gets the raster image definition</summary>
    /// <returns>Returns the raster image definition. </returns> 
	FDOGRFP_API FdoGrfpRasterImageDefinition* GetImage();

    /// <summary>Sets the raster image definition.</summary>
	/// <param name="imageDefinition">Input raster image definition</param>
	/// <returns>Returns nothing</returns> 
	FDOGRFP_API void SetImage(FdoGrfpRasterImageDefinition* imageDefinition);

	/// <summary>Gets the band number</summary>
    /// <returns>Returns the band number. </returns> 
	FDOGRFP_API FdoInt32 GetBandNumber();

    /// <summary>Sets the band number.</summary>
	/// <param name="imageDefinition">Input band number</param>
	/// <returns>Returns nothing</returns> 
	FDOGRFP_API void SetBandNumber(FdoInt32 bandNumber);

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
    FDOGRFP_API virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );
    FDOGRFP_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOGRFP_API FdoGrfpRasterBandDefinition(void);
	FDOGRFP_API virtual ~FdoGrfpRasterBandDefinition(void);
	void Dispose(void);

private:
	FdoPtr<FdoGrfpRasterImageDefinition> m_imageDefinition;
	FdoInt32 m_bandNumber;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterBandDefinitionP is a FdoPtr on FdoGrfpRasterBandDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterBandDefinition> FdoGrfpRasterBandDefinitionP;


/// <summary> 
/// The FdoGrfpRasterBandCollection class holds a list of Raster Band Definition.
/// </summary>
class FdoGrfpRasterBandCollection : public FdoPhysicalElementMappingCollection<FdoGrfpRasterBandDefinition>
{
public:
    /// <summary>Constructs a new empty collection of Raster Band Definition.</summary>
    /// <param name="parent">Input parent object</param> 
    /// <returns>Returns the newly created FdoGrfpRasterBandCollection instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterBandCollection* Create(FdoGrfpRasterFeatureDefinition *parent);

//DOM-IGNORE-BEGIN

protected:
	FdoGrfpRasterBandCollection();
    FDOGRFP_API FdoGrfpRasterBandCollection(FdoGrfpRasterFeatureDefinition *parent);
    FDOGRFP_API virtual ~FdoGrfpRasterBandCollection(void);
	void Dispose();

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterBandsP is a FdoPtr on FdoGrfpRasterBandCollection, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterBandCollection> FdoGrfpRasterBandsP;

#endif

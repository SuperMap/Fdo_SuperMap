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

#ifndef FDOGRFPRASTERIMAGEDEFINITION_H
#define FDOGRFPRASTERIMAGEDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterExtents;
class FdoGrfpRasterGeoreferenceLocation;

/// <summary> 
/// The FdoGrfpRasterImageDefinition class defines a raster image which contains a name 
/// and the extents of the raster image.
/// </summary>
class FdoGrfpRasterImageDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;
	friend class FdoGrfpRasterBandDefinition;

public:
    /// <summary>Constructs a new Raster Image Definition.</summary>
    /// <returns>Returns the newly created FdoGrfpRasterImageDefinition instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterImageDefinition* Create();

    /// <summary>Gets the frame number of the raster image.</summary>
    /// <returns>Returns the frame number of the raster image.</returns> 
	FDOGRFP_API FdoInt32 GetFrameNumber();

    /// <summary>Sets the frame number of the raster image.</summary>
    /// <param name="extents">Input the frame number of the raster image.</param>
	/// <returns>Returns nothing</returns> 
	FDOGRFP_API void SetFrameNumber(FdoInt32 frameNumber);

    /// <summary>Gets the georeferenced location of the raster image.</summary>
    /// <returns>Returns the georeferenced location of the raster image.</returns> 
    FDOGRFP_API FdoGrfpRasterGeoreferenceLocation * GetGeoreferencedLocation();

    /// <summary>Sets the georeferenced location of the raster image.</summary>
    /// <param name="location">Input the georeferenced location of the raster image.</param>
    /// <returns>Returns nothing</returns> 
    FDOGRFP_API void SetGeoreferencedLocation (FdoGrfpRasterGeoreferenceLocation * location);

    FDOGRFP_API bool GetBounds( double &minX, double &minY, double &maxX, double &maxY );
    FDOGRFP_API void SetBounds( double minX, double minY, double maxX, double maxY );

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
    FDOGRFP_API virtual void XmlCharacters(FdoXmlSaxContext*, FdoString*);
    FDOGRFP_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOGRFP_API FdoGrfpRasterImageDefinition(void);
	FDOGRFP_API virtual ~FdoGrfpRasterImageDefinition(void);
	void Dispose(void);

private:
    FdoInt32 m_state;
    FdoInt32 m_frameNumber;
    FdoPtr<FdoGrfpRasterGeoreferenceLocation> m_geoReference;

    bool     m_haveBounds;
    double   m_minX;
    double   m_minY;
    double   m_maxX;
    double   m_maxY;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterImageDefinitionP is a FdoPtr on FdoGrfpRasterImageDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterImageDefinition> FdoGrfpRasterImageDefinitionP;

#endif

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

#ifndef FDOGRFPRASTERGEOREFERENCELOCATION_H
#define FDOGRFPRASTERGEOREFERENCELOCATION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

/// <summary> 
/// The FdoGrfpRasterImageDefinition class defines a raster image which contains a name 
/// and the extents of the raster image.
/// </summary>
class FdoGrfpRasterGeoreferenceLocation : public FdoDisposable
{
public:
    /// <summary>Constructs a new Raster Image Georeference Location.</summary>
    /// <returns>Returns the newly created FdoGrfpRasterGeoreferenceLocation instance.</returns> 
	FDOGRFP_API static FdoGrfpRasterGeoreferenceLocation* Create();

	/// <summary>Retrieves the X insertion point of the raster image.</summary>
    /// <returns>Returns the X insertion point.</returns> 
    /// <remarks> X coordinate (in ground units) of the center of the upper 
    /// left pixel of the image; the (1, 1) or (0, 0) pixel depending on convention.</remarks>
    FDOGRFP_API FdoDouble GetXInsertionPoint (void) const;

    /// <summary>Sets the X insertion point of the raster image.</summary>
    /// <param name="point">Input the X insertion point of the image.</param>
    /// <returns>Returns nothing.</returns> 
    /// <remarks> X coordinate (in ground units) of the center of the upper 
    /// left pixel of the image; the (1, 1) or (0, 0) pixel depending on convention.</remarks>
    FDOGRFP_API void SetXInsertionPoint (FdoDouble point);

    /// <summary>Retrieves the Y insertion point of the raster image.</summary>
    /// <returns>Returns the Y insertion point.</returns> 
    /// <remarks> Y coordinate (in ground units) of the center of the upper 
    /// left pixel of the image; the (1, 1) or (0, 0) pixel depending on convention.</remarks>
    FDOGRFP_API FdoDouble GetYInsertionPoint (void) const;

    /// <summary>Sets the Y insertion point of the raster image.</summary>
    /// <param name="point">Input the Y insertion point of the image.</param>
    /// <returns>Returns nothing.</returns> 
    /// <remarks> Y coordinate (in ground units) of the center of the upper 
    /// left pixel of the image; the (1, 1) or (0, 0) pixel depending on convention.</remarks>
    FDOGRFP_API void SetYInsertionPoint (FdoDouble point);

    /// <summary>Retrieves the X resolution of the raster image.</summary>
    /// <returns>Returns the Resolution angle.</returns> 
    /// <remarks> Cell size in the X direction. Usually a positive number. </remarks>
    FDOGRFP_API FdoDouble GetXResolution (void) const;

    /// <summary>Sets the X Resolution of the raster image.</summary>
    /// <param name="Resolution">Input the Resolution angle in degrees.</param>
    /// <returns>Returns nothing.</returns> 
    /// <remarks> Cell size in the X direction. Usually a positive number. </remarks>
    FDOGRFP_API void SetXResolution (FdoDouble Resolution);

    /// <summary>Retrieves the Y Resolution of the raster image.</summary>
    /// <returns>Returns the Resolution angle.</returns> 
    /// <remarks> Cell size in the Y direction. Usually a negative number in order to convert 
    /// from image row numbering (increasing from the top down) to map coordinates (increasing 
    /// from the bottom up). For a rectified image, ResolutionY must be equal to ResolutionX and 
    /// of opposite sign. </remarks>
    FDOGRFP_API FdoDouble GetYResolution (void) const;

    /// <summary>Sets the Y Resolution of the raster image.</summary>
    /// <param name="resolution">Input the resolution of the .</param>
    /// <returns>Returns nothing.</returns> 
    /// <remarks> Cell size in the Y direction. Usually a negative number in order to convert 
    /// from image row numbering (increasing from the top down) to map coordinates (increasing 
    /// from the bottom up). For a rectified image, ResolutionY must be equal to ResolutionX and 
    /// of opposite sign. </remarks>
    FDOGRFP_API void SetYResolution (FdoDouble resolution);

    /// <summary>Retrieves the X Rotation of the raster image.</summary>
    /// <returns>Returns the rotation angle.</returns> 
    FDOGRFP_API FdoDouble GetXRotation (void) const;

    /// <summary>Sets the X Rotation of the raster image.</summary>
    /// <param name="rotation">Input the rotation angle in degrees.</param>
    /// <returns>Returns nothing.</returns> 
    FDOGRFP_API void SetXRotation (FdoDouble rotation);

    /// <summary>Retrieves the Y Rotation (Skew) of the raster image.</summary>
    /// <returns>Returns the rotation angle.</returns> 
    FDOGRFP_API FdoDouble GetYRotation (void) const;

    /// <summary>Sets the Y Rotation (Skew) of the raster image.</summary>
    /// <param name="rotation">Input the rotation angle in degrees.</param>
    /// <returns>Returns nothing.</returns> 
    FDOGRFP_API void SetYRotation (FdoDouble rotation);

protected:
	FDOGRFP_API FdoGrfpRasterGeoreferenceLocation(void);
	FDOGRFP_API virtual ~FdoGrfpRasterGeoreferenceLocation(void);
	void Dispose(void);

private:
	FdoDouble m_resX;
    FdoDouble m_resY;
	FdoDouble m_insX;
    FdoDouble m_insY;
	FdoDouble m_rotX;
    FdoDouble m_rotY; 
//DOM-IGNORE-END
};

/// <summary> FdoGrfpRasterImageDefinitionP is a FdoPtr on FdoGrfpRasterImageDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpRasterGeoreferenceLocation> FdoGrfpRasterGeoreferenceLocationP;

#endif // FDOGRFPRASTERGEOREFERENCELOCATION_H

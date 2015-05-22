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
#ifndef FDOWMSRASTERDEFINITION_H
#define FDOWMSRASTERDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>
#include <WMS/Override/FdoWmsOvFormatType.h>
#include <WMS/Override/FdoWmsOvLayerCollection.h>

/// \brief
///  
/// The FdoWmsOvRasterDefinition class defines the physical overrides for a raster property in a WMS FDO schema.
class FdoWmsOvRasterDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;
	friend class FdoWmsOvClassDefinition;

public:
    /// \brief
    /// Constructs a new Raster Definition.
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvRasterDefinition instance.
    /// 
	FDOWMS_API static FdoWmsOvRasterDefinition* Create();

    /// \brief
    /// Gets the format type in which the WMS image will be generated.
    /// 
    /// \remarks
    /// Allowed map formats are "picture" formats . Picture formats constitute 
    /// a rectangular pixel array of fixed size. Picture formats include file types such 
    /// as Portable Network Graphics (PNG), Joint Photographics Expert Group (JPEG) 
    /// and file types such as Tagged Image File Format (TIFF).
    /// 
    /// \return
    /// Returns the WMS format type.
    /// 
    FDOWMS_API FdoWmsOvFormatType GetFormatType(void) const;

    /// \brief
    /// Sets the format type in which the WMS image will be generated.
    /// 
    /// \remarks
    /// Allowed map formats are "picture" formats . Picture formats constitute 
    /// a rectangular pixel array of fixed size. Picture formats include file types such 
    /// as Portable Network Graphics (PNG), Joint Photographics Expert Group (JPEG) 
    /// and file types such as Tagged Image File Format (TIFF).
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDOWMS_API void SetFormatType(FdoWmsOvFormatType value);

    /// \brief
    /// Gets the transparency state.
    /// 
    /// \remarks
    /// The transparency state specifies whether the WMS map background is to  
    /// be made transparent or not. The default value is false. The ability to return 
    /// an image drawn with transparent pixels allows results of different Map requests 
    /// to be overlaid, producing a composite map. 
    /// 
    /// \return
    /// Returns an FdoBoolean indicating the state of the transparency flag.
    /// 
    FDOWMS_API FdoBoolean GetTransparent(void) const;
    
    /// \brief
    /// Sets the transparency state.
    /// 
    /// \remarks
    /// The transparency state specifies whether the WMS map background is to  
    /// be made transparent or not. The default value is false. The ability to return 
    /// an image drawn with transparent pixels allows results of different Map requests 
    /// to be overlaid, producing a composite map. 
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDOWMS_API void SetTransparent(FdoBoolean transparent);  

    /// \brief
    /// Gets the background color.
    /// 
    /// \remarks
    /// The background color is a string that specifies the color to be used 
    /// as the background pixels of the map. The general format of the background color 
    /// is a hexadecimal encoding of an RGB value where two hexadecimal characters 
    /// are used for each of Red, Green, and Blue colour values. The values can range 
    /// between 00 and FF for each (0 and 255, base 10). The format is 0xRRGGBB; either 
    /// upper or lower case characters are allowed for RR, GG, and BB values. 
    /// The "0x" prefix shall have a lower case ‘x? The default value is 0xFFFFFF 
    /// (corresponding to the colour white).
    /// 
    /// \return
    /// Returns a FdoString indicating the background color 
    /// to be used when rendering the WMS image.
    /// 
    FDOWMS_API FdoString* GetBackgroundColor(void) const;

    /// \brief
    /// Sets the background color.
    /// 
    /// \remarks
    /// The background color is a string that specifies the color to be used 
    /// as the background pixels of the map. The general format of the background color 
    /// is a hexadecimal encoding of an RGB value where two hexadecimal characters 
    /// are used for each of Red, Green, and Blue colour values. The values can range 
    /// between 00 and FF for each (0 and 255, base 10). The format is 0xRRGGBB; either 
    /// upper or lower case characters are allowed for RR, GG, and BB values. 
    /// The "0x" prefix shall have a lower case ‘x? The default value is 0xFFFFFF 
    /// (corresponding to the colour white).
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDOWMS_API void SetBackgroundColor(FdoString* bgColor);

    /// \brief
    /// Gets the time dimension of the requested WMS map.
    /// 
    /// \remarks
    /// If a WMS map has a Time dimension defined, then requests may 
    /// include the parameter TIME=value. For the TIME parameter, the special keyword 
    /// 'current' may be used if the WMS Dimension:Name="time" service metadata 
    /// element includes a nonzero value for the 'current' attribute. The expression 
    /// "TIME=current" means send the most current data available. The expression 
    /// "TIME=start_time/current" means send data from start_time up to the most 
    /// current data available.
    /// 
    /// \return
    /// Returns a FdoString indicating the time dimension of the 
    /// requested WMS image.
    /// 
    FDOWMS_API FdoString* GetTimeDimension(void) const;

    /// \brief
    /// Sets the time dimension of the requested WMS map.
    /// 
    /// \remarks
    /// If a WMS map has a Time dimension defined, then requests may 
    /// include the parameter TIME=value. For the TIME parameter, the special keyword 
    /// 'current' may be used if the WMS Dimension:Name="time" service metadata 
    /// element includes a nonzero value for the 'current' attribute. The expression 
    /// "TIME=current" means send the most current data available. The expression 
    /// "TIME=start_time/current" means send data from start_time up to the most 
    /// current data available.
    /// 
    /// \return
    /// Returns nothing .
    /// 
    FDOWMS_API void SetTimeDimension(FdoString* time);

    /// \brief
    /// Gets the elevation dimension of the requested WMS map.
    /// 
    /// \remarks
    /// If a WMS Map has a Elevation dimension defined, then in 
    /// order to retrieve the map in the required dimension, 
    /// the dimension property may set to 'ELEVATION=value'.
    /// 
    /// \return
    /// Returns a FdoString indicating the elevation dimension 
    /// of the requested WMS image.
    /// 
    FDOWMS_API FdoString* GetElevationDimension(void) const;

    /// \brief
    /// Sets the time dimension of the requested WMS map.
    /// 
    /// \remarks
    /// If a WMS Map has a Elevation dimension defined, then in 
    /// order to retrieve the map in the required dimension, 
    /// the dimension property may set to 'ELEVATION=value'.
    /// 
    /// \return
    /// Returns nothing.
    /// \return
    /// /// Returns a FdoString indicating the elevation dimension 
    /// of the requested WMS image.
    /// 
    /// 
    FDOWMS_API void SetElevationDimension(FdoString* dimension);

    /// \brief
    /// Gets the spatial context in which the requested 
    /// WMS map will be returned.
    /// 
    /// \remarks
    /// The same spatial context name applies to all layers 
    /// in a single WMS class definition.
    /// 
    /// \return
    /// Returns the WMS Provider's spatial context name.
    /// 
    FDOWMS_API FdoString* GetSpatialContextName(void) const;

    /// \brief
    /// Sets the spatial context in which the requested 
    /// WMS map will be returned.
    /// 
    /// \remarks
    /// The same spatial context name applies to all layers 
    /// in a single WMS class definition.
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDOWMS_API void SetSpatialContextName(FdoString* value);

    /// \brief
    /// Gets the WMS layers that will be used to construct 
    /// the composite WMS image.
    /// 
    /// \remarks
    /// A WMS shall render the requested layers by drawing 
    /// the first map in the list bottommost, the next one over that, 
    /// and so on.
    /// 
    /// \return
    /// Returns the collection of WMS layers associated to the logical 
    /// FDO class definition.
    /// 
    FDOWMS_API FdoWmsOvLayerCollection* GetLayers(void) const;

    /// \brief
    /// Gets the fully qualified name of this element
    /// 
    /// \return
    /// Returns the qualified element name
    /// 
    FDOWMS_API virtual FdoStringP GetQualifiedName();

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
    FDOWMS_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOWMS_API FdoWmsOvRasterDefinition(void);
	FDOWMS_API virtual ~FdoWmsOvRasterDefinition(void);

protected:
    void _SetFormatType(FdoString* value);
    FdoStringP _GetFormatType(void) const;
    void _SetTransparent(FdoString* value);
    FdoStringP _GetTransparent(void) const;
	void Dispose(void);

private:
    FdoStringP m_backgroundColor;
    FdoStringP m_timeDimension;
    FdoStringP m_elevationDimension;
    FdoStringP m_spatialContext;
    FdoBoolean m_transparent;
    FdoWmsOvFormatType m_formmatType;
	FdoWmsOvLayersP m_layers;
    FdoXmlCharDataHandler *m_pXmlContentHandler;

/// \endcond

};

/// \brief
///  FdoWmsOvRasterDefinitionP is a FdoPtr on FdoWmsOvRasterDefinition, provided for convenience. 
typedef FdoPtr<FdoWmsOvRasterDefinition> FdoWmsOvRasterDefinitionP;

#endif  // FDOWMSRASTERDEFINITION_H



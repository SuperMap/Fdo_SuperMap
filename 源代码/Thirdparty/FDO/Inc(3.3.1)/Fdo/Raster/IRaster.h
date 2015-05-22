#ifndef _IRASTER_H_
#define _IRASTER_H_

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Raster/RasterDataModelType.h>
#include <Fdo/Raster/RasterDataOrganization.h>
#include <Fdo/Raster/IRasterPropertyDictionary.h>
#include <Fdo/Expression/DataValue.h>
#include <Geometry/IEnvelope.h>
#include <Common/IStreamReader.h>

/// \brief
/// The FdoIRaster specifies the data type and organization
/// of raster data retrieved and stored. Using this class and the image
/// extents in width and length, the binary format of the image data returned
/// by and accepted by the FdoIoStreamReader class can be interpreted.
class FdoIRaster : public FdoIDisposable
{
public:

    /// \brief
    /// Returns true if the FdoIRaster represents a null value.
    /// 
    /// \return
    /// Returns true if the FdoIRaster represents a null value.
    /// 
    FDO_API virtual bool IsNull () = 0;

    /// \brief
    /// Sets the FdoIRaster to a null value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetNull () = 0;

    /// \brief
    ///  Gets the number of bands/channels contained in the raster image.
    /// 
    /// \return
    ///  Returns the numbers of bands/channels contained in the raster image. 
    /// 
    FDO_API virtual FdoInt32 GetNumberOfBands () = 0;

    /// \brief
    ///  Sets the number of bands/channels contained in the raster image.
    /// 
    /// \return
    ///  Returns nothing. 
    /// 
    FDO_API virtual void SetNumberOfBands (FdoInt32 value) = 0;

    /// \brief
    ///  Gets the currently active band/channel.
    /// 
    /// \remarks
    ///  The FdoIRaster Bounds, DataModel, ImageSize, AuxilliaryProperties and Stream 
    /// accessors all conform to the current band. NOTE: The return value
    /// is a 1 based index whose maximum value is determined by the result from
    /// GetNumberOfBands.
    /// 
    /// \return
    ///  Returns the current active band/channel. 
    /// 
    FDO_API virtual FdoInt32 GetCurrentBand () = 0;

    /// \brief
    ///  Sets the currently active band/channel.
    /// 
    /// \remarks
    ///  Setting the current band will mean that the Bounds, DataModel, ImageSize, 
    /// AuxilliaryProperties and Stream accessors of FdoIRaster 
    /// will all switch to the specified band. NOTE: The input parameter 'value'
    /// is indexed starting from 1 to the result returned from GetNumberOfBands.
    /// 
    /// \return
    ///  Returns nothing. 
    /// 
    FDO_API virtual void SetCurrentBand (FdoInt32 value) = 0;

    /// Get the minimum bounding box around the image.
    /// The bounds are transformed to the active spatial context.
    FDO_API virtual FdoByteArray* GetBounds () = 0;

    /// Set the minimum bounding box around the image.
    /// For georeferenced images, the coordinate system is specified by the
    /// spatial context in force when the object is created.  The act of
    /// setting this property georeferences the image.  In order to provide
    /// for non-georeferenced images, this property is Nullable (doesn't
    /// need to be set).
    FDO_API virtual void SetBounds (FdoByteArray* bounds) = 0;

    /// \brief
    /// Gets the data model in use by this raster property.
    /// 
    /// \return
    /// Returns the current data model.
    /// 
    FDO_API virtual FdoRasterDataModel* GetDataModel () = 0;

    /// \brief
    /// Sets the data model used by this raster property.
    /// Allowed values are only those data models that are acceptable to the
    /// SupportsDataModel capability.
    /// This attribute specifies the colour/palette model, bits per pixel,
    /// tiling and interleaving. For example, if the bits per pixel of the
    /// data model is 8 and it is set to 24, a conversion would be performed
    /// when image data is requested, to return 24 bit data.  If an update
    /// command is executed to save this value, the raster data would be
    /// transformed and saved.  The next time this image is retrieved
    /// by the client the bits per pixel value would indicate 24.
    /// 
    /// \param datamodel 
    /// The datamodel to be used.
    /// 
    FDO_API virtual void SetDataModel (FdoRasterDataModel* datamodel) = 0;

    /// \brief
    /// Gets the size of image file in the horizontal
    /// direction in pixels (number of columns).
    /// 
    /// \return
    /// Returns the horizontal image size in pixels
    /// (number of columns).
    /// 
    FDO_API virtual FdoInt32 GetImageXSize () = 0;

    /// \brief
    /// Sets the size of image file in the horizontal
    /// direction in pixels (number of columns).
    /// By setting the X and Y image size properties prior to getting
    /// a reader for the data, the client application can control the
    /// density of pixels fetched by the provider, which may reduce
    /// the amount of data shipped by the reader and reduce processing
    /// time significantly.  For example, a certain query in the
    /// coordinate system of the raster object class returns a
    /// FdoIRaster object with image size 12091 by 8043.  But the
    /// image only needs to be displayed in an area 1167 by 776 on
    /// the users monitor. 
    /// \note
    /// The aspect ratios are the same
    /// because the query is constructed based on the display area).
    /// \remarks
    /// By setting the image size to these lower values the FDO raster
    /// subsystem may be able to use a previously subsampled image
    /// where the resolution has been reduced by a factor of 4.
    /// So instead of transferring 97MB, it can transfer 6MB (a reduction
    /// by 4 in both dimensions reduces the amount of data by a factor of 16)
    /// and subsample the image again to the desired resolution in a
    /// more timely manner (less data to process means less total time),
    /// with no appreciable difference in display quality to the user.
    /// 
    /// \param size 
    /// The desired horizontal image size in pixels
    /// (number of columns).
    /// 
    FDO_API virtual void SetImageXSize (FdoInt32 size) = 0;

    /// \brief
    /// Gets the size of image file in the vertical
    /// direction in pixels (number of rows).
    /// 
    /// \return
    /// Returns the vertical image size in pixels
    /// (number of rows).
    /// 
    FDO_API virtual FdoInt32 GetImageYSize () = 0;

    /// \brief
    /// Sets the size of image file in the vertical
    /// direction in pixels (number of rows). See SetImageXSize.
    /// 
    /// \param size 
    /// The desired vertical image size in pixels
    /// (number of rows).
    /// 
    FDO_API virtual void SetImageYSize (FdoInt32 size) = 0;

    /// \brief
    /// Get a dictionary style interface to the raster properties.
    /// Through this interface the non-standard properties of a raster
    /// image can be determined and their values can be retrieved and set.
    /// Data values are exchanged through the FdoDataValue object to
    /// accommodate various data types, boolean, integer, double, string,
    /// etc.
    /// 
    /// \return
    /// The dictionary of auxilliary raster properties.
    /// 
    FDO_API virtual FdoIRasterPropertyDictionary* GetAuxiliaryProperties () = 0;

    /// \brief
    ///  Gets the pixel value that represents a NULL value in the available raster stream. 
    /// 
    /// \remarks
    ///  The Null Pixel Value is Data Model dependent. The value of the Null pixel
    /// will change depending on which data model is set. If the client application changes 
    /// the Data Model using SetDataModel(FdoRasterDataModel* datamodel) a subsequent 
    /// call to GetNullPixelValue will need to be made in order to determine the valid Null 
    /// value for the current data model.
    /// 
    /// \return
    ///  Returns the FdoDataType value that can be used to identify the Null value. 
    /// 
    FDO_API virtual FdoDataValue* GetNullPixelValue () = 0;

    /// \brief
    /// Set the source of image data.
    /// Image data is shipped using a paradigm similar to BLOB I/O.
    /// When inserting or updating an object with a raster property,
    /// the SetStreamReader method provides a means to set a
    /// FdoIStreamReader callback.
    /// On execution of an insert or update command, requests are made on
    /// the reader for the image data (which is supplied by the FDO client
    /// application).
    /// The format of the image data expected is determined by the
    /// DataModel property.  The data type, bit depth, tiling and
    /// organization specify the meaning of the image data.
    /// By setting the DataModel property prior to setting a
    /// reader for the data, the FDO client application can control the
    /// way data is understood by, the FDO raster subsystem.
    /// 
    FDO_API virtual void SetStreamReader (FdoIStreamReader* reader) = 0;

    /// \brief
    /// Get the source of image data.
    /// Image data is shipped using a paradigm similar to BLOB I/O.
    /// When fetching a raster image the GetStreamReader() method provides
    /// a FdoIStreamReader from which the client may request the image data.
    /// \remarks
    /// The format of the image data expected is determined by the
    /// DataModel property.  The data type, bit depth, tiling and
    /// organization specify the meaning of the image data.
    /// By setting the DataModel property prior to getting a
    /// reader for the data, the FDO client application can control the
    /// way data is retrieved from the FDO raster subsystem.
    /// When a tiled image is fetched, the image data will be tiled by default,
    /// unless a spatial query is used that covers a portion of a tile,
    /// in which case the image is converted to monolithic form prior to
    /// returning to the client.  The client may force a monolithic
    /// image in the former case by setting the DataModel to monolithic
    /// prior to getting the stream reader.  Or conversely it can request
    /// a re-tiling of the remaining sub-image by setting the DataModel
    /// property to tiled (in this case the tile origin is at the new upper
    /// left corner of the sub-image).
    /// \note
    /// Altering the DataModel may have significant performance issues.
    /// 
    FDO_API virtual FdoIStreamReader* GetStreamReader () = 0;

    /// \brief
    /// Gets the Vertical Unit of Measure corresponding to the Raster Band.
    /// The string value returned will be a considered lookup value that
    /// will be used to identify the properties of the Unit of Measure using
    /// the FDO FdoIGetMeasureUnits command.
    ///
    /// \return
    /// Returns the Unit of Measure type of data associated to the Raster Band.
    ///
    FDO_API virtual FdoString* GetVerticalUnits () = 0;

    /// \brief
    /// Sets the Vertical Unit of Measure corresponding to the Raster Band.
    ///
    /// \param units
    /// The Unit of Measure type for the current band.
    /// The units string value corresponds to a Unit of Measure supported
    /// through the FdoIGetMeasureUnits command.
    FDO_API virtual void SetVerticalUnits (FdoString* units) = 0;
};

#endif // _IRASTER_H_



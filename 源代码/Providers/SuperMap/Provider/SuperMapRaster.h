/** \file	 SuperMapRaster.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#ifndef __SUPERMAP_RASTER_H__
#define __SUPERMAP_RASTER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapRaster SuperMapRaster.h
	\brief 用于处理影像数据集，在调用FeatureReader的GetRaster时，返回该类的对象
    return 影像数据的读取是由该类中的GetStreamReader来完成
*/

class SuperMapRaster : public FdoIRaster
{
public:
	SuperMapRaster(UGC::UGDatasetRaster *pDatasetRaster, FdoClassDefinition* ClassDef);

protected:
	virtual void Dispose();

public:
	/// <summary> Gets the number of bands/channels contained in the raster image.</summary>
    /// <returns> Returns the numbers of bands/channels contained in the raster image. < /returns> 
    virtual FdoInt32 GetNumberOfBands ();

    /// <summary> Sets the number of bands/channels contained in the raster image.</summary>
    /// <returns> Returns nothing. </returns> 
    virtual void SetNumberOfBands (FdoInt32 value);

    /// <summary> Gets the currently active band/channel.</summary>
    /// <returns> Returns the current active band/channel. < /returns> 
    /// <remarks> The FdoIRaster Bounds, DataModel, ImageSize, AuxilliaryProperties and Stream 
    /// accessors all conform to the current band. </remarks>
    virtual FdoInt32 GetCurrentBand ();

    /// <summary> Sets the currently active band/channel.</summary>
    /// <returns> Returns nothing. < /returns> 
    /// <remarks> Setting the current band will mean that the Bounds, DataModel, ImageSize, 
    /// AuxilliaryProperties and Stream accessors of FdoIRaster 
    /// will all switch to the specified band. </remarks>
    virtual void SetCurrentBand (FdoInt32 value);


    ///<summary>Returns true if the FdoIRaster represents a null value.</summary>
    /// <returns>Returns true if the FdoIRaster represents a null value.</returns> 
    virtual bool IsNull ();

    ///<summary>Sets the FdoIRaster to a null value.</summary>
    /// <returns>Returns nothing</returns> 
    virtual void SetNull ();

    /// Get the minimum bounding box around the image.
    /// The bounds are transformed to the active spatial context.
    virtual FdoByteArray* GetBounds ();

    /// Set the minimum bounding box around the image.
    /// For georeferenced images, the coordinate system is specified by the
    /// spatial context in force when the object is created.  The act of
    /// setting this property georeferences the image.  In order to provide
    /// for non-georeferenced images, this property is Nullable (doesn't
    /// need to be set).
    virtual void SetBounds (FdoByteArray* bounds);

    /// <summary>Gets the data model in use by this raster property.</summary>
    /// <returns>Returns the current data model.</returns> 
    virtual FdoRasterDataModel* GetDataModel ();

    /// <summary>Sets the data model used by this raster property.
    /// Allowed values are only those data models that are acceptable to the
    /// SupportsDataModel capability.
    /// This attribute specifies the colour/palette model, bits per pixel,
    /// tiling and interleaving. For example, if the bits per pixel of the
    /// data model is 8 and it is set to 24, a conversion would be performed
    /// when image data is requested, to return 24 bit data.  If an update
    /// command is executed to save this value, the raster data would be
    /// transformed and saved.  The next time this image is retrieved
    /// by the client the bits per pixel value would indicate 24.</summary>
    /// <param name="datamodel">The datamodel to be used.</param>
    virtual void SetDataModel (FdoRasterDataModel* datamodel);

    /// <summary>Gets the size of image file in the horizontal
    /// direction in pixels (number of columns).</summary>
    /// <returns>Returns the horizontal image size in pixels
    /// (number of columns).</returns> 
    virtual FdoInt32 GetImageXSize ();

    /// <summary>Sets the size of image file in the horizontal
    /// direction in pixels (number of columns).
    /// By setting the X and Y image size properties prior to getting
    /// a reader for the data, the client application can control the
    /// density of pixels fetched by the provider, which may reduce
    /// the amount of data shipped by the reader and reduce processing
    /// time significantly.  For example, a certain query in the
    /// coordinate system of the raster object class returns a
    /// FdoIRaster object with image size 12091 by 8043.  But the
    /// image only needs to be displayed in an area 1167 by 776 on
    /// the users monitor (note that the aspect ratios are the same
    /// because the query is constructed based on the display area).
    /// By setting the image size to these lower values the FDO raster
    /// subsystem may be able to use a previously subsampled image
    /// where the resolution has been reduced by a factor of 4.
    /// So instead of transferring 97MB, it can transfer 6MB (a reduction
    /// by 4 in both dimensions reduces the amount of data by a factor of 16)
    /// and subsample the image again to the desired resolution in a
    /// more timely manner (less data to process means less total time),
    /// with no appreciable difference in display quality to the user.</summary>
    /// <param name="size">The desired horizontal image size in pixels
    /// (number of columns).</param> 
    virtual void SetImageXSize (FdoInt32 size);

    /// <summary>Gets the size of image file in the vertical
    /// direction in pixels (number of rows).</summary>
    /// <returns>Returns the vertical image size in pixels
    /// (number of rows).</returns> 
    virtual FdoInt32 GetImageYSize ();

    /// <summary>Sets the size of image file in the vertical
    /// direction in pixels (number of rows). See SetImageXSize.</summary>
    /// <param name="size">The desired vertical image size in pixels
    /// (number of rows).</param> 
    virtual void SetImageYSize (FdoInt32 size);

    /// <summary>Get a dictionary style interface to the raster properties.
    /// Through this interface the non-standard properties of a raster
    /// image can be determined and their values can be retrieved and set.
    /// Data values are exchanged through the FdoDataValue object to
    /// accommodate various data types, boolean, integer, double, string,
    /// etc.</summary>
    /// <returns>The dictionary of auxilliary raster properties.</returns> 
    virtual FdoIRasterPropertyDictionary* GetAuxiliaryProperties ();

    /// <summary> Gets the pixel value that represents a NULL value in the available raster stream. </summary>
    /// <returns> Returns the FdoDataType value that can be used to identify the Null value. </returns> 
    /// <remarks> The Null Pixel Value is Data Model dependent. The value of the Null pixel
    /// will change depending on which data model is set. If the client application changes 
    /// the Data Model using SetDataModel(FdoRasterDataModel* datamodel) a subsequent 
    /// call to GetNullPixelValue will need to be made in order to determine the valid Null 
    /// value for the current data model.</remarks>
    virtual FdoDataValue* GetNullPixelValue ();

    /// <summary>Set the source of image data.
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
    /// </summary>
    virtual void SetStreamReader (FdoIStreamReader* reader);

    /// <summary>Get the source of image data.
    /// Image data is shipped using a paradigm similar to BLOB I/O.
    /// When fetching a raster image the GetStreamReader() method provides
    /// a FdoIStreamReader from which the client may request the image data.
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
    /// Note that altering the DataModel may have significant performance issues.
    /// </summary>
    virtual FdoIStreamReader* GetStreamReader ();

    /// \brief
    /// Gets the Vertical Unit of Measure corresponding to the Raster Band.
    /// The string value returned will be a considered lookup value that
    /// will be used to identify the properties of the Unit of Measure using
    /// the FDO FdoIGetMeasureUnits command.
    ///
    /// \return
    /// Returns the Unit of Measure type of data associated to the Raster Band.
    virtual FdoString* GetVerticalUnits ();

    /// \brief
    /// Sets the Vertical Unit of Measure corresponding to the Raster Band.
    ///
    /// \param units
    /// The Unit of Measure type for the current band.
    /// The units string value corresponds to a Unit of Measure supported
    /// through the FdoIGetMeasureUnits command.
    virtual void SetVerticalUnits (FdoString* units);

public:
	~SuperMapRaster(void);

public:
	/*
		\brief 判断给定图像是否是带有调色板信息的图像
		\return bool 是调色板图像返回真，否则返回假
	*/
	bool IsPalletteImage();


private:
	int m_nBandNum;								//波段数, 目前UGC中是不分波段的, 因此先设为1
	int m_nCurBand;								//当前波段, 目前UGC中是不分波段的, 因此先设为1
	bool m_bNull;								//判断该FdoIRaster是否为空
	UGC::UGDatasetRaster *m_pDatasetRaster;		//指向栅格数据集的指针
	FdoPtr<FdoRasterDataModel> m_dataModel;		//指向栅格图像支持的数据模型
	FdoPtr<FdoClassDefinition> m_ClassDef;		//栅格要素类定义
	enum BitsPerPixel							//目前支持的图像像素格式
	{
		GRAYORMONO	= 8,	//单色或灰度图像
		RGB24		= 24,	//RGB图像
		RGBA32		= 32,	//RGBA图像
		TRGB48		= 48,	//TRGB图像
		RGB64		= 64	//LONGLONG图像
	};

};

#endif // __SUPERMAP_RASTER_H__

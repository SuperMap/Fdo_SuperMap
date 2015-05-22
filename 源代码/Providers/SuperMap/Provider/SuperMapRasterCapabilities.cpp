/** \file	 SuperMapRasterCapabilities.cpp
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#include <SuperMap.h>

SuperMapRasterCapabilities::SuperMapRasterCapabilities ()
{
}

SuperMapRasterCapabilities::~SuperMapRasterCapabilities ()
{
}

void SuperMapRasterCapabilities::Dispose()
{
    delete this;
}

/// <summary>Returns true if the provider has raster capability.
/// This implies the capability to define new raster properties on a class
/// and store and retrieve raster images.</summary>
/// <returns>Returns true if raster images are supported, false otherwise.</returns>
bool SuperMapRasterCapabilities::SupportsRaster ()
{
    return (true);
}

/// <summary>Returns true if the provider has the capability to stitch images from a
/// select command (query) together into a single image.</summary>
/// <returns>Returns false if this capability is not supported, and hence the
/// FdoIFeatureReader object returned from a select command will have one feature
/// for each of the FdoIRaster objects that match the select filter.
/// Returns true if this capability is supported. If the MOSAIC function
/// is specified in the select command, then a single image that is a combination
/// of the selected images is returned.</returns>
bool SuperMapRasterCapabilities::SupportsStitching ()
{
    return (false);
}

/// <summary>Returns true if the provider can reduce the resolution of an image.</summary>
/// <returns>Returns true if this capability is supported, and hence the FdoIRaster
/// object returned by the FdoIFeatureReader from a query will honour the
/// SetImageXSize() and SetImageYSize() methods and reduce the resolution of the
/// image by one of several means of subsampling. Returns false if attempting to set
/// the image size of an FdoIRaster object returned by a FdoIFeatureReader will
/// throw an FdoException.</returns>
bool SuperMapRasterCapabilities::SupportsSubsampling ()
{
	return (false);
}

/// <summary>Returns true if the provider can handle the provided data model.
/// It is expected that when used to transform between data models, the matrix defined
/// by input and output data models is not sparse for every data model that is supported.</summary>
/// <param name="model">The model to check for validity with this provider.</param> 
/// <returns>Returns true if the specified data model is supported, and hence the
/// FdoIRaster object will dynamically transform an image to the specified data model.
/// Returns false if the specified data model is not supported.</returns>
bool SuperMapRasterCapabilities::SupportsDataModel (FdoRasterDataModel* model)
{
	TRACE(_T("µ÷ÓÃ SuperMapRasterCapabilities::SupportsDataModel()..."));
      if (model == NULL)
        return false;

    FdoInt32 bpp = model->GetBitsPerPixel();
    int bands;

    switch (model->GetDataModelType())
    {
      case FdoRasterDataModelType_Bitonal:
        return false;  

        
      case FdoRasterDataModelType_Palette:
        if( model->GetDataType() != FdoRasterDataType_UnsignedInteger )
            return false;
        bands = 1;
        break;

      case FdoRasterDataModelType_Gray:
      case FdoRasterDataModelType_Data:
        bands = 1;
        break;

      case FdoRasterDataModelType_RGB:
        bands = 3;
        break;

      case FdoRasterDataModelType_RGBA:
        bands = 4;
        break;
    };
	
    if( model->GetDataType() == FdoRasterDataType_Float )
        return model->GetBitsPerPixel() == 32 * bands 
            || model->GetBitsPerPixel() == 64 * bands;
    else if( model->GetDataType() == FdoRasterDataType_Integer )
        return model->GetBitsPerPixel() == 16 * bands 
            || model->GetBitsPerPixel() == 32 * bands;
    else if( model->GetDataType() == FdoRasterDataType_UnsignedInteger )
        return model->GetBitsPerPixel() == 8 * bands
            || model->GetBitsPerPixel() == 16 * bands 
            || model->GetBitsPerPixel() == 32 * bands;
    else
        return false;

    return false;
}


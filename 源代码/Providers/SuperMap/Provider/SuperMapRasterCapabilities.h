
/** \file	 SuperMapRasterCapabilities.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */

#ifndef __SUPERMAP_RASTERCAPABILITIES_H__
#define __SUPERMAP_RASTERCAPABILITIES_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapRasterCapabilities : public FdoIRasterCapabilities
{
public:
    SuperMapRasterCapabilities ();

protected:
    virtual ~SuperMapRasterCapabilities ();

protected:
    virtual void Dispose ();

public:
    /// <summary>Returns true if the provider has raster capability.
    /// This implies the capability to define new raster properties on a class
    /// and store and retrieve raster images.</summary>
    /// <returns>Returns true if raster images are supported, false otherwise.</returns>
    virtual bool SupportsRaster ();

    /// <summary>Returns true if the provider has the capability to stitch images from a
    /// select command (query) together into a single image.</summary>
    /// <returns>Returns false if this capability is not supported, and hence the
    /// FdoIFeatureReader object returned from a select command will have one feature
    /// for each of the FdoIRaster objects that match the select filter.
    /// Returns true if this capability is supported. If the MOSAIC function
    /// is specified in the select command, then a single image that is a combination
    /// of the selected images is returned.</returns>
    virtual bool SupportsStitching ();

    /// <summary>Returns true if the provider can reduce the resolution of an image.</summary>
    /// <returns>Returns true if this capability is supported, and hence the FdoIRaster
    /// object returned by the FdoIFeatureReader from a query will honour the
    /// SetImageXSize() and SetImageYSize() methods and reduce the resolution of the
    /// image by one of several means of subsampling. Returns false if attempting to set
    /// the image size of an FdoIRaster object returned by a FdoIFeatureReader will
    /// throw an FdoException.</returns>
    virtual bool SupportsSubsampling ();

    /// <summary>Returns true if the provider can handle the provided data model.
    /// It is expected that when used to transform between data models, the matrix defined
    /// by input and output data models is not sparse for every data model that is supported.</summary>
    /// <param name="model">The model to check for validity with this provider.</param> 
    /// <returns>Returns true if the specified data model is supported, and hence the
    /// FdoIRaster object will dynamically transform an image to the specified data model.
    /// Returns false if the specified data model is not supported.</returns>
    virtual bool SupportsDataModel (FdoRasterDataModel* model);
};

#endif // __SUPERMAP_RASTERCAPABILITIES_H__


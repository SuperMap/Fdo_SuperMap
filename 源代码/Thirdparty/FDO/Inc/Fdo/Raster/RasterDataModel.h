#ifndef _RASTERDATAMODEL_H_
#define _RASTERDATAMODEL_H_

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
#include <Fdo/Raster/RasterDataType.h>

/// \brief
/// The FdoRasterDataModel specifies the data type and organization
/// of raster data retrieved and stored. Using this class and the image
/// extents in width and length, the binary format of the image data returned
/// by and accepted by the FdoIStreamReader class can be interpreted.
class FdoRasterDataModel: public FdoIDisposable
{
protected:
    FdoRasterDataModelType m_Type;
    FdoInt32 m_BitsPerPixel;
    FdoRasterDataOrganization m_Organization;
    FdoInt32 m_TileX;
    FdoInt32 m_TileY;
    FdoRasterDataType m_DataType;

    FDO_API FdoRasterDataModel ();
    FDO_API virtual void Dispose ();


public:
    /// \brief
    /// Creates a new datamodel.
    /// 
    /// \return
    /// Returns a bitonal 256x256 tiled data model.
    /// 
    FDO_API static FdoRasterDataModel* Create ();

    /// \brief
    /// Gets the type of data available from this datamodel.
    /// 
    /// \return
    /// Returns the type of data available with this data model.
    /// 
    FDO_API virtual FdoRasterDataModelType GetDataModelType ();

    /// \brief
    /// Sets the type of data for this datamodel.
    /// 
    /// \param type 
    /// The type of data for this data model.
    /// 
    FDO_API virtual void SetDataModelType (FdoRasterDataModelType type);

    /// \brief
    /// Get the number of bits per pixel.
    /// 
    /// \return
    /// Returns the number of bits for each pixel. For multi-channel
    /// data the bits per channel will be this value devided by the numer of
    /// channels. For example, RGB data has three channels, so if this
    /// method returns twelve, each channel is four bits.
    /// 
    FDO_API virtual FdoInt32 GetBitsPerPixel ();

    /// \brief
    /// Set the number of bits per pixel.
    /// 
    /// \param bpp 
    /// The number of bits per pixel desired.
    /// Values of 1, 4, 8, 16, 24, 32, 48 and 64 bits per channel may
    /// be supported. Others values (i.e. indivisible by the number of channels)
    /// are likely to raise a FdoException.
    /// 
    FDO_API virtual void SetBitsPerPixel (FdoInt32 bpp);

    /// \brief
    /// Get the data interleave organization.
    /// 
    /// \return
    /// Returns the way data is interleaved.
    /// 
    FDO_API virtual FdoRasterDataOrganization GetOrganization ();

    /// \brief
    /// Set the data interleave organization.
    /// 
    /// \param organization 
    /// Specifies the way data is to be interleaved.
    /// 
    FDO_API virtual void SetOrganization (FdoRasterDataOrganization organization);

    /// \brief
    /// Get the tile size in the horizontal direction (number of columns).
    /// 
    /// \return
    /// The number of columns in a tile.
    /// 
    FDO_API virtual FdoInt32 GetTileSizeX ();

    /// \brief
    /// Set the tile size in the horizontal direction (number of columns).
    /// 
    /// \param sizex 
    /// The number of columns in a tile.
    /// 
    FDO_API virtual void SetTileSizeX (FdoInt32 sizex);

    /// \brief
    /// Get the tile size in the vertical direction (number of rows).
    /// 
    /// \return
    /// The number of rows in a tile.
    /// 
    FDO_API virtual FdoInt32 GetTileSizeY ();

    /// \brief
    /// Set the tile size in the vertical direction (number of rows).
    /// Values of 64, 128, 256, 512, 1024 and the image extents in width and
    /// length may be supported. When the tile sizes are equal to the image
    /// extents, the image is monolithic. Rectangular tile sizes, combining
    /// different values for X and Y, may be supported.
    /// 
    /// \param sizey 
    /// The number of rows in a tile.
    /// 
    FDO_API virtual void SetTileSizeY (FdoInt32 sizey);

    /// \brief
    /// Gets the data type.
    /// 
    /// \return
    /// Returns the data type of the raster.
    /// 
    FDO_API virtual FdoRasterDataType GetDataType ();

    /// \brief
    /// Sets the data type.
    /// 
    /// \param dataType
    /// Specifies the data type the raster data is to be returned in.
    /// 
    FDO_API virtual void SetDataType (FdoRasterDataType dataType);

    /// \brief
    /// Compares this raster data model with another one.
    /// 
    /// \param pModel
    /// The Raster Data Model to compare with
    /// 
    /// \return
    /// Returns true if this Raster Data Model is the same as pModel
    /// (all members have the same values).
    FDO_API virtual bool Equals (FdoRasterDataModel* pModel);
};

#endif // _RASTERDATAMODEL_H_



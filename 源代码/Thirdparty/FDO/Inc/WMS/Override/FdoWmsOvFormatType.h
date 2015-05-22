//
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


#ifndef FdoWmsOvFormatType_H
#define FdoWmsOvFormatType_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

/// \brief
/// The FdoWmsOvFormatType enumeration defines the list of image formats in which a WMS can be returned from the FDO WMS Provider.
/// <param name="FdoWmsOvFormatType_Png">
/// Portable Network Graphics (PNG).
/// </param>
/// <param name="FdoWmsOvFormatType_Tif">
/// Tagged Image File Format (TIFF).
/// </param>
/// <param name="FdoWmsOvFormatType_Jpg">
/// Joint Photographics Expert Group (JPEG).
/// </param>
/// <param name="FdoWmsOvFormatType_Gif">
/// Graphics Interchange Format (GIF).
/// </param>
enum FdoWmsOvFormatType{

    FdoWmsOvFormatType_Png = 0,
    FdoWmsOvFormatType_Tif,
    FdoWmsOvFormatType_Jpg,
    FdoWmsOvFormatType_Gif
};

#endif // FdoWmsOvFormatType_H



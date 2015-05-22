#ifndef _ISPATIALCONTEXTREADER_H_
#define _ISPATIALCONTEXTREADER_H_
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
//

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>

/// \brief
/// The FdoISpatialContextReader interface provides forward-only, read-only
/// functionality for enumerating spatial contexts. A reference to an
/// FdoISpatialContextReader is returned from the GetSpatialContexts command.
/// The initial position of the FdoISpatialContextReader interface is prior to the
/// first item. Thus, you must call ReadNext to begin accessing any data.
class FdoISpatialContextReader : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the name of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the name of the spatial context.
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Gets the description of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the description of the spatial context.
    /// 
    FDO_API virtual FdoString* GetDescription() = 0;

    /// \brief
    /// Gets the name of the coordinate system of the spatial context currently
    /// being read. If the result is a null or empty string, the coordinate system is
    /// unknown to the spatial context.
    /// 
    /// \return
    /// Returns the coordinate system name of the spatial context.
    /// 
    FDO_API virtual FdoString* GetCoordinateSystem() = 0;

    /// \brief
    /// Gets the name of the coordinate system in OpenGIS SRS WKT format of the spatial context currently
    /// being read. If the result is an empty string, the coordinate system WKT description is
    /// not available.
    /// 
    /// \return
    /// Returns the coordinate system description in WKT of of the spatial context.
    /// 
    FDO_API virtual FdoString* GetCoordinateSystemWkt() = 0;

    /// \brief
    /// Gets the extent type of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the extent type.
    /// 
    FDO_API virtual FdoSpatialContextExtentType GetExtentType() = 0;

    /// \brief
    /// Gets the extent of the spatial context currently being read as a byte
    /// array in FGF format.
    /// 
    /// \return
    /// Returns the extent as a byte array in FGF format.
    /// 
    FDO_API virtual FdoByteArray* GetExtent() = 0;

    /// \brief
    /// Gets the tolerance value for XY ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API virtual const double GetXYTolerance() = 0;

    /// \brief
    /// Gets the tolerance value for Z ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs a frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API virtual const double GetZTolerance() = 0;

    /// \brief
    /// Returns true if the spatial context currently being read is the active
    /// spatial context.
    /// 
    /// \return
    /// Returns true if the current spatial context is the active one.
    /// 
    FDO_API virtual const bool IsActive() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the reader
    /// is prior to the first item. Thus, you must call ReadNext to begin
    /// accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoISpatialContextReader object, freeing any resources it may
    /// be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Dispose() = 0;
};
#endif



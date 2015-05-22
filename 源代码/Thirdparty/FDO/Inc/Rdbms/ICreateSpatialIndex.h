#ifndef _ICREATESPATIALINDEX_H_
#define _ICREATESPATIALINDEX_H_
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

/// <library>
/// FdoRdbms.lib
/// </library>

#ifdef _WIN32
#pragma once
#endif

#include "FdoStd.h"
#include "Fdo/Commands/ICommand.h"
#include "Rdbms/SpatialIndexDimensionType.h"
#include "Rdbms/SpatialIndexType.h"
#include "Fdo/Schema/PropertyDefinition.h"


/// <summary>The ICreateSpatialIndex interface defines the CreateSpatialIndex
/// command, which is spatial indexing the speciified spatial context.
/// Input to the command includes the name, spatial context, special index type,
/// the number of dimensions for the new spatial index.</summary>
class FdoICreateSpatialIndex : public FdoICommand
{

public:
    /// <summary>Gets the name of the Spatial index as a String.</summary>
    /// <returns>Returns the name of the spatial Index </returns>
    FDO_API virtual const wchar_t* GetName() = 0;

    /// <summary>Sets the name of the spatial Index  to create as a String.</summary>
    /// <param name="value">Input the name of the spatial Index </param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetName(const wchar_t* value) = 0;

    /// <summary>Gets the name of the spatial context as a String.</summary>
    /// <returns>Returns the description of the spatial context </returns>
    FDO_API virtual const wchar_t* GetSpatialContextName() = 0;

    /// <summary>Sets the name of the spatial context to create as a String.</summary>
    /// <param name="value">Input the description of the spatial spatial Index </param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetSpatialContextName(const wchar_t* value) = 0;

    /// <summary>Gets the type of the spatial Index, either Quad-Tree or R-Tree.</summary>
    /// <returns>Returns the spatial index type</returns>
    FDO_API virtual SpatialIndexType GetSpatialIndexType() = 0;

    /// <summary>Sets the desired spatial Index  to create, either Quad-Tree or R-Tree.</summary>
    /// <param name="value">Input the index type</param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetSpatialIndexType(SpatialIndexType value) = 0;

    /// <summary>Gets the number of dimensions of the spatial Index.</summary>
    /// <returns>Returns the extent type</returns>
    FDO_API virtual SpatialIndexDimensionType GetNumDimensions() = 0;

    /// <summary>Sets the desired value of the spatial Index dimension.</summary>
    /// <param name="value">Input the index dimension </param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetNumDimensions(SpatialIndexDimensionType value) = 0;

    /// <summary>Sets the geometric property.</summary>
    /// <param name="value">Input the geometric property definition.</param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetGeometricProperty(FdoGeometricPropertyDefinition *value) = 0;

    /// <summary>Gets the geometric property previously set, if any.</summary>
    /// <returns>Returns NULL if not set or a pointer to a geometry property definition</returns>
    FDO_API virtual FdoGeometricPropertyDefinition *GetGeometricProperty() = 0;

    /// <summary>Executes the CreateSpatialIndex command. An exception is thrown if
    /// the spatial index or the spatial context names are not indicated.</summary>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void Execute() = 0;
};
#endif


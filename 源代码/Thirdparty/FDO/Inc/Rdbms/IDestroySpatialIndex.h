#ifndef _IDESTROYSPATIALINDEX_H_
#define _IDESTROYSPATIALINDEX_H_
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
#include "Fdo/Schema/PropertyDefinition.h"
#include "Fdo/Commands/ICommand.h"

/// <summary>The IDestroySpatialIndex interface defines the DestroySpatialIndex
/// command, which drops an existing spatial index. Input to the command is
/// the name of the index to drop. </summary>
class FdoIDestroySpatialIndex : public FdoICommand
{
public:
    /// <summary>Gets the name of the spatial index to destroy as a String.</summary>
    /// <returns>Returns the name of the spatial index to be drop</returns>
    FDO_API virtual const wchar_t* GetName() = 0;

    /// <summary>Sets the name of the spatial index to drop as a String.</summary>
    /// <param name="value">Input the name of the spatial index to be drop</param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetName(const wchar_t* value) = 0;

    /// <summary>Sets the desired value of the geometric property.</summary>
    /// <param name="value">Input the geometric property definition </param>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void SetGeometricProperty(FdoGeometricPropertyDefinition *pGeomProp ) = 0;

    /// <summary>Gets the geometric property previously set, if any.</summary>
    /// <returns>Returns NULL if not set or a pointer to a geometry property definition</returns>
    FDO_API virtual FdoGeometricPropertyDefinition *GetGeometricProperty() = 0;

    /// <summary>Executes the DestroySpatialIndex command dropping the specified
    /// spatial index. An exception is thrown if the spatial index does not exist.</summary>
    /// <returns>Returns nothing</returns>
    FDO_API virtual void Execute() = 0;
};
#endif


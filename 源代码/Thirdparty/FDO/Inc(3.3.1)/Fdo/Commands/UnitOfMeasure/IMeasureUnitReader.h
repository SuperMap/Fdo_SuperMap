#ifndef _IMEASUREUNITREADER_H_
#define _IMEASUREUNITREADER_H_
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
#include <Fdo/Commands/UnitOfMeasure/BaseUnit.h>

/// \brief
/// The FdoIMeasureUnitReader interface provides forward-only, read-only
/// functionality for enumerating measurement units.  A reference to an
/// FdoIMeasureUnitReader interface is returned from the GetMeasureUnits command.
/// The initial position of the FdoIMeasureUnitReader is prior to the
/// first item. Thus, you must call ReadNext to begin accessing any data.
class FdoIMeasureUnitReader : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the abbreviation of the measure unit currently being read.
    /// 
    /// \return
    /// Returns the abbreviation of the measure unit
    /// 
    FDO_API virtual FdoString* GetAbbreviation() = 0;

    /// \brief
    /// Gets the name of the measure unit currently being read.
    /// 
    /// \return
    /// Returns the name of the measure unit
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Gets the description of the measure unit currently being read.
    /// 
    /// \return
    /// Returns the description of the measure unit
    /// 
    FDO_API virtual FdoString* GetDescription() = 0;

    /// \brief
    /// Gets the base unit of the measure unit currently being read.
    /// 
    /// \return
    /// Returns the base unit
    /// 
    FDO_API virtual FdoBaseUnit GetBaseUnit() = 0;

    /// \brief
    /// Gets the scale factor of the measure unit currently being read.
    /// 
    /// \return
    /// Returns the scale factor of the measure unit
    /// 
    FDO_API virtual double GetScaleFactor() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoIMeasureUnitReader object, freeing any resources it may be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;
};
#endif



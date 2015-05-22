#ifndef _BASEUNIT_H_
#define _BASEUNIT_H_
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

/// \ingroup (enums)
/// \brief
///  The FdoBaseUnit enumeration defines the well known base unit used to
/// establish a measure unit.
enum FdoBaseUnit
{
    /// Represents an unspecified base unit, it can be used to create an
    /// unknown or unspecified unit of measure.
    FdoBaseUnit_None,

    /// The base unit for linear, area, and volume measurement units
    /// represented by meters, meters squared, or meters cubed respectively.
    FdoBaseUnit_Meters,

    /// The base unit for the angular measurement units represented by radians.
    FdoBaseUnit_Radians
};
#endif



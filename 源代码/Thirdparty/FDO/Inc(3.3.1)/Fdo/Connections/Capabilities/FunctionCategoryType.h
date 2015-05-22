#ifndef _FUNCTIONCATEGORYTYPE_H_
#define _FUNCTIONCATEGORYTYPE_H_

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
/// The FdoFunctionCategoryType enumeration lists all types a function may
/// be classified in.

enum FdoFunctionCategoryType
{

    /// Represents the identifier used to categorize aggregate functions.
    FdoFunctionCategoryType_Aggregate,

    /// Represents the identifier used to categorize conversion functions.
    FdoFunctionCategoryType_Conversion,

    /// Represents the identifier used to categorize custom functions.
    FdoFunctionCategoryType_Custom,

    /// Represents the identifier used to categorize date functions.
    FdoFunctionCategoryType_Date,

    /// Represents the identifier used to categorize geometry functions.
    FdoFunctionCategoryType_Geometry,

    /// Represents the identifier used to categorize mathematic functions.
    FdoFunctionCategoryType_Math,

    /// Represents the identifier used to categorize numeric functions.
    FdoFunctionCategoryType_Numeric,

    /// Represents the identifier used to categorize string functions.
    FdoFunctionCategoryType_String,

    /// Represents the identifier used to categorize unspecified functions.
    FdoFunctionCategoryType_Unspecified,

};  //  FdoFunctionCategoryType

#endif


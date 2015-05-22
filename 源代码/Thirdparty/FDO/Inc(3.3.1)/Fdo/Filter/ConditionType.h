#ifndef _CONDITIONTYPE_H_
#define _CONDITIONTYPE_H_
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
/// The FdoConditionType enumeration defines the filter condition types available. 
/// This enumeration is used in the capabilities.
enum FdoConditionType
{
    /// Tests if one expression is equal, not equal, greater than, less than, 
    /// greater than or equal to, or less than or equal to another expression.
    FdoConditionType_Comparison,

    /// Tests if the value of a specified data property matches a specified pattern.
    FdoConditionType_Like,

    /// Tests if the value of a specified data property is within a given set 
    /// of literal values.
    FdoConditionType_In,

    /// Tests if the value of a specified data property is null.
    FdoConditionType_Null,

    /// Tests whether the value of a geometric property and a literal geometric 
    /// value satisfy the spatial relationship implied by the operation.
    FdoConditionType_Spatial,

    /// Tests whether the value of a geometric property is within or beyond a 
    /// specified distance of a literal geometric value.
    FdoConditionType_Distance
};
#endif



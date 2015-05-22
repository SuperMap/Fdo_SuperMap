#ifndef _ORDERTYPE_H_
#define _ORDERTYPE_H_

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
/// The FdoOrderType enumeration list contains two values to indicate if the
/// object collection is to be ordered in ascending or descending fashion.
enum FdoOrderType
{
    /// Specifies the collection is to be ordered from the smallest value to the largest value.
    FdoOrderType_Ascending,

    /// Specifies the collection is to be ordered from the largest value to the smallest value.
    FdoOrderType_Descending
};
#endif



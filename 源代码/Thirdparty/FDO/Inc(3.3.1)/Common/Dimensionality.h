#ifndef _DIMENSIONALITY_H_
#define _DIMENSIONALITY_H_

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
#ifdef __cplusplus
    /// \ingroup (enums)
    /// \brief
    ///  FdoDimensionality is an enumeration to describe the presence of spatial dimensions in ordinated data.
    /// 
    /// \remarks
    ///  Values of this enumeration are bit-field definitions.
    /// They can be combined via bitwise OR or separated via bitwise AND.
    /// \remarks
    /// The XY value is zero, thus indicating that all spatial data 
    /// is assumed to carry X and Y dimensions.
    /// 
enum FdoDimensionality
#else
    typedef enum
#endif
{
    /// X and Y dimensions are present.
    FdoDimensionality_XY = 0,
    /// Z dimension is present.
    FdoDimensionality_Z  = 1,
    /// M ('measure') dimension is present.
    FdoDimensionality_M  = 2
#ifdef __cplusplus
};
#else
} FdoDimensionality;
#endif
#endif



#ifndef _ARRAYHELPER_H_
#define _ARRAYHELPER_H_
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

/// \brief
/// Class to do allocations for the FdoArray template.
/// Allocations and freeing must be done in this class in order to 
/// protect against various callers that have overridden
/// the "new" and "delete" operators.
class FdoArrayHelper
{
public:
    /// Metadata for an array. This precedes the actually array data in any allocation.
    struct Metadata
    {
    /// Reference count.
        FdoInt32 refCount;  
    /// Number of bytes used in array data.
        FdoInt32 size;      
    /// Number of bytes allocated for array data.
        FdoInt32 alloc;     
        void SetSizes(FdoInt32 rc, FdoInt32 s, FdoInt32 a) { refCount=rc; size=s; alloc=a; }
    };

    /// Declare generic array and element types.
    /// An array is a single heap allocation whose first bytes are a GenericArray.
    struct GenericArray     
    {
        Metadata m_metadata;
        FdoByte* GetData() { return (m_metadata.alloc<=0) ? 0 : (((FdoByte*)this) + sizeof(Metadata)); }
    };

    FDO_API_COMMON static GenericArray* Append(GenericArray* array, FdoInt32 numElements, FdoByte* elements, FdoInt32 elementSize);

    FDO_API_COMMON static GenericArray* SetSize(GenericArray* array, FdoInt32 numElements, FdoInt32 elementSize);

    FDO_API_COMMON static GenericArray* SetAlloc(GenericArray* array, FdoInt32 numElements, FdoInt32 elementSize);

    FDO_API_COMMON static GenericArray* AllocMore(GenericArray* array, FdoInt32 atLeastThisMuch, bool exactly, FdoInt32 elementSize);

    FDO_API_COMMON static void DisposeOfArray(GenericArray* array, FdoInt32 elementSize);

protected:

    /// Constructor (makes sure that this class cannot be instantiated -- it consists of all static methods.)
    FDO_API_COMMON FdoArrayHelper() {};
};
#endif



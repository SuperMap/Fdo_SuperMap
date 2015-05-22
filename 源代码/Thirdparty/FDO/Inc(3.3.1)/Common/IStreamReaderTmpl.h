#ifndef FDO_ISTREAMREADERTMPL_H
#define FDO_ISTREAMREADERTMPL_H
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

#include <Common/Array.h>
#include <Common/IStreamReader.h>

/// \brief
/// FdoIStreamReaderTmpl reads items from a stream of [T].
template <typename T> class FdoIStreamReaderTmpl : public FdoIStreamReader 
{
public:

    /// \brief
    /// Get the size of a stream.
    /// 
    /// \return
    /// Returns the size of the data source in number of items 
    /// 
    FDO_API_COMMON virtual FdoInt64   GetLength() = 0;   

    /// \brief
    ///  Skips a number of items 
    /// 
    /// \param offset 
    /// Number of items to skip. Must be a positive number
    /// 
    /// \return
    /// Returns nothing 
    /// 
    FDO_API_COMMON virtual void       Skip(const FdoInt32 offset) = 0;  
      
    /// \brief
    ///  Get the current index in the stream 
    /// 
    /// \return
    /// Returns the current index in the stream in number of items 
    /// 
    FDO_API_COMMON virtual FdoInt64   GetIndex() = 0;  

    /// \brief
    ///  Reset the current index in the stream. Allows re-reading 
    /// 
    /// \return
    /// Returns nothing 
    /// 
    FDO_API_COMMON virtual void       Reset() = 0;      
     
    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. 
    /// 
    /// \param buffer 
    /// Buffer holding data read in
    /// \param offset 
    /// Index in the buffer indicating the beginning of the output buffer. 
    /// The caller is responsable for allocating a buffer of a proper size.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached. 
    /// 

    FDO_API_COMMON virtual FdoInt32   ReadNext( T* buffer, 
                                        const FdoInt32 offset = 0,
                                        const FdoInt32 count = -1) = 0;

    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. The caller is responsible to create/dispose the FdoArray. 
    /// 
    /// \param buffer 
    /// FdoArray object holding data read in. Cannot be NULL
    /// \param offset 
    /// Index in the array indicating the beginning of the output buffer. 
    /// If the end of the buffer, then read in appending mode (store at the end). 
    /// Otherwise, overwrite the buffer. Throws "invalid parameter" exception if not in this range.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns number of items read.
    /// 
    FDO_API_COMMON virtual FdoInt32    ReadNext(  FdoArray<T> * &buffer, 
                                            const FdoInt32 offset = 0,
                                            const FdoInt32 count = -1 ) = 0; 
};
 
#endif



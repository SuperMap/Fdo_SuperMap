#ifndef FDO_IO_OBJECTSTREAMREADER_H
#define FDO_IO_OBJECTSTREAMREADER_H
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

#include <FdoCommon.h>
#include <Common/IStreamReaderTmpl.h>

/// \brief
/// FdoIoObjectStreamReader is the template for all
/// readers on FdoIoStream. Readers for various sized objects
/// or primitive types can be based on this class.
template <typename T> class FdoIoObjectStreamReader : public FdoIStreamReaderTmpl<T> 
{
public:
    /// \brief
    /// Gets the stream length
    /// 
    /// \return
    /// Returns the size of the data source in number of items 
    /// 
    FDO_API_COMMON virtual FdoInt64   GetLength()
    {
        FdoInt64 byteCount = mStream->GetLength();

    /// Return the number of objects (floor if #bytes/object size)
    /// Partial objects at end of stream are ignored.
        return( byteCount / sizeof(T) );
    }

 
    /// \brief
    /// Skips a number of items
    /// 
    /// \param offset 
    /// Input number of items to skip
    /// 
    FDO_API_COMMON virtual void       Skip(const FdoInt32 offset)
    {
        mStream->Skip( offset * sizeof(T) );
    }
  
    /// \brief
    /// Gets the current stream position. Position is 
    /// measured by number of items from the stream start
    /// 
    /// \return
    /// Returns the current index in the stream
    /// 
    FDO_API_COMMON virtual FdoInt64   GetIndex()
    {
        FdoInt64 byteIndex = mStream->GetIndex();

        if ( (byteIndex % sizeof(T)) != 0 )
            throw FdoException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_36_STREAMINDEXALIGN),
                    "%1$s: Current byte position %2$d does not align with size of item being read ($3$d)",
                    "FdoIoObjectStreamReader::GetIndex",
                    byteIndex,
                    sizeof(T)
                )
            );

        return( byteIndex / sizeof(T) );
    }


    /// \brief
    /// Reset the current index to the stream start. Allows re-reading.
    /// 
    FDO_API_COMMON virtual void       Reset()
    {
        mStream->Reset();
    }

    /// \brief
    /// Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. The caller is responsible to allocate a buffer large 
    /// enough to store data.
    /// 
    /// \param buffer 
    /// Output array holding data read in.
    /// \param offset 
    /// Input index in the array indicating the beginning of the output buffer. 
    /// If zero, then the buffer is reused. If the end of the buffer, then read in 
    /// appending mode. Throws "out-of-bounds" exception if not in this range.
    /// \param count 
    /// Input number of items to be read in. If -1 read the entire stream.
    /// Throws "out-of-bounds"  exception if not a positive value or -1.
    /// 
    /// \return
    /// Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached.
    /// 
    FDO_API_COMMON virtual FdoInt32   ReadNext( T* buffer, 
                                      const FdoInt32 offset = 0,
                                      const FdoInt32 count = -1)
    {
        FdoInt32 objectsRead = 0;
        FdoInt32 totalObjectsRead = 0;
        FdoInt32 bytesRead = 0;

		if ( offset < 0 ) 
            throw FdoException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)
                )
            );

		if ( count < -1 ) 
            throw FdoException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)
                )
            );

        if ( count == -1 ) {
            for ( ; ; ) {
                objectsRead = ReadNext( buffer, offset + totalObjectsRead, mBlockSize );
                if ( objectsRead == 0 )
                    break;
                totalObjectsRead += objectsRead;
            }

            return(totalObjectsRead);
        }
        else {
            FdoInt32 lCount = count;

    /// If the stream provides context information then calculate
    /// how many items are left to read.
            if ( mStream->HasContext() ) {
                FdoInt64 length = GetLength();

                if ( length > -1 ) {
                    FdoInt64 pos = GetIndex();
                    FdoInt64 remaining = ( length - pos ) / sizeof(T);
    /// Items that will be read is lessor of items to read
    /// and items remaining. This ensures that we don't
    /// read any partial item at the end of the stream.
                    lCount = lCount < remaining ? lCount : (FdoInt32) remaining;
                }
            }

            bytesRead =  (FdoInt32) mStream->Read( &buffer[offset], lCount * sizeof(T));

            return( bytesRead / sizeof(T) );
        }
    }
    /// \param buffer 
    /// Output array holding data read in.
    /// \param offset 
    /// Input index in the array indicating the beginning of the output buffer. 
    /// If zero, then the buffer is reused. If the end of the buffer, then read in 
    /// appending mode. Throws "out-of-bounds" exception if not in this range.
    /// \param count 
    /// Input number of items to be read in. If -1 read the entire stream.
    /// Throws "out-of-bounds"  exception if not a positive value or -1.
    /// 
    /// \return
    /// Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached.
    /// 
    
    /// \brief
    /// Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. The caller is responsible to create/dispose the FdoArray.
    /// 
    /// \param buffer 
    /// Input array holding data read in.
    /// \param offset 
    /// Input index in the array indicating the beginning of the output buffer. 
    /// If zero, then the buffer is reused. If the end of the buffer, then read in 
    /// appending mode. Throws "out-of-bounds" exception if not in this range.
    /// \param count 
    /// Input number of items to be read in. If -1 read the entire stream.
    /// Throws "out-of-bounds"  exception if not a positive value or -1.
    /// 
    /// \return
    /// Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached.
    /// 
    FDO_API_COMMON virtual FdoInt32       ReadNext(  FdoArray<T> * &buffer, 
                                        const FdoInt32 offset = 0,
                                        const FdoInt32 count = -1 )
    {
        FdoInt32 lCount = count;

        FdoInt32 lCount2 = 0;
        FdoInt64 byteRemaining = 0;
        FdoInt64 remaining = 0;

		if ( offset < 0 ) 
            throw FdoException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)
                )
            );

		if ( count < -1 ) 
            throw FdoException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)
                )
            );

        if ( count == -1 ) {
            byteRemaining = mStream->GetLength() - mStream->GetIndex();
            remaining = byteRemaining / sizeof(T);

            if ( remaining > LONG_MAX ) 
				throw FdoException::Create(
					FdoException::NLSGetMessage(
						FDO_NLSID(FDO_46_REMAININGSTREAMSIZE),
						"%1$s: Cannot read remainder of stream, there are more than %$2d items remaining.",
						"FdoIoObjectStreamReader::ReadNext(FdoArray<T>,FdoInt32,FdoInt32)",
						LONG_MAX
					)
				);

            lCount = (FdoInt32) remaining;
        }
        T* tmpBuffer = buffer->GetData();

        lCount2 = ReadNext( tmpBuffer, offset, lCount );

		return(lCount2);
    }

protected:
/// \cond DOXYGEN-IGNORE
    FdoIoObjectStreamReader() {}

    FdoIoObjectStreamReader( FdoIoStream* stream ) 
    {
        FDO_SAFE_ADDREF(stream);
        mStream = stream;
    }

    ~FdoIoObjectStreamReader()
    {
    }
/// \endcond

private:
    FdoIoStreamP mStream;
    static const FdoInt32 mBlockSize = 4096;
};

#endif



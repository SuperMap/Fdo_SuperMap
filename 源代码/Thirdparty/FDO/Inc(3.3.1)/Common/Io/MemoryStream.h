#ifndef FDO_IO_MEMORYSTREAM_H
#define FDO_IO_MEMORYSTREAM_H
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

#include <Common/Io/Stream.h>
#include <Common/Collection.h>
#include <Common/Io/BufferStream.h>

/// \brief
/// FdoIoMemoryStream provides streamed I/O to and from memory.
class FdoIoMemoryStream :
    public FdoIoStream
{
public:
    /// \brief
    /// creates the memory stream. The stream manages its own storage.
    /// 
    /// \param bufferSize 
    /// Input memory allocation increment. Amount of new memory to 
    /// allocated when the stream needs more memory.
    /// 
    /// \return
    /// Returns the created memory stream.
    /// 
    FDO_API_COMMON static FdoIoMemoryStream* Create( FdoSize bufferSize = 4096 );

   	FDO_API_COMMON virtual FdoSize Read( FdoByte* buffer, FdoSize count );
	FDO_API_COMMON virtual void Write( FdoByte* buffer, FdoSize count );
	FDO_API_COMMON virtual void Write( FdoIoStream* stream, FdoSize count = 0 );
	FDO_API_COMMON virtual void SetLength( FdoInt64 length );
    FDO_API_COMMON virtual FdoInt64 GetLength() {
        return( mLength );
    }

    FDO_API_COMMON virtual FdoInt64 GetIndex()
    {
        return(mPos);
    }

   	FDO_API_COMMON virtual void Skip( FdoInt64 offset );
	FDO_API_COMMON virtual void Reset();

protected:
/// \cond DOXYGEN-IGNORE
    FdoIoMemoryStream(FdoSize bufferSize = 4096);
    virtual ~FdoIoMemoryStream(void);
    void GetBufPosn( FdoSize& bufNum, FdoSize& bufOffset );
/// \endcond

private:
    /// Buffer collection class
    class Buffers : public FdoCollection<FdoIoBufferStream,FdoException>
    {
    public:
        static Buffers* Create() {return new Buffers();}

    protected:
        Buffers() {}
        ~Buffers() {}
        virtual void Dispose()
        {
            delete this;
        }

    };

    /// Collection of buffers where stream contents are stored.
    FdoPtr<Buffers> mBuffers;
    /// Buffer size
    FdoSize mBufferSize;
    /// Stream length
    FdoInt64 mLength;
    /// Current stream position
    FdoInt64 mPos;

};

/// \ingroup (typedefs)
/// \brief
/// FdoIoMemoryStreamP is a FdoPtr on FdoIoMemoryStream, provided for convenience.
typedef FdoPtr<FdoIoMemoryStream> FdoIoMemoryStreamP;

#endif



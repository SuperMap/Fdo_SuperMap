#ifndef FDO_IO_BUFFERSTREAM_H
#define FDO_IO_BUFFERSTREAM_H
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

/// \cond DOXYGEN-IGNORE
// This class is not yet exposed to the API.
// It provides streamed I/O against a simple array of bytes.
class FdoIoBufferStream :
    public FdoIoStream
{
public:
    /// Creates a stream around the given buffer. 
    static FdoIoBufferStream* Create( FdoByte* buffer, FdoSize size );
    /// Creates a new buffer of the given size and wraps a stream around it. 
    static FdoIoBufferStream* Create( FdoSize size );

    /// FdoIoStream implementations
   	virtual FdoSize Read( FdoByte* buffer, FdoSize count );
	virtual void Write( FdoByte* buffer, FdoSize count );
	virtual void Write( FdoIoStream* stream, FdoSize count = 0 );
	virtual void SetLength( FdoInt64 length );

    virtual FdoInt64 GetLength() {
        return( mLength);
    }

    virtual FdoInt64 GetIndex()
    {
        return mPos;
    }

   	virtual void Skip( FdoInt64 offset );
	virtual void Reset();

protected:
    FdoIoBufferStream( FdoByte* buffer, FdoSize size );
    FdoIoBufferStream( FdoSize size = 4096 );
    virtual ~FdoIoBufferStream(void);

private:
    /// the buffer.
    FdoByte* mpBuffer;
    /// true if the buffer was allocated by this stream.
    /// false if the stream is attached to an existing buffer.
    FdoBoolean mbMyBuffer;
    /// Total size of the buffer
    FdoSize mSize;
    /// Total length of the stream
    FdoSize mLength;
    /// Current stream position.
    FdoSize mPos;

};

typedef FdoPtr<FdoIoBufferStream> FdoIoBufferStreamP;
/// \endcond

#endif



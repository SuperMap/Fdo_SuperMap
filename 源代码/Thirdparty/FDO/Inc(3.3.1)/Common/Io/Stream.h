#ifndef FDO_IO_STREAM_H
#define FDO_IO_STREAM_H
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

/// \brief
/// FdoIoStream defines the interface for all FDO streams. Streamed I/O support
/// for various locations, such as files, memory, etc. can be provided by classes
/// that implement this interface.
/// \note
/// There is no function provided to close a FdoIoStream. The only way
/// to close it is to destroy it by releasing all references.
class FdoIoStream : public FdoDisposable
{
public:
    /// \brief
    /// reads the number of bytes indicated by count into the given buffer, 
    /// or the number of bytes after the current stream position, whichever is less. 
    /// The stream’s current position is moved ahead by the number of bytes read.
    /// 
    /// \param buffer 
    /// Output read into this buffer
    /// \param count 
    /// Input read this number of bytes into the buffer.
    /// The caller is responsible for allocating a buffer that is large enough to hold the bytes.
    /// 
    /// \return
    /// Returns the number of bytes that were read. 0 if already at the
    /// end of the stream.
    /// 
    FDO_API_COMMON virtual FdoSize Read( FdoByte* buffer, FdoSize count ) = 0;

    /// \brief
    /// writes the number of bytes indicated by count, from the given buffer, 
    /// to the stream. The current position is moved ahead by the number of bytes 
    /// written.
    /// 
    /// \param buffer 
    /// Intput write from this buffer
    /// \param count 
    /// Input number of bytes to write
    /// 
    /// \note
	/// Write will overwrite some of the contents of the stream 
    /// if the current position is not at the end of the stream.
	FDO_API_COMMON virtual void Write( FdoByte* buffer, FdoSize count ) = 0;

    /// \brief
    /// reads the number of bytes from the given stream, and writes them 
    /// to this stream. 
    /// 
    /// \param stream 
    /// Input write from this buffer
    /// \param count 
    /// Input the maximum number of bytes to read and write. 
    /// When 0, all remaining bytes are read from the given stream.
    /// 
	FDO_API_COMMON virtual void Write( FdoIoStream* stream, FdoSize count = 0 ) = 0;

    /// \brief
    /// truncates the stream to the indicated length.
    /// 
    /// \param length 
    /// Input the new length (in bytes) for the stream. If this is 
    /// longer than the current stream length then the stream's length
    /// is not changed.
    /// 
	FDO_API_COMMON virtual void SetLength( FdoInt64 length) = 0;

    /// \brief
    /// gets the current length of the stream.
    /// 
    /// \return
    /// Returns the length in bytes. Returns -1 if the length is unknown
    /// or undefined.
    /// 
    FDO_API_COMMON virtual FdoInt64 GetLength() = 0;

    /// \brief
    /// gets the current position for the stream.
    /// 
    /// \return
    /// Returns the position in bytes from the start. When 0, the 
    /// the position is at the start of the stream. When GetIndex() ==
    /// GetLength() the position is at the end of the stream.
    /// 
    FDO_API_COMMON virtual FdoInt64 GetIndex() = 0;

    /// \brief
    /// skips over part of the stream.
    /// 
    /// \param offset 
    /// The number of bytes to skip. if position then 
    /// the current position is moved forward. If negative, the position is
    /// moved backward. The position will remain between the start and end 
    /// of the stream. The position is set to the end of the stream if the 
    /// given offset would put it past the end. Similarily, the position is 
    /// set to the start if the offset would put it before the start.
    /// 
	FDO_API_COMMON virtual void Skip( FdoInt64 offset ) = 0;

    /// \brief
    /// sets the position to the start of the stream.
    /// 
	FDO_API_COMMON virtual void Reset() = 0;

    /// \brief
    /// gets the reading capability.
    /// 
    /// \return
    /// Returns true if the stream can be read.
    /// 
    FDO_API_COMMON virtual FdoBoolean CanRead()
    {
        return true;
    }

    /// \brief
    /// gets the writing capability.
    /// 
    /// \return
    /// Returns true if the stream can be written to.
    /// 
	FDO_API_COMMON virtual FdoBoolean CanWrite()
    {
        return true;
    }

    /// \brief
    /// returns whether the stream has any positional context.
    /// Streams without context can only be read and written in a forward-only
    /// manner. These streams do not allow position and length changes.
    /// 
    /// \return
    /// Returns true if the stream has context. Returns false if it does 
    /// not. When a stream does not have context, the SetLength(), Skip() and 
    /// Reset() functions are not supported.
    /// 
	FDO_API_COMMON virtual FdoBoolean HasContext()
    {
        return true;
    }

protected:
};

/// \ingroup (typedefs)
/// \brief
/// FdoIoStreamP is a FdoPtr on FdoIoStream, provided for convenience.
typedef FdoPtr<FdoIoStream> FdoIoStreamP;

#endif



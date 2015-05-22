#ifndef FDO_IO_FILESTREAM_H
#define FDO_IO_FILESTREAM_H
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

/// \brief
/// FdoIoFileStream provides streamed I/O on a disk file.
class FdoIoFileStream :
    public FdoIoStream
{
public:
    /// \brief
    /// creates the stream for a named file.
    /// 
    /// \param fileName 
    /// Input the file name
    /// \param accessModes 
    /// Input File access modes. Same as the fopen() C run-time library function
    /// (mode parameter).
    /// 
    /// \return
    /// Returns the created file stream.
    /// 
    static FDO_API_COMMON FdoIoFileStream* Create(FdoString* fileName, FdoString* accessModes );

    /// \brief
    /// creates the stream around a C Runtime file stream.
    /// 
    /// \param fp 
    /// Input the file stream pointer.
    /// 
    /// \return
    /// Returns the created file stream.
    /// 
    FDO_API_COMMON static FdoIoFileStream* Create(FILE* fp);

    FDO_API_COMMON virtual FdoSize Read( FdoByte* buffer, FdoSize count );
	FDO_API_COMMON virtual void Write( FdoByte* buffer, FdoSize count );
	FDO_API_COMMON virtual void Write( FdoIoStream* stream, FdoSize count = 0 );
	FDO_API_COMMON virtual void SetLength( FdoInt64 length );
    FDO_API_COMMON virtual FdoInt64 GetLength();
    FDO_API_COMMON virtual FdoInt64 GetIndex();
   	FDO_API_COMMON virtual void Skip( FdoInt64 offset );
	FDO_API_COMMON virtual void Reset();

    FDO_API_COMMON virtual FdoBoolean CanRead();
	FDO_API_COMMON virtual FdoBoolean CanWrite();
	FDO_API_COMMON virtual FdoBoolean HasContext();
	
/// \cond DOXYGEN-IGNORE
protected:
    /// Default constructor to satisfy Linux
    FdoIoFileStream() {}
    FdoIoFileStream(FdoString* fileName, FdoString* accessModes );
    FdoIoFileStream(FILE* fp);
    virtual ~FdoIoFileStream(void);

    int GetFd()
    {
        return mFd;
    }

    /// Sets up the canRead and canWrite flags.
    void InitFileStatus();

    /// Throw exception if this stream has no context.
    /// Context is lost when the file size exceeds MAX_LONG.
    void CheckContext( FdoString* caller );

    /// Buffer size for writing from another stream.
    static const size_t mBufferSize = 1024;
/// \endcond

private:
    FILE*         mFp;
    int           mFd;
    FdoBoolean    mbMyFp;
    FdoBoolean    mbCanRead;
    FdoBoolean    mbCanWrite;
    FdoBoolean    mbHasContext;
    FdoBoolean    mbTextMode;
};

/// \ingroup (typedefs)
/// \brief
/// FdoIoFileStreamP is a FdoPtr on FdoIoFileStream, provided for convenience.
typedef FdoPtr<FdoIoFileStream> FdoIoFileStreamP;

#endif



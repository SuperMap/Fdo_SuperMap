#ifndef FDO_IO_TEXTREADER_H
#define FDO_IO_TEXTREADER_H
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
/// FdoIoTextReader reads from a binary stream containing UTF8 characters.
/// It formats these UTF8 characters into Unicode wide characters. This class is 
/// not yet complete, since the Read functions still have to be added.
class FdoIoTextReader : public FdoDisposable
{
public:
    /// \brief
    /// Constructs a text reader on a file
    /// 
    /// \param fileName 
    /// Input name of the file to read.
    /// 
    /// \return
    /// Returns FdoIoTextReader
    /// 
    FDO_API_COMMON static FdoIoTextReader* Create( FdoString* fileName );

    /// \brief
    /// Constructs a text reader on a stream
    /// 
    /// \param stream 
    /// Input the stream to read.
    /// 
    /// \return
    /// Returns FdoIoTextReader
    /// 
    FDO_API_COMMON static FdoIoTextReader* Create( FdoIoStream* stream );

    /// \brief
    /// Gets the underlying stream. If a stream was passed to this object
    /// then this stream is returned.
    /// Otherwise, an auto-generated stream (wrapped around the  file name 
    /// that was passed to this object) is returned.
    /// 
    /// \return
    /// Returns the underlying stream.
    /// 
    FDO_API_COMMON FdoIoStream* GetStream();

protected:
/// \cond DOXYGEN-IGNORE
    FdoIoTextReader() {}
    FdoIoTextReader( FdoIoStream* stream );
    virtual ~FdoIoTextReader(void);
/// \endcond

private:
    /// the underlying stream.
    FdoIoStreamP mStream;
};

/// \ingroup (typedefs)
/// \brief
/// FdoIoTextReaderP is a FdoPtr on FdoIoTextReader, provided for convenience.
typedef FdoPtr<FdoIoTextReader> FdoIoTextReaderP;

#endif



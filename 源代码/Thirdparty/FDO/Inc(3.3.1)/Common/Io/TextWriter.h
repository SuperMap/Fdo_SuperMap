#ifndef FDO_IO_TEXTWRITER_H
#define FDO_IO_TEXTWRITER_H
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
/// FdoIoTextWriter writes Unicode wide character text to a binary stream.
/// The text is written in UTF8 format.
class FdoIoTextWriter : public FdoDisposable
{
public:
    /// \brief
    /// Constructs a text writer on a file.
    /// 
    /// \param fileName 
    /// Input name of the file to write to. The file is created
    /// if it does not yet exist. If it already exists, its previous contents are 
    /// completely overwritten.
    /// 
    /// \return
    /// Returns FdoIoTextWriter
    /// 
    FDO_API_COMMON static FdoIoTextWriter* Create( FdoString* fileName );

    /// \brief
    /// Constructs a text writer on a stream.
    /// 
    /// \param stream 
    /// Input the stream to write to. Writing starts at the 
    /// stream's current position.
    /// 
    /// \return
    /// Returns FdoIoTextWriter
    /// 
    FDO_API_COMMON static FdoIoTextWriter* Create( FdoIoStream* stream );
    
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

    /// \brief
    /// Writes to this text writer. The text is written in UTF8 format.
    /// 
    /// \param string 
    /// The text to write.
    /// 
    FDO_API_COMMON void Write( FdoString* string );

    /// \brief
    /// Same as Write(), except that a carriage return (n) is appended to
    /// the text.
    /// 
    /// \param string 
    /// The text to write.
    /// 
    FDO_API_COMMON void WriteLine( FdoString* string );

protected:
/// \cond DOXYGEN-IGNORE
    FdoIoTextWriter() {}
    FdoIoTextWriter( FdoIoStream* stream );
    virtual ~FdoIoTextWriter(void);
/// \endcond

private:
    /// The underlying stream.
    FdoIoStreamP mStream;
};

/// \ingroup (typedefs)
/// \brief
/// FdoIoTextWriterP is a FdoPtr on FdoIoTextWriter, provided for convenience.
typedef FdoPtr<FdoIoTextWriter> FdoIoTextWriterP;

#endif



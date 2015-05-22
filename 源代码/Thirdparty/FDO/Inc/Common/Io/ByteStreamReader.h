#ifndef FDO_IO_BYTESTREAMREADER_H
#define FDO_IO_BYTESTREAMREADER_H
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
#include <Common/Io/ObjectStreamReader.h>

/// \brief
/// FdoIoObjectStreamReader is the template for all
/// readers on FdoIoStream. Readers for various sized objects
/// or primitive types can be based on this class.
class FdoIoByteStreamReader : public FdoIoObjectStreamReader<FdoByte> 
{
public:

    /// \brief
    /// Creates a Byte Stream reader. Reads binary data from
    /// a FdoIoStream
    /// 
    /// \param stream 
    /// Input the stream to read from
    /// 
    /// \return
    /// Returns FdoIoByteStreamReader
    /// 
    FDO_API_COMMON static FdoIoByteStreamReader* Create( FdoIoStream* stream );
	
    /// \return
    /// Returns FdoStreamReaderType_Byte
    /// 
	FDO_API_COMMON virtual FdoStreamReaderType GetType();

protected:
/// \cond DOXYGEN-IGNORE
    FdoIoByteStreamReader();
    FdoIoByteStreamReader( FdoIoStream* stream );
/// \endcond

    FDO_API_COMMON virtual void Dispose();

};

/// \ingroup (typedefs)
/// \brief
/// FdoIoByteStreamReaderP is a FdoPtr on FdoIoByteStreamReader, provided for convenience.
typedef FdoPtr<FdoIoByteStreamReader> FdoIoByteStreamReaderP;

#endif



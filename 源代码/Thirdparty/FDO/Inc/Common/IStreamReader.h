#ifndef _ISTREAMREADER_H_
#define _ISTREAMREADER_H_
// 

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or</a>
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

#include <Common/Std.h>

/// \ingroup (enums)
/// \brief
/// Enumeration for datatypes used by stream readers.
enum FdoStreamReaderType {
        FdoStreamReaderType_Byte,
        FdoStreamReaderType_Char,
        FdoStreamReaderType_WChar
};


/// \brief
/// The FdoIStreamReader class is a top level interface for stream reader classes. 
/// The API it provides allows the user to read large streams of data in blocks of items. 
class FdoIStreamReader : public FdoIDisposable
{
public:
    /// \return
    /// /// Returns the Stream reader type
   /// 
   FDO_API_COMMON virtual FdoStreamReaderType GetType() = 0;
};

#endif



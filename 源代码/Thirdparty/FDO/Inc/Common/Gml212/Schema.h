#ifndef FDO_GML212_SCHEMA_H
#define FDO_GML212_SCHEMA_H
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
#include <Common/Stack.h>

/// \brief
/// FdoGml212Schema is a utility class for handling the GML 2.1.2 
/// version of the GML Schema.
class FdoGml212Schema 
{
public:
    /// \brief
    /// Constructs an GML 2.1.2 schema reader. This reader reads
    /// an XML document containing the GML 2.1.2 and Xlinks schemas.
    /// 
    /// \return
    /// Returns FdoXmlReader
    /// 
    FDO_API_COMMON static FdoXmlReader* CreateReader();
};

#endif



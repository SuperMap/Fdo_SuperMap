#ifndef FDO_XML_SPATIALCONTEXTSERIALIZER_H
#define FDO_XML_SPATIALCONTEXTSERIALIZER_H

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

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Xml/SpatialContextReader.h>
#include <Fdo/Xml/SpatialContextWriter.h>
#include <Fdo/Connections/IConnection.h>

/// \brief
/// This static class provides the ability to serialize and deserialize spatial contexts
/// to and from GML.
class FdoXmlSpatialContextSerializer
{
public:
    /// \brief
    /// reads all Spatial Contexts from an XML document to an FDO 
    /// connection.
    /// 
    /// \param connection 
    /// Input the FDO connection.
    /// \param reader 
    /// Input XML document reader.
    /// \param flags 
    /// Input options for controlling the 
    /// deserializing of the Spatial Contexts. If NULL then the 
    /// default flags are used.
    /// 
    FDO_API static void XmlDeserialize( 
		FdoIConnection*                 connection, 
		FdoXmlSpatialContextReader*     reader,
    	FdoXmlSpatialContextFlags*      flags = NULL
	);

    /// \brief
    /// writes all Spatial Contexts from the FDO connection to 
    /// an XML document.
    /// 
    /// \param connection 
    /// Input the FDO connection.
    /// \param writer 
    /// Input XML document writer.
    /// \param flags 
    /// Input options for controlling the 
    /// serializing of the Spatial Contexts. If NULL then the 
    /// default flags are used.
    /// 
    FDO_API static void XmlSerialize( 
		FdoIConnection*                 connection, 
		FdoXmlSpatialContextWriter*     writer,
    	FdoXmlSpatialContextFlags*      flags = NULL
	);

};

#endif



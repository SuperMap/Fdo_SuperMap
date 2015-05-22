#ifndef FDO_XML_FEATURESERIALIZER_H_
#define FDO_XML_FEATURESERIALIZER_H_

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

class FdoXmlFeatureWriter;
class FdoXmlFeatureFlags;

/// \brief
/// This static class provides the ability to serialize and deserialize features
/// to and from GML.
class FdoXmlFeatureSerializer
{
public:

    /// \brief
    /// writes the features retrieved by a feature reader to 
    /// an XML document.
    /// 
    /// \param reader 
    /// Input the Feature Reader.
    /// \param writer 
    /// Input XML document writer. By default, the features written are wrapped in a 
    /// GML FeatureCollection element. This behaviour can be changed by setting 
    /// flags->writeCollection. The name of the collection element can also be 
    /// customized by setting flags->collectionUri and flags->collectionName.
    /// \param flags 
    /// Input options for controlling the serializing of the features. If NULL then the 
    /// flags passed to the document writer are used.
    /// 
    FDO_API static void XmlSerialize( 
		FdoIFeatureReader*              reader, 
		FdoXmlFeatureWriter*            writer,
    	FdoXmlFeatureFlags*             flags = NULL
	);

};



#endif



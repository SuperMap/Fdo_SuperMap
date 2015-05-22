#ifndef FDO_XML_FEATUREREADER_H_
#define FDO_XML_FEATUREREADER_H_

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
#include <Fdo/Xml/FeatureHandler.h>

class FdoXmlFeatureFlags;
class FdoXmlFeaturePropertyReader;


/// \brief
/// FdoXmlFeatureReader reads GML format features from a XML
/// document. The reading is done procedurally, rather than through events.
/// Each feature can be read in 3 steps:
/// <ol>
/// 	<li> call ReadNext() to get the next feature.
/// 	<li> call GetClassDefinition() to get the current feature's property list.
/// 	<li> call GetProperty() for each feature property to retrieve.
/// </ol>
/// This class allows random access to the properties of the current feature, meaning that 
/// ReadNext() accumulates a list of these properties. This may have slight performance implications.
/// If performance is a concern then FdoXmlFeaturePropertyReader should be used instead.
class FdoXmlFeatureReader : 
	public FdoIFeatureReader,
	public FdoXmlFeatureHandler
{
public:

    /// \brief
    /// creates a Feature Reader for reading features from XML.
    /// 
    /// \param reader 
    /// Input XML document reader. Please refer to the reader parameter of 
    /// FdoXmlFeaturePropertyReader::Create() for a description of how the features are
    /// read from the document. An FdoXmlFeaturePropertyReader is automatically wrapped 
    /// around this reader. This Feature Property Reader can be retrieved by calling 
    /// GetFeaturePropertyReader().
    /// \param flags 
    /// Input options for controlling the 
    /// deserializing of the features. If NULL then the 
    /// default flags are used.
    /// 
    /// \return
    /// Returns FdoXmlFeatureReader
    /// 
	FDO_API static FdoXmlFeatureReader * Create( 
		FdoXmlReader*                   reader,
    	FdoXmlFeatureFlags*      flags = NULL
		);

    /// \brief
    /// Gets the feature property reader that was passed to this object.
    /// 
    /// \return
    /// Returns FdoXmlFeaturePropertyReader
    /// 
    FDO_API virtual FdoXmlFeaturePropertyReader* GetFeaturePropertyReader() = 0;


    /// \brief
    /// Gets the feature schemas describing the features being read.
    /// 
    /// \return
    /// Returns FdoFeatureSchemaCollection
    /// 
    FDO_API virtual FdoFeatureSchemaCollection* GetFeatureSchemas() = 0;

    /// \brief
    /// Sets the feature schemas describing the features being read. 
    /// 
    /// \remarks
    /// The feature schemas
    /// provide directions on how to deserialize the features and convert their property
    /// values from the strings in the XML document to their proper types. If any 
    /// feature, whose class definition is not present in these schemas, is encountered 
    /// then one of the following is done:
    /// <ul>
    /// 	<li> an exception is thrown when flags->errorLevel is Normal or higher. The 
    ///       exception reports all such features.
    /// 	<li> these features are silently skipped When the flags->errorLevel is below 
    ///       Normal.
    /// </ul>
    /// 
    /// \param schemas 
    /// Input the feature schemas
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureSchemas(FdoFeatureSchemaCollection* schemas) = 0;

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFeatureReaderP is a FdoPtr on FdoXmlFeatureReader, provided for convenience.
typedef FdoPtr<FdoXmlFeatureReader> FdoXmlFeatureReaderP;

#endif



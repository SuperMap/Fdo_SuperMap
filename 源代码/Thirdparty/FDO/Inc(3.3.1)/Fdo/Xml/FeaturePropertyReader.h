#ifndef FDO_XML_FEATUREPROPERTYREADER_H_
#define FDO_XML_FEATUREPROPERTYREADER_H_
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

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>

class FdoXmlFeatureContext;
class FdoXmlFeatureFlags;
class FdoXmlFeatureHandler;
class FdoXmlGeometryHandler;

/// \brief
/// FdoXmlFeaturePropertyReader reads features from an XML document. The reading
/// is event driven. As features and properties within features are encountered, the 
/// invoker is notified through the FdoXmlFeatureHandler interface. This class is 
/// similar to FdoXmlFeatureReader except that it provides better performance.
class FdoXmlFeaturePropertyReader :
	public FdoXmlSaxHandler,
	public FdoIDisposable
{
public:


    /// \brief
    /// creates a Feature Property Reader.
    /// 
    /// \remarks
    /// The XML element, at the document reader's current position, is recognized as a feature 
    /// collection if it is one or more of the following: 
    /// <ul>
    /// 	<li> GML FeatureCollection element
    /// 	<li> the element specified by flags->collectionUri and flags->collectionName
    /// 	<li> it has a corresponding class definition, in the given schemas, that 
    ///       derives from the GML AbstractFeatureCollectionType.
    /// </ul>
    /// 
    /// \param reader 
    /// Input XML document reader.
    /// If this reader is currently positioned at a feature 
    /// collection type element then all features in this element are read. Otherwise, 
    /// it processes all Feature Collection type sub-elements of the current element 
    /// and reads their features. Therefore, if the reader is at the start of the XML 
    /// document, all top-level feature collections in the document are read.
    /// \param flags 
    /// Input options for controlling the deserializing of the features. If NULL then 
    /// the default flags are used.
    /// 
    /// \return
    /// Returns FdoXmlFeaturePropertyReader
    /// 
	FDO_API static FdoXmlFeaturePropertyReader * Create( 
		FdoXmlReader*               reader,
    	FdoXmlFeatureFlags*         flags = NULL
    );

    /// \brief
    /// Gets the Xml document reader that was passed to this object.
    /// 
    /// \return
    /// Returns FdoXmlReader.
    /// 
    FDO_API virtual FdoXmlReader* GetXmlReader() = 0;

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
    /// The feature schemas provide directions to this class on how to deserialize the 
    /// features and convert their property values from the strings in the XML document
    /// to their proper types. If any feature, whose class definition is not present 
    /// in these schemas, is encountered then one of the following is done:
    /// <ul>
    /// 	<li> an exception is thrown when flags->errorLevel is Normal or higher. The 
    ///       exception reports all such features.
    /// 	<li> the feature is read according to a best default translation when the 
    ///       flags->errorLevel is below Normal.
    /// </ul>
    /// 
    /// \param schemas 
    /// Input the feature schemas
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureSchemas(FdoFeatureSchemaCollection* schemas) = 0;

    /// \brief
    /// Parses the XML document.
    /// 
    /// \param featureHandler 
    /// Input handler to receive events. Parse() fires various events as features and
    /// properties are encountered.
    /// \param featureContext 
    /// Input Caller-specific contextual information that is pass to the feature 
    /// handler event callbacks.
    /// \param incremental 
    /// Input 
    /// true: an incremental (progressive) parse is performed. This function returns after the 
    /// next feature is read. 
    /// false: this function keeps going until all features have been read.
    /// 
    /// \return
    /// Returns false if no feature(s) were read.
    /// 
    FDO_API virtual FdoBoolean Parse(
        FdoXmlFeatureHandler* featureHandler = NULL, 
        FdoXmlFeatureContext* featureContext = NULL, 
        FdoBoolean incremental = false
    ) = 0;

    /// \brief
    /// Indicates whether all features have been read
    /// 
    /// \return
    /// Returns true if there are no more features to read , false otherwise
    /// 
    FDO_API virtual FdoBoolean GetEOF() = 0;

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFeaturePropertyReaderP is a FdoPtr on FdoXmlFeaturePropertyReader, provided for convenience.
typedef FdoPtr<FdoXmlFeaturePropertyReader> FdoXmlFeaturePropertyReaderP;


#endif



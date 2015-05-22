#ifndef FDO_XML_H
#define FDO_XML_H
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

/// \brief
/// FdoXml is a utility class defining the FdoXml package constants.
class FdoXml
{
public:
	FDO_API_COMMON static const FdoStringP mXmlnsPref;		// "xmlns"

    /// various XML namespaces and URI's declared in an FDO XML document.

	FDO_API_COMMON static const FdoStringP mXsNs;			// "xs"
	FDO_API_COMMON static const FdoStringP mXsUri;			// "http://www.w3.org/2001/XMLSchema"
	FDO_API_COMMON static const FdoStringP mXsiNs;			// "xsi"
	FDO_API_COMMON static const FdoStringP mXsiUri;		// "http://www.w3.org/2001/XMLSchema-instance"
	FDO_API_COMMON static const FdoStringP mXlinkNs;		// "xlink"
	FDO_API_COMMON static const FdoStringP mXlinkUri;		// "http://www.w3.org/1999/xlink"
	FDO_API_COMMON static const FdoStringP mGmlNs;			// "gml"
	FDO_API_COMMON static const FdoStringP mGmlUri;		// "http://www.opengis.net/gml"
	FDO_API_COMMON static const FdoStringP mFdoNs;			// "fdo"
	FDO_API_COMMON static const FdoStringP mFdoUri;		// "http://fdo.osgeo.org/schemas"
	FDO_API_COMMON static const FdoStringP mFdsNs;			// "fds"
	FDO_API_COMMON static const FdoStringP mFdsUri;		// "http://fdo.osgeo.org/schemas/fds"
	FDO_API_COMMON static const FdoStringP mWfsNs;			// "wfs"
	FDO_API_COMMON static const FdoStringP mWfsUri;		// "http://www.opengis.net/wfs"

    /// default FDO XML document root element.

	FDO_API_COMMON static const FdoStringP mDefaultRoot;	// "fdo:DataStore"

    /// default FDO XML document root element.

    FDO_API_COMMON static const FdoStringP mGmlProviderName;	// provider name for GML Schema Mappings "OSGeo.GML.1.0"

    /// default Feature Member and Feature Collection serialization names

    FDO_API_COMMON static const FdoStringP mFeatureCollectionName;     // "FeatureCollection"
    FDO_API_COMMON static const FdoStringP mFeatureMemberName;         // "featureMember" 
};

#endif



#ifndef FDO_XML_FEATUREFLAGS_H
#define FDO_XML_FEATUREFLAGS_H

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
#include <Fdo/Xml/Flags.h>

/// \brief
/// FdoXmlFeatureFlags extends FdoXmlFlags to specify flags specific to feature 
/// serialization.
/// \remarks
/// The Error Levels inherited from FdoXmlFlags take on the following meaning when
/// applied to features. Suppose we have GML Document A that conforms to GML Schema A.
/// If Document A is read into FDO and then written to Document B then the Error Levels
/// applied to the Document A read have the following meaning:
/// <ul>
///    <li>ErrorLevel_High: Document B will be structurally identical to Document A.
///    Errors are issued if this cannot be guaranteed. Document B will have the 
///    exact same elements and attributes as Document A.
///    <li>ErrorLevel_Normal: There is no information loss. Document B contains
///    all of the information from Document A and Document B conforms to Schema A.
///    Errors are issued if this cannot be guaranteed.
///    However, Documents A and B might not look exactly alike; some Document A elements
///    may have an equivalent but different structure in Document B.
///    <li>ErrorLevel_Low: There can be information loss. Document B is a subset
///    of Document A but still conforms to Schema A. Errors are issued if 
///    this cannot be guaranteed. Any Document A elements, not recognized by
///    FDO, are discarded on read.
///    <li>ErrorLevel_VeryLow: FDO does a best effort read of Document A and write of
///    Document B. There is no guarantee that Document B will look anything like 
///    Document A or that Document B will conform to Schema A.
/// </ul>
///    
/// The above assumes that FDO is not provided the GML form of Schema A when writing
/// Document B. For example, supposed that FDO can write a Schema A conformant 
/// Document B only when supplied the GML version of Schema A. FDO will still generate 
/// errors and fail to read Document A under ErrorLevel_Low.
class FdoXmlFeatureFlags : public FdoXmlFlags
{
public:
    	/// \brief
    	/// The FdoXmlFeatureFlags::ConflictOption specifies how to handle features that 
    	/// are already in the DataStore, when Deserializing:
	enum ConflictOption {
    		/// Add new features to the FDO DataStore and if a feature already exists, 
    		/// throw an exception.
		ConflictOption_Add,
    		/// Update the feature if it already exists, add it if it doesn't exist.
		/// This is the slowest option, since the feature must be queried from the DataStore
    		/// before it is inserted or updated.
		ConflictOption_Update,
    		/// Add new features and silently skip features already in the DataStore.
		ConflictOption_Skip
	};

    /// \brief
    /// Constructs an FdoXmlFeatureFlags object.
    /// 
    /// \param url 
    /// See FdoXmlFlags::Create()
    /// \param errorLevel 
    /// See FdoXmlFlags::Create()
    /// \param nameAdjust 
    /// See FdoXmlFlags::Create()
    /// \param conflictOption 
    /// Conflict option to apply to pre-existing features, when deserializing features
    /// into an FDO datastore.
    /// 
    /// \return
    /// Returns FdoXmlFeatureFlags
    /// 
    FDO_API static FdoXmlFeatureFlags* Create( 
		FdoString*	    			                url = L"fdo.osgeo.org/schemas/feature",
        ErrorLevel		                            errorLevel = ErrorLevel_Normal,
		FdoBoolean				                    nameAdjust = true,
        ConflictOption	                            conflictOption = ConflictOption_Add
	);

    /// \brief
    /// Sets the current option for handling features already in the connection 
    /// datastore.
    /// 
    /// \param conflictOption 
    /// Specifies how feaures, already in the datastore, are handled.
    /// 
	FDO_API virtual void SetConflictOption( ConflictOption conflictOption );
    
    /// \brief
    /// Get the current option for handling feature already in the connection datastore.
    /// 
    /// \return
    /// Returns the current conflict option.
    /// 
	FDO_API virtual ConflictOption GetConflictOption() const;

    /// \brief
    /// Sets the write feature collection flag. This flag is initially set to true.
    /// 
    /// \param writeCollection 
    /// Input 
    /// true: The serialized features are wrapped in a GML FeatureCollection element.
    /// false: features are serialize without a wrapping collection element.
    /// 
	FDO_API virtual void SetWriteCollection( FdoBoolean writeCollection );

    /// \brief
    /// Gets the write feature collection flag.
    /// 
    /// \return
    /// Returns the write feature collection flag.
    /// 
	FDO_API virtual FdoBoolean GetWriteCollection() const;

    /// \brief
    /// Sets the write feature member flag. This flag is initially set to true.
    /// 
    /// \param writeMember 
    /// Input 
    /// true: Each serialized feature is wrapped in a GML featureMember element.
    /// false: features are serialized without a wrapping member element. Normally,
    /// writeMember would only be set to false when writing values to a collection
    /// object property.
    /// 
	FDO_API virtual void SetWriteMember( FdoBoolean writeMember );

    /// \brief
    /// Gets the write feature member flag.
    /// 
    /// \return
    /// Returns the write feature member flag.
    /// 
	FDO_API virtual FdoBoolean GetWriteMember() const;

    /// \brief
    /// Sets the URI for the feature collection element to wrap around serialized 
    /// features. The initial value is 'http://www.opengis.net/gml'
    /// 
    /// \param uri 
    /// Input the URI. If NULL or blank, the URI reverts back to the initial value.
    /// 
	FDO_API virtual void SetCollectionUri( FdoString* uri );

    /// \brief
    /// Gets the feature collection element URI.
    /// 
    /// \return
    /// Returns the URI.
    /// 
	FDO_API virtual FdoString* GetCollectionUri() const;

    /// \brief
    /// Sets the name for the feature collection element to wrap around serialized 
    /// features. The initial value is 'FeatureCollection'
    /// 
    /// \param name 
    /// Input the name. If NULL or blank, the name reverts back to the initial value.
    /// 
	FDO_API virtual void SetCollectionName( FdoString* name );

    /// \brief
    /// Gets the feature collection element name.
    /// 
    /// \return
    /// Returns FdoString*.
    /// 
	FDO_API virtual FdoString* GetCollectionName() const;

    /// \brief
    /// Sets the URI for the feature member element to wrap around each serialized 
    /// feature. The initial value is 'http://www.opengis.net/gml'
    /// 
    /// \param uri 
    /// Input the URI. If NULL or blank, the URI defaults to the URI of the feature 
    /// collection element's sub-element. If this sub-element cannot be determined 
    /// then the URI defaults to the initial value
    /// 
	FDO_API virtual void SetMemberUri( FdoString* uri );

    /// \brief
    /// Gets the feature member element URI.
    /// 
    /// \return
    /// Returns FdoString*
    /// 
	FDO_API virtual FdoString* GetMemberUri() const;

    /// \brief
    /// Sets the name for the feature member element to wrap around each serialized 
    /// feature. The initial value is 'featureMember'
    /// 
    /// \param name 
    /// Input the name. If NULL or blank, the URI defaults to the name of the feature 
    /// collection element's sub-element. If this sub-element cannot be determined then
    /// the name defaults to the initial value
    /// 
	FDO_API virtual void SetMemberName( FdoString* name );

    /// \brief
    /// Gets the feature member element name.
    /// 
    /// \return
    /// Returns FdoString*.
    /// 
	FDO_API virtual FdoString* GetMemberName() const;

    /// \brief
    /// Sets the GML ID prefix for writing features. This prefix is prepended to the 
    /// gml:id value for each feature. When features from different FDO Datastores are
    /// serialized to the same GML document, it is recommended that a different GML ID 
    /// prefix be used for each Datastore, to ensure that the gml:id values in the GML
    /// document are unique. The initial value is L"" (no prefix).
    /// 
    /// \param prefix 
    /// Input the GML ID Prefix
    /// 
	FDO_API virtual void SetGmlIdPrefix( FdoString* prefix );

    /// \brief
    /// Gets the current GML ID prefix.
    /// 
    /// \return
    /// Returns FdoString
    /// 
	FDO_API virtual FdoString* GetGmlIdPrefix() const;

    /// \brief
    /// Sets the schema locations for writing features. The output GML must have schema
    /// definition for all its referenced namespaces, e.g, gml namespace, wfs namespace, 
    /// user defined namespace. There are default values for gml namespace schema location
    /// and wfs namespace schema location, so the user doesn't need to set locations for those
    /// two namespaces. But the user can still set values to override the default values. The
    /// user could call this function multiple times to set schema location for multiple namespace. 
    /// 
    /// \param nameSpace 
    /// Namespace of which the schema location is to be set. Like "http://www.opengis.net/wfs" 
    /// for wfs namespace.
    /// \param schemaLocation 
    /// Standard URL indicating the schema location, like "http://schemas.opengeospatial.net/wfs/1.0.0/WFS-basic.xsd"
    /// for wfs namespace.
    /// 
    FDO_API virtual void SetSchemaLocation(FdoString* nameSpace, FdoString* schemaLocation);

    /// \brief
    /// Gets the schema location for the specified namespace.
    /// 
    /// \param nameSpace 
    /// Namespace of which the schema location is to be retrieved. Like "http://www.opengis.net/wfs"
    /// 
    /// \return
    /// Returns the URL indicating the schema location. 
    /// 
    FDO_API virtual FdoString* GetSchemaLocation(FdoString* nameSpace);

    /// \brief
    /// Gets all namespaces that have been set for schemaLocation by SetSchemaLocation().
    /// 
    /// \return
    /// Returns all namespaces that have been set for schemaLocation.
    /// 
    FDO_API virtual FdoStringCollection* GetNamespaces();

    /// \brief
    /// Sets the default namespace which defines all feature/object types found in the input
    /// feature reader which is to be serialized. The user is also supposed to set the schema
    /// location for this namespace.
    /// 
    /// \param defaultNamespace 
    /// Default namespace.
    /// 
    FDO_API virtual void SetDefaultNamespace(FdoString* defaultNamespace);

    /// \brief
    /// Gets the default namespace.
    /// 
    /// \return
    /// Returns the default namespace.
    /// 
    FDO_API virtual FdoString* GetDefaultNamespace();

protected:
	FdoXmlFeatureFlags();
    FdoXmlFeatureFlags(FdoString* url, ErrorLevel errorLevel, FdoBoolean nameAdjust, ConflictOption conflictOption);
	virtual ~FdoXmlFeatureFlags();

private:
    ConflictOption mConflictOption;
    FdoBoolean mWriteCollection;
    FdoBoolean mWriteMember;
    FdoStringP mCollectionUri;
    FdoStringP mCollectionName;
    FdoStringP mMemberUri;
    FdoStringP mMemberName;
    FdoStringP mGmlIdPrefix;
    FdoPtr<FdoStringCollection> mNamespaces;
    FdoPtr<FdoStringCollection> mSchemaLocations;
    FdoStringP mDefaultNamespace;

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFeatureFlagsP is a FdoPtr on FdoXmlFeatureFlags, provided for convenience.
typedef FdoPtr<FdoXmlFeatureFlags> FdoXmlFeatureFlagsP;

#endif



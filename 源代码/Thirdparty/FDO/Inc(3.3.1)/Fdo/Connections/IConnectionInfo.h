#ifndef _ICONNECTIONINFO_H_
#define _ICONNECTIONINFO_H_
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
#include <Fdo/Connections/IConnectionPropertyDictionary.h>
#include <Fdo/Connections/ProviderDatastoreType.h>

/// \brief
/// The FdoIConnectionInfo interface exposes information about the feature provider
/// and provides access to the FdoIConnectionPropertyDictionary interface.
class FdoIConnectionInfo : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the name of the feature provider.
    /// 
    /// \return
    /// Returns the provider name
    /// 
    FDO_API virtual FdoString* GetProviderName() = 0;

    /// \brief
    /// Gets the display name of the feature provider.
    /// 
    /// \return
    /// Returns the provider's display name
    /// 
    FDO_API virtual FdoString* GetProviderDisplayName() = 0;

    /// \brief
    /// Gets the description of the feature provider.
    /// 
    /// \return
    /// Returns the provider description
    /// 
    FDO_API virtual FdoString* GetProviderDescription() = 0;

    /// \brief
    /// Gets the version of the feature provider.
    /// 
    /// \return
    /// Returns provider version
    /// 
    FDO_API virtual FdoString* GetProviderVersion() = 0;

    /// \brief
    /// Gets the version of the Feature Data Objects specification to which this provider conforms.
    /// 
    /// \return
    /// Returns FDO version supported.
    /// 
    FDO_API virtual FdoString* GetFeatureDataObjectsVersion() = 0;

    /// \brief
    /// Gets the FdoIConnectionPropertyDictionary interface that can be used to dynamically query and set the properties required to establish a connection.
    /// 
    /// \return
    /// Returns the property dictionary
    /// 
    FDO_API virtual FdoIConnectionPropertyDictionary* GetConnectionProperties() = 0;

    /// \brief
    /// Returns the provider type. A provider can be a file-based, database-based or
    /// web-based provider. The valid values the function may return are defined in
    /// the enumeration FdoProviderDatastoreType. The enumeration includes the following
    /// values: FdoProviderDatastoreType_Unknown, FdoProviderDatastoreType_File,
    /// FdoProviderDatastoreType_DatabaseServer, FdoProviderDatastoreType_WebServer.
    /// 
    /// \return
    /// Returns the provider data store type.
    /// 
    FDO_API virtual FdoProviderDatastoreType GetProviderDatastoreType() = 0;

    /// \brief
    /// File-based providers depend on a various files. This function returns a list
    /// of fully qualified dependend file names. The return parameter will be NULL if
    /// the provider is not a file-based provider.
    /// 
    /// \return
    /// Returns the list of fully-qualified dependend file names if the provider is a
    /// file-based provider, NULL otherwise.
    /// 
    FDO_API virtual FdoStringCollection* GetDependentFileNames() = 0;
};
#endif



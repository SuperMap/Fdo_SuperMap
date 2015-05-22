#ifndef _PROVIDERDATASTORETYPE_H_
#define _PROVIDERDATASTORETYPE_H_

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

/// \ingroup (enums)
/// \brief
/// The FdoProviderDatastoreType enumeration lists all of the concrete provider
/// types supported by FDO.

enum FdoProviderDatastoreType
{

    /// Indicates that the provider is a database-based provider.
    FdoProviderDatastoreType_DatabaseServer,

    /// Indicates that the provider is a file-based provider.
    FdoProviderDatastoreType_File,

    /// Indicates that the provider is a web-based provider.
    FdoProviderDatastoreType_WebServer,

    /// Indicates that the provider is of an unknown provider type.
    FdoProviderDatastoreType_Unknown

};  //  FdoProviderDatastoreType

#endif



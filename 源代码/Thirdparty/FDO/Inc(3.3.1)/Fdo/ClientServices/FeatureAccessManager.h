#ifndef _FDOFEATUREACCESSMANAGER_H_
#define _FDOFEATUREACCESSMANAGER_H_
/***************************************************************************

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

 *
 ***************************************************************************/
#ifdef _WIN32
#pragma once
#endif

// Include Definitions
#include <Fdo/IProviderRegistry.h>
#include <Fdo/ClientServices/ClientServices.h>

// Forward Declare References
class FdoConnectionManager;
class FdoProviderRegistry;
class IConnectionManager;

/// \brief
/// The FeatureAccessManager class manages a registry of feature providers stored in the registry
/// and provides support for dynamic discovery and binding to registered feature providers
class FdoFeatureAccessManager
{
public:
    /// \brief
    /// Static method that gets an object that implements IConnection Manager
    /// 
    /// \return
    /// Returns a static instance of an IConnectionManager object. 
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
	FDO_API static IConnectionManager* GetConnectionManager();

    /// \brief
    /// Static method that gets an object that implements IProviderRegistry
    /// 
    /// \return
    /// Returns a static instance of an IProviderRegistry object. 
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
	FDO_API static IProviderRegistry* GetProviderRegistry();
/// \cond DOXYGEN-IGNORE
    static void Reset();
/// \endcond
private:
    /// Static FdoConnectionManager
    static FdoConnectionManager * m_connectionManager;

    /// Static FdoProviderRegistry
    static FdoProviderRegistry * m_providerRegistry;
};
#endif



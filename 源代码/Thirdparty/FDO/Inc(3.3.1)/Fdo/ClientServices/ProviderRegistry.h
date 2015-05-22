#ifndef _FDOPROVIDERREGISTRY_H_
#define _FDOPROVIDERREGISTRY_H_
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

// Include definitions
#include <Fdo/IProviderRegistry.h>

// Forward class declarations
class FdoProviderCollection;

/// \brief
/// The FdoProviderRegistry interface supports registering, un-registering, and enumerating 
/// registered feature providers
/// \note
/// This is not the MS-Windows registry.
class FdoProviderRegistry : public IProviderRegistry
{
/// \brief
/// Instances of the FdoFeatureAccessManager interface are responsible for the 
/// lifespan of FdoProviderRegistry.
    friend class FdoFeatureAccessManager;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a FdoProviderRegistry object.
    FdoProviderRegistry();

    /// Default destructor for FdoProviderRegistry object.
    virtual ~FdoProviderRegistry();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Gets a read only collection of information describing each of the registered feature providers. 
    /// 
    /// \return
    /// Returns an an instance of FdoProviderCollection. Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const FdoProviderCollection* GetProviders() const;
	
    /// \brief
    /// Registers a provider given the necessary information to register the provider. 
    /// If any of the parameters are missing or invalid and exception is thrown. 
    /// 
    /// \param name 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// \param displayName 
    /// A user friendly display name of the feature provider.
    /// \param description 
    /// A brief description of the feature provider.
    /// \param version 
    /// The version of the feature provider. The version number string has the form 
    /// [VersionMajor].[VersionMinor].[BuildMajor].[BuildMinor].
    /// \param fdoVersion 
    /// The version of the feature data objects specification the feature provider conforms to. 
    /// The version number string has the form [VersionMajor].[VersionMinor].[BuildMajor].[BuildMinor].
    /// \param libraryPath 
    /// The FULL library path + library name of the provider.
    /// \param isManaged 
    /// A flag indicating if the provider is a managed or unmanaged .Net provider.
    /// 
    /// \return
    /// Returns nothing. Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual void RegisterProvider(const wchar_t * name, 
                                            const wchar_t * displayName, 
                                            const wchar_t * description, 
                                            const wchar_t * version, 
                                            const wchar_t * fdoVersion, 
                                            const wchar_t * libraryPath,
                                            bool isManaged);

    /// \brief
    /// Unregisters the provider with the specified name. 
    /// 
    /// \param name 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns nothing. Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual void UnregisterProvider(const wchar_t * name);

private:
    /// The ProvideRegistry class defines and maintains a collection of Providers
    FdoProviderCollection* m_providerCollection;
};
#endif



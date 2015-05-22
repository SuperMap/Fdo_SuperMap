#ifndef _FDOPROVIDER_H_
#define _FDOPROVIDER_H_
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
#include <string>
#include <FdoStd.h>
#include <Fdo/ClientServices/ClientServices.h>

/// \brief
/// Provides information about a feature provider, including name, description, library, and version information.
class FdoProvider : public FdoIDisposable
{
    /// Instances of interface FdoProviderRegistry/FdoRegistryUtility/FdoProviderCollection 
    /// are responsible for the lifespan of FdoProvider
    friend class FdoProviderRegistry;
    friend class FdoRegistryUtility;
    friend class FdoProviderCollection;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a FdoProvider.

	FdoProvider();

    FdoProvider(const wchar_t* name, 
                const wchar_t* displayName, 
                const wchar_t* description, 
                const wchar_t* version, 
                const wchar_t* fdoVersion, 
                const wchar_t* libraryPath,
                bool managed);

    /// Default destructor for FdoProvider.
    virtual ~FdoProvider();

    virtual void Dispose();

    /// Sets the values of the provider.
    virtual void Set(const wchar_t* name, 
                     const wchar_t* displayName, 
                     const wchar_t* description, 
                     const wchar_t* version, 
                     const wchar_t* fdoVersion, 
                     const wchar_t* libraryPath,
                     bool managed);
/// \endcond
public:
    /// \brief
    /// Gets the unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns the name as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetName() const;

    /// \brief
    /// Gets a user friendly display name of the feature provider.
    /// 
    /// \return
    /// Returns the display name as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetDisplayName() const;
    
    /// \brief
    /// Gets a brief description of the feature provider.
    /// 
    /// \return
    /// Returns the description as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetDescription() const;
    
    /// \brief
    /// Gets the version of the feature provider. The version number string has the form 
    /// [VersionMajor].[VersionMinor].[BuildMajor].[BuildMinor].
    /// 
    /// \return
    /// Returns the version as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetVersion() const;

    /// \brief
    /// Gets the version of the feature data objects specification the feature provider conforms to. 
    /// The version number string has the form [VersionMajor].[VersionMinor].[BuildMajor].[BuildMinor].
    /// 
    /// \return
    /// Returns the Feature Data Objects version as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetFeatureDataObjectsVersion() const;

    /// \brief
    /// Gets the FULL library path + library name of the provider. 
    /// 
    /// \return
    /// Returns the library path as a constant wchar_t*.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual const wchar_t* GetLibraryPath() const;

    /// \brief
    /// Gets a boolean flag indicating if the provider is a managed or unmanaged provider. 
    /// 
    /// \return
    /// Returns the managed state flag as a bool.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual bool GetIsManaged() const;

private:
    /// private data holding the data used to construct the object
    std::wstring m_name;
    std::wstring m_displayName;
    std::wstring m_description;
    std::wstring m_version;
    std::wstring m_fdoVersion;
    std::wstring m_libraryPath;
    bool m_isManaged;
};
#endif



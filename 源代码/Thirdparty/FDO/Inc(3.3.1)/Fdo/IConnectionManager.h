#ifndef _ICONNECTIONMANAGER_H_
#define _ICONNECTIONMANAGER_H_


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

// Include definitions
#include <Fdo.h>
#include <Fdo/ClientServices/ClientServices.h>

/// \brief
///  
/// The IConnectionManager interface supports dynamic creation of connection objects 
/// given a provider name. 
/// \remarks
///  
/// In order for dynamic creation to work, each dynamic link library, shared library, 
/// or assembly that implements a provider must supply a well-defined entry point function that 
/// takes as input a provider name and returns an FdoIConnection instance. The definition of the 
/// entry point function is language and platform dependent. For this release of FDO, on the 
/// Windows platform, windows libraries supporting FDO providers will be expected to support the 
/// following well-known entry point function which will create and returns an unitialized 
/// connection object.
///
///         FdoIConnection * CreateConnection();
///
class IConnectionManager : public FdoIDisposable
{
public:
    /// \brief
    /// Creates an unitialized connection object given the provider name.
    /// 
    /// \param providerName 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns an instance of an FdoIConnection object. Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual FdoIConnection* CreateConnection(const wchar_t* providerName) = 0;
	
    /// \brief
    /// Frees a connection library reference given the provider name.
    /// 
    /// \param providerName 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns nothing. Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual void FreeLibrary(const wchar_t* providerName) = 0;
};
#endif



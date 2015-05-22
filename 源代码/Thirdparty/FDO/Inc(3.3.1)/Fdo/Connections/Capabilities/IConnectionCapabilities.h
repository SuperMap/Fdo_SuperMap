#ifndef _ICONNECTIONCAPABILITIES_H_
#define _ICONNECTIONCAPABILITIES_H_
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
#include <Fdo/Connections/Capabilities/ThreadCapability.h>
#include <Fdo/Commands/SpatialContext/SpatialContextExtentType.h>
#include <Fdo/Commands/Locking/LockType.h>

/// \brief
/// The FdoIConnectionCapabilities interface declares the feature provider's capabilities.
class FdoIConnectionCapabilities : public FdoIDisposable
{
public:
    /// \brief
    /// Gets an FdoThreadCapability value that declares the feature provider's level of thread safety.
    /// 
    /// \return
    /// Returns the connection thread capability.
    /// 
    FDO_API virtual FdoThreadCapability GetThreadCapability() = 0;

    /// \brief
    /// Gets the spatial context extent types supported by the feature provider.
    /// 
    /// \param length 
    /// Output the number of spatial context types.
    /// 
    /// \return
    /// Returns the list of spatial context extent types.
    /// 
    FDO_API virtual FdoSpatialContextExtentType* GetSpatialContextTypes(FdoInt32& length) = 0;

    /// \brief
    /// Determines if the feature provider supports persistent locking.
    /// 
    /// \return
    /// Returns true if the feature provider supports persistent locking.
    /// 
    FDO_API virtual bool SupportsLocking() = 0;

    /// \brief
    /// Gets an array of the FdoLockType values supported by the feature provider.
    /// 
    /// \param size 
    /// Output the number of lock types
    /// 
    /// \return
    /// Returns the list of lock types
    /// 
    FDO_API virtual FdoLockType* GetLockTypes(FdoInt32& size) = 0;

    /// \brief
    /// Determines if the feature provider supports connection timeout.
    /// 
    /// \return
    /// Returns true if the feature provider supports connection timeout.
    /// 
    FDO_API virtual bool SupportsTimeout() = 0;

    /// \brief
    /// Determines if the feature provider supports transactions.
    /// 
    /// \return
    /// Returns true if the feature provider supports transactions.
    /// 
    FDO_API virtual bool SupportsTransactions() = 0;

    /// \brief
    /// Determines true if the feature provider supports long transactions.
    /// 
    /// \return
    /// Returns true if the feature provider supports long transactions.
    /// 
    FDO_API virtual bool SupportsLongTransactions() = 0;

    /// \brief
    /// Determines if the feature provider supports SQL commands.
    /// 
    /// \return
    /// Returns true if the feature provider supports SQL commands.
    /// 
    FDO_API virtual bool SupportsSQL() = 0;

    /// \brief
    /// Determines if the feature provider supports XML configuration.
    /// 
    /// \return
    /// Returns true if the feature provider supports the setting of a configuration.
    /// 
    FDO_API virtual bool SupportsConfiguration() = 0;

    /// \brief
    /// Determines if the provider supports multiple spatial contexts.
    /// 
    /// \return
    /// Returns true if the provider supports multiple spatial contexts.
    /// 
    FDO_API virtual bool SupportsMultipleSpatialContexts() = 0;

    /// \brief
    /// Determines if the provider supports specifying the coordinate system by name or ID without specifying the WKT
    /// when creating a new spatial context.
    /// 
    /// \return
    /// Returns true if the provider supports specifying the coordinate system by name or ID without specifying the WKT
    /// when creating a new spatial context.
    /// 
    FDO_API virtual bool SupportsCSysWKTFromCSysName() = 0;

    /// \brief
    ///	Determines if write is supported by the provider or by the datastore depending on whether this request is at
    /// the provider or datastore level.
    ///
    /// \return
    ///	Returns true if write is supported by the provider or by the datastore depending on whether this request is at
    /// the provider or datastore level.
    FDO_API virtual bool SupportsWrite() = 0;

	/// \brief
    /// Determines if the provider or datastore can support more than one user writing to a single datastore at
    /// one time.
    ///
    /// \return
    /// Returns true if the provider or datastore can support more than one user writing to a single datastore at
    /// one time.
    FDO_API virtual bool SupportsMultiUserWrite() = 0;

    /// \brief
    /// Determines if the provider can support the flush function. Flush is used to write any outstanding data
    /// to the datastore. This is mainly used by the file based providers to ensure that any cached data is writen to the file.
    ///
    /// \return
    /// Returns true if the provider or datastore can support the flush function.
    ///
    FDO_API virtual bool SupportsFlush() = 0;

};
#endif



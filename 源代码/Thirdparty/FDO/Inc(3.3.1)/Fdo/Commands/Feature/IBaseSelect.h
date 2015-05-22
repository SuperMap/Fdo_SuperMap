#ifndef _IBASESELECT_H_
#define _IBASESELECT_H_
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
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Commands/Locking/LockType.h>
#include <Fdo/Commands/Locking/LockStrategy.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/Feature/IFeatureReader.h>
#include <Fdo/Commands/Locking/ILockConflictReader.h>
#include <Fdo/Commands/IdentifierCollection.h>
#include <Fdo/Commands/OrderingOption.h>

/// \brief
/// The FdoISelect interface defines the Select command, which queries for features
/// of a given class that match the specified criteria. Input to the select
/// command includes the name of the class, the list of properties to be
/// returned, and a filter. All but the class name is optional. If the list of
/// properties to be returned is empty then all properties are returned. The
/// filter may be specified either as text or as an expression tree (most likely
/// produced by a query builder). The result of executing a select command is an
/// FdoIFeatureReader reference (see "Reading Features"). If the feature provider
/// supports locking, then the select command can optionally lock all of the
/// features selected, via the ExecuteWithLock method (see "Locking
/// Commands" for more information on locking features).
class FdoIBaseSelect : public FdoIFeatureCommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of property names to 
    /// return with the result. If empty all properties of the specified class
    /// are returned.
    /// 
    /// \return
    /// Returns the list of property names.
    /// 
    FDO_API virtual FdoIdentifierCollection* GetPropertyNames() = 0;

    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a order by criteria.
    /// 
    /// \return
    /// Returns the list of group by property names.
    /// 
    FDO_API virtual FdoIdentifierCollection* GetOrdering() = 0;

    /// \brief
    /// Set the ordering option of the selection. This is only used if the ordering collection is not empty.
    /// 
    /// \param option 
    /// Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
    /// FdoOrderingOption_Ascending is the default value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetOrderingOption( FdoOrderingOption  option ) = 0;

    /// \brief
    /// Gets the ordering option.
    /// 
    /// \return
    /// Returns the ordering option.
    /// 
    FDO_API virtual FdoOrderingOption GetOrderingOption( ) = 0;

};
#endif



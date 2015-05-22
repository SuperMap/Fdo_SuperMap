#ifndef _ISELECTAGGREGATES_H_
#define _ISELECTAGGREGATES_H_
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
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/Feature/IDataReader.h>
#include <Fdo/Commands/IdentifierCollection.h>
#include <Fdo/Commands/OrderingOption.h>
#include <Fdo/Commands/Feature/IBaseSelect.h>

/// \brief
/// The FdoISelectAggregate interface defines a Select command that handle selection of properties that include 
/// the use of aggregate functions. This command differs from the FdoISelect command in a number of ways. 
/// It handles selection of properties that are aggregate functions and supports selecting distinct property values. 
/// It also includes grouping criteria. The execute method returns an IDataReader which is not tied to a specific class. 
/// Unlike Select, FdoISelectAggregate does not include any locking functions.
class FdoISelectAggregates : public FdoIBaseSelect
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Executes the select command and returns a reference to an FdoIDataReader.
    /// 
    /// \return
    /// Returns the data reader.
    /// 
    FDO_API virtual FdoIDataReader* Execute() = 0;

    /// \brief
    /// Set the distinct option of the selection. 
    /// Non-simple properties such as object properties, geometry properties, raster properties, association properties, etc. will not be supported with Distinct.
    /// 
    /// \param value 
    /// true or false; when set to true, only distinct values are returned. Otherwise all values are returned
    /// 
    /// \return
    /// Returns nothing
    /// 
    /// \note
	/// Grouping criteria is not supported with Distinct. 
    FDO_API virtual void SetDistinct( bool value ) = 0;

    /// \brief
    /// Get the distinct option.
    /// 
    /// \return
    /// Returns true if distinct is set, false otherwise.
    /// 
    FDO_API virtual bool GetDistinct( ) = 0;

    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of group by property names. If empty no grouping is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a group by criteria. No LOB or Geometry type properties
    /// can be used for ordering.
    /// 
    /// \return
    /// Returns the list of group by property names.
    /// 
    FDO_API virtual FdoIdentifierCollection* GetGrouping() = 0;

    /// \brief
    /// Set the grouping by filter. Use the grouping filter to restrict the groups of returned properties to those groups for 
    /// which the specified filter is TRUE. For example "order by city" and  "min(lanes) = 2". The FdoFilter have to evalute to a 
    /// binary value(true or false).
    /// 
    /// \param filter 
    /// The grouping filter.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetGroupingFilter( FdoFilter* filter ) = 0;

    /// \brief
    /// Gets the grouping by filter.
    /// 
    /// \return
    /// Returns the grouping filter.
    /// 
    FDO_API virtual FdoFilter* GetGroupingFilter( ) = 0;
};
#endif



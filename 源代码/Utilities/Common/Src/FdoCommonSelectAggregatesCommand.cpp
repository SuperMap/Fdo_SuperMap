/*
 * 
* Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
* 
 */

#include "stdafx.h"
#include <FdoCommonSelectAggregatesCommand.h>
#include <FdoCommonDataReader.h>
#include <FdoCommonSchemaUtil.h>

#include <malloc.h>

FdoCommonSelectAggregatesCommand::FdoCommonSelectAggregatesCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoISelectAggregates, FdoIConnection> (connection),
    m_bDistinct(false),
    m_eOrderingOption(FdoOrderingOption_Ascending)
{
    m_GroupingIds = FdoIdentifierCollection::Create();
    m_OrderingIds = FdoIdentifierCollection::Create();
    mPropertiesToSelect = FdoIdentifierCollection::Create();
}


/** Do not implement the copy constructor. **/
//FdoCommonSelectAggregatesCommand::FdoCommonSelectAggregatesCommand (const FdoCommonSelectAggregatesCommand &right) { }

FdoCommonSelectAggregatesCommand::~FdoCommonSelectAggregatesCommand (void)
{
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of property names to 
/// return with the result. If empty all properties of the specified class
/// are returned.</summary>
/// <returns>Returns the list of property names.</returns> 
FdoIdentifierCollection* FdoCommonSelectAggregatesCommand::GetPropertyNames ()
{
    return (FDO_SAFE_ADDREF(mPropertiesToSelect.p));
}

/// <summary>Executes the select command and returns a reference to an FdoIDataReader.</summary>
/// <returns>Returns the feature reader.</returns> 
FdoIDataReader* FdoCommonSelectAggregatesCommand::Execute ()
{
    FdoString* class_name;

    class_name = FdoPtr<FdoIdentifier> (GetFeatureClassName ())->GetName ();
    FdoPtr<FdoIConnection> conn = (FdoIConnection*)GetConnection ();


    //we will need a vanilla select command to get the features
    //the user would like to work with (given class and FdoFilter)
    FdoPtr <FdoISelect> selectCmd = (FdoISelect*)conn->CreateCommand(FdoCommandType_Select);
    selectCmd->SetFeatureClassName(class_name);
    selectCmd->SetFilter(mFilter);

    // Get other relevant info:
    FdoPtr<FdoIdentifierCollection> selectedIds = GetPropertyNames();
    FdoPtr<FdoClassDefinition> originalClassDef = FdoCommonSchemaUtil::GetLogicalClassDefinition(conn, class_name, NULL);

    // Create and return the data reader:
    FdoPtr<FdoIDataReader> dataReader = new FdoCommonDataReader(conn, selectCmd, originalClassDef, selectedIds, m_bDistinct, m_OrderingIds, m_eOrderingOption);
    return FDO_SAFE_ADDREF(dataReader.p);
}


/// <summary>Set the distinct option of the selection. Note that grouping criteria is not supported with Distinct. 
/// Non-simple properties such as object properties, geometry properties, raster properties, association properties, etc. will not be supported with Distinct.</summary>
/// <param name="value">true or false; when set to true, only distinct values are returned. Otherwise all values are returned</param> 
/// <returns>Returns nothing</returns>  
void FdoCommonSelectAggregatesCommand::SetDistinct( bool value )
{
    m_bDistinct = value;
}

/// <summary>Get the distinct option.</summary>
/// <returns>Returns true if distinct is set, false otherwise.</returns> 
bool FdoCommonSelectAggregatesCommand::GetDistinct( )
{
    return m_bDistinct;
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of group by property names. If empty no grouping is used. This list is initially
/// empty and the caller need to add the property that the command should use as a group by criteria. No LOB or Geometry type properties
/// can be used for ordering.</summary>
/// <returns>Returns the list of group by property names.</returns> 
FdoIdentifierCollection* FdoCommonSelectAggregatesCommand::GetGrouping()
{
    return FDO_SAFE_ADDREF(m_GroupingIds.p);
}

/// <summary>Set the grouping by filter. Use the grouping filter to restrict the groups of returned properties to those groups for 
/// which the specified filter is TRUE. For example "order by city" and  "min(lanes) = 2". The FdoFilter have to evalute to a 
/// binary value(true or false).</summary>
/// <param name="filter">The grouping filter.</param> 
/// <returns>Returns nothing</returns> 
void FdoCommonSelectAggregatesCommand::SetGroupingFilter(FdoFilter* filter)
{
    m_GroupingFilter = FDO_SAFE_ADDREF(filter);
}

/// <summary>Gets the grouping by filter.</summary>
/// <returns>Returns the grouping filter.</returns> 
FdoFilter* FdoCommonSelectAggregatesCommand::GetGroupingFilter(void)
{
    return FDO_SAFE_ADDREF(m_GroupingFilter.p);
}

/// <summary>Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
/// empty and the caller need to add the property that the command should use as a order by criteria.</summary>
/// <returns>Returns the list of group by property names.</returns> 
FdoIdentifierCollection* FdoCommonSelectAggregatesCommand::GetOrdering(void)
{
    return FDO_SAFE_ADDREF(m_OrderingIds.p);
}

/// <summary>Set the ordering option of the selection. This is only used if the ordering collection is not empty.</summary>
/// <param name="option">Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
/// FdoOrderingOption_Ascending is the default value.</param> 
/// <returns>Returns nothing</returns> 
void FdoCommonSelectAggregatesCommand::SetOrderingOption(FdoOrderingOption option)
{
    m_eOrderingOption = option;
}

/// <summary>Gets the ordering option.</summary>
/// <returns>Returns the ordering option.</returns> 
FdoOrderingOption FdoCommonSelectAggregatesCommand::GetOrderingOption(void)
{
    return m_eOrderingOption;
}


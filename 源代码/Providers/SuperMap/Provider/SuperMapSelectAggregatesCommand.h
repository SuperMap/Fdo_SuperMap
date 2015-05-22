
/** \file	 SuperMapSelectAggregatesCommand.h
*  \author	 Âí¿¡
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#ifndef __SUPERMAP_SELECTAGGREGATESCOMMAND_H__
#define __SUPERMAP_SELECTAGGREGATESCOMMAND_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapSelectCommand;

class SuperMapSelectAggregatesCommand : public FdoCommonFeatureCommand<FdoISelectAggregates, FdoIConnection>
{
protected:
    FdoPtr<FdoIdentifierCollection> mPropertiesToSelect;
    bool m_bDistinct;
    FdoOrderingOption m_eOrderingOption;
    FdoPtr<FdoIdentifierCollection> m_OrderingIds;
    FdoPtr<FdoFilter> m_GroupingFilter;
    FdoPtr<FdoIdentifierCollection> m_GroupingIds;

	SuperMapSelectCommand  *m_pSelect;

protected:
    virtual ~SuperMapSelectAggregatesCommand (void);

public:
    SuperMapSelectAggregatesCommand (FdoIConnection *connection);

    //
    /// Prevent the use of the Assignment Operation by defining it and not implementing it.
    /// DO NOT IMPLEMENT
    SuperMapSelectAggregatesCommand & operator= (const SuperMapSelectAggregatesCommand &right);

    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of property names to 
    /// return with the result. If empty all properties of the specified class
    /// are returned.
    /// 
    /// \return
    /// Returns the list of property names.
    /// 
    virtual FdoIdentifierCollection* GetPropertyNames ();

    /// \brief
    /// Executes the select command and returns a reference to an FdoIDataReader.
    /// 
    /// \return
    /// Returns the data reader.
    /// 
    virtual FdoIDataReader* Execute ();

    /// \brief
    /// Set the distinct option of the selection. Note that grouping criteria is not supported with Distinct. 
    /// Non-simple properties such as object properties, geometry properties, raster properties, association properties, etc. will not be supported with Distinct.
    /// 
    /// \param value 
    /// true or false; when set to true, only distinct values are returned. Otherwise all values are returned
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void SetDistinct( bool value );

    /// \brief
    /// Get the distinct option.
    /// 
    /// \return
    /// Returns true if distinct is set, false otherwise.
    /// 
    virtual bool GetDistinct( );

    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of group by property names. If empty no grouping is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a group by criteria. No LOB or Geometry type properties
    /// can be used for ordering.
    /// 
    /// \return
    /// Returns the list of group by property names.
    /// 
    virtual FdoIdentifierCollection* GetGrouping();

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
    virtual void SetGroupingFilter( FdoFilter* filter );

    /// \brief
    /// Gets the grouping by filter.
    /// 
    /// \return
    /// Returns the grouping filter.
    /// 
    virtual FdoFilter* GetGroupingFilter( );

    /// \brief
    /// Gets the FdoIdentifierCollection that holds the list of order by property names. If empty no ordering is used. This list is initially
    /// empty and the caller need to add the property that the command should use as a order by criteria.
    /// 
    /// \return
    /// Returns the list of group by property names.
    /// 
    virtual FdoIdentifierCollection* GetOrdering();

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
    virtual void SetOrderingOption( FdoOrderingOption  option );

    /// \brief
    /// Gets the ordering option.
    /// 
    /// \return
    /// Returns the ordering option.
    /// 
    virtual FdoOrderingOption GetOrderingOption( );
};

#endif // __SUPERMAP_SELECTAGGREGATESCOMMAND_H__
// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef SHPIEXTENDEDSELECT_H
#define SHPIEXTENDEDSELECT_H

#include "FdoStd.h"
#include "Fdo.h"
#include "SHP/IScrollableFeatureReader.h"
#include "SHP/ShpCompareHandler.h"

class ShpIExtendedSelect : public FdoISelect
{		
	
public:
	// Expose the FdoISelect hidden functions
	using FdoISelect::GetOrderingOption;
	using FdoISelect::SetOrderingOption;

	/// <summary>Set the ordering option of the selection. This is only used if the ordering collection is not empty.</summary>
	/// <param name="propertyName">Is the property name for which the ordering should be applied. This property should be in the ordering collection.</param> 
    /// <param name="option">Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
    /// FdoOrderingOption_Ascending is the default value.</param> 
    /// <returns>Returns nothing</returns> 
	virtual void SetOrderingOption( FdoString* propertyName, FdoOrderingOption  option ) = 0;

    /// <summary>Gets the ordering option for a given property.</summary>
	/// <param name="propertyName">Is the property name for which the ordering should be applied. This property should be in the ordering collection.</param> 
    /// <returns>Returns the ordering option.</returns> 
	virtual FdoOrderingOption GetOrderingOption( FdoString* propertyName ) = 0;

	/// <summary>This method clears the internal list of property/ordering option list and re-sets the ordering option for all 
	/// the ordering properties to the default FdoOrderingOption_Ascending or to the ordering option specified by the 
	/// FdoIBaseSelect interface.</summary>
    /// <returns>Returns nothing.</returns> 
	virtual void ClearOrderingOptions( ) = 0;

	/// <summary>Set the compare handler. This method is used to override the default Shp compare handler.</summary>
    /// <param name="handler">The compare handle that should be derived from the ShpCompareHandler class.</param> 
    /// <returns>Returns nothing</returns> 
	virtual void SetCompareHandler( ShpCompareHandler*  handler ) = 0;

	/// <summary> Executes the select command and returns a ShpIScrollableFeatureReader.  
	/// If ordering is enabled, then the returned reader is sorted according to 
	/// the ordering collection. This method perform sorting in memory and allocates an integer value for each row.</summary>
    /// <returns>Returns a ShpIScrollableFeatureReader object</returns> 
	virtual ShpIScrollableFeatureReader* ExecuteScrollable() = 0;

};

#endif


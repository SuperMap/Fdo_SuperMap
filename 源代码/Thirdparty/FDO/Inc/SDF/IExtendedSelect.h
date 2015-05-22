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

#ifndef _SdfIExtendedSelect_H_
#define _SdfIExtendedSelect_H_

#include "FdoStd.h"
#include "Fdo.h"
#include "SDF/IScrollableFeatureReader.h"
#include "SDF/SdfCompareHandler.h"

class SdfIExtendedSelect : public FdoISelect
{		
	
public:
	// Expose the FdoISelect hidden functions
	using FdoISelect::GetOrderingOption;
	using FdoISelect::SetOrderingOption;

	/// \brief
	/// Set the ordering option of the selection.
	/// 
	/// \remarks
	/// This is only used if the ordering collection is not empty.
	///
	/// \param propertyName
	/// Is the property name for which the ordering should be applied. This property should be in the ordering collection.
	///
    /// \param option
	 /// Is the ordering option and should be set to one of FdoOrderingOption_Ascending or FdoOrderingOption_Descending.
    /// FdoOrderingOption_Ascending is the default value.
	virtual void SetOrderingOption( FdoString* propertyName, FdoOrderingOption  option ) = 0;

    /// \brief
	 /// Gets the ordering option for a given property.
	 ///
	/// \param propertyName
	//Is the property name for which the ordering should be applied. This property should be in the ordering collection.
	///
    /// \return
	 /// Returns the ordering option.
	virtual FdoOrderingOption GetOrderingOption( FdoString* propertyName ) = 0;

	/// \brief
	/// Clears the internal list of property/ordering option list and re-sets the ordering option for all 
	/// the ordering properties to the default FdoOrderingOption_Ascending or to the ordering option specified by the 
	/// FdoIBaseSelect interface.
	virtual void ClearOrderingOptions( ) = 0;

	/// \brief
	/// Sets the compare handler.
	///
	/// \remarks
	/// This method is used to override the default sdf compare handler.
	///
    /// \param handler
	 /// The compare handle that should be derived from the SdfCompareHandler class.
	virtual void SetCompareHandler( SdfCompareHandler*  handler ) = 0;

	/// \brief
	/// Executes the select command and returns an SdfIScrollableFeatureReader.
	///
	/// \remarks  
	/// If ordering is enabled, then the returned reader is sorted according to 
	/// the ordering collection. This method perform sorting in memory and allocates an integer value for each row.
    /// \return
	 /// Returns a SdfIScrollableFeatureReader object
	virtual SdfIScrollableFeatureReader* ExecuteScrollable() = 0;

	/// \brief
	/// Executes the select command and returns a SdfIScrollableFeatureReader.
	/// \remarks
	/// Creates a temporary SDF file that contains the selected properties.
	/// If ordering is enabled, then the created temporary SDF file
	/// is sorted according to the ordering collection.
	/// In this case the sorting is file based where the SQLite BTree is used. 
	//  The extendedProps and extendedDefaults can be used to extend the class definition of the selected data. 
	/// Both collections have to be in-sync otherwise an exception will be thrown.
	///
	/// \param sdfCacheFile
	/// File path and name used to store the result of the query.
	///
	/// \param extendedProps
	/// A collection of data property definition that extends the class definition defined by the selected properties.
	///
	/// \param extendedDefaults
	/// A collection of property values used as defaults for extended properties defined by extendedProps parameter.
	///
    /// \return
	 /// Returns a SdfIScrollableFeatureReader object.
    virtual SdfIScrollableFeatureReader* ExecuteScrollable( const wchar_t* sdfCacheFile, FdoDataPropertyDefinitionCollection* extendedProps, FdoPropertyValueCollection*  extendedDefaults ) = 0;
};

#endif


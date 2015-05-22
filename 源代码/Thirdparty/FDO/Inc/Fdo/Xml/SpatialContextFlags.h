#ifndef FDO_XML_SPATIALCONTEXTFLAGS_H
#define FDO_XML_SPATIALCONTEXTFLAGS_H

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
#include <Fdo/Xml/Flags.h>

/// \brief
/// FdoXmlSpatialContextFlags extends FdoXmlFlags to specify flags 
/// specific to Spatial Contexts.
class FdoXmlSpatialContextFlags : public FdoXmlFlags
{
public:
    	/// \brief
    	/// The FdoXmlSpatialContextFlags::ConflictOption specifies how 
    	/// to handle Spatial Contexts that are already in the DataStore, 
    	///  when Deserializing:
	enum ConflictOption {
    		/// Add new spatial contexts to the FDO DataStore and
		/// if the Spatial Context already exists, throw an exception.
    		/// is thrown.
		ConflictOption_Add,
    		/// Update the spatial context if it already exists and
    		/// add it if it doesn't exist.
		ConflictOption_Update,
    		/// Add new spatial contexts and
    		/// silently skip spatial contexts already in the DataStore.
		ConflictOption_Skip
	};

    /// \brief
    /// Constructs an FdoXmlSpatialContextFlags object.
    /// 
    /// \param url 
    /// Base URL for generating well-known references to 
    /// GML coordinate systems and transformations
    /// \param errorLevel 
    /// Input The error level for reading spatial contexts. Controls how 
    /// strict the error reporting is.
    /// \param nameAdjust 
    /// Input true: apply name adjustment to all elements. 
    /// false: apply name adjustment only to elements with fdo:nameAdjust="true"
    /// \param conflictOption 
    /// Input option for Deserializing Spatial Contexts. 
    /// Specified how Spatial Contexts, already in the FDO connection, are handled.
    /// \param includeDefault 
    /// Input true: When Serializing Spatial Contexts, serialize
    /// all contexts including the default.
    /// false: skip the default Spatial Context.
    /// 
    /// \return
    /// Returns FdoXmlSpatialContextFlags
    /// 
    FDO_API static FdoXmlSpatialContextFlags* Create( 
		FdoString*	    			                url = L"fdo.osgeo.org/schemas/feature",
        ErrorLevel		                            errorLevel = ErrorLevel_Normal,
		FdoBoolean				                    nameAdjust = true,
        ConflictOption	conflictOption = ConflictOption_Add,
		FdoBoolean				                    includeDefault = false
	);

    /// \brief
    /// Sets the current option for handling Spatial Contexts
    /// already in the connection.
    /// 
    /// \param conflictOption 
    /// Input option for Deserializing Spatial Contexts. 
    /// Specified how Spatial Contexts, already in the FDO connection, are handled.
    /// 
	FDO_API void SetConflictOption( ConflictOption conflictOption );
    
    /// \brief
    /// Get the current option for handling Spatial Contexts
    /// already in the connection.
    /// 
    /// \return
    /// Returns the current conflict option.
    /// 
	FDO_API ConflictOption GetConflictOption() const;

    /// \brief
    /// Sets the default Spatial Context inclusion flag.
    /// 
    /// \param includeDefault 
    /// Input true: When Serializing Spatial Contexts, serialize
    /// all contexts including the default.
    /// false: skip the default Spatial Context.
    /// 
	FDO_API void SetIncludeDefault( FdoBoolean includeDefault );

    /// \brief
    /// Gets the default Spatial Context inclusion flag.
    /// 
    /// \return
    /// Returns the default Spatial Context inclusion flag.
    /// 
	FDO_API FdoBoolean GetIncludeDefault() const;


protected:
    /// default constructor to keep linux from complaining
    FdoXmlSpatialContextFlags() {}
	FDO_API FdoXmlSpatialContextFlags( 
		FdoString*				url,
		ErrorLevel				errorLevel,
		FdoBoolean				nameAdjust,
		ConflictOption		    conflictOption,
		FdoBoolean				includeDefault
    );
    FDO_API virtual ~FdoXmlSpatialContextFlags();

private:
	ConflictOption		    mConflictOption;
	FdoBoolean				mIncludeDefault;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSpatialContextFlagsP is a FdoPtr on FdoXmlSpatialContextFlags, provided for convenience.
typedef FdoPtr<FdoXmlSpatialContextFlags> FdoXmlSpatialContextFlagsP;

#endif



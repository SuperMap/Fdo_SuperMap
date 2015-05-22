#ifndef _IPROPERTYDICTIONARY_H_
#define _IPROPERTYDICTIONARY_H_
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

/// \brief
/// The FdoIPropertyDictionary exposes a dictionary style interface
/// to the connection properties. The properties required to establish a connection
/// can be determined and their values can be set through this interface.
/// Modifying connection properties through this
/// interface dynamically modifies the connection string held by the connection
/// object. When the connection is in an open state, calling SetProperty on this
/// interface will result in an error.
class FdoIPropertyDictionary : public FdoIDisposable
{
public:
    /// \brief
    ///  Gets the names of all the properties that can appear in a connection string
    /// for this feature provider as an array of Strings. The order of the property
    /// names in the resulting array dictate the order in which they need to be 
    /// specified. This is especially important for the success of the 
    /// EnumeratePropertyValues method because properties that occur earlier in the array
    /// may be required for successful enumeration of properties that appear later.
    /// 
    /// \param count 
    /// Output the number of parameters
    /// 
    /// \return
    /// Returns the list of parameter names
    /// 
    FDO_API virtual FdoString** GetPropertyNames(FdoInt32& count) = 0;

    /// \brief
    /// Gets the value of the specified property.
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the property value.
    /// 
    FDO_API virtual FdoString* GetProperty(FdoString* name) = 0;

    /// \brief
    /// Sets the value of the specified property. An exception is thrown if the connection is currently open.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetProperty(FdoString* name, FdoString* value) = 0;

    /// \brief
    /// Gets the default value for the specified property.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns the property default value
    /// 
    FDO_API virtual FdoString* GetPropertyDefault(FdoString* name) = 0;

    /// \brief
    /// Determines if the specified property is required.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is required
    /// 
    FDO_API virtual bool IsPropertyRequired(FdoString* name) = 0;
 
    /// \brief
    ///  Indicates if the property is a password or other protected field
    /// that should be kept secure.
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns true if the property is a password or other protected field
    /// that should be kept secure.
    /// 
    FDO_API virtual bool IsPropertyProtected(FdoString* name) = 0;
   
    /// \brief
    /// Determines if the possible values for the specified property can be enumerated via the EnumeratePropertyValues method.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the possible values for the specified property can be enumerated.
    /// 
    FDO_API virtual bool IsPropertyEnumerable(FdoString* name) = 0;

    /// \brief
    ///  Returns an array of possible values for the specified property.
    /// 
    /// \param name 
    /// Input the property name.
    /// \param count 
    /// Output the number of values.
    /// 
    /// \return
    /// Returns the list of values for this property.
    /// 
    FDO_API virtual FdoString** EnumeratePropertyValues(FdoString* name, FdoInt32& count) = 0;

    /// \brief
    ///  Gets a localized name for the property (for NLS purposes).
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the localized name for the property (for NLS purposes).
    /// 
    FDO_API virtual FdoString* GetLocalizedName(FdoString* name) = 0;

    /// \brief
    /// Determines if the specified property represents a file name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a file name
    /// 
	FDO_API virtual bool IsPropertyFileName(FdoString* name) = 0;

    /// \brief
    /// Determines if the specified property represents a path name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a path name
    /// 
    FDO_API virtual bool IsPropertyFilePath(FdoString* name) = 0;

    /// \brief
    /// Determines if the specified property represents a datastore name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a datastore name
    /// 
	FDO_API virtual bool IsPropertyDatastoreName(FdoString* name) = 0;

};
#endif



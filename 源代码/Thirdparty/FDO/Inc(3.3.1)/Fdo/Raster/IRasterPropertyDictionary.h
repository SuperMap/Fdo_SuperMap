#ifndef _IRASTERPROPERTYDICTIONARY_H_
#define _IRASTERPROPERTYDICTIONARY_H_

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
#include <Fdo/Raster/RasterDataModelType.h>
#include <Fdo/Raster/RasterDataOrganization.h>
#include <Fdo/Expression/DataValueCollection.h>

/// \brief
/// The FdoIRasterPropertyDictionary exposes a dictionary style
/// interface to the raster properties. Through this interface the
/// non-standard properties of a raster image can be determined and
/// their values can be retrieved and set.  Data values are exchanged
/// through the FdoDataValue object to accommodate various data types,
/// boolean, integer, double, string etc.
class FdoIRasterPropertyDictionary: public FdoIDisposable
{
public:

    /// \brief
    /// Gets the names of all the properties that apply to this
    /// image as a collection of Strings. The order of the property names
    /// in the collection dictate the order in which they need to
    /// be specified. This is especially important for the success of
    /// the EnumeratePropertyValues method as properties that occur
    /// earlier in the collection may be required for successful enumeration
    /// of properties that appear later in the collection.
    /// 
    /// \return
    /// A collection of the names of properties in this dictionary.
    /// 
    FDO_API virtual FdoStringCollection* GetPropertyNames () = 0;

    /// \brief
    /// Gets the data type for the specified property.
    /// 
    /// \param name 
    /// The name of the property to get the data type of.
    /// 
    /// \return
    /// The data type of the property.
    /// 
    FDO_API virtual FdoDataType GetPropertyDataType (FdoString* name) = 0;

    /// \brief
    /// Gets the value of the specified property (or its default).
    /// 
    /// \param name 
    /// The name of the property to get the value of.
    /// 
    /// \return
    /// The value of the property.
    /// 
    FDO_API virtual FdoDataValue* GetProperty (FdoString* name) = 0;

    /// \brief
    /// Sets the value of the specified property.
    /// 
    /// \param name 
    /// The name of the property to set the value of.
    /// \param value 
    /// The new value for the property.
    /// 
    FDO_API virtual void SetProperty (FdoString* name, FdoDataValue* value) = 0;

    /// \brief
    /// Gets the default value for the specified property.
    /// 
    /// \param name 
    /// The name of the property to get the default value of.
    /// 
    /// \return
    /// The default value of the property.
    /// 
    FDO_API virtual FdoDataValue* GetPropertyDefault (FdoString* name) = 0;

    /// \brief
    /// Predicate to determine if the property is required to be set.
    /// 
    /// \param name 
    /// The name of the property to get the required status of.
    /// 
    /// \return
    /// Returns true if the specified property is required, false if it is optional.
    /// 
    FDO_API virtual bool IsPropertyRequired (FdoString* name) = 0;

    /// \brief
    /// Predicate to determine if the property is enumerable (has more than one value).
    /// 
    /// \param name 
    /// The name of the property to get the enumerable status of.
    /// 
    /// \return
    /// Returns true if the possible values for the specified property
    /// can be enumerated via the GetPropertyValues method.
    /// 
    FDO_API virtual bool IsPropertyEnumerable (FdoString* name) = 0;

    /// \brief
    /// Access the values of the specified enumerable property.
    /// The property must respond TRUE to IsPropertyEnumerable.
    /// 
    /// \param name 
    /// The name of the property to get the collection of values for.
    /// 
    /// \return
    /// A collection of datavaluesfor the enumerable property.
    /// 
    FDO_API virtual FdoDataValueCollection* GetPropertyValues (FdoString* name) = 0;

    /// \brief
    /// Set the values of the specified enumerable property.
    /// The property must respond TRUE to IsPropertyEnumerable.
    /// Clients will need to use SetPropertyValues when creating an image
    /// with specific values for the enumerable property.
    /// An example would be setting a table of wavelength ranges corresponding
    /// to the false colour used to encode the image.
    /// 
    /// \param name 
    /// The name of the property to set the collection of values for.
    /// \param collection 
    /// The collection of values for the enumerable property.
    /// 
    FDO_API virtual void SetPropertyValues (FdoString* name, FdoDataValueCollection* collection) = 0;

    /// The FdoDataValueCollection object is a subclass of the standard collection template with FdoDataValue elements.
};

#endif // _IRASTERPROPERTYDICTIONARY_H_



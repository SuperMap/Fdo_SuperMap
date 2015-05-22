#ifndef _IDATAREADER_H_
#define _IDATAREADER_H_

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
#include <Fdo/Commands/Feature/IReader.h>

/// \brief
/// The FdoIDataReader interface provides a forward-only, read-only
/// iterator for reading relational table data. A reference to an
/// FdoIDataReader is returned from the SQLCommands ExecuteReader method.
/// The initial position of the FdoIDataReader interface is prior to the first item.
/// Thus, you must call ReadNext to begin accessing any data.
class FdoIDataReader: public FdoIReader
{
public:
    /// \brief
    /// Gets the number of propertys in the result set.
    /// 
    /// \return
    /// Returns the number of propertys.
    /// 
    FDO_API virtual FdoInt32 GetPropertyCount() = 0;

    /// \brief
    /// Gets the name of the property at the given ordinal position.
    /// 
    /// \param index 
    /// Input the position of the property.
    /// 
    /// \return
    /// Returns the property name
    /// 
    FDO_API virtual FdoString* GetPropertyName(FdoInt32 index) = 0;

    /// \brief
    /// Gets the data type of the property with the specified name.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the type of the property.
    /// 
    FDO_API virtual FdoDataType GetDataType(FdoString* propertyName) = 0;

    /// \brief
    /// Gets the FDO property type of a given property. This is used
    ///  to indicate if a given property is a geometric property or a data property. If the property is
    ///  a FdoPropertyType_DataProperty, then GetDataType can be used to to find the data type of the property.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the FDO property type.
    /// 
    FDO_API virtual FdoPropertyType GetPropertyType(FdoString* propertyName) = 0;
};
#endif



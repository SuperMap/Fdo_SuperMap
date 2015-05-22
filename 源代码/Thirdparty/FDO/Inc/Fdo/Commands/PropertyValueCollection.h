#ifndef _PROPERTYVALUECOLLECTION_H_
#define _PROPERTYVALUECOLLECTION_H_
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
#include <Fdo/Commands/PropertyValue.h>
#include <Fdo/Commands/CommandException.h>

/// \brief
/// FdoPropertyValueCollection represents a collection of property values. Property
/// values are name/value pairs used for specifying the values of properties for
/// insert and update commands.
class FdoPropertyValueCollection : public FdoCollection<FdoPropertyValue, FdoCommandException>
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default empty instance of an FdoPropertyValueCollection.
    FdoPropertyValueCollection():FdoCollection<FdoPropertyValue, FdoCommandException>()
    {
    }

    virtual ~FdoPropertyValueCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs a default empty instance of an FdoPropertyValueCollection.
    /// 
    /// \return
    /// Returns FdoPropertyValueCollection
    /// 
    FDO_API static FdoPropertyValueCollection* Create();

    /// \brief
    /// Gets the item in the collection with the specified name. Throws an invalid 
    /// argument exception if an item with the specified name does not exist in 
    /// the collection.
    /// 
    /// \param name 
    /// Input name of item
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API FdoPropertyValue* GetItem(FdoString* name);

    /// \brief
    /// Finds the item in the collection with the specified name. Returns NULL 
    /// if an item with the specified name does not exist in the collection.
    /// 
    /// \param name 
    /// Input name of item
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API FdoPropertyValue* FindItem(FdoString* name);

    /// \brief
    /// Gets the item in the collection at the specified index. Throws an
    /// invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index of item
    /// 
    /// \return
    /// Returns FdoPropertyValue
    /// 
    FDO_API FdoPropertyValue* GetItem(FdoInt32 index);
};
#endif



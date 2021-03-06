#ifndef _READONLYDATAPROPERTYDEFINITIONCOLLECTION_H_
#define _READONLYDATAPROPERTYDEFINITIONCOLLECTION_H_

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
#include <Fdo/Schema/SchemaElement.h>
#include <Fdo/Schema/SchemaException.h>
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/DataPropertyDefinitionCollection.h>
#include <Fdo/IDisposableCollection.h>
#include <Fdo/ReadOnlyCollection.h>

class FdoClassDefinition;

/// \brief
/// The FdoReadOnlyDataPropertyDefinitionCollection class represents a read-only collection of FdoDataPropertyDefinition objects.
class FdoReadOnlyDataPropertyDefinitionCollection : public FdoReadOnlyCollection<FdoDataPropertyDefinition, FdoIDisposableCollection, FdoSchemaException>
{
protected:
/// \cond DOXYGEN-IGNORE
    FdoReadOnlyDataPropertyDefinitionCollection()
	{
	}
    FdoReadOnlyDataPropertyDefinitionCollection(FdoDataPropertyDefinitionCollection* properties);

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs and populates an instance of an FdoReadOnlyDataPropertyDefinitionCollection.
    /// 
    /// \param properties 
    /// Input collection of FdoDataPropertyDefinition objects
    /// 
    /// \return
    /// Returns an FdoReadOnlyDataPropertyDefinitionCollection
    /// 
    FDO_API static FdoReadOnlyDataPropertyDefinitionCollection* Create(FdoDataPropertyDefinitionCollection* properties);

    /// \brief
    /// Gets the number of items in the collection.
    /// 
    /// \return
    /// Returns the number of items in the collection
    /// 
    FDO_API FdoInt32 GetCount();

    /// \brief
    /// Gets the item in the collection at the specified index. Throws an
    /// invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the item in the collection at the specified index
    /// 
    FDO_API FdoDataPropertyDefinition* GetItem(FdoInt32 index);

    /// \brief
    /// Gets the item in the collection with the specified name. Throws an invalid argument exception if an item with the specified name does not exist in the collection.
    /// 
    /// \param name 
    /// Input name to find
    /// 
    /// \return
    /// Returns the item in the collection with the specified name
    /// 
	FDO_API FdoDataPropertyDefinition* GetItem(FdoString* name);

    /// \brief
    /// Determines if the collection contains the specified item.
    /// 
    /// \param value 
    /// Input FdoDataPropertyDefinition
    /// 
    /// \return
    /// Returns true if the collection contains the specified item
    /// 
    FDO_API bool Contains(FdoDataPropertyDefinition* value);

    /// \brief
    /// Returns the index of the specified item in the collection.
    /// If the item does not exist, the IndexOf function returns -1.
    /// 
    /// \param value 
    /// Input FdoDataPropertyDefinition
    /// 
    /// \return
    /// Returns the index of the specified item in the collection
    /// 
    FDO_API FdoInt32 IndexOf(FdoDataPropertyDefinition* value);
};
#endif



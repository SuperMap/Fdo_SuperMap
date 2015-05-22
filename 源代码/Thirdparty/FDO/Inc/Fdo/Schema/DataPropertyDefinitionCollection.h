#ifndef _DATAPROPERTYDEFINITIONCOLLECTION_H_
#define _DATAPROPERTYDEFINITIONCOLLECTION_H_

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
#include <Fdo/Schema/DataPropertyDefinition.h>
#include <Fdo/Schema/SchemaCollection.h>

class FdoClassDefinition;

/// \brief
/// The FdoDataPropertyDefinitionCollection class represents a collection of FdoDataPropertyDefinition objects.
class FdoDataPropertyDefinitionCollection: public FdoSchemaCollection<FdoDataPropertyDefinition> 
{
    friend class FdoClassDefinition;
    friend class FdoAssociationPropertyDefinition;

public:

protected:
/// \cond DOXYGEN-IGNORE
	FdoDataPropertyDefinitionCollection()
	{
	}
    /// Constructs an instance of a DataPropertyDefinitionCollection using the specified argument.
    FdoDataPropertyDefinitionCollection(FdoSchemaElement* parent) : FdoSchemaCollection<FdoDataPropertyDefinition>(parent)
    {
    /// DataPropertyCollection is only used for identityProperties, which only reference items
    /// in the Properties collection.  Since it doesn't own these items, the parent shouldn't
    /// be set when adding to this collection.
        m_setItemParent = false;
    }

    virtual ~FdoDataPropertyDefinitionCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:

    /// \brief
    /// Constructs an instance of an FdoDataPropertyDefinitionCollection using the specified argument.
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoDataPropertyDefinitionCollection
    /// 
    FDO_API static FdoDataPropertyDefinitionCollection* Create(FdoSchemaElement* parent);

    /// \brief
    /// Sets the item in the collection at the specified index to the specified value. 
    /// Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetItem(FdoInt32 index, FdoDataPropertyDefinition* value);

    /// \brief
    /// Adds the specified item to the end of the collection. Returns the 
    /// index of the newly added item.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns the index of the newly added item
    /// 
    FDO_API virtual FdoInt32 Add(FdoDataPropertyDefinition* value);

    /// \brief
    /// Inserts the specified item at the specified index within the collection. 
    /// Items following the insertion point are moved down to accommodate the new item. 
    /// Throws an invalid argument exception if the specified index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Insert(FdoInt32 index, FdoDataPropertyDefinition* value);
};

/// \ingroup (typedefs)
/// \brief
/// FdoDataPropertiesP is a FdoPtr on FdoDataPropertyDefinitionCollection, provided for convenience.
typedef FdoPtr<FdoDataPropertyDefinitionCollection> FdoDataPropertiesP;

#endif



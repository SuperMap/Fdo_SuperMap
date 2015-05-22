#ifndef _PROPERTYDEFINITIONCOLLECTION_H_
#define _PROPERTYDEFINITIONCOLLECTION_H_

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

#include <Fdo/Schema/PropertyDefinition.h>
#include <Fdo/Schema/SchemaCollection.h>

class FdoClassDefinition;

/// \brief
/// The FdoPropertyDefinitionCollection class represents a collection of FdoPropertyDefinition objects.
class FdoPropertyDefinitionCollection: public FdoSchemaCollection<FdoPropertyDefinition> 
{
    friend class FdoClassDefinition;

protected:
/// \cond DOXYGEN-IGNORE
    FdoPropertyDefinitionCollection()
	{
	}
    /// Constructs a default empty instance of an FdoPropertyDefinitionCollection.
    FdoPropertyDefinitionCollection(FdoSchemaElement* parent):FdoSchemaCollection<FdoPropertyDefinition>(parent)
    {
    }

    virtual ~FdoPropertyDefinitionCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs an instance of an FdoPropertyDefinitionCollection using the specified argument.
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoPropertyDefinitionCollection
    /// 
    FDO_API static FdoPropertyDefinitionCollection* Create(FdoSchemaElement* parent);

    /// \brief
    /// Removes the specified item from the collection. Throws an invalid argument exception if the item does not exist within the collection.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Remove(const FdoSchemaElement* value);

    /// \brief
    /// Removes the specified item from the collection. Throws an invalid argument exception if the item does not exist within the collection.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void RemoveAt(FdoInt32 index);
};

/// \ingroup (typedefs)
/// \brief
/// FdoPropertiesP is a FdoPtr on FdoPropertyDefinitionCollection, provided for convenience.
typedef FdoPtr<FdoPropertyDefinitionCollection> FdoPropertiesP;

#endif



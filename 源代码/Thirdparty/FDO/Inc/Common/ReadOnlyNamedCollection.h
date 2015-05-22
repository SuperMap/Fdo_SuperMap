#ifndef _READONLYNAMEDCOLLECTION_H_
#define _READONLYNAMEDCOLLECTION_H_
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

/// \brief
/// FdoReadOnlyNamedCollection is an abstract template class that can be
/// wrapped around a base collection of type specified by the BASECOLLECTION 
/// template argument. It allows access to the members of the base collection 
/// but disallows the adding or removing of members to or from the base 
/// collection.
///
/// Note1: the OBJ template argument must be set to the type of the members 
/// of the BASECOLLECTION.
///
/// Note2: BASECOLLECTION must be a type based on FdoNamedCollection.
template <class OBJ, class BASECOLLECTION> class FdoReadOnlyNamedCollection : public FdoIDisposable
{
protected:
    FdoReadOnlyNamedCollection() {}
    /// \brief
    /// Read Only Named Collection constructor
    /// 
    /// \param baseCollection 
    /// Input collection to wrap around. This collection
    /// provides read-only access to the base collection.
    /// 
    FdoReadOnlyNamedCollection( BASECOLLECTION* baseCollection )
    {
        m_collection = FDO_SAFE_ADDREF(baseCollection);
    }

public:

    /// \brief
    /// Gets the number of items in the base collection.
    /// 
    /// \return
    /// Returns number of items in the base collection
    /// 
    virtual FdoInt32 GetCount() const
    {
        return m_collection->GetCount();
    }

    /// \brief
    /// Gets the item in the base collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the item in the base collection at the specified index
    /// 
    virtual OBJ* GetItem(FdoInt32 index) const
    {
        return m_collection->GetItem(index);
    }

    /// \brief
    /// Gets the item in the base collection with the specified name. Throws an exception if the item is not found.
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the base collection with the specified name
    /// 
    virtual OBJ* GetItem(const wchar_t* name) const
    {
        return m_collection->GetItem(name);
    }

    /// \brief
    /// Finds the item in the base collection with the specified name.
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the base collection with the specified name.
    /// Returns NULL if the item was not found.
    /// 
    virtual OBJ* FindItem(const wchar_t* name) const
    {
        return m_collection->FindItem(name);
    }

    /// \brief
    /// Returns true if the base collection contains the specified item, false otherwise.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns true if the base collection contains the specified item, false otherwise
    /// 
    virtual bool Contains(const OBJ* value) const
    {
        return m_collection->Contains(value);
    }

    /// \brief
    /// Returns the index of the specified item in the base collection or -1 if the item does not exist.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns the index of the specified item in the base collection or -1 if the item does not exist
    /// 
    virtual FdoInt32 IndexOf(const OBJ* value) const
    {
        return m_collection->IndexOf(value);
    }

private:
    FdoPtr<BASECOLLECTION > m_collection;
};

#endif



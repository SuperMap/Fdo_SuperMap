#ifndef _RESTRICTEDNAMEDCOLLECTION_H_
#define _RESTRICTEDNAMEDCOLLECTION_H_
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
/// FdoRestrictedNamedCollection is an abstract template class that can be
/// wrapped around a base collection of type specified by the BASECOLLECTION 
/// template argument. However, the members of this collection are restricted 
/// to being of a subtype of the type of members allowed in the base 
/// collection. The subtype is specified by the SUBOBJ template argument. 
///
/// Any class deriving from this template must also defined a:
///
///    SUBOBJ* DownCast(BASEOBJ* value )
///
/// function, which must cast the member of the base type to the subtype. It is recommended
/// that static_cast be used, when possible, to perform the down cast.
///
/// \note
/// BASEOBJ must match the item class for BASECOLLECTION. 
template <class BASEOBJ, class SUBOBJ, class BASECOLLECTION> class FdoRestrictedNamedCollection : public FdoIDisposable
{
protected:
    FdoRestrictedNamedCollection() {}
    FdoRestrictedNamedCollection( BASECOLLECTION* baseCollection )
    {
        m_collection = FDO_SAFE_ADDREF(baseCollection);
    }

public:

    /// \brief
    /// Gets the number of items in the collection.
    /// 
    /// \return
    /// Returns number of items in the collection
    /// 
    virtual FdoInt32 GetCount() const
    {
        return m_collection->GetCount();
    }

    /// \brief
    /// Gets the item in the collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the item in the collection at the specified index
    /// 
    virtual SUBOBJ* GetItem(FdoInt32 index) const
    {
        return DownCast(m_collection->GetItem(index));
    }

    /// \brief
    /// Gets an item by name. Throws an invalid argument exception if 
    /// the item is not in this collection
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the collection with the specified name
    /// 
    virtual SUBOBJ* GetItem(const wchar_t* name) const
    {
        return DownCast(m_collection->GetItem(name));
    }

    /// \brief
    /// Gets an item by name.
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the collection with the specified name.
    /// Returns NULL if the item is not in this collection.
    /// 
    ///  
    virtual SUBOBJ* FindItem(const wchar_t* name) const
    {
        return DownCast(m_collection->FindItem(name));
    }

    /// \brief
    /// Sets the item in the collection at the specified index to the specified value. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void SetItem(FdoInt32 index, SUBOBJ* value)
    {
        m_collection->SetItem(index, value);
    }

    /// \brief
    /// Adds the specified item to the end of the collection. Returns the index of the newly added item.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns the index of the newly added item
    /// 
    virtual FdoInt32 Add(SUBOBJ* value)
    {
        return m_collection->Add(value);
    }

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
    virtual void Insert(FdoInt32 index, SUBOBJ* value)
    {
        m_collection->Insert(index, value );
    }

    /// \brief
    /// Removes all items from the collection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Clear()
    {
        m_collection->Clear();
    }

    /// \brief
    /// Removes the specified item from the collection. Throws an invalid argument exception if the item does not exist within the collection.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Remove(const SUBOBJ* value)
    {
        m_collection->Remove(value);
    }

    /// \brief
    /// Removes the specified item from the collection. Throws an invalid argument exception if the item does not exist within the collection.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void RemoveAt(FdoInt32 index)
    {
        m_collection->RemoveAt(index);
    }

    /// \brief
    /// Returns true if the collection contains the specified item, false otherwise.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns true if the collection contains the specified item, false otherwise
    /// 
    virtual bool Contains(const SUBOBJ* value) const
    {
        return m_collection->Contains(value);
    }

    /// \brief
    /// Returns the index of the specified item in the collection or -1 if the item does not exist.
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns the index of the specified item in the collection or -1 if the item does not exist
    /// 
    virtual FdoInt32 IndexOf(const SUBOBJ* value) const
    {
        return m_collection->IndexOf(value);
    }

    /// \brief
    /// Returns a read only pointer to the base collection
    /// 
    /// \return
    /// Returns const BASECOLLECTION*
    /// 
    virtual const BASECOLLECTION* GetBaseCollection()
    {
        return (const BASECOLLECTION*) m_collection;
    }

protected:
    /// Downcasts an item from the Base to the SubType.
    virtual SUBOBJ* DownCast( BASEOBJ* value ) const = 0;

private:

    FdoPtr<BASECOLLECTION > m_collection;

};
#endif



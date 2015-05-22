#ifndef FDO_NAMED_COLLECTION_H
#define FDO_NAMED_COLLECTION_H        1
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

#include <FdoCommon.h>
#include <Common/Collection.h>
#include <map>

// Build a map when the collection exceeds this number of elements.
// GetItem by name is faster through the map, when the collection
// exceeds 10 elements. The threshold is set a bit higher to account
// for the overhead of building and deleting the map. 
#define FDO_COLL_MAP_THRESHOLD 50

/// \brief
/// FdoNamedCollection is a template for collections keyed by element name.
/// The OBJ class must provide a GetName() function that returns the element name 
/// as a FdoString* and a CanSetName() function that returns true if the class 
/// allows modification of the name (implements SetName()) and false if it does not. 
/// This class also provides fast access by name for large collections.
/// When CanSetName() returns true, the access by name is a bit less 
/// efficient since linear searches need to be done in some cases. The 
/// reason for this is that after an object changes name, it is no longer
/// in the right position in this collection's name map.
template <class OBJ, class EXC> class FdoNamedCollection : public FdoCollection<OBJ, EXC>
{
public: 
    /// \brief
    /// Gets the item in the collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the item in the collection at the specified index
    /// 
    virtual OBJ* GetItem(FdoInt32 index) const
    {
        return FdoCollection<OBJ, EXC>::GetItem(index);
    }

    /// \brief
    /// Gets the item in the collection with the specified name. Throws an exception if the item is not found.
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the collection with the specified name
    /// 
    virtual OBJ* GetItem(const wchar_t* name) const
    {
        OBJ* item = FindItem( name );
        if ( !item ) 
            throw EXC::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_38_ITEMNOTFOUND),
                    name
                )
            );

        return(item);
    }

    /// \brief
    /// Finds the item in the collection with the specified name.
    /// 
    /// \param name 
    /// Input item name
    /// 
    /// \return
    /// Returns the item in the collection with the specified name.
    /// Returns NULL if the item was not found.
    /// 
    virtual OBJ* FindItem(const wchar_t* name) const
    {
    // trigger the building of a map when the collection reaches the threshold size.
        ((FdoNamedCollection<OBJ,EXC>*) this)->InitMap();

        OBJ* obj = NULL;

        if ( mpNameMap ) {
            // Accessing the map is faster for large collections, so use it if built.
            obj = GetMap(name);

            // The map can become stale if the name of any item changed after it
            // was added to the map. Check if the object's class allows name modifications.
            // Do this check on found object by default
            OBJ* canSetObj = obj;

            if ( !canSetObj && (FdoCollection<OBJ, EXC>::GetCount() > 0))
                // Object was not found, do check on first object in collection.
                canSetObj = GetItem(0);

            // Check if object name can be modified. 
            bool canSetName = canSetObj ? canSetObj->CanSetName() : true;

            if (!obj)
                FDO_SAFE_RELEASE(canSetObj);

            // If the object name can't be modified then we're done.
            // Otherwise, there's a chance the object name was modified,
            // meaning that it can be in the collection but not the map,
            // or in the wrong place in the map.
            if ( !canSetName )
                return(obj);

            // If the found object's name is the same as the given name
            // then we're done. Otherwise, this object's name has changed
            // and a linear search is needed to find the requested object.
            if ( (obj != NULL) && (Compare(obj->GetName(), name) != 0) )
                FDO_SAFE_RELEASE( obj );
        }

        if ( obj == NULL ) {
            // No map or map might be stale, so do linear search.
            for ( FdoInt32 i = 0; i < FdoCollection<OBJ, EXC>::GetCount(); i++ ) {
                OBJ* obj = GetItem(i);

                if ( Compare(name, obj->GetName()) == 0 )
                    return(obj);

                FDO_SAFE_RELEASE(obj);
            }
        }

        return (obj);
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
    virtual void SetItem(FdoInt32 index, OBJ* value)
    {
        CheckDuplicate( value, index );

    // Remove the old item from the map 
        if ( mpNameMap ) 
            RemoveMapAt(index);

    // Add the new item to the map
        if ( mpNameMap && value ) 
            InsertMap( value );

    // Set the new item in the collection.
        FdoCollection<OBJ,EXC>::SetItem(index, value);
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
    virtual FdoInt32 Add( OBJ* value)
    {
        CheckDuplicate( value, -1 );

    // Insert the new item in the map
        if ( mpNameMap && value ) {
            InsertMap(value);
        }

    // add it to the list.
        return( FdoCollection<OBJ,EXC>::Add(value) );
    }

    /// \brief
    /// Inserts the specified item at the specified index within the collection. 
    /// Items following the insertion point are moved down to accommodate the new item. 
    /// Throws an invalid argument exception if the specified index is out of range.
    /// 
    /// \param item 
    /// Input item
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Insert( FdoInt32 item, OBJ* value)
    {
        CheckDuplicate( value, -1 );

    // Insert the new item in the map
        if ( mpNameMap ) {
            InsertMap(value);
        }

    // Insert it in the list
        return( FdoCollection<OBJ,EXC>::Insert(item, value) );
    }

    /// \brief
    /// Removes all items from the collection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Clear()
    {
    // Clear the map
        if (mpNameMap ) {
            delete mpNameMap;
            mpNameMap = NULL;
        }

    // Clear the list
        FdoCollection<OBJ,EXC>::Clear();
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
    virtual void Remove(const OBJ* value)
    {
    // Remove the item from the map.
        if ( mpNameMap ) 
            RemoveMap( value );

    // Remove it from the list
        FdoCollection<OBJ,EXC>::Remove(value);
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
    // Remove the item from the map.
        if ( mpNameMap ) 
            RemoveMapAt(index);

    // Remove it from the list
        FdoCollection<OBJ,EXC>::RemoveAt(index);
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
    virtual bool Contains(const OBJ* value) const
    {
    // trigger the building of a map when the collection reaches the threshold size.
        ((FdoNamedCollection<OBJ,EXC>*) this)->InitMap();

        if (mpNameMap )
        {
    // If map is built, use it since it is faster. 
            FdoPtr <FdoIDisposable> temp = GetMap (((OBJ*)value)->GetName());
            bool ret = (temp != NULL);
            return (ret);
        }
        else // Otherwise, linear search
        {
            FdoString * valueName = ((OBJ*)value)->GetName();
            FdoInt32 count = FdoCollection<OBJ, EXC>::GetCount();
            bool ret = false;
            for (FdoInt32 i = 0; !ret && i < count; i++)
            {
                FdoPtr<OBJ> item = GetItem(i);
                FdoString * itemName = item->GetName();
                ret = (Compare(itemName, valueName)==0);
            }
            return ret;
        }
    }

    /// \brief
    /// Returns true if the collection contains the specified item, false otherwise.
    /// 
    /// \param name 
    /// Input the item name
    /// 
    /// \return
    /// Returns true if the collection contains the specified item, false otherwise
    /// 
    virtual bool Contains(FdoString* name) const
    {
        OBJ* item = FindItem(name);
        bool found = (item != NULL);

        FDO_SAFE_RELEASE(item);

        return(found);
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
    virtual FdoInt32 IndexOf(const OBJ* value) const
    {
        return(FdoCollection<OBJ,EXC>::IndexOf(value));
    }

    /// \brief
    /// Returns the index of the specified item (by name) in the collection or -1 if the item does not exist.
    /// 
    /// \param name 
    /// Input the item name
    /// 
    /// \return
    /// Returns the index of the specified item in the collection or -1 if the item does not exist
    /// 
    virtual FdoInt32 IndexOf(FdoString* name) const
    {
        if (name == NULL)
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_137_NAMED_COLLECTION_INDEX_NAME_ERROR),
                                                          L"FdoNamedCollection::IndexOf"));

        FdoInt32    size = FdoCollection <OBJ, EXC>::GetCount();
        for (FdoInt32 i = 0; i < size; i++)
        {
            FdoPtr<OBJ> pitem = FdoNamedCollection<OBJ, EXC>::GetItem(i);
            if (pitem != NULL && pitem->GetName() != (FdoString*) NULL && Compare(name, pitem->GetName()) == 0) {
                return i;
            }
        }

        return(-1);
    }

protected:
    FdoNamedCollection( bool caseSensitive = true )
    {
        mbCaseSensitive = caseSensitive;
        mpNameMap = NULL;
    }

    virtual ~FdoNamedCollection(void)
    {
        if (mpNameMap ) 
            delete mpNameMap;
    }

/// \cond DOXYGEN-IGNORE
    int Compare( FdoString* str1, FdoString* str2 ) const
    {
        if ( mbCaseSensitive )
            return ( wcscmp(str1, str2) );

    // Try case-insensitive comparison.
#ifdef _WIN32
        return ( _wcsicmp(str1, str2) );
#else
        return ( wcscasecmp(str1, str2) );
#endif
    }

    void CheckDuplicate( OBJ* item, FdoInt32 index )
    {
        FdoPtr<OBJ> foundItem1 = FindItem( item->GetName() );
        FdoPtr<OBJ> foundItem2;

        if ( index >= 0 ) {
            foundItem2 = GetItem(index);
        }

        if ( (foundItem1 !=NULL) && (foundItem1.p != foundItem2.p ) ) { 
            throw EXC::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_45_ITEMINCOLLECTION),
                    (FdoString*) item->GetName()
                )
            );
        }
    }
/// \endcond

private:
    void InitMap()
    {
    // Build the map if not already built and the collection has hit the threshold
        if ( !mpNameMap && ( FdoCollection <OBJ, EXC>::GetCount() > FDO_COLL_MAP_THRESHOLD ) ) {
            mpNameMap = new std::map<FdoStringP,OBJ*>();

    // Put all the current elements into the map
            for ( FdoInt32 i = (FdoCollection <OBJ, EXC>::GetCount() - 1); i >= 0; i-- ) 
                InsertMap( FdoPtr<OBJ>(GetItem(i)) );
        }
    }

    void InsertMap( OBJ* value ) const
    {
    // Add an element to the map. Elements are keyed by name, which may or may not be case sensitive.
    // Case insensitive names are stored in lower case.
        if ( mbCaseSensitive ) 
            mpNameMap->insert( std::pair<FdoStringP,OBJ*> ( FdoStringP(value->GetName(),true), value ) );
        else
            mpNameMap->insert( std::pair<FdoStringP,OBJ*> ( FdoStringP(value->GetName(),true).Lower(), value ) );            
    }

    // Remove the element at the specified index, from the map
    void RemoveMapAt( FdoInt32 index )
    {
    // Remove the old item from the map 
        OBJ* pItem = FdoCollection<OBJ,EXC>::GetItem(index);

        if ( pItem ) {
            RemoveMap( pItem );
            pItem->Release();
        }
    }

    // Remove the given element from the map.
    void RemoveMap( const OBJ* value )
    {
    // handle the current case sensitivity of the element name.
        if ( mbCaseSensitive ) 
            mpNameMap->erase( FdoStringP( ((OBJ*)value)->GetName() ) );
        else
            mpNameMap->erase( FdoStringP( ((OBJ*)value)->GetName() ).Lower() );            
    }

    // Get the named element from the map. Returns NULL if element not in map.
    OBJ* GetMap( const wchar_t* name ) const
    {
        OBJ* pItem = NULL;

        typename std::map <FdoStringP,OBJ*> :: const_iterator iter;

        if ( mbCaseSensitive )
            iter = mpNameMap->find( FdoStringP(name) );
        else 
    // Case sensitive names are stored in lower case.
            iter = mpNameMap->find( FdoStringP(name).Lower() );

        if ( iter != mpNameMap->end() ) { 
            pItem = (OBJ*) iter->second;
            FDO_SAFE_ADDREF(pItem);
        }

        return( pItem );
    }

    bool mbCaseSensitive;

    // A map keyed by name, to help performance of large collections.
    std::map<FdoStringP,OBJ*> *mpNameMap;
};

#endif



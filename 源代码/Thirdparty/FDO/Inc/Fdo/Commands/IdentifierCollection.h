#ifndef _IDENTIFIERCOLLECTION_H_
#define _IDENTIFIERCOLLECTION_H_
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
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Commands/CommandException.h>

/// \brief
/// The FdoIdentifierCollection class represents a collection of FdoIdentifier objects.
class FdoIdentifierCollection : public FdoCollection<FdoIdentifier, FdoCommandException>
{
/// \cond DOXYGEN-IGNORE
protected:
    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default empty instance of an FdoIdentifierCollection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoIdentifierCollection* Create();


    /// \brief
    /// Gets the item in the collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the item in the collection at the specified index
    /// 
    FDO_API FdoIdentifier* GetItem(FdoInt32 index)
    {
        return FdoCollection<FdoIdentifier, FdoCommandException>::GetItem(index);
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
    FDO_API FdoIdentifier* GetItem(const wchar_t* name)
    {
        FdoIdentifier* item = FindItem( name );
        if ( !item ) 
            throw FdoCommandException::Create(
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
    FDO_API FdoIdentifier* FindItem(const wchar_t* name)
    {
    // trigger the building of a map when the collection reaches the threshold size.
        ((FdoIdentifierCollection*) this)->InitMap();

        FdoIdentifier* obj = NULL;

        if ( mpNameMap ) {
    // Accessing the map is faster for large collections, so use it if built.
            obj = GetMap(name);

    // If the object name can't be modified then we're done.
    // Otherwise, there's a chance the object name was modified,
    // meaning that it can be in the collection but not the map,
    // or in the wrong place in the map.
    /*  FdoIdentifier supports SetText() so we have to assume the text might have changed
            if ( (obj != NULL) && !obj->CanSetName() )
                return(obj);
    */

    // If the found object's name is the same as the given name
    // then we're done. Otherwise, this object's name has changed
    // and a linear search is needed to find the requested object.
            if ( (obj != NULL) && (Compare(obj->GetText(), name) != 0) )
                FDO_SAFE_RELEASE( obj );
        }

        if ( obj == NULL ) {
    // No map so do linear search.
            for ( FdoInt32 i = 0; i < FdoCollection<FdoIdentifier, FdoCommandException>::GetCount(); i++ ) {
                FdoIdentifier* obj = GetItem(i);

                if ( Compare(name, obj->GetText()) == 0 )
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
    virtual void SetItem(FdoInt32 index, FdoIdentifier* value)
    {
        CheckDuplicate( value, index );

    // Remove the old item from the map 
        if ( mpNameMap ) 
            RemoveMapAt(index);

    // Add the new item to the map
        if ( mpNameMap && value ) 
            InsertMap( value );

    // Set the new item in the collection.
        FdoCollection<FdoIdentifier, FdoCommandException>::SetItem(index, value);
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
    virtual FdoInt32 Add( FdoIdentifier* value)
    {
        CheckDuplicate( value, -1 );

    // Insert the new item in the map
        if ( mpNameMap && value ) {
            InsertMap(value);
        }

    // add it to the list.
        return( FdoCollection<FdoIdentifier, FdoCommandException>::Add(value) );
    }

    /// \brief
    /// Inserts the specified item at the specified index within the collection. 
    /// Items following the insertion point are moved down to accommodate the new item. 
    /// Throws an invalid argument exception if the specified index is out of range.
    /// 
    /// \param item 
    /// Input index
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Insert( FdoInt32 item, FdoIdentifier* value)
    {
        CheckDuplicate( value, -1 );

    // Insert the new item in the map
        if ( mpNameMap ) {
            InsertMap(value);
        }

    // Insert it in the list
        return( FdoCollection<FdoIdentifier, FdoCommandException>::Insert(item, value) );
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
        FdoCollection<FdoIdentifier, FdoCommandException>::Clear();
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
    virtual void Remove(const FdoIdentifier* value)
    {
    // Remove the item from the map.
        if ( mpNameMap ) 
            RemoveMap( value );

    // Remove it from the list
        FdoCollection<FdoIdentifier, FdoCommandException>::Remove(value);
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
        FdoCollection<FdoIdentifier, FdoCommandException>::RemoveAt(index);
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
    virtual bool Contains(const FdoIdentifier* value)
    {
    // trigger the building of a map when the collection reaches the threshold size.
        ((FdoIdentifierCollection*) this)->InitMap();

        if (mpNameMap )
        {
    // If map is built, use it since it is faster. 
            FdoPtr <FdoIDisposable> temp = GetMap (((FdoIdentifier*)value)->GetText());
            bool ret = (temp != NULL);
            return (ret);
        }
        else // Otherwise, linear search
        {
            FdoString * valueName = ((FdoIdentifier*)value)->GetText();
            FdoInt32 count = FdoCollection<FdoIdentifier, FdoCommandException>::GetCount();
            bool ret = false;
            for (FdoInt32 i = 0; !ret && i < count; i++)
            {
                FdoPtr<FdoIdentifier> item = GetItem(i);
                FdoString * itemName = item->GetText();
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
    virtual bool Contains(FdoString* name)
    {
        FdoIdentifier* item = FindItem(name);
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
    virtual FdoInt32 IndexOf(const FdoIdentifier* value)
    {
        return(FdoCollection<FdoIdentifier, FdoCommandException>::IndexOf(value));
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
    virtual FdoInt32 IndexOf(FdoString* name)
    {
        if (name == NULL)
            throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_2_BADPARAMETER)));

        FdoInt32    size = FdoCollection<FdoIdentifier, FdoCommandException>::GetCount();
        for (FdoInt32 i = 0; i < size; i++)
        {
            FdoPtr<FdoIdentifier> pitem = GetItem(i);
            if (pitem != NULL && pitem->GetText() != (FdoString*) NULL && Compare(name, pitem->GetText()) == 0) {
                return i;
            }
        }

        return(-1);
    }

protected:
    FdoIdentifierCollection( bool caseSensitive = true )
    {
        mbCaseSensitive = caseSensitive;
        mpNameMap = NULL;
    }

    virtual ~FdoIdentifierCollection(void)
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

    void CheckDuplicate( FdoIdentifier* item, FdoInt32 index )
    {
        FdoPtr<FdoIdentifier> foundItem1 = FindItem( item->GetText() );
        FdoPtr<FdoIdentifier> foundItem2;

        if ( index >= 0 ) {
            foundItem2 = GetItem(index);
        }

        if ( (foundItem1 !=NULL) && (foundItem1.p != foundItem2.p ) ) { 
            throw FdoCommandException::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_45_ITEMINCOLLECTION),
                    (FdoString*) item->GetText()
                )
            );
        }
    }
/// \endcond

private:
    void InitMap()
    {
    // Build the map if not already built and the collection has hit the threshold
        if ( !mpNameMap && ( FdoCollection<FdoIdentifier, FdoCommandException>::GetCount() > FDO_COLL_MAP_THRESHOLD ) ) {
            mpNameMap = new std::map<FdoStringP,FdoIdentifier*>();

    // Put all the current elements into the map
            for ( FdoInt32 i = (FdoCollection<FdoIdentifier, FdoCommandException>::GetCount() - 1); i >= 0; i-- ) 
                InsertMap( FdoPtr<FdoIdentifier>(GetItem(i)) );
        }
    }

    void InsertMap( FdoIdentifier* value ) const
    {
    // Add an element to the map. Elements are keyed by name, which may or may not be case sensitive.
    // Case insensitive names are stored in lower case.
        if ( mbCaseSensitive ) 
            mpNameMap->insert( std::pair<FdoStringP,FdoIdentifier*> ( value->GetText(), value ) );
        else
            mpNameMap->insert( std::pair<FdoStringP,FdoIdentifier*> ( FdoStringP(value->GetText()).Lower(), value ) );            
    }

    // Remove the element at the specified index, from the map
    void RemoveMapAt( FdoInt32 index )
    {
    // Remove the old item from the map 
        FdoIdentifier* pItem = FdoCollection<FdoIdentifier, FdoCommandException>::GetItem(index);

        if ( pItem ) {
            RemoveMap( pItem );
            pItem->Release();
        }
    }

    // Remove the given element from the map.
    void RemoveMap( const FdoIdentifier* value )
    {
    // handle the current case sensitivity of the element name.
        if ( mbCaseSensitive ) 
            mpNameMap->erase( FdoStringP( ((FdoIdentifier*)value)->GetText() ) );
        else
            mpNameMap->erase( FdoStringP( ((FdoIdentifier*)value)->GetText() ).Lower() );            
    }

    // Get the named element from the map. Returns NULL if element not in map.
    FdoIdentifier* GetMap( const wchar_t* name ) const
    {
        FdoIdentifier* pItem = NULL;

        /*typename*/ std::map <FdoStringP,FdoIdentifier*> :: const_iterator iter;

        if ( mbCaseSensitive )
            iter = mpNameMap->find( FdoStringP(name) );
        else 
    // Case sensitive names are stored in lower case.
            iter = mpNameMap->find( FdoStringP(name).Lower() );

        if ( iter != mpNameMap->end() ) { 
            pItem = (FdoIdentifier*) iter->second;
            FDO_SAFE_ADDREF(pItem);
        }

        return( pItem );
    }

    bool mbCaseSensitive;

    // A map keyed by name, to help performance of large collections.
    std::map<FdoStringP,FdoIdentifier*> *mpNameMap;

};
#endif


#ifndef FDO_PHYSICALELEMENTMAPPINGCOLLECTION
#define FDO_PHYSICALELEMENTMAPPINGCOLLECTION
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
#include <Common/NamedCollection.h>
#include <Fdo/Commands/CommandException.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>

/// \brief
/// FdoPhysicalElementMappingCollection is an abstract template class that is used to
/// define collections of Physical Schema Mapping elements.
template <class OBJ> class FdoPhysicalElementMappingCollection : public FdoNamedCollection<OBJ, FdoCommandException>
{

/// \cond DOXYGEN-IGNORE
protected:
	FdoPhysicalElementMappingCollection()  : FdoNamedCollection<OBJ, FdoCommandException>(),
		m_parent(NULL)
	{
	}

    FdoPhysicalElementMappingCollection(FdoPhysicalElementMapping* parent) : FdoNamedCollection<OBJ, FdoCommandException>()
    {
        m_parent = parent;
    }

    virtual ~FdoPhysicalElementMappingCollection()
    {
        if ( m_parent)
        {
            for(FdoInt32 i = 0; i < FdoNamedCollection<OBJ, FdoCommandException>::GetCount(); i++)
            {
                FdoPtr<OBJ>    pitem = FdoNamedCollection<OBJ, FdoCommandException>::GetItem(i);

    // When the collection disappears, the ownership does too.
    // So NULL out the parent.  This is necessary because the
    // parent reference within items is not refcounted to avoid
    // circular references/memory leaks.
    // 
    // \warning
	// The pitem->GetParent() should always equal m_parent, but we cannot verify this
    // because the call to pitem->GetParent() might AddRef() an item that has already
    // been disposed.  So we just NULL it out.
    // 
                pitem->SetParent(NULL);
            }
        }
    }
/// \endcond

public:
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
		// Verify index is in bounds.
        if (index < FdoNamedCollection<OBJ, FdoCommandException>::GetCount() && index >= 0)
        {
            if (m_parent)
            {
			// Validate parentage for object to add.  Membership in a
			// collection implys parentage, and a object can only have
			// one parent.
            // 
                FdoPhysicalElementMappingP   pparent = value->GetParent();
                if (pparent && (pparent != m_parent) )
                    throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(COMMANDS_7_OBJECTHASPARENT),value->GetName()));
            }

            if (m_parent)
                value->SetParent(m_parent);
 
            FdoPtr<OBJ>    pitemOld = FdoNamedCollection<OBJ, FdoCommandException>::GetItem(index);
            FdoPhysicalElementMappingP   pparentOldItem = pitemOld->GetParent();
            if ( pparentOldItem == m_parent )
            {
    // When an object is removed from a collection, that
    // collection's owner is no longer the object's
    // parent.
    //
                pitemOld->SetParent(NULL);
            }
        }

        FdoNamedCollection<OBJ, FdoCommandException>::SetItem(index, value);
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
    virtual FdoInt32 Add(OBJ* value)
    {
        if (m_parent)
        {
		// Validate parentage for object to add.  Membership in a
		// collection implys parentage, and a object can only have
		// one parent.
        // 
            FdoPhysicalElementMappingP   pparent = value->GetParent();
            if (pparent && (pparent != m_parent) )
                throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(COMMANDS_7_OBJECTHASPARENT),value->GetName()));
        }

        if (m_parent)
            value->SetParent(m_parent);

        return FdoNamedCollection<OBJ, FdoCommandException>::Add(value);
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
    virtual void Insert(FdoInt32 index, OBJ* value)
    {
        if (m_parent)
        {
		// Validate parentage for object to add.  Membership in a
		// collection implys parentage, and a object can only have
		// one parent.
        // 
            FdoPhysicalElementMappingP  pparent = value->GetParent();
            if (pparent && (pparent != m_parent) )
                throw FdoCommandException::Create(FdoException::NLSGetMessage(FDO_NLSID(COMMANDS_7_OBJECTHASPARENT),value->GetName()));
        }

        if (m_parent)
            value->SetParent(m_parent);
 
        FdoNamedCollection<OBJ, FdoCommandException>::Insert(index, value);
    }

    /// \brief
    /// Removes all items from the collection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Clear()
    {
        if (m_parent)
        {
            for(FdoInt32 i = 0; i < FdoNamedCollection<OBJ, FdoCommandException>::GetCount(); i++)
            {
                FdoPtr<OBJ>    pitem = FdoNamedCollection<OBJ, FdoCommandException>::GetItem(i);
                FdoPhysicalElementMappingP   pparent = pitem->GetParent();

                if ( pparent == m_parent )
                {
				// When an object is removed from a collection, that
				// collection's owner is no longer the object's
				// parent.
                    pitem->SetParent(NULL);
                }
            }
        }

        FdoNamedCollection<OBJ, FdoCommandException>::Clear();
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
        if (m_parent)
        {
            // Cast drops const
            FdoPtr<OBJ>    pitem = (OBJ*)value;
            FdoPhysicalElementMappingP   pparent = pitem->GetParent();

            if ( pparent == m_parent )
            {
			// When an object is removed from a collection, that
			// collection's owner is no longer the object's
			// parent.
            // 
                pitem->SetParent(NULL);
            }
        }

        FdoNamedCollection<OBJ, FdoCommandException>::Remove(value);
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

        if (m_parent)
        {
            FdoPtr<OBJ>    pitem = FdoNamedCollection<OBJ, FdoCommandException>::GetItem(index);
            FdoPhysicalElementMappingP   pparent = pitem->GetParent();

            if ( pparent == m_parent )
            {
			// When an object is removed from a collection, that
			// collection's owner is no longer the object's
			// parent.
            // 
                pitem->SetParent(NULL);
            }

        }

        FdoNamedCollection<OBJ, FdoCommandException>::RemoveAt(index);
    }

/// \cond DOXYGEN-IGNORE
protected:

    /// m_parent is a non-refcounted reference, to avoid circular references that prevent
    /// elements from being freed.
    FdoPhysicalElementMapping*   m_parent;
/// \endcond
};

#endif



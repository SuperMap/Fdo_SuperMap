#ifndef _SCHEMACOLLECTION_H_
#define _SCHEMACOLLECTION_H_

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
#include <Fdo/Schema/SchemaElement.h>
#include <Fdo/Schema/SchemaException.h>

/// \brief
/// FdoSchemaCollection is an abstract template class that is used to
/// define schema collections; FdoClassCollection, FdoDatapropertyDefinitionCollection, 
/// FdoFeatureClassCollection, FdoFeatureSchemaCollection, FdoPropertyDefinitionCollection, and
/// FdoRelationCollection.
template <class OBJ> class FdoSchemaCollection : public FdoNamedCollection<OBJ, FdoSchemaException>
{

/// \cond DOXYGEN-IGNORE
protected:
    FdoSchemaCollection()
    {
    }

    FdoSchemaCollection(FdoSchemaElement* parent) : FdoNamedCollection<OBJ, FdoSchemaException>()
    {
        m_parent = parent;
        m_changeInfoState = 0;
        m_listCHANGED = NULL;
        m_sizeCHANGED = 0;
        if ( m_parent ) 
            m_setItemParent = true;
        else
            m_setItemParent = false;
    }

    virtual ~FdoSchemaCollection()
    {
        if (m_setItemParent && m_parent)
        {
            for(FdoInt32 i = 0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
            {
                OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);

            /// When the collection disappears, the ownership does too.
            /// So NULL out the parent.  This is necessary because the
            /// parent reference within items is not refcounted to avoid
            /// circular references/memory leaks.
            /// 
            /// \warning
            /// The pitem->GetParent() should always equal m_parent, but we cannot verify this
            /// because the call to pitem->GetParent() might AddRef() an item that has already
            /// been disposed.  So we just NULL it out.
            /// 
                pitem->SetParent(NULL);
                FDO_SAFE_RELEASE(pitem);
            }
        }

        /// Dispose of change information
        if (m_listCHANGED)
        {
            for (FdoInt32 i=0; i < m_sizeCHANGED; i++)
            {
                FDO_SAFE_RELEASE(m_listCHANGED[i]);
            }
            delete [] m_listCHANGED;
            m_listCHANGED = NULL;
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
    FDO_API virtual void SetItem(FdoInt32 index, OBJ* value)
    {
        if (index < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount() && index >= 0)   // verify index is in bounds
        {
            if (m_setItemParent && m_parent)
            {
            /// Validate parentage for object to add.  Membership in a
            /// collection implys parentage, and a object can only have
            /// one parent.
            /// 
                FdoSchemaElement*   pparent = value->GetParent();
                if (pparent)
                {
                /// OK, just restoring collection.
                    if (pparent == m_parent && (m_changeInfoState & CHANGEINFO_PROCESSING))
                        pparent->Release(); 
                    else
                    {
                        pparent->Release();
                        throw FdoSchemaException::Create(FdoException::NLSGetMessage(FDO_NLSID(SCHEMA_10_OBJECTHASPARENT)));
                    }
                }
            }
            _StartChanges();

            if (m_setItemParent && m_parent)
                value->SetParent(m_parent);
            /// Adding to a non-owning class does not change the state.
            /// \warning
            /// Do not change states during Accept/RejectChanges.
            ///
            if (m_setItemParent
                && !(m_changeInfoState & CHANGEINFO_PROCESSING))
            {
                value->SetElementState(FdoSchemaElementState_Added);
            }

            OBJ*    pitemOld = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(index);
            FdoSchemaElement*   pparentOldItem = pitemOld->GetParent();
            if ( pparentOldItem == m_parent )
            {
            /// When an object is removed from a collection, that
            /// collection's owner is no longer the object's
            /// parent.
            /// 
                pitemOld->SetParent(NULL);
                pitemOld->SetElementState(FdoSchemaElementState_Detached);
            }
            FDO_SAFE_RELEASE(pparentOldItem);
            FDO_SAFE_RELEASE(pitemOld);
        }

        FdoNamedCollection<OBJ, FdoSchemaException>::SetItem(index, value);
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
    FDO_API virtual FdoInt32 Add(OBJ* value)
    {
        if (m_setItemParent && m_parent)
        {
        /// Validate parentage for object to add.  Membership in a
        /// collection implys parentage, and a object can only have
        /// one parent.
        /// 
            FdoSchemaElement*   pparent = value->GetParent();
            if (pparent)
            {
                if (pparent == m_parent && (m_changeInfoState & CHANGEINFO_PROCESSING))
                    pparent->Release(); // OK, just restoring collection
                else
                {
                    pparent->Release();
                    throw FdoSchemaException::Create(FdoException::NLSGetMessage(FDO_NLSID(SCHEMA_10_OBJECTHASPARENT)));
                }
            }
        }
        _StartChanges();

        if (m_setItemParent && m_parent)
            value->SetParent(m_parent);
        /// Adding to a non-owning class does not change the state.
        /// \warning
        /// Do not change states during Accept/RejectChanges.
        ///
        if (m_setItemParent
            && !(m_changeInfoState & CHANGEINFO_PROCESSING))
        {
            value->SetElementState(FdoSchemaElementState_Added);
        }
        return FdoNamedCollection<OBJ, FdoSchemaException>::Add(value);
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
    FDO_API virtual void Insert(FdoInt32 index, OBJ* value)
    {
        if (m_setItemParent && m_parent)
        {
        /// Validate parentage for object to add.  Membership in a
        /// collection implys parentage, and a object can only have
        /// one parent.
        /// 
            FdoSchemaElement*   pparent = value->GetParent();
            if (pparent)
            {
            /// OK, just restoring collection.
                if (pparent == m_parent && (m_changeInfoState & CHANGEINFO_PROCESSING))
                    pparent->Release();
                else
                {
                    pparent->Release();
                    throw FdoSchemaException::Create(FdoException::NLSGetMessage(FDO_NLSID(SCHEMA_10_OBJECTHASPARENT)));
                }
            }
        }
        _StartChanges();

        if (m_setItemParent && m_parent)
            value->SetParent(m_parent);
        /// Adding to a non-owning class does not change the state.
        /// \warning
        /// Do not change states during Accept/RejectChanges.
        ///
        if (m_setItemParent
            && !(m_changeInfoState & CHANGEINFO_PROCESSING))
        {
            value->SetElementState(FdoSchemaElementState_Added);
        }
        FdoNamedCollection<OBJ, FdoSchemaException>::Insert(index, value);
    }

    /// \brief
    /// Removes all items from the collection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Clear()
    {
        _StartChanges();

        if (m_setItemParent && m_parent)
        {
            for(FdoInt32 i = 0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
            {
                OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
                FdoSchemaElement*   pparent = pitem->GetParent();

                if ( pparent == m_parent )
                {
                /// When an object is removed from a collection, that
                /// collection's owner is no longer the object's
                /// parent.
                /// 
                    pitem->SetParent(NULL);
                    pitem->SetElementState(FdoSchemaElementState_Detached);
                }

                FDO_SAFE_RELEASE(pparent);
                FDO_SAFE_RELEASE(pitem);
            }
        }

        FdoNamedCollection<OBJ, FdoSchemaException>::Clear();
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
    FDO_API virtual void Remove(const OBJ* value)
    {
        _StartChanges();

        if (m_setItemParent && m_parent)
        {
        /// Cast drops const.
            OBJ*    pitem = (OBJ*)value;
            FdoSchemaElement*   pparent = pitem->GetParent();

            if ( pparent == m_parent )
            {
            /// When an object is removed from a collection, that
            /// collection's owner is no longer the object's
            /// parent.
            /// 
                pitem->SetParent(NULL);
                pitem->SetElementState(FdoSchemaElementState_Detached);
            }

            FDO_SAFE_RELEASE(pparent);
        }

        FdoNamedCollection<OBJ, FdoSchemaException>::Remove(value);
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
    FDO_API virtual void RemoveAt(FdoInt32 index)
    {
        _StartChanges();

        if (m_setItemParent && m_parent)
        {
            OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(index);
            FdoSchemaElement*   pparent = pitem->GetParent();

            if ( pparent == m_parent )
            {
            /// When an object is removed from a collection, that
            /// collection's owner is no longer the object's
            /// parent.
            /// 
                pitem->SetParent(NULL);
                pitem->SetElementState(FdoSchemaElementState_Detached);
            }

            FDO_SAFE_RELEASE(pparent);
            FDO_SAFE_RELEASE(pitem);
        }

        FdoNamedCollection<OBJ, FdoSchemaException>::RemoveAt(index);
    }

/// \cond DOXYGEN-IGNORE
protected:
    /// States stored in the m_changeInfoState bitfield flag
    static const unsigned int   CHANGEINFO_PRESENT      = 0x00000001;
    static const unsigned int   CHANGEINFO_PROCESSING   = 0x00000002;
    static const unsigned int   CHANGEINFO_PROCESSED    = 0x00000004;

    FdoSchemaElement*   m_parent;
    bool                m_setItemParent;

    /// FdoFeatureSchema::RejectChanges() support
    FdoByte             m_changeInfoState;
    OBJ**               m_listCHANGED;
    FdoInt32            m_sizeCHANGED;

    virtual void _StartChanges()
    {
        if (!(m_changeInfoState & (CHANGEINFO_PRESENT|CHANGEINFO_PROCESSING)))
        {
            m_sizeCHANGED = FdoNamedCollection<OBJ, FdoSchemaException>::GetCount();

            if (m_sizeCHANGED > 0)
            {
                m_listCHANGED = new OBJ*[m_sizeCHANGED];
                for (FdoInt32 i=0; i < m_sizeCHANGED; i++)
                {
                    m_listCHANGED[i] = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
                }
            }

            m_changeInfoState |= CHANGEINFO_PRESENT;

            if (m_parent)
                m_parent->SetElementState(FdoSchemaElementState_Modified);
        }
    }

    virtual void _AcceptChanges()
    {
    /// Already processed.
        if (m_changeInfoState & CHANGEINFO_PROCESSED)
            return;
        m_changeInfoState |= CHANGEINFO_PROCESSED;

        if (m_changeInfoState & CHANGEINFO_PRESENT)
        {
        /// Reset.
            for (FdoInt32 i=0; i < m_sizeCHANGED; i++)
            {
            /// Accept changes to items once in this collection.
                m_listCHANGED[i]->_AcceptChanges();

            /// Release from change list.
                FDO_SAFE_RELEASE(m_listCHANGED[i]);
            }
            delete [] m_listCHANGED;
            m_listCHANGED = NULL;
            m_sizeCHANGED = 0;
        }

        /// Accept changes to items currently in this collection.
        for (FdoInt32 i=0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
        {
            FdoPtr<OBJ>    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);

            if (pitem->GetElementState() == FdoSchemaElementState_Deleted)
            {
            /// Really remove items marked for deletion.
                RemoveAt(i);
                i--;
            }

            pitem->_AcceptChanges();
        }
    }

    virtual void _RejectChanges()
    {
        /// Already processed.
        if (m_changeInfoState & CHANGEINFO_PROCESSED)
            return;
        m_changeInfoState |= CHANGEINFO_PROCESSED;

        if (m_changeInfoState & CHANGEINFO_PRESENT)
        {
        /// Restore.

        /// Reject changes to items currently in this collection.
            for (FdoInt32 i=0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
            {
                OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
                pitem->_RejectChanges();
                FDO_SAFE_RELEASE(pitem);
            }

            FdoNamedCollection<OBJ, FdoSchemaException>::Clear();
            for (FdoInt32 iChanged=0; iChanged < m_sizeCHANGED; iChanged++)
            {
                Add(m_listCHANGED[iChanged]);
                FDO_SAFE_RELEASE(m_listCHANGED[iChanged]);
            }

            /// Reset.
            delete [] m_listCHANGED;
            m_listCHANGED = NULL;
            m_sizeCHANGED = 0;
        }

        /// Reject changes to items now in this collection.
        for (FdoInt32 i=0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
        {
            OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
            pitem->_RejectChanges();
            FDO_SAFE_RELEASE(pitem);
        }
    }

    virtual void _BeginChangeProcessing()
    {
        /// Already marked for processing.
        if (m_changeInfoState & CHANGEINFO_PROCESSING)
            return;

        m_changeInfoState |= CHANGEINFO_PROCESSING;

        for (FdoInt32 i=0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
        {
            OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
            pitem->_BeginChangeProcessing();
            FDO_SAFE_RELEASE(pitem);
        }
    }

    virtual void _EndChangeProcessing()
    {
        /// Processing flag already cleared.
        if (!(m_changeInfoState & CHANGEINFO_PROCESSING))
            return;

        for (FdoInt32 i=0; i < FdoNamedCollection<OBJ, FdoSchemaException>::GetCount(); i++)
        {
            OBJ*    pitem = FdoNamedCollection<OBJ, FdoSchemaException>::GetItem(i);
            pitem->_EndChangeProcessing();
            FDO_SAFE_RELEASE(pitem);
        }

        m_changeInfoState = 0;
    }
/// \endcond
};
#endif



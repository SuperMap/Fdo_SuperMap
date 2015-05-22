#ifndef _COLLECTION_H_
#define _COLLECTION_H_
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
/// FdoCollection is an abstract template class for defining
/// standard collection access for all collection classes.
template <class OBJ, class EXC> class FdoCollection : public FdoIDisposable
{
protected:
    static const FdoInt32 INIT_CAPACITY = 10;

    FdoCollection()
    {
        m_capacity = INIT_CAPACITY;
        m_size = 0;
        m_list = new OBJ*[m_capacity];
    }

    virtual ~FdoCollection()
    {
        for(FdoInt32 i = 0; i < m_size; i++)
        {
            FDO_SAFE_RELEASE(m_list[i]);
        }

        delete[] m_list;
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
        return m_size;
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
    virtual OBJ* GetItem(FdoInt32 index) const
    {
        if (index >= m_size || index < 0)
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));
        return FDO_SAFE_ADDREF(m_list[index]);
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
        if (index < m_size && index >= 0)
        {
            FDO_SAFE_RELEASE(m_list[index]);
            m_list[index] = FDO_SAFE_ADDREF(value);
        }
        else
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));
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
        if (m_size == m_capacity)
            resize();

        m_list[m_size] = FDO_SAFE_ADDREF(value);
        return m_size++;
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
        FdoInt32    i;
        if (m_size == m_capacity) 
            resize();
        if (index <= m_size && index >= 0)
        {
            for (i = m_size; i > index; i--) 
                m_list[i] = m_list[i-1];

            m_list[index] = FDO_SAFE_ADDREF(value);
            m_size++;
        }
        else
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));
    }

    /// \brief
    /// Removes all items from the collection.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Clear()
    {
        FdoInt32    i;
        for (i = 0; i < m_size; i++) 
        {
            FDO_SAFE_RELEASE(m_list[i]);
            m_list[i] = NULL;
        }

        m_size = 0;
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
        FdoInt32    i;
        for (i = 0; i < m_size; i++) 
        {
            if (m_list[i] == value)
                break;
        }

        FDO_SAFE_RELEASE(m_list[i]);

        if (i == m_size)
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_6_OBJECTNOTFOUND)));
        
        while (i < m_size - 1) 
        {
            m_list[i] = m_list[i+1];
            i++;
        }

        m_list[--m_size] = NULL;
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
        if (index < m_size && index >= 0) 
        {
            FdoInt32    i;

            FDO_SAFE_RELEASE(m_list[index]);    // also NULLs out m_list[index]

            for (i = index; i < m_size-1; i++)
                m_list[i] = m_list[i+1];

            m_list[--m_size] = NULL;
        }
        else
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));
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
        FdoInt32    i;
        bool ret = false;
        for (i = 0; i < m_size; i++) {
            if (m_list[i] == value)
            {
                ret = true;
                break;
            }
        }
        return ret;
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
        FdoInt32    i, index = -1;
        for (i = 0; i < m_size; i++) {
            if (m_list[i] == value) 
            {
                index = i;        
                break;
            }
        }
        return index;
    }

private:

    void resize()
    {
        FdoInt32    i, old_capacity = m_capacity;
        m_capacity = (FdoInt32)(m_capacity*(1.4));
        OBJ** newArray = new OBJ*[m_capacity];
        for (i = 0; i < old_capacity; i++) {
            newArray[i] = m_list[i];
        }
        delete[] m_list;
        m_list = newArray;
    }

private:
    OBJ**       m_list;
    FdoInt32    m_capacity;
    FdoInt32    m_size;
};
#endif



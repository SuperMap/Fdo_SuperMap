#ifndef _READONLYCOLLECTION_H_
#define _READONLYCOLLECTION_H_
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

/// \brief
/// FdoReadOnlyCollection is an abstract template class used to define a collection
/// that can not be modified after it is constructed, i.e. provides read-only access.
template <class OBJ, class BASE, class EXC> class FdoReadOnlyCollection : public FdoIDisposable
{
protected:
    FDO_API FdoReadOnlyCollection()
    {
    }

    FDO_API virtual ~FdoReadOnlyCollection()
    {
        FDO_SAFE_RELEASE(m_base);
    }

    void SetBaseCollection(BASE* base)
    {
        FDO_SAFE_ADDREF(base);
        m_base = base;
    }

public:
    /// \brief
    /// Gets the number of items in the collection.
    /// 
    /// \return
    /// Returns number of items in the collection
    /// 
    FDO_API virtual FdoInt32 GetCount()
    {
        if (m_base)
            return m_base->GetCount();
        else
            return 0;
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
    FDO_API virtual OBJ* GetItem(FdoInt32 index)
    {
        if (m_base)
            return (OBJ*)m_base->GetItem(index);
        else
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INDEXOUTOFBOUNDS)));
    }

    /// \brief
    /// Gets the item in the collection with the specified name. Throws an invalid argument exception if an item with the specified name does not exist in the collection.
    /// 
    /// \param name 
    /// Input name to find
    /// 
    /// \return
    /// Returns the item in the collection with the specified name
    /// 
	FDO_API virtual OBJ* GetItem(FdoString* name)
	{
        if (name == NULL)
            throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADPARAMETER)));

        FdoInt32    size = GetCount();
        for (FdoInt32 i = 0; i < size; i++)
        {
            OBJ* pitem = GetItem(i);
            if (pitem != NULL && pitem->GetName() != NULL && wcscmp(name, pitem->GetName()) == 0)
                return pitem;
            FDO_SAFE_RELEASE(pitem);
        }
        throw EXC::Create(FdoException::NLSGetMessage(FDO_NLSID(SCHEMA_5_INVALIDELEMENTNAME)));
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
    FDO_API virtual bool Contains(const OBJ* value)
    {
        if (m_base)
            return m_base->Contains(value);
        else
            return false;
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
    FDO_API virtual FdoInt32 IndexOf(const OBJ* value)
    {
        if (m_base)
            return m_base->IndexOf(value);
        else
            return -1;
    }

private:
    BASE*   m_base;    
};
#endif



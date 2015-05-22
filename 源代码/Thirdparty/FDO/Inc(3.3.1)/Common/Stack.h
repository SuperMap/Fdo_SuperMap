#ifndef _STACK_H_
#define _STACK_H_
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

/// \cond DOXYGEN-IGNORE

/// \brief
/// FdoStack is an abstract template for a Stack ADT. This class is not yet
/// part of the FDOCommon API. However, doc comments have been added since it might
/// be added to the API in the future. All doc comments will need to change to
/// if this happens.
template <class OBJ, class EXC> class FdoStack : private FdoCollection<OBJ,EXC>
{

public:
    /// \brief
    /// Checks if the stack is empty
    /// 
    /// \return
    /// Returns true if the stack is empty
    /// 
    virtual FdoBoolean IsEmpty() const
    {
        return (FdoCollection <OBJ, EXC>::GetCount() == 0);
    }

    /// \brief
    /// Gets the top item on the stack without popping it
    /// 
    /// \return
    /// Returns the top item. Returns NULL if the stack is empty
    /// 
    virtual OBJ* Peek(void) const
    {
        if ( IsEmpty() ) 
            return NULL;

        return GetItem(FdoCollection <OBJ, EXC>::GetCount() - 1);
    }

    /// \brief
    /// Pushes the given item onto the stack
    /// 
    /// \param value 
    /// Input the item to push. This item becomes the top item.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Push(OBJ* value)
    {
        Add(value);
    }

    /// \brief
    /// Removes all items from the stack
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void Clear()
    {
        FdoCollection<OBJ,EXC>::Clear();
    }

    /// \brief
    /// Pops the top item off the stack. The previous top item becomes the top item.
    /// An exception is thrown if the stack is empty
    /// 
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual OBJ* Pop(void)
    {
        if ( IsEmpty() )
            throw EXC::Create(
                FdoException::NLSGetMessage(
                    FDO_NLSID(FDO_39_STACKPOP),
                    "Stack is empty, cannot pop."
                )
            );


        OBJ* pItem = Peek();
        RemoveAt(FdoCollection <OBJ, EXC>::GetCount() - 1);

        return pItem;
    }

    /// \brief
    /// Increase the reference count.
    /// 
    /// \return
    /// Returns the new reference count (value for debugging use only).
    /// 
    FDO_API_COMMON FdoInt32 AddRef() { return FdoCollection<OBJ,EXC>::AddRef(); }

    /// \brief
    /// Decrease the reference count.
    /// 
    /// \return
    /// Returns the new reference count (value for debugging use only).
    /// 
    FDO_API_COMMON FdoInt32 Release() { return FdoCollection<OBJ,EXC>::Release(); }

protected:
    /// \brief
    /// Gets an item at a given position in the stack. This
    /// function is protected so that FdoStack implementors can decide
    /// whether to expose it or restrict access to the top element only.
    /// 
    /// \param level 
    /// Input Get the element at this level. If 0 then
    /// the top element is returned. If 1 then the element just below the
    /// top element is returned, and so on.
    /// 
    /// \return
    /// Returns the requested item. Returns NULL if the stack is empty
    /// or level is out of range (less than 0 or greater or equal to 
    /// the number of elements in the stack
    /// 
	FDO_API_COMMON   virtual OBJ* Peek(int level) const
    {
        if ( level < 0 || (level >= FdoCollection <OBJ, EXC>::GetCount()) ) 
            return NULL;

        return GetItem(FdoCollection <OBJ, EXC>::GetCount() - level - 1);
    }

private:

};
/// \endcond

#endif



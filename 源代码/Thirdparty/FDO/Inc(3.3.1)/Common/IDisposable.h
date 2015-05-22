#ifndef _IDISPOSABLE_H_
#define _IDISPOSABLE_H_
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
/// FdoIDisposable is the base interface for all classes that implement this
/// standard interface for reference counting and object destruction.
class FdoIDisposable
{
protected:
    /// \brief
    /// Create an instance of the IDisposable object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API_COMMON FdoIDisposable() : m_refCount(1) {};

    /// \brief
    /// Default destructor for this class.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API_COMMON virtual ~FdoIDisposable() {};

    /// \brief
    /// Dispose this object.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API_COMMON virtual void Dispose() = 0;

public:
    /// \brief
    /// Increase the reference count.
    /// 
    /// \return
    /// Returns the new reference count (value for debugging use only).
    /// 
    FDO_API_COMMON virtual FdoInt32 AddRef() { return ++m_refCount; }

    /// \brief
    /// Decrease the reference count.
    /// 
    /// \return
    /// Returns the new reference count (value for debugging use only).
    /// 
    FDO_API_COMMON virtual FdoInt32 Release();

    /// \brief
    /// Retrieves the reference count.
    /// 
    /// \return
    /// Returns the existing reference count value.
    /// 
    FDO_API_COMMON virtual FdoInt32 GetRefCount() { return m_refCount; }

private:
    FdoInt32    m_refCount;
};

#include <Common/Exception.h>

inline
FdoInt32 FdoIDisposable::Release()
{
#ifdef _DEBUG
    if (m_refCount <= 0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_MEMORY_DEALLOCATION_ERROR), 
                                                           L"FdoIDisposable::Release",
                                                           L"FdoIDisposable"));
#endif
    if (0 != --m_refCount )
        return m_refCount;
    Dispose();
    return 0;
}


#define FDO_SAFE_RELEASE(x) {if (x) (x)->Release(); (x) = NULL;}
#define FDO_SAFE_ADDREF(x)  ((x != NULL) ? (x)->AddRef(), (x) : (NULL))
#endif



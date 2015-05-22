#ifndef _FDOPTR_H_
#define _FDOPTR_H_
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
/// This class ensures T implements AddRef() and Release() and also ensures
/// you cannot call it through the FdoPtr.
template <class T>
class _NoAddRefReleaseOnFdoPtr : public T
{
    private:
        virtual FdoInt32 AddRef()  = 0;
        virtual FdoInt32 Release() = 0;
};

template <class T>
#ifdef _WIN32
inline __declspec(nothrow) T* __stdcall FdoPtrAssign(T** pp, T* lp)
#else
inline T* FdoPtrAssign(T** pp, T* lp)
#endif
{
    if (lp != NULL)
        lp->AddRef();
    if (*pp)
        (*pp)->Release();
    *pp = lp;
    return lp;
}

/// \brief
/// FdoPtr is smart pointer to FDO objects. It automatically 
/// handles the memory management for these objects. In particular it handles
/// the adding and releasing of references on the objects, and their deletion
/// when the last reference is released.
///
/// When the FdoPtr goes out of scope, the FDO object that it references
/// is released.
template <class T>
class FdoPtr
{
public:
    typedef T _PtrClass;
    
    /// \brief
    /// Constructs a FdoPtr that initially points to NULL.
    /// 
    /// \return
    /// Returns a FdoPtr
    /// 
    FdoPtr()  throw()
    {
        p = NULL;
    }

    /// \brief
    /// Constructs a FdoPtr that initially points to NULL.
    /// 
    /// \param nNull 
    /// Input always 0
    /// 
    /// \return
    /// Returns a FdoPtr
    /// 
#ifdef _WIN32
    FdoPtr(FdoInt32 nNull) throw(...)
#else
    FdoPtr(FdoInt32 nNull) throw( FdoException *)
#endif
    {
        if (nNull != 0)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_CREATION),
                                                                   L"FdoPtr",
                                                                   L"nNull"));

        p = NULL;
    }

    /// \brief
    /// Constructs a FdoPtr around the given object.
    /// 
    /// \param lp 
    /// Input the object to wrap.
    /// 
    /// \return
    /// Returns a FdoPtr
    /// 
    /// \note
	/// This constructor just attaches the object to this FdoPtr. It does
    /// not add a reference on the object.
    FdoPtr(T* lp) throw()
    {
        p = lp;
    }

    /// \brief
    /// FdoPtr copy constructor. Wraps a new FdoPtr around the object
    /// referenced by lp.
    /// 
    /// \param lp 
    /// Input the FdoPtr to copy from.
    /// 
    /// \return
    /// Returns a FdoPtr
    /// 
    /// \note
	/// This operator adds a reference on the object.
    FdoPtr(const FdoPtr<T>& lp) throw()
    {
        p = lp.p;
        if (p != NULL)
            p->AddRef();
    }

    /// \brief
    /// FdoPtr destructor. If this FdoPtr points to an object
    /// then the object is released.
    /// 
    ~FdoPtr() throw()
    {
        if (p)
            p->Release();
    }

    /// \brief
    /// FdoPtr object extractor
    /// 
    /// \return
    /// Returns a pointer to the object referenced by this FdoPtr.
    /// 
    operator T*() const throw()
    {
        return p;
    }

    /// \brief
    /// FdoPtr object extractor
    /// 
    /// \return
    /// Returns the object referenced by this FdoPtr.
    /// 
#ifdef _WIN32
    T& operator*() const throw(...)
#else
    T& operator*() const throw(FdoException *)
#endif
    {
        if (p==NULL)
	        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                                   L"FdoPtr::operator*",
                                                                   L"p"));
        return *p;
    }

    /// \brief
    /// FdoPtr object extractor
    /// 
    /// \return
    /// Returns a double pointer to the object referenced by this FdoPtr.
    /// 
#ifdef _WIN32
    T** operator&() throw(...)
#else
    T** operator&() throw(FdoException *)
#endif
    {
        return &p;
    }
    
#ifdef _WIN32
    _NoAddRefReleaseOnFdoPtr<T>* operator->() const throw(...)
#else
    _NoAddRefReleaseOnFdoPtr<T>* operator->() const throw(FdoException *)
#endif
    {
        if (p==NULL)
	        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_INVALID_INPUT_ON_CLASS_FUNCTION),
                                                                   L"FdoPtr::operator->",
                                                                   L"p"));
        return (_NoAddRefReleaseOnFdoPtr<T>*)p;
    }
    
    /// \brief
    /// Is Null operator
    /// 
    /// \return
    /// Returns true if this FdoPtr points to NULL.
    /// 
    bool operator!() const throw()
    {
        return (p == NULL);
    }
    
    /// \brief
    /// Less than operator
    /// 
    /// \param pT
    /// Input the object to compare
    /// 
    /// \return
    /// Returns true if this FdoPtr points to an object whose
    /// address is less than the address of the given object.
    /// 
    bool operator<(T* pT) const  throw()
    {
        return p < pT;
    }
    
    /// \brief
    /// Equals operator
    /// 
    /// \param pT
    /// Input the object to compare
    /// 
    /// \return
    /// Returns true if this FdoPtr points to the given object.
    /// 
    bool operator==(T* pT) const throw()
    {
        return p == pT;
    }

    /// \brief
    /// Assignment operator. Wraps the given object in this 
    /// FdoPtr.
    /// 
    /// \param lp 
    /// Input the object to assign to this FdoPtr.
    /// 
    /// \return
    /// Returns lp
    /// 
    /// \note
	/// This operator just attaches the object to this FdoPtr. It does
    /// not add a reference on the object.
    T* operator=(T* lp) throw()
    {
        FDO_SAFE_RELEASE(p);
        p = lp;
        return p;
    }
    
    /// \brief
    /// Assignment operator for matching smart-pointer types. Assign the given FdoPtr's object to 
    /// this FdoPtr.
    /// 
    /// \param lp 
    /// Input the FdoPtr whose object is assigned to this FdoPtr.
    /// 
    /// \return
    /// Returns the object.
    /// 
    /// \note
	/// This operator adds a reference on the object and releases the object
    /// previously referenced by this FdoPtr.
    T* operator=(const FdoPtr<T>& lp) throw()
    {
        return static_cast<T*>(FdoPtrAssign<T>(&p, lp));
    }

    
    /// \brief
    /// Assignment operator for unmatched smart-pointer types. Assign the given FdoPtr's object to 
    /// this FdoPtr.
    /// 
    /// \param lp 
    /// Input the FdoPtr whose object is assigned to this FdoPtr.
    /// 
    /// \return
    /// Returns the object.
    /// 
    /// \note
	/// This operator adds a reference on the object and releases the object
    /// previously referenced by this FdoPtr.
    template<class U>
    T* operator=(const FdoPtr<U>& lp) throw()
    {
        return static_cast<T*>(FdoPtrAssign<T>(&p, lp));
    }

/// \cond DOXYGEN-IGNORE

    /// Release the object and set to NULL
    void Release() throw()
    {
        T* pTemp = p;
        if (pTemp)
        {
            p = NULL;
            pTemp->Release();
        }
    }
/// \endcond

    /// \brief
    /// Attaches the given object to this FdoPtr. It does
    /// not add a reference on the object. However, the object
    /// previously referenced by this FdoPtr is released.
    /// 
    /// \param p2 
    /// Input the object to attach.
    /// 
    void Attach(T* p2) throw()
    {
        if (p)
            p->Release();
        p = p2;
    }

    /// \brief
    /// Detaches this FdoPtr's object from this FdoPtr. It does
    /// not release the object.
    /// 
    /// \return
    /// Returns the object that was detached.
    /// 
    T* Detach() throw()
    {
        T* pt = p;
        p = NULL;
        return pt;
    }

    /// \brief
    /// Copies this FdoPtr's object to a double pointer. A reference
    /// is added to the object.
    /// 
    /// \param ppT 
    /// Input the double pointer.
    /// 
    /// \return
    /// Returns true if the object as copied, false if it could
    /// not be copied (double pointer is null).
    /// 
    bool CopyTo(T** ppT) throw()
    {
        if (ppT == NULL)
            return false;
        *ppT = p;
        if (p)
            p->AddRef();
        return true;
    }

    T* p;
};
#endif



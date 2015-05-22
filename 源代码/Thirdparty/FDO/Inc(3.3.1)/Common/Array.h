#ifndef _ARRAY_H_
#define _ARRAY_H_
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

#include <Common/ArrayHelper.h>


// Template for dynamic array.  It supports:
//  - shared ownership, via reference counting
//  - single allocation on heap for entire structure (no internal indirection)
//  - dynamic growth with infrequent reallocation
//  - hiding "new" and "delete" from callers that may have redefined these operators
//
// This class integrates its own needed member variables within
// the array itself.  This approach is very space efficient, as 
// it avoids the overhead of a level of indirection; there is no
// pointer to an internal, owned array.
//
// The tradeoffs to get these features are:
//  - any method call that could cause re-allocation is static, 
//    returning a (possibly new) location for the array object
//  - one cannot call re-allocating methods if the object is shared
//  - this class must never contain virtual methods (thus does its own reference counting)
//  - the allocation mechanism delegates to a helper class
//  - it is not typesafe for objects that cannot safely be moved around
//    in memory or which have non-empty destructors (it is safe for basic
//    types and most structs).
//
// Example:
//      FdoIntArray* ints = FdoIntArray::Create();
//      ints = FdoIntArray::Append(ints, 7);
//      FdoInt32 moreInts [] = { 8, 9 };
//      FdoInt32 numMoreInts = sizeof(moreInts)/sizeof(moreInts[0]);
//      ints = FdoIntArray::Append(ints, numMoreInts, moreInts);
//      int element = (*ints)[1];
//      cout << "The second element is " << element << endl;
//      FDO_SAFE_RELEASE(ints);

/// \brief
/// Abstract template class for defining dynamic arrays.
/// 
/// <span class="red_text"><b>WARNING:</b></span> This array uses a single memory allocation to store array elements
/// and may re-allocate that memory when the array size needs to change.
/// Therefore, do not keep pointers to array elements and avoid using 
/// for objects which cannot be safely moved around in memory or which have
/// non-empty destructors.
template <typename T> class FdoArray
{
public:

    /// \brief
    /// Create an empty array
    /// 
    /// \return
    /// Returns a FdoArray pointer
    /// 
    static FdoArray<T> * Create();
    /// \brief
    /// Create a dynamic array preallocated to a specific size
    /// 
    /// \param initialAlloc 
    /// Input initial size of the array
    /// 
    /// \return
    /// Returns a FdoArray pointer
    /// 
    static FdoArray<T> * Create(FdoInt32 initialAlloc);
    /// \brief
    /// Create a dynamic array from a pointer to a fixed array
    /// 
    /// \param elements 
    /// Input pointer to array of elements
    /// \param initialNumElements 
    /// Input number of elements to be added
    /// 
    /// \return
    /// Returns a FdoArray pointer
    /// 
    static FdoArray<T> * Create(const T* elements, FdoInt32 initialNumElements);

    /// \brief
    /// Increase the reference count.
    /// 
    /// \return
    /// Returns the new reference count. For debugging use only.
    /// 
    inline FdoInt32 AddRef() { return ++((FdoArrayHelper::GenericArray*)this)->m_metadata.refCount; }
    /// \brief
    /// Decrease the reference count.
    /// 
    /// \return
    /// Returns the new reference count. For debugging use only.
    /// 
    inline FdoInt32 Release()
    {
#ifdef _DEBUG
        if (((FdoArrayHelper::GenericArray*)this)->m_metadata.refCount <= 0)
            throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_MEMORY_DEALLOCATION_ERROR), 
                                                               L"FdoArray::Release",
                                                               L"FDO Array"));
#endif
        if (0 != --((FdoArrayHelper::GenericArray*)this)->m_metadata.refCount )
            return ((FdoArrayHelper::GenericArray*)this)->m_metadata.refCount;
        Dispose();
        return 0;
    }

    /// \brief
    /// Retrieves the reference count.
    /// 
    /// \return
    /// Returns the existing reference count value.
    /// 
    inline FdoInt32 GetRefCount() { return ((FdoArrayHelper::GenericArray*)this)->m_metadata.refCount; }

    /// \brief
    /// Gets the number of items in the array.
    /// 
    /// \return
    /// Returns number of items in the array
    /// 
    FdoInt32 GetCount() const { return ((FdoArrayHelper::GenericArray*)this)->m_metadata.size; }
    /// \brief
    /// Get a pointer to the data in the array.
    /// 
    /// \return
    /// Returns a pointer to the data
    /// 
    T* GetData() { return (T*)(((FdoArrayHelper::GenericArray*)this)->GetData()); }
    /// \brief
    /// Get a pointer to the data in the array.
    /// 
    /// \return
    /// Returns a pointer to the data
    /// 
    const T* GetData() const {return (const T*)(((FdoArrayHelper::GenericArray*)this)->GetData()); }

    /// \brief
    ///  Resize the array.
    /// 
    /// \return
    /// Returns the new array pointer.
    /// 
    static FdoArray<T> * SetSize(FdoArray<T> * array, FdoInt32 numElements);

    /// \brief
    /// Adds the specified array of items to the end of the array. Returns a new array pointer.
    /// 
    /// \param array 
    /// Input array pointer
    /// \param numElements 
    /// Input number of items to be added
    /// \param elements 
    /// Input pointer to array to append
    /// 
    /// \return
    /// Returns the new array pointer.
    /// 
    static FdoArray<T> * Append(FdoArray<T> * array, FdoInt32 numElements, T * elements);
    /// \brief
    /// Adds the specified item to the end of the array. Returns a new array pointer.
    /// 
    /// \param array 
    /// Input array pointer
    /// \param element 
    /// Input item to be appended to array
    /// 
    /// \return
    /// Returns the new array pointer.
    /// 
    static FdoArray<T> * Append(FdoArray<T> * array, T element);
    /// \brief
    /// Removes all items from the array.
    /// 
    /// \return
    /// Returns nothing
    /// 
    void Clear();

    /// \brief
    /// Provide index operator [] access to array members.
    /// 
    /// \param i 
    /// Input index to access
    /// 
    /// \return
    /// Returns the value of the specified item in the array.
    /// 
    const T& operator[](int i) const { return GetValue(i); }
    /// \brief
    /// Provide index operator [] access to array members.
    /// 
    /// \param i 
    /// Input index to access
    /// 
    /// \return
    /// Returns the value of the specified item in the array.
    /// 
    T& operator[](int i) { return GetValue(i); }

protected:
    /// Constructor
    FdoArray() {}

    static FdoArray<T> * AllocMore(FdoArray<T> * array, FdoInt32 atLeastThisMuch, bool exactly);
    static FdoArray<T> * SetAlloc(FdoArray<T> * array, FdoInt32 numElements);

    /// Access elements
    const T& GetValue(FdoInt32 i) const;
    T& GetValue(FdoInt32 i);
    void SetValue(FdoInt32 i, T newElement);

    /// the rest of FdoIDisposable
    void Dispose();
};

template <class T>
inline
FdoArray<T> * FdoArray<T>::Create()
{
    return AllocMore(0, 0, true);
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::Create(FdoInt32 initialAlloc)
{
    return AllocMore(0, initialAlloc, true);
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::Create(const T* elements, FdoInt32 initialNumElements)
{
    FdoArray<T> * array = AllocMore(0, initialNumElements, true);
    if (array != NULL)
        array = (FdoArray<T> *)FdoArrayHelper::Append((FdoArrayHelper::GenericArray*) array, initialNumElements, (FdoByte*) elements, sizeof(T));
    return array;
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::Append(FdoArray<T> * array, FdoInt32 numElements, T * elements)
{
    array = (FdoArray<T> *)FdoArrayHelper::Append((FdoArrayHelper::GenericArray*) array, numElements, (FdoByte*) elements, sizeof(T));
    return array;
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::Append(FdoArray<T> * array, T element)
{
    if ( ((FdoArrayHelper::GenericArray*)array)->m_metadata.size == ((FdoArrayHelper::GenericArray*)array)->m_metadata.alloc )
    {
        array = (FdoArray<T> *)FdoArrayHelper::AllocMore((FdoArrayHelper::GenericArray*) array, 1, false /*exactly*/, sizeof(T));
    }
    array->GetValue((((FdoArrayHelper::GenericArray*)array)->m_metadata.size)++) = element;
    return array;
}

template <class T>
inline
void FdoArray<T>::Clear()
{
    /// since no memory reallocation we can avoid input/output of array class pointer
    SetSize(this, 0);
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::SetSize(FdoArray<T> * array, FdoInt32 numElements)
{
    array = (FdoArray<T> *)FdoArrayHelper::SetSize((FdoArrayHelper::GenericArray*) array, numElements, sizeof(T));
    return array;
}

template <class T>
inline
FdoArray<T> * FdoArray<T>::SetAlloc(FdoArray<T> * array, FdoInt32 numElements)
{
    array = (FdoArray<T> *)FdoArrayHelper::SetAlloc((FdoArrayHelper::GenericArray*) array, numElements, sizeof(T));
    return array;
}

//
// Allocate some more memory for the array.
// If the given array is NULL, a new array of zero size 
// but the requested allocation is returned.
// The returned array will always have at least one new
// free element allocated. Thus, passing atLeastThisMuch < 1, 
// while not an error, still results in some new storage.
//
template <class T>
inline
FdoArray<T> * FdoArray<T>::AllocMore(FdoArray<T> * array, FdoInt32 atLeastThisMuch, bool exactly)
{
    array = (FdoArray<T> *)FdoArrayHelper::AllocMore((FdoArrayHelper::GenericArray*) array, atLeastThisMuch, exactly, sizeof(T));
    return array;
}

template <class T>
inline
void FdoArray<T>::Dispose()
{
    FdoArrayHelper::DisposeOfArray((FdoArrayHelper::GenericArray*) this, sizeof(T));
}

template <class T>
inline
const T& FdoArray<T>::GetValue(FdoInt32 i) const 
{
    if (i >= GetCount() || i < 0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));

    return *(this->GetData()+i); 
}

template <class T>
inline
T& FdoArray<T>::GetValue(FdoInt32 i) 
{
    if (i >= GetCount() || i < 0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));

    return *(this->GetData()+i); 
}

template <class T>
inline
void FdoArray<T>::SetValue(FdoInt32 i, T newElement) 
{
    if (i >= GetCount() || i < 0)
        throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_5_INDEXOUTOFBOUNDS)));

    *(this->GetData()+i) = newElement;
}

/// \ingroup (typedefs)
/// \brief
/// Dynamic array of bytes (FdoByte).
typedef FdoArray<FdoByte>   FdoByteArray;

/// \ingroup (typedefs)
/// \brief
/// Dynamic array of doubles (FdoDouble).
typedef FdoArray<FdoDouble> FdoDoubleArray;

/// \ingroup (typedefs)
/// \brief
/// Dynamic array of integers (FdoInt32).
typedef FdoArray<FdoInt32>  FdoIntArray;
//typedef FdoArray<FdoString> FdoStringArray;
#endif



#ifndef FDO_DICTIONARY_ELEMENT_H
#define FDO_DICTIONARY_ELEMENT_H
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

#include <Common/Disposable.h>

/// \brief
/// FdoDictionaryElement is an element in a FdoDictionary. It consists of a
/// name-value pair.
class FdoDictionaryElement : public FdoDisposable
{
    friend class FdoCommonInternal;

public:

    /// \brief
    /// Constructs and initializes a a FdoDictionaryElement
    /// 
    /// \param name 
    /// Input the name of the element (required)
    /// \param value
    /// Input the value of the element. Can be blank (L"")
    /// 
    /// \return
    /// Returns FdoDictionaryElement
    /// 
    FDO_API_COMMON static FdoDictionaryElement* Create(FdoString* name, FdoString* value);

    /// \brief
    /// Gets the name of this element
    /// 
    /// \return
    /// Returns the element name
    /// 
    FDO_API_COMMON virtual FdoString* GetName();

    /// \brief
    /// Indicates that this object does not allow its name
    /// to change. Not allowing name change allows more efficient 
    /// random access to FdoDictionary.
    /// 
    /// \return
    /// Returns false
    /// 
    FDO_API_COMMON virtual FdoBoolean CanSetName()
    {
        return false;
    }

    /// \brief
    /// Gets the value of this dictionary element.
    /// 
    /// \return
    /// Returns the element value
    /// 
    FDO_API_COMMON virtual FdoString* GetValue();

    /// \brief
    /// Sets the value of this dictionary element
    /// 
    /// \param value 
    /// Input the element value
    /// 
    FDO_API_COMMON virtual void SetValue(FdoString* value);

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a FdoDictionaryElement.
    FDO_API_COMMON FdoDictionaryElement()
    {
    }

    /// Constructs an instance of a FdoDictionaryElement using the specified arguments.
    FDO_API_COMMON FdoDictionaryElement(FdoString* name, FdoString* value);

    FDO_API_COMMON virtual ~FdoDictionaryElement() {}
/// \endcond

private:

    /// The name of the dictionary element. 
    FdoStringP                        mName;

    /// The element value
    FdoStringP                        mValue;
};

/// \ingroup (typedefs)
/// \brief
/// FdoDictionaryElementP is a FdoPtr on FdoDictionaryElement, provided for convenience.
typedef FdoPtr<FdoDictionaryElement> FdoDictionaryElementP;

#endif



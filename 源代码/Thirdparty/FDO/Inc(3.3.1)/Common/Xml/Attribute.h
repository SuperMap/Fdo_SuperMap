#ifndef FDO_XML_ATTRIBUTE_H
#define FDO_XML_ATTRIBUTE_H
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

#include <FdoCommon.h>

/// \brief
/// FdoXmlAttribute contains the name and value of a single attribute
/// from an XML document.
class FdoXmlAttribute : public FdoDictionaryElement
{
    friend class FdoCommonInternal;

public:
    /// \brief
    /// Constructs an XML Attribute object
    /// 
    /// \param name 
    /// Input unique attribute name. If the attribute name is namespace qualified
    /// the name is {uri}:{localName}. Otherwise, it is {localName}
    /// \param value 
    /// Input attribute value.
    /// \param localName 
    /// Input attribute name without namespace qualification.
    /// \param uri 
    /// Input uri for the attribute namespace. L"" if the attribute
    /// name is not namespace qualified.
    /// \param prefix 
    /// Input prefix for the attribute namespace. L"" if the attribute
    /// name is not namespace qualified.
    /// \param valueUri 
    /// Input uri for the attribute value's namespace. L"" if the attribute
    /// value is not namespace qualified.
    /// \param localValue 
    /// Input attribute value without namespace qualification.
    /// \param valuePrefix 
    /// Input prefix for the attribute value's namespace. L"" if the attribute
    /// value is not namespace qualified.
    /// 
    /// \return
    /// Returns FdoXmlAttribute
    /// 
    FDO_API_COMMON static FdoXmlAttribute* Create(
        FdoString* name, 
        FdoString* value, 
        FdoString* localName = NULL,
        FdoString* uri = NULL,
        FdoString* prefix = NULL,
        FdoString* valueUri = NULL,
        FdoString* localValue = NULL,
        FdoString* valuePrefix = NULL
    );

    /// \brief
    /// Gets the attribute's local name.
    /// 
    /// \return
    /// Returns FdoStringP. Same value is GetName() when attribute name not
    /// qualified by namespace
    /// 
    FdoStringP GetLocalName()
    {
        return mLocalName;
    }

    /// \brief
    /// Gets the attribute's namespace URI.
    /// 
    /// \return
    /// Returns FdoStringP. L"" when attribute name not
    /// qualified by namespace
    /// 
    FdoStringP GetUri()
    {
        return mUri;
    }

    /// \brief
    /// Gets the attribute's namespace prefix.
    /// 
    /// \return
    /// Returns FdoStringP. L"" when attribute name not
    /// qualified by namespace
    /// 
    FdoStringP GetPrefix()
    {
        return mPrefix;
    }

    /// \brief
    /// Gets the attribute value's namespace URI.
    /// 
    /// \return
    /// Returns FdoStringP. L"" when attribute value not
    /// qualified by namespace
    /// 
    FdoStringP GetValueUri()
    {
        return mValueUri;
    }

    /// \brief
    /// Gets the attribute's local value.
    /// 
    /// \return
    /// Returns FdoStringP. Same value is GetValue() when attribute value is not
    /// qualified by namespace
    /// 
    FdoStringP GetLocalValue()
    {
        return mLocalValue;
    }

    /// \brief
    /// Gets the attribute value's namespace prefix.
    /// 
    /// \return
    /// Returns FdoStringP. L"" when attribute value is not
    /// qualified by namespace
    /// 
    FdoStringP GetValuePrefix()
    {
        return mValuePrefix;
    }

    /// \brief
    /// Gets the attribute's qualified name.
    /// 
    /// \return
    /// Returns {prefix}:{localName} when attribute name is qualified by namespace.
    /// Otherwise, returns the same value as GetLocalName().
    /// 
    FdoStringP GetQName()
    {
        return mPrefix.GetLength() > 0 ?
                    mPrefix + L":" + mLocalName :
                    mLocalName;
    }

protected:
/// \cond DOXYGEN-IGNORE
    FdoXmlAttribute()
        : FdoDictionaryElement()
    {
    }

    FdoXmlAttribute(
        FdoString* name, 
        FdoString* value, 
        FdoString* localName,
        FdoString* uri,
        FdoString* prefix,
        FdoString* valueUri,
        FdoString* localValue,
        FdoString* valuePrefix
    );

/// \endcond

private:
    FdoStringP mLocalName;
    FdoStringP mUri;
    FdoStringP mPrefix;
    FdoStringP mValueUri;
    FdoStringP mLocalValue;
    FdoStringP mValuePrefix;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlAttributeP is a FdoPtr on FdoXmlAttribute, provided for convenience.
typedef FdoPtr<FdoXmlAttribute> FdoXmlAttributeP;

#endif



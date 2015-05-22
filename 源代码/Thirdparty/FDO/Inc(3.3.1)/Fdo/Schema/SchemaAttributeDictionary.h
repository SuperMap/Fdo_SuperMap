#ifndef _SCHEMAATTRIBUTEDICTIONARY_H_
#define _SCHEMAATTRIBUTEDICTIONARY_H_

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

class FdoSchemaElement;
class FdoSchemaXmlContext;

/// \brief
/// The FdoSchemaAttributeDictionary class maintains a dictionary of named 
/// attributes that provide a generic extensibility mechanism for objects
/// in the feature schema. This mechanism can be used to dynamically extend 
/// schema elements in either an application- or provider-specific manner.
class FdoSchemaAttributeDictionary : 
    public FdoIDisposable,
    public virtual FdoXmlSaxHandler
{
    friend class FdoSchemaElement;

/// \cond DOXYGEN-IGNORE
protected:
    FdoSchemaAttributeDictionary()
	{
	}	
    FdoSchemaAttributeDictionary(FdoSchemaElement& parent);

    virtual ~FdoSchemaAttributeDictionary();

    virtual void Dispose();

    /// Write this SAD to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );
/// \endcond

public:
    /// \brief
    /// Gets the number of attributes in the dictionary.
    /// 
    /// \return
    /// Returns the number of attributes in the dictionary
    /// 
    FDO_API FdoInt32 GetCount();

    /// \brief
    /// Gets an array containing all of the attribute names in the dictionary.
    /// 
    /// \param length 
    /// Output number of attribute names
    /// 
    /// \return
    /// Returns an array containing all of the attribute names in the dictionary
    /// 
    FDO_API FdoString** GetAttributeNames(FdoInt32& length);

    /// \brief
    /// Gets the value of the specified attribute.
    /// 
    /// \param name 
    /// Input attribute name
    /// 
    /// \return
    /// Returns the value of the specified attribute
    /// 
    FDO_API FdoString* GetAttributeValue(FdoString* name);

    /// \brief
    /// Sets the value of the specified attribute.
    /// 
    /// \param name 
    /// Input name
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetAttributeValue(FdoString* name, FdoString* value);

    /// \brief
    /// Returns true if the dictionary contains the specified attribute.
    /// 
    /// \param name 
    /// Input attribute name
    /// 
    /// \return
    /// Returns true if the dictionary contains the specified attribute
    /// 
    FDO_API bool ContainsAttribute(FdoString* name);

    /// \brief
    /// Adds the specified attribute with the specified value to the dictionary.
    /// 
    /// \param name 
    /// Input name
    /// \param value 
    /// Input value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Add(FdoString* name, FdoString* value);

    /// \brief
    /// Removes the specified attribute and its value from the dictionary.
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Remove(FdoString* name);

    /// \brief
    /// Clears all attributes and values from the dictionary.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Clear();

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML support

    /// Handle the start of a dictionary element
    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    /// Handle the end of a dictionary element
    virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );


private:
    FdoInt32            m_alloc;
    FdoInt32            m_used;
    wchar_t**           m_names;
    wchar_t**           m_values;
    FdoSchemaElement*   m_parent;

    /// SAX Handler for reading dictionary element values
    FdoXmlCharDataHandlerP        m_XmlContentHandler;
    /// When deserializing from XML, contains the name of the 
    /// current SAD item.
    FdoStringP                    m_nextName;


protected:
    /// FdoFeatureSchema::RejectChanges() support
    virtual void    _StartChanges();
    virtual void    _BeginChangeProcessing();
    virtual void    _AcceptChanges();
    virtual void    _RejectChanges();
    virtual void    _EndChangeProcessing();
    unsigned int        m_changeInfoState;
    FdoInt32            m_allocCHANGED;
    FdoInt32            m_usedCHANGED;
    wchar_t**           m_namesCHANGED;
    wchar_t**           m_valuesCHANGED;

    /// States stored in the m_changeInfoState bitfield flag
    static const unsigned int   CHANGEINFO_PRESENT      = 0x00000001;
    static const unsigned int   CHANGEINFO_PROCESSING   = 0x00000002;
    static const unsigned int   CHANGEINFO_PROCESSED    = 0x00000004;
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoSADP is a FdoPtr on FdoSchemaAttributeDictionary, provided for convenience.
typedef FdoPtr<FdoSchemaAttributeDictionary> FdoSADP;


#endif



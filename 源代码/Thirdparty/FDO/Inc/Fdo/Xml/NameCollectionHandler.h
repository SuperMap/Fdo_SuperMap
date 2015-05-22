#ifndef FDO_XML_NAMECOLLECTIONHANDLER_H
#define FDO_XML_NAMECOLLECTIONHANDLER_H

// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <FdoStd.h>
#include <FdoCommon.h>

class FdoXmlFlags;

/// \brief
/// FdoXmlNameCollectionHandler is a class for serializing and 
/// deserializing fdo:NameCollectionType elements.
class FdoXmlNameCollectionHandler :
    public FdoDisposable,
    public FdoXmlSaxHandler
{
public:
    /// \brief
    /// Constructs an Fdo XML Name Collection Handler.
    /// 
    /// \param pNames 
    /// Input the collection of names. Any names deserialized
    /// will be added to this collection. If NULL then an internal empty
    /// name collection is created.
    /// 
    /// \return
    /// Returns FdoXmlNameCollectionHandler
    /// 
    FDO_API static FdoXmlNameCollectionHandler* Create(FdoStringCollection* pNames = NULL);

    /// \brief
    /// Gets the collection of names
    /// 
    /// \return
    /// Returns the element content.
    /// 
    FDO_API FdoStringCollection* GetNames();

    /// XML Serialization functions, not part of supported API.

    /// _writeXml serializes each name in the collection as a 
    /// [Name] element.
    virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* saxContext, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    virtual FdoBoolean XmlEndElement(
        FdoXmlSaxContext* saxContext, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );

protected:
    FdoXmlNameCollectionHandler();
    FdoXmlNameCollectionHandler(FdoStringCollection* pNames);
    virtual ~FdoXmlNameCollectionHandler(void);

private:
    /// The names in the name collection
    FdoStringsP                 mNames;

    /// SAX Handler for deserializing a single name.
    FdoXmlCharDataHandlerP      mNameHandler;
    /// SAX Handler for skipping elements
    FdoXmlSkipElementHandlerP   mXmlSkipper;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlNameCollectionHandlerP is a FdoPtr on FdoXmlNameCollectionHandler, provided for convenience.
typedef FdoPtr<FdoXmlNameCollectionHandler> FdoXmlNameCollectionHandlerP;

#endif



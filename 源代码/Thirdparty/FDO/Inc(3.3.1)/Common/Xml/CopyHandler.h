#ifndef FDO_XML_COPYHANDLER_H
#define FDO_XML_COPYHANDLER_H
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
/// FdoXmlCopyHandler can be used to copy a set of elements from one XML
/// document to another. It can be created and set as the SAX Handler for an XML Reader
/// on the document to copy from. An XML Writer to the document to copy to is 
/// passed to one of the Create methods below. The elements to copy will be inserted
/// at the XML writer's current position.
class FdoXmlCopyHandler : 
    public FdoDisposable,
    public FdoXmlSaxHandler
{
public:
    /// \brief
    /// Constructs a Copy Handler. When attached (as the SAX Handler) to 
    /// a FdoXmlReader, this object copies all sub-elements of the current element
    /// being parsed.
    /// 
    /// \param writer 
    /// Input the sub-elements are written to this XML writer.
    /// 
    /// \return
    /// Returns FdoXmlCopyHandler
    /// 
    FDO_API_COMMON static FdoXmlCopyHandler* Create( FdoXmlWriter* writer )
    {
        return new FdoXmlCopyHandler( writer );
    }

    /// \brief
    /// Constructs a Copy Handler. When attached (as the SAX Handler) to 
    /// a FdoXmlReader, this object copies the current element
    /// being parsed, plus all of its sub-elements. 
    /// 
    /// \param writer 
    /// Input the sub-elements are written to this XML writer.
    /// \param uri 
    /// Input current element's Universal Resource Indicator
    /// \param name 
    /// Input the unqualified name of the current element (doesn't include namespace)
    /// \param qName 
    /// Input the qualified name of the current element(includes namespace)
    /// \param atts 
    /// Input the attributes for the current element. 
    /// \warning 
    /// If the current element will become the root element in the destination 
    /// document, the caller is responsible for including all required xmlns: namespace
    /// declarations in the atts list.
    /// \param namespaces 
    /// Input list of XML namespace declarations to write to the 
    /// destination document.
    /// 
    /// \return
    /// Returns FdoXmlCopyHandler
    /// 
    FDO_API_COMMON static FdoXmlCopyHandler* Create( 
        FdoXmlWriter* writer,
        FdoString* uri,
        FdoString* name, 
        FdoString* qName, 
        FdoXmlAttributeCollection* atts,
        FdoDictionary* namespaces = NULL
    )
    {
        return new FdoXmlCopyHandler( writer, uri, name, qName, atts, namespaces );
    }

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlCopyHandler() {}
/// \endcond

    FDO_API_COMMON FdoXmlCopyHandler( FdoXmlWriter* writer );

    FDO_API_COMMON FdoXmlCopyHandler( 
        FdoXmlWriter* writer,
        FdoString* uri,
        FdoString* name, 
        FdoString* qName, 
        FdoXmlAttributeCollection* atts,
        FdoDictionary* namespaces = NULL
    );

    FDO_API_COMMON virtual ~FdoXmlCopyHandler();

/// \cond DOXYGEN-IGNORE
    void SetWriter( FdoXmlWriter* writer );

    /// General function for writing start of an element.
    /// Handles namespace translation, of the element name,
    /// between the source and destination documents.

    void WriteStartElement(
        FdoString* uri , 
        FdoString* name, 
        FdoString* qName, 
        FdoXmlAttributeCollection* atts
    );

    /// writes the given set of XML namespaces to the output document
    void WriteNamespaces( FdoDictionary* namespaces );

    /// handles an attribute qualified by namespace. Adds namespace declaration
    /// to output document if not already there.
    FdoStringP HandleQAtt(FdoStringP uri, FdoStringP localName, FdoStringP prefix, FdoStringP QName );


    /// SAX handlers to catch and copy various XML fragments.

    FDO_API_COMMON virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext*, FdoString*, FdoString* name, FdoString*, FdoXmlAttributeCollection*);
    FDO_API_COMMON virtual FdoBoolean XmlEndElement(FdoXmlSaxContext*, FdoString*, FdoString*, FdoString* qName);
    FDO_API_COMMON virtual void XmlCharacters(FdoXmlSaxContext*, FdoString*);

/// \endcond

    /// \brief
    /// This function is called before each attribute is copied to the 
    /// destination document. It determines whether the attribute value
    /// references a qualified XML element name. If it does, then the
    /// namespace prefix for the value is converted to the equivalent prefix 
    /// in the destination document.
    /// 
    /// \param uri 
    /// Input the namespace URI for attribute's containing element.
    /// \param name 
    /// Input the local name for attribute's containing element.
    /// \param qName 
    /// Input the fully qualified name from attribute's containing element.
    /// \param att 
    /// Input the attribute to check.
    /// 
    /// \return
    /// returns true if the attribute value is a qualified XML element name.
    /// This default implementation returns true only if the containing element
    /// is in the XML Schema namespace and the attribute name is one of 
    /// ("base","type","ref"). Classes derived from FdoXmlCopyHandler
    /// can override this virtual function to change this behaviour.
    /// 
    FDO_API_COMMON virtual FdoBoolean AttHasNs(
        FdoString* uri,
        FdoString* name, 
        FdoString* qName, 
        FdoXmlAttribute* att
    );

private:
    FdoXmlWriterP mWriter;
    FdoBoolean mWroteCurrElement;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlCopyHandlerP is a FdoPtr on FdoXmlCopyHandler, provided for convenience.
typedef FdoPtr<FdoXmlCopyHandler> FdoXmlCopyHandlerP;

#endif



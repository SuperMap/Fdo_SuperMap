#ifndef FDO_XML_SAXHANDLER_H
#define FDO_XML_SAXHANDLER_H
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
/// FdoXmlSaxHandler defines the FDO SAX Handler callback interface.
/// It is not an interface in the strict sense, since each function has a 
/// default implementation that does nothing. Implementors can override these
/// callbacks to customize the handling of XML fragments parsed by FdoXmlReader.
class FdoXmlSaxHandler
{
public:

    /// \brief
    /// Default Sax callback that is called when the FdoXmlReader 
    /// starts reading an XML document. Does nothing.
    /// 
    /// \param saxContext 
    /// Input caller specified contextual information
    /// 
    /// \return
    /// Returns the SAX Handler for the document's root element. If NULL then 
    /// this SAX handler will handle the root element
    /// 
    FDO_API_COMMON virtual FdoXmlSaxHandler* XmlStartDocument(FdoXmlSaxContext* saxContext);

    /// \brief
    /// Default Sax callback that is called when the FdoXmlReader 
    /// finishes reading an XML document. Does nothing
    /// 
    /// \param saxContext 
    /// Input caller specified contextual information
    /// 
    FDO_API_COMMON virtual void XmlEndDocument(FdoXmlSaxContext* saxContext);

    /// \brief
    /// Default Sax callback that is called when the FdoXmlReader 
    /// reads the start tag for an XML element in the document. Does nothing.
    /// 
    /// \param saxContext 
    /// Input caller specified contextual information
    /// \param uri 
    /// Input the element's Universal Resource Indicator
    /// \param name 
    /// Input the unqualified element name (doesn't include namespace)
    /// \param qname 
    /// Input the qualified element name (includes namespace)
    /// \param atts 
    /// Input the attributes for the element.
    /// 
    /// \return
    /// Returns the SAX Handler for the element's sub-elements. If NULL then 
    /// this SAX handler will handle the sub-elements
    /// 
    FDO_API_COMMON virtual FdoXmlSaxHandler* XmlStartElement(FdoXmlSaxContext* saxContext, FdoString* uri, FdoString* name, FdoString* qname, FdoXmlAttributeCollection* atts);

    /// \brief
    /// Default Sax callback that is called when the FdoXmlReader 
    /// reads the end tag for an XML element in the document. Does nothing.
    /// 
    /// \param saxContext 
    /// Input caller specified contextual information
    /// \param uri 
    /// Input the element's Universal Resource Indicator
    /// \param name 
    /// Input the unqualified element name (doesn't include namespace)
    /// \param qname 
    /// Input the qualified element name (includes namespace)
    /// 
    /// \return
    /// Returning true causes the current parse to stop. Returning false
    /// cause the parse to continue. Return value is ignored if the current parse
    /// is not an incremental parse ( see FdoXmlReader::Parse())
    /// 
    FDO_API_COMMON virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* saxContext, FdoString* uri, FdoString* name, FdoString* qname);

    /// \brief
    /// Default Sax callback that is called when the FdoXmlReader 
    /// reads a chunk of simple content for the current element. Does nothing by default.
    /// This function may be called multiple times for the same element, if the 
    /// the content is long. Applications must not make any assumptions about the
    /// chunk size or number of chunks for each element
    /// 
    /// \param saxContext 
    /// Input caller specified contextual information
    /// \param chars 
    /// Input the next chunk of simple content
    /// 
    FDO_API_COMMON virtual void XmlCharacters(FdoXmlSaxContext* saxContext, FdoString* chars);
};

#endif



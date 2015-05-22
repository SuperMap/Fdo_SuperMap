#ifndef FDO_XML_SKIPELEMENTHANDLER_H
#define FDO_XML_SKIPELEMENTHANDLER_H
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
/// FdoXmlSkipHandler can be used to skip an XML element, when reading an 
/// XML document via FdoXmlReader. It is a FdoXmlSaxHandler with no callback 
/// implementations. Therefore, if another FdoXmlSaxHandler's XmlStartElement
/// callback returns a FdoXmlSkipElementHandler then there are no more SAX events
/// until the end of the current element is reached.
class FdoXmlSkipElementHandler : 
    public FdoDisposable,
    public FdoXmlSaxHandler
{
public:
    /// \brief
    /// Constructs a SAX Handler for skipping an element.
    /// 
    /// \return
    /// Returns FdoXmlSkipElementHandler
    /// 
    FDO_API_COMMON static FdoXmlSkipElementHandler* Create()
    {
        return new FdoXmlSkipElementHandler();
    }

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlSkipElementHandler() {}
    ~FdoXmlSkipElementHandler() {}
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSkipElementHandlerP is a FdoPtr on FdoXmlSkipElementHandler, provided for convenience.
typedef FdoPtr<FdoXmlSkipElementHandler> FdoXmlSkipElementHandlerP;

#endif



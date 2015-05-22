#ifndef FDO_XML_CHARDATAHANDLER_H
#define FDO_XML_CHARDATAHANDLER_H
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
/// FdoXmlCharDataHandler is convenience class for reading XML element content.
/// When FdoXmlReader encounters the start of an element with simple content, an object
/// of this class can be constructed and pushed onto the FdoXmlReader's SAX handler 
/// stack. When the end of the element is reached, the object will contain all of
/// the element's content.
class FdoXmlCharDataHandler :
    public FdoDisposable,
    public FdoXmlSaxHandler
{
public:
    /// \brief
    /// Constructs a Char Data Handler.
    /// 
    /// \return
    /// Returns FdoXmlCharDataHandler
    /// 
    FDO_API_COMMON static FdoXmlCharDataHandler* Create(void);

    /// \brief
    /// Gets the element content that has been read sofar. When the end of the
    /// element is reached, this will contain all of the element content.
    /// 
    /// \return
    /// Returns the element content.
    /// 
    FDO_API_COMMON FdoString* GetString()
    {
        return(mString);
    }

protected:
/// \cond DOXYGEN-IGNORE
    FdoXmlCharDataHandler(void);
    virtual ~FdoXmlCharDataHandler(void);

    /// Overridden Sax Callback. Receives the next chunk of element content.
    virtual void XmlCharacters(FdoXmlSaxContext*, FdoString *chars);
/// \endcond

private:
    /// The element content read sofar
    FdoStringP mString;

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlCharDataHandlerP is a FdoPtr on FdoXmlCharDataHandler, provided for convenience.
typedef FdoPtr<FdoXmlCharDataHandler> FdoXmlCharDataHandlerP;

#endif



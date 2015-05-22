#ifndef FDO_XML_SAXCONTEXT_H
#define FDO_XML_SAXCONTEXT_H
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

class FdoXmlReader;

/// \brief
/// FdoXmlSaxContext provides contextual information to the 
/// FdoMathUtility callback implementations when an XML document parse
/// is in progress. This class provides very rudimentary functionality such as
/// error reporting and access to the FdoXmlReader doing the parse. Applications
/// can pass extra information by sub-classing from this class.
class FdoXmlSaxContext : public FdoContext
{
public:
    /// \brief
    /// Constructs the default Sax Context
    /// 
    /// \param reader 
    /// Input the FdoXmlReader that is parsing the XML document.
    /// 
    /// \return
    /// Returns FdoXmlSaxContext
    /// 
    FDO_API_COMMON static FdoXmlSaxContext* Create(FdoXmlReader* reader);

    /// \brief
    /// Gets the FdoXmlReader that is parsing the XML document.
    /// 
    /// \return
    /// Returns FdoXmlReader
    /// 
    FDO_API_COMMON FdoXmlReader* GetReader();

protected:
    /// Default constructor to keep g++ from complaining.
    FDO_API_COMMON FdoXmlSaxContext();
    FDO_API_COMMON FdoXmlSaxContext(FdoXmlReader* reader);
    FDO_API_COMMON virtual ~FdoXmlSaxContext();

private:
    /// Current XML Reader.
    FdoXmlReader*  mpReader;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSaxContextP is a FdoPtr on FdoXmlSaxContext, provided for convenience.
typedef FdoPtr<FdoXmlSaxContext> FdoXmlSaxContextP;

#endif



#ifndef FDO_XML_FEATURECONTEXT_H
#define FDO_XML_FEATURECONTEXT_H

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
#include <Common/Xml/SaxContext.h>

class FdoXmlFeaturePropertyReader;

/// \brief
/// FdoXmlFeatureContext provides contextual information to the FdoXmlFeatureHandler 
/// callback implementations when an XML document parse is in progress. This class 
/// provides very rudimentary functionality such as error reporting and access to the 
/// FdoXmlFeaturePropertyReader doing the parse. Applications can pass extra information
/// by sub-classing from this class.
class FdoXmlFeatureContext : public FdoXmlSaxContext
{
public:
    /// \brief
    /// Constructs an XML  feature context
    /// 
    /// \param reader 
    /// Input the FdoXmlFeaturePropertyReader that is parsing the XML document.
    /// 
    /// \return
    /// Returns FdoXmlFeatureContext
    /// 
    FDO_API static FdoXmlFeatureContext* Create(FdoXmlFeaturePropertyReader* reader);

    /// \brief
    /// Gets the FdoXmlFeaturePropertyReader that is parsing the XML document.
    /// 
    /// \return
    /// Returns FdoXmlFeaturePropertyReader
    /// 
    FDO_API virtual FdoXmlFeaturePropertyReader* GetFeaturePropertyReader();

protected:
	FdoXmlFeatureContext(FdoXmlFeaturePropertyReader* reader);
	virtual ~FdoXmlFeatureContext();
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFeatureContextP is a FdoPtr on FdoXmlFeatureContext, provided for convenience.
typedef FdoPtr<FdoXmlFeatureContext> FdoXmlFeatureContextP;

#endif



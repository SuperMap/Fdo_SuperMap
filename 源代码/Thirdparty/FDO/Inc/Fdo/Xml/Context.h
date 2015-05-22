#ifndef FDO_XML_CONTEXT_H
#define FDO_XML_CONTEXT_H

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

#include <FdoStd.h>
#include <Fdo/Xml/Flags.h>

/// \brief
/// Default context for deserializing from XML documents via
/// FdoXmlDeserializable.
class FdoXmlContext : public FdoXmlSaxContext
{
public:
    /// \brief
    /// Constructs a context for parsing FDO Deserializable items
    /// 
    /// \param flags 
    /// Input flags.
	 ///
	 /// \param xmlReader
	 /// Input xmlReader.
    /// 
	 /// \return
	 /// Returns FdoXmlContext.
	FDO_API static FdoXmlContext* Create( FdoXmlFlags* flags, FdoXmlReader* xmlReader );

    /// \brief
    /// Decodes any element name that was encoded to be XML-compatible.
    /// 
	 /// \param name
	 /// Input name.
	 ///
	 /// \return
	 /// Returns FdoStringP.
    FDO_API FdoStringP DecodeName ( FdoStringP name );

    /// \brief
    /// Retrieves the current XML flags.
    /// 
	 /// \return
	 /// Returns FdoXmlFlags.
    FDO_API FdoXmlFlags* GetFlags();


protected:
    FdoXmlContext() {}
	FDO_API FdoXmlContext( FdoXmlFlags* flags, FdoXmlReader* xmlReader );
    FDO_API virtual ~FdoXmlContext();


private:
    FdoXmlFlagsP mFlags;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlContextP is an FdoPtr on FdoXmlContext provided for convenience.
typedef FdoPtr<FdoXmlContext> FdoXmlContextP;

#endif



#ifndef FDO_XML_DESERIALIZABLE_H
#define FDO_XML_DESERIALIZABLE_H

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
/// FdoXmlDeserializable provides the ability to deserialize an FDO object 
/// from an XML Document. Deserialization support can be added to any class by basing
/// it on FdoXmlDeserializable and implementing the FdoXmlSaxHander callbacks.
class FdoXmlDeserializable : public FdoXmlSaxHandler
{
public:

    /// \brief
    /// Reads from an XML document in a file.
    /// 
    /// \param fileName 
    /// Input the file name. Must consist of an XML document.
    /// \param flags 
    /// Input controls the reading of the elements from the document.
    /// If NULL then the default flags are used (see FdoXmlFlags::Create())
    /// 
	FDO_API virtual void ReadXml(
 		FdoString* fileName, 
    	FdoXmlFlags* flags = NULL
	);

    /// \brief
    /// Reads an XML document from an XML reader.
    /// 
    /// \param xmlReader 
    /// Input the XML reader.
    /// \param flags 
    /// Input controls the reading of the elements from the document. 
    /// If NULL then the default flags are used (see FdoXmlFlags::Create())
    /// 
	FDO_API virtual void ReadXml(
       	FdoXmlReader* xmlReader, 
    	FdoXmlFlags* flags = NULL
	);

    /// \brief
    /// Reads an XML document from a text reader.
    /// 
    /// \param textReader 
    /// Input the text reader. Must be positioned at the
    /// start of an XML document.
    /// \param flags 
    /// Input controls the reading of the elements from the document. 
    /// If NULL then the default flags are used (see FdoXmlFlags::Create())
    /// 
	FDO_API virtual void ReadXml(
   	    FdoIoTextReader* textReader, 
    	FdoXmlFlags* flags = NULL
	);

    /// \brief
    /// Reads an XML document from a stream.
    /// 
    /// \param stream 
    /// Input the stream. Must be positioned at the
    /// start of an XML document.
    /// \param flags 
    /// Input controls the reading of the elements from the document. 
    /// If NULL then the default flags are used (see FdoXmlFlags::Create())
    /// 
	FDO_API virtual void ReadXml(
    	FdoIoStream* stream, 
    	FdoXmlFlags* flags = NULL
	);

    /// \brief
    /// Gets the XML Flags that were passed to the ReadXml() 
    /// function that is currently being executed. This function would 
    /// typically be called by the FdoXmlSaxHandler callbacks.
    /// 
    /// \return
    /// Returns the XML Flags
    /// 
    FDO_API virtual FdoXmlFlags* GetDeserializationFlags();

    /// \brief
    /// Gets the current XML Reader. This function would 
    /// typically be called by the FdoXmlSaxHandler callbacks when 
    /// ReadXml() is being invoked. When ReadXml() reads from a file, stream,
    /// or text reader, a wrapping XML reader is automatically created.
    /// 
    /// \return
    /// Returns the XML reader
    /// 
    FDO_API virtual FdoXmlReader* GetXmlReader();

    /// \brief
    /// Gets the stylesheet for converting the XML document from 
    /// external to internal format. When classes derived from FdoXmlDeserializable
    /// define an internal format, they must override this function to return a
    /// stylesheet that does the conversion.
    /// 
    /// \return
    /// Returns NULL by default (no internal format defined)
    /// 
    FDO_API virtual FdoXmlReader* GetFromExternalStylesheet();

    /// \brief
    /// Gets the SAX context to pass to the FdoXmlSaxHandler callbacks.
    /// Classes derived from FdoXmlDeserializable can override this function to 
    /// specify a SAX context with class-specific information.
    /// 
    /// \return
    /// Returns NULL by default, the default FdoXmlSaxContext is used.
    /// The default provides basic error handling functionality.
    /// 
    FDO_API virtual FdoXmlSaxContext* GetSaxContext();

protected:
    FDO_API FdoXmlDeserializable();
    FDO_API virtual ~FdoXmlDeserializable();

private:
    // current XML flags
    FdoXmlFlagsP mFlags;
    // current XML reader
    FdoXmlReaderP mInternalReader;

};

#endif



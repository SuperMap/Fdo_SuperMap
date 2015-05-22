#ifndef FDO_XML_WRITER_H
#define FDO_XML_WRITER_H
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
/// FdoXmlWriter writes an XML document to a text or binary stream. 
/// \note
/// The XML document is not completely written until this object
/// is destroyed by releasing all references to it. Therefore, this object
/// must be destroyed before reading back the document being written.
class FdoXmlWriter : public FdoDisposable
{
public:

	/// \brief
	/// Specifies whether the output XML document
	/// has line breaks or indentation.
	enum LineFormat {
		/// The document is written without line breaks or element indentation.
		LineFormat_None,
		/// The document is written with a line break after:
		/// <ul>
		/// <li>every end element tag</li>
		/// <li>every start tag for elements with complex content (sub-elements)</li>
		/// </ul>
		/// Elements are not indented.
		LineFormat_Break,
		/// Same as LineFormat_Break, except that each element immediately following 
		/// a line break is indented by a certain number of spaces. The number of
		/// spaces is the element's nesting level within the document X 3. The root
		/// element has nesting level 0.
		LineFormat_Indent
	};

    /// \brief
    /// Constructs an XML writer on a file
    /// 
    /// \param fileName 
    /// Input name of the file to write.
    /// \param defaultRoot 
    /// true: all elements written are wrapped in a default root element, named "DataStore".
    /// false: the default root element is not written. In this case, the first 
    /// element written (via  WriteStartElement() ) becomes the root element. 
    /// The caller is responsible for ensuring that only one root element is written 
    /// (the XML standard disallows multiple root elements).
    /// \param lineFormat 
    /// Input Line break and indentation options 
    /// for the output document.
    /// \param lineLength 
    /// Input maximum line length. If 0 there is 
    /// no maximum. Otherwise, a line break is added before an XML attribute is
    /// written, if the attribute would have caused the current line to exceed
    /// this length.
    /// 
    /// \return
    /// Returns FdoXmlWriter
    /// 
    FDO_API_COMMON static FdoXmlWriter* Create( 
        FdoString* fileName, 
        FdoBoolean defaultRoot = true,
        LineFormat lineFormat = LineFormat_None,
        FdoSize    lineLength = 0
    );

    /// \brief
    /// Constructs an XML writer on a stream
    /// 
    /// \param stream 
    /// Input the stream to write.
    /// \param defaultRoot 
    /// true: all elements written are wrapped in a default root element, named "DataStore".
    /// false: the default root element is not written. In this case, the first 
    /// element written (via  WriteStartElement() ) becomes the root element. 
    /// The caller is responsible for ensuring that only one root element is written 
    /// (the XML standard disallows multiple root elements).
    /// \param lineFormat 
    /// Input Line break and indentation options 
    /// for the output document.
    /// \param lineLength 
    /// Input maximum line length. If 0 there is 
    /// no maximum. Otherwise, a line break is added before an XML attribute is
    /// written, if the attribute would have caused the current line to exceed
    /// this length.
    /// 
    /// \return
    /// Returns FdoXmlWriter
    /// 
    FDO_API_COMMON static FdoXmlWriter* Create( 
        FdoIoStream* stream, 
        FdoBoolean defaultRoot = true,
        LineFormat lineFormat = LineFormat_None,
        FdoSize    lineLength = 0
    );

    /// \brief
    /// Constructs an XML writer on a text writer
    /// 
    /// \param writer 
    /// Input the text writer.
    /// \param defaultRoot 
    /// true: all elements written are wrapped in a default root element, named "DataStore".
    /// false: the default root element is not written. In this case, the first 
    /// element written (via  WriteStartElement() ) becomes the root element. 
    /// The caller is responsible for ensuring that only one root element is written 
    /// (the XML standard disallows multiple root elements).
    /// \param lineFormat 
    /// Input Line break and indentation options 
    /// for the output document.
    /// \param lineLength 
    /// Input maximum line length. If 0 there is 
    /// no maximum. Otherwise, a line break is added before an XML attribute is
    /// written, if the attribute would have caused the current line to exceed
    /// this length.
    /// 
    /// \return
    /// Returns FdoXmlWriter
    /// 
    FDO_API_COMMON static FdoXmlWriter* Create( 
        FdoIoTextWriter* writer,
        FdoBoolean defaultRoot = true,
        LineFormat lineFormat = LineFormat_None,
        FdoSize    lineLength = 0
    );

    /// \brief
    /// Gets the underlying text writer. If a text writer was passed to this object
    /// then this text writer is returned.
    /// Otherwise, an auto-generated text writer is returned (a text writer
    /// wrapped around the file name or stream that was passed to this object)
    /// 
    /// \return
    /// Returns the underlying text writer
    /// 
    FDO_API_COMMON FdoIoTextWriter* GetTextWriter();

    /// \brief
    /// Gets the underlying stream. If a text writer was passed to this object
    /// then the stream for this text writer is returned.
    /// If a stream was passed to this object then this stream is returned.
    /// If a file name as passed then a auto-generated stream (wrapped around
    /// the file) is returned.
    /// 
    /// \return
    /// Returns the underlying stream
    /// 
    FDO_API_COMMON FdoIoStream* GetStream()
    {
        return mTextWriter->GetStream();
    }

    /// \brief
    /// Gets the current default root state.
    /// 
    /// \return
    /// Returns true if the default root element will be written, false otherwise.
    /// 
    FDO_API_COMMON FdoBoolean GetDefaultRoot()
    {
        return mbDefaultRoot;
    }

    /// \brief
    /// Closes this XML Writer by writing end tags for all
    /// elements currently open. Once this function is called, no more
    /// elements can be added to the output document.
    /// 
    FDO_API_COMMON void Close();

    /// \brief
    /// Sets whether to write the default root element.
    /// Must be called before the first element is written,
    /// otherwise an exception is thrown
    /// 
    /// \param defaultRoot 
    /// true: use the default root element ("DataStore") as the root element.
    /// false: caller is responsible for writing the root element.
    /// 
    FDO_API_COMMON void SetDefaultRoot( FdoBoolean defaultRoot );

    /// \brief
    /// Writes an element start tag to the document
    /// 
    /// \param elementName 
    /// Input the element name. Must be a valid
    /// XML 1.0 element name.
    /// 
    FDO_API_COMMON void WriteStartElement( FdoString* elementName );

    /// \brief
    /// Writes the end tag for the current element to the document.
    /// A FdoXmlException is thrown if there is no element to end.
    /// 
    FDO_API_COMMON void WriteEndElement();

    /// \brief
    /// Writes an attribute to the current element.
    /// A FdoXmlException is thrown if this function is called immediately after
    /// WriteEndElement().
    /// 
    /// \param attributeName 
    /// Input the element name. Must be a valid
    /// XML 1.0 attribute name.
    /// \param attributeValue 
    /// Input the element value.
    /// 
    FDO_API_COMMON void WriteAttribute( FdoString* attributeName, FdoString* attributeValue );

    /// \brief
    /// Writes simple (character) content for the current element. This function
    /// can be called multiple times for the same element. The characters are appended
    /// to the element's content. A FdoXmlException is thrown if there is no current 
    /// element.
    /// 
    /// \param characters 
    /// Input characters to append to the element content.
    /// 
    FDO_API_COMMON void WriteCharacters( FdoString* characters );

    /// \brief
    /// Writes arbitrary bytes to the XML Writer. Caller is responsible
    /// for ensuring that the text does not introduce any errors into the 
    /// XML document.
    ///
    /// \param bytes
    /// Input bytes to write.
    ///
    /// \param count
    /// Input count of bytes to write.
    /// 
    FDO_API_COMMON void WriteBytes( FdoByte* bytes, FdoSize count );

    /// \brief
    /// utility function that converts FDO element names to valid XML
    /// element or attribute names. Conversion is done by changing each invalid 
    /// character to a hex pattern ( "-xnnnn-" ).
    /// 
    /// \param name 
    /// Input the name to encode (convert).
    /// 
    /// \return
    /// Returns the encoded name.
    /// 
    FDO_API_COMMON virtual FdoStringP EncodeName ( FdoStringP name ) = 0;

    /// \brief
    /// Checks if a string is a valid XML 1.0 element or attribute name.
    /// 
    /// \param name 
    /// Input the string to check.
    /// 
    /// \return
    /// Returns true if the string is a valid name, false otherwise.
    /// 
    FDO_API_COMMON virtual FdoBoolean IsValidName ( FdoStringP name ) = 0;

    /// \brief
    ///    Given an element's or attribute's globally unique name ( uri and local name ),
    ///    this function returns its fully qualified name as per the
    ///    XML document being written, or the unqualified name if the uri is 
    ///    the default namespace. This is done by searching for the current 
    ///    namespace declaration that references the uri. 
    /// 
    /// \remarks
    ///    If a matching default namespace declaration ( "xmlns=<uri>" ) was
    ///    found and the name is for an element then the localName is returned.
    ///    \note
	///    According to the XML 1.0 specification, default namespaces do 
    ///    not apply to attribute names, so the default namespace is ignored when the 
    ///    given name is not for an element.
    /// \n
    ///    Otherwise, if a matching namespace declaration was found then 
    ///    "[namespace]:[localName]" is returned.
    /// \n
    ///    Otherwise, L"" is returned (unable to determine qualified name).
    /// 
    /// \param uri 
    /// Input the URI corresponding to an element.
    /// \param localName 
    /// Input the local name corresponding to an element.
    /// \param isElement 
    /// Input a boolean flag indicating that the URI corresponds to an element.
    /// 
    /// \return
    ///    Returns the fully qualified name corresponding to the uri.
    /// 
    FDO_API_COMMON FdoStringP UriToQName( FdoString* uri, FdoString* localName, FdoBoolean isElement = true );

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlWriter() {}
    FdoXmlWriter( FdoIoTextWriter* writer, FdoBoolean defaultRoot, LineFormat lineFormat, FdoSize lineLength );

    virtual ~FdoXmlWriter(void);

    /// Write the prologue when needed
    void WritePrologue();
/// \endcond

private:
    /// XML Element stack element, representing a currently open XML element.
    class StackElement : public FdoDisposable 
    {
    public:
        static StackElement* Create( FdoStringP elementName, FdoXmlWriter* writer)
        {
            return new StackElement(elementName, writer);
        }

        FdoStringP GetName()
        {
            return mName;
        }
    
        /// returns true if this element declares any namespaces.
        bool GetHasNsDecl();

        /// set an attribute value for this element.
	    void SetAttribute( FdoString* attributeName, FdoString* attributeValue );
        
        /// Flush all the attributes to the output document
		void FlushAttributes( FdoIoTextWriterP pWriter );

        /// Generates fully qualified name for the given element from
        /// namespace declarations in this element.
	    FdoStringP UriToQName( FdoString* uri, FdoString* localName, FdoBoolean isElement );

        static FdoStringP EncodeValue ( FdoStringP value );

    protected:
        StackElement();
        StackElement( FdoStringP elementName, FdoXmlWriter* writer);
        virtual ~StackElement() {}

    private:
        FdoStringP mName;
        FdoXmlAttributesP mAtts;
        bool mHasNsDecl;
        FdoXmlWriter* mWriter;

    };

    typedef FdoPtr<StackElement> StackElementP;

    /// Stack of all currently open XML elements. 
    class ElementStack : public FdoStack<StackElement,FdoXmlException>
    {
    public:
        static ElementStack* Create() {return new ElementStack();}

        /// Generates fully qualified name for the given element or attribute from
        /// namespace declarations in the stacked elements.
	    FdoStringP UriToQName( FdoString* uri, FdoString* localName, FdoBoolean isElement );

    protected:
        ElementStack() {}
        ~ElementStack() {}
        virtual void Dispose()
        {
            delete this;
        }

    };

    /// Close the currently open start element tag.
    void CloseStartElementTag();

    void WriteIndent();

    /// Underlying test writer
    FdoIoTextWriterP mTextWriter;

    /// true if automatically writing default root element.
    FdoBoolean       mbDefaultRoot;

    /// Tracks whether current element start tag is still open 
    /// (attributes can be added )
    FdoBoolean       mbTagOpen;

    /// Tracks whether the document prologue has been written.
    FdoBoolean       mbPrologueWritten;

    /// Tracks whether an element has been written.
    FdoBoolean       mbElementWritten;

    FdoBoolean       mbCharsWritten;

    /// Stack containing all elements whose end tag has not yet been written.
    /// The current (innermost) element is at the top of the stack.
    FdoPtr<ElementStack>      mElementStack;

    FdoStringP  mIndent;
    FdoInt32    mIndentLevel;
    LineFormat  mLineFormat;
    FdoSize     mLineLength;

	FdoSize     mCharWritten;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlWriterP is a FdoPtr on FdoXmlWriter, provided for convenience.
typedef FdoPtr<FdoXmlWriter> FdoXmlWriterP;

#endif



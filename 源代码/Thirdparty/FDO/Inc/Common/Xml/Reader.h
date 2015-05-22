#ifndef FDO_XML_READER_H
#define FDO_XML_READER_H
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
#include <Common/Stack.h>

/// \brief
/// FdoXmlReader reads an XML document from a text or binary stream. As various
/// document fragments are read, it calls the appropriate SAX Handler callback on 
/// the current SAX Handler. This object maintains a stack of SAX Handlers, with the 
/// current one being the top handler in the stack. Callers provide this object with
/// SAX Handlers to customize the processing of the XML document.
/// FdoSAXHandler callbacks also provide a means to push other handlers onto the stack.
/// For example, a SAX Handler for a particular XML element might push another handler
/// to read a particular sub-element.
class FdoXmlReader : public FdoDisposable
{
public:
    /// \brief
    /// Constructs an XML reader on a file
    /// 
    /// \param fileName 
    /// Input name of the file to read.
    /// 
    /// \return
    /// Returns FdoXmlReader
    /// 
    FDO_API_COMMON static FdoXmlReader* Create( FdoString* fileName );

    /// \brief
    /// Constructs an XML reader on a stream
    /// 
    /// \param stream 
    /// Input the stream to read.
    /// 
    /// \return
    /// Returns FdoXmlReader
    /// 
    FDO_API_COMMON static FdoXmlReader* Create( FdoIoStream* stream );

    /// \brief
    /// Constructs an XML reader on a text reader
    /// 
    /// \param reader 
    /// Input the text reader.
    /// 
    /// \return
    /// Returns FdoXmlReader
    /// 
    FDO_API_COMMON static FdoXmlReader* Create( FdoIoTextReader* reader );

    /// \brief
    /// Gets the underlying text reader. If a text reader was passed to this object
    /// then this text reader is returned.
    /// Otherwise, an auto-generated text reader is returned (a text reader
    /// wrapped around the file name or stream that was passed to this object)
    /// 
    /// \return
    /// Returns the underlying text reader
    /// 
    FDO_API_COMMON FdoIoTextReader* GetTextReader();

    /// \brief
    /// Gets the underlying stream. If a text reader was passed to this object
    /// then the stream for this text reader is returned.
    /// If a stream was passed to this object then this stream is returned.
    /// If a file name as passed then a auto-generated stream (wrapped around
    /// the file) is returned.
    /// 
    /// \return
    /// Returns the underlying stream
    /// 
    FDO_API_COMMON FdoIoStream* GetStream();

    /// \brief
    /// Parses the XML document.
    /// 
    /// \param saxHandler 
    /// Input SAX Handler to receive the FdoMathUtility events.
    /// This object is pushed onto the SAX Handler stack when parse() starts and popped
    /// when parse() is finished. If NULL then no handler is pushed, meaning that
    /// the current top SAX Handler receives the events. If saxHander is NULL
    /// and there is on current top SAX Handler then this function does a 
    /// parse and reports syntax errors, but does no semantic processing.
    /// \param saxContext 
    /// Input Caller-specific contextual information that is 
    /// pass to all SAX callbacks.
    /// \param incremental 
    /// Input 
    /// true: an incremental (progressive) parse is performed. The first call 
    /// to FdoXmlReader::Parse() causes the XML document to be read from the current 
    /// position  until the FdoXmlSaxHandler::EndElement() callback returns false 
    /// or the end of the document is reached. On subsequent calls to Parse() the 
    /// read continues where the previous call left off. 
    /// false: the whole document is parsed in a single call to FdoXmlReader::Parse(). 
    /// The FdoXmlSaxHandler::EndElement() return value is ignored. If a previous call 
    /// was made to FdoXmlReader::Parse(), with incremental = true, then the rest of the 
    /// document is parsed ( the EndElement() return value is ignored ).
    /// 
    /// \return
    /// Returns true if the end of the document has not yet been reached
    /// 
    FDO_API_COMMON virtual FdoBoolean Parse(
        FdoXmlSaxHandler* saxHandler = NULL, 
        FdoXmlSaxContext* saxContext = NULL, 
        FdoBoolean incremental = false
    ) = 0;

    /// \brief
    /// Utility function that is typically called for element names or 
    /// name type attributes that were adjusted when they were written to XML. 
    /// FDO names that correspond to XML names, but aren't valid XML names, are 
    /// adjusted. This function undoes the name adjustment.
    /// 
    /// \param name 
    /// Input the name to decode.
    /// 
    /// \return
    /// Returns the decoded name.
    /// 
    FDO_API_COMMON virtual FdoStringP DecodeName ( FdoStringP name ) = 0;

    /// \brief
    /// Indicates whether the end of the XML document has been reached.
    /// 
    /// \return
    /// Returns true if this reader is at the end of the document, false otherwise
    /// 
    FDO_API_COMMON FdoBoolean GetEOD();

    /// \brief
    /// Returns all of the XML namespace declarations that are currently
    /// in-scope for the current position in the XML document being read.
    /// 
    /// \return
    /// Returns FdoDictionary. The dictionary has one FdoDictionaryElement
    /// entry per namespace declaration. FdoDictionaryElement->GetName() returns
    /// the namespace prefix. FdoDictionaryElement->GetValue() returns the URI.
    /// 
    FDO_API_COMMON FdoDictionary* GetNamespaces();

    /// \brief
    /// Gets the URI for a namespace prefix.
    /// 
    /// \param prefix 
    /// Input the namespace prefix.
    /// 
    /// \return
    /// Returns the URI; L"" if the prefix is not in-scope at the
    /// current position in the XML document.
    /// 
    FDO_API_COMMON FdoString* PrefixToUri( FdoString* prefix );

protected:
/// \cond DOXYGEN-IGNORE
    FdoXmlReader() {}
    FdoXmlReader( FdoIoTextReader* reader );

    virtual ~FdoXmlReader(void);

    FDO_API_COMMON virtual void Dispose()
    {
        delete this;
    }

    /// \brief
    /// Pushes the given object onto the SAX Handler stack. This object will 
    /// now receive the SAX events.
    /// \param saxHandler 
    /// Input the SAX Handler to push.
    /// 
    void PushSaxHandler( FdoXmlSaxHandler* saxHandler );

    /// \brief
    /// Pops the top SAX Handler from the stack.
    /// \return
    /// Returns the SAX Handler that was popped.
    /// 
    FdoXmlSaxHandler* PopSaxHandler();

    /// \brief
    /// Gets the top SAX Handler from the stack without popping it.
    /// \return
    /// Returns the top SAX Handler.
    /// 
    FdoXmlSaxHandler* GetSaxHandler();


    /// These functions are invoked when various SAX events occur. They delegate these
    /// events to the current SAX Handler.
    void HandleStartDocument();
    void HandleEndDocument();
    void HandleStartElement(
        FdoString *pUri, 
        FdoString *pElementName, 
        FdoString *pElementQName, 
        FdoXmlAttributeCollection* pAttrs
    );
    void HandleEndElement(
        FdoString *pUri, 
        FdoString *pElementName, 
        FdoString *pElementQName
    );
    void HandleStartPrefixMapping(
        FdoString *pPrefix,
        FdoString *pUri
    );
    void HandleEndPrefixMapping(
        FdoString *pPrefix
    );
    void HandleCharacters(FdoString *chars);

    /// Sets the SAX Context for the current parse. 
    /// The SAX Context is passed to all FdoMathUtility callbacks.
    void SetSaxContext( FdoXmlSaxContext* saxContext );

    //Various functions for incremental parsing.

    /// true if parse must be stopped.
    FdoBoolean GetStopParse();
    /// set to true when parse is to be stopped
    void SetStopParse( FdoBoolean stopParse );

    /// true if the first parse has been performed
    FdoBoolean GetParsed();
    /// set to true when the first parse has been performed
    void SetParsed();
/// \endcond

private:

    /// SAX Handler stack element. Wraps around a SAX Handler.
    class StackElement : public FdoDisposable 
    {
    public:
        static StackElement* Create( FdoXmlSaxHandler* pHandler );

        FdoXmlSaxHandler* GetHandler()
        {
            return mpHandler;
        }
    
    protected:
        StackElement();
        StackElement( FdoXmlSaxHandler* pHandler );
        virtual ~StackElement() {}

    private:
        FdoXmlSaxHandler* mpHandler;
    };

    typedef FdoPtr<StackElement> StackElementP;
    
    /// SAX Handler stack definition.
    class HandlerStack : public FdoStack<StackElement,FdoXmlException>
    {
    public:
        static HandlerStack* Create() {return new HandlerStack();}

    protected:
        HandlerStack() {}
        ~HandlerStack() {}
        virtual void Dispose()
        {
            delete this;
        }

    };

    /// Tracks the scoped URI's for an XML namespace prefix
    class PrefixMapping : public FdoDisposable 
    {
    public:
        static PrefixMapping* Create( FdoString* pPrefix );

        FdoString* GetName();

        FdoString* GetUri();

    /// Called when a different URI comes into scope for this prefix
        void PushUri( FdoString* pUri );

    /// Called when current URI goes out of scope
        void PopUri();

        FdoBoolean CanSetName()
        {
            return false;
        }
    
    protected:
        PrefixMapping() {}
        PrefixMapping( FdoString* pPrefix );
        virtual ~PrefixMapping() {}

    private:
        FdoStringP mPrefix;
        FdoStringsP mUriStack;
    };

    typedef FdoPtr<PrefixMapping> PrefixMappingP;
    
    /// SAX Handler stack definition.
    class PrefixMappingCollection : public FdoNamedCollection<PrefixMapping,FdoXmlException>
    {
    public:
        static PrefixMappingCollection* Create() {return new PrefixMappingCollection();}

    protected:
        PrefixMappingCollection() {}
        ~PrefixMappingCollection() {}
        virtual void Dispose()
        {
            delete this;
        }

    };

    /// SAX handler stack
    FdoPtr<HandlerStack> mHandlerStack;

    /// current namespace prefixes.
    FdoPtr<PrefixMappingCollection> mPrefixes;

    /// Underlying text reader.
    FdoIoTextReaderP mTextReader;

    FdoBoolean mStopParse;
    FdoBoolean mParsed;
    FdoBoolean mEOD;

    FdoXmlSaxContextP mSaxContext;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlReaderP is a FdoPtr on FdoXmlReader, provided for convenience.
typedef FdoPtr<FdoXmlReader> FdoXmlReaderP;

#endif



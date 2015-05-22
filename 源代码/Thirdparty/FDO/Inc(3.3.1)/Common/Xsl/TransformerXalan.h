#ifndef FDO_XSL_TRANSFORMERXALAN_H
#define FDO_XSL_TRANSFORMERXALAN_H
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
#include <xercesc/util/BinInputStream.hpp>
#define XALAN_USE_NATIVE_WCHAR_T 1
#include <xalanc/XalanTransformer/XalanTransformer.hpp>
#include <xalanc/XSLT/ProblemListener.hpp>


/// \cond DOXYGEN-IGNORE
// Subclass of FdoXslTransformer that uses Xalan to perform the transformation.
// This class is not directly exposed to the API, only through the 
// FdoXslTransformer interface.
class FdoXslTransformerXalan : public FdoXslTransformer, public XALAN_CPP_NAMESPACE::ProblemListener
{
public:

    static FdoXslTransformerXalan* Create( 
        FdoXmlReader* inDoc = NULL, 
        FdoXmlReader* stylesheet = NULL, 
        FdoXmlWriter* outDoc = NULL,
        FdoIoTextWriter* log = NULL
    );

    virtual void Transform();

    static void Initialize();

    /// Implementation of XALAN_CPP_NAMESPACE::ProblemListener interface:
    virtual void setPrintWriter(XALAN_CPP_NAMESPACE::PrintWriter*		pw);
    /**
 	 * Function that is called when a problem event occurs.
     * 
     * @param   where          either in XMLPARSER, XSLPROCESSOR, or QUERYENGINE
     * @param   classification either MESSAGE, ERROR or WARNING
	 * @param   sourceNode     source tree node where the problem occurred
	 *                         (may be 0)
	 * @param   styleNode      style tree node where the problem occurred
	 *                         (may be 0)
	 * @param   msg            string message explaining the problem.
	 * @param   uri            the URI of the document where the problem occurred.  May be 0.
	 * @param   lineNo         line number where the problem occurred.
	 * @param   charOffset     character offset where the problem.
	 */
	virtual void
	problem(
			eProblemSource				where,
			eClassification				classification,
            const XALAN_CPP_NAMESPACE::XalanNode*			sourceNode,
			const XALAN_CPP_NAMESPACE::ElemTemplateElement*	styleNode,
			const XALAN_CPP_NAMESPACE::XalanDOMString&		msg,
			const XALAN_CPP_NAMESPACE::XalanDOMChar*			uri,
			int							lineNo,
			int							charOffset);

protected:
    /// Reader adapter. Allows Xalan to read from a FdoXmlReader.
    class InputSource : public XALAN_CPP_NAMESPACE::XSLTInputSource
    {
    public:

        InputSource( FdoXmlReader* reader );

        ~InputSource() {}

        virtual XALAN_CPP_NAMESPACE::BinInputStreamType* makeStream () const;

    private:
        class InputStream : public XALAN_CPP_NAMESPACE::BinInputStreamType
        {
        public:
            InputStream( FdoXmlReader* reader ); 

            ~InputStream() {}

    /// Tells Xalan the current position of the reader
            virtual unsigned int curPos()  const;

    /// Gets data from the reader to Xalan.
            virtual unsigned int readBytes( 
                XMLByte *const  toFill,  
                const unsigned int  maxToRead 
            );

        private:
            FdoXmlReaderP mReader;
        };

        FdoXmlReaderP mReader;
    };

    FdoXslTransformerXalan( 
        FdoXmlReader* inDoc = NULL, 
        FdoXmlReader* stylesheet = NULL, 
        FdoXmlWriter* outDoc = NULL,
        FdoIoTextWriter* log = NULL
    );

    virtual ~FdoXslTransformerXalan(void) {}

    /// Output handler callback implementation. Writes the data to the 
    /// out document
    unsigned long HandleOutput(const void* data, unsigned long length );

    /// Output handler callback implementation. Forwards the data to this 
    /// transformer, which is passed in through the handle parameter.
    static CallbackSizeType outputHandler(const void* data, CallbackSizeType length, const void *handle);

    /// Handles output flush requests from Xalan.
    static void flushHandler(const void *handle);

    /// Convert a XalanDOMString to a FdoStringP string:
    FdoStringP XalanDomStringToUnicode(const XALAN_CPP_NAMESPACE::XalanDOMString &xalanDomString);

    /// Convert a XalanNode to a FdoStringP string:
    FdoStringP XalanNodeToUnicode(const XALAN_CPP_NAMESPACE::XalanNode* inNode);

private:
    FdoInt32            mPrologueState;
};
/// \endcond

#endif



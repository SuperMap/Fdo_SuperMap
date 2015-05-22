#ifndef FDO_XSL_TRANSFORMER_H
#define FDO_XSL_TRANSFORMER_H
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
/// FdoXslTransformer provides a way to execute an XSL stylesheet
/// on an XML document.
class FdoXslTransformer : public FdoDisposable
{
public:

    /// \brief
    /// Constructs an XSL Transformer object.
    /// 
    /// \param inDoc 
    /// Input the XML document to transform.
    /// \param stylesheet 
    /// Input the XSL stylesheet with transformation instructions.
    /// \param outDoc 
    /// Output the transformed XML document.
    /// \warning 
	/// The transformed document is not completely written until 'outDoc'
    /// and this transformer are destroyed by releasing all references to them.
    /// Therefore, these objects must be destroyed before reading back the 
    /// transformed document.
    /// \param log 
    /// Input the logging object which captures messages and warnings.
    /// 
    /// \return
    /// Returns FdoXslTransformer
    /// 
    FDO_API_COMMON static FdoXslTransformer* Create( 
        FdoXmlReader* inDoc = NULL, 
        FdoXmlReader* stylesheet = NULL, 
        FdoXmlWriter* outDoc = NULL,
        FdoIoTextWriter* log = NULL
    );

    /// \brief
    /// Gets the document being transformed
    /// 
    /// \return
    /// Returns the input document.
    /// 
    FDO_API_COMMON FdoXmlReader* GetInDoc();

    /// \brief
    /// Sets the document to transform.
    /// 
    /// \param inDoc 
    /// Input the XML document to transform.
    /// 
    FDO_API_COMMON void SetInDoc( FdoXmlReader* inDoc );

    /// \brief
    /// Gets the XSL Stylesheet
    /// 
    /// \return
    /// Returns the stylesheet.
    /// 
    FDO_API_COMMON FdoXmlReader* GetStylesheet();

    /// \brief
    /// Sets the XSL stylesheet
    /// 
    /// \param stylesheet 
    /// Input the stylesheet
    /// 
    FDO_API_COMMON void SetStylesheet( FdoXmlReader* stylesheet );

    /// \brief
    /// Gets the output document.
    /// 
    /// \return
    /// Returns the out document
    /// 
    FDO_API_COMMON FdoXmlWriter* GetOutDoc();

    /// \brief
    /// Sets the output document
    /// 
    /// \param outDoc 
    /// Input the output document
	/// \warning 
	/// The output document is not completely written until outDoc
    /// and this transformer are destroyed by releasing all references to them.
    /// 
    FDO_API_COMMON void SetOutDoc( FdoXmlWriter* outDoc );

    /// \brief
    /// Gets the logging object
    /// 
    /// \return
    /// Returns the logging object
    /// 
    FDO_API_COMMON FdoIoTextWriter* GetLog();

    /// \brief
    /// Sets the logging object
    /// 
    /// \param log 
    /// The logging object which captures messages and warnings.
    /// 
    FDO_API_COMMON void SetLog( FdoIoTextWriter* log );

    /// \brief
    /// Gets the list of parameters that will be passed to the 
    /// stylesheet by Transform(). The caller can add parameters to this list
    /// or modify/delete existing parameters. The parameter list is empty
    /// when this class is constructed.
    /// Parameter values must be in XPath syntax. Therefore, literal values
    /// must be enclosed in single quotes.
    /// 
    /// \return
    /// Returns the parameter list.
    /// 
    FDO_API_COMMON FdoDictionary* GetParameters();

    /// \brief
    /// Performs the transformation.
    /// 
    FDO_API_COMMON virtual void Transform() = 0;

/// \cond DOXYGEN-IGNORE
protected:
    FdoXslTransformer( 
        FdoXmlReader* inDoc = NULL, 
        FdoXmlReader* stylesheet = NULL, 
        FdoXmlWriter* outDoc = NULL,
        FdoIoTextWriter* log = NULL
    );

    virtual ~FdoXslTransformer(void) {}
/// \endcond

private:
    /// in document
    FdoXmlReaderP mInDoc;
    /// stylesheet
    FdoXmlReaderP mStylesheet;
    /// out document
    FdoXmlWriterP mOutDoc;
    /// stylesheet parameters
    FdoDictionaryP mParameters;
    /// Logger
    FdoIoTextWriterP mLog;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXslTransformerP is a FdoPtr on FdoXslTransformer, provided for convenience.
typedef FdoPtr<FdoXslTransformer> FdoXslTransformerP;

#endif



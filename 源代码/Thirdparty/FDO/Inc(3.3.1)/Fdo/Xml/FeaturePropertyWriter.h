#ifndef FDO_XML_FEATUREPROPERTYWRITER_H_
#define FDO_XML_FEATUREPROPERTYWRITER_H_

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

/// \brief
/// FdoXmlFeaturePropertyWriter writes features in GML format. It is similar to 
/// FdoXmlFeatureWriter, except that it provides better performance. However, the 
/// caller is responsible for ensuring that properties are written in proper order. 
class FdoXmlFeaturePropertyWriter : public FdoIDisposable
{
public:
    /// \brief
    /// Creates a Feature Property Writer for writing FDO features to XML.
    /// 
    /// \param writer 
    /// Input XML document writer. Specifies the XML document that the features will be
    /// written to.
    /// \param flags 
    /// Input options for controlling the writing of the features. If NULL then the 
    /// default flags are used.
    /// 
    /// \return
    /// Returns FdoXmlFeaturePropertyWriter
    /// 
	FDO_API static FdoXmlFeaturePropertyWriter * Create( 
		FdoXmlWriter*               writer,
    	FdoXmlFlags*                flags = NULL
 	);

    /// \brief
    /// Gets the underlying XML writer.
    /// 
    /// \return
    /// Returns the underlying XML writer.
    /// 
    FDO_API FdoXmlWriter* GetXmlWriter();

    /// \brief
    /// Gets the class definition for the current feature being written.
    /// 
    /// \return
    /// Returns FdoClassDefinition
    /// 
    FDO_API FdoClassDefinition* GetClassDefinition();

    /// \brief
    /// Sets the class definition for the current feature being written.
    /// 
    /// \param classDefinition 
    /// Input the class definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetClassDefinition(FdoClassDefinition* classDefinition);

    /// \brief
    /// Writes the start of a feature to XML. The start tags for the feature member 
    /// element and the feature's actual element are written. The feature element name
    /// is derived from the feature's class and schema names.
    /// 
    /// \param startTag 
    /// The start tag for the feature element. If it is null, the
    /// feature's class name used.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteFeatureStart(FdoString* startTag);

    /// \brief
    /// Closes the current feature by writing the feature element and feature member 
    /// element end tags.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteFeatureEnd();

    /// \brief
    /// Writes a feature property to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the property value as an FDO property
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteProperty( FdoString* name, FdoPropertyValue* value, FdoBoolean valueOnly = false );

    /// \brief
    /// Writes a feature property to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the property value as a string
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
/// \return
/// Returns nothing
    FDO_API void WriteProperty(FdoString* name, FdoString* value, FdoBoolean valueOnly = false );

//TBD: do we need functions for other basic types or make the caller do the
//conversion to string. 

    /// \brief
    /// Writes a raster property to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the raster property value
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteProperty(FdoString* name, FdoIRaster* value, FdoBoolean valueOnly = false );

    /// \brief
    /// Writes a lob property to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the lob property value
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteProperty(FdoString* name, FdoLOBValue* value, FdoBoolean valueOnly = false );

    /// \brief
    /// Writes a LOB feature property from a stream reader to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param lobReader 
    /// Input the reader for retrieving the lob
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteProperty(FdoString* name, FdoIStreamReader* lobReader, FdoBoolean valueOnly = false );

    /// \brief
    /// Writes a geometric property to XML.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the property value as an array of bytes
    /// \param count 
    /// Input the number of bytes in the byte array
    /// \param valueOnly 
    /// false: wrap the property value in a property element
    /// true: just write the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteGeometricProperty(
        FdoString* name, 
        FdoByte* value, 
        FdoInt32 count, 
        FdoBoolean valueOnly = false 
    );

    /// \brief
    /// Writes start tag for an object property. The object property sub-properties
    /// can be written by subsequent calls to this class's Write functions.
    /// 
    /// \param name 
    /// Input the object property name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteObjectPropertyStart(FdoString* name);

    /// \brief
    /// Closes the current object property by writing its end tag.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void WriteObjectPropertyEnd();


protected:
    FdoXmlFeaturePropertyWriter();
    FdoXmlFeaturePropertyWriter(FdoXmlWriter* writer, FdoXmlFlags* flags);
    virtual ~FdoXmlFeaturePropertyWriter();
    virtual void Dispose();

private:
    FdoPtr<FdoXmlWriter> m_writer;
    FdoPtr<FdoXmlFlags> m_flags;
    FdoPtr<FdoClassDefinition> m_classDef;


};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlFeaturePropertyReaderP is a FdoPtr on FdoXmlFeaturePropertyReader, provided for convenience.
typedef FdoPtr<FdoXmlFeaturePropertyWriter> FdoXmlFeaturePropertyWriterP;


#endif



#ifndef FDO_XML_SPATIALCONTEXTREADER_H_
#define FDO_XML_SPATIALCONTEXTREADER_H_

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
#include <Fdo/Commands/SpatialContext/SpatialContextExtentType.h>
#include <Fdo/Commands/SpatialContext/ISpatialContextReader.h>
#include <Fdo/Xml/SpatialContextFlags.h>

class FdoXmlSCReadHandler;

/// \brief
/// FdoXmlSpatialContextReader reads Spatial Contexts from an XML 
/// document. Unlike other XML Readers, the reading is done procedurally, 
/// rather than through events. FdoXmlSpatialContextReader implements 
/// FdoISpatialContextReader to provide the functions for retrieving the 
/// spatial contexts that were read.
class FdoXmlSpatialContextReader : 
	public FdoISpatialContextReader,
    public FdoXmlSaxHandler
{
public:

    /// \brief
    /// creates a Spatial Context Reader.
    /// 
    /// \param reader 
    /// Input XML document reader. Specifies the XML
    /// document that the Spatial Contexts will be read from.
    /// \param flags 
    /// Input options for controlling the 
    /// deserializing of the Spatial Contexts. If NULL then the 
    /// default flags are used.
    /// 
    /// \return
    /// Returns FdoXmlSpatialContextReader
    /// 
	FDO_API static FdoXmlSpatialContextReader * Create( 
		FdoXmlReader*               reader,
    	FdoXmlSpatialContextFlags*  flags = NULL
    );

    /// \brief
    /// Gets the Xml document reader that was passed to this object.
    /// 
    /// \return
    /// Returns the XML document reader.
    /// 
    FDO_API FdoXmlReader* GetXmlReader();

// FdoISpatialContextReader implementation

    /// \brief
    /// Gets the name of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the name of the spatial context.
    /// 
    FDO_API virtual FdoString* GetName();

    /// \brief
    /// Gets the description of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the description of the spatial context.
    /// 
    FDO_API virtual FdoString* GetDescription();

    /// \brief
    /// Gets the name of the coordinate system of the spatial context currently
    /// being read. If the result is a null or empty string, the coordinate system is
    /// unknown to the spatial context.
    /// 
    /// \return
    /// Returns the coordinate system name of the spatial context.
    /// 
    FDO_API virtual FdoString* GetCoordinateSystem();

    /// \brief
    /// Gets the coordinate system in OpenGIS SRS WKT format of the spatial context currently
    /// being read. If the result is an empty string, the coordinate system WKT description is
    /// not available.
    /// 
    /// \return
    /// Returns the coordinate system description in WKT of of the spatial context.
    /// 
    FDO_API virtual FdoString* GetCoordinateSystemWkt();

    /// \brief
    /// Gets the extent type of the spatial context currently being read.
    /// 
    /// \return
    /// Returns the extent type.
    /// 
    FDO_API virtual FdoSpatialContextExtentType GetExtentType();

    /// \brief
    /// Gets the extent of the spatial context currently being read as a byte
    /// array in FGF format.
    /// 
    /// \return
    /// Returns the extent as a byte array in FGF format.
    /// 
    FDO_API virtual FdoByteArray* GetExtent();

    /// \brief
    /// Gets the tolerance value for XY ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API virtual const double GetXYTolerance();

    /// \brief
    /// Gets the tolerance value for Z ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs a frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API virtual const double GetZTolerance();

    /// \brief
    /// Returns true if the spatial context currently being read is the active
    /// spatial context.
    /// 
    /// \return
    /// Returns true if the current spatial context is the active one.
    /// 
    FDO_API virtual const bool IsActive();

    /// \brief
    /// Advances the reader to the next item. The default position of the reader
    /// is prior to the first item. Thus, you must call ReadNext to begin
    /// accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext();

    FDO_API virtual FdoXmlSaxHandler* XmlStartDocument(FdoXmlSaxContext* saxContext);

    /// The following callbacks catch the start element and end element
    /// SAX events.
    FDO_API virtual FdoXmlSaxHandler* XmlStartElement( 
        FdoXmlSaxContext* saxContext, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );

    FDO_API virtual FdoBoolean XmlEndElement( 
        FdoXmlSaxContext* saxContext, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname
    );


protected:
    /// default constructor to keep linux from complaining.
    FdoXmlSpatialContextReader() {}

    FDO_API FdoXmlSpatialContextReader( 
		FdoXmlReader* reader,
    	FdoXmlSpatialContextFlags* flags
    );
    FDO_API virtual ~FdoXmlSpatialContextReader();

    /// Closes the FdoXmlSpatialContextReader object, freeing any resources it may
    /// be holding.
    FDO_API virtual void Dispose();

    /// Throws an exception if a getter is called but there is no currently read Spatial Context.
    void ThrowOnNotRead( FdoString* function );

private:

    FdoXmlReaderP               mXmlReader;
    FdoXmlSpatialContextFlagsP  mXmlFlags;

    FdoBoolean              mIsActiveSC;
    FdoPtr<FdoByteArray>    mExtent;

    FdoXmlSCReadHandler*     mSCHandler;
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSpatialContextReaderP is a FdoPtr on FdoXmlSpatialContextReader, provided for convenience.
typedef FdoPtr<FdoXmlSpatialContextReader> FdoXmlSpatialContextReaderP;


#endif



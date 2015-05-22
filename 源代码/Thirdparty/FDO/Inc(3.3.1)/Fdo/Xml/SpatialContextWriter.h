#ifndef FDO_XML_SPATIALCONTEXTWRITER_H
#define FDO_XML_SPATIALCONTEXTWRITER_H

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
#include <Fdo/Xml/SpatialContextFlags.h>

/// \brief
/// FdoXmlSpatialContextWriter writes Spatial Contexts to an 
/// XML document. This is done by calling the various setter functions 
/// to set the spatial context attributes and then calling 
/// WriteSpatialContext() to write the spatial context using the current 
/// attributes. 
class FdoXmlSpatialContextWriter : public FdoIDisposable
{
public:
    /// \brief
    /// creates a Spatial Context Writer.
    /// 
    /// \param writer 
    /// Input XML document writer. Specifies the XML
    /// document that the Spatial Contexts will be written to.
    /// \param flags 
    /// Input options for controlling the 
    /// deserializing of the Spatial Contexts. If NULL then the 
    /// default flags are used.
    /// 
    /// \return
    /// Returns FdoXmlSpatialContextWriter
    /// 
	FDO_API static FdoXmlSpatialContextWriter * Create( 
		FdoXmlWriter*               writer,
    	FdoXmlSpatialContextFlags*  flags = NULL
 	);

    /// \brief
    /// Gets the name of the context to create as a string.
    /// 
    /// \return
    /// Returns the name of the spatial context
    /// 
    FDO_API FdoString* GetName();

    /// \brief
    /// Sets the name of the context to create as a string.
    /// 
    /// \param value 
    /// Input the name of the spatial context
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoString* value);

    /// \brief
    /// Gets the description of the context to create as a string.
    /// 
    /// \return
    /// Returns the description of the spatial context
    /// 
    FDO_API FdoString* GetDescription();

    /// \brief
    /// Sets the description of the context to create as a string.
    /// 
    /// \param value 
    /// Input the description of the spatial context
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDescription(FdoString* value);

    /// \brief
    /// Gets the name of the coordinate system of the context to create.
    /// 
    /// \return
    /// Returns the coordinate system name
    /// 
    FDO_API FdoString* GetCoordinateSystem();

    /// \brief
    /// Gets the name of the coordinate system of the context to create.
    /// 
    /// \param value 
    /// Input the coordinate system name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetCoordinateSystem(FdoString* value);

    /// \brief
    /// Gets the coordinate system of the context to create as a string
    /// in OpenGIS SRS WKT format.
    /// 
    /// \return
    /// Returns the coordinate system
    /// 
    FDO_API FdoString* GetCoordinateSystemWkt();

    /// \brief
    /// Sets the coordinate system of the context to create as a string in
    /// OpenGIS SRS WKT format.
    /// 
    /// \param value 
    /// Input the coordinate system
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetCoordinateSystemWkt(FdoString* value);

    /// \brief
    /// Gets the desired extent type of the context to create, either static or dynamic.
    /// 
    /// \return
    /// Returns the extent type
    /// 
    FDO_API FdoSpatialContextExtentType GetExtentType();

    /// \brief
    /// Sets the desired extent type of the context to create, either static or dynamic.
    /// 
    /// \param value 
    /// Input the extent type
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetExtentType(FdoSpatialContextExtentType value);

    /// \brief
    /// Gets the extent of the context to create as a byte array in FGF format.
    /// If the extent type is dynamic, any value specified via this function is ignored.
    /// 
    /// \return
    /// Returns the extent of the spatial context
    /// 
    FDO_API FdoByteArray* GetExtent();

    /// \brief
    /// Sets the extent of the context to create as a byte array in FGF format.
    /// If the extent type is dynamic this is optional and any value specified is ignored.
    /// 
    /// \param value 
    /// Input the extent of the spatial context
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetExtent(FdoByteArray* value);

    /// \brief
    /// Gets the tolerance value to use for X/Y ordinates. Tolerances are used
    /// in some geometric tests, mostly for equality between coordinates.  This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions.  It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API const double GetXYTolerance();

    /// \brief
    /// Sets the tolerance value to use for X/Y ordinates. Tolerances are used
    /// in some geometric tests, mostly for equality between coordinates.  This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions.  It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \param value 
    /// Input the tolerance
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetXYTolerance(const double value);

    /// \brief
    /// Gets the tolerance value to use for Z ordinates. Tolerances are used in
    /// some geometric tests, mostly for equality between coordinates.  This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions.  It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance
    /// 
    FDO_API const double GetZTolerance();

    /// \brief
    /// Sets the tolerance value to use for Z ordinates. Tolerances are used in
    /// some geometric tests, mostly for equality between coordinates.  This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions.  It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \param value 
    /// Input the tolerance
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetZTolerance(const double value);

    /// \brief
    /// Writes the current Spatial Context to the XML document.
    /// 
    FDO_API	void WriteSpatialContext();

protected:
    /// default constructor to keep linux from complaining.
    FdoXmlSpatialContextWriter() {}
	FdoXmlSpatialContextWriter( 
		FdoXmlWriter*               writer,
    	FdoXmlSpatialContextFlags*  flags = NULL
    );
    virtual ~FdoXmlSpatialContextWriter() { FDO_SAFE_RELEASE (mExtent) };

    /// Closes the FdoXmlSpatialContextWriter object, freeing any resources it may
    /// be holding.
    FDO_API virtual void Dispose();

private:
    FdoXmlWriterP               mXmlWriter;
    FdoXmlSpatialContextFlagsP  mXmlFlags;

    FdoStringP                  mSCName;
    FdoStringP                  mDescription;
    FdoStringP                  mCoordSysName;
    FdoStringP                  mCoordSysWkt;

    FdoSpatialContextExtentType mExtentType;
    FdoByteArray*               mExtent;
    FdoInt32                    mExtentLength;

    FdoDouble                   mXYTolerance;
    FdoDouble                   mZTolerance;

};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlSpatialContextWriterP is a FdoPtr on FdoXmlSpatialContextWriter, provided for convenience.
typedef FdoPtr<FdoXmlSpatialContextWriter> FdoXmlSpatialContextWriterP;

#endif



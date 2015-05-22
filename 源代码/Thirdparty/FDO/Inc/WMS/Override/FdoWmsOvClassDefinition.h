/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the GNU Lesser
 * General Public License as published by the Free Software Foundation.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef FdoWmsOvClassDefinition_H
#define FdoWmsOvClassDefinition_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>
#include <WMS/Override/FdoWmsOvRasterDefinition.h>

/// \brief
///  
/// The FdoWmsOvClassDefinition class defines mapping overrides for a 
/// WMS feature class that exposes WMS layers as an FDO class. The 
/// properties defined here will be used in the WMS Getap operation 
/// when querying data from the WMS server.
class FdoWmsOvClassDefinition : public FdoPhysicalClassMapping
{
	typedef FdoPhysicalClassMapping BaseType;

public:
    /// \brief
    /// Constructs a new empty WMS physical mapping class definition.
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvClassDefinition instance.
    /// 
	FDOWMS_API static FdoWmsOvClassDefinition* Create();

    /// \brief
    /// Gets the physical overrides for a raster property definition.
    /// 
    /// \return
    /// Returns the raster definition. 
    /// 
	FDOWMS_API FdoWmsOvRasterDefinition* GetRasterDefinition();

    /// \brief
    /// Sets the physical overrides for a raster property definition.
    /// 
    /// \param rasterDefinition 
    /// Input raster definition
    /// 
    /// \return
    /// Returns nothing
    /// 
	FDOWMS_API void SetRasterDefinition(FdoWmsOvRasterDefinition* rasterDefinition);

    /// \brief
    /// Gets the fully qualified name of this element
    /// 
    /// \return
    /// Returns the qualified element name
    /// 
    FDOWMS_API virtual FdoStringP GetQualifiedName();

/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of supported API.
	FDOWMS_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOWMS_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    FDOWMS_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOWMS_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOWMS_API FdoWmsOvClassDefinition(void);
	FDOWMS_API virtual ~FdoWmsOvClassDefinition(void);
	void Dispose(void);

private:
	FdoWmsOvRasterDefinitionP m_rasterDefinition;

/// \endcond

};

/// \brief
///  FdoWmsOvClassDefinitionP is a FdoPtr on FdoWmsOvClassDefinition, provided for convenience. 
typedef FdoPtr<FdoWmsOvClassDefinition> FdoWmsOvClassDefinitionP;

#endif



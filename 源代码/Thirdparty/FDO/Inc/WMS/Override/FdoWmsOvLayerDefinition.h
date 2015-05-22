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
#ifndef FdoWmsOvLayerDefinition_H
#define FdoWmsOvLayerDefinition_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>
#include <WMS/Override/FdoWmsOvStyleDefinition.h>

/// \brief
///  
/// The FdoWmsOvLayerDefinition class represents a WMS Layer defined on a WMS Server. 
/// A request to render a Map through WMS will allow mutliple layers to be specified 
/// in order to form a composite image. 
class FdoWmsOvLayerDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    /// \brief
    /// Constructs a new empty layer definition.
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvLayerDefinition instance.
    /// 
	FDOWMS_API static FdoWmsOvLayerDefinition* Create();

    /// \brief
    /// Gets the WMS style that will be used to render a WMS 
    /// layer in a composit WMS image.
    /// 
    /// \remarks
    /// If the server advertises several styles for a layer, and the style 
    /// definition is either set to the default style or not specified at all, the 
    /// choice of which style to use as default is at the discretion of the server.
    /// 
    /// \return
    /// Returns the style definition.
    /// 
    FDOWMS_API FdoWmsOvStyleDefinition* GetStyle(void) const;

    /// \brief
    /// Sets the WMS style that will be used to render a WMS 
    /// layer in a composit WMS image.
    /// 
    /// \remarks
    /// If the server advertises several styles for a layer, and the style 
    /// definition is either set to the default style or not specified at all, the 
    /// choice of which style to use as default is at the discretion of the server.
    /// 
    /// \return
    /// Returns nothing.
    /// 
    FDOWMS_API void SetStyle(FdoWmsOvStyleDefinition* style);

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
	FDOWMS_API FdoWmsOvLayerDefinition(void);
	FDOWMS_API virtual ~FdoWmsOvLayerDefinition(void);
	void Dispose(void);

private:
	FdoWmsOvStyleDefinitionP m_styleDefinition;

/// \endcond

};

/// \brief
///  FdoWmsOvLayerDefinitionP is a FdoPtr on FdoWmsOvLayerDefinition, provided for convenience. 
typedef FdoPtr<FdoWmsOvLayerDefinition> FdoWmsOvLayerDefinitionP;

#endif



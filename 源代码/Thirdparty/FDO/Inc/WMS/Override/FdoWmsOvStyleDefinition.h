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
#ifndef FdoWmsOvStyleDefinition_H
#define FdoWmsOvStyleDefinition_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>

/// \brief
///  
/// The FdoWmsOvStyleDefinition class defines a WMS style that will be used to stylize a WMS layer.
class FdoWmsOvStyleDefinition : public FdoPhysicalElementMapping
{
	typedef FdoPhysicalElementMapping BaseType;

public:
    /// \brief
    /// Constructs a new empty style definition.
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvStyleDefinition instance.
    /// 
	FDOWMS_API static FdoWmsOvStyleDefinition* Create();

/// \cond DOXYGEN-IGNORE

public:
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
	FDOWMS_API FdoWmsOvStyleDefinition(void);
	FDOWMS_API virtual ~FdoWmsOvStyleDefinition(void);
	void Dispose(void);
/// \endcond

};

/// \brief
///  FdoWmsOvStyleDefinitionP is a FdoPtr on FdoWmsOvStyleDefinition, provided for convenience. 
typedef FdoPtr<FdoWmsOvStyleDefinition> FdoWmsOvStyleDefinitionP;

#endif



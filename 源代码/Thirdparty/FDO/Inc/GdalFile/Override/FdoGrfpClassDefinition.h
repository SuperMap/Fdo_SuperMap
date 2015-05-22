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
/// <library>GRFPOverrides.lib</library>

#ifndef FDOGRFPCLASSDEFINITION_H
#define FDOGRFPCLASSDEFINITION_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

class FdoGrfpRasterDefinition;
class FdoGrfpPhysicalSchemaMapping;

/// <summary> 
/// The FdoGrfpClassDefinition class defines overrides for a feature class that contains raster data.
/// </summary>
class FdoGrfpClassDefinition : public FdoPhysicalClassMapping
{
	typedef FdoPhysicalClassMapping BaseType;

public:
    /// <summary>Constructs a new empty class definition.</summary>
    /// <returns>Returns the newly created FdoGrfpClassDefinition instance.</returns> 
	FDOGRFP_API static FdoGrfpClassDefinition* Create();

    /// <summary>Gets the raster definition which contains a collection of raster locations.</summary>
    /// <returns>Returns the raster definition. </returns> 
	FDOGRFP_API FdoGrfpRasterDefinition* GetRasterDefinition();

    /// <summary>Sets the raster definition.</summary>
	/// <param name="rasterDefinition">Input raster definition</param>
	/// <returns>Returns nothing</returns> 
	FDOGRFP_API void SetRasterDefinition(FdoGrfpRasterDefinition* rasterDefinition);
	
//DOM-IGNORE-BEGIN

    // XML Serialization functions, not part of supported API.
	FDOGRFP_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
    FDOGRFP_API virtual FdoXmlSaxHandler* XmlStartElement(
        FdoXmlSaxContext* context, 
        FdoString* uri, 
        FdoString* name, 
        FdoString* qname, 
        FdoXmlAttributeCollection* atts
    );
    FDOGRFP_API virtual FdoBoolean XmlEndElement(FdoXmlSaxContext* context, FdoString* uri, FdoString* name, FdoString* qname);
    FDOGRFP_API void _writeXml( FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags );

protected:
	FDOGRFP_API FdoGrfpClassDefinition(void);
	FDOGRFP_API virtual ~FdoGrfpClassDefinition(void);
	void Dispose(void);

private:
	FdoPtr<FdoGrfpRasterDefinition> m_rasterDefinition;

//DOM-IGNORE-END
};

/// <summary> FdoGrfpClassDefinitionP is a FdoPtr on FdoGrfpClassDefinition, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpClassDefinition> FdoGrfpClassDefinitionP;

/// <summary> 
/// The FdoGrfpClassCollection holds a list of class definitions.
/// </summary>
class FdoGrfpClassCollection : public FdoPhysicalElementMappingCollection<FdoGrfpClassDefinition>
{
public:
    /// <summary>Constructs a new empty Class Definition collection.</summary>
    /// <param name="parent">Input parent object</param> 
    /// <returns>Returns the newly created FdoGrfpClassCollection instance.</returns> 
	FDOGRFP_API static FdoGrfpClassCollection* Create(FdoGrfpPhysicalSchemaMapping *parent);

//DOM-IGNORE-BEGIN

protected:
	FdoGrfpClassCollection();
    FDOGRFP_API FdoGrfpClassCollection(FdoGrfpPhysicalSchemaMapping *parent);
    FDOGRFP_API virtual ~FdoGrfpClassCollection(void);
	void Dispose();

//DOM-IGNORE-END
};

/// <summary> FdoGrfpClassesP is a FdoPtr on FdoGrfpClassCollection, provided for convenience. </summary>
typedef FdoPtr<FdoGrfpClassCollection> FdoGrfpClassesP;

#endif

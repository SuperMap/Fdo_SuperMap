#ifndef FDO_XMLELEMENTMAPPINGCOLLECTION
#define FDO_XMLELEMENTMAPPINGCOLLECTION

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
#include <Fdo/Xml/ElementMapping.h>
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>

class FdoXmlClassMapping;

/// \brief
/// FdoXmlElementMappingCollection is a collection of Element Mapping objects.
class FdoXmlElementMappingCollection : public FdoPhysicalElementMappingCollection<FdoXmlElementMapping>
{
public:
    /// \brief
    /// Constructs an empty XML element mapping collection.
    /// 
    /// \param parent 
    /// Input the parent FdoXmlSchemaMapping or FdoXmlClassMapping.
    /// 
    /// \return
    /// Returns FdoXmlElementMappingCollection
    /// 
    FDO_API static FdoXmlElementMappingCollection* Create(FdoPhysicalElementMapping* parent);

/// \cond DOXYGEN-IGNORE
protected:
    FdoXmlElementMappingCollection() : FdoPhysicalElementMappingCollection<FdoXmlElementMapping>()
    {
    }

    FdoXmlElementMappingCollection(FdoPhysicalElementMapping* parent) : FdoPhysicalElementMappingCollection<FdoXmlElementMapping>(parent)
    {
    }
    virtual ~FdoXmlElementMappingCollection()
    {
    }

    virtual void Dispose();
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlElementMappingsP is a FdoPtr on FdoXmlElementMappingCollection, provided for convenience.
typedef FdoPtr<FdoXmlElementMappingCollection> FdoXmlElementMappingsP;

#endif



#ifndef FDO_XMLCLASSMAPPINGCOLLECTION
#define FDO_XMLCLASSMAPPINGCOLLECTION

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
#include <Fdo/Xml/ClassMapping.h>

/// \brief
/// FdoXmlClassMappingCollection is a collection of Fdo-GML Class Mapping objects.
class FdoXmlClassMappingCollection : public FdoPhysicalElementMappingCollection<FdoXmlClassMapping>
{
public:
    /// \brief
    /// Constructs an empty Class mapping collection.
    /// 
    /// \param parent 
    /// Input the parent FdoXmlSchemaMapping.
    /// 
    /// \return
    /// Returns FdoXmlClassMappingCollection
    /// 
    FDO_API static FdoXmlClassMappingCollection* Create(FdoPhysicalElementMapping* parent);

protected:
/// \cond DOXYGEN-IGNORE
    FdoXmlClassMappingCollection() : FdoPhysicalElementMappingCollection<FdoXmlClassMapping>()
    {
    }

    FdoXmlClassMappingCollection(FdoPhysicalElementMapping* parent) : FdoPhysicalElementMappingCollection<FdoXmlClassMapping>(parent)
    {
    }

    virtual void Dispose();
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlClassMappingsP is a FdoPtr on FdoXmlClassMappingCollection, provided for convenience.
typedef FdoPtr<FdoXmlClassMappingCollection> FdoXmlClassMappingsP;

#endif



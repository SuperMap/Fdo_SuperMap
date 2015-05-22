#ifndef _CLASSCOLLECTION_H_
#define _CLASSCOLLECTION_H_

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
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/SchemaCollection.h>

/// \brief
/// The FdoClassCollection class represents a collection of FdoClassDefinition classes.
class FdoClassCollection: public FdoSchemaCollection<FdoClassDefinition> 
{
    friend class FdoFeatureSchema;

protected:
/// \cond DOXYGEN-IGNORE
    FdoClassCollection()
	{
	}

    /// Constructs an instance of a ClassCollection using the specified argument.
    FdoClassCollection(FdoSchemaElement* parent) : FdoSchemaCollection<FdoClassDefinition>(parent)
    {
    }

    virtual ~FdoClassCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs an instance of an FdoClassCollection using the specified argument.
    /// 
    /// \param parent 
    /// Input parent FdoSchemeElement
    /// 
    /// \return
    /// Returns FdoClassCollection
    /// 
    FDO_API static FdoClassCollection* Create(FdoSchemaElement* parent);
};

/// \ingroup (typedefs)
/// \brief
/// FdoClassesP is a FdoPtr on FdoClassCollection, provided for convenience.
typedef FdoPtr<FdoClassCollection> FdoClassesP;

#endif



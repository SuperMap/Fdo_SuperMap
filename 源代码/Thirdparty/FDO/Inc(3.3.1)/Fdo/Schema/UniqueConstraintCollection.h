#ifndef _UNIQUECONSTRAINTCOLLECTION_H_
#define _UNIQUECONSTRAINTCOLLECTION_H_
// 

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
#include <Fdo/Schema/UniqueConstraint.h>
#include <Fdo/Schema/SchemaException.h>

/// \brief
/// The FdoUniqueConstraintCollection class represents a collection of FdoUniqueConstraint objects.
class FdoUniqueConstraintCollection : public FdoCollection<FdoUniqueConstraint, FdoSchemaException>
{
protected:
    FdoUniqueConstraintCollection() : FdoCollection<FdoUniqueConstraint, FdoSchemaException>()
    {
    }

    virtual ~FdoUniqueConstraintCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }

public:
    /// \brief
    /// Constructs a default instance of an FdoUniqueConstraintCollection.
    /// 
    /// \return
    /// Returns FdoUniqueConstraintCollection
    /// 
    FDO_API static FdoUniqueConstraintCollection* Create();
};

/// \ingroup (typedefs)
/// \brief
/// FdoUniqueConstraintCollectionP is a FdoPtr on FdoUniqueConstraintCollection, provided for convenience.
typedef FdoPtr<FdoUniqueConstraintCollection> FdoUniqueConstraintCollectionP;

#endif



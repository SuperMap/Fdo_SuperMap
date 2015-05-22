#ifndef _FEATURECLASSCOLLECTION_H_
#define _FEATURECLASSCOLLECTION_H_

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

#include <Fdo/Schema/FeatureClass.h>
#include <Fdo/Schema/SchemaCollection.h>

/// \brief
/// The FdoFeatureClassCollection class represents a collection of FdoFeatureClasse objects.
class FdoFeatureClassCollection: public FdoSchemaCollection<FdoFeatureClass> 
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs an instance of a FeatureClassCollection using the specified argument.
    FdoFeatureClassCollection(FdoSchemaElement* parent) : FdoSchemaCollection<FdoFeatureClass>(parent)
    {
    }

    virtual ~FdoFeatureClassCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs an instance of an FdoFeatureClassCollection using the specified argument.
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoFeatureClassCollection
    /// 
    FDO_API static FdoFeatureClassCollection* Create(FdoSchemaElement* parent);
};
#endif



#ifndef _UNIQUECONSTRAINT_H_
#define _UNIQUECONSTRAINT_H_
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
#include <Fdo/Schema/DataPropertyDefinitionCollection.h>

/// \brief
/// FdoUniqueConstraint can be used to specify that a property or list of properties taken together 
/// have unique values for all objects of that class in a datastore. A unique constraint that is based on a list 
/// of two or more properties is called a composite unique constraint.
/// This constraint type applies to all data property types except for Boolean, BLOB, and CLOB. A Boolean property 
/// can be included if it is part of a composite unique constraint.
class FdoUniqueConstraint : public FdoIDisposable
{

protected:
    /// Constructs a default instance of a FdoUniqueConstraint.
    FdoUniqueConstraint();

    virtual ~FdoUniqueConstraint();

	virtual void Dispose()
    {
        delete this;
    }
public:
    
    /// \brief
    /// Constructs an empty instance of an FdoUniqueConstraint.
    /// 
    /// \return
    /// Returns an FdoUniqueConstraint.
    /// 
    FDO_API static FdoUniqueConstraint* Create( );

    /// \brief
    /// Returns the list of properties that define the unique constraint. The caller can modify the list by adding or removing properties
    /// 
    /// \return
    /// Returns the collection that holds the properties that defines the constraint.
    /// 
	FDO_API FdoDataPropertyDefinitionCollection* GetProperties();

private:

	FdoDataPropertyDefinitionCollection*  m_properties;
};

/// \ingroup (typedefs)
/// \brief
/// FdoUniqueConstraintP is a FdoPtr on FdoUniqueConstraint, provided for convenience.
typedef FdoPtr<FdoUniqueConstraint> FdoUniqueConstraintP;

#endif



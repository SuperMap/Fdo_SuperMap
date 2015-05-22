#ifndef _PROPERTYVALUECONSTRAINT_H_
#define _PROPERTYVALUECONSTRAINT_H_

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
#include <Fdo/Schema/PropertyValueConstraintType.h>
#include <Fdo/Schema/SchemaException.h>

class FdoSchemaMergeContext;

/// \brief
/// FdoPropertyValueConstraint is an abstract class that derives from FdoIDisposable.
/// FdoPropertyValueConstraint is the base class of FdoPropertyValueConstraintRange 
/// and FdoPropertyValueConstraintList.
class FdoPropertyValueConstraint : public FdoIDisposable
{

public:
    /// \brief
    /// Abstract operation that must be implemented by derived classes to return the constraint type.
    /// 
    /// \return
    /// Returns the constraint type
    /// 
    FDO_API virtual FdoPropertyValueConstraintType GetConstraintType() = 0;

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    // Update this value constraint from the given value constraint.
    virtual void Set( FdoPropertyValueConstraint* /*pConstraint*/, FdoString* /*parentName*/, FdoSchemaMergeContext* /*pContext*/ )
    {
    }

    // \brief
    // Compares this value constraint with another one.
    // 
    // \param value 
    // The Property Value constraint to compare with
    // 
    // \return
    // Returns true if this Property Value Constraint is the same as pConstraint
    // (all members have the same values).
    virtual bool Equals( FdoPropertyValueConstraint* pConstraint ) = 0;
/// \endcond
};

#endif



#ifndef _FILTER_H_
#define _FILTER_H_
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
#include <Fdo/Filter/BinaryLogicalOperations.h>
#include <Fdo/Commands/IdentifierCollection.h>

class FdoIFilterProcessor;

/// \brief
/// The FdoFilter abstract class is a base class for condition and operator classes
/// that can occur in a filter expression tree. The FdoFilter class contains
/// operations for converting between the text and expression tree representation
/// of a filter.
class FdoFilter : public FdoIDisposable
{
/// \cond DOXYGEN-IGNORE
protected:
    FdoFilter();
    virtual ~FdoFilter();
/// \endcond

public:
    /// \brief
    /// Static operation that parses the well defined text representation and
    /// returns a Filter instance.
    /// 
    /// \param filterText 
    /// Input well defined text string
    /// 
    /// \return
    /// Returns root node of parse tree
    /// 
    FDO_API static FdoFilter* Parse(FdoString* filterText);

    /// \brief
    /// Abstract operation that takes an FdoIFilterProcessor as an argument.
    /// Concrete filter subclasses must override this method and pass themselves
    /// as an argument to the appropriate filter processor operation.
    /// 
    /// \param p 
    /// Input filter processor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Process(FdoIFilterProcessor* p) = 0;

    /// \brief
    /// Converts the filter expression to its well
    /// defined text representation.
    /// 
    /// \return
    /// Returns well defined text string
    /// 
    FDO_API FdoString* ToString();

/// \cond DOXYGEN-IGNORE

    /// \brief
    /// This is an internal method. It returns the well defined text representation of the filter. 
    /// 
    /// \param pIdCol 
    /// A identifier collection that contains all the computed identifier used by the filter
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    virtual FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol ) = 0;
/// \endcond

    /// \brief
    /// Static operation that combines two filters using the specified binary
    /// logical operation.
    /// 
    /// \param lhs 
    /// Input left hand expression as filter expression
    /// \param operation 
    /// Input binary logical operation
    /// \param rhs 
    /// Input right hand expression as filter expression
    /// 
    /// \return
    /// Returns new filter node
    /// 
    FDO_API static FdoFilter* Combine(FdoFilter* lhs, FdoBinaryLogicalOperations operation, FdoFilter* rhs);

    /// \brief
    /// Static operation that combines two filters using the specified binary
    /// logical operation.
    /// 
    /// \param lhs 
    /// Input left hand expression as well defined text string
    /// \param operation 
    /// Input binary logical operation
    /// \param rhs 
    /// Input right hand expression as filter expression
    /// 
    /// \return
    /// Returns new filter node
    /// 
    FDO_API static FdoFilter* Combine(FdoString* lhs, FdoBinaryLogicalOperations operation, FdoFilter* rhs);

    /// \brief
    /// Static operation that combines two filters using the specified binary
    /// logical operation.
    /// 
    /// \param lhs 
    /// Input left hand expression as filter expression
    /// \param operation 
    /// Input binary logical operation
    /// \param rhs 
    /// Input right hand expression as well defined text string
    /// 
    /// \return
    /// Returns new filter node
    /// 
    FDO_API static FdoFilter* Combine(FdoFilter* lhs, FdoBinaryLogicalOperations operation, FdoString* rhs);

    /// \brief
    /// Static operation that combines two filters using the specified binary
    /// logical operation.
    /// 
    /// \param lhs 
    /// Input left hand expression as well defined text string
    /// \param operation 
    /// Input binary logical operation
    /// \param rhs 
    /// Input right hand expression as well defined text string
    /// 
    /// \return
    /// Returns new filter node
    /// 
    FDO_API static FdoFilter* Combine(FdoString* lhs, FdoBinaryLogicalOperations operation, FdoString* rhs);

/// \cond DOXYGEN-IGNORE
protected:
    wchar_t*    m_toString;
/// \endcond
};
#endif



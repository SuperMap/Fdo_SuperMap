#ifndef _UNARYLOGICALOPERATOR_H_
#define _UNARYLOGICALOPERATOR_H_
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
#include <Fdo/Filter/Filter.h>
#include <Fdo/Filter/LogicalOperator.h>
#include <Fdo/Filter/UnaryLogicalOperations.h>

/// \brief
/// The FdoUnaryLogicalOperator class derives from FdoLogicalOperator and allows a
/// logical "Not" to be performed against a filter.
class FdoUnaryLogicalOperator : public FdoLogicalOperator
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a UnaryLogicalOperator.
    FdoUnaryLogicalOperator();

    /// Constructs an instance of a UnaryLogicalOperator using the specified
    /// arguments.
    FdoUnaryLogicalOperator(FdoFilter* operand, FdoUnaryLogicalOperations operation);

    virtual ~FdoUnaryLogicalOperator();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoUnaryLogicalOperator.
    /// 
    /// \return
    /// Returns FdoUnaryLogicalOperator
    /// 
    FDO_API static FdoUnaryLogicalOperator* Create();

    /// \brief
    /// Constructs an instance of an FdoUnaryLogicalOperator using the specified arguments.
    /// 
    /// \param operand 
    /// Input operand
    /// \param operation 
    /// Input operation
    /// 
    /// \return
    /// Returns FdoUnaryLogicalOperator
    /// 
    FDO_API static FdoUnaryLogicalOperator* Create(FdoFilter* operand, FdoUnaryLogicalOperations operation);

    /// \brief
    /// Gets the unary operation to be performed on the operand.
    /// 
    /// \return
    /// Returns the unary operation
    /// 
    FDO_API FdoUnaryLogicalOperations GetOperation();

    /// \brief
    /// Sets the unary operation to be performed on the operand.
    /// 
    /// \param value 
    /// Input the unary operation
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoUnaryLogicalOperations value);

    /// \brief
    /// Gets the FdoFilter operand to apply the operator to.
    /// 
    /// \return
    /// Returns filter
    /// 
    FDO_API FdoFilter* GetOperand();

    /// \brief
    /// Sets the FdoFilter operand to apply the operator to.
    /// 
    /// \param value 
    /// Input filter
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperand(FdoFilter* value);

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoUnaryLogicalOperator to the
    /// appropriate filter processor operation.
    /// 
    /// \param p 
    /// Input filter processor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIFilterProcessor* p);

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
    FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );
/// \endcond

private:
    FdoFilter*                  m_operand;
    FdoUnaryLogicalOperations   m_operation;
};
#endif



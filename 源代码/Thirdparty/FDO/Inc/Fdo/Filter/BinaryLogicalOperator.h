#ifndef _BINARYLOGICALOPERATOR_H_
#define _BINARYLOGICALOPERATOR_H_
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
#include <Fdo/Filter/Filter.h>
#include <Fdo/Filter/LogicalOperator.h>

/// \brief
/// The FdoBinaryLogicalOperator class derives from FdoLogicalOperator and allows two
/// filters to be combined via a logical "and" or a logical "or".
class FdoBinaryLogicalOperator : public FdoLogicalOperator
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoBinaryLogicalOperator.
    FdoBinaryLogicalOperator();

    /// Constructs an instance of an FdoBinaryLogicalOperator using the specified
    /// arguments.
    FdoBinaryLogicalOperator(FdoFilter* leftOperand, FdoBinaryLogicalOperations operation, FdoFilter* rightOperand);

    virtual ~FdoBinaryLogicalOperator();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoBinaryLogicalOperator.
    /// 
    /// \return
    /// Returns FdoBinaryLogicalOperator
    /// 
    FDO_API static FdoBinaryLogicalOperator* Create();

    /// \brief
    /// Constructs an instance of an FdoBinaryLogicalOperator using the specified arguments.
    /// 
    /// \param leftOperand 
    /// Input left hand operand
    /// \param operation 
    /// Input operator
    /// \param rightOperand 
    /// Input right hand operand
    /// 
    /// \return
    /// Returns FdoBinaryLogicalOperator
    /// 
    FDO_API static FdoBinaryLogicalOperator* Create(FdoFilter* leftOperand, FdoBinaryLogicalOperations operation, FdoFilter* rightOperand);

    /// \brief
    /// Gets the operation to be performed between the two operands.
    /// 
    /// \return
    /// Returns the operation to be performed
    /// 
    FDO_API FdoBinaryLogicalOperations GetOperation();

    /// \brief
    /// Sets the operation to be performed between the two operands.
    /// 
    /// \param value 
    /// Input the operation to be performed
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoBinaryLogicalOperations value);

    /// \brief
    /// Gets the filter that defines the left operand.
    /// 
    /// \return
    /// Returns the filter that defines the left operand
    /// 
    FDO_API FdoFilter* GetLeftOperand();

    /// \brief
    /// Sets the filter that defines the left operand.
    /// 
    /// \param value 
    /// Input the filter that defines the left operand
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLeftOperand(FdoFilter* value);

    /// \brief
    /// Gets the filter that defines the right operand.
    /// 
    /// \return
    /// Returns the filter that defines the right operand
    /// 
    FDO_API FdoFilter* GetRightOperand();

    /// \brief
    /// Sets the filter that defines the right operand.
    /// 
    /// \param value 
    /// Input the filter that defines the right operand
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetRightOperand(FdoFilter* value);

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoBinaryLogicalOperator to the
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
    FdoFilter*                  m_leftOperand;
    FdoFilter*                  m_rightOperand;
    FdoBinaryLogicalOperations  m_operation;
};
#endif



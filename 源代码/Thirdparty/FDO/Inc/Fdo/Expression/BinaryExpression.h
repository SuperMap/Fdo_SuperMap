#ifndef _BINARYEXPRESSION_H_
#define _BINARYEXPRESSION_H_
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
#include <Fdo/Expression/Expression.h>
#include <Fdo/Expression/BinaryOperations.h>

/// \brief
/// The FdoBinaryExpression class derives from FdoExpression and represents string
/// concatenation and the simple arithmetic operations add, subtract, multiply,
/// and divide.
class FdoBinaryExpression : public FdoExpression
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoBinaryExpression.
    FdoBinaryExpression();

    /// Constructs an instance of an FdoBinaryExpression using the specified arguments.
    FdoBinaryExpression(FdoExpression* leftExpression, FdoBinaryOperations operation, FdoExpression* rightExpression);

    virtual ~FdoBinaryExpression();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoBinaryExpression.
    /// 
    /// \return
    /// Returns FdoBinaryExpression
    /// 
    FDO_API static FdoBinaryExpression* Create();

    /// \brief
    /// Constructs an instance of an FdoBinaryExpression using the specified arguments.
    /// 
    /// \param leftExpression 
    /// Input left hand expression
    /// \param operation 
    /// Input binary operation
    /// \param rightExpression 
    /// Input right hand expression
    /// 
    /// \return
    /// Returns FdoBinaryExpression
    /// 
    FDO_API static FdoBinaryExpression* Create(FdoExpression* leftExpression, FdoBinaryOperations operation, FdoExpression* rightExpression);

    /// \brief
    /// Gets the binary operation to be evaluated by this expression.
    /// 
    /// \return
    /// Returns the binary operation
    /// 
    FDO_API FdoBinaryOperations GetOperation();

    /// \brief
    /// Sets the binary operation to be evaluated by this expression.
    /// 
    /// \param value 
    /// Input binary operation value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoBinaryOperations value);

    /// \brief
    /// Gets the expression on the left side of the binary expression.
    /// 
    /// \return
    /// Returns the left hand side expression
    /// 
    FDO_API FdoExpression* GetLeftExpression();

    /// \brief
    /// Sets the expression on the left side of the binary expression.
    /// 
    /// \param value 
    /// Input left side expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLeftExpression(FdoExpression* value);

    /// \brief
    /// Gets the expression on the right side of the binary expression.
    /// 
    /// \return
    /// Returns the right hand side expression
    /// 
    FDO_API FdoExpression* GetRightExpression();

    /// \brief
    /// Sets the expression on the right side of the binary expression.
    /// 
    /// \param value 
    /// Input right side expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetRightExpression(FdoExpression* value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoBinaryOperation to the appropriate expression processor operation.
    /// 
    /// \param p 
    /// Input the FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns the well defined text representation of this expression
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// This is an internal method. It returns the well defined text representation of the expression. 
    /// 
    /// \param pIdCol 
    /// A identifier collection that contains all the computed identifier used by the filter
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    virtual FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );

private:
      FdoBinaryOperations   m_operation;
      FdoExpression*        m_leftExpr;
      FdoExpression*        m_rightExpr;
};
#endif



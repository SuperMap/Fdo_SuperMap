#ifndef _UNARYEXPRESSION_H_
#define _UNARYEXPRESSION_H_
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
#include <Fdo/Expression/UnaryOperations.h>

/// \brief
/// The FdoUnaryExpression class derives from FdoExpression and allows negation of
/// arithmetic expressions.
class FdoUnaryExpression : public FdoExpression
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoUnaryExpression.
    FdoUnaryExpression();

    /// Constructs an instance of an FdoUnaryExpression using the specified arguments.
    FdoUnaryExpression(FdoUnaryOperations operation, FdoExpression* expression);

    /// Default destructor for FdoUnaryExpression.
    virtual ~FdoUnaryExpression();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoUnaryExpression.
    /// 
    /// \return
    /// Returns FdoUnaryExpression
    /// 
    FDO_API static FdoUnaryExpression* Create();

    /// \brief
    /// Constructs an instance of an FdoUnaryExpression using the specified arguments.
    /// 
    /// \param operation 
    /// Input the type of unary operation
    /// \param expression 
    /// Input the expression
    /// 
    /// \return
    /// Returns FdoUnaryExpression
    /// 
    FDO_API static FdoUnaryExpression* Create(FdoUnaryOperations operation, FdoExpression* expression);

    /// \brief
    ///  Gets the unary operation to be evaluated by this expression.
    /// 
    /// \return
    /// Returns the unary operation
    /// 
    FDO_API FdoUnaryOperations GetOperation();

    /// \brief
    /// Sets the unary operation to be evaluated by this expression.
    /// 
    /// \param value 
    /// Input the type of unary operation
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoUnaryOperations value);

    /// \brief
    /// Gets the expression to be operated on.
    /// 
    /// \return
    /// Returns the expression
    /// 
    FDO_API FdoExpression* GetExpression();

    /// \brief
    /// Sets the expression to be operated on.
    /// 
    /// \param value 
    /// Input the value expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetExpression(FdoExpression* value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoUnaryExpression to the
    /// appropriate expression processor operation.
    /// 
    /// \param p 
    /// Input expression processor interface
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
    FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );

private:
    FdoUnaryOperations  m_operation;
    FdoExpression*      m_expr;
};
#endif



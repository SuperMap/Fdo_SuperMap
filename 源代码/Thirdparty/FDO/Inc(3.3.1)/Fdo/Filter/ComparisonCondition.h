#ifndef _COMPARISONCONDITION_H_
#define _COMPARISONCONDITION_H_
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
#include <Fdo/Filter/ComparisonOperations.h>
#include <Fdo/Expression/Expression.h>
#include <Fdo/Filter/SearchCondition.h>

/// \brief
/// The FdoComparisonCondition class derives from FdoSearchCondition and can be used
/// to test the equality of two expressions.
class FdoComparisonCondition : public FdoSearchCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoComparisonCondition.
    FdoComparisonCondition();

    /// Constructs an instance of an FdoComparisonCondition using the specified
    /// arguments.
    FdoComparisonCondition(FdoExpression* leftExpression, FdoComparisonOperations operation, FdoExpression* rightExpression);

    virtual ~FdoComparisonCondition();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoComparisonCondition.
    /// 
    /// \return
    /// Returns FdoComparisonCondition
    /// 
    FDO_API static FdoComparisonCondition* Create();

    /// \brief
    /// Constructs an instance of a ComparisonCondition using the specified arguments.
    /// 
    /// \param leftExpression 
    /// Input the expression that defines the left side of the comparison
    /// \param operation 
    /// Input the operation to be used to compare the two expressions
    /// \param rightExpression 
    /// Input the expression that defines the right side of the comparison
    /// 
    /// \return
    /// Returns FdoComparisonCondition
    /// 
    FDO_API static FdoComparisonCondition* Create(FdoExpression* leftExpression, FdoComparisonOperations operation, FdoExpression* rightExpression);

    /// \brief
    /// Gets the operation to be used to compare the two expressions.
    /// 
    /// \return
    /// Returns the operation to be used to compare the two expressions
    /// 
    FDO_API FdoComparisonOperations GetOperation();

    /// \brief
    /// Sets the operation to be used to compare the two expressions.
    /// 
    /// \param operation 
    /// Input the operation to be used to compare the two expressions
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoComparisonOperations operation);

    /// \brief
    /// Gets the expression that defines the left side of the comparison.
    /// 
    /// \return
    /// Returns the expression that defines the left side of the comparison
    /// 
    FDO_API FdoExpression* GetLeftExpression();

    /// \brief
    /// Sets the expression that defines the left side of the comparison.
    /// 
    /// \param value 
    /// Input the expression that defines the left side of the comparison
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetLeftExpression(FdoExpression* value);

    /// \brief
    /// Gets the expression that defines the right side of the comparison.
    /// 
    /// \return
    /// Returns the expression that defines the right side of the comparison
    /// 
    FDO_API FdoExpression* GetRightExpression();

    /// \brief
    /// Sets the expression that defines the right side of the comparison.
    /// 
    /// \param value 
    /// Input the expression that defines the right side of the comparison
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetRightExpression(FdoExpression* value);

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoComparisonCondition to the
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
    FdoExpression*          m_leftExpression;
    FdoExpression*          m_rightExpression;
    FdoComparisonOperations m_operation;
};
#endif



#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
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

class FdoIExpressionProcessor;
class FdoIdentifierCollection;

/// \brief
/// FdoExpression is an abstract base class that forms the root of an expression
/// tree. The FdoExpression class contains operations for converting between the
/// well defined text representation and the object representation of an
/// expression.
class FdoExpression : public FdoIDisposable
{
protected:
/// \cond DOXYGEN-IGNORE
    FdoExpression();
    virtual ~FdoExpression();
/// \endcond

public:
    /// \brief
    /// Static operation that parses the specified text and returns an
    /// expression. An exception is thrown if the text does not conform to the
    /// well defined text representation of an expression.
    /// 
    /// \param expressionText 
    /// Input expression in well defined text
    /// 
    /// \return
    /// Returns parse tree root node
    /// 
    FDO_API static FdoExpression* Parse(FdoString* expressionText);

    /// \brief
    /// Abstract operation that takes an FdoIExpressionProcessor as an argument.
    /// Concrete expression subclasses must override this method and pass
    /// themselves as an argument to the appropriate expression processor
    /// operation.
    /// 
    /// \param p 
    /// Input expression processor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Process(FdoIExpressionProcessor* p) = 0;

    /// \brief
    /// Abstract operation that returns the well defined text representation of
    /// this expression.
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    FDO_API virtual FdoString* ToString() = 0;

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

protected:
    wchar_t*    m_toString;
};
#endif



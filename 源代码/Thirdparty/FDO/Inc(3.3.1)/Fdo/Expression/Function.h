#ifndef _FUNCTION_H_
#define _FUNCTION_H_
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
#include <Fdo/Expression/ExpressionCollection.h>

/// \brief
/// The FdoFunction class derives from FdoExpression and represents a function call. As
/// such it defines the name of the function and the collection of arguments to
/// be passed to it.
class FdoFunction : public FdoExpression
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoFunction.
    FdoFunction();

    /// Constructs an instance of a function using the specified arguments.
    FdoFunction(FdoString* name, FdoExpression** arguments, FdoInt32 numArgs);

    /// Default destructor for FdoFunction.
    virtual ~FdoFunction();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoFunction.
    /// 
    /// \return
    /// Returns FdoFunction class
    /// 
    FDO_API static FdoFunction* Create();

    /// \brief
    /// Constructs an instance of a function using the specified arguments.
    /// 
    /// \param name 
    /// Input name of the function
    /// \param arguments 
    /// Input pointer to arguments
    /// \param numArgs 
    /// Input number of arguments
    /// 
    /// \return
    /// Returns FdoFunction
    /// 
    FDO_API static FdoFunction* Create(FdoString* name, FdoExpression** arguments, FdoInt32 numArgs);

    /// \brief
    /// Constructs an instance of a function using the specified arguments.
    /// 
    /// \param name 
    /// Input name of the function
    /// \param arguments 
    /// Input arguments as collection
    /// 
    /// \return
    /// Returns FdoFunction
    /// 
    FDO_API static FdoFunction* Create(FdoString* name, FdoExpressionCollection* arguments);

    /// \brief
    /// Gets the name of the function.
    /// 
    /// \return
    /// Returns name of the function
    /// 
    FDO_API FdoString* GetName();

    /// \brief
    /// Sets the name of the function.
    /// 
    /// \param value 
    /// Input name of the function
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoString* value);

    /// \brief
    /// Gets the FdoExpressionCollection that contains the arguments to the
    /// function.
    /// 
    /// \return
    /// Returns arguments as collection
    /// 
    FDO_API FdoExpressionCollection* GetArguments();

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoFunction to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input expression processor
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
    wchar_t*                    m_name;
    FdoExpressionCollection*    ExpArguments;
};
#endif



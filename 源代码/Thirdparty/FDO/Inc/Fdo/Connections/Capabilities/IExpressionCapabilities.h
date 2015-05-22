#ifndef _IEXPRESSIONCAPABILITIES_H_
#define _IEXPRESSIONCAPABILITIES_H_
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
#include <Fdo/Expression/ExpressionType.h>
#include <Fdo/Connections/Capabilities/FunctionDefinitionCollection.h>

// Number function names
#define  FDO_FUNCTION_CEIL   L"Ceil"    // Returns the smallest integer greater than or equal to the expression value
#define  FDO_FUNCTION_FLOOR  L"Floor"   // Returns the largest integer equal to or less than the expression value

// Aggregates function names
#define  FDO_FUNCTION_AVG    L"Avg"     // Returns the average value of an expression
#define  FDO_FUNCTION_COUNT  L"Count"   // Returns the number of objects in the query
#define  FDO_FUNCTION_MAX    L"Max"     // Returns the maximum value of an expression
#define  FDO_FUNCTION_MIN    L"Min"     // Returns the minimum value of an expression
#define  FDO_FUNCTION_SUM    L"Sum"     // Returns the sum of values of an expression
#define  FDO_FUNCTION_SPATIALEXTENTS L"SpatialExtents" // Returns the minimum bounding rectangle of a Geometry expression


// Strings function names
#define  FDO_FUNCTION_LOWER  L"Lower"   // Returns strings with all lowercase letters
#define  FDO_FUNCTION_UPPER  L"Upper"   // Returns strings with all letters uppercase
#define  FDO_FUNCTION_CONCAT L"Concat"  // Returns the string concatenation of 2 expressions"


/// \brief
/// The FdoIExpressionCapbilities interface declares the feature provider's level
/// of support for FdoExpression classes.
class FdoIExpressionCapabilities : public FdoIDisposable
{
protected:

    /// \brief
    /// Constructs and return an FdoFunctionDefinitionCollection that contains a common list of
    /// function definition. Providers can pick the function they support and add them to their supported
    /// functions list. This method is internal to providers implementations.
    /// 
    /// \return
    /// Returns FdoFunctionDefinitionCollection
    /// 
    FDO_API static FdoFunctionDefinitionCollection* GetWellKnownFunctions();

public:
    /// \brief
    /// Returns an array of FdoExpressionType objects the feature provider supports.
    /// 
    /// \param length 
    /// Input the number of expression types
    /// 
    /// \return
    /// Returns the list of expression types
    /// 
    FDO_API virtual FdoExpressionType* GetExpressionTypes(FdoInt32& length) = 0;

    /// \brief
    /// Returns a collection of FdoFunctionDefinition objects the feature provider supports within expressions.
    /// 
    /// \return
    /// Returns the collection of function definitions
    /// 
    FDO_API virtual FdoFunctionDefinitionCollection* GetFunctions() = 0;
};
#endif



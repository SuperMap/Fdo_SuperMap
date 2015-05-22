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

// Expression Function Name Specifications
//  - Aggregates Function Names
#define  FDO_FUNCTION_AVG             L"Avg"             // Returns the average value of an expression
#define  FDO_FUNCTION_COUNT           L"Count"           // Returns the number of objects in the query
#define  FDO_FUNCTION_MAX             L"Max"             // Returns the maximum value of an expression
#define  FDO_FUNCTION_MEDIAN          L"Median"          // Returns the middle value or an interpolated value that
                                                         // would be the middle value once the values are sorted of
                                                         // an expression
#define  FDO_FUNCTION_MIN             L"Min"             // Returns the minimum value of an expression
#define  FDO_FUNCTION_SPATIALEXTENTS  L"SpatialExtents"  // Returns the minimum bounding rectangle of a geometry
                                                         // expression
#define  FDO_FUNCTION_STDDEV          L"Stddev"          // Returns the standard deviation of an expression
#define  FDO_FUNCTION_SUM             L"Sum"             // Returns the sum of values of an expression

//  - Conversion Function Names
#define  FDO_FUNCTION_NULLVALUE  L"NullValue"  // Evaluates two expressions and returns the first one if it does not
                                               // evaluate to NULL, the second otherwise
#define  FDO_FUNCTION_TODATE     L"ToDate"     // Converts a string to a date
#define  FDO_FUNCTION_TODOUBLE   L"ToDouble"   // Converts a numeric or string expression to a double
#define  FDO_FUNCTION_TOFLOAT    L"ToFloat"    // Converts a numeric or string expression to a float
#define  FDO_FUNCTION_TOINT32    L"ToInt32"    // Converts a numeric or string expression to an int32
#define  FDO_FUNCTION_TOINT64    L"ToInt64"    // Converts a numeric or string expression to an int64
#define  FDO_FUNCTION_TOSTRING   L"ToString"   // Converts a numeric or date expression to a string

//  - Date Function Names
#define  FDO_FUNCTION_ADDMONTHS      L"AddMonths"      // Adds a specified number of months to a date expression
#define  FDO_FUNCTION_CURRENTDATE    L"CurrentDate"    // Returns the current date
#define  FDO_FUNCTION_EXTRACT        L"Extract"        // Extracts a specified portion of a date
#define  FDO_FUNCTION_MONTHSBETWEEN  L"MonthsBetween"  // Returns the number of months between two date expressions

//  - Mathematical Function Names
#define  FDO_FUNCTION_ABS        L"Abs"        // Returns the absolute value of a numeric expression
#define  FDO_FUNCTION_ACOS       L"Acos"       // Returns the arc cosine of a numeric expression
#define  FDO_FUNCTION_ASIN       L"Asin"       // Returns the arc sine of a numeric expression
#define  FDO_FUNCTION_ATAN       L"Atan"       // Returns the arc tangent of a numeric expression
#define  FDO_FUNCTION_ATAN2      L"Atan2"      // Returns the arc tangent calculated of two numeric expressions
#define  FDO_FUNCTION_COS        L"Cos"        // Returns the cosine of a numeric expression
#define  FDO_FUNCTION_EXP        L"Exp"        // Returns e raised to the power of a numeric expression
#define  FDO_FUNCTION_LN         L"Ln"         // Returns the natural logarithm of a numeric expression
#define  FDO_FUNCTION_LOG        L"Log"        // Returns the logarithm of a numeric expression calculated on a given
                                               // base
#define  FDO_FUNCTION_MOD        L"Mod"        // Returns the remainder of a division of two numeric expressions
#define  FDO_FUNCTION_POWER      L"Power"      // Returns the result of one numeric expression raised to the power of
                                               // of a second numeric expression
#define  FDO_FUNCTION_REMAINDER  L"Remainder"  // Returns the remainder of a division of two numeric expressions
#define  FDO_FUNCTION_SIN        L"Sin"        // Returns the sine of a numeric expression
#define  FDO_FUNCTION_SQRT       L"Sqrt"       // Returns the square root of a numeric expression
#define  FDO_FUNCTION_TAN        L"Tan"        // Returns the tangent of a numeric expression

//  - Numeric function names
#define  FDO_FUNCTION_CEIL   L"Ceil"    // Returns the smallest integer greater than or equal to the expression value
#define  FDO_FUNCTION_FLOOR  L"Floor"   // Returns the largest integer equal to or less than the expression value
#define  FDO_FUNCTION_ROUND  L"Round"   // Returns the rounded value of an expression
#define  FDO_FUNCTION_SIGN   L"Sign"    // Returns -1 if a numeric expression evaluates to a value less than 0, 0
                                        // if the numeric expression evaluates to 0 and 1 if the numeric expression
                                        // evaluates to a value greater than 0
#define  FDO_FUNCTION_TRUNC  L"Trunc"   // Truncates a numeric or date expression

//  - Strings function names
#define  FDO_FUNCTION_CONCAT     L"Concat"     // Returns the string concatenation of 2 expressions
#define  FDO_FUNCTION_INSTR      L"Instr"      // Returns the position of a substring in a string expression
#define  FDO_FUNCTION_LENGTH     L"Length"     // Returns the length of a string expression
#define  FDO_FUNCTION_LOWER      L"Lower"      // Returns strings with all lowercase letters
#define  FDO_FUNCTION_LPAD       L"Lpad"       // Pads a string expression to the left to defined length
#define  FDO_FUNCTION_LTRIM      L"Ltrim"      // Removes leading blanks from a string expression
#define  FDO_FUNCTION_RPAD       L"Rpad"       // Pads a string expression to the right to defined length
#define  FDO_FUNCTION_RTRIM      L"Rtrim"      // Removes trailing blanks from a string expression
#define  FDO_FUNCTION_SOUNDEX    L"Soundex"    // Returns the phonetic representation of a string expression
#define  FDO_FUNCTION_SUBSTR     L"Substr"     // Extracts a substring from a string expression
#define  FDO_FUNCTION_TRANSLATE  L"Translate"  // Replaces a set of letters in a string expression
#define  FDO_FUNCTION_TRIM       L"Trim"       // Removes leading and/or trailing blanks from a string expression
#define  FDO_FUNCTION_UPPER      L"Upper"      // Returns strings with all letters uppercase

//  - Geometry function names
#define  FDO_FUNCTION_AREA2D    L"Area2D"    // Returns the area of a geometry expression
#define  FDO_FUNCTION_LENGTH2D  L"Length2D"  // Returns the length of a geometry expression


/// \brief
/// The FdoIExpressionCapbilities interface declares the feature provider's level
/// of support for FdoExpression classes.
class FdoIExpressionCapabilities : public FdoIDisposable
{
protected:

    /// \brief
    /// Constructs and returns an FdoFunctionDefinitionCollection that contains a common list of
    /// function definition. Providers can pick the function they support and add them to their supported
    /// functions list. This method is internal to providers implementations.
    /// 
    /// \return
    /// Returns FdoFunctionDefinitionCollection
    /// 
    FDO_API static FdoFunctionDefinitionCollection *GetWellKnownFunctions ();

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
    FDO_API virtual FdoExpressionType *GetExpressionTypes (FdoInt32& length) = 0;

    /// \brief
    /// Returns a collection of FdoFunctionDefinition objects the feature provider supports within expressions.
    /// 
    /// \return
    /// Returns the collection of function definitions
    /// 
    FDO_API virtual FdoFunctionDefinitionCollection *GetFunctions () = 0;

};
#endif



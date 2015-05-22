#ifndef _COMPARISONOPERATIONS_H_
#define _COMPARISONOPERATIONS_H_
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

/// \ingroup (enums)
/// \brief
/// The FdoComparisonOperations enumeration lists the comparison operations
/// available.
enum FdoComparisonOperations
{
    /// Test to see if the left and right expressions are equal.
    FdoComparisonOperations_EqualTo,

    /// Test to see if the left and right expressions are not equal.
    FdoComparisonOperations_NotEqualTo,

    /// Test to see if the left expression is greater than the right expression.
    FdoComparisonOperations_GreaterThan,

    /// Test to see if the left expression is greater than or equal to the right expression.
    FdoComparisonOperations_GreaterThanOrEqualTo,

    /// Test to see if the left expression is less than the right expression.
    FdoComparisonOperations_LessThan,

    /// Test to see if the left expression is less than or equal to the right expression.
    FdoComparisonOperations_LessThanOrEqualTo,

    /// Test to see if the left expression matches the pattern specified by the
    /// right expression.  Wildcard characters supported in the pattern are:
    //
    /// %    Any string of zero or more characters
    /// _    Any single character
    /// []   Any single character within the specified range ([a-f]) or set 
    /// ([abcdef]).
    /// [^]  Any single character not within the specified range ([^a-f]) or 
    /// set ([^abcdef]).
    FdoComparisonOperations_Like
};
#endif



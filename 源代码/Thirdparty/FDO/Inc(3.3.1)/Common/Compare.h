#ifndef FDO_COMPARE_H_
#define FDO_COMPARE_H_

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

/// \cond DOXYGEN-IGNORE

/// \brief
///  FdoCompareType is an enumeration of different value comparison results when comparing
///  value1 and value2
/// 
/// \param FdoCompareType_Undefined 
/// The values cannot be compared, usually due to different nullities or incompatible types.
/// \param FdoCompareType_Less 
/// Value 1 is less than value2
/// \param FdoCompareType_Greater 
/// Value 1 is greater than value2
/// \param FdoCompareType_Equal 
/// The values are equal or both null.
/// \param FdoCompareType_PartlyEqual 
/// One or both values are partly undefined but the defined parts are equal.
/// For example, a Date value (time undefined) and DateTime value are 
/// partly equal if their date parts are equal. A Date value and Time 
/// value are always considered partly equal (defined parts do not
/// overlap).
/// 
enum FdoCompareType
{
    FdoCompareType_Undefined,
    FdoCompareType_Less,
    FdoCompareType_Greater,
    FdoCompareType_Equal,
    FdoCompareType_PartlyEqual
};
/// \endcond

/// \cond DOXYGEN-IGNORE
// General function for comparing values of simple types or types that define the comparison operators.
template< class T> FdoCompareType FdoCompare( T val1, T val2 )
{
    FdoCompareType compare = FdoCompareType_Undefined;

    if ( val1 < val2 ) 
        compare = FdoCompareType_Less;
    else if ( val1 > val2 ) 
        compare = FdoCompareType_Greater;
    else 
        compare = FdoCompareType_Equal;

    return compare;
}
/// \endcond


#endif

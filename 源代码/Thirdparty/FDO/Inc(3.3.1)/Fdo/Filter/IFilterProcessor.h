#ifndef _IFILTERPROCESSOR_H_
#define _IFILTERPROCESSOR_H_
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
#include <Fdo/Filter/BinaryLogicalOperator.h>
#include <Fdo/Filter/ComparisonCondition.h>
#include <Fdo/Filter/DistanceCondition.h>
#include <Fdo/Filter/InCondition.h>
#include <Fdo/Filter/NullCondition.h>
#include <Fdo/Filter/SpatialCondition.h>
#include <Fdo/Filter/UnaryLogicalOperator.h>

/// \brief
/// The FdoIFilterProcessor interface can be used to process the nodes in a filter
/// tree. It declares a process operation for each concrete class in the filter
/// hierarchy. Providers or client applications can create classes that realize
/// this interface to do something meaningful with a filter hierarchy. For
/// example, a RDBMS feature provider can implement a processor class to convert a
/// filter hierarchy to the SQL equivalent syntax.
class FdoIFilterProcessor : public FdoIDisposable
{
public:
    /// \brief
    /// Processes the FdoBinaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoBinaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& filter) = 0;

    /// \brief
    /// Processes the FdoUnaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoUnaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& filter) = 0;

    /// \brief
    /// Processes the FdoComparisonCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoComparisonCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessComparisonCondition(FdoComparisonCondition& filter) = 0;

    /// \brief
    /// Processes the FdoInCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoInCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInCondition(FdoInCondition& filter) = 0;

    /// \brief
    /// Processes the FdoNullCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoNullCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessNullCondition(FdoNullCondition& filter) = 0;

    /// \brief
    /// Processes the FdoSpatialCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoSpatialCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessSpatialCondition(FdoSpatialCondition& filter) = 0;

    /// \brief
    /// Processes the FdoDistanceCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoDistanceCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDistanceCondition(FdoDistanceCondition& filter) = 0;
};
#endif



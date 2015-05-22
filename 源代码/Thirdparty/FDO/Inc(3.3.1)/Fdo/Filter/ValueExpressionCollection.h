#ifndef _VALUE_EXPRESSION_COLLECTION_H_
#define _VALUE_EXPRESSION_COLLECTION_H_
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
#include <Fdo/Expression/ValueExpression.h>
#include <Fdo/Expression/Parameter.h>
#include <Fdo/Filter/FilterException.h>

/// \brief
/// The FdoValueExpressionCollection class represents a collection of FdoValueExpression classes.
class FdoValueExpressionCollection: public FdoCollection<FdoValueExpression, FdoFilterException> 
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default empty instance of a ValueCollection.
    FdoValueExpressionCollection():FdoCollection<FdoValueExpression, FdoFilterException>()
    {
    }

    virtual ~FdoValueExpressionCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs a default empty instance of an FdoValueExpressionCollection.
    /// 
    /// \return
    /// Returns FdoValueExpressionCollection
    /// 
    static FDO_API FdoValueExpressionCollection* Create();

    /// \brief
    /// Constructs an FdoValueExpressionCollection using array of strings.
    /// 
    /// \param values 
    /// Input an array of values
    /// \param length 
    /// Input the number of values
    /// 
    /// \return
    /// Returns FdoValueExpressionCollection
    /// 
    static FDO_API FdoValueExpressionCollection* Create(FdoString** values, FdoInt32 length);
};
#endif



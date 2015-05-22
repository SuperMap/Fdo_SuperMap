#ifndef _INT32VALUE_H_
#define _INT32VALUE_H_
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
#include <Fdo/Expression/DataValue.h>
#include <Fdo/Schema/DataType.h>

/// \brief
/// The FdoInt32Value class derives from FdoDataValue and represents a 32-bit signed integer value.
class FdoInt32Value : public FdoDataValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoInt32Value with a
    /// value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoInt32Value();

    /// \brief
    /// Constructs a default instance of an FdoInt32Value using the specified arguments.
    /// \param value 
    /// Input a 32 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoInt32Value(FdoInt32 value);

    /// \brief
    /// Default destructor for FdoInt32Value.
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoInt32Value();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoInt32Value with a value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoInt32Value* Create();

    /// \brief
    /// Constructs a default instance of an FdoInt32Value using the specified arguments.
    /// 
    /// \param value 
    /// Input a 32 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API static FdoInt32Value* Create(FdoInt32 value);

    /// \brief
    /// Gets the data type of the FdoInt32Value.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the FdoInt32Value.
    /// 
    /// \return
    /// Returns a 32 bit integer
    /// 
    FDO_API FdoInt32 GetInt32();

    /// \brief
    /// Sets the FdoInt32Value.
    /// 
    /// \param value 
    /// Input a 32 bit integer
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetInt32(FdoInt32 value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoInt32Value to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input an FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a character string
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// A cast operator to get the integer value.
    /// 
    /// \return
    /// Returns a 32 bit integer
    /// 
    FDO_API operator FdoInt32()
    {
        return m_data;
    }

protected:
    FdoInt32    m_data;
};
#endif



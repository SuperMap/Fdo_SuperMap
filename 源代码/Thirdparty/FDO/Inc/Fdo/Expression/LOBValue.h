#ifndef _LOBVALUE_H_
#define _LOBVALUE_H_
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
/// The FdoLOBValue class derives from FdoDataValue and represents a literal
/// BLOB value.
class FdoLOBValue : public FdoDataValue
{

public:

    /// \brief
    /// Gets the data type of the FdoLOBValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API virtual FdoDataType GetDataType() = 0;

    /// \brief
    /// Gets the LOB value.
    /// 
    /// \return
    /// Returns a byte array
    /// 
    FDO_API virtual FdoByteArray* GetData() = 0;

    /// \brief
    /// Sets the LOB value.
    /// 
    /// \param value 
    /// Input an array of bytes
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetData(FdoByteArray* value) = 0;

    /// \brief
    /// Sets the FdoLOBValue to a null value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetNull() = 0;

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoLOBValue to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input the FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Process(FdoIExpressionProcessor* p) = 0;

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns a text string
    /// 
    FDO_API virtual FdoString* ToString() = 0;

    /// \brief
    /// A cast operator to get the BLOB value.
    /// 
    /// \return
    /// Returns a byte array
    /// 
    FDO_API operator FdoByteArray*()
    {
        return m_data;
    }

protected:
    FdoByteArray*   m_data;
};
#endif



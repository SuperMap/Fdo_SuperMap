#ifndef _CLOBVALUE_H_
#define _CLOBVALUE_H_
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
#include <Fdo/Expression/LOBValue.h>
#include <Fdo/Schema/DataType.h>

/// \brief
/// The FdoCLOBValue class derives from FdoLOBValue and represents a literal
/// CLOB value.
class FdoCLOBValue : public FdoLOBValue 
{
/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoCLOBValue with a value of null.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoCLOBValue();

    /// \brief
    /// Constructs a default instance of an FdoCLOBValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte array
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoCLOBValue(FdoByteArray* value);

    /// \brief
    /// Default destructor for FdoCLOBValue.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoCLOBValue();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoCLOBValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoCLOBValue
    /// 
    FDO_API static FdoCLOBValue* Create();

    /// \brief
    /// Constructs a default instance of an FdoCLOBValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte array
    /// 
    /// \return
    /// Returns the created FdoCLOBValue
    /// 
    FDO_API static FdoCLOBValue* Create(FdoByteArray* value);

    /// \brief
    /// Gets the data type of the FdoCLOBValue.
    /// 
    /// \return
    /// Returns an FdoDataType
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Gets the CLOB value.
    /// 
    /// \return
    /// Returns a byte array
    /// 
    FDO_API FdoByteArray* GetData();

    /// \brief
    /// Sets the CLOB value.
    /// 
    /// \param value 
    /// Input a byte array
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetData(FdoByteArray* value);

    /// \brief
    /// Sets the CLOB value to a null value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetNull();

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoCLOBValue to the appropriate
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
    /// Returns a text string
    /// 
    FDO_API FdoString* ToString();

};
#endif



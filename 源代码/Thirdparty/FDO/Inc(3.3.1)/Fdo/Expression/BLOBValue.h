#ifndef _BLOBVALUE_H_
#define _BLOBVALUE_H_
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
/// The FdoBLOBValue class derives from FdoLOBValue and represents a literal
/// BLOB value.
class FdoBLOBValue : public FdoLOBValue 
{
public:
    /// \brief
    /// Constructs a default instance of an FdoBLOBValue with a value of null.
    /// 
    /// \return
    /// Returns the created FdoBLOBValue
    /// 
    FDO_API static FdoBLOBValue* Create();

    /// \brief
    /// Constructs an instance of an FdoBLOBValue using the specified arguments.
    /// 
    /// \param value 
    /// Input a byte array
    /// 
    /// \return
    /// Returns the created FdoBLOBValue
    /// 
    FDO_API static FdoBLOBValue* Create(FdoByteArray* value);


    FDO_API FdoDataType GetDataType();
    FDO_API FdoByteArray* GetData();
    FDO_API void SetData(FdoByteArray* value);
    FDO_API void SetNull();
    FDO_API void Process(FdoIExpressionProcessor* p);
    FDO_API FdoString* ToString();


/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of an FdoBLOBValue with a value of null.
    /// \return
    /// Returns nothing
    /// 
    FdoBLOBValue();

    /// \brief
    /// Constructs a default instance of an FdoBLOBValue using the specified arguments.
    /// \param value 
    /// Input a byte array
    /// 
    /// \return
    /// Returns nothing
    /// 
    FdoBLOBValue(FdoByteArray* value);

    /// \brief
    /// Default destructor for FdoBLOBValue.
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoBLOBValue();

    virtual void Dispose();
/// \endcond

};
#endif



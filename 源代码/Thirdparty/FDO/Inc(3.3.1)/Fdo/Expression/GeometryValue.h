#ifndef _GEOMETRYVALUE_H_
#define _GEOMETRYVALUE_H_
// 

//
// Copyright (C) 2004-2007  Autodesk, Inc.
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
#include <Fdo/Expression/LiteralValue.h>

/// \brief
/// The FdoGeometryValue class derives from FdoLiteralValue and represents a geometric value.
class FdoGeometryValue : public FdoLiteralValue
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoGeometryValue with a value of null.
    FdoGeometryValue();

    /// Constructs an instance of an FdoGeometryValue using the specified arguments.
    FdoGeometryValue(FdoByteArray* geometry);

    /// Default destructor for GeometryValue.
    virtual ~FdoGeometryValue();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoGeometryValue with a value of null.
    /// 
    /// \return
    /// Returns FdoGeometryValue
    /// 
    FDO_API static FdoGeometryValue* Create();

    /// \brief
    /// Constructs an instance of an FdoGeometryValue using the specified arguments.
    /// 
    /// \param geometry 
    /// Input geometry byte array
    /// 
    /// \return
    /// Returns FdoGeometryValue
    /// 
    FDO_API static FdoGeometryValue* Create(FdoByteArray* geometry);

    /// \brief
    /// Returns true if the FdoGeometryValue represents a null value.
    /// 
    /// \return
    /// Returns true if null geometry
    /// 
    FDO_API bool IsNull();

    /// \brief
    /// Gets the geometry as a byte array. The geometry is expected to be
    /// encoded in Autodesk Well-Known Binary format.
    /// 
    /// \return
    /// Returns geometry in FGF format
    /// 
    FDO_API FdoByteArray* GetGeometry();

    /// \brief
    /// Sets the geometry as a byte array. The geometry is expected to be
    /// encoded in Autodesk Well-Known Binary format.
    /// 
    /// \param value 
    /// Input geometry in FGF format
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetGeometry(FdoByteArray* value);

    /// \brief
    /// Sets the FdoGeometryValue to a null value.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetNullValue();

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoGeometryValue to the
    /// appropriate expression processor operation.
    /// 
    /// \param p 
    /// Input the expression processor interface
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    FDO_API FdoString* ToString();

    /// \brief
    /// Gets the literal value type of the FdoGeometryValue.
    /// 
    /// \return
    /// Returns an FdoLiteralValueType
    /// 
    FDO_API virtual FdoLiteralValueType GetLiteralValueType() const;

/// \cond DOXYGEN-IGNORE
protected:
    FdoByteArray*    m_geometry;
/// \endcond
};
#endif



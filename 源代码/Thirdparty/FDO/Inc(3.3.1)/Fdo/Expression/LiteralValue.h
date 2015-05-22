#ifndef _LITERALVALUE_H_
#define _LITERALVALUE_H_
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
#include <Fdo/Expression/ValueExpression.h>
#include <Fdo/Expression/LiteralValueType.h>

/// \brief
/// FdoLiteralValue is an abstract base class that derives from FdoValueExpression to
/// form the root for all literal value types.
class FdoLiteralValue : public FdoValueExpression
{
public:

    /// \brief
    /// Gets the literal value type of the FdoLiteralValue.
    /// 
    /// \return
    /// Returns an FdoLiteralValueType
    /// 
	FDO_API virtual FdoLiteralValueType GetLiteralValueType() const = 0;
};
#endif



#ifndef _LITERALVALUECOLLECTION_H_
#define _LITERALVALUECOLLECTION_H_
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
#include <Fdo/Expression/ExpressionException.h>

class FdoLiteralValueCollection : public FdoCollection<FdoLiteralValue, FdoExpressionException>
{
protected:
    FdoLiteralValueCollection() : FdoCollection<FdoLiteralValue, FdoExpressionException>()
    {
    }

    virtual ~FdoLiteralValueCollection()
    {
    }

    virtual void Dispose()
    {
        delete this;
    }

public:
    /// \brief
    /// Constructs a default instance of an FdoLiteralValueCollection.
    /// 
    /// \return
    /// Returns FdoLiteralValueCollection
    /// 
    FDO_API static FdoLiteralValueCollection* Create();
};

#endif


#ifndef _FUNCTIONDEFINITIONCOLLECTION_H_
#define _FUNCTIONDEFINITIONCOLLECTION_H_
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
#include <Fdo/Connections/Capabilities/FunctionDefinition.h>
#include <Fdo/Connections/ConnectionException.h>

/// \brief
/// The FdoFunctionDefinitionCollection class represents a collection of FdoFunctionDefinition objects.
class FdoFunctionDefinitionCollection : public FdoNamedCollection<FdoFunctionDefinition, FdoConnectionException>
{
protected:
    virtual void Dispose();

public:
    /// \brief
    /// Constructs a default empty instance of an FdoFunctionDefinitionCollection.
    /// 
    /// \return
    /// Returns FdoFunctionDefinitionCollection
    /// 
    FDO_API static FdoFunctionDefinitionCollection* Create();

    /// \brief
    /// Constructs an instance of an FdoFunctionDefinitionCollection from an array of 
    /// FdoFunctionDefinition objects.
    /// 
    /// \param arguments 
    /// Input an array of FdoFunctionDefinition objects
    /// \param length 
    /// Input the number of arguments
    /// 
    /// \return
    /// Returns FdoFunctionDefinitionCollection
    /// 
    FDO_API static FdoFunctionDefinitionCollection* Create(FdoFunctionDefinition** arguments, FdoInt32 length);
};
#endif



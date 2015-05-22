#ifndef _CLASS_H_
#define _CLASS_H_

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
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Schema/ClassType.h>

/// \brief
/// The FdoClass class derives from FdoClassDefinition and can be used to represent any type of
/// non-spatial data within a feature schema. Typically, classes are used in the
/// feature schema to define complex properties of other feature types by
/// containment. However, they can also be used at global scope and
/// instances can be created, deleted, updated, and selected through FDO
/// commands. The Class type does not pre-define any base properties.
class FdoClass : public FdoClassDefinition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoClass.
    FdoClass();

    /// Constructs an instance of an FdoClass using the specified arguments.
    FdoClass(FdoString* name, FdoString* description);

    virtual ~FdoClass();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoClass.
    /// 
    /// \return
    /// Returns FdoClass
    /// 
    FDO_API static FdoClass* Create();

    /// \brief
    /// Constructs an instance of an FdoClass using the specified arguments.
    /// 
    /// \param name 
    /// Input name
    /// \param description 
    /// Input description
    /// 
    /// \return
    /// Returns FdoClass
    /// 
    FDO_API static FdoClass* Create(FdoString* name, FdoString* description);

    /// \brief
    /// Gets the concrete class type.
    /// 
    /// \return
    /// Returns class type
    /// 
    FDO_API virtual FdoClassType GetClassType();

/// \cond DOXYGEN-IGNORE

    /// Public non-API functions for XML support

    /// Initialize this class from its XML attributes
    virtual void InitFromXml(FdoString* classTypeName, FdoSchemaXmlContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serializes this class to XML.
    virtual void _writeXml( FdoSchemaXmlContext* pContext );
/// \endcond
};

/// \ingroup (typedefs)
/// \brief
/// FdoClassP is a FdoPtr on FdoClass, provided for convenience.
typedef FdoPtr<FdoClass> FdoClassP;

#endif



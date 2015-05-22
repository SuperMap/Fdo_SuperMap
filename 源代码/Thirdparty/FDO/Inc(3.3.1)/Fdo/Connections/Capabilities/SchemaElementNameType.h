#ifndef _SCHEMAELEMENTNAMETYPE_H_
#define _SCHEMAELEMENTNAMETYPE_H_

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

/// \ingroup (enums)
/// \brief
/// The FdoSchemaElementNameType enumeration lists all of the concrete schema name
/// types defined to address schema limitation information.

enum FdoSchemaElementNameType
{

    /// Represents the identifier to address a data store name.
    FdoSchemaElementNameType_Datastore,

    /// Represents the identifier to address a schema.
    FdoSchemaElementNameType_Schema,

    /// Represents the identifier to address a class.
    FdoSchemaElementNameType_Class,

    /// Represents the identifier to address a property.
    FdoSchemaElementNameType_Property,

    /// Represents the identifier to address a description.
    FdoSchemaElementNameType_Description,

};  //  FdoSchemaElementNameType
#endif



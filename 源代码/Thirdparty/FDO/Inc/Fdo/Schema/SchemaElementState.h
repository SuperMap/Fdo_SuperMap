#ifndef _SCHEMAELEMENTSTATE_H_
#define _SCHEMAELEMENTSTATE_H_
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

/// \ingroup (enums)
/// \brief
/// The FdoSchemaElementState enumeration defines the current state of the schema element
enum FdoSchemaElementState
{
    /// Indicates the schema element has been added.
    FdoSchemaElementState_Added,

    /// Indicates the schema element is marked for deletion.
    FdoSchemaElementState_Deleted,

    /// Indicates the schema element is not associated with an FdoFeatureSchema.
    FdoSchemaElementState_Detached,

    /// Indicates the schema element has been modified in some way.
    FdoSchemaElementState_Modified,

    /// Indicates the schema element has not been changed.
    FdoSchemaElementState_Unchanged
};
#endif



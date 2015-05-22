#ifndef _DELETERULE_H_
#define _DELETERULE_H_

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
/// The FdoDeleteRule enumeration specifies the action to take when a delete
/// operation is executed on the class instance at the other end of the
/// relation.
enum FdoDeleteRule
{
    /// Cascade the delete operation to class instances at this end of the relation.
    FdoDeleteRule_Cascade,

    /// Prevent the delete operation if there are class instances at this end of the relation.
    FdoDeleteRule_Prevent,

    /// Break the relationship by setting the identifying properties at this end to null values.
    FdoDeleteRule_Break
};

#endif



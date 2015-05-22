// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef _SHPCOMMANDTYPE_H_
#define _SHPCOMMANDTYPE_H_

#include "Fdo/Commands/CommandType.h"

// This number is defined so our custom command would not clash with other
// custom provider commands.
#define SHP_FIRST_PROVIDER_COMMAND 911


/// \brief
/// The ShpCommandType enumeration defines the list of SHP+ commands.
/// Represents the SHP specific commands.
/// </param>

enum ShpCommandType {

    /// Represents the CreateSDFFile command.
    ShpCommandType_ExtendedSelect =  FdoCommandType_FirstProviderCommand + SHP_FIRST_PROVIDER_COMMAND
};






#endif



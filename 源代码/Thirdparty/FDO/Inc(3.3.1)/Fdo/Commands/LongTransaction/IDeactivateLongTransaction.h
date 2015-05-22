#ifndef _IDEACTIVATELONGTRANSACTION_H_
#define _IDEACTIVATELONGTRANSACTION_H_
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
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIDeactivateLongTransaction interface defines the 
/// DeactivateLongTransaction command, which deactivates the active long 
/// transaction where feature manipulation commands operate on it. If the 
/// active long transaction is the root long transaction, then no long
/// transaction will be deactivated.
class FdoIDeactivateLongTransaction : public FdoICommand
{
    friend class FdoIConnection;

public:

    /// \brief
    /// Executes the deactivate long transaction command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



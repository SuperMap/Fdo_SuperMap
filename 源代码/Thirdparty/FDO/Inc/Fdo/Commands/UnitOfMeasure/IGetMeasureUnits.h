#ifndef _IGETMEASUREUNITS_H_
#define _IGETMEASUREUNITS_H_
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
#include <Fdo/Commands/UnitOfMeasure/IMeasureUnitReader.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoIGetMeasureUnits interface defines the GetMeasureUnits command, which
/// enumerates the existing measurement units.
class FdoIGetMeasureUnits : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Executes the GetMeasureUnits command and returns an FdoIMeasureUnitReader.
    /// 
    /// \return
    /// Returns the measure unit reader
    /// 
    FDO_API virtual FdoIMeasureUnitReader* Execute() = 0;
};
#endif



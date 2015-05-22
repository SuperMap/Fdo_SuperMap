#ifndef _ILISTDATASTORES_H_
#define _ILISTDATASTORES_H_
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
#include <Fdo/Commands/DataStore/IDataStoreReader.h>

/// \brief
/// The FdoIListDataStores interface defines the list datastores command,
/// which provides a way to get a list of datastores at a particular server. 
class FdoIListDataStores : public FdoICommand
{
friend class FdoIConnection;

public:
    
    /// \brief
    /// Gets the flag that indicates whether to include or
    /// not include Non-FDO enabled datastores in the returned list.
    /// These are also referred to as foreign datastores.
    /// 
    /// \return
    /// Returns the flag
    /// 
	FDO_API virtual bool GetIncludeNonFdoEnabledDatastores() = 0;

    /// \brief
    /// Sets the flag to indicate whether to include or not include
    /// Non-FDO enabled datastores in the returned list. These are also
    /// referred to as foreign datastores.
    /// 
    /// \return
    /// Returns nothing
    /// 
	FDO_API virtual void SetIncludeNonFdoEnabledDatastores(bool include) = 0;

    /// \brief
    /// Executes the FdoIListDataStores command.
    /// 
    /// \return
    /// Returns nothing
    /// 
	FDO_API virtual FdoIDataStoreReader* Execute() = 0;
};

#endif



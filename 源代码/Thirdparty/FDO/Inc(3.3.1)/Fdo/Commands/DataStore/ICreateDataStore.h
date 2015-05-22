#ifndef _ICREATEDATASTORE_H_
#define _ICREATEDATASTORE_H_
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
#include <Fdo/Commands/DataStore/IDataStorePropertyDictionary.h>

/// \brief
/// The FdoICreateDataStore interface defines the create datastore command,
/// which can be used to create new provider specific datastores. The input is provided
/// through a dictionary of name value pairs that is provider dependant. 
class FdoICreateDataStore :	public FdoICommand
{
	friend class FdoIConnection;

public:

    /// \brief
    /// Gets the FdoIDataStorePropertyDictionary interface that	
    /// can be used to dynamically query	and	set	the	properties required	
    /// to create a new datastore.
    /// 
    /// \return
    /// Returns the property dictionary
    /// 
	FDO_API	virtual	FdoIDataStorePropertyDictionary* GetDataStoreProperties() = 0;

    /// \brief
    /// Executes the FdoICreateDataStore command.
    /// 
    /// \return
    /// Returns nothing
    /// 
	FDO_API	virtual	void Execute() = 0;
};

#endif



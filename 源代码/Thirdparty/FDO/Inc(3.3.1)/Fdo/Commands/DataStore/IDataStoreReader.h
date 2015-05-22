#ifndef _IDATASTOREREADER_H_
#define _IDATASTOREREADER_H_
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
/// The FdoIDataStoreReader interface provides a forward-only, read-only iterator
/// for reading feature data.  A reference to an FdoIDataStoreReader is returned
/// from the IListDataStores command. Because the initial position of the
/// FdoIDataStoreReader is prior to the first item, you must call
/// ReadNext to begin accessing any data.
class FdoIDataStoreReader : public FdoIDisposable
{
public:

    /// \brief
    /// Gets the name of the datastore currently being read.
    /// 
    /// \return
    /// Returns the description of the datastore.
    /// 
	FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Gets the description of the datastore currently being read.
    /// 
    /// \return
    /// Returns the description of the datastore.
    /// 
	FDO_API virtual FdoString* GetDescription() = 0;

    /// \brief
    /// Gets the flag that indicates whether the datastore is FDO enabled.
    /// Non-FDO databases are also referred to as foreign datastores.
    /// 
    /// \return
    /// Returns the flag
    /// 
	FDO_API virtual bool GetIsFdoEnabled() = 0;

    /// \brief
    /// Gets the FdoIConnectionPropertyDictionary interface that 
    /// includes the properties of the datastores set at datastore create 
    /// time, with the exception of password.
    /// 
    /// \return
    /// Returns the property dictionary
    /// 
	FDO_API virtual FdoIDataStorePropertyDictionary* GetDataStoreProperties() = 0;

    /// \brief
    /// Advances the reader to the next item and returns true if there is
    /// another object to read or false if reading is complete. The default
    /// position of the reader is prior to the first item. Thus you must
    /// call ReadNext to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
	FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoIDataStoreReader object, freeing any resources it may be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
	FDO_API virtual void Close() = 0;
};

#endif



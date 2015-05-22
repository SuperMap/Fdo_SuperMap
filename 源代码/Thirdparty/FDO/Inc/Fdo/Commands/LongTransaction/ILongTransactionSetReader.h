#ifndef _ILONGTRANSACTIONSETREADER_H_
#define _ILONGTRANSACTIONSETREADER_H_
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
#include <Fdo/Commands/LongTransaction/LongTransactionConstants.h>

/// \brief
/// The FdoILongTransactionSetReader interface provides forward only, read-only
/// functionality for enumerating the versions in the long transaction selection
/// set.  A reference to an FdoILongTransactionSetReader is returned from the
/// GetLongTransactionsInSet command. The initial position of the
/// FdoILongTransactionSetReader is prior to the first item. Thus, you must
/// call ReadNext to begin accessing any data.
class FdoILongTransactionSetReader : public FdoIDisposable
{
public:
    /// \brief
    /// Gets the name of the long transaction in the selection set currently
    /// being read.
    /// 
    /// \return
    /// Returns the long transaction name
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Gets the owner of the long transaction in the selection set currently
    /// being read.
    /// 
    /// \return
    /// Returns the owner of the long transaction
    /// 
    FDO_API virtual FdoString* GetOwner() = 0;

    /// \brief
    /// Advances the reader to the next item. The default position of the
    /// reader is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data.
    /// 
    /// \return
    /// Returns true if there is a next item.
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Closes the FdoILongTransactionSetReader object, freeing any resources
    /// it may be holding.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Close() = 0;
};
#endif



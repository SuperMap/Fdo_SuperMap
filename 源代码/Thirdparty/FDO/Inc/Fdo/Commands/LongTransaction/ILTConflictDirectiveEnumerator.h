#ifndef _ILONGTRANSACTIONCONFLICTDIRECTIVEENUMERATOR_H_
#define _ILONGTRANSACTIONCONFLICTDIRECTIVEENUMERATOR_H_
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
#include <Fdo/Commands/LongTransaction/LongTransactionConflictResolution.h>

/// \brief
/// The FdoILongTransactionConflictDirective interface is used to specify how
/// conflict should be resolved for a particular object.
class FdoILongTransactionConflictDirectiveEnumerator : public FdoIDisposable
{
  public:
    /// \brief
    /// Gets the class name of the current feature in conflict.
    /// 
    /// \return
    /// Returns the class name
    /// 
    FDO_API virtual FdoString* GetFeatureClassName() = 0;

    /// \brief
    /// Returns FdoPropertyValueCollection containing the property values that
    /// uniquely identify the current feature in conflict.
    /// 
    /// \return
    /// Returns FdoPropertyValueCollection
    /// 
    FDO_API virtual FdoPropertyValueCollection* GetIdentity() = 0;

    /// \brief
    /// Gets the FdoLongTransactionConflictResolution value to use for the current
    /// feature. The default value is FdoLongTransactionConflictResolution_Child.
    /// 
    /// \return
    /// Returns FdoLongTransactionConflictResolution value
    /// 
    FDO_API virtual FdoLongTransactionConflictResolution GetResolution() = 0;

    /// \brief
    /// Sets the FdoLongTransactionConflictResolution value to use for the current
    /// feature. The default value is FdoLongTransactionConflictResolution_Child.
    /// 
    /// \param value 
    /// Input the FdoLongTransactionConflictResolution value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetResolution(FdoLongTransactionConflictResolution value) = 0;

    /// \brief
    /// Returns the number of conflicts reported by this enumerator.
    /// 
    /// \return
    /// Returns the number of conflicts
    /// 
    FDO_API virtual FdoInt32 GetCount() = 0;

    /// \brief
    /// Advances the enumerator to the next conflict. The default position of the
    /// enumerator is prior to the first item. Thus, you must call ReadNext
    /// to begin accessing any data. ReadNext returns true until the end of the
    /// directives is reached. After the end of the directives is passed,
    /// subsequent calls to ReadNext return false until Reset is called.
    /// 
    /// \return
    /// Returns True until the end of the
    /// directives is reached
    /// 
    FDO_API virtual bool ReadNext() = 0;

    /// \brief
    /// Sets the enumerator to its initial position, which is before the first
    /// conflict.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Reset() = 0;
};
#endif



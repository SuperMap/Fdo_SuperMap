#ifndef _CLASSCAPABILITIES_H_
#define _CLASSCAPABILITIES_H_

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
#include <Fdo/Schema/SchemaElement.h>
#include <Fdo/Commands/Locking/LockType.h>

class FdoClassDefinition;

/// \brief
/// The FdoClassCapabilites class describes various capabilities
/// for a particular FDO Class Definition and an FDO Provider datastore.
class FdoClassCapabilities : 
    public FdoIDisposable
{
protected:
/// \cond DOXYGEN-IGNORE
    FdoClassCapabilities();

    FdoClassCapabilities(FdoClassDefinition& parent);

    virtual ~FdoClassCapabilities();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Gets the locking support capability.
    /// 
    /// \return
    /// Returns true if objects of this class can be locked
    /// 
    FDO_API FdoBoolean SupportsLocking();

    /// \brief
    /// Gets an array of the FdoLockType values supported by the feature provider.
    /// 
    /// \param size 
    /// Output the number of lock types
    /// 
    /// \return
    /// Returns the list of lock types
    /// 
    FDO_API FdoLockType* GetLockTypes(FdoInt32& size);

    /// \brief
    /// Gets the long transaction support capability.
    /// 
    /// \return
    /// Returns true if long transactions can be created on objects
    /// of this class
    /// 
    FDO_API FdoBoolean SupportsLongTransactions();

    /// \brief
    /// Gets the parent of this Class Capabilites object.
    /// 
    /// \return
    /// Returns FdoClassDefinition
    /// 
    FDO_API FdoClassDefinition* GetParent();

    /// \brief
    /// Constructs an FdoClassCapabilities instance. This function
    /// should only be called from an FDO Provider.
    /// 
    /// \param parent 
    /// Input The Fdo Class Definition that owns these
    /// capabilities.
    /// 
    /// \return
    /// Returns FdoClassCapabilities
    /// 
    FDO_API static FdoClassCapabilities* Create(FdoClassDefinition& parent);

    /// \brief
    /// Sets the locking support capability.
    /// 
    /// \param value 
    /// Input The locking support capability
    /// 
    FDO_API void SetSupportsLocking(FdoBoolean value);

    /// \brief
    /// Sets the locking types support capability. This function should only 
    /// be called from an FDO Provider.
    /// 
    /// \param types 
    /// The supported array of lock types
    /// \param size 
    /// The number of lock types
    /// 
    FDO_API void SetLockTypes(const FdoLockType* types, FdoInt32 size);

    /// \brief
    /// Sets the long transaction support capability.
    /// 
    /// \param value 
    /// Input The long transaction capability
    /// 
    FDO_API void SetSupportsLongTransactions(FdoBoolean value);

    /// \brief
    /// Returns true if the class supports write.
    /// 
    FDO_API FdoBoolean SupportsWrite();

    /// \brief
    /// Sets the flag indicating whether or not write is supported. This function should only 
    /// be called from an FDO Provider.
    /// 
    /// \param value 
    /// Input The capability
    /// 
    FDO_API void SetSupportsWrite(FdoBoolean value);

private:
    FdoBoolean          m_supportsLocking;
    FdoBoolean          m_supportsLongTransactions;
    FdoBoolean          m_supportsWrite;
    FdoClassDefinition* m_parent;
    FdoLockType*        m_lockTypes;
    FdoInt32            m_lockTypeCount;

};

/// \ingroup (typedefs)
/// \brief
/// FdoClassCapabilitiesP is a FdoPtr on FdoClassCapabilities, provided for convenience.
typedef FdoPtr<FdoClassCapabilities> FdoClassCapabilitiesP;

#endif



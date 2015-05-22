#ifndef _IINSERT_H_
#define _IINSERT_H_
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
#include <Fdo/Commands/IFeatureCommand.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/PropertyValueCollection.h>
#include <Fdo/Commands/BatchParameterValueCollection.h>
#include <Fdo/Commands/Feature/IFeatureReader.h>

/// \brief
/// The FdoIInsert interface defines the Insert command, which inserts a new
/// instance of a given class. Input to the insert command includes the name of
/// the class and a collection of property values. Properties that are
/// not specified and do not have a default value will be assigned a null value
/// or an exception will be thrown if the property is required. The insert
/// command can insert instances at global scope or instances nested within an
/// object collection property. Instances at global scope are referred to simply
/// by the class name. Instances at a nested scope (i.e. instances within a
/// object collection property) are referred to by the containing class name,
/// followed by a '.', followed by the object collection property name.
class FdoIInsert : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the class to be operated upon as an FdoIdentifier.
    /// 
    /// \return
    /// Returns the class name.
    /// 
    FDO_API virtual FdoIdentifier* GetFeatureClassName() = 0;

    /// \brief
    /// Sets the name of the class to be operated upon as an FdoIdentifier.
    /// 
    /// \param value 
    /// Input the identifier for the class.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureClassName(FdoIdentifier* value) = 0;

    /// \brief
    /// Sets the name of the class to be operated upon as an FdoIdentifier.
    /// 
    /// \param value 
    /// Input the class name.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureClassName(FdoString* value) = 0;

    /// \brief
    /// Gets the FdoPropertyValueCollection that specifies the names and values
    /// of the properties for the instance to be inserted.
    /// 
    /// \return
    /// Returns the list of properties and their values.
    /// 
    FDO_API virtual FdoPropertyValueCollection* GetPropertyValues() = 0;

    /// \brief
    /// Gets the FdoBatchParameterValueCollection that can be used for optimized
    /// batch inserts of multiple features with a single insert command. Batch
    /// inserts can be performed by using Parameters for each of the property
    /// values, then adding collections of parameter values to the
    /// FdoBatchParameterValueCollection. Each FdoParameterValueCollection in the
    /// FdoBatchParameterValueCollection should contain one FdoParameterValue for each
    /// of the parameters specified for property values.
    /// 
    /// \return
    /// Returns FdoBatchParameterValueCollection
    /// 
    FDO_API virtual FdoBatchParameterValueCollection* GetBatchParameterValues() = 0;

    /// \brief
    /// Executes the insert command and returns a reference to an
    /// FdoIFeatureReader. Some feature providers can generate automatic identity
    /// values for features. This will happen automatically as the features are
    /// inserted. The returned FdoIFeatureReader allows the client to obtain the
    /// automatic identity property value(s) of newly inserted object(s). The
    /// returned feature reader at a minimum will read the unique identity
    /// properties of the objects just inserted. Multiple objects will be
    /// returned through the reader in the case of a batch insert.
    /// 
    /// \return
    /// Returns an FdoIFeatureReader
    /// 
    FDO_API virtual FdoIFeatureReader* Execute() = 0;
};
#endif



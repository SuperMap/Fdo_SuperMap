/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef FDOCOMMONFEATURECOMMAND_H
#define FDOCOMMONFEATURECOMMAND_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <FdoCommonCommand.h>

template <class FDO_COMMAND, class CONNECTION_CLASS> class FdoCommonFeatureCommand :
    public FdoCommonCommand<FDO_COMMAND, CONNECTION_CLASS>
{
    //friend class CONNECTION_CLASS;

protected:
    FdoPtr<FdoFilter> mFilter;         // the command filter
    FdoPtr<FdoIdentifier> mClassName;  // the name of the feature class
    FdoPtr<FdoPropertyValueCollection> mValues;  // the collection of values to insert or update

protected:

    /// Constructs an instance of a command for the given connection.    
    FdoCommonFeatureCommand (FdoIConnection* connection) :
        FdoCommonCommand<FDO_COMMAND,CONNECTION_CLASS>(connection)  // superclass constructor
    {
    }

    /// Default destructor for a command.
    virtual ~FdoCommonFeatureCommand() 
    { 
    }

    virtual void Dispose()
    {
        delete this;
    }

    /// \brief
    /// Gets the FdoPropertyValueCollection that specifies the names and values
    /// of the properties for the instance to be inserted OR updated.
    /// 
    /// \return
    /// Returns the list of properties and their values.
    /// 
    virtual FdoPropertyValueCollection* GetPropertyValues ()
    {
    /// allocate a new property value collection if not yet done
        if (mValues == NULL)
            mValues = FdoPropertyValueCollection::Create ();

        return (FDO_SAFE_ADDREF(mValues.p));
    }

public:

    /// \brief
    /// Gets the filter as a filter tree.
    /// 
    /// \return
    /// Returns the filter object
    /// 
    virtual FdoFilter* GetFilter ();

    /// \brief
    /// Sets the filter as a Filter tree.
    /// 
    /// \param value 
    /// Input the filter object
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void SetFilter (FdoFilter* value);

    /// \brief
    /// Sets the filter as a Filter tree.
    /// 
    /// \param value 
    /// Input the filter expression string
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void SetFilter (FdoString* value);

    /// \brief
    /// Gets the name of the class to be operated upon as an identifier.
    /// 
    /// \return
    /// Returns the class identifier.
    /// 
    virtual FdoIdentifier* GetFeatureClassName ();

    /// \brief
    /// Sets the name of the class to be operated upon as an identifier.
    /// 
    /// \param value 
    /// Input the class identifier
    /// 
    /// \return
    /// Returns nothing.
    /// 
    virtual void SetFeatureClassName (FdoIdentifier* value);

    /// \brief
    /// Sets the name of the class to be operated upon as an identifier.
    /// 
    /// \param value 
    /// Input the class name
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void SetFeatureClassName (FdoString* value);
};



/// \brief
/// Gets the filter as a filter tree.
/// \return
/// Returns the filter object
template <class FDO_COMMAND, class CONNECTION_CLASS> 
FdoFilter* FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::GetFilter ()
{
    return (FDO_SAFE_ADDREF(mFilter.p));
}

/// \brief
/// Sets the filter as a Filter tree.
/// <param name="value">
/// Input the filter object
/// </param>
/// \return
/// Returns nothing
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::SetFilter (FdoFilter* value)
{
    mFilter = FDO_SAFE_ADDREF(value);
}

/// \brief
/// Sets the filter as a Filter tree.
/// <param name="value">
/// Input the filter expression string
/// </param>
/// \return
/// Returns nothing
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::SetFilter (FdoString* value)
{
    FdoPtr<FdoFilter> filter = FdoFilter::Parse (value);
    mFilter = FDO_SAFE_ADDREF(filter.p);
}


/// \brief
/// Gets the name of the class to be operated upon as an identifier.
/// \return
/// Returns the class identifier.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
FdoIdentifier* FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::GetFeatureClassName ()
{
    /// addref the class name because we own it
    return (FDO_SAFE_ADDREF(mClassName.p));
}


/// \brief
/// Sets the name of the class to be operated upon as an identifier.
/// <param name="value">
/// Input the class identifier
/// </param>
/// \return
/// Returns nothing.
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::SetFeatureClassName (FdoIdentifier* value)
{
    /// Store the given feature class name:
    mClassName = FDO_SAFE_ADDREF(value);  // does automatic release
}


/// \brief
/// Sets the name of the class to be operated upon as an identifier.
/// <param name="value">
/// Input the class name
/// </param>
/// \return
/// Returns nothing
template <class FDO_COMMAND, class CONNECTION_CLASS> 
void FdoCommonFeatureCommand<FDO_COMMAND,CONNECTION_CLASS>::SetFeatureClassName (FdoString* value)
{
    FdoPtr<FdoIdentifier> class_name;

    if (value != NULL)
        class_name = FdoIdentifier::Create (value);
    else
        class_name = NULL;
    SetFeatureClassName (class_name);
}


#endif // FDOCOMMONFEATURECOMMAND_H



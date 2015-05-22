#ifndef _IFEATURECOMMAND_H_
#define _IFEATURECOMMAND_H_
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
#include <Fdo/Commands/ICommand.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Filter/Filter.h>

/// \brief
/// The FdoIFeatureCommand interface defines the behavior common 
/// to all commands that operate on feature instances. The features to 
/// be operated on are identified by their class and a filter. If the feature 
/// provider supports inheritance in the schema capabilities, then the command 
/// will operate on instances of that class and any derived classes. 
/// In addition, feature commands can operate on related features if one or 
/// more relation directives are specified. Each relation directive specifies 
/// the relation to follow and how many levels of depth to follow it.
class FdoIFeatureCommand :  public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the class to be operated upon as an identifier.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual FdoIdentifier* GetFeatureClassName() = 0;

    /// \brief
    /// Sets the name of the class to be operated upon as an identifier.
    /// 
    /// \param value 
    /// Input the class identifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureClassName(FdoIdentifier* value) = 0;

    /// \brief
    /// Sets the name of the class to be operated upon as an identifier.
    /// 
    /// \param value 
    /// Input the class name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFeatureClassName(FdoString* value) = 0;

    /// \brief
    /// Gets the filter as a filter tree.
    /// 
    /// \return
    /// Returns the filter object
    /// 
    FDO_API virtual FdoFilter* GetFilter() = 0;

    /// \brief
    /// Sets the filter as a Filter tree.
    /// 
    /// \param value 
    /// Input the filter object
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFilter(FdoFilter* value) = 0;

    /// \brief
    /// Sets the filter as a Filter tree.
    /// 
    /// \param value 
    /// Input the filter expression string
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetFilter(FdoString* value) = 0;
};
#endif



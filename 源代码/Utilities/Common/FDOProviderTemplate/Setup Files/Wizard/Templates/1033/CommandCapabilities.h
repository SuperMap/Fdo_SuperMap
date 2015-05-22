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

#ifndef [!output UPPER_PREFIX]COMMANDCAPABILITIES_H
#define [!output UPPER_PREFIX]COMMANDCAPABILITIES_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]CommandCapabilities : public FdoICommandCapabilities
{
public:
    [!output PREFIX]CommandCapabilities ();

protected:
    virtual ~[!output PREFIX]CommandCapabilities ();

protected:
    virtual void Dispose();

public:
    /// <summary>Gets an array of the FdoCommandType values supported by the feature provider.</summary>
    /// <param name="size">Output the number of commands</param> 
    /// <returns>Returns the list of commands</returns> 
    virtual FdoInt32* GetCommands (FdoInt32& size);

    /// <summary>Determines if commands support parameterization.</summary>
    /// <returns>Returns true if commands support parameterization</returns> 
    virtual bool SupportsParameters ();

    /// <summary>Determines if the feature provider supports command execution timeout.</summary>
    /// <returns>Returns true if the feature provider supports timeout.</returns> 
    virtual bool SupportsTimeout ();

    /// <summary>Determines if the feature provider can use expressions for properties with Select and SelectAggregate commands.</summary>
    /// <returns>Returns true if the feature provider supports select expressions.</returns> 
    virtual bool SupportsSelectExpressions();

    /// <summary>Determines if simple functions can be used in Select and SelectAggregates command. 
    /// Aggregate functions can only be used in the SelectAggregates command. Capability for using SelectAggregates is found in 
    /// CommandCapabilities.</summary>
    /// <returns>Returns true if the feature provider supports select simple functions.</returns> 
    virtual bool SupportsSelectFunctions();

    /// <summary>Determines if Distinct can be used with SelectAggregates. This can be true only 
    /// if the SelectAggregates command is supported by the provider.</summary>
    /// <returns>Returns true if the feature provider supports select distinct.</returns> 
    virtual bool SupportsSelectDistinct();

    /// <summary>Determines  if ordering is available in the Select and SelectAggregates command.</summary>
    /// <returns>Returns true if the feature provider supports select ordering.</returns> 
    virtual bool SupportsSelectOrdering();

    /// <summary>Determines if a grouping criteria is available in the SelectAggregates command. 
    /// This can be true only if the SelectAggregates command is supported by the provider. Note that aggregate 
    /// functions can be supported without also supporting grouping criteria (but not vice versa).</summary>
    /// <returns>Returns true if the feature provider supports select grouping.</returns> 
    virtual bool SupportsSelectGrouping();
};

#endif // [!output UPPER_PREFIX]COMMANDCAPABILITIES_H


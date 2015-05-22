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

#ifndef [!output UPPER_PREFIX]EXPRESSIONCAPABILITIES_H
#define [!output UPPER_PREFIX]EXPRESSIONCAPABILITIES_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]ExpressionCapabilities : public FdoIExpressionCapabilities
{
public:
    [!output PREFIX]ExpressionCapabilities ();

protected:
    virtual ~[!output PREFIX]ExpressionCapabilities ();

protected:
    virtual void Dispose ();

public:
    /// <summary>Returns an array of FdoExpressionType objects the feature provider supports.</summary>
    /// <param name="length">Input the number of expression types</param> 
    /// <returns>Returns the list of expression types</returns> 
    virtual FdoExpressionType* GetExpressionTypes (FdoInt32& length);

    /// <summary>Returns a collection of FdoFunctionDefinition objects the feature provider supports within expressions.</summary>
    /// <returns>Returns the collection of function definitions</returns> 
    virtual FdoFunctionDefinitionCollection* GetFunctions ();
};

#endif // [!output UPPER_PREFIX]EXPRESSIONCAPABILITIES_H


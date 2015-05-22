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

#ifndef [!output UPPER_PREFIX]FEATUREREADER_H
#define [!output UPPER_PREFIX]FEATUREREADER_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

class [!output PREFIX]FeatureReader :
    public virtual [!output PREFIX]Reader<FdoIFeatureReader>
{
    typedef [!output PREFIX]Reader<FdoIFeatureReader> superclass;

public:
    [!output PREFIX]FeatureReader ();
    virtual ~[!output PREFIX]FeatureReader (void);

    virtual void Dispose();

    // Prevent the use of the Assignment Operation by definning it and not implemeting it.
    // DO NOT IMPLEMENT
    [!output PREFIX]FeatureReader & operator= (const [!output PREFIX]FeatureReader &right);

    /// <summary>Gets the definition of the object currently being read. If the user
    /// has requested only a subset of the class properties, the class 
    /// definition reflects what the user has asked, rather than the full class 
    /// definition.</summary>
    /// <returns>Returns the class definition object.</returns> 
    FdoClassDefinition* GetClassDefinition ();

    /// <summary>Gets a value indicating the depth of nesting for the current reader.
    /// The depth value increases each time GetFeatureObject is called and a new 
    /// reader is returned. The outermost reader has a depth of 0.</summary>
    /// <returns>Returns the depth</returns> 
    FdoInt32 GetDepth ();

    /// <summary>Gets a reference to an FdoIFeatureReader to read the data contained in
    /// the object or object collection property. If the property is not an
    /// object property, an exception is thrown.</summary>
    /// <param name="propertyName">Input the property name.</param> 
    /// <returns>Returns the nested feature reader</returns> 
    FdoIFeatureReader* GetFeatureObject (FdoString* propertyName);
};

#endif // [!output UPPER_PREFIX]FEATUREREADER_H


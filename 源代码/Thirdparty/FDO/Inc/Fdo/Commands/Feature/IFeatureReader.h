#ifndef FDO_XML_IFEATUREREADER_H_
#define FDO_XML_IFEATUREREADER_H_
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
#include <Fdo/Schema/ClassDefinition.h>
#include <Fdo/Raster/IRaster.h>
#include <Fdo/Expression/LOBValue.h>
#include <Fdo/Commands/Feature/IReader.h>

/// \brief
/// The FdoIFeatureReader interface provides a forward-only, read-only iterator
/// for reading feature data.  A reference to an FdoIFeatureReader is returned
/// from the Select and SelectAndLock commands. Because the initial position of the
/// FdoIFeatureReader is prior to the first item, you must call
/// ReadNext to begin accessing any data.
class FdoIFeatureReader: public FdoIReader
{
public:
    /// \brief
    /// Gets the definition of the object currently being read. If the user
    /// has requested only a subset of the class properties, the class 
    /// definition reflects what the user has asked, rather than the full class 
    /// definition.
    /// 
    /// \return
    /// Returns the class definition object.
    /// 
    FDO_API virtual FdoClassDefinition* GetClassDefinition() = 0;

    /// \brief
    /// Gets a value indicating the depth of nesting for the current reader.
    /// The depth value increases each time GetFeatureObject is called and a new 
    /// reader is returned. The outermost reader has a depth of 0.
    /// 
    /// \return
    /// Returns the depth
    /// 
    FDO_API virtual FdoInt32 GetDepth() = 0;

    /// \brief
    /// Gets the geometry value of the specified property as a byte array in 
    /// FGF format. Because no conversion is performed, the property must be
    /// of Geometric type; otherwise, an exception is thrown. 
    /// This method is a language-specific performance optimization that returns a
    /// pointer to the array data, rather than to an object that encapsulates
    /// the array.  The array's memory area is only guaranteed to be valid
    /// until a call to ReadNext() or Close(), or the disposal of this reader
    /// object.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// \param count 
    /// Output the number of bytes in the array.
    /// 
    /// \return
    /// Returns a pointer to the byte array in FGF format.
    /// 
    FDO_API virtual const FdoByte * GetGeometry(FdoString* propertyName, FdoInt32 * count) = 0;

    /// \brief
    /// Gets the geometry value of the specified property as a byte array in 
    /// FGF format. Because no conversion is performed, the property must be
    /// of Geometric type; otherwise, an exception is thrown.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the byte array in FGF format.
    /// 
    FDO_API virtual FdoByteArray* GetGeometry(FdoString* propertyName) = 0;

    /// \brief
    /// Gets a reference to an FdoIFeatureReader to read the data contained in
    /// the object or object collection property. If the property is not an
    /// object property, an exception is thrown.
    /// 
    /// \param propertyName 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the nested feature reader
    /// 
    FDO_API virtual FdoIFeatureReader* GetFeatureObject(FdoString* propertyName) = 0;
};
#endif



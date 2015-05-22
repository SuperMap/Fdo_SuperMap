// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef ICREATESDFFILE_H
#define ICREATESDFFILE_H

#include "FdoStd.h"
#include "Fdo/Commands/ICommand.h"


/// \brief
/// This command creates a new SDF+ file with a specified location
/// and file name and a given spatial coordinate system.
class FdoICreateSDFFile : public FdoICommand
{
public:

    /// \brief
    /// Sets the name of the SDF+ file being created.
    /// The name must be a fully qualified absolute path.
    /// 
    /// \param name 
    /// The fully qualified SDF+ file name.
    FDO_API virtual void SetFileName(FdoString* name) = 0;

    /// \brief
    /// Gets the name of the SDF+ file being created.
    /// The name is a fully qualified absolute path.
    /// 
    /// \return
    /// Returns the name of the SDF+ file.
    /// 
    FDO_API virtual FdoString* GetFileName() = 0;

    /// \brief
    /// Sets the name of the spatial context as a string.
    /// 
    /// \param name 
    /// Input the name of the spatial context.
    FDO_API virtual void SetSpatialContextName(FdoString* name) = 0;

    /// \brief
    /// Gets the name of the coordinate system of the spatial context.
    /// If the result is a null or empty string, the coordinate system is
    /// unknown to the spatial context.
    /// 
    /// \return
    /// Returns the coordinate system name of the spatial context.
    /// 
    FDO_API virtual FdoString* GetSpatialContextName() = 0;

    /// \brief
    /// Sets the description of the spatial context as a string.
    /// 
    /// \param description 
    /// Input the description of the spatial context.
    FDO_API virtual void SetSpatialContextDescription(FdoString* description) = 0;

    /// \brief
    /// Gets the description of the spatial context.
    /// 
    /// \return
    /// Returns the description of the spatial context.
    /// 
    FDO_API virtual FdoString* GetSpatialContextDescription() = 0;

    /// \brief
    /// Sets the coordinate system of the context to create as a string in
    /// OpenGIS SRS WKT format.
    /// 
    /// \param wkt 
    /// Input the coordinate system.
    FDO_API virtual void SetCoordinateSystemWKT(FdoString* wkt) = 0;

    /// \brief
    /// Gets the name of the coordinate system in OpenGIS SRS WKT format of the spatial context.
    /// If the result is an empty string, the coordinate system WKT description is
    /// not available.
    /// 
    /// \return
    /// Returns the coordinate system description in WKT format of the spatial context.
    /// 
    FDO_API virtual FdoString* GetCoordinateSystemWKT() = 0;

    /// \brief
    /// Sets the tolerance value to use for X/Y ordinates. Tolerances are used
    /// in some geometric tests, mostly for equality between coordinates. This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions. It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \param tolerance 
    /// Input the tolerance.
    FDO_API virtual void SetXYTolerance(double tolerance) = 0;

    /// \brief
    /// Gets the tolerance value for X/Y ordinates of the spatial context.
	 ///
	 /// \remarks
    /// Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates. This occurs frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance.
    /// 
    FDO_API virtual double GetXYTolerance() = 0;
    
    /// \brief
    /// Sets the tolerance value to use for Z ordinates.
	 ///
	 /// \remarks
	 /// Tolerances are used in
    /// some geometric tests, mostly for equality between coordinates. This
    /// occurs frequently in spatial queries, especially with "on boundary" or "just
    /// touching" conditions. It is also an objective amount that can be used
    /// when formulating step distances for parametric curve interpolation.
    /// 
    /// \param tolerance 
    /// Input the tolerance.
    FDO_API virtual void SetZTolerance(double tolerance) = 0;

    /// \brief
    /// Gets the tolerance value for Z ordinates of the spatial context.
	 ///
	 /// \remarks
    /// Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates. This occurs a frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.
    /// 
    /// \return
    /// Returns the tolerance.
    /// 
    FDO_API virtual double GetZTolerance() = 0;

    /// \brief
    /// Executes the command. An exception is thrown if the file fails to be 
    /// created.
    FDO_API virtual void Execute() = 0;

};


#endif



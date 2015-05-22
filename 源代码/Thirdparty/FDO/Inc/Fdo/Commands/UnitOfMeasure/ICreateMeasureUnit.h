#ifndef _ICREATEMEASUREUNIT_H_
#define _ICREATEMEASUREUNIT_H_
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
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/UnitOfMeasure/BaseUnit.h>
#include <Fdo/Commands/ICommand.h>

/// \brief
/// The FdoICreateMeasureUnit interface defines the CreateMeasureUnit command,
/// which creates or updates a measurement unit. Input to the command includes
/// the abbreviation, name, description, measure type, base unit, and scale
/// factor that defines the measure unit. The update existing flag indicates how
/// the command should behave in the presence of an existing measure unit. If it is 
/// false, and the specified measure unit already exists, command execution will
/// fail. If it is true, the command will either create a new measure unit or update an
/// existing one.
class FdoICreateMeasureUnit : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the abbreviation of the measure unit to create or update as a
    /// string. Abbreviations must be unique because they define the identity of a
    /// measurement unit.
    /// 
    /// \return
    /// Returns the abbreviation for the measure unit
    /// 
    FDO_API virtual FdoString* GetAbbreviation() = 0;

    /// \brief
    /// Sets the abbreviation of the measure unit to create or update as a
    /// string. Abbreviations must be unique because they define the identity of a
    /// measurement unit.
    /// 
    /// \param value 
    /// Input the abbreviation for the measure unit
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetAbbreviation(FdoString* value) = 0;

    /// \brief
    /// Gets the name of the measure unit to create or update as a string.
    /// 
    /// \return
    /// Returns the name for the measure unit
    /// 
    FDO_API virtual FdoString* GetName() = 0;

    /// \brief
    /// Sets the name of the measure unit to create or update as a string.
    /// 
    /// \param value 
    /// Input the name for the measure unit
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetName(FdoString* value) = 0;

    /// \brief
    /// Gets the description of the measure unit to create or update as a string.
    /// 
    /// \return
    /// Returns the description for the measure unit
    /// 
    FDO_API virtual FdoString* GetDescription() = 0;

    /// \brief
    /// Sets the description of the measure unit to create or update as a string.
    /// 
    /// \param value 
    /// Input the description for the measure unit
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetDescription(FdoString* value) = 0;

    /// \brief
    /// Gets the base units that define the measure unit to create or update
    /// as an FdoBaseUnit value.
    /// 
    /// \return
    /// Returns the base units
    /// 
    FDO_API virtual FdoBaseUnit GetBaseUnit() = 0;

    /// \brief
    /// Sets the base units that define the measure unit to create or update
    /// as an FdoBaseUnit value.
    /// 
    /// \param value 
    /// Input the base units
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetBaseUnit(FdoBaseUnit value) = 0;

    /// \brief
    /// Gets the scale factor to be applied to the base unit in order to get
    /// one of the units being defined.
    /// 
    /// \return
    /// Returns the scale factor
    /// 
    FDO_API virtual double GetScaleFactor() = 0;

    /// \brief
    /// Sets the scale factor to be applied to the base unit in order to get
    /// one of the units being defined.
    /// 
    /// \param value 
    /// Input the scale factor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetScaleFactor(double value) = 0;

    /// \brief
    /// Gets a Boolean flag that indicates how the CreateMeasureUnit command
    /// should behave if the measure unit already exists. If update existing is
    /// true and a measure unit with the specified abbreviation already exists
    /// then it will be updated. If update existing is false and a measure unit
    /// with the specified abbreviation already exists, command execution
    /// will fail.
    /// 
    /// \return
    /// Returns true if the existing measure unit can be updated
    /// 
    FDO_API virtual bool GetUpdateExisting() = 0;

    /// \brief
    /// Sets a Boolean flag that indicates how the CreateMeasureUnit command
    /// should behave if the measure unit already exists. If update existing
    /// is true and a measure unit of the specified name already exists,
    /// it will be updated. If update existing is false and a measure unit of
    /// the specified name already exists, command execution will fail.
    /// 
    /// \param value 
    /// Input Indicates if the existing measure unit can be updated
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetUpdateExisting(bool value) = 0;

    /// \brief
    /// Executes the CreateMeasureUnit command. If the measure unit already
    /// exists and the update existing flag is set to false, an exception is thrown.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif



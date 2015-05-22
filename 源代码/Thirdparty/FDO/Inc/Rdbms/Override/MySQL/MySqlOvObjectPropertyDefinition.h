#ifndef FDO_MySQLOVOBJECTPROPERTYDEFINITION_H
#define FDO_MySQLOVOBJECTPROPERTYDEFINITION_H
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
#include <Fdo/Commands/Schema/PhysicalElementMapping.h>
#include <Rdbms/Override/RdbmsOvObjectPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingClass.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingConcrete.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingSingle.h>

/// \brief
/// Concrete class defining physical schema overrides for an object property definition.
class FdoMySQLOvObjectPropertyDefinition : public FdoRdbmsOvObjectPropertyDefinition, public FdoMySQLOvPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvObjectPropertyDefinition
    /// 
    /// \return
    /// Returns FdoMySQLOvObjectPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvObjectPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvObjectPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvObjectPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvObjectPropertyDefinition* Create(FdoString* name);

    /// \brief
    /// Gets the mapping definition
    /// 
    /// \return
    /// Returns the mapping definition
    /// 
    FDOMYSQL_OV_API FdoMySQLOvPropertyMappingDefinition* GetMappingDefinition();

    /// \brief
    /// Sets the mapping definition
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetMappingDefinition(FdoMySQLOvPropertyMappingDefinition* propertyMappingDefinition);

protected:
    FdoMySQLOvObjectPropertyDefinition();
    FdoMySQLOvObjectPropertyDefinition(FdoString* name);
    virtual ~FdoMySQLOvObjectPropertyDefinition();
    virtual void Dispose();

    /// Create and optionally attach a Single table property mapping.
    virtual FdoRdbmsOvPropertyMappingSingle* CreateSingleMapping(
        bool attach
    );

    /// Create and optionally attach a Class table property mapping.
    virtual FdoRdbmsOvPropertyMappingClass* CreateClassMapping(
        bool attach
    );

    /// Create and optionally attach a Concrete table property mapping.
    virtual FdoRdbmsOvPropertyMappingConcrete* CreateConcreteMapping(
        bool attach
    );

private:
};


/// \brief
/// FdoMySQLOvObjectPropertyP is a FdoPtr on FdoMySQLOvObjectPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoMySQLOvObjectPropertyDefinition> FdoMySQLOvObjectPropertyP;

#endif



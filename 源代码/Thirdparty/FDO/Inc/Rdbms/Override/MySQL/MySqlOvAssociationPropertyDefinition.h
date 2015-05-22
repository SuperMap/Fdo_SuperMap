#ifndef FDO_MySQLOVASSOCIATIONPROPERTYDEFINITION_H
#define FDO_MySQLOVASSOCIATIONPROPERTYDEFINITION_H
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
#include <FdoCommon.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinitionCollection.h>
#include <Rdbms/Override/RdbmsOvAssociationPropertyDefinition.h>


/// \brief
/// Concrete class defining physical schema overrides for an association property
/// definition.
class FdoMySQLOvAssociationPropertyDefinition : public FdoMySQLOvPropertyDefinition, public FdoRdbmsOvAssociationPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvAssociationPropertyDefinition
    /// 
    /// \return
    /// Returns FdoMySQLOvAssociationPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvAssociationPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvAssociationPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvAssociationPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvAssociationPropertyDefinition* Create(FdoString* name);

    /// \brief
    /// Gets a collection of property definitions
    /// 
    /// \return
    /// Returns a collection of property definitions
    /// 
    FDOMYSQL_OV_API FdoMySQLOvPropertyDefinitionCollection *GetIdentityProperties();

protected:
    FdoMySQLOvAssociationPropertyDefinition();
    FdoMySQLOvAssociationPropertyDefinition(FdoString* name);
    virtual ~FdoMySQLOvAssociationPropertyDefinition();
    virtual void Dispose();

private:
    void Init();
    FdoMySQLOvPropertiesP mPropertyDefinitions;
};

#endif



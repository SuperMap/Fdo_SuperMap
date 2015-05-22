#ifndef FDO_MySQLOVPROPERTYDEFINITIONCOLLECTION_H
#define FDO_MySQLOVPROPERTYDEFINITIONCOLLECTION_H
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
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinitionCollection.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>

/// \brief
/// Concrete class defining physical schema overrides for a collection of property
/// definitions.
class FdoMySQLOvPropertyDefinitionCollection : public FdoRestrictedNamedCollection<FdoRdbmsOvPropertyDefinition,FdoMySQLOvPropertyDefinition,FdoRdbmsOvPropertyDefinitionCollection>
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvPropertyDefinitionCollection
    /// 
    /// \return
    /// Returns FdoMySQLOvPropertyDefinitionCollection
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPropertyDefinitionCollection* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvPropertyDefinitionCollection using the specified arguments
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoMySQLOvPropertyDefinitionCollection
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPropertyDefinitionCollection* Create(FdoRdbmsOvPropertyDefinitionCollection* baseCollection );

protected:
    FdoMySQLOvPropertyDefinitionCollection();
    FdoMySQLOvPropertyDefinitionCollection(FdoRdbmsOvPropertyDefinitionCollection* baseCollection);
    virtual ~FdoMySQLOvPropertyDefinitionCollection();
    virtual void Dispose();

    virtual FdoMySQLOvPropertyDefinition* DownCast( FdoRdbmsOvPropertyDefinition* value ) const;
};

/// \brief
/// FdoMySQLOvPropertiesP is a FdoPtr on FdoMySQLOvPropertyDefinitionCollection, provided for convenience.
typedef FdoPtr<FdoMySQLOvPropertyDefinitionCollection> FdoMySQLOvPropertiesP;


#endif



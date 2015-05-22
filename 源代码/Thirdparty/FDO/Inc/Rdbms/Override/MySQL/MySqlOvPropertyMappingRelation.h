#ifndef FDO_MySQLOVPROPERTYMAPPINGRELATION_H
#define FDO_MySQLOVPROPERTYMAPPINGRELATION_H
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
#include <Rdbms/Override/RdbmsOvPropertyMappingConcrete.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingDefinition.h>

class FdoMySQLOvClassDefinition;

/// \brief
/// Abstract class defining the physical schema overrides for relation type object property
/// table mappings.
class FdoMySQLOvPropertyMappingRelation : public FdoMySQLOvPropertyMappingDefinition, public virtual FdoRdbmsOvPropertyMappingRelation
{

public:

    /// \brief
    /// Gets the internal class
    /// 
    /// \return
    /// Returns the internal class
    /// 
    FDOMYSQL_OV_API FdoMySQLOvClassDefinition* GetInternalClass();

    /// \brief
    /// Sets the internal class
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetInternalClass(FdoMySQLOvClassDefinition* classDefinition);

protected:
    FdoMySQLOvPropertyMappingRelation();
    virtual ~FdoMySQLOvPropertyMappingRelation();

    /// Creates and optionally attaches an internal class override object.
    virtual FdoRdbmsOvClassDefinition* CreateInternalClass(
        bool attach
    );
};

/// \brief
/// FdoMySQLOvPropertyMappingRelationP is a FdoPtr on FdoMySQLOvPropertyMappingRelation, provided for convenience.
typedef FdoPtr<FdoMySQLOvPropertyMappingRelation> FdoMySQLOvPropertyMappingRelationP;

#endif



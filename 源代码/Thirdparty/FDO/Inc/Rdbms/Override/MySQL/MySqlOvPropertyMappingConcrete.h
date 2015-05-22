#ifndef FDO_MySQLOVPROPERTYMAPPINGRCONCRETE_H
#define FDO_MySQLOVPROPERTYMAPPINGRCONCRETE_H
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
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingRelation.h>

/// \brief
/// Concrete class defining the physical schema overrides for the Concrete type object
/// property mapping. Under the Concrete mapping type, each object property is kept in its own
/// table.
class FdoMySQLOvPropertyMappingConcrete : public FdoMySQLOvPropertyMappingRelation, public FdoRdbmsOvPropertyMappingConcrete
{

public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvPropertyMappingConcrete
    /// 
    /// \return
    /// Returns FdoMySQLOvPropertyMappingConcrete
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPropertyMappingConcrete* Create();

protected:
    FdoMySQLOvPropertyMappingConcrete();
    virtual ~FdoMySQLOvPropertyMappingConcrete();
    virtual void Dispose();

private:
};

/// \brief
/// FdoMySQLOvPropertyMappingConcreteP is a FdoPtr on FdoMySQLOvPropertyMappingConcrete, provided for convenience.
typedef FdoPtr<FdoMySQLOvPropertyMappingConcrete> FdoMySQLOvPropertyMappingConcreteP;

#endif



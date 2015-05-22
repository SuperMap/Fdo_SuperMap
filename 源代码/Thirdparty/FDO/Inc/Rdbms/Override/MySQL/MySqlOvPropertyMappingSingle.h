#ifndef FDO_MySQLOVPROPERTYMAPPINGSINGLE_H
#define FDO_MySQLOVPROPERTYMAPPINGSINGLE_H
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
#include <Rdbms/Override/RdbmsOvPropertyMappingSingle.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyMappingDefinition.h>



/// \brief
/// Concrete class defining the physical schema overrides for the Single type object
/// property mapping. Under the Single mapping type, the object property is kept in the same
/// table as its containing class.
class FdoMySQLOvPropertyMappingSingle : public FdoMySQLOvPropertyMappingDefinition, public FdoRdbmsOvPropertyMappingSingle
{
public:

    /// \brief
    /// Constructs a default of an FdoMySQLOvPropertyMappingSingle
    /// 
    /// \return
    /// Returns FdoMySQLOvPropertyMappingSingle
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPropertyMappingSingle* Create();

protected:
    FdoMySQLOvPropertyMappingSingle();
    virtual ~FdoMySQLOvPropertyMappingSingle();
    virtual void Dispose();
};

/// \brief
/// FdoMySQLOvPropertyMappingSingleP is a FdoPtr on FdoMySQLOvPropertyMappingSingle, provided for convenience.
typedef FdoPtr<FdoMySQLOvPropertyMappingSingle> FdoMySQLOvPropertyMappingSingleP;

#endif



#ifndef FDO_MySQLOVPROPERTYMAPPINGCLASS_H
#define FDO_MySQLOVPROPERTYMAPPINGCLASS_H
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
#include <Rdbms/Override/RdbmsOvPropertyMappingClass.h>

/// \cond DOXYGEN-IGNORE

/// \brief
/// Concrete class defining the physical schema overrides for the Class
/// type object property mapping.
class FdoMySQLOvPropertyMappingClass : public FdoMySQLOvPropertyMappingRelation, public FdoRdbmsOvPropertyMappingClass
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvPropertyMappingClass
    /// 
    /// \return
    /// Returns FdoMySQLOvPropertyMappingClass
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPropertyMappingClass* Create();

protected:
    FdoMySQLOvPropertyMappingClass();
    virtual ~FdoMySQLOvPropertyMappingClass();
    virtual void Dispose();
};

/// \brief
/// FdoMySQLOvPropertyMappingClassP is a FdoPtr on FdoMySQLOvPropertyMappingClass, provided for convenience.
typedef FdoPtr<FdoMySQLOvPropertyMappingClass> FdoMySQLOvPropertyMappingClassP;

/// \endcond

#endif



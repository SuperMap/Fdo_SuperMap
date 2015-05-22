#ifndef FDO_MySQLOVGEOMETRICPROPERTYDEFINITION_H
#define FDO_MySQLOVGEOMETRICPROPERTYDEFINITION_H
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
#include <Rdbms/Override/RdbmsOvGeometricPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvGeometricColumn.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinition.h>

/// \brief
/// Concrete class defining physical schema overrides for a geometric property definition.
class FdoMySQLOvGeometricPropertyDefinition : public FdoRdbmsOvGeometricPropertyDefinition, public FdoMySQLOvPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvGeometricPropertyDefinition
    /// 
    /// \return
    /// Returns FdoMySQLOvGeometricPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvGeometricPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvGeometricPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvGeometricPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvGeometricPropertyDefinition* Create(FdoString* name);

    /// \brief
    /// Gets the column
    /// 
    /// \return
    /// Returns the column
    /// 
    FDOMYSQL_OV_API FdoMySQLOvGeometricColumn* GetColumn();

    /// \brief
    /// Sets the column
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetColumn(FdoMySQLOvGeometricColumn* geometricColumn);


protected:
/// \cond DOXYGEN-IGNORE

    FdoMySQLOvGeometricPropertyDefinition();
    FdoMySQLOvGeometricPropertyDefinition(FdoString* name);
    virtual ~FdoMySQLOvGeometricPropertyDefinition();
    virtual void Dispose();
/// \endcond

private:
};

/// \brief
/// FdoMySQLOvGeometricPropertyP is a FdoPtr on FdoMySQLOvGeometricPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoMySQLOvGeometricPropertyDefinition> FdoMySQLOvGeometricPropertyP;

#endif



#ifndef FDO_MySQLOVDATAPROPERTYDEFINITION_H
#define FDO_MySQLOVDATAPROPERTYDEFINITION_H

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
#include <Rdbms/Override/RdbmsOvDataPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvColumn.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinition.h>

/// \brief
/// Concrete class defining physical schema overrides for a data property definition.
class FdoMySQLOvDataPropertyDefinition : public FdoRdbmsOvDataPropertyDefinition, public FdoMySQLOvPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvDataPropertyDefinition
    /// 
    /// \return
    /// Returns FdoMySQLOvDataPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvDataPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvDataPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvDataPropertyDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvDataPropertyDefinition* Create(FdoString* name);

    /// \brief
    /// Gets the MySQL column
    /// 
    /// \return
    /// Returns the MySQL column
    /// 
    FDOMYSQL_OV_API FdoMySQLOvColumn* GetColumn();

    /// \brief
    /// Sets the MySQL column
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetColumn(FdoMySQLOvColumn *column);

/* //TODO: enable this code when FdoMySQLOvValidPropertyValueConstraint is ready

    /// \brief
    /// Get the single ValidPropertyValueConstraint
    /// 
    /// \return
    /// Returns the single ValidPropertyValueConstraint
    /// 
    FDOMYSQL_OV_API FdoMySQLOvValidPropertyValueConstraint* GetValidPropertyValueConstraint();

    /// \brief
    /// Set the single ValidPropertyValueConstraint
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetValidPropertyValueConstraint(FdoMySQLOvValidPropertyValueConstraint* validPropertyValueConstraint);
*/

/// \cond DOXYGEN-IGNORE

/// \endcond

protected:
    FdoMySQLOvDataPropertyDefinition();
    FdoMySQLOvDataPropertyDefinition(FdoString* name);
    virtual ~FdoMySQLOvDataPropertyDefinition();
    virtual void Dispose();

private:
};


/// \brief
/// FdoMySQLOvDataPropertyP is a FdoPtr on FdoMySQLOvDataPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoMySQLOvDataPropertyDefinition> FdoMySQLOvDataPropertyP;

#endif



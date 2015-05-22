#ifndef FDO_OdbcOVDATAPROPERTYDEFINITION_H
#define FDO_OdbcOVDATAPROPERTYDEFINITION_H

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
#include <Rdbms/Override/ODBC/OdbcOv.h>
#include <Rdbms/Override/ODBC/OdbcOvColumn.h>
#include <Rdbms/Override/ODBC/OdbcOvPropertyDefinition.h>

/// \brief
/// Concrete class defining physical schema overrides for a data property definition.
class FdoOdbcOvDataPropertyDefinition : public FdoRdbmsOvDataPropertyDefinition, public FdoOdbcOvPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvDataPropertyDefinition
    /// 
    /// \return
    /// Returns FdoOdbcOvDataPropertyDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvDataPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvDataPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvDataPropertyDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvDataPropertyDefinition* Create(FdoString* name);

    /// \brief
    /// Gets the Odbc column
    /// 
    /// \return
    /// Returns the Odbc column
    /// 
    FDOODBC_OV_API FdoOdbcOvColumn* GetColumn();

    /// \brief
    /// Sets the Odbc column
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOODBC_OV_API void SetColumn(FdoOdbcOvColumn *column);

/// \cond DOXYGEN-IGNORE

/// \endcond

protected:
    FdoOdbcOvDataPropertyDefinition();
    FdoOdbcOvDataPropertyDefinition(FdoString* name);
    virtual ~FdoOdbcOvDataPropertyDefinition();
    virtual void Dispose();

private:
};


/// \brief
/// FdoOdbcOvDataPropertyP is a FdoPtr on FdoOdbcOvDataPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoOdbcOvDataPropertyDefinition> FdoOdbcOvDataPropertyP;

#endif



#ifndef FDO_OdbcOVGEOMETRICPROPERTYDEFINITION_H
#define FDO_OdbcOVGEOMETRICPROPERTYDEFINITION_H
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
#include <Rdbms/Override/ODBC/OdbcOv.h>
#include <Rdbms/Override/ODBC/OdbcOvPropertyDefinition.h>

/// \brief
/// Concrete class defining physical schema overrides for a geometric property definition.
class FdoOdbcOvGeometricPropertyDefinition : public FdoRdbmsOvGeometricPropertyDefinition, public FdoOdbcOvPropertyDefinition
{
public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvGeometricPropertyDefinition
    /// 
    /// \return
    /// Returns FdoOdbcOvGeometricPropertyDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvGeometricPropertyDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvGeometricPropertyDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvGeometricPropertyDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvGeometricPropertyDefinition* Create(FdoString* name);

protected:
/// \cond DOXYGEN-IGNORE

    FdoOdbcOvGeometricPropertyDefinition();
    FdoOdbcOvGeometricPropertyDefinition(FdoString* name);
    virtual ~FdoOdbcOvGeometricPropertyDefinition();
    virtual void Dispose();
/// \endcond

private:
};

/// \brief
/// FdoOdbcOvGeometricPropertyP is a FdoPtr on FdoOdbcOvGeometricPropertyDefinition, provided for convenience.
typedef FdoPtr<FdoOdbcOvGeometricPropertyDefinition> FdoOdbcOvGeometricPropertyP;

#endif



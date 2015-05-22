#ifndef FDO_MySQLOVGEOMETRICCOLUMN_H
#define FDO_MySQLOVGEOMETRICCOLUMN_H
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
#include <Rdbms/Override/RdbmsOvGeometricColumn.h>


/// \brief
/// Concrete class defining physical schema overrides for a geometric column.
class FdoMySQLOvGeometricColumn : public FdoRdbmsOvGeometricColumn
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvGeometricColumn
    /// 
    /// \return
    /// Returns FdoMySQLOvGeometricColumn
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvGeometricColumn* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvGeometricColumn using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvGeometricColumn
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvGeometricColumn* Create(FdoString* name);


/// \cond DOXYGEN-IGNORE

    /// XML serialization functions, not part of the API.

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize provider-specific parts of this override to XML
    virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);
/// \endcond

protected:
    FdoMySQLOvGeometricColumn();
    FdoMySQLOvGeometricColumn(FdoString* name);
    virtual ~FdoMySQLOvGeometricColumn();
    virtual void Dispose();
};

/// \brief
/// FdoMySQLOvGeometricColumnP is a FdoPtr on FdoMySQLOvGeometricColumn, provided for convenience.
typedef FdoPtr<FdoMySQLOvGeometricColumn> FdoMySQLOvGeometricColumnP;

#endif



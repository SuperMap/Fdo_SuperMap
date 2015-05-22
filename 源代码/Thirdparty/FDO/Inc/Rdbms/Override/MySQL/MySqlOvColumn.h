#ifndef FDO_MySQLOvColumn_H
#define FDO_MySQLOvColumn_H

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
#include <Rdbms/Override/RdbmsOvColumn.h>

/// \brief
/// Concrete class defining physical schema overrides for a column.
class FdoMySQLOvColumn : public FdoRdbmsOvColumn
{

public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvColumn
    /// 
    /// \return
    /// Returns FdoMySQLOvColumn
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvColumn* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvColumn using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvColumn
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvColumn* Create(FdoString* name);

/// \cond DOXYGEN-IGNORE

    /// XML serialization functions, not part of the API.

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

/// \endcond

protected:
    FdoMySQLOvColumn();
    FdoMySQLOvColumn(FdoString* name);
    virtual ~FdoMySQLOvColumn();
    virtual void Dispose();

    /// Serialize this property to XML.
    virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
};

/// \brief
/// FdoMySQLOvColumnP is a FdoPtr on FdoMySQLOvColumn, provided for convenience.
typedef FdoPtr<FdoMySQLOvColumn> FdoMySQLOvColumnP;

#endif



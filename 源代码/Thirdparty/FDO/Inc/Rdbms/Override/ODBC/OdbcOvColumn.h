#ifndef FDO_OdbcOvColumn_H
#define FDO_OdbcOvColumn_H

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
#include <Rdbms/Override/ODBC/OdbcOv.h>
#include <Rdbms/Override/RdbmsOvColumn.h>

/// \brief
/// Concrete class defining physical schema overrides for a column.
class FdoOdbcOvColumn : public FdoRdbmsOvColumn
{

public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvColumn
    /// 
    /// \return
    /// Returns FdoOdbcOvColumn
    /// 
    FDOODBC_OV_API static FdoOdbcOvColumn* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvColumn using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvColumn
    /// 
    FDOODBC_OV_API static FdoOdbcOvColumn* Create(FdoString* name);


/// \cond DOXYGEN-IGNORE

    /// XML serialization functions, not part of the API.

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

/// \endcond

protected:
    FdoOdbcOvColumn();
    FdoOdbcOvColumn(FdoString* name);
    virtual ~FdoOdbcOvColumn();
    virtual void Dispose();

    /// Serialize this property to XML.
    virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
};

/// \brief
/// FdoOdbcOvColumnP is a FdoPtr on FdoOdbcOvColumn, provided for convenience.
typedef FdoPtr<FdoOdbcOvColumn> FdoOdbcOvColumnP;

#endif



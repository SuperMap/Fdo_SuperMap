#ifndef FDO_OdbcOVTABLE_H
#define FDO_OdbcOVTABLE_H
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
#include <Rdbms/Override/RdbmsOvTable.h>
#include <Rdbms/Override/ODBC/OdbcOv.h>


/// \brief
/// Concrete class defining physical schema overrides for a table.
class FdoOdbcOvTable : public FdoRdbmsOvTable
{

public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvTable
    /// 
    /// \return
    /// Returns FdoOdbcOvTable
    /// 
    FDOODBC_OV_API static FdoOdbcOvTable* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvTable using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvTable
    /// 
    FDOODBC_OV_API static FdoOdbcOvTable* Create(FdoString *name);


/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of the API.

    /// Serialize this property to XML.
    virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Sets the parent of this object. Not part of the API.
    void SetParent(FdoPhysicalElementMapping* value);

    /// Common initializer for all constructors:
    void Init();

/// \endcond

protected:
    FdoOdbcOvTable();
    FdoOdbcOvTable(FdoString *name);
    virtual ~FdoOdbcOvTable();
    virtual void Dispose();

private:
};

/// \brief
/// FdoOdbcOvTableP is a FdoPtr on FdoOdbcOvTable, provided for convenience.
typedef FdoPtr<FdoOdbcOvTable> FdoOdbcOvTableP;

#endif



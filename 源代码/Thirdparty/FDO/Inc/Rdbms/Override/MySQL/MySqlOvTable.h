#ifndef FDO_MySQLOVTABLE_H
#define FDO_MySQLOVTABLE_H
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
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvStorageEngineType.h>


/// \brief
/// Concrete class defining physical schema overrides for a table.
class FdoMySQLOvTable : public FdoRdbmsOvTable
{

public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvTable
    /// 
    /// \return
    /// Returns FdoMySQLOvTable
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvTable* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvTable using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvTable
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvTable* Create(FdoString *name);

    /// \brief
    /// Gets the directory where table data is stored
    /// 
    /// \return
    /// Returns the directory where table data is stored
    /// 
    FDOMYSQL_OV_API FdoString *GetDataDirectory();

    /// \brief
    /// Sets the directory where table data is stored
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetDataDirectory(FdoString *dataDirectory);

    /// \brief
    /// Gets the directory where indexes are stored
    /// 
    /// \return
    /// Returns the directory where indexes are stored
    /// 
    FDOMYSQL_OV_API FdoString *GetIndexDirectory();

    /// \brief
    /// Sets the directory where indexes are stored
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetIndexDirectory(FdoString *indexDirectory);

    /// \brief
    /// Gets the storage engine type
    /// 
    /// \return
    /// Returns the storage engine type
    /// 
    FDOMYSQL_OV_API MySQLOvStorageEngineType GetStorageEngine();

    /// \brief
    /// Sets the storage engine type
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetStorageEngine(MySQLOvStorageEngineType storageEngine);

    /// \brief
    /// Gets the database
    /// 
    /// \return
    /// Returns the database
    /// 
    FDOMYSQL_OV_API FdoString *GetDatabase();

    /// \brief
    /// Sets the database
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetDatabase(FdoString *database);


/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of the API.

    /// Serialize this property to XML.
    virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Sets the parent of this object. Not part of the API.
    void SetParent(FdoPhysicalElementMapping* value);

/// \endcond

protected:
    FdoMySQLOvTable();
    FdoMySQLOvTable(FdoString *name);
    virtual ~FdoMySQLOvTable();
    virtual void Dispose();

    /// Common initializer for all constructors:
    void Init();

private:
    FdoStringP                  mDataDirectory;
    FdoStringP                  mIndexDirectory;
    MySQLOvStorageEngineType    mStorageEngine;
    FdoStringP                  mDatabase;
};

/// \brief
/// FdoMySQLOvTableP is a FdoPtr on FdoMySQLOvTable, provided for convenience.
typedef FdoPtr<FdoMySQLOvTable> FdoMySQLOvTableP;

#endif



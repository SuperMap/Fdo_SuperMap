#ifndef FDO_MySQLOVPHYSICALSCHEMAMAPPING_H
#define FDO_MySQLOVPHYSICALSCHEMAMAPPING_H
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
#include <Rdbms/Override/RdbmsOvPhysicalSchemaMapping.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvClassCollection.h>
#include <Rdbms/Override/MySQL/MySqlOvStorageEngineType.h>

/// \brief
/// Concrete class offering schema overrides for
/// the MySQL Provider.
class FdoMySQLOvPhysicalSchemaMapping : public FdoRdbmsOvPhysicalSchemaMapping
{

public:

    /// \brief
    /// Constructs a default of an FdoMySQLOvPhysicalSchemaMapping
    /// 
    /// \return
    /// Returns FdoMySQLOvPhysicalSchemaMapping
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPhysicalSchemaMapping* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvPhysicalSchemaMapping using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvPhysicalSchemaMapping
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvPhysicalSchemaMapping* Create(FdoString* name);

    /// \brief
    /// Gets the classes
    /// 
    /// \return
    /// Returns the classes
    /// 
    FDOMYSQL_OV_API FdoMySQLOvClassCollection* GetClasses();

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

    /// \brief
    /// Gets the provider name
    /// 
    /// \return
    /// Returns the provider name
    /// 
    FDOMYSQL_OV_API virtual FdoString *GetProvider(void);

/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of API.

    /// Serialize this property to XML.
    virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

/// \endcond

protected:
    FdoMySQLOvPhysicalSchemaMapping();
    FdoMySQLOvPhysicalSchemaMapping(FdoString* name);
    virtual ~FdoMySQLOvPhysicalSchemaMapping();
    virtual void Dispose();

    /// Create a class override from XML attributes
    virtual FdoRdbmsOvClassDefinition* CreateClass( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* atts
    );

    /// Add the given class override to this schema override set
    virtual void AddClass( 
        FdoRdbmsOvClassDefinition* pClass
    );

    /// common initializer for all constructors:
    void Init();

private:
    FdoMySQLOvClassesP          mClasses;
    FdoStringP                  mDataDirectory;
    FdoStringP                  mIndexDirectory;
    MySQLOvStorageEngineType    mStorageEngine;
    FdoStringP                  mDatabase;
};

/// \brief
/// FdoMySQLOvSchemaMappingP is a FdoPtr on FdoMySQLOvPhysicalSchemaMapping, provided for convenience.
typedef FdoPtr<FdoMySQLOvPhysicalSchemaMapping> FdoMySQLOvSchemaMappingP;

#endif



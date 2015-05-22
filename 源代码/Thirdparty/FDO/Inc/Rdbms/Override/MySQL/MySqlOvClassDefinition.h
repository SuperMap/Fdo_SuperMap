#ifndef FDO_MySQLOVCLASSDEFINITION_H
#define FDO_MySQLOVCLASSDEFINITION_H
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
#include <Rdbms/Override/RdbmsOvClassDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOv.h>
#include <Rdbms/Override/MySQL/MySqlOvDataPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOvGeometricPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOvObjectPropertyDefinition.h>
#include <Rdbms/Override/MySQL/MySqlOvPropertyDefinitionCollection.h>
#include <Rdbms/Override/MySQL/MySqlOvTable.h>
#include <Rdbms/Override/MySQL/MySqlOvGeometricColumn.h>

/// \brief
/// Concrete class defining physical schema overrides for a class definition.
class FdoMySQLOvClassDefinition : public FdoRdbmsOvClassDefinition
{

public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvClassDefinition
    /// 
    /// \return
    /// Returns FdoMySQLOvClassDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvClassDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvClassDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoMySQLOvClassDefinition
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvClassDefinition* Create(FdoString* name);

    /// \brief
    /// Gets a collection of MySQL property overrides
    /// 
    /// \return
    /// Returns the collection of MySQL property overrides
    /// 
    FDOMYSQL_OV_API FdoMySQLOvPropertyDefinitionCollection* GetProperties();

    /// \brief
    /// Gets the MySQL table override for this class override
    /// 
    /// \return
    /// Returns FdoMySQLOvTable
    /// 
    FDOMYSQL_OV_API FdoMySQLOvTable* GetTable();

    /// \brief
    /// Sets the MySQL table override for this class override
    /// 
    /// \param name 
    /// Input MySQL table override
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetTable(FdoMySQLOvTable* table);

    /// \brief
    /// Which FDO property maps to an MySQL auto-increment column, if any.
    /// 
    /// \remarks
    /// An empty string indicates
    /// there is no such column on this class’s table.  There can only be at most one auto-increment column
    /// per table, it must be indexed, and it cannot have a default value.  As of MySQL 3.23, an AutoIncrement
    /// column works properly only if it contains only positive values.  Inserting a negative number is
    /// regarded as inserting a very large positive number.  For MyISAM and BDB tables, you can specify an
    /// AUTO_INCREMENT secondary column in a multiple-column key.  The first value in an AutoIncrement column
    /// is always 1 and always increments by 1 for each new value.  This override is ignored on ApplySchema if
    /// this class refers to an existing table in a foreign database.
    /// 
    /// \param name 

    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetAutoIncrementPropertyName(FdoString* autoIncrementPropertyName);

    /// \brief
    /// Gets which FDO property corresponds to the single MySQL auto-increment column
    /// 
    /// \return
    /// Returns the FDO property corresponding to the single MySQL auto-increment column,
    /// or an empty string if there is no such property
    /// 
    FDOMYSQL_OV_API FdoString* GetAutoIncrementPropertyName(void);

    /// \brief
    /// The initial value to use for the first row in the auto-increment column, if any.
    /// 
    /// \remarks
    /// This override is only valid if the AutoIncrementProperty override is set to a non-empty string.
    /// This works only for the following storage engine types: MyISAM, MEMORY as of MySQL 4.1, and InnoDB
    /// as of MySQL 5.0.3.  This override is ignored on ApplySchema if this table is an existing table in
    /// a foreign database.
    /// 
    /// \return
    /// Returns the initial value to use for the first row in the auto-increment column
    /// 
    FDOMYSQL_OV_API FdoInt64 GetAutoIncrementSeed(void);

    /// \brief
    /// Sets the initial value to use for the first row in the auto-increment column, if any
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOMYSQL_OV_API void SetAutoIncrementSeed(FdoInt64 autoIncrementSeed);


/// \cond DOXYGEN-IGNORE

    /// Sets the parent of this object. Not part of the API.
    void SetParent(FdoPhysicalElementMapping* value);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize the XML attributes of this class:
    virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

/// \endcond

protected:
    FdoMySQLOvClassDefinition();
    FdoMySQLOvClassDefinition(FdoString *name);

    virtual ~FdoMySQLOvClassDefinition();
    void Init();
    virtual void Dispose();

    /// Create table override from XML attributes
    virtual void SetTable(
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* atts
    );

    /// Create data property override from XML attributes
    virtual FdoRdbmsOvDataPropertyDefinition* CreateDataProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoXmlAttributeCollection* colAtts
    );

    /// Create geometric property override from XML attributes
    virtual FdoRdbmsOvGeometricPropertyDefinition* CreateGeometricProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoXmlAttributeCollection* colAtts
    );

    /// Create object property override from XML attributes
    virtual FdoRdbmsOvObjectPropertyDefinition* CreateObjectProperty( 
        FdoXmlSaxContext* context,
        FdoXmlAttributeCollection* propAtts,
        FdoString* mappingType,
        FdoXmlAttributeCollection* mappingAtts
    );

    /// Add the given property override to this class override
    virtual void AddProperty( 
        FdoRdbmsOvPropertyDefinition* pProp
    );

private:
    FdoMySQLOvPropertiesP  mPropertyDefinitions;
    FdoInt64  mAutoIncrementSeed;
    FdoStringP  mAutoIncrementPropertyName;
};


/// \brief
/// FdoMySQLOvClassP is a FdoPtr on FdoMySQLOvClassDefinition, provided for convenience.
typedef FdoPtr<FdoMySQLOvClassDefinition> FdoMySQLOvClassP;

#endif



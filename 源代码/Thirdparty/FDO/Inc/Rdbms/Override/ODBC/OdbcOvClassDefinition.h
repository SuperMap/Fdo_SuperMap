#ifndef FDO_ODBCOVCLASSDEFINITION_H
#define FDO_ODBCOVCLASSDEFINITION_H
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
#include <Rdbms/Override/ODBC/OdbcOv.h>
#include <Rdbms/Override/ODBC/OdbcOvDataPropertyDefinition.h>
#include <Rdbms/Override/ODBC/OdbcOvGeometricPropertyDefinition.h>
#include <Rdbms/Override/ODBC/OdbcOvPropertyDefinitionCollection.h>
#include <Rdbms/Override/ODBC/OdbcOvTable.h>

/// \brief
/// Concrete class defining physical schema overrides for a class definition.
class FdoOdbcOvClassDefinition : public FdoRdbmsOvClassDefinition
{

public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvClassDefinition
    /// 
    /// \return
    /// Returns FdoOdbcOvClassDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvClassDefinition* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvClassDefinition using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvClassDefinition
    /// 
    FDOODBC_OV_API static FdoOdbcOvClassDefinition* Create(FdoString* name);

    /// \brief
    /// Gets a collection of Odbc property overrides
    /// 
    /// \return
    /// Returns the collection of Odbc property overrides
    /// 
    FDOODBC_OV_API FdoOdbcOvPropertyDefinitionCollection* GetProperties();

    /// \brief
    /// Gets the Odbc table override for this class override
    /// 
    /// \return
    /// Returns FdoOdbcOvTable
    /// 
    FDOODBC_OV_API FdoOdbcOvTable* GetTable();

    /// \brief
    /// Sets the Odbc table override for this class override
    /// 
    /// \param name 
    /// Input Odbc table override
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDOODBC_OV_API void SetTable(FdoOdbcOvTable* table);


/// \cond DOXYGEN-IGNORE

    /// Sets the parent of this object. Not part of the API.
    void SetParent(FdoPhysicalElementMapping* value);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

    /// Serialize the XML attributes of this class:
    virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

/// \endcond

protected:
    FdoOdbcOvClassDefinition();
    FdoOdbcOvClassDefinition(FdoString *name);

    virtual ~FdoOdbcOvClassDefinition();
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

    /// Add the given property override to this class override
    virtual void AddProperty( 
        FdoRdbmsOvPropertyDefinition* pProp
    );

private:
    FdoOdbcOvPropertiesP  mPropertyDefinitions;
};


/// \brief
/// FdoOdbcOvClassP is a FdoPtr on FdoOdbcOvClassDefinition, provided for convenience.
typedef FdoPtr<FdoOdbcOvClassDefinition> FdoOdbcOvClassP;

#endif



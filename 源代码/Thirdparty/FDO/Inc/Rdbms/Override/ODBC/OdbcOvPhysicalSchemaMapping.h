#ifndef FDO_ODBCOVPHYSICALSCHEMAMAPPING_H
#define FDO_ODBCOVPHYSICALSCHEMAMAPPING_H
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
#include <Rdbms/Override/ODBC/OdbcOv.h>
#include <Rdbms/Override/ODBC/OdbcOvClassCollection.h>

/// \brief
/// Concrete class offering schema overrides for
/// the Odbc Provider.
class FdoOdbcOvPhysicalSchemaMapping : public FdoRdbmsOvPhysicalSchemaMapping
{

public:

    /// \brief
    /// Constructs a default of an FdoOdbcOvPhysicalSchemaMapping
    /// 
    /// \return
    /// Returns FdoOdbcOvPhysicalSchemaMapping
    /// 
    FDOODBC_OV_API static FdoOdbcOvPhysicalSchemaMapping* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvPhysicalSchemaMapping using the specified arguments
    /// 
    /// \param name 
    /// Input name
    /// 
    /// \return
    /// Returns FdoOdbcOvPhysicalSchemaMapping
    /// 
    FDOODBC_OV_API static FdoOdbcOvPhysicalSchemaMapping* Create(FdoString* name);

    /// \brief
    /// Gets the classes
    /// 
    /// \return
    /// Returns the classes
    /// 
    FDOODBC_OV_API FdoOdbcOvClassCollection* GetClasses();

    /// \brief
    /// Gets the provider name
    /// 
    /// \return
    /// Returns the provider name
    /// 
    FDOODBC_OV_API virtual FdoString *GetProvider(void);

/// \cond DOXYGEN-IGNORE

    /// XML Serialization functions, not part of API.

    /// Serialize this property to XML.
    virtual void _writeXmlAttributes(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

    /// Initialize this element from its XML attributes
    virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);

/// \endcond

protected:
    FdoOdbcOvPhysicalSchemaMapping();
    FdoOdbcOvPhysicalSchemaMapping(FdoString* name);
    virtual ~FdoOdbcOvPhysicalSchemaMapping();
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

    /// Common initializer for all constructors:
    void Init();

private:
    FdoOdbcOvClassesP      mClasses;
};

/// \brief
/// FdoOdbcOvSchemaMappingP is a FdoPtr on FdoOdbcOvPhysicalSchemaMapping, provided for convenience.
typedef FdoPtr<FdoOdbcOvPhysicalSchemaMapping> FdoOdbcOvSchemaMappingP;

#endif



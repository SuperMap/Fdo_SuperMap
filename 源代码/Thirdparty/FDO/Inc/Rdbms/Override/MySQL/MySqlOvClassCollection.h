#ifndef FDO_MySQLOVCLASSCOLLECTION_H
#define FDO_MySQLOVCLASSCOLLECTION_H
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
#include <Rdbms/Override/MySQL/MySqlOvClassDefinition.h>
#include <Rdbms/Override/RdbmsOvClassCollection.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>

/// \brief
/// Concrete class defining physical schema overrides for a collection of classes.
class FdoMySQLOvClassCollection : public FdoRestrictedNamedCollection<FdoRdbmsOvClassDefinition,FdoMySQLOvClassDefinition,FdoRdbmsOvClassCollection>
{
public:
    /// \brief
    /// Constructs a default of an FdoMySQLOvClassCollection
    /// 
    /// \return
    /// Returns FdoMySQLOvClassCollection
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvClassCollection* Create();

    /// \brief
    /// Constructs an instance of an FdoMySQLOvClassCollection using the specified arguments
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoMySQLOvClassCollection
    /// 
    FDOMYSQL_OV_API static FdoMySQLOvClassCollection* Create(FdoRdbmsOvClassCollection* baseCollection);

protected:
    FdoMySQLOvClassCollection();
    FdoMySQLOvClassCollection(FdoRdbmsOvClassCollection* baseCollection);
    virtual ~FdoMySQLOvClassCollection();
    virtual void Dispose();

    virtual FdoMySQLOvClassDefinition* DownCast( FdoRdbmsOvClassDefinition* value ) const;

private:

};

/// \brief
/// FdoMySQLOvClassesP is a FdoPtr on FdoMySQLOvClassCollection, provided for convenience.
typedef FdoPtr<FdoMySQLOvClassCollection> FdoMySQLOvClassesP;

#endif



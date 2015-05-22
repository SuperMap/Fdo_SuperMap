#ifndef FDO_OdbcOVCLASSCOLLECTION_H
#define FDO_OdbcOVCLASSCOLLECTION_H
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
#include <Rdbms/Override/ODBC/OdbcOvClassDefinition.h>
#include <Rdbms/Override/RdbmsOvClassCollection.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>

/// \brief
/// Concrete class defining physical schema overrides for a collection of classes.
class FdoOdbcOvClassCollection : public FdoRestrictedNamedCollection<FdoRdbmsOvClassDefinition,FdoOdbcOvClassDefinition,FdoRdbmsOvClassCollection>
{
public:
    /// \brief
    /// Constructs a default of an FdoOdbcOvClassCollection
    /// 
    /// \return
    /// Returns FdoOdbcOvClassCollection
    /// 
    FDOODBC_OV_API static FdoOdbcOvClassCollection* Create();

    /// \brief
    /// Constructs an instance of an FdoOdbcOvClassCollection using the specified arguments
    /// 
    /// \param parent 
    /// Input parent
    /// 
    /// \return
    /// Returns FdoOdbcOvClassCollection
    /// 
    FDOODBC_OV_API static FdoOdbcOvClassCollection* Create(FdoRdbmsOvClassCollection* baseCollection);

protected:
    FdoOdbcOvClassCollection();
    FdoOdbcOvClassCollection(FdoRdbmsOvClassCollection* baseCollection);
    virtual ~FdoOdbcOvClassCollection();
    virtual void Dispose();

    virtual FdoOdbcOvClassDefinition* DownCast( FdoRdbmsOvClassDefinition* value ) const;

private:

};

/// \brief
/// FdoOdbcOvClassesP is a FdoPtr on FdoOdbcOvClassCollection, provided for convenience.
typedef FdoPtr<FdoOdbcOvClassCollection> FdoOdbcOvClassesP;

#endif



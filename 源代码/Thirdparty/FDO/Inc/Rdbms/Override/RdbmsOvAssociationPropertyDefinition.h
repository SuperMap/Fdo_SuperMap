#ifndef FDO_RDBMSOVASSOCIATIONPROPERTYDEFINITION_H
#define FDO_RDBMSOVASSOCIATIONPROPERTYDEFINITION_H
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

/// <library>
/// FdoRdbms.lib
/// </library>

#include <Rdbms/Override/RdbmsOv.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinitionCollection.h>

///<summary>Abstract class defining physical schema overrides for an association property
///definition.</summary>
class FdoRdbmsOvAssociationPropertyDefinition : public virtual FdoRdbmsOvPropertyDefinition
{
public:
    ///<summary>Gets a collection of Oracle property definitions</summary>
    /// <returns>Returns the collection of Oracle property definitions</returns>
    FDORDBMS_OV_API FdoRdbmsOvReadOnlyPropertyDefinitionCollection* GetProperties();

protected:
    FDORDBMS_OV_API FdoRdbmsOvAssociationPropertyDefinition();
    FDORDBMS_OV_API FdoRdbmsOvAssociationPropertyDefinition(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvAssociationPropertyDefinition();

    FDORDBMS_OV_API FdoRdbmsOvPropertyDefinitionCollection* GetRdbmsProperties();

private:
    FdoRdbmsOvPropertiesP mProperties;
};

#endif


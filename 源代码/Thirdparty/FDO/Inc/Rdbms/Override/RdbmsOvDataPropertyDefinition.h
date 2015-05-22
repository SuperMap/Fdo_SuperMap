#ifndef FDO_RDBMSOVDATAPROPERTYDEFINITION_H
#define FDO_RDBMSOVDATAPROPERTYDEFINITION_H
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
#include <Rdbms/Override/RdbmsOvColumn.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinition.h>

///<summary>Abstract class defining physical schema overrides for a data property
///definition.</summary>
class FdoRdbmsOvDataPropertyDefinition : public virtual FdoRdbmsOvPropertyDefinition
{
public:
    ///<summary>Gets the column override</summary>
    /// <returns>Returns FdoRdbmsOvColumn</returns>
    FDORDBMS_OV_API FdoRdbmsOvColumn* GetColumn();

protected:
    FDORDBMS_OV_API FdoRdbmsOvDataPropertyDefinition();
    FDORDBMS_OV_API FdoRdbmsOvDataPropertyDefinition(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvDataPropertyDefinition();

    // Sets the column override.
    FDORDBMS_OV_API void SetColumn(FdoRdbmsOvColumn *column);

    // Serialize provider-specific parts of this override to XML.
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
    FdoRdbmsOvColumnP mColumn;
};

///<summary>FdoRdbmsOvDataPropertyP is a FdoPtr on FdoRdbmsOvDataPropertyDefinition, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvDataPropertyDefinition> FdoRdbmsOvDataPropertyP;

#endif


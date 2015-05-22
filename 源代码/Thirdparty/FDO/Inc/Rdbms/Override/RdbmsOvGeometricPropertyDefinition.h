#ifndef FDO_RDBMSOVGEOMETRICPROPERTYDEFINITION_H
#define FDO_RDBMSOVGEOMETRICPROPERTYDEFINITION_H

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
#include <Rdbms/Override/RdbmsOvPropertyDefinition.h>
#include <Rdbms/Override/RdbmsOvGeometricColumn.h>
#include <Utilities/SchemaMgr/Overrides/GeometricColumnType.h>
#include <Utilities/SchemaMgr/Overrides/GeometricContentType.h>

///<summary>Abstract class defining physical schema overrides for a geometric property
///definition.</summary>
class FdoRdbmsOvGeometricPropertyDefinition : virtual public FdoRdbmsOvPropertyDefinition
{
public:
    ///<summary>Gets the column override</summary>
    /// <returns>Returns FdoRdbmsOvGeometricColumn</returns>
    FDORDBMS_OV_API FdoRdbmsOvGeometricColumn* GetColumn();

    ///<summary>Gets the geometric column type</summary>
    ///<returns>Returns the default geometric column type</returns>
    FDORDBMS_OV_API FdoSmOvGeometricColumnType GetGeometricColumnType();

    ///<summary>Sets the geometric column type</summary>
    /// <param name="mappingType">Input the geometric column type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetGeometricColumnType(FdoSmOvGeometricColumnType columnType);

    ///<summary>Gets the geometric content type</summary>
    ///<returns>Returns the geometric content type</returns>
    FDORDBMS_OV_API FdoSmOvGeometricContentType GetGeometricContentType();

    ///<summary>Sets the content type</summary>
    /// <param name="mappingType">Input the content type</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetGeometricContentType(FdoSmOvGeometricContentType contentType);

    ///<summary>Gets the ordinate column name for the X ordinate.
    /// This only applies when GeometricContentType==FdoSmOvGeometricContentType_Ordinates.
    /// Default value is "X".
    ///</summary>
    ///<returns>Returns the ordinate column name for the X ordinate</returns>
    FDORDBMS_OV_API FdoString * GetXColumnName();

    ///<summary>Sets the ordinate column name for the X ordinate</summary>
    /// <param name="mappingType">Input the X ordinate column name</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetXColumnName(FdoString * columnName);

    ///<summary>Gets the ordinate column name for the Y ordinate.
    /// This only applies when GeometricContentType==FdoSmOvGeometricContentType_Ordinates.
    /// Default value is "Y".
    ///</summary>
    ///<returns>Returns the ordinate column name for the Y ordinate</returns>
    FDORDBMS_OV_API FdoString * GetYColumnName();

    ///<summary>Sets the ordinate column name for the Y ordinate</summary>
    /// <param name="mappingType">Input the Y ordinate column name</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetYColumnName(FdoString * columnName);

    ///<summary>Gets the ordinate column name for the Z ordinate.
    /// This only applies when GeometricContentType==FdoSmOvGeometricContentType_Ordinates
    /// and the property definition's "HasElevation" attribute is "true".
    /// Default value is "Z".
    ///</summary>
    ///<returns>Returns the ordinate column name for the Z ordinate</returns>
    FDORDBMS_OV_API FdoString * GetZColumnName();

    ///<summary>Sets the ordinate column name for the Z ordinate</summary>
    /// <param name="mappingType">Input the Z ordinate column name</param>
    ///<returns>Returns nothing</returns>
    FDORDBMS_OV_API void SetZColumnName(FdoString * columnName);

//DOM-IGNORE-BEGIN
    FDORDBMS_OV_API virtual void InitFromXml(FdoXmlSaxContext* pContext, FdoXmlAttributeCollection* attrs);
//DOM-IGNORE-END


protected:
    FDORDBMS_OV_API FdoRdbmsOvGeometricPropertyDefinition();
    FDORDBMS_OV_API FdoRdbmsOvGeometricPropertyDefinition(FdoString* name);
    FDORDBMS_OV_API virtual ~FdoRdbmsOvGeometricPropertyDefinition();

    // Sets the column override
    FDORDBMS_OV_API void SetColumn(FdoRdbmsOvGeometricColumn* geometricColumn);

    FDORDBMS_OV_API virtual void _writeXml(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);
    FDORDBMS_OV_API virtual void _writeXmlContents(FdoXmlWriter* xmlWriter, const FdoXmlFlags* flags);

private:
    FdoPtr<FdoRdbmsOvGeometricColumn> mColumn;
    FdoSmOvGeometricColumnType  mGeometricColumnType;
    FdoSmOvGeometricContentType mGeometricContentType;
    FdoStringP                     mXColumnName;
    FdoStringP                     mYColumnName;
    FdoStringP                     mZColumnName;

};

///<summary>FdoRdbmsOvGeometricPropertyP is a FdoPtr on FdoRdbmsOvGeometricPropertyDefinition, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvGeometricPropertyDefinition> FdoRdbmsOvGeometricPropertyP;

#endif


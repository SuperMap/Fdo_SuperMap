#ifndef FDO_RDBMSOVPROPERTYDEFINITIONCOLLECTION_H
#define FDO_RDBMSOVPROPERTYDEFINITIONCOLLECTION_H
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

#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>
#include <Rdbms/Override/RdbmsOvPropertyDefinition.h>

//DOM-IGNORE-BEGIN
///<summary>Concrete class defining physical schema overrides for a collection of property
///definitions.</summary>
class FdoRdbmsOvPropertyDefinitionCollection : public FdoPhysicalElementMappingCollection<FdoRdbmsOvPropertyDefinition>
{
public:
    ///<summary>Constructs a default instance of an FdoRdbmsOvPropertyDefinitionCollection</summary>
    /// <returns>Returns FdoRdbmsOvPropertyDefinitionCollection</returns> 
    static FdoRdbmsOvPropertyDefinitionCollection* Create();

    ///<summary>Constructs an instance of an FdoRdbmsOvPropertyDefinitionCollection using the specified arguments</summary>
    /// <param name="parent">Input parent</param> 
    /// <returns>Returns FdoRdbmsOvPropertyDefinitionCollection</returns> 
    static FdoRdbmsOvPropertyDefinitionCollection* Create(FdoPhysicalElementMapping* parent);

protected:
    FdoRdbmsOvPropertyDefinitionCollection();
    FdoRdbmsOvPropertyDefinitionCollection(FdoPhysicalElementMapping* parent);
    virtual ~FdoRdbmsOvPropertyDefinitionCollection();
    virtual void Dispose();
};

///<summary>FdoRdbmsOvPropertiesP is a FdoPtr on FdoRdbmsOvPropertyDefinitionCollection, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvPropertyDefinitionCollection> FdoRdbmsOvPropertiesP;
//DOM-IGNORE-END

///<summary>Collection of property overrides for an RDBMS-type provider.
///Members cannot be added to or removed from this collection.
///</summary>
class FdoRdbmsOvReadOnlyPropertyDefinitionCollection : public FdoReadOnlyNamedCollection<FdoRdbmsOvPropertyDefinition,FdoRdbmsOvPropertyDefinitionCollection>
{
//DOM-IGNORE-BEGIN
public:
    ///<summary>Constructs a default of an FdoRdbmsReadOnlyOvPropertyDefinitionCollection</summary>
    /// <returns>Returns FdoRdbmsOvReadOnlyPropertyDefinitionCollection</returns> 
    static FdoRdbmsOvReadOnlyPropertyDefinitionCollection* Create();

    ///<summary>Constructs an instance of an FdoRdbmsReadOnlyOvPropertyDefinitionCollection using the specified arguments</summary>
    /// <param name="parent">Input parent</param> 
    /// <returns>Returns FdoRdbmsOvReadOnlyPropertyDefinitionCollection</returns> 
    static FdoRdbmsOvReadOnlyPropertyDefinitionCollection* Create(FdoRdbmsOvPropertyDefinitionCollection* baseCollection);

protected:
    FdoRdbmsOvReadOnlyPropertyDefinitionCollection();
    FdoRdbmsOvReadOnlyPropertyDefinitionCollection(FdoRdbmsOvPropertyDefinitionCollection* baseCollection);
    virtual ~FdoRdbmsOvReadOnlyPropertyDefinitionCollection();
    virtual void Dispose();
//DOM-IGNORE-END
};

///<summary>FdoRdbmsOvReadOnlyPropertiesP is a FdoPtr on FdoRdbmsOvReadOnlyPropertyDefinitionCollection, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvReadOnlyPropertyDefinitionCollection> FdoRdbmsOvReadOnlyPropertiesP;


#endif


#ifndef FDO_RDBMSOVCLASSCOLLECTION_H
#define FDO_RDBMSOVCLASSCOLLECTION_H
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

#include <Rdbms/Override/RdbmsOvClassDefinition.h>
#include <Fdo/Commands/Schema/PhysicalElementMappingCollection.h>

//DOM-IGNORE-BEGIN
///<summary>Concrete class defining physical schema overrides for a collection of class
///definitions.</summary>
class FdoRdbmsOvClassCollection : public FdoPhysicalElementMappingCollection<FdoRdbmsOvClassDefinition>
{
public:
    ///<summary>Constructs a default instance of an FdoRdbmsOvClassCollection</summary>
    /// <returns>Returns FdoRdbmsOvClassCollection</returns> 
    static FdoRdbmsOvClassCollection* Create();

    ///<summary>Constructs an instance of an FdoRdbmsOvClassCollection using the specified arguments</summary>
    /// <param name="parent">Input parent</param> 
    /// <returns>Returns FdoRdbmsOvClassCollection</returns> 
    static FdoRdbmsOvClassCollection* Create(FdoPhysicalElementMapping* parent);

protected:
    FdoRdbmsOvClassCollection();
    FdoRdbmsOvClassCollection(FdoPhysicalElementMapping* parent);
    virtual ~FdoRdbmsOvClassCollection();
    virtual void Dispose();
};

///<summary>FdoRdbmsOvClassesP is a FdoPtr on FdoRdbmsOvClassCollection, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvClassCollection> FdoRdbmsOvClassesP;
//DOM-IGNORE-END

///<summary>Collection of class overrides for an RDBMS-type provider.
///Members cannot be added to or removed from this collection.
///</summary>
class FdoRdbmsOvReadOnlyClassCollection : public FdoReadOnlyNamedCollection<FdoRdbmsOvClassDefinition,FdoRdbmsOvClassCollection>
{
//DOM-IGNORE-BEGIN
public:
    ///<summary>Constructs a default of an FdoRdbmsReadOnlyOvClassCollection</summary>
    /// <returns>Returns FdoRdbmsOvReadOnlyClassCollection</returns> 
    static FdoRdbmsOvReadOnlyClassCollection* Create();

    ///<summary>Constructs an instance of an FdoRdbmsOvReadOnlyClassCollection using the specified arguments</summary>
    /// <param name="parent">Input parent</param> 
    /// <returns>Returns FdoRdbmsOvReadOnlyClassCollection</returns> 
    static FdoRdbmsOvReadOnlyClassCollection* Create(FdoRdbmsOvClassCollection* baseCollection);

protected:
    FdoRdbmsOvReadOnlyClassCollection();
    FdoRdbmsOvReadOnlyClassCollection(FdoRdbmsOvClassCollection* baseCollection);
    virtual ~FdoRdbmsOvReadOnlyClassCollection();
    virtual void Dispose();
//DOM-IGNORE-END
};

///<summary>FdoRdbmsOvReadOnlyClassesP is a FdoPtr on FdoRdbmsOvReadOnlyClassCollection, provided for convenience.</summary>
typedef FdoPtr<FdoRdbmsOvReadOnlyClassCollection> FdoRdbmsOvReadOnlyClassesP;


#endif


// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef FDOCOMMONPROPERTYINDEX_H
#define FDOCOMMONPROPERTYINDEX_H

#include <string>


typedef unsigned short FCID_STORAGE;


struct FdoCommonPropertyStub
{
    wchar_t* m_name;
    int m_recordIndex;
    FdoDataType m_dataType;
	FdoPropertyType m_propertyType;
    bool m_isAutoGen;
};

//Utility class that maps a class' property names
//to their index inside the database record.
//Identity properties are indexed using negative numbers (starting at -1), 
//since they are stored in the key record, not the 
//data record
class FdoCommonPropertyIndex : public FdoDisposable
{
public:

    FdoCommonPropertyIndex(FdoClassDefinition* clas, unsigned int fcid, FdoIdentifierCollection *selectedIds = NULL);

    FdoCommonPropertyStub* GetPropInfo(FdoString* name);
    FdoCommonPropertyStub* GetPropInfo(int index);
    bool IsPropAutoGen(FdoString* name);
    int GetNumProps();
    FdoClassDefinition* GetBaseClass();
    FdoFeatureClass* GetBaseFeatureClass();
    unsigned int GetFCID();
    bool HasAutoGen();

    static FdoGeometricPropertyDefinition* FindGeomProp(FdoClassDefinition* clas);

protected:

    FdoCommonPropertyIndex(){};
    ~FdoCommonPropertyIndex();

private:

    int m_numProps;
    FdoCommonPropertyStub* m_vProps;
    FdoClassDefinition* m_baseClass;
    FdoFeatureClass* m_baseFeatureClass;
    unsigned int m_fcid;
    bool m_bHasAutoGen;
};


#endif



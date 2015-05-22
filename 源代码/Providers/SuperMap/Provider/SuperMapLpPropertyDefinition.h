/** \file	 SuperMapLpPropertyDefinition.h
*  \brief    该类主要完成从SuperMap矢量数据集属性列到Fdo逻辑要素类的属性的转换。
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_PROPERTYDEFINITION_H__
#define __SUPERMAP_LP_PROPERTYDEFINITION_H__

#ifdef _WIN32
#pragma once
#endif

#include "UGC.h"

class SuperMapLpClassDefinition;

class SuperMapLpPropertyDefinition : public FdoDisposable
{
public:
	SuperMapLpPropertyDefinition(SuperMapLpClassDefinition* parentLpClass, UGC::UGDatasetVector* pDataset, UGC::UGFieldInfo* fieldInfo, FdoPropertyDefinition* configLogicalProperty);
	~SuperMapLpPropertyDefinition(void);

	//! \brief		从物理数据集的属性字段建立逻辑要素类的数据属性
	//! \param		[in]fieldInfo 物理属性字段信息的指针
	void ConvertPhysicalToLogical(UGC::UGFieldInfo* fieldInfo);

	//! \brief		从逻辑要素类的数据属性建立物理数据集的属性字段
	//! \param		[in/out]pDatasetVector 在该矢量数据集中建立物理属性字段  
	//! \param		[in]configLogicalProperty 待转换的逻辑属性
	void ConvertLogicalToPhysical(UGC::UGDatasetVector* pDatasetVector,FdoPropertyDefinition* configLogicalProperty);

	 // To please FdoNamedCollection:
    FdoString* GetName(void);
    virtual FdoBoolean CanSetName() { return true; }

	// Returns the physical layer:
	UGC::UGFieldInfo* GetFieldInfo() const;
    
protected:
	SuperMapLpPropertyDefinition(){}
private:
	// Parent LpClass, weak reference
	SuperMapLpClassDefinition* m_parentLpClass;

	// logical layer
	FdoPtr<FdoDataPropertyDefinition> m_logicalProperty;

	// physical layer
	UGC::UGFieldInfo* m_fieldInfo;
};

class SuperMapLpPropertyDefinitionCollection : public FdoNamedCollection<SuperMapLpPropertyDefinition, FdoException>
{
public:
	SuperMapLpPropertyDefinitionCollection(){}

protected:
	virtual ~SuperMapLpPropertyDefinitionCollection(){}

	/// <summary>Dispose this object instance.</summary>
    /// <returns>Returns nothing</returns>
    virtual void Dispose() 
    { 
        delete this; 
    }
};


#endif //__SUPERMAP_LP_PROPERTYDEFINITION_H__
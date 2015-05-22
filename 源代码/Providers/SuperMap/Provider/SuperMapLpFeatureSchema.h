/** \file	 SuperMapLpFeatureSchema.h
*  \brief    该类主要完成从SuperMap数据源到Fdo逻辑模式的转换。
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_FEATURESCHEMA_H__
#define __SUPERMAP_LP_FEATURESCHEMA_H__

#ifdef _WIN32
#pragma once
#endif

#include "UGC.h"

class SuperMapConnection;
class SuperMapLpFeatureSchemaCollection ;
class SuperMapLpClassDefinitionCollection ;

class SuperMapLpFeatureSchema : public FdoDisposable
{
public:
	SuperMapLpFeatureSchema(void); // 0-argument constructor to please FdoPtr::operator-> 

	SuperMapLpFeatureSchema(
		SuperMapLpFeatureSchemaCollection* parentLpSchemas,
		SuperMapConnection* connection,
		UGC::UGDataSource* pDataSource,
		FdoFeatureSchema* configLogicalSchema,
		bool ignoreStates = false);

	// For FdoNamedCollection:
    FdoString * GetName() const;
    bool CanSetName() const;

	//! \brief		获取逻辑物理模式中的逻辑模式
	//! \return		FdoFeatureSchema* 逻辑模式的的指针
    FdoFeatureSchema * GetLogicalSchema() const;

	//! \brief		获取逻辑物理模式中的影像模式
	//! \return		FdoFeatureSchema* 逻辑模式的的指针
    //FdoFeatureSchema * GetImageSchema() const;

    //! \brief		获取逻辑物理模式中的逻辑物理类集合
	//! \return		SuperMapLpClassDefinitionCollection* 逻辑物理类集合的指针	
    SuperMapLpClassDefinitionCollection* GetLpClasses();

    //! \brief		获取逻辑物理模式中的物理数据源
	//! \return		UGC::UGDataSource* 物理数据源指针 
    UGC::UGDataSource* GetDataSource() const;

	//! \brief      根据给定的信息修改模式
	//! \param      connection 当前的SuperMap连接
	//! \param		configLogicalSchema 待修改的模式
	//! \param		bool变量ignoreStates，是否忽略模式元素状态
	void Modify(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates);

	//! \brief		在当前模式中增加一个要素类
	//! \param		connection 当前的SuperMap连接
	//! \param		logicalClass 添加的逻辑类（大容量复制中根据此逻辑类创建物理数据集）
	void addClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		在当前模式中删除一个要素类
	//! \param		connection 当前的SuperMap连接
	//! \param		待删除的类
	void deleteClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		在当前模式中修改一个要素类
	//! \param		connection 当前的SuperMap连接
	//! \param		待修改的类
	void modifyClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass);

	//! \brief		永久删除该逻辑模式中的相关信息
	//! \param		connection 当前的SuperMap连接
	void Delete(SuperMapConnection* connection);

protected:
	//! \biref		从物理数据源到逻辑模式的转换
	//! \param		[in]connection 当前连接
    void ConvertPhysicalToLogical(SuperMapConnection * connection);
	
	//! \biref		从逻辑模式到物理数据源的转换
	//! \param		[in]connection 当前连接
	//! \param		[in]configLogicalSchema 待转换的逻辑模式
	//! \param		[in]ignoreStates 是否忽略FDO模式元素状态标志
	void ConvertLogicalToPhysical(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates);

	virtual ~SuperMapLpFeatureSchema(void);

private:
	SuperMapLpFeatureSchemaCollection*          m_parentLpSchemas ;    // weak reference 存包括该逻辑物理模式的逻辑物理模式集合
	FdoPtr<FdoFeatureSchema>					m_logicalSchema ;      // 逻辑（FDO）模式
	UGC::UGDataSource*							m_pDataSource ;        // 物理（UGC）模式,即SuperMap数据源
	FdoPtr<SuperMapLpClassDefinitionCollection> m_lpClasses ;          // 逻辑物理类

	// 专门处理影像数据的模式
	//FdoPtr<FdoFeatureSchema> m_ImageSchema;

};

class SuperMapLpFeatureSchemaCollection : public FdoNamedCollection<SuperMapLpFeatureSchema, FdoException>
{
public:
	SuperMapLpFeatureSchemaCollection(void);

	SuperMapLpFeatureSchemaCollection(
		SuperMapConnection* connection,
		UGC::UGDataSource* pDataSource
		);

	// Return pointer to cached logical schema collection:
    FdoFeatureSchemaCollection* GetLogicalSchemas();

protected:
	// Convert physical to logical schema collection:
	void ConvertPhysicalToLogical(SuperMapConnection* connection,UGC::UGDataSource* pDataSource);

	virtual ~SuperMapLpFeatureSchemaCollection(void){}
	/// <summary>Dispose this object instance.</summary>
    /// <returns>Returns nothing</returns>
    virtual void Dispose() 
    { 
        delete this; 
    }

private:
	FdoPtr<FdoFeatureSchemaCollection> m_logicalSchemas;             // 由物理数据源转化的逻辑模式集合

};

#endif //__SUPERMAP_LP_FEATURESCHEMA_H__
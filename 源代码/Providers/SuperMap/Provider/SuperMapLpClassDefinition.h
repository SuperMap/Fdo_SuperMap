/** \file	 SuperMapLpClassDefinition.h
*  \brief    该类主要完成从SuperMap数据集到Fdo逻辑类的转换。
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#ifndef __SUPERMAP_LP_CLASSDEFINITION_H__
#define __SUPERMAP_LP_CLASSDEFINITION_H__

#ifdef _WIN32
#pragma once
#endif

class SuperMapConnection;
class SuperMapLpFeatureSchema;
class SuperMapLpPropertyDefinitionCollection;

class SuperMapLpClassDefinition : public FdoDisposable
{
	friend class SuperMapLpFeatureSchema;

public:
	SuperMapLpClassDefinition(void);
	SuperMapLpClassDefinition(
		SuperMapLpFeatureSchema* parentLpSchema, 
		SuperMapConnection* connection, 
		UGC::UGDataset* pDataset, 
		FdoClassDefinition* configLogicalClass);

	~SuperMapLpClassDefinition(void);

	//! \biref		从物理数据集到逻辑要素类的转换
	//! \param		[in]connection 当前连接
	//! \param		[in]pDataset 待转换的物理数据集
	void ConvertPhysicalToLogical(SuperMapConnection * connection, UGC::UGDataset* pDataset);
	
	//! \biref		从逻辑要素类到物理数据集的转换
	//! \param		[in]connection 当前连接
	//! \param		[in]configLogicalClass 待转化的逻辑要素类
	void ConvertLogicalToPhysical(SuperMapConnection* connection, FdoClassDefinition* configLogicalClass);

	//! \biref		将物理数据集的标识字段转化成逻辑类的标识属性字段
	//! \return     返回一个FdoDataPropertyDefinition的指针
    static FdoDataPropertyDefinition* ConvertPhysicalToLogicalIdentityProperty();

	//! \brief		根据物理数据集类型生成要数类的几何属性
    //! \param		[in]connection 当前连接
	//! \param      [in]pDatasetVector 矢量的物理数据集
	//! \return     返回一个FdoGeometricPropertyDefinition的指针
    static FdoGeometricPropertyDefinition* ConvertPhysicalToLogicalGeometryProperty(SuperMapConnection *connection,
		UGC::UGDatasetVector* pDatasetVector);

	//! \brief		从Fdo的几何类型到物理数据集类型的转换
    //! \param		[in]geomTypes 存储具体的Fdo几何类型的数组
	//! \param      [in]geomTypeCount 几何类型数组中具体的几何类型个数
	//! \return     返回UGC的物理数据集类型
	//! \note		Fdo几何属性类型如由FdoGeometricPropertyDefinition::SetSpecificGeometryTypes()设置可以正确转化;
	//!             但是如由FdoGeometricPropertyDefinition::SetGeometryTypes()设置则不行            
	static UGC::UGDataset::DatasetType FdoGeometryToUGDatasetType(FdoGeometryType* geomTypes, FdoInt32 geomTypeCount,
		bool has_elevation, bool has_measure);
	
	//! \brief		根据栅格数据集生成对应的逻辑栅格属性
	//! \param		connection 当前连接
	//! \param		pDatasetRaster 栅格数据集指针
	//! \return		返回一个FdoRasterPropertyDefinition的指针
	static FdoRasterPropertyDefinition* ConvertPhysicalToLogicalRasterProperty(SuperMapConnection* connection, 
		UGC::UGDatasetRaster* pDatasetRaster);

	//! \brief		获取本逻辑物理要素类包含的逻辑物理属性的集合
	//! \return		SuperMapLpPropertyDefinitionCollection* 逻辑物理属性几何的指针
    SuperMapLpPropertyDefinitionCollection* GetLpProperties() const;

	//! \brief		获取逻辑物理类中的物理数据集
	//! \return		UGC::UGDataset* 物理数据集指针 
    UGC::UGDataset* GetDataset(void);

	//! \brief		获取逻辑物理类中的逻辑类
	//! \return		FdoClassDefinition* 逻辑类的指针
    FdoClassDefinition* GetLogicalClass(void);

	//! \brief		设置父逻辑物理模式
	//! \param		[in]parent 逻辑物理模式
    void SetParent (SuperMapLpFeatureSchema* parent);

	//! \brief		永久删除逻辑物理相关类
	//! \param		connection当前的SuperMap连接
	void Delete (SuperMapConnection* connection);

	// To please FdoNamedCollection:
    FdoString* GetName();
    virtual FdoBoolean CanSetName() { return true; }

private:
	SuperMapConnection*  m_connection;				// NOTE: weak reference

	// Logical layer:
    FdoPtr<FdoClassDefinition> m_logicalClassDefinition;

	 // LogicalPhysical layer:
    SuperMapLpFeatureSchema*                       m_parentLpSchema; // weak reference
    FdoPtr<SuperMapLpPropertyDefinitionCollection> m_LpProperties;

	// Physical layer:
	UGC::UGDataset* m_pDataset;
};

class SuperMapLpClassDefinitionCollection : public FdoNamedCollection<SuperMapLpClassDefinition, FdoException>
{
public:
	SuperMapLpClassDefinitionCollection(){}

protected:
	virtual ~SuperMapLpClassDefinitionCollection(){}

	virtual void Dispose()
	{
		delete this;
	}
};

#endif // __SUPERMAP_LP_CLASSDEFINITION_H__ 

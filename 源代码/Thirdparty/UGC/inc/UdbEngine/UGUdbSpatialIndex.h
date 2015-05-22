//////////////////////////////////////////////////////////////////////////
//!  \file UGUdbSpatialIndex.h
//!  \brief UGUdbSpatialIndex 类的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_)
#define AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UdbEngine/UGUdbDatasetVector.h"

namespace UGC{

class UGUdbSpatialIndex  
{
	friend class UGUdbDatasetVector;
	friend class UGUdbEditRecordset;

public:
	UGUdbSpatialIndex();
	UGUdbSpatialIndex(UGUdbDatasetVector *pDT);
	virtual ~UGUdbSpatialIndex();
	
public:
	//! \brief 建立空间索引。
	//! \param spatial 空间索引信息的引用,此信息记录了索引的类型及重要参数[in]。
	//! \return 是否成功创建索引，成功返回TRUE，失败返回FALSE。
	//! \remarks 此函数是对创建不同索引的分支函数。
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief 根据当前索引状态重建索引。
	//! \return 是否成功重建索引，成功返回TRUE，失败返回FALSE。
	UGbool ReBuildSpatialIndex();

	//! \brief 脏数据的空间索引更新。
	//! \return 是否成功更新索引，成功返回TRUE，失败返回FALSE。
	//! \remarks 是否更新索引根据脏数据所占总记录数的比例是否达到临界值来决定。
	UGbool UpdateSpatialIndex();
	
	//! \brief 清除空间索引。
	//! \return 是否成功清除索引，成功返回TRUE，失败返回FALSE。
	UGbool DropSpatialIndex();
	
	//! \brief 是否需要重建空间索引。
	//! \return 需要重建索引返回TRUE，否则返回FALSE。
	//! \remarks 根据脏数据所占比例来确定。
	UGbool IsSpatialIndexDirty();
	
	//! \brief 得到空间索引脏的记录的数目。
	//! \return 空间索引脏的记录的数目。
	//! \remarks 为是否需要重建空间索引提供参考，是返回TRUE，否返回FALSE。
	UGint GetDirtyRecordCount();

	//! \brief 统计索引创建后的一些参数。
	//! \param pDs 数据源指针[in]。
	//! \return 是统计成功，成功返回TRUE，失败返回FALSE。
	UGbool StatisticIndex(UGDataSource *pDs);
protected:
	//以下三个方法在 BuildSpatialIndex 中调用，用于建立不同类型的索引

	//! \brief 建立R树索引。
	//! \param spatial 空间索引信息的引用[in]。
	//! \return 是否成功创建索引，成功返回TRUE，失败返回FALSE。
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立图幅索引。
	//! \param spatial 空间索引信息的引用[in]。
	//! \return 是否成功创建索引，成功返回TRUE，失败返回FALSE。
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立多级网格索引
	//! \param spatial 空间索引信息的引用[in]。
	//! \return 是否成功创建索引，成功返回TRUE，失败返回FALSE。
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief 建立四叉树索引
	//! \param spatial 空间索引信息的引用[in]。
	//! \return 是否成功创建索引，成功返回TRUE，失败返回FALSE。
	UGbool BuildSpatialIndexQTree(UGSpatialIndexInfo &spatial);

	/////////////////////////////// 图幅索引的方法 ////////////////////////////////////
	
	//! \brief 注册三级索引，创建索引子Lib表。
	//! \return 是否成功创建Lib表，成功返回TRUE，失败返回FALSE。
	UGbool PrepareLib();

	//! \brief 通过指定图幅的大小来建立三级索引。
	//! \param dWidth 图幅的宽度[in]。
	//! \param dHeight 图幅的高度度[in]。
	//! \return 是否成功建立三级索引，成功返回TRUE，失败返回FALSE。
	UGbool RegisterLibraryByGridSize(UGdouble dWidth, UGdouble dHeight);

	//! \brief 通过指定名称的字段来建立三级索引。
	//! \param strFieldName 指定名称的字段[in]。
	//! \return 是否成功建立三级索引，成功返回TRUE，失败返回FALSE。
	UGbool RegisterLibraryByField(const UGString &strFieldName);

	/////////////////////////////// R树索引的方法 ////////////////////////////////////
	
	//! \brief R树叶子节点的加载。
	//! \param nID 节点ID号[in]。
	//! \param stream 节点对应的索引包[out]。
	//! \return 叶子节点包的大小(字节)。
	UGint LoadRTreeLeaf(UGint nID,UGStream &stream);	
	
	//! \brief R树叶子节点的存储。
	//! \param nID 节点ID号[in]。
	//! \param stream 节点对应的索引包[in]。
	//! \return 是否成功建立三级索引，成功返回TRUE，失败返回FALSE。
	UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);	

	//! \brief 析取叶节点数据。
	//! \param SearchBounds 选择框矩形[in]。
	//! \param aryItemIDs 析取到的合适的点集[out]。
	//! \param aryCertainLeafIDs 确定在选择框内的叶节点ID数组[in]。
	//! \param &aryCertainBounds 确定在选择框内的对象的四至范围数组[in]。
	//! \param aryMaybeLeafIDs 可能在选择框内的叶节点ID数组[in]。
	//! \param &aryMaybeBounds 可能在选择框内的对象的四至范围数组[in]。
	//! \param bFuzzy 是否模糊查询[in]。
	//! \param dGranule 查询的粒度[in]。
	//! \return 是否析取叶节点数据，成功返回TRUE，失败返回FALSE。
	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);	

	//! \brief 更新对索引的编辑。
	//! \param nID 更新的记录的ID[in]。
	//! \param nEditState 对记录所作的更新操作[in]。
	//! \param pGeometry 几何对象指针[in]。
	//! \param rc2Org 编辑前的边界[in]。
	//! \param rc2New 编辑后的边界[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	//! \remarks 编辑后对索引的更新入口。
	//! \attention pGeometry 只在多级网格索引时传入非空，其它传入NULL。
	UGbool UpdateIndexItem(UGint nID, const UGint nEditState, 
		UGGeometry *pGeometry,const UGRect2D &rc2Org, const UGRect2D &rc2New);	

private:

	//! \brief 更新RTree索引叶节点。
	//! \param nID 更新的记录的ID[in]。
	//! \param nEditState 对记录所作的更新操作[in]。
	//! \param &rc2Org 记录原来的Bounds[in]。
	//! \param &rc2New 记录新的Bounds，只在SetGeometry时rc2Org和rc2Dest不同[in]。
	//! \return 更新索引的操作成功与否。
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Org, const UGRect2D &rc2New);	
	
	//这些在UpdateRTreeItem调用

	//! \brief 更新R树索引的添加编辑。
	//! \param nID 更新的记录的ID[in]。
	//! \param rc2New 新记录的四至[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);

	//! \brief 更新R树索引的删除编辑。
	//! \param nID 更新的记录的ID[in]。
	//! \param rc2Org 原记录的四至[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Org);	

	//! \brief 更新R树索引的移动编辑。
	//! \param nID 更新的记录的ID[in]。
	//! \param &rc2Org 原记录的四至[in]。
	//! \param &rc2New 新记录的四至[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Org, const UGRect2D &rc2New);	

	//! \brief 从数据表中取得所有Geometry的ID和四至并清空R树索引表。
	//! \param NodeItems 节点元素集数组[in]。
	//! \param strSort 排序字段[in]。
	//! \attention ，在建立R树索引时调用。
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGString strSort);	

	//! \brief 更新图幅索引的图幅信息。
	//! \param dwLibID 图幅索引的ID号[in]。
	//! \param nID 更新的记录的ID[in]。
	//! \param nEditMode 对记录所作的更新操作[in]。
	//! \param rc2New 新记录的四至[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);	

	//! \brief 更新多级网格索引
	//! \param nID 更新的记录的ID[in]。
	//! \param nEditMode 对记录所作的更新操作[in]。
	//! \param *pGeometry 几何对象的指针[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief 更新纯四叉树索引
	//! \param nID 更新的记录的ID[in]。
	//! \param nEditMode 对记录所作的更新操作[in]。
	//! \param rc2New 新记录的四至[in]。
	//! \return 是否成功更新编辑，成功返回TRUE，失败返回FALSE。
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief 保存索引信息
	UGbool SaveIndexInfo();

private:
	//! \brief 索引关联的适量数据集指针。
	UGUdbDatasetVector *m_pDataset;
};

}
#endif // !defined(AFX_UGUDBSPATIALINDEX_H__EFA5DF23_E7FE_439D_A1D9_C6885B0183C6__INCLUDED_)

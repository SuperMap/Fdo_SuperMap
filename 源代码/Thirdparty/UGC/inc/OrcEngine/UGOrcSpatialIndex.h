// UGOrcSpatialIndex.h: interface for the UGOrcSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_)
#define AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OrcEngine/UGOrcDatasetVector.h"

namespace UGC{

class UGOrcSpatialIndex  
{
	//加一个class，否则linux下编译不过，modified by xielin 
	friend class UGOrcDatasetVector;
	friend class UGOrcEditRecordset;
	friend class UGOrcDatasetVectorVersion;
public:
	UGOrcSpatialIndex();
	UGOrcSpatialIndex(UGOrcDatasetVector *pDT);
	virtual ~UGOrcSpatialIndex();

public:
	//! 建立空间索引
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief 根据当前索引状态重建索引
	//! \param。
	//! \return
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex();

	//! \brief 脏数据的空间索引更新
	//! \param。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool UpdateSpatialIndex();
	
	//! 清除空间索引
	UGbool DropSpatialIndex();
	
	//! 是否需要重建空间索引
	UGbool IsSpatialIndexDirty();
	
	//! 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	UGint GetDirtyRecordCount();

	UGbool StatisticIndex(UGDataSource *pDs);
protected:
	//以下三个方法在 BuildSpatialIndex 中调用，用于建立不同类型的索引

	//! \brief 建立R树索引
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立图幅索引
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立多级网格索引
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief 建立四叉树索引
	UGbool BuildSpatialIndexQTree(UGSpatialIndexInfo &spatial);

	/////////////////////////////// 图幅索引的方法 ////////////////////////////////////
	//! \brief 注册三级索引，创建索引子Lib表
	UGbool PrepareLib();

	//! \brief 通过指定图幅的大小来建立三级索引
	UGbool RegisterLibraryByGridSize(UGdouble dWidth, UGdouble dHeight);

	//! \brief 通过指定名称的字段来建立三级索引
	UGbool RegisterLibraryByField(const UGString &strFieldName);


	/////////////////////////////// R树索引的方法 ////////////////////////////////////
	
	//! \brief R树叶子节点的加载
	UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	
	//! \brief R树叶子节点的存储
	UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);


	//! \brief 编辑后对索引的更新入口, pGeometry 只在多级网格索引时传入非空，其它传入NULL
	UGbool UpdateIndexItem(UGint nID, const UGint nEditState, UGGeometry *pGeometry,
										   const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//! \brief 图幅索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool DynamicSpatialQuery(UGGeometry *pGeo, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs, 
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractLibIDs(UGGeometry *pGeo,
		UGArray<UGint> &aryLibInnerIDs, UGArray<UGint> &aryLibMaybeIDs,
		UGArray<UGGeoRegion*> &aryClipGeo, UGArray<UGGeoLine*> &aryClipLines,
		UGArray<UGint> &aryLibOuterIDs, SpatialQueryOption nOption);

	//! \brief 根据nOption，从图幅IDs aryLibIDs 中提取对象的IDs 
	//! \param aryClipRegions 被裁减过的LibTile的面对象,二维对象使用[in]
	//! \param aryClipLines 被LibTile裁减过的pGeo线对象,一维对象使用[in]
	//! \param aryLibIDs	[in]
	//! \param aryIDs	[out]
	//! \param nOption指示传入的aryLibIDs是Inner、Maybe还是Outer的	[in]
	UGbool ExtractMaybeIDsByLibIDs(UGGeometry *pGeo,UGArray<UGGeoRegion*> &aryClipRegions, 
		UGArray<UGGeoLine*> &aryClipLines,UGArray<UGint> aryLibIDs, 
		UGArray<UGint> &aryInnerIDs,UGMaybeItems &aryMaybeIDsStruct,UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractCertainIDsByLibIDs(UGArray<UGint> aryLibIDs,UGArray<UGint> &aryCertainIDs);

	//! \brief R树索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryLeafIDs  [in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	UGbool ExtractIDsByLeafIDs(UGGeometry *pGeo, UGArray<UGint> aryLeafIDs, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption);

	//网格索引空间查询
	//! \brief 网格索引空间查询:提取经过aryGrids的所有对象的ID和GX、GY
	//! \param aryGrids 网格数组[in]
	//! \param aryIDs 出来的ID是经过排序的，升序 [out]
	//! \param aryGX [out]
	//! \param aryGY [out]
	UGbool ExtractIDsByGrids(UGArray<UGPoint> &aryGrids, UGArray<UGint> &aryIDs, 
		UGArray<UGint> &aryGX,UGArray<UGint> &aryGY);

	//网格索引空间查询
	//! \brief 网格索引空间查询:提取经过aryGrids的所有对象的ID,在进行Outer查询时调用
	//! \param aryGrids 网格数组[in]
	//! \param aryIDs 出来的ID是没有经过排序，但是唯一的 [out]
	UGbool ExtractIDsByGrids(UGArray<UGPoint> &aryGrids, UGArray<UGint> &aryIDs);

	//! \brief 网格索引空间查询:去除重复ID，挑出完全Inner 的 IDs，其它是Maybe的
	//! \param pArry 相关网格的Tag数组 [in]
	//! \param nSize pArry的长度 [in]
	//! \param pntOffset网格Tag的起始点 [in]
	//! \param aryIDs [in]
	//! \param aryGX [in]
	//! \param aryGY [in]
	//! \param aryInnerIDs [out]
	//! \param aryUGMaybeIDs [out]
	UGbool FilterIDs(UGint *pArry, UGint nHeight, UGint nWidth, UGPoint pntOffset, UGArray<UGint> &aryIDs, 
		UGArray<UGint> &aryGX,UGArray<UGint> &aryGY,
		UGArray<UGint> &aryInnerIDs, UGArray<UG_MayIDs> &aryUGMaybeIDs,UGArray<UGint> &aryOuterIDs);

	//! \brief 网格索引空间查询: aryUGMaybeIDs 中是按格子分组的，对每组中的ID进行进一步判断
	//! \param pGeo 查询的空间对象 [in]
	//! \param aryUGMaybeIDs ID分组 aryUGMaybeIDs[i] 中的i表示第i个格子 [in]
	//! \param aryInnerIDs [out]
	//! \param aryMaybeIDs [out]
	//! \param aryOuterIDs [out]
	//! \param nOption [in]
	UGbool ExtractGridMaybeSubIDs(UGGeometry *pGeo, UGArray<UG_MayIDs> &aryUGMaybeIDs,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption, UGdouble dbTolerance);

	UGbool ExtractGridMaybeIDs(UGGeometry *pGeo, UGint nLevel, UGArray<UGPoint>& aryGridMaybe,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption);

	UGbool ExtractGridMaybeSubIDs(UGGeometry *pGeo,UGArray<UGPoint>& aryGridMaybe,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryOuterIDs, 
		SpatialQueryOption nOption);

	//! \brief R树索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryGridInner  [in]
	//! \param aryIDs  [out]
	UGbool ExtractGridInnerIDs(UGArray<UGPoint>& aryGridInner,UGArray<UGint> &aryIDs);
private:
	//! \brief				更新RTree索引叶节点
	// \param nID			更新的记录的ID
	// \param nEditState	对记录所作的更新操作	
	// \param rc2Org		记录原来的Bounds
	// \param rc2Des		记录新的Bounds，只在SetGeometry时rc2Org和rc2Dest不同
	// \return				更新索引的操作成功与否
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Org, const UGRect2D &rc2New);
	
	//这些在UpdateRTreeItem调用
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Org);
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Org, const UGRect2D &rc2New);

	//取得所有Geometry的ID和四至并清空R树索引表，在建立R树索引时调用
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGProgress *pProgress,UGString strSort);

	//! \brief 更新图幅索引的图幅信息
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief 更新多级网格索引
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief 更新纯四叉树索引
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief 保存索引信息
	UGbool SaveIndexInfo();

private:
	UGOrcDatasetVector *m_pDataset;
};

}
#endif // !defined(AFX_UGORCSPATIALINDEX_H__E4155113_5D24_478C_8C7D_7A9BAD348D7B__INCLUDED_)

// UGODBCSpatialIndex.h: interface for the UGODBCSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_)
#define AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ODBCEngine/UGODBCDatasetVector.h"
namespace UGC{

class UGEXPORT UGODBCSpatialIndex  
{
	friend class UGODBCDatasetVector;
	friend class UGODBCEditRecordset;
	friend class UGSqlDatasetVectorVersion;
public:
	UGODBCSpatialIndex();
	UGODBCSpatialIndex(UGODBCDatasetVector *pDT);
	virtual ~UGODBCSpatialIndex();

public:
	//! \brief 建立空间索引
	//! \param spatial[in] 创建索引需要的索引相关信息
	//! \return 成功为TRUE,否则为FALSE.
	//! \remarks
	//! \attention 
	UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief 根据当前索引状态重建索引
	//! \param
	//! \return 成功为TRUE,否则为FALSE.
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex();

	//! \brief 脏数据的空间索引更新
	//! \param
	//! \return 成功为TRUE,否则为FALSE.
	//! \remarks 
	//! \attention
	UGbool UpdateSpatialIndex();
	
	//! \brief 清除空间索引
	//! \param
	//! \return 成功为TRUE,否则为FALSE.
	//! \remarks 
	//! \attention
	UGbool DropSpatialIndex();
	
	//! \brief 是否需要重建空间索引
	//! \param
	//! \return 需要返回TRUE,否则为FALSE.
	//! \remarks 
	//! \attention
	UGbool IsSpatialIndexDirty();
	
	//! \brief 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	UGint GetDirtyRecordCount();

	//! \brief 索引分析
	//! \param
	//! \return 成功为TRUE,否则为FALSE.
	//! \remarks 
	//! \attention
	UGbool StatisticIndex(UGDataSource *pDs);

	//! \brief 图幅索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief R树索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief 多级网格索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,UGdouble dbTolerance);
	
protected:
	//以下三个方法在 BuildSpatialIndex 中调用，用于建立不同类型的索引

	//! \brief 建立R树索引
	//! \param spatial[in] 创建索引需要的索引相关信息
	//! \return 成功为TRUE,否则为FALSE.
	UGbool BuildSpatialIndexRTree(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立图幅索引
	//! \param spatial[in] 创建索引需要的索引相关信息
	//! \return 成功为TRUE,否则为FALSE.
	//! \attention 数据集范围特别大的情况下，用户自定义范围比较小有可能出现内存不够的现象
	UGbool BuildSpatialIndexTile(UGSpatialIndexInfo &spatial);
	
	//! \brief 建立多级网格索引
	//! \param spatial[in] 创建索引需要的索引相关信息
	//! \return 成功为TRUE,否则为FALSE.
	UGbool BuildSpatialIndexDynamic(UGSpatialIndexInfo &spatial);

	//! \brief 建立四叉树索引
	//! \param spatial[in] 创建索引需要的索引相关信息
	//! \return 成功为TRUE,否则为FALSE.
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
	UGbool UpdateIndexItem(UGint nID, UGint nEditState, UGGeometry *pGeometry,
									   const UGRect2D &rc2Old, const UGRect2D &rc2New);

private:
	//! \brief				更新RTree索引叶节点
	// \param nID			更新的记录的ID
	// \param nEditState	对记录所作的更新操作	
	// \param rc2Old		记录原来的Bounds
	// \param rc2New		记录新的Bounds，只在SetGeometry时rc2Old和rc2New不同
	// \return				更新索引的操作成功与否
	UGbool UpdateRTreeItem(	UGint nID, const UGint nEditState, 
						   const UGRect2D &rc2Old, const UGRect2D &rc2New);
	
	//这些在UpdateRTreeItem调用
	UGbool UpdateRTreeItemAdd(UGint nID, const UGRect2D &rc2New);
	UGbool UpdateRTreeItemDel(UGint nID, const UGRect2D &rc2Old);
	UGbool UpdateRTreeItemSetGeo(UGint nID, const UGRect2D &rc2Old, const UGRect2D &rc2New);

	//取得所有Geometry的ID和四至并清空R树索引表，在建立R树索引时调用
	void GetAllNodeItems(UGDBRTreeNodeItems &NodeItems,UGProgress &Progress,UGString strSort);

	//! \brief 更新图幅索引的图幅信息
	UGbool UpdateLibVersion(const UGuint dwLibID, const UGint nID, 
		const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief 更新多级网格索引
	UGbool UpdateDynamicIdx(UGint nID, const UGint nEditMode, UGGeometry *pGeometry);

	//! \brief 更新纯四叉树索引
	UGbool UpdateQTreeIdx(UGint nID, const UGint nEditMode, const UGRect2D &rc2New);

	//! \brief 保存索引信息
	UGbool SaveIndexInfo();

	//图幅索引空间查询函数

	//! \brief 图幅ID查询
	//! \param pGeo					面对象[in]
	//! \param aryInnerLibIDs		存储满足Inner情况的图幅ID[out]
	//! \param aryMaybeLibTileIDs	必须获取Maybe情况的图幅ID[out]
	//! \param aryOuterLibIDs		存储满足Outer情况的图幅ID[out]
	//! \param aryGeoRg				存储对应图幅裁剪的多边形[out]
	//! \param nOption				查询选项[in]
	UGbool GetQueryLibTileIDs(UGGeometry *pGeo,UGArray<UGint>& aryInnerLibIDs,
		UGArray<UGint>& aryMaybeLibTileIDs,UGArray<UGint>& aryOuterLibIDs,
		UGArray<UGGeoRegion> &aryGeoRg,SpatialQueryOption nOption);
	
	//! \brief 对象ID查询，获取Maybe情况图幅内对象ID
	//! \param pGeo					 面对象[in]
	//! \param aryMaybeLibTileIDs	 Maybe情况的图幅ID[in]
	//! \param aryGeoRg				 Maybe情况的图幅ID对应的裁剪多边形[in]
	//! \param aryMaybeInnerIDs		 存储Maybe情况图幅内满足Inner情况对象的ID[out]
	//! \param aryMaybeOuterIDs		 存储Maybe情况图幅内满足Outer情况对象的ID[out]
	//! \param aryMaybeIDs		 	 存储Maybe情况图幅内满足Maybe情况对象的ID[out]
	//! \param dbTolerance			 判断点在同一位置的容限
	UGbool GetMaybeIDsInTile(UGGeometry *pGeo,UGArray<UGint>& aryMaybeLibTileIDs,
		UGArray<UGint>& aryMaybeInnerIDs,UGArray<UGGeoRegion> &aryGeoRg,
		UGArray<UGint>& aryMaybeOuterIDs,UGMaybeItems& aryMaybeIDs,UGdouble dbTolerance);

	//! \brief 对象ID查询，获取图幅内对象ID
	//! \param aryQueryLibIDs	图幅ID[in]
	//! \param aryIDs  图幅内对象ID[out]
	UGbool GetIDsInTile(UGArray<UGint>& aryQueryLibIDs,UGArray<UGint>& aryIDs);

	//! \brief R树索引包内分组对象ID
	//! \param pGeo				面对象[in]
	//! \param aryLeafIDs		R树索引包[in]
	//! \param aryInnerIDs		存储满足inner的对象[out]
	//! \param aryMaybeIDs		存储满足maybe的对象[out]
	//! \param aryIDs			存储满足inner及outer的对象ID[out]
	UGbool GetIDsInLeaf(UGGeometry *pGeo,UGArray<UGint>& aryLeafIDs,
		UGArray<UGint>& aryInnerIDs,UGMaybeItems& aryMaybeIDs,UGArray<UGint>& aryIDs);

	//! \brief 查询四叉树管理的对象ID
	//! \param pGeo				面对象[in]
	//! \param aryInnerIDs		满足inner的对象[out]
	//! \param aryMaybeIDs		满足maybe的对象[out]
	//! \param aryIDs			存储满足inner及outer的对象ID[out]
	UGbool GetIDsInQTree(UGGeometry *pGeo,UGArray<UGint>& aryInnerIDs,UGMaybeItems& aryMaybeIDs,UGArray<UGint>& aryIDs);

	//! \brief 获取outer对象ID(取反)
	//! \param aryIDs			满足inner和maybe的对象ID[in]
	//! \param aryOuterIDs		满足outer的对象ID[out]
	UGbool GetIDsOuter(UGArray<UGint>& aryIDs,UGArray<UGint>& aryOuterIDs);

	//! \brief maybe网格内分组
	//对maybe的网格相邻的两两合并，求出裁剪多边形及网格内的对象ID(区分出maybe及inner的对象)，本身也得过滤重复的ID
	//! \param pGeo				面对象[in]
	//! \param nLevel			网格的层数[in]
	//! \param aryGridMaybe		满足maybe的网格[in]
	//! \param aryMaybeIDs		存储满足maybe的对象[out]
	//! \param aryInnerIDs		存储满足inner的对象[out]
	//! \param aryIds			存储满足maybe对象的ID[out](求反时用)
	UGbool GetMaybeGridIDs(UGGeometry *pGeo,UGint& nLevel,UGArray<UGPoint>& aryGridMaybe,
						UGMaybeItems &aryMaybeIDs,UGArray<UGint> &aryInnerIDs,UGArray<UGint> &aryIds);

// 	//! \brief	获取maybe网格内对象
// 	//! \param pGeo					面对象[in]
// 	//! \param GridPoint			网格x,y[in]
// 	//! \param aryMaybeIDs			满足maybe的对象[out]
// 	//! \param aryInnerIDs			满足inner的对象[out]
// 	UGbool GetIDsInMaybeGrid(UGGeoRegion *pGeo,UGPoint& GridPoint,
// 						UG_SQ_MAYBEIDS& aryMaybeID,UGArray<UGint>& aryInnerIDs);

	//! \brief	为传入的inner及maybe网格打标记存入到二维数组，并通过关联查询和相关算法获取过滤重复ID后inner对象ID及maybe对象ID的分组(按网格分组)
	//! \param nLevel				所在的网格层[in]
	//! \param aryGrids				查询对象经过的网格左下右上的坐标[in]
	//! \param aryGridMaybe			查询对象经过的maybe网格[in]
	//! \param aryGridInner			查询对象经过的inner网格[in]
	//! \param aryInnerIDsTemp		满足inner的对象[out]
	//! \param aryUGMaybeIDs		满足maybe的分组对象[out]
	//! \param aryouterIDs			所有outer的对象id[out]
	UGbool GetIDsFromMarkGrid(UGbool bOuter,UGint nLevel,UGArray<UGPoint>& aryGrids,UGArray<UGPoint>& aryGridMaybe,UGArray<UGPoint>& aryGridInner,
		UGArray<UGint>& aryInnerIDsTemp,UGArray<UG_MayIDs>& aryUGMaybeIDs,UGArray<UGint>& aryouterIDs);

	//! \brief	用maybe对象组裁剪多边形
	//! \param pGeo						面对象[in]
	//! \param aryUGMaybeIDs			maybe对象组[in]
	//! \param aryMaybeGirdinnerIDs		这些网格内满足inner的对象[out]
	//! \param aryMaybeGirdouterIDs		这些网格内满足outer的对象[out]
	//! \param aryMaybeIDsTemp			满足maybe的对象[out]
	UGbool MaybeIDsClipRegion(UGGeometry *pGeo,UGArray<UG_MayIDs>& aryUGMaybeIDs,UGArray<UGint>& aryMaybeGirdinnerIDs,
		UGArray<UGint>& aryMaybeGirdouterIDs,UGMaybeItems& aryMaybeIDsTemp,UGdouble dbTolerance);
	
	//! \brief	用maybe对象组裁剪多边形
	//! \param aryGridMaybe			查询对象经过的maybe网格[in]
	//! \param aryGridInner			查询对象经过的inner网格[in]
	//! \param aryOuterIDsTemp		满足outer的对象[out]
	UGbool GetIDsFromOuterGrid(UGArray<UGPoint>& aryGridMaybe,UGArray<UGPoint>& aryGridInner,UGArray<UGint>& aryOuterIDsTemp);

private:
	UGODBCDatasetVector *m_pDataset;

};
}
#endif // !defined(AFX_UGODBCSPATIALINDEX_H__1BF4DAD3_380B_41A7_9DE4_6E7914AC028C__INCLUDED_)



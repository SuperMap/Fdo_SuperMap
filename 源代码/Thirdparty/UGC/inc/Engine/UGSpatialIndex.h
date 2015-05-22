/* 
	\file UGSpatialIndex.h
	\brief	负责管理索引的一切
			包括索引的创建，重建，删除
			包括创建索引之前对数据的分析，创建索引，管理索引以及对索引的应用
			包括引擎是否支持某种索引的控制

	\author 李文龙
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
*/
	// UGSpatialIndex.h: interface for the UGSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_)
#define AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class ENGINE_API UGSpatialIndex
{
public:
	UGSpatialIndex();
	virtual ~UGSpatialIndex();

public:

	//! \brief 建立索引
	//! \param *pDataset [in]。
	//! \return
	//! \remarks
	//! \attention 
	UGbool BuildSpatialIndex(UGDatasetVector *pDataset,UGSpatialIndexInfo &spatial);

	//! \brief 根据当前索引状态重建索引
	//! \param *pDataset [in]。
	//! \return
	//! \remarks
	//! \attention 
	UGbool ReBuildSpatialIndex(UGDatasetVector *pDataset);

	//! \brief 脏数据的空间索引更新
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool UpdateSpatialIndex(UGDatasetVector *pDataset);

	//! \brief 删除索引
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool DropSpatialIndex(UGDatasetVector *pDataset);

	//! \brief 分析当前的索引，把分析结果放在系统信息统计表里
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool StatisticIndex(UGDatasetVector *pDataset);
	
	//! \brief 当前数据集是否此索引支持
	//! \param *pDataset [in]。
	//! \param nIdxType [in]。
	//! \return 
	//! \remarks 
	//! \attention 
	UGbool IsSupported(UGDatasetVector *pDataset,IndexType nIdxType);

	//! \brief 索引是否赃了
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks TRUE 表示脏；否则，不脏
	//! \attention 。
	UGbool IsSpatialIndexDirty(UGDatasetVector *pDataset);

public:
	UGbool AnalyzeDataset(UGDatasetVector *pDataset,UGSpatialIndexInfo &info);

	UGshort RecommendSpatialIndexLevel(UGDatasetVector *pDataset);

protected:
	UGbool IsNeedBuiltIndex(UGDatasetVector *pDataset);

private:
	UGbool ConfigIndexByDataDistributing(UGDatasetVector *pDataset,UGSpatialIndexInfo &info);
};
}

#endif // !defined(AFX_UGSPATIALINDEX_H__AAA6D3A9_BE41_415A_8BB9_122FF427F2D0__INCLUDED_)

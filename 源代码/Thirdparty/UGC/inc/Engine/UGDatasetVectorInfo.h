/*! \file	 UGDatasetVectorInfo.h
 *  \brief	 矢量数据集信息定义
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVectorInfo.h,v 1.14 2007/10/19 08:20:43 liwl Exp $
 */

#ifndef UGDATASETVECTORINFO_H
#define UGDATASETVECTORINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "UGDataset.h"

namespace UGC {

//! 空间索引
enum IndexType
{
	IdxNone		= 1,		//没有索引
	IdxRTree	= 2,		//Rtree索引
	IdxQTree	= 3,		//四叉树索引
	IdxTile		= 4,		//图幅索引 UGC里不支持编辑
	IdxDynamic  = 5,		//multi-level Grid
};


//! 矢量数据集信息类
class ENGINE_API UGDatasetVectorInfo  
{
public:
	//! 构造函数
	UGDatasetVectorInfo();
	//! 析构函数
	~UGDatasetVectorInfo();

	void SetToleranceToDefault();

	//! 得到当前的索引类型
	UGint GetIndexType(){return m_nIndexType;};
	void SetIndexType(IndexType nIdxType){m_nIndexType = nIdxType;};

public:
	//! 数据集名称
	UGString m_strName;

	//! 数据集类型
	UGDataset::DatasetType m_nType;

	//! 选项信息
	UGint m_nOptions;
	
	//! 对象个数
	UGint m_nObjectCount;

	//! 索引类型 
	UGint	m_nIndexType;
	
	//! 网格索引标志
	UGint	m_nDynamicIndex;
	
	//! 网格索引专用参数
	UGPoint2D m_pntIdxCenter;
	UGdouble  m_dbGridRatio;
	UGdouble  m_dbdGrid0;
	UGdouble  m_dbdGrid1;
	UGdouble  m_dbdGrid2;
		
	//! 空间索引层数
	UGint m_nSpatialIndexLevel;
		
	//! 数据集的Bounds
	UGRect2D m_rc2Bounds;

	//! 三维Bounds的最小值
	UGdouble m_dMinZ;

	//! 三维Bounds的最大值
	UGdouble m_dMaxZ;
	
	//! 数据集中索引所设置的Bounds
	UGRect2D m_rc2IndexedBounds;	

	//! 以下的容限为建立拓扑关系、编辑时使用
	//UGdouble m_dToleranceFuzzy;
	UGdouble m_dToleranceExtend;
	UGdouble m_dToleranceDangle;
	UGdouble m_dToleranceNodeSnap;
	UGdouble m_dToleranceSmallPolygon;
	UGdouble m_dToleranceGrain;

	//! Tin数据集里，金字塔层使用
	UGdouble m_dTinTolerance;

	//! 长事务、锁定　及状态
	UGint m_nCheckedUserID;
	UGint m_nLockedUserID;
	UGint m_nState;

	//! 数据编码类型
	UGint m_nCodecType;	

	UGString m_strDescription;	//对数据集的描述信息
};

}

#endif


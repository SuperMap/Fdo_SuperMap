// UGQuadGridSet.h: interface for the UGQuadTileGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_)
#define AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Base/UGThread.h"
#include "Scene/UGQuadGrid.h"
#include "Base/UGDict.h"
#include "Scene/UGVectorDatasetAtr.h"
namespace UGC
{
class UGDataset;
//! \brief 管理四叉树第0层根节点的类 
//! \remarks 备注信息
class SCENE_API SyncTopGridMap
{
public:
	SyncTopGridMap(){};
	virtual ~SyncTopGridMap(){};
	void inline Lock(){m_mutex.lock();}
	void inline Unlock(){m_mutex.unlock();}

public:
	UGDict<UGlong,UGQuadGrid*> m_Dict;	
protected:
	UGMutex m_mutex;	
};

//! \brief 管理四叉树的类
//! \remarks 
class SCENE_API UGQuadGridSet:public UGRenderable, public UGMovableObject
{
public:
	//! \brief 构造函数
	UGQuadGridSet();	
	virtual ~UGQuadGridSet();
public:	
	//! \brief 得到计算LOD的参数因子TileDrawDistance
	UGfloat GetTileDrawDistance();
	//! \brief 设置计算LOD的参数因子TileDrawDistance
	void SetTileDrawDistance(UGfloat value);
	//! \brief 得到计算LOD的参数因子TileDrawSpread
	UGfloat GetTileDrawSpread();
	//! \brief 设置计算LOD的参数因子TileDrawSpread
	void SetTileDrawSpread(UGfloat value);
	//! \brief 得到全球统一格网所使用的球体半径
	UGdouble GetGlobalRadius();
	//! \brief 设置全球统一格网所使用的球体半径
	void SetGlobalRadius(UGdouble dRadius);
	//! \brief 得到全球统一格网的最大层数
	UGint GetMaxLevel();
	//! \brief 设置全球统一格网的最大层数
	void SetMaxLevel(UGint nMaxLevel);
	UGList<UGVectorDatasetAtr>& GetDatasetList();
	void AddDataset(const UGVectorDatasetAtr& pDataset);
	UGbool IsDatasetExist(const UGString& strName);
	void RemoveDataset(const UGString& strName);
	UGbool GetDataset(const UGString& strName,UGVectorDatasetAtr& atr);

 
	//! \brief 得到四叉树原始数据块的北边界
	UGReal GetNorth();
	//! \brief 得到四叉树原始数据块的东边界
	UGReal GetEast();
	//! \brief 得到四叉树原始数据块的南边界
	UGReal GetSouth();
	//! \brief 得到四叉树原始数据块的西边界
	UGReal GetWest();
	//! \brief 继承自可渲染对象的函数
	virtual void Initialize();
	//! \brief 继承自可渲染对象的函数，负责数据的选择
	virtual UGbool PerformSelectionAction();
	//! \brief 继承自可渲染对象的函数，负责块数据的更新
	virtual void Update();
	//! \brief 继承自可渲染对象的函数，负责数据的渲染
	virtual void Render();
	//! \brief 继承自可渲染对象的函数，负责数据的释放
	virtual void Release();
	virtual void ResetCacheForCurrentView(UGMomentumCamera* pCamera);
	//! \brief 将四叉树顶层不可见快从渲染队列中删除
	void RemoveInvisibleTiles(UGMomentumCamera* pCamera);
	

protected:	
	//! \brief 四叉树第0层每块经纬度间隔
	UGdouble m_dL0TileSizeDeg;
	//! \brief 四叉树LOD计算因子TileDrawDistance
	UGfloat m_fTileDrawDistance;
	//! \brief 四叉树LOD计算因子TileDrawSpread
	UGfloat m_fTileDrawSpread;
	//! \brief 四叉树第0层根节点的管理对象
	SyncTopGridMap	m_TopmostTiles;
	//! \brief 
	UGlong m_lLastRenderTime;
	//! \brief 全球统一格网最大层数
	UGint m_nMaxLevel;
	//! 半径
	UGdouble m_dGlobalRadius;
	UGList<UGVectorDatasetAtr>m_DatasetList;
};
}

#endif // !defined(AFX_UGQUADTILEGRID_H__504F4C12_5DDB_4816_A901_3A197F2383F7__INCLUDED_)

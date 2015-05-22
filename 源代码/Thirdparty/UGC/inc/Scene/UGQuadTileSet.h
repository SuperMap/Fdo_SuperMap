/* 
	\file UGQuadTileSet.h
	\brief 管理四叉树的类文件 
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/



#if !defined(AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_)
#define AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "scene/UGImgAccessor.h"
#include "Base/UGThread.h"

namespace UGC
{
//! \brief 管理四叉树第0层根节点的类 
//! \remarks 备注信息
class SCENE_API SyncTopTilesMap
{
public:
	SyncTopTilesMap(){};
	virtual ~SyncTopTilesMap(){};
	void inline Lock(){m_mutex.lock();}
	void inline Unlock(){m_mutex.unlock();}

public:
	UGDict<UGlong,UGQuadTile*> m_Dict;	
protected:
	UGMutex m_mutex;	
};

//! \brief 管理四叉树的类
//! \remarks 
class SCENE_API UGQuadTileSet : public UGRenderObject
{
public:
	//! \brief 构造函数
	UGQuadTileSet();	
	//! \brief 构造函数
	UGQuadTileSet(const UGString& strName);	
	 
 
	//! \brief  构造函数
	//! \param name [in] 可渲染对象的名称
	//! \param distanceAboveSurface [in]距离球面的高度
	//! \param north [in]四叉树原始数据块的北边界
	//! \param south [in]四叉树原始数据块的南边界
	//! \param west [in]四叉树原始数据块的西边界
	//! \param east [in]四叉树原始数据块的东边界
	//! \param dL0TileSizeDeg [in]四叉树第0层的经纬度跨度
	//! \param *pImgAccessor [in]四叉树影响贴图数据的获取对象
	UGQuadTileSet(
	const UGString& name,		
	UGdouble distanceAboveSurface,
	UGdouble north,
	UGdouble south,
	UGdouble west,
	UGdouble east,
	UGdouble dL0TileSizeLatDeg,
	UGdouble dL0TileSizeLonDeg,
	UGImgAccessor *pImgAccessor
	);
	//! \brief  析构函数
	virtual ~UGQuadTileSet();

public:	
	//! \brief 得到该四叉树层的半径
	UGdouble GetLayerRadius();	
	//! \brief 得到该四叉树影响贴图对象
	UGImgAccessor *GetImgAccessor();
	//! \brief 得到计算LOD的参数因子TileDrawDistance
	UGdouble GetTileDrawDistance();
	//! \brief 设置计算LOD的参数因子TileDrawDistance
	void SetTileDrawDistance(UGdouble value);
	//! \brief 得到计算LOD的参数因子TileDrawSpread
	UGdouble GetTileDrawSpread();
	//! \brief 设置计算LOD的参数因子TileDrawSpread
	void SetTileDrawSpread(UGdouble value);
	/*
	//! \brief 暂时无用
	UGbool GetbRenderStruts();
	//! \brief 暂时无用
	void SetbRenderStruts(UGbool value);
	//! \brief  
	*/
	UGbool GetbAlwaysRenderBaseTiles();
	//! \brief  
	void SetbAlwaysRenderBaseTiles(UGbool value);
	//! \brief 得到描述每块网格每行的点数
	UGint GetElevatedVertexCount();
	//! \brief 得到描述每块网格索引数目
	UGint GetElevatedVertexIndiceCount();
	//! \brief 得到描述每块网格索引数组，因每块都相同，所以这些数据被所有块共享
	UGushort *GetElevatedVertexIndexData();
	UGbool GetElevationAt(UGdouble dLon, UGdouble dLat, UGdouble &dZ);

	 

protected:
	//! \brief 得到四叉树原始数据块的北边界
	UGdouble GetNorth();
	//! \brief 得到四叉树原始数据块的东边界
	UGdouble GetEast();
	//! \brief 得到四叉树原始数据块的南边界
	UGdouble GetSouth();
	//! \brief 得到四叉树原始数据块的西边界
	UGdouble GetWest();
	//! \brief 得到四叉树块集的半径
	void SetLayerRadius(UGdouble value);	
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
	//! \brief 初始化块的索引数组
	void InitVertexIndexArray();

protected:	
	//! \brief 四叉树原始数据块的北边界
	UGdouble m_dNorth;
	//! \brief 四叉树原始数据块的南边界
	UGdouble m_dSouth;
	//! \brief 四叉树原始数据块的西边界
	UGdouble m_dWest;
	//! \brief 四叉树原始数据块的东边界
	UGdouble m_dEast;
	//! \brief 四叉树原始数据块的球半径
	UGdouble m_dLayerRadius;
	//! \brief 四叉树第0层每块经纬度间隔
	UGdouble m_dL0TileSizeLatDeg;
	//! \brief 四叉树第0层每块经纬度间隔
	UGdouble m_dL0TileSizeLonDeg;
	//! \brief 四叉树LOD计算因子TileDrawDistance
	UGdouble m_fTileDrawDistance;
	//! \brief 四叉树LOD计算因子TileDrawSpread
	UGdouble m_fTileDrawSpread;
	//! \brief 四叉树每块影响纹理的加载管理对象
	UGImgAccessor *m_pImgAccessor;
	//! \brief 四叉树第0层根节点的管理对象
	SyncTopTilesMap	m_TopmostTiles;
	//! \brief 
	UGlong m_lLastRenderTime;
	//! \brief 描述每块网格每行的点数
	UGint m_nElevatedVertexCount;
	//! \brief 描述每块网格索引数目
	UGint m_nElevatedVertexIndiceCount;	
	//! \brief 描述每块网格索引数据
	UGushort* m_pElevatedVertexIndex;	
	
};
}
#endif // !defined(AFX_UGQUADTILESET_H__204A8275_7394_4378_97CF_6245678A5ED3__INCLUDED_)

       
  
         
       
 
 
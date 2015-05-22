// UGTerrainAccessor.h: interface for the UGTerrainAccessor class.
/* 
	\file UGTerrainAccessor.h
	\brief 地形获取器头文件
	\author 马柳青、张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_)
#define AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"

namespace UGC
{

//! \brief 地形获取器，管理地形块和地形块缓存。
class SCENE_API UGTerrainAccessor  
{
public:
	//! \brief 构造函数。
	UGTerrainAccessor();
	//! \brief 析构函数。
	virtual ~UGTerrainAccessor();
	
public:
	//! \brief 获取指定范围的地形块。
	//! \param north 北边界[in]。
	//! \param south 南边界[in]。
	//! \param west 西边界[in]。
	//! \param east 东边界[in]。
	//! \param samples 分辨率[in]。
	//! \return 地形块。
	UGTerrainTile* GetTerrainTile(UGdouble north, UGdouble south, 
		UGdouble west, UGdouble east, UGint samples);	

	//! \brief 设置地形服务。
	//! \param serverUrl 获取地形的服务URL地址[in]。	
	//! \param levelZeroTileSizeDegrees 第0层每块的度数[in]。
	//! \param samplesPerTile 每块分辨率[in]。
	//! \param fileExtension 数据扩展名[in]。
	//! \param numberLevels 层数[in]。
	//! \param terraintileDirectory 地形数据本地存储目录[in]。
	//! \param dataType 地形数据类型[in]。
	void AddTerrainTileServer(const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);	
	UGbool GetElevationAt(UGdouble dLon,UGdouble dLat,UGdouble dSamplesPerDegree,UGdouble& dElevation);

protected:			
	//! \brief 把地形块缓存接口加入到缓存列表。
	//! \param pttce 地形块缓存接口[in]。
	void AddToCache(UGTerrainTileCacheEntry* pttce);
protected:	
	//! \brief 地形数据服务。
	UGTerrainTileServer* m_pTerrainTileServer;
	//! \brief 地形数据缓存接口列表。
	UGList<UGTerrainTileCacheEntry*> m_TileCache;
	//! \brief 地形数据缓存数目最大值。
	UGint m_stCacheSize;
	UGMutex m_mutex;
};

typedef UGArray<UGTerrainAccessor*> UGTerrainAccessorArray;
}
#endif // !defined(AFX_UGTERRAINACCESSOR_H__097390C2_3F90_4628_85CA_1EFC7BACCFC5__INCLUDED_)

// UGTerrainManager.h: interface for the UGTerrainManager class.
/* 
	\file UGTerrainManager.h
	\brief 地形管理器头文件。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_)
#define AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGSingleton.h"
#include "Scene/UGTerrainAccessor.h"

namespace UGC
{
//! \brief 地形管理器，单件模式。	
//! \remarks 可以支持多层地形数据。
class SCENE_API UGTerrainManager : public UGSingleton<UGTerrainManager>
{
public:
	//! \brief 构造函数。
	UGTerrainManager();
	//! \brief 析构函数。
	virtual ~UGTerrainManager();

public:
	//! \brief 获取指定范围的地形块。
	//! \param north 北边界[in]。
	//! \param south 南边界[in]。
	//! \param west 西边界[in]。
	//! \param east 东边界[in]。
	//! \param samples 分辨率[in]。
	//! \return 地形块。
	UGTerrainTile *GetTerrainTile(UGdouble north, UGdouble south, 
		UGdouble west, UGdouble east, UGint samples);
		
	//! \brief 设置地形服务。
	//! \param serverUrl 获取地形的服务URL地址[in]。	
	//! \param levelZeroTileSizeDegrees 第0层每块的度数[in]。
	//! \param samplesPerTile 每块分辨率[in]。
	//! \param fileExtension 数据扩展名[in]。
	//! \param numberLevels 层数[in]。
	//! \param terraintileDirectory 地形数据本地存储目录[in]。
	//! \param dataType 地形数据类型[in]。
	void AddTerrainAccessor(const UGString& serverUrl,
		UGdouble levelZeroTileSizeDegrees,
		UGint samplesPerTile,
		const UGString& fileExtension,
		UGint numberLevels,
		const UGString& terraintileDirectory,
		const UGString& dataType,UGdouble dNorth=PI/2,UGdouble dSouth=-PI/2, UGdouble dWest=-PI, UGdouble dEast=PI);
	UGdouble GetElevationAt(UGdouble dLon, UGdouble dLat, UGdouble dSamplesPerDegree);
public:	
	//! \brief 单件模式获取接口。
	static UGTerrainManager& GetSingleton();

protected:
	//! \brief 地形获取器接口数组。
	UGTerrainAccessorArray m_TerrainAccessorArray;
};
}
#endif // !defined(AFX_UGTERRAINMANAGER_H__81D06E1A_2C75_47B1_8A61_54623AD0C0C8__INCLUDED_)

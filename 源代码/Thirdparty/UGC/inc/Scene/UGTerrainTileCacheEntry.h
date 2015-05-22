// UGTerrainTileCacheEntry.h: interface for the UGTerrainTileCacheEntry1 class.
/* 
	\file UGTerrainTileCacheEntry.h
	\brief 地形块缓存接口头文件。
	\author 马柳青、张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/	
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_)
#define AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_
#include "Scene/UGPrerequisites.h"

namespace UGC
{

//! \brief 地形块缓存接口。
class SCENE_API UGTerrainTileCacheEntry
{
public:
	//! \brief 构造函数。
	UGTerrainTileCacheEntry();	
	//! \brief 构造函数。
	//! \param pTile 地形块[in]。
	UGTerrainTileCacheEntry(UGTerrainTile* pTile);
	//! \brief 析构函数。
	~UGTerrainTileCacheEntry();	

public:
	//! \brief 获取地形块指针。
	//! \return 地形块指针。
	UGTerrainTile* GetTerrainTile();	
	//! \brief 传入的文件名与本地形块缓存的文件比较。
	//! \param strPath 文件名[in]。
	//! \return 0 为相同；其它为不同。
	UGint ComparePath(const UGString& strPath);	
	//! \brief 传入的缓存接口与本缓存接口的访问时间比较。
	//! \param pEntry 缓存[in]。
	//! \return 0 为相同；其它为不同。
	UGdouble CompareAccessTime(UGTerrainTileCacheEntry* pEntry);	
	//! \brief 设置本缓存接口的最后访问时间。
	//! \param dLassAccess 访问时间[in]。
	void SetLastAccess(UGdouble dLassAccess );	

protected:
//	UGint ComparePath(UGTerrainTileCacheEntry* pEntry);		
	//! \brief 获取最后访问时间。
	//! \return 最后访问时间。
	UGdouble GetLastAccess();		

protected:
	//! \brief 最后访问时间。
	UGdouble m_dLastAccess;
	//! \brief 地形块指针。
	UGTerrainTile* m_pTerrainTile;
};
}
#endif // !defined(AFX_UGTERRAINTILECACHEENTRY_H__8B84FC9C_2875_4D4C_923A_56D664F49986__INCLUDED_)

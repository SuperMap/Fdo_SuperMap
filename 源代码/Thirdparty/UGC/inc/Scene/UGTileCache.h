// UGTileCache.h: interface for the UGTileCache class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_)
#define AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include"Base/UGThread.h"

namespace UGC
{
class UGVeTile;
class SCENE_API UGTileCacheEntry
{
public:
	//! \brief 构造函数。
	UGTileCacheEntry();	
	//! \brief 构造函数。
	//! \param pTile 地形块[in]。
	UGTileCacheEntry(UGVeTile* pTile);
	//! \brief 析构函数。
	~UGTileCacheEntry();	
public:
	//! \brief 获取地形块指针。
	//! \return 地形块指针。
	UGVeTile* GetTile();	
	//! \brief 传入的文件名与本地形块缓存的文件比较。
	//! \param strPath 文件名[in]。
	//! \return 0 为相同；其它为不同。
	UGbool IsEqual(UGint nRow,UGint nCol,UGint nLevel);	
	//! \brief 传入的缓存接口与本缓存接口的访问时间比较。
	//! \param pEntry 缓存[in]。
	//! \return 0 为相同；其它为不同。
	UGdouble CompareAccessTime(UGTileCacheEntry* pEntry);	
	//! \brief 设置本缓存接口的最后访问时间。
	//! \param dLassAccess 访问时间[in]。
	void SetLastAccess(UGdouble dLassAccess );	
	
protected:
	//	UGint ComparePath(UGTileCacheEntry* pEntry);		
	//! \brief 获取最后访问时间。
	//! \return 最后访问时间。
	UGdouble GetLastAccess();		
	
protected:
	//! \brief 最后访问时间。
	UGdouble m_dLastAccess;
	//! \brief 地形块指针。
	UGVeTile* m_pTile;
};

class SCENE_API UGTileCache  
{
public:
	UGTileCache();
	virtual ~UGTileCache();
	// 添加任意快到缓存，必循先先去搜索，按时间先后插入的缓存的合适位置
	void AddTileToCache(UGTileCacheEntry* pTce);
	// 将最近访问的块添加的缓存，不需要搜索，注意这个会直接添加的缓存的头部，因为最近访问，所以时间最新
	void AddRecentTileToCache(UGTileCacheEntry* pTce);
	void AddRecentTileToCache(UGVeTile* pTile);
	void ClearCache();
	// 清除缓存中所有块
	// 在缓存中找到该Tile,并且修改其访问时间，并且按时间排序
	UGVeTile* AskCacheTile(UGint nRow, UGint nCol, UGint nLevel);
	//  只负责查找，不排序
	UGVeTile* FindCacheTile(UGint nRow, UGint nCol, UGint nLevel);
	void Lock(){m_Mutex.lock();}
	void UnLock(){m_Mutex.unlock();}
	void DelNoUseTile();
	inline UGbool IsFull(){return m_CacheTileList.GetCount()>m_nCacheSize;}
	inline UGbool IsMore(){return m_CacheTileList.GetCount()>m_nCacheSize>>1;}
	
	/*
	void inline Lock(){m_Mutex.lock();}
	void inline Unlock(){m_Mutex.unlock();}
	void inline AddRenderQueueTail(UGVeTile* pTile);
	void inline AddRenderQueueHead(UGVeTile* pTile);
	// 注意这里不删除，数据时保存到缓存中的
	void ClearRenderQueue();
	//UGbool FindRenderQueueTile(UGint nRow,UGint nCol,UGint nLevel);
	void Render();
	*/
private:
	UGint  m_nCacheSize;
	UGList<UGTileCacheEntry*> m_CacheTileList;
	UGMutex m_Mutex;
	// 这个是每次渲染的块 
	//UGList<UGVeTile*> m_RenderQueue;	
 

};

}

#endif // !defined(AFX_UGTILECACHE_H__A9135BF6_F75F_4F47_BFDA_9C7A5F1E420E__INCLUDED_)

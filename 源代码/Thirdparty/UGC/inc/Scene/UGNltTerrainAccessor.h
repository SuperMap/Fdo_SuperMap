// UGNltTerrainAccessor.h: interface for the UGNltTerrainAccessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGNLTTERRAINACCESSOR_H__6DE7C296_07BF_4C6A_8F92_9E1005193D52__INCLUDED_)
#define AFX_UGNLTTERRAINACCESSOR_H__6DE7C296_07BF_4C6A_8F92_9E1005193D52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGTerrainAccessor.h"
#include "Scene/UGTerrainTile.h"

namespace UGC
{

class UGTerrainTileServer;

class SCENE_API UGTerrainTileCacheEntry
{
 public:
	 UGTerrainTileCacheEntry()
	{
		m_pTerrainTile = NULL;
		m_dLastAccess=clock();
	}
	UGTerrainTileCacheEntry(UGTerrainTile* pTile)
	{
		m_pTerrainTile = pTile;
		m_dLastAccess=clock();
	}
	 ~UGTerrainTileCacheEntry()
	{
		 if (m_pTerrainTile!=NULL) 
		 {
			 delete m_pTerrainTile;
			 m_pTerrainTile=NULL;
		 }
	 
		 
	}
	UGTerrainTile* GetTerrainTile()
	{
		return m_pTerrainTile;
	}
	void SetTerrainTile(UGTerrainTile* pTile)
	{
		if (m_pTerrainTile!=NULL) 
		{
			delete m_pTerrainTile;
		}
		m_pTerrainTile=pTile;
	}
	UGint ComparePath(const UGString& strPath)
	{
		if ( m_pTerrainTile==NULL|| m_pTerrainTile->m_strTileFilePath.GetLength()!=strPath.GetLength()) 
		{
				return -1;
		}
		else
		{
			UGint nLength=strPath.GetLength();
			for(UGint i=0;i<nLength;i++)
			{
				if (m_pTerrainTile->m_strTileFilePath[nLength-i-1]!=strPath[nLength-i-1]) 
				{
					return m_pTerrainTile->m_strTileFilePath[nLength-i-1]-strPath[nLength-i-1];
				}
			}
			return 0;
		}

	}
	UGint ComparePath(UGTerrainTileCacheEntry* pEntry)
	{
		if (pEntry==NULL||pEntry->GetTerrainTile()==NULL)
		{
			return -1;
		}
		  
		// 不用UGString的比较，因为我们的文件可能就后面的文件名不一样,从后面开始比较
		 return ComparePath(pEntry->GetTerrainTile()->m_strTileFilePath);

	}
	UGdouble CompareAccessTime(UGTerrainTileCacheEntry* pEntry)
	{
		if (pEntry==NULL || m_pTerrainTile==NULL ||pEntry->GetTerrainTile()==NULL)
		{
			return -1;
		}
		return m_dLastAccess-pEntry->GetLastAccess();
	}
	UGdouble GetLastAccess()
	{
		return m_dLastAccess;
	}
	void SetLastAccess(UGdouble dLassAccess )
	{
		m_dLastAccess=dLassAccess;
	}
private:
	UGdouble m_dLastAccess;
	UGTerrainTile* m_pTerrainTile;

};
/*
class SCENE_API UGTileCacheNode
{
public:
	UGTileCacheNode()
	{
		m_strTilePath="";
		m_pTerrianTileCacheEntry=NULL;

	}
	UGTileCacheNode(const UGString strPath,UGTerrainTileCacheEntry* pNode)
	{
		m_strTilePath=strPath;
		m_pTerrianTileCacheEntry=pNode;

	}
	~UGTileCacheNode()
	{
		if (m_pTerrianTileCacheEntry!=NULL) 
		{
			delete m_pTerrianTileCacheEntry;

		}
	}
	UGString GetTileFilePath()
	{
		return m_strTilePath;
	}
	void SetTileFilePath(const UGString& strPath)
	{
		m_strTilePath=strPath;

	}
	UGTerrainTileCacheEntry* GetTileCacheEntry()
	{
		return m_pTerrianTileCacheEntry;
	}
	void SetTileCacheEntry(UGTerrainTileCacheEntry* pTerrianTileCacheEntry)
	{
		if (m_pTerrianTileCacheEntry!=NULL) 
		{
			delete m_pTerrianTileCacheEntry;
		}
		m_pTerrianTileCacheEntry=pTerrianTileCacheEntry;
	}
private:
	UGString m_strTilePath;
	UGTerrainTileCacheEntry* m_pTerrianTileCacheEntry;
};
*/

class SCENE_API UGNltTerrainAccessor:public UGTerrainAccessor  
{
public:
	UGNltTerrainAccessor();
	UGNltTerrainAccessor(const UGString& name, UGdouble west, UGdouble south, UGdouble east, UGdouble north,
										   UGTerrainTileServer* pTerrainTileServe, UGTerrainAccessorArray* pHigherResSubsetsArry);
	virtual ~UGNltTerrainAccessor();
	virtual UGfloat GetElevationAt(UGdouble latitude, UGdouble longitude, UGdouble targetSamplesPerDegree);
	virtual UGfloat GetElevationAtCacheFirst(UGdouble latitude, UGdouble longitude, UGdouble targetSamplesPerDegree);
	virtual UGfloat GetElevationAt(UGdouble latitude, UGdouble longitude);
	virtual UGTerrainTile* GetElevationArray(UGdouble north, UGdouble south, UGdouble west, UGdouble east,UGint samples);
	virtual void AddToCache(UGTerrainTileCacheEntry* pttce);
	UGTerrainAccessor* operator[](UGint index) const;
	UGTerrainTileServer* GetTerrainTileServer();
	void SetTerrainTileServer(UGTerrainTileServer* pTerrainTileServer);
	UGTerrainAccessorArray* GetTerrainTileAccessorArry();
	void SetTerrainTileAccessorArry(UGTerrainAccessorArray* pTerrainTileAccessorArry);

public:
	static UGint m_stCacheSize;
protected:
	 UGTerrainTileServer* m_pTerrainTileServer;
	 UGTerrainAccessorArray* m_pHigherResSubsetsArry;
	 UGList<UGTerrainTileCacheEntry*> m_TileCache;
};
}
#endif // !defined(AFX_UGNLTTERRAINACCESSOR_H__6DE7C296_07BF_4C6A_8F92_9E1005193D52__INCLUDED_)

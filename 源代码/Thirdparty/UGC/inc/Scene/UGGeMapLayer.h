// UGGeMapLayer.h: interface for the UGGeMapLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEMAPLAYER_H__6A281167_C9DD_484A_A88B_8B09B09C135A__INCLUDED_)
#define AFX_UGGEMAPLAYER_H__6A281167_C9DD_484A_A88B_8B09B09C135A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "scene/UGImgAccessor.h"
#include "Base/UGThread.h"
#include "Base/UGFile.h"
#include "Base/UGToolkit.h"
#include "Base/UGList.h"
#include "Scene/UGTileCache.h"
#include "Scene/UGScene.h"
#include "Scene/UGCameraBase.h"
#include "Scene/UGMathEngine.h"
namespace UGC
{

	//static extern IntPtr pj_init(UGint argc, string[] args);
	//static extern string pj_free(IntPtr projPJ);
	//static extern UV pj_fwd(UV uv, IntPtr projPJ);
//static extern UV pj_inv(UV uv, IntPtr projPJ);
class UGGeMapLayer;
class SCENE_API UGVeTile 
{
public:
	UGVeTile();
	virtual ~UGVeTile();
	UGVeTile(UGint nRow, UGint nCol, UGint nLevel,UGGeMapLayer* pQuadTileSet);
	UGbool IsNeeded();
	void SetNeeded(UGbool bNeeded);
	UGbool IsEqual(UGint nRow, UGint nCol, UGint nLevel);
	void CreateMesh();
	void Release();
	void Render();
	void Initialize();
	UGbool IsInitialized(){return m_bInitialized;};
	UGint GetLevel(){return m_nLevel;};
	UGint GetRow(){return m_nRow;};
	UGint GetCol(){return m_nCol;};
	UGbool IsGrandSon(UGint nRow, UGint nCol, UGint nLevel)
	{
		UGint nCount=(m_nLevel-nLevel);
		if (nCount>0 && nRow==m_nRow>>nCount && nCol==m_nCol>>nCount)
		{
			return TRUE;
		}

		return FALSE;
	}
 
public:
	// UpperLeft
	UV m_ul;
	UV m_ur;
	// LOWERLEFT
	UV m_ll;
	UV m_lr;

	UGdouble m_dNorth;
	UGdouble m_dSouth;
	UGdouble m_dWest;
	UGdouble m_dEast;
	UGdouble m_dVertEx;
	UGBoundingBox m_BoundingBox;
private:
	UGint m_nRow;
	UGint m_nCol;
	UGint m_nLevel;
	UGbool m_bNeeded;
	UGTexture* m_pTexture;
	UGGeMapLayer* m_pQuadTileSet;
	UGRenderOperation* m_pRo; 
	UGbool m_bInitialized;
	UGMutex m_mutex;
};
struct ThreeID 
{
	UGint m_nRow;
	UGint m_nCol;
	UGint m_nLevel;
	ThreeID(UGint nRow,UGint nCol,UGint nLevel)
	{
		m_nRow=nRow;
		m_nCol=nCol;
		m_nLevel=nLevel;

	}
};

class SCENE_API SyncVeTileList
{
public:
	SyncVeTileList(){};
	virtual ~SyncVeTileList(){Clear();};
	void  Lock(){m_Mutex.lock();}
	void  Unlock(){m_Mutex.unlock();}
	inline UGint  GetCount(){return m_list.GetCount();};
	inline UGList<UGVeTile*>::POSITION GetHeadPosition(){return m_list.GetHeadPosition();};
	inline  UGVeTile* GetNext(UGList<UGVeTile*>::POSITION& pos){return m_list.GetNext(pos);};
	void  AddTile(UGVeTile* pTile)
	{
		m_Mutex.lock();

		UGVeTile* pCurTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
			pCurTile=m_list.GetNext(pos);
			if (pTile->IsEqual(pCurTile->GetRow(),pCurTile->GetCol(),pCurTile->GetLevel()))
			{
				m_Mutex.unlock();
				return;
			}
			if (pTile->GetLevel()<pCurTile->GetLevel())
			{
				break;
			}
			
		}
		if (m_list.IsEOF(pos) ) 
		{
			m_list.AddTail(pTile);
		}
		else
		{
			m_list.InsertBefore(pos,pTile);
		}
		m_Mutex.unlock();
		 
	}
	void  AddTail(UGVeTile* pTile)
	{
		m_Mutex.lock();
		pTile->SetNeeded(TRUE);
		m_list.AddTail(pTile);
		m_Mutex.unlock();
	}
	void inline AddHead(UGVeTile* pTile)
	{
		m_Mutex.lock();
		pTile->SetNeeded(TRUE);
		m_list.AddHead(pTile);
		m_Mutex.unlock();
	}
	// 注意这里不删除，数据时保存到缓存中的
	void Clear()
	{
		m_Mutex.lock();
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
			pTile=m_list.GetNext(pos);
			pTile->SetNeeded(FALSE);
		}
		m_list.RemoveAll();
		m_Mutex.unlock();
	}
	// 注意这里不删除，数据时保存到缓存中的
	UGbool FindTile(UGint nRow,UGint nCol,UGint nLevel)
	{
	 
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
			pTile=m_list.GetNext(pos);
			if (pTile->IsEqual(nRow,nCol,nLevel))
			{
				return TRUE;
			}
			 
		}
		return FALSE;
	}
	void Render(UGCameraBase* pActiveCamera)
	{
		m_Mutex.lock();
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
			pTile=m_list.GetNext(pos);
			//if(pActiveCamera->IsVisible(pTile->m_BoundingBox))
			pTile->Render();
		}
		m_Mutex.unlock();
	}
	UGbool IsAllChildrenExist(UGint nRow,UGint nCol,UGint nLevel)
	{
		UGVeTile* pTile=NULL;
		UGint nChildNum=0;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
			
			pTile=m_list.GetNext(pos); 
			if (nLevel==pTile->GetLevel()-1 && nRow ==pTile->GetRow()>>1 && nCol ==pTile->GetCol()>>1)
			{
				if(pTile->IsInitialized())
				{
					nChildNum++;
					// 如果四个弟兄都找到
					if (nChildNum==4)
					{
						return TRUE;
					}
					
				}
				else
				{
					return FALSE;
				}
				
			}
		}
		return FALSE;

	}
	UGbool FindBrother(UGint nRow,UGint nCol,UGint nLevel,UGbyte* pFlg)
	{
		
		 
		UGVeTile* pTile=NULL;
		UGint nCount=m_list.GetCount();
		UGint nBrotherNum=0;
		UGint nIndex=0;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		while(!m_list.IsEOF(pos))
		{
		
			pTile=m_list.GetNext(pos); 
			if (nLevel==pTile->GetLevel() && nRow>>1 ==pTile->GetRow()>>1 && nCol>>1 ==pTile->GetCol()>>1)
			{
				pFlg[nIndex]=1;
				if(pTile->IsInitialized())
				{
					nBrotherNum++;
					// 如果四个弟兄都找到
					if (nBrotherNum==4)
					{
						return TRUE;
					}

				}
				else
				{
					return FALSE;
				}

			}
			nIndex++;
		}
		return FALSE;

	}
	void  FindNeedAddedTile(UGArray<ThreeID>&  addArray)
	{
	 
		m_Mutex.lock();
		UGint nCount=m_list.GetCount();
        UGbyte* pFlg=new UGbyte[nCount];
		memset(pFlg,0,nCount*sizeof(UGbyte));
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		UGint nIndex=0;
		while(!m_list.IsEOF(pos))
		{
			pTile=m_list.GetNext(pos); 
			if (pFlg[nIndex]==0)
			{
				if (!pTile->IsInitialized() || !FindBrother(pTile->GetRow(),pTile->GetCol(),pTile->GetLevel(),pFlg))
				{
					addArray.Add(ThreeID(pTile->GetRow(),pTile->GetCol(),pTile->GetLevel()));
					pFlg[nIndex]=1;
				}
			}
			nIndex++;
		}

		delete pFlg;
		m_Mutex.unlock();

	}
	void CopyTiles(const SyncVeTileList& tileList)
	{
		m_Mutex.lock();
		m_list.RemoveAll();
		m_Mutex.unlock();
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=tileList.m_list.GetHeadPosition();
		while(!tileList.m_list.IsEOF(pos))
		{
			pTile=tileList.m_list.GetNext(pos);
			pTile->SetNeeded(TRUE);
			AddTile(pTile);

		}
	}
	 
	void DelChildernTile(UGint nRow,UGint nCol,UGint nLevel)
	{
		m_Mutex.lock();
		UGVeTile* pTile=NULL;
		UGint nChildNum=0;

		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		UGList<UGVeTile*>::POSITION prePos=m_list.GetHeadPosition();;
		while(!m_list.IsEOF(pos))
		{
			//malq- 一定要注意这个删除的用法
			prePos=pos;
			pTile=m_list.GetNext(pos); 

			if (pTile->IsGrandSon(nRow,nCol,nLevel))
			{
				pTile->SetNeeded(FALSE);
				m_list.RemoveAt(prePos);// 注意不是m_list.RemoveAt(pos);
				
			}
		}
		m_Mutex.unlock();

	}
	void RemoveInvisible(UGCameraBase* pActiveCamera)
	{
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		UGList<UGVeTile*>::POSITION prePos;
		m_Mutex.lock();
		while(!m_list.IsEOF(pos))
		{
			
			prePos=pos;
			pTile=m_list.GetNext(pos);
			if (!pActiveCamera->IsVisible(pTile->m_BoundingBox))
			{
				pTile->SetNeeded(FALSE);
				m_list.RemoveAt(prePos);
				continue;
			}
			else
			{
				pTile->SetNeeded(TRUE);
			}
			
		}
			m_Mutex.unlock();

	}
	void DelNoUseTile(UGCameraBase* pActiveCamera)
	{
	
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=m_list.GetHeadPosition();
		UGList<UGVeTile*>::POSITION prePos;
			m_Mutex.lock();
		while(!m_list.IsEOF(pos))
		{
		
			prePos=pos;
			pTile=m_list.GetNext(pos);
			if (IsAllChildrenExist(pTile->GetRow(),pTile->GetCol(),pTile->GetLevel()))
			{
				

				pTile->SetNeeded(FALSE);
				m_list.RemoveAt(prePos);
				continue;
			}
			else
			{
				pTile->SetNeeded(TRUE);
			}

		}
			m_Mutex.unlock();
	

	}
	// 类的内部可以使用同类的私有函数
	void AddTiles(const SyncVeTileList& tileList)
	{
		
		UGVeTile* pTile=NULL;
		UGList<UGVeTile*>::POSITION pos=tileList.m_list.GetHeadPosition();
		while(!tileList.m_list.IsEOF(pos))
		{
			pTile=tileList.m_list.GetNext(pos);
			if (FindTile(pTile->GetRow(),pTile->GetCol(),pTile->GetLevel()))
			{
				continue;
			}
			m_Mutex.lock();
			DelChildernTile(pTile->GetRow(),pTile->GetCol(),pTile->GetLevel());
			pTile->SetNeeded(TRUE);
			AddTile(pTile);
			UGScene::ms_bNeedRefresh=TRUE;
			m_Mutex.unlock();
			
		}
		
	}

//public:
		
private:
	// 注意我把缓存放到这里来，是为了用异步机制，用锁把缓存保护起来
	UGMutex m_Mutex;
	UGList<UGVeTile*> m_list;
};


class SCENE_API UGGeMapLayer:public UGRenderObject
{
public:
	UGGeMapLayer();
	UGGeMapLayer(const UGString& name,UGint nStartLevel,UGImgAccessor* pImgAccessor);
	virtual ~UGGeMapLayer();
	UGint GetElevatedVertexCount();
	UGint GetElevatedVertexIndiceCount();
	UGushort *GetElevatedVertexIndexData();
	void ForceRefresh();
	UGint GetZoomLevelByTrueViewRange(UGdouble trueViewRange);
	virtual void Update();
	virtual void Render();
	virtual void Release();
	UGdouble GetLevelArcs(UGint nLevel);
	UGint GetZoomLevelByArcDistance(UGdouble arcDistance);
	UGint LatitudeToYAtZoom(UGdouble lat, UGint zoom);
	UGint LongitudeToXAtZoom(UGdouble lon, UGint zoom);
	
	void GetViewPort(UGdouble& lat1, UGdouble& lon1, UGdouble& lat2, UGdouble& lon2);
	UGImgAccessor* GetImgAccessor();
private:
	void Initialize();
	UGdouble MetersPerTile(UGint zoom);
	UGdouble MetersPerPixel(UGint zoom);
	void InitVertexIndexArray();
	void AddVeTile(UGint nRow, UGint nCol, UGint nLevel);
	void AddNeighborTiles(UGint nRow, UGint nCol, UGint nLevel, UGint range);
	UGVeTile* CreateVeTile(UGint nRow, UGint nCol, UGint nLevel);
	void FindVisibleFatherTile(UGint nRow,UGint nCol,UGint nLevel);
public:
	UGdouble m_dEarthRadius; //6378137;
	UGdouble m_dEarthCircum; //40075016.685578488
	UGdouble m_dEarthHalfCirc; //20037508.
private:
	 UGint    m_nStartLevel;
	 UGint m_nPixelsPerTile;
	 UGint m_nPrevRow ;
	 UGint m_nPrevCol ;
	 UGint m_nPrevLvl ;
	 UGdouble m_dVerticalExaggeration;
	 UGTileCache m_TileCache;
	 SyncVeTileList m_RenderQueue;
	 SyncVeTileList m_PreRenderQueue;
	 UGfloat m_dScaleWidth ;
	 UGfloat m_dScaleHeight ;
	 UGint m_nElevatedVertexCount;
	 UGint m_nElevatedVertexIndiceCount;
	 UGushort* m_pElevatedVertexIndex;	
	 UGImgAccessor *m_pImgAccessor;

};
}

#endif // !defined(AFX_UGGEMAPLAYER_H__6A281167_C9DD_484A_A88B_8B09B09C135A__INCLUDED_)

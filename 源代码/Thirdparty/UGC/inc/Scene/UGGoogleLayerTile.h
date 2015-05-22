// UGGoogleLayerTile.h: interface for the UGGoogleLayerTile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_)
#define AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGVector3R.h"
#include "Base/UGThread.h"
#include "UGMathEngine.h"
namespace UGC
{
class UGGoogleLayer;
//! \brief 四叉树块节点类
//! \remarks 备注信息。
class SCENE_API UGGoogleLayerTile : public UGRenderable, public UGMovableObject
{
public:
	//! \brief 构造函数
	UGGoogleLayerTile();
	
 
	//! \brief 构造函数
	//! \param south [in]块节点的经纬度南边界
	//! \param north [in]块节点的经纬度北边界
	//! \param west [in]块节点的经纬度西边界
	//! \param east [in]块节点的经纬度东边界
	//! \param level [in]块节点的所处的四叉树的层数  
	//! \param pQuadTileSet [in]块节点所属的四叉树对象
	UGGoogleLayerTile(UGint nRow,UGint nCol, 
		UGint nLevel, UGGoogleLayer* pQuadTileSet);	
	virtual ~UGGoogleLayerTile();
public:
	/// <summary>
	/// Child tile location
	/// </summary>
	enum ChildLocation
	{
		NorthWest,
		SouthWest,
		NorthEast,
		SouthEast	
	};
public:
	//! \brief 继承自可渲染对象的函数，负责块的初始化
	virtual void Initialize();
	//! \brief 继承自可渲染对象的函数，负责块的更新
	virtual void Update();
	//! \brief 继承自可渲染对象的函数，负责块的渲染
	virtual void Render();
	
	//! \brief 继承自可渲染对象的函数，负责块的文件缓存
	void ResetCache();
	//! \brief 继承自可渲染对象的函数，获得块的层数 
	UGint GetLevel();
	//! \brief 继承自可渲染对象的函数，获得块的行号
	UGint GetRow();
	//! \brief 继承自可渲染对象的函数，获得块的列号
	UGint GetCol();
	UGbool IsVisible();
	
protected:	
	 
	//! \brief 生成一个指定经纬度范围的子块
	//! \param childSouth [in]
	//! \param childNorth [in]
	//! \param childWest [in]
	//! \param childEast [in]
	//! \return 返回新生成的子块的指针
	UGGoogleLayerTile* ComputeChild(UGint nRow,UGint nCol);	
	//! \brief 计算该块的四个子块
	//! \param drawArgs [in]
	void ComputeChildren();		
	void ReleaseChild();	
	//! \brief  渲染该块
	UGbool RenderTile();
	//! \brief 释放该块
	virtual void Release();	
	//! \brief  渲染实际数据
	void RenderTile(UGRenderOperation* pRo);
	//! \brief  选中该块
	virtual UGbool PerformSelectionAction();

	//! \brief 
	void CreateTileMesh();		
	//! \brief 
	void CreateFlatMesh();
	//! \brief 
	void CreateElevatedMesh();
	//! \brief 生成指定子块的网格数据
	//! \param corner [in]
	//! \param pRo [in]
	//! \param meshBaseRadius [in]
	//! \param heightData [in]
	void CreateElevatedMesh(ChildLocation corner, UGRenderOperation* pRo ,
	UGdouble meshBaseRadius, UGfloat* heightData);	

	
	UGdouble ComputeLOD();

protected:
	//! \brief 块所属的四叉树
	UGGoogleLayer* m_pQuadTileSet;
	//! \brief 
	UGbool m_bRenderStruts ;
	//! \brief 
	UGdouble m_dWest;
	//! \brief 
	UGdouble m_dEast;
	//! \brief 
	UGdouble m_dNorth;
	//! \brief 
	UGdouble m_dSouth;
	//! \brief 
	UGdouble m_dCenterLatitude;
	//! \brief 
	UGdouble m_dCenterLongitude;
	//! \brief 
	UGdouble m_dLatitudeSpan;
	//! \brief 
	UGdouble m_dLongitudeSpan;
	//! \brief 
	UGint m_nLevel;
	//! \brief 
	UGint m_nRow;
	//! \brief 
	UGint m_nCol;	
	//! \brief 
	UGVector3R m_vecLocalOrigin;  
	//! \brief 
	UGbool m_bResetingCache;
	//! \brief 
	UGdouble m_dVerticalExaggeration;
	//! \brief 
	UGGoogleLayerTile* m_pNorthWestChild;
	//! \brief 
	UGGoogleLayerTile* m_pSouthWestChild;
	//! \brief 
	UGGoogleLayerTile* m_pNorthEastChild;
	//! \brief 
	UGGoogleLayerTile* m_pSouthEastChild;
	//! \brief northWestVertices
	UGRenderOperation* m_pNWRo; 
	//! \brief southWestVertices
	UGRenderOperation* m_pSWRo; 
	//! \brief northEastVertices
	UGRenderOperation* m_pNERo; 
	//! \brief southEastVertices
	UGRenderOperation* m_pSERo; 
	//! \brief
	UGTexture* m_pTexture;
	//! \brief
	UGMutex m_mutex;

	// UpperLeft
	UV m_ul;
	UV m_ur;
	// LOWERLEFT
	UV m_ll;
	UV m_lr;
};
}

#endif // !defined(AFX_UGGOOGLELAYERTILE_H__505D0DAC_0C2B_4828_A427_47E8F573779C__INCLUDED_)

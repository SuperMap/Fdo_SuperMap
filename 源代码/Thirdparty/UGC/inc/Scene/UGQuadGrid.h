// UGQuadGrid1.h: interface for the UGQuadGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_)
#define AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"
#include "Scene/UGRenderable.h"
namespace UGC
{
class SCENE_API UGQuadDataList:public UGList<UGQuadDataset*>
{
public:
	UGQuadDataList();
	virtual~ UGQuadDataList();
	void ReleaseAll();
	void Render();
	void Initialize();
};
class SCENE_API UGQuadGrid:public UGRenderable, public UGMovableObject
{
public:
	//! \brief 构造函数
	UGQuadGrid();
	
 
	//! \brief 构造函数
	//! \param south [in]块节点的经纬度南边界
	//! \param north [in]块节点的经纬度北边界
	//! \param west [in]块节点的经纬度西边界
	//! \param east [in]块节点的经纬度东边界
	//! \param level [in]块节点的所处的四叉树的层数  
	//! \param pQuadTileSet [in]块节点所属的四叉树对象
	UGQuadGrid(UGdouble south, UGdouble north, UGdouble west, UGdouble east, 
		UGint level, UGQuadGridSet* pQuadTileSet);	
	virtual ~UGQuadGrid();
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
	
protected:	
	 
	//! \brief 生成一个指定经纬度范围的子块
	//! \param childSouth [in]
	//! \param childNorth [in]
	//! \param childWest [in]
	//! \param childEast [in]
	//! \return 返回新生成的子块的指针
	UGQuadGrid* ComputeChild(UGdouble childSouth, UGdouble childNorth, 
		UGdouble childWest, UGdouble childEast);	
	//! \brief 计算该块的四个子块
	//! \param drawArgs [in]
	void ComputeChildren();		
	void ReleaseChild();	
	//! \brief  渲染该块
	UGbool RenderTile();
	//! \brief  渲染该块的数据
	void RenderTileData();
	//! \brief 释放该块
	virtual void Release();	
protected:
	//! \brief 块所属的四叉树
	UGQuadGridSet* m_pQuadTileSet;
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
	UGbool m_bResetingCache;
	//! \brief 
	UGQuadGrid* m_pNorthWestChild;
	//! \brief 
	UGQuadGrid* m_pSouthWestChild;
	//! \brief 
	UGQuadGrid* m_pNorthEastChild;
	//! \brief 
	UGQuadGrid* m_pSouthEastChild;
	//! \brief northWest
	UGQuadDataList m_DataList;
	/*
	//! \brief southWestVertices
	UGQuadDataList m_SWDataList;
	//! \brief northEastVertices
	UGQuadDataList m_NEDataList;
	//! \brief southEastVertices
	UGQuadDataList m_SEDataList;
	*/
	//! \brief
	UGMutex m_mutex;
};
}
#endif // !defined(AFX_UGQUADGRID1_H__934E03A2_8EC2_4B86_B4A9_105F83E03C72__INCLUDED_)

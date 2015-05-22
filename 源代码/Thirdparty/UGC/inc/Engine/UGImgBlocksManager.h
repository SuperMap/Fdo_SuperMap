// UGImgBlocksManager.h: interface for the UGImgBlockManager class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGImgBlocksManager.h
	\brief 处理多线程Block管理类
	\author 李文龙
	\attention 线程安全
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)
#define AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Geometry/UGImgBlock.h"

namespace UGC {

class UGDatasetRaster;

class ENGINE_API UGThreadBlocks
{
public:
	UGThreadBlocks();
public:
	UGArray<UGint> m_aryPos;
	UGImgBlocks m_ImgLoadedBlocks;
};

class ENGINE_API UGImgBlocksManager  
{
public:
	UGImgBlocksManager();
	UGImgBlocksManager(UGDatasetRaster *pDtRaster);
	virtual ~UGImgBlocksManager();

	//! \brief 设置指定的缓存的Block
	//! \param y [in] 数据库里的第几行 对应数据为SmColumn
	//! \param x [in] 数据库里的第几列 对应数据库里的SmRow
	//! \param *pImgBlock [out] 参数的指针
	//! \return 每个线程维护自己的内存
	//! \remarks 如果当前位置已经存在数据的指针，那么删除之
	//! \attention 
	UGbool SetBlockAt(UGint y,UGint x,UGImgBlock *pImgBlock);

	//! \brief 设置指定的缓存的Block
	//! \param nIndex [in] Position
	//! \param *pImgBlock [in] ImgBlock
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool SetBlockAt(UGint nIndex,UGImgBlock *pImgBlock);	

	//! \brief 得到指定的缓存的Block
	//! \param y [in] 数据库里的第几行 对应数据为SmColumn
	//! \param x [in] 数据库里的第几列 对应数据库里的SmRow
	//! \param *pImgBlock [out] 返回的指针
	//! \return 每个线程维护自己的内存
	//! \remarks 。
	//! \attention 。
	UGImgBlock * GetBlockAt(UGint y,UGint x);
	

	//! \brief 得到指定位置的缓存Block
	//! \param nIndex [in] 一维数组的位置
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGImgBlock * GetBlockAt(UGint nIndex);	

	//! \brief 释放当前线程缓存的数据
	//! \return TRUE 
	//! \remarks 
	//! \attention 如果Block修改了，要负责修改的数据库
	UGbool ReleaseBlocks();


	//! \brief 得到所有的Img块指针为了快速保存些东西
	//! \return TRUE
	//! \remarks 返回的指针只读，不能删除
	//! \attention 。
	UGImgBlocks * GetAllBlocks();

	//! \brief 初始化。
	//! \param *pDataset [in]。
	//! \param FALSE [in]。
	//! \return True
	//! \remarks 默认是支持多线程的，但对于SDB引擎不支持那么将用不支持方式来处理
	//! \attention 。
	UGbool SetDataset(UGDatasetRaster *pDataset,UGbool bSingleThread = FALSE);	

protected:
	UGDatasetRaster *m_pRaster;
	UGArray<UGint> m_aryThreadIDs;
	UGArray<UGThreadBlocks*> m_aryImgBlocks;
	UGbool m_bSingleThread;
};

}

#endif // !defined(AFX_UGIMGBLOCKMANAGER_H__1A2DC698_B9F7_40D2_8DE3_2C83B9380D68__INCLUDED_)

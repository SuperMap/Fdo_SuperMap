/*! \file	 UGUdbDatasetRaster.h
 *  \brief	 Oracle Plus UGUdbDatasetRaster
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGUdbDatasetRaster.h,v 1.3 2007/11/06 03:08:13 liwl Exp $
 */

#if !defined(AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)
#define AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_

#include "Engine/UGDatasetRaster.h"
#include "Base/ugdefs.h"

namespace UGC {

class UDBENGINE_API UGUdbDatasetRaster : public UGDatasetRaster
{
	friend class UGUdbDataSource;
	
	
public:
	UGUdbDatasetRaster();
	UGUdbDatasetRaster(UGDataSource *pDataSource);
	virtual ~UGUdbDatasetRaster();

public:

	//! 打开数据集
	virtual UGbool Open();

	//! 关闭数据集
	virtual void Close();
	
	//! 保存数据集信息
	virtual UGbool SaveInfo();
	
	//! 刷新数据集信息
	virtual UGbool RefreshInfo() {
		return FALSE;
	}

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();
	
	//! 返回创建时间
	virtual UGTime GetDateCreated();

	//! 判断当前数据集是否可编辑
	virtual UGbool CanUpdate();

		
	//! 返回数据集对应表名
	virtual UGString GetTableName() {
		return m_RasterInfo.m_strTableName;
	}

	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	virtual UGbool RemovePyramids();

	UGint GetMaxBlockSize() const {
		return m_nMaxBlockSize;
	}

	void SetMaxBlockSize(UGint nMaxBlockSize) {
		m_nMaxBlockSize = nMaxBlockSize;
		SetModifiedFlag();
	}
	UGbool Create(const UGDatasetRasterInfo &rInfo);

	UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! 卸载所有已放入内存的块
	virtual void ReleaseAllBlock();

	//! pImgBlock存盘
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);


	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! 判断数据集是否支持某种操作
	virtual UGbool IsSupport(UGEngAction nAction);


private:

	UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions);

	UGbool ReleasePyramidDatasets();

	void GetImgPyramidValue(PixelFormat ipf, UGbool bIndexedColor, UGuint a,
		UGuint b, UGuint c, UGuint d, UGuint& e);
	
	UGdouble CalcAvgValue(UGdouble a, UGdouble b, UGdouble c, UGdouble d);

	//! 内部函数，用于错误检查并输出 
	void CheckError() const;
	
	//! \brief 保存索引的影像块，但不破坏内存
	//! \return True 成功
	//! \attention 。
	UGbool SaveAllBlocks();	

	UGint m_nMaxBlockSize;	

	UGbool m_bPrepared;

	UGDataSource *m_DataSource;


};

}

#endif // !defined(AFX_UGUdbDatasetRaster_H__3DF7970F_EE60_4428_A101_DDC3CCE82A39__INCLUDED_)


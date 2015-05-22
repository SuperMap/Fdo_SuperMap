// UGSitDatasetRaster.h: interface for the UGSitDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_)
#define AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
#include "SitEngine/UGSitDataSource.h"

namespace UGC
{

class SITENGINE_API UGSitDatasetRaster  : public UGDatasetRaster
{
	friend class UGSitDataSource;

public:
	UGSitDatasetRaster();
	virtual ~UGSitDatasetRaster();

	virtual UGbool BuildPyramid(UGbool bShhowProgress) {return FALSE;};
	virtual UGbool RemovePyramids() {return FALSE;};

	
	//! \brief  pImgBlock存盘
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock) {return FALSE;};

	
	//! \brief  保存数据集信息
	virtual UGbool SaveInfo(){return FALSE;};
	
	//! \brief  刷新数据集信息
	virtual UGbool RefreshInfo() {
		return FALSE;
	}
	
	//! \brief  返回最后更新时间
	virtual UGTime GetDateLastUpdated(){return UGTime(0.0);};
	
	//! \brief  返回创建时间
	virtual UGTime GetDateCreated(){return UGTime(0.0);};
	
	//! \brief  判断当前数据集是否可编辑
	virtual UGbool CanUpdate(){return FALSE;};
	
	
	//! \brief  返回数据集对应表名
	virtual UGString GetTableName() {
		return m_RasterInfo.m_strTableName;
	}
	
	//! \brief  数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName){return FALSE;};
	
	UGbool Create(const UGDatasetRasterInfo &rInfo){return FALSE;};
	
	
	//! \brief  读入指定块数据
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! \brief  打开数据集
	virtual UGbool Open();
	
	//! \brief  关闭数据集
	virtual void Close();
	

	//! \brief  卸载所有已放入内存的块
	virtual void ReleaseAllBlock();
	
	
	
private:
	UGbool ReleasePyramidDatasets();
	SmTierInfo * m_pTierInfo;
	UGSitDataSource * m_pOrgDataSource;

	
	
};

}

#endif // !defined(AFX_UGSITDATASETRASTER_H__3EDB907A_EDF4_4CAC_99C1_FF2566D22C16__INCLUDED_)

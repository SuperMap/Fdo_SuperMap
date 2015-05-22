// UGODBCDatasetRaster.h: interface for the UGODBCDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_)
#define AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_

#include "Engine/UGDatasetRaster.h"
#include "ODBCEngine/UGODBCConnection.h"

namespace UGC
{
class UGEXPORT UGODBCDatasetRaster : public UGDatasetRaster
{
public:
	UGODBCDatasetRaster();
	virtual ~UGODBCDatasetRaster();

public:
	//! \brief  打开数据集
	virtual UGbool Open();

	//! \brief  关闭数据集
	virtual void Close();
	
	//! \brief  保存数据集信息
	virtual UGbool SaveInfo();
	
	//! \brief  刷新数据集信息
	virtual UGbool RefreshInfo();

	//! \brief  返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! \brief  返回创建时间
	virtual UGTime GetDateCreated();
	
	//! \brief  返回数据集对应表名
	virtual UGString GetTableName();
	
	//! \brief  数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! \brief 创建金字塔
	//! \param　bShhowProgress　是否显示进度条
	//!  \return 创建成功为True,否则False
	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	//! \brief 删除金字塔
	virtual UGbool RemovePyramids();

	//! \brief  读入指定块数据
	//! \param　nRowBlock 块所在行数
	//! \param　nColBlock 块所在列数
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);

	//! \brief  pImgBlock存盘
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);

	//! \brief block的缓存
	//! \param nLeft,nTop,nWidth,nHeight确定一个Bounds
	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop, UGint nWidth,UGint nHeight);

	//! 卸载所有已放入内存的块
	virtual void ReleaseAllBlock();

	//! 注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	//! 反注册选项信息
	virtual UGbool UnRegisterOption(UGint nOption);
public:
	//! \brief　设置最大影像块的值
	//! \param　nMaxBlockSize　[in]
	void SetMaxBlockSize(UGint nMaxBlockSize);

	//! \brief　获取最大影像块的值
	UGint GetMaxBlockSize();

	//! \brief 获取连接
	UGODBCConnection * GetConnection() const;
protected:

	//! \brief 删除金字塔数据集
	UGbool ReleasePyramidDatasets();

	//! \brief 创建金字塔数据集表
	UGDatasetRaster* Tier(UGint nLevel, UGint lWidth, UGint lHeight, UGDatasetRasterInfo::IBSizeOption eBlockSize, UGint nOptions);
	//! \brief 计算平均值
	UGdouble CalcAvgValue(UGdouble a, UGdouble b,UGdouble c,UGdouble d);

	UGbool SaveAllBlocks();
protected:
	UGint m_nMaxBlockSize;
	UGbyte *m_pTempData;
	UGint m_nTempDataSize;
	UGMutex m_nOpenMutex;
};

}

#endif // !defined(AFX_UGODBCDATASETRASTER_H__07D60798_A059_496F_91CB_3371625C598D__INCLUDED_)

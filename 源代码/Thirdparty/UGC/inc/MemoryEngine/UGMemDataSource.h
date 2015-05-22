// SmMemDataSource.h: interface for the UGMemDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGMEMDATASOURCE_H)
#define UGMEMDATASOURCE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"

namespace UGC
{

extern "C" MEMENGINE_API UGDataSource* CreateDataSource();

class MEMENGINE_API UGMemDataSource : public UGDataSource  
{
public:
	UGMemDataSource();
	virtual ~UGMemDataSource();
	
	//! \brief 创建数据源,需要预先设置好连接信息。
	/**
		函数功能详细描述。
	 	\return 返回是否成功创建数据源，成功返回TRUE，失败返回FALSE。
	 	\remarks 内存数据源的创建并不是真的创建数据源，只是改变了数据源的一些相关参数。
	*/
	virtual UGbool Create();

	//! \brief 打开数据源,需要预先设置好连接信息。
	/**
	函数功能详细描述。
		\return 返回是否成功打开数据源，成功返回TRUE，失败返回FALSE。
		\remarks 内存数据源的创建并不是真的打开数据源，只是改变了数据源的一些相关参数。
	*/
	virtual UGbool Open();

	//! \brief 关闭数据源。
	/**
	函数功能详细描述。
		\remarks 释放全部Dataset,回收内存。
	*/
	virtual void Close();

	//! \brief 获取最后更新时间。
	/**
	函数功能详细描述。
		\return 最后更新时间。
	*/
	virtual UGTime GetDateLastUpdated() const;

	//! \brief 获取创建时间。
	/**
	函数功能详细描述。
		\return 创建时间。
	*/
	virtual UGTime GetDateCreated() const;

	//! \brief 保存数据信息。
	/**
	函数功能详细描述。
		\return 返回成功TRUE或失败FALSE。
		\remarks 。
	*/
	virtual UGbool SaveInfo();

	//! \brief 修改密码。
	/**
	函数功能详细描述。
		\param strNewPassword 希望更改为的密码。
		\return 返回修改成功TRUE或失败FALSE。
	*/
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! \brief 通过DatasetVectorInfo创建数据集。
	/**
	函数功能详细描述。
		\param vInfo 失量数据集信息。
		\return 矢量数据集类指针。
		\remarks 。
		\attention 。
		\sa 。
	*/
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! 数据源是否和数据连接
	virtual UGbool IsConnected();
	
	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

public:
	virtual UGString GetEngineName() const; 
protected:
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);
};

}

#endif // !defined(UGMEMDATASOURCE_H)

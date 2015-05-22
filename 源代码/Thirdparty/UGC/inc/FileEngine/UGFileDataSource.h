
/*!
    **************************************************************************************
     \file     UGFileDataSource.h
    **************************************************************************************
     \author   周芹
     \project  FileEngine
     \brief    文件型引擎数据源
     \remarks                                                                         <br>
    ----------------------------------------------------------------------------------<br>
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(UGMEMDATASOURCE_H)
#define UGMEMDATASOURCE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDataSource.h"
#include "Engine/UGDataSource.h"
#include "DataExchange/UGImportParams.h"

namespace UGC
{

class FILEENGINE_API UGFileDataSource : public UGDataSource  
{
public:
	UGFileDataSource();
	virtual ~UGFileDataSource();

	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();

	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据源
	virtual void Close();

	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const;

	//! 保存数据信息
	virtual UGbool SaveInfo();

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	virtual UGMetadata* GetMetaData();

	//! 数据源是否和数据连接
	virtual UGbool IsConnected();
	
	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

	//! brief 设置默认的参数
	void AttatchParams(UGImportParams importParams);

public:
	virtual UGString GetEngineName() const; 

private:
	//! brief 根据m_Connection中的参数 与外部文件连接
	UGbool Connect(const UGString& strServer, const UGString& strFileName);

	//! \brief 根据文件名 (UGDsConnection 的 m_strServer) 构建数据源名称
	void MakeCacheName();

	//! \brief 填充数据源
	UGbool FillDataSource();

	//! brief 找MasterFile
	UGbool InitMasterFile();

	//! \brief 更新xml
	void UpdateMasterFile();

	//! brief 创建一个xml文件
	UGbool CreateMasterFile();

	//! brief 看看 对应的 Cache 是否存在
	UGbool IsCacheExist();

	//! brief 得到一个唯一的Cache名
	UGString GetUnOccupiedCacheName(UGString strCacheFileName);
	//! biief 验证 Cache是否唯一
	UGbool IsUnOccupiedCacheName(UGString strCacheFileName);


private:
	UGImportParams m_importParams;

	UGDataSource *m_pFileDataSource;

	//! \brief xml文件名（绝对路径）
	UGString m_strMasterFileName;
	
	//! \brief 需要打开的文件名（绝对路径）
	UGString m_strSourceFileName;

	//! \brief Cache文件名（绝对路径）
	UGString m_strCacheName;
};

extern "C" FILEENGINE_API UGDataSource* CreateDataSource();

}

#endif // !defined(UGMEMDATASOURCE_H)

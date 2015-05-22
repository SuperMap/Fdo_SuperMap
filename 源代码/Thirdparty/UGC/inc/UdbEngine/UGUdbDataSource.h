/*! \file	 UGUdbDataSource.h
 *  \brief	 Oracle Plus DataSource
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGUdbDataSource.h,v 1.12 2007/12/17 11:19:40 liwl Exp $
 */


#ifndef UGUdbDataSource_H
#define UGUdbDataSource_H

#include "Engine/UGDataSource.h"
#include "UdbEngine/UGUdbDatasetVector.h"
#include "Base/UGTime.h"
#include "UdbEngine/UGUdbRecordset.h"
#include "CppSQLite3.h"

namespace UGC {	

class UDBENGINE_API UGUdbDataSource : public UGDataSource
{
	friend class UGUdbDatasetVector;
	friend class UGUdbDatasetRaster;
	friend class UGUdbEditRecordset;
	friend class UGUdbRecordset;

public:
	UGTime GetCurServerTime();
	UGUdbDataSource();
	virtual ~UGUdbDataSource();	

	//检查错误信息
	void CheckError() const;
	
	//! 执行SQL语句，主要用于在数据库级执行的数据操作
	virtual UGbool Execute(const UGString& strSQL);
	
	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();
	
	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据源
	virtual void Close();
		
	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const ;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const ;

	//! 保存数据信息
	virtual UGbool SaveInfo();

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! 开始事务
	virtual UGbool BeginTrans();

	//! 提交事务
	virtual void Commit();

	//! 撤消事务
	virtual void Rollback();

	//! 是否有执行某些操作的能力
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;

	//! 是否支持特定的操作
	virtual UGbool IsSupport(UGEngAction nAction) const ;

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);
	
	//! UndoCheckOut
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	//! CheckIn
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) ;

	//! CheckOut
	virtual UGbool CheckOut() ;

	//! Login
	virtual UGbool Login(const UGString& strName,
		const UGString& strPassword);

	virtual void LogOff() ;

	//! 判断是否已经登录
	virtual UGbool IsLogged() const {
		return m_bLoged;
	}

	virtual UGMetadata * GetMetaData();
	
	//! 数据源是否和数据连接
	virtual UGbool IsConnected();
			
	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;

	CppSQLite3DB m_db;
private:
	UGbool X_SetDataSourceInfo(UGbool bAddNew = FALSE);
	UGbool X_ReadInfo();

	UGbool m_bConnected;	
	UGString m_strSchema;
};

extern "C" UDBENGINE_API UGDataSource* CreateDataSource();

}

#endif
